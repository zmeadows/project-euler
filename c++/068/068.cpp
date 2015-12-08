#include <cmath>
#include <algorithm>
#include <array>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <vector>
#include <time.h>

typedef std::array<unsigned int, 9> gon;

int fill_random(gon &g);
double fitness(const gon &g);
void print_gon(const gon &g);
std::string max_string(const gon &g);

    double
fitness(const gon &g)
{
    // static const double MAX_RMS = 16.816658407662327;

    unsigned int sums[5];

    sums[0] = 10 + g[0] + g[1];
    sums[1] = g[5] + g[1] + g[2];
    sums[2] = g[6] + g[2] + g[3];
    sums[3] = g[7] + g[3] + g[4];
    sums[4] = g[8] + g[4] + g[0];

    int i;
    double mean = 0;
    for (i = 0; i < 5; i++) { mean += sums[i]; }
    mean /= 5;

    double rms = 0;
    for (i=0; i < 5; i++) { rms += std::pow(sums[i] - mean, 2); }
    rms = std::sqrt(rms);

    return rms;
}

    int
fill_random(gon &g)
{
    std::set<unsigned int> vals;
    for (int i = 1; i < 10; ++i)
        vals.insert(vals.end(), i);

    unsigned int r;
    std::set<unsigned int>::const_iterator sit;
    gon::iterator git(g.begin());
    while (!vals.empty())
    {
        sit = vals.begin();
        r = rand() % vals.size();
        advance(sit, r);
        *git = *sit;
        git++;
        vals.erase(*sit);
    }
    return 0;
}

    void
print_gon(const gon &g)
{
    std::cout << "   " << "10" << std::endl;
    std::cout << "   " << " \\" << std::endl;
    std::cout << "     " << g[0] << "    " << g[5] << std::endl;
    std::cout << "   " << " /" << " " << " \\ /" << std::endl;
    std::cout << "   " << g[4] << "    " << g[1] << std::endl;
    std::cout << "  / \\  /" << std::endl;
    std::cout << g[8] << "   " << g[3] << "-" << g[2] << "--" << g[6] << std::endl;
    std::cout << "     \\" << std::endl;
    std::cout << "      " << g[7] << std::endl;
}

    std::string
max_string(const gon &g)
{
    unsigned int min_node_value = 10;
    unsigned int min_node_index = 5;

    for (const auto i : {5,6,7,8}) {
        if (g[i] < min_node_value)
        {
            min_node_index = i;
            min_node_value = g[i];
        }
    }

    std::vector<unsigned int> nodes;
    switch (min_node_index)
    {
        case 5:
            nodes = {5,6,7,8,9};
            break;
        case 6:
            nodes = {6,7,8,9,5};
            break;
        case 7:
            nodes = {7,8,9,5,6};
            break;
        case 8:
            nodes = {8,9,5,6,7};
            break;
    }

    std::ostringstream s;
    for (const auto n : nodes) {
        if (n == 9) {
            s << "10" << g[0] << g[1];
        } else if (n == 8) {
            s << g[8] << g[4] << g[0];
        } else {
            s << g[n] << g[n-4] << g[n-3];
        }
    }

    return s.str();
}

int main(void)
{
    srand(time(NULL));

    std::set<gon> solutions;
    std::mutex gs_mutex;

    auto search = [&]() -> void {
        gon g;
        std::unique_lock<std::mutex> lock(gs_mutex, std::defer_lock);
        while (solutions.size() < 4)
        {
            fill_random(g);
            if (fitness(g) == 0)
            {
                lock.lock();
                solutions.insert(g);
                lock.unlock();
            };
        }
    };

    std::vector<std::thread> solver_threads;
    for (int i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        solver_threads.emplace_back(search);
    }
    for (auto &t : solver_threads) t.join();

    for (const auto &s : solutions) {
        print_gon(s);
        std::cout << std::endl << max_string(s) << std::endl;
    }

    return 0;
}
