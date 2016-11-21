#include <string>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <mutex>
#include <thread>
#include <functional>
#include <climits>
#include <atomic>
#include <assert.h>

enum class Dir {
    RIGHT,
    DOWN
};

// TODO: try float and see impact on speed/convergence
typedef double real_t;

typedef std::array<Dir, 79*2> Path;
typedef std::array<unsigned int, 80*80> Matrix;

Path generate_random_path(void);
unsigned int path_sum(const Matrix &m, const Path &p);

std::mutex print_mutex;

void thread_print(std::string str)
{
    std::unique_lock<std::mutex> lock(print_mutex);
    std::cout << str << std::endl;
}

class PathFinder {
    public:
        PathFinder(Matrix _matrix);
        const Matrix matrix;

        void check_global_path(const Path &p, const unsigned int sum) {
            std::unique_lock<std::mutex> lock(best_path_mutex_);
            if (sum < best_sum_) {
                best_path_ = p;
                best_sum_ = sum;
                thread_print(std::to_string(best_sum_));
            }
        }

        unsigned int get_best_sum(void) {
            std::unique_lock<std::mutex> lock(best_path_mutex_);
            return best_sum_;
        }

        void launch_threads(void);
        void cleanup_threads(void);

        std::atomic<bool> keep_searching_;

    private:
        std::mutex best_path_mutex_;
        Path best_path_;
        unsigned int best_sum_;

        std::vector<std::thread> threads_;
};

class PathThread {
    public:
        PathThread(PathFinder *pf, unsigned int max_temp, real_t gamma);
        void mutate_path(void);
        unsigned int get_local_best_sum() const { return local_best_sum_; }
        unsigned int get_failed_mutations() const { return failed_mutations_; }
        Path get_path() const { return path_; }

    private:
        PathFinder *pf_;

        Path path_;
        unsigned int sum_;
        unsigned int local_best_sum_;
        unsigned int failed_mutations_;
        real_t temp_;
        real_t gamma_;
        const unsigned int max_temp_;

        void update_temp(void) {

            temp_ *= 0.999999;
            if (failed_mutations_ > 2000000 and temp_ < max_temp_/50) {
                failed_mutations_ = 0;
                temp_ = max_temp_/2;
                thread_print("reset temp");
            }
        }
        bool accept_mc(unsigned int new_sum);
        bool accept_stun(unsigned int new_sum);
        real_t get_random_normal(void);
        unsigned int get_random_path_position(void);

};

PathFinder::PathFinder(Matrix _matrix)
    : matrix(_matrix),
      best_path_(generate_random_path()),
      best_sum_(path_sum(matrix, best_path_))
{
    keep_searching_.store(true);
}

void
PathFinder::launch_threads()
{
    assert(threads_.empty());

    for (int i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        auto thread_launcher = [this]() -> void {
            std::unique_ptr<PathThread> pt(new PathThread(this, 20000, 0.1));

            while (this->keep_searching_.load()) {
                pt->mutate_path();
            }

            thread_print(std::to_string(pt->get_failed_mutations()));
        };

        threads_.push_back(std::thread(thread_launcher));
    }
}

void
PathFinder::cleanup_threads()
{
    keep_searching_.store(false);

    while (!threads_.empty())
    {
        auto &t = threads_.back();
        if (t.joinable()) t.join();
        threads_.pop_back();
    }
}

PathThread::PathThread(PathFinder *pf, unsigned int max_temp, real_t gamma)
    : pf_(pf),
    path_(generate_random_path()),
    sum_(path_sum(pf->matrix, path_)),
    local_best_sum_(sum_),
    failed_mutations_(0),
    temp_(max_temp),
    gamma_(gamma),
    max_temp_(max_temp)
{
}

bool
PathThread::accept_mc(unsigned int new_sum)
{
    if (new_sum < sum_) {
        return true;
    } else {
        real_t prob = exp(((int)sum_ - (int)new_sum) / temp_);
        return prob >= this->get_random_normal();
    }
}

bool
PathThread::accept_stun(unsigned int new_sum)
{
    real_t f1, f2, prob;
    real_t global_best_sum = pf_->get_best_sum();
    if (new_sum < sum_) {
        return true;
    } else {
        f1 = 1 - exp(-gamma_ * ((real_t)sum_ - global_best_sum));
        f2 = 1 - exp(-gamma_ * ((real_t)new_sum - global_best_sum));
        prob = exp(-(f2 - f1) / temp_);
        return prob >= this->get_random_normal();
    }
}

unsigned int
PathThread::get_random_path_position()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, path_.size()-2);

    return dis(gen);
}

real_t
PathThread::get_random_normal()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0, 1);

    return dis(gen);
}

void PathThread::mutate_path()
{
     this->update_temp();

     Path new_path = path_;
     unsigned int r;
     Dir d_1, d_2;

     unsigned int mutations_left = 1 + 10 * exp(-temp_/(temp_/3));

     while (mutations_left > 0)
     {
         r = this->get_random_path_position();
         d_1 = new_path[r];
         d_2 = new_path[r+1];

         while(d_2 == d_1)
         {
             r = this->get_random_path_position();
             d_1 = new_path[r];
             d_2 = new_path[r+1];
         }

         new_path[r] = d_2;
         new_path[r+1] = d_1;
         mutations_left--;
     }

     unsigned int new_sum = path_sum(pf_->matrix, new_path);
     if (accept_mc(new_sum))
     {
         path_ = new_path;
         sum_ = new_sum;

         if (sum_ < local_best_sum_)
         {
             local_best_sum_ = sum_;
             pf_->check_global_path(path_, sum_);
         } else {
             failed_mutations_++;
         }
     }
}

Path generate_random_path()
{
    Path new_path;

    unsigned int downs = 79;
    unsigned int rights = 79;

    for (int i = 0; i < new_path.size(); i++)
    {
        if (downs == 0) {
            rights--;
            new_path[i] = Dir::RIGHT;
        } else if (rights == 0) {
            downs--;
            new_path[i] = Dir::DOWN;
        } else if (rand() % 2 == 0) {
            downs--;
            new_path[i] = Dir::DOWN;
        } else {
            rights--;
            new_path[i] = Dir::RIGHT;
        }
    }

    assert(downs == 0 and rights == 0);

    return new_path;
}

int
main(void)
{
    srand(time(NULL));

    std::string line;
    std::ifstream file("./matrix.txt");
    Matrix matrix;
    int i = 0;

    while(getline(file,line))
    {
        std::stringstream linestream(line);
        std::string value;

        while(getline(linestream,value,','))
        {
            unsigned int v = std::stoi(value);
            matrix[i++] = v;
        }
    }

    assert(i == (matrix.size()));

    PathFinder pf(matrix);
    pf.launch_threads();
    std::this_thread::sleep_for (std::chrono::seconds(60));
    pf.cleanup_threads();
    return 0;
}

unsigned int
path_sum(const Matrix &m, const Path &p)
{
    int sum = m[0];
    int x = 0;
    int y = 0;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == Dir::DOWN) { y++; } else { x++; }
        sum += m[x + 80*y];
    }


    assert(x == 79 and y == 79);

    return sum;
}

//
