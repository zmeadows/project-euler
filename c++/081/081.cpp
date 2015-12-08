#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <array>
#include <math.h>

enum class Dir {
    RIGHT,
    DOWN
};

typedef std::array<Dir, 79*2> Path;
typedef std::array<unsigned int, 80*80> Matrix;

unsigned int get_path_sum(const Matrix &m, const Path &p);
void mutate_path(const Matrix &m, Path &p);
Path generate_new_path(void);

class PathFinder {
    public:
        PathFinder(Matrix matrix);

    private:
        const Matrix matrix_;
        Path best_path_;
        unsigned int best_sum_;

};

int
main(void)
{
    srand(time(NULL));

    std::string line;
    std::ifstream file("./matrix.txt");
    std::array<unsigned int, 80*80> matrix_;
    int i = 0;

    while(getline(file,line))
    {
        std::stringstream   linestream(line);
        std::string         value;

        while(getline(linestream,value,','))
        {
            matrix_[i++] = std::stoi(value);
        }

    }

    const std::array<unsigned int, 80*80> matrix = matrix_;
    Path p;

    for (int i = 0; i < 79*2; i++)
    {
        (i % 2 == 0) ? p[i] = Dir::RIGHT : p[i] = Dir::DOWN;
    }

    unsigned int N = 0;
    unsigned int min_sum, temp_sum;
    min_sum = 999999999;
    while (N < 100000000)
    {
        mutate_path(matrix, p);
        temp_sum = path_sum(matrix, p);
        if (temp_sum < min_sum) {
            min_sum = temp_sum;
            std::cout << min_sum << std::endl;
        }
        N++;
    }


    return 0;
}

unsigned int
path_sum(const Matrix &m, const Path &p)
{
    unsigned int sum = 0;
    int x = 0;
    int y = 0;
    for (const auto i : p)
    {
        sum += m[x + 80*y];
        (i == Dir::DOWN) ? y++ : x++;
    }
    return sum;
}

void mutate_path(const Matrix &m, Path &p)
{
    static double T = 500000;

    T *= 0.9999999;
    unsigned int r;

    Path p_new = p;

    Dir d_1, d_2;

    int mutated = 0;

    while (mutated < (rand() % (2 + (int)(T/500.0))))
    {
        r = rand() % p.size();
        if (r == 0)
        {
            if (p_new[1] != p_new[0])
            {
                d_1 = p_new[0];
                d_2 = p_new[1];

                if (d_1 != d_2)
                {
                    p_new[0] = d_2;
                    p_new[1] = d_1;
                    mutated++;
                }

            }
        } else {
            if (p_new[r-1] != p_new[r])
            {
                d_1 = p_new[r];
                d_2 = p_new[r-1];

                if (d_1 != d_2)
                {
                    p_new[r] = d_2;
                    p_new[r-1] = d_1;
                    mutated++;
                }
            }
        }
    }

    unsigned int sum_new, sum_old;
    int diff;

    sum_old = path_sum(m,p);
    sum_new = path_sum(m,p_new);

    diff = sum_old - sum_new;


    if (sum_old >= sum_new)
    {
        p = p_new;
    } else {
        double rrr = (double)rand() / (double)RAND_MAX;
        double ppp = exp(diff/T);
        if (ppp >= rrr)
        {
            p = p_new;
        }
    }
}
