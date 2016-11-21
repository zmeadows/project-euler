// For pseudo-random number generators and distributions
#include <random>
#include <math.h>
#include <numeric>
#include <vector>
#include <array>
#include <cmath>
#include <iostream>

class BallPicker {
public:
    BallPicker(void);
    ~BallPicker(void) {};

    double run(const unsigned num_blocks, const unsigned num_passes_per_block);
private:
    std::vector<unsigned> m_ball_array;

    void rand_swap(void);
    double pass(void);

    std::mt19937 rand_engine;
    std::uniform_real_distribution<double> dist;
    inline double rndm1(void) { return dist(rand_engine); };
};

BallPicker::BallPicker(void)
{
    std::random_device rd;
    rand_engine = std::mt19937(rd());
    dist = std::uniform_real_distribution<double>(0.0,1.0);

    m_ball_array.clear();
    for (unsigned i = 0; i < 70; i++) {
        m_ball_array.push_back(i);
    }

    for (unsigned i = 0; i < 500; i++) {
        rand_swap();
    }
}

void BallPicker::rand_swap(void)
{
    auto s1 = (unsigned) std::floor(rndm1() * 70);
    auto s2 = (unsigned) std::floor(rndm1() * 70);

    unsigned tmp = m_ball_array[s1];
    m_ball_array[s1] = m_ball_array[s2];
    m_ball_array[s2] = tmp;
}

double BallPicker::pass(void) {
    unsigned colors[7] = { 0, 0, 0, 0, 0, 0, 0 };
    unsigned num_colors = 0;

    for (unsigned i = 0; i < 20; i++) {
        colors[m_ball_array[i]/10] += 1;
    }

    for (unsigned i = 0; i < 7; i++)
        if (colors[1] > 0) num_colors++;

    unsigned tmp_color;
    for (unsigned i = 0; i < 50; i++) {
        tmp_color = m_ball_array[i]/10;
        if (--colors[tmp_color] == 0) num_colors--;

        tmp_color = m_ball_array[i+20]/10;
        if (++colors[tmp_color] == 1) num_colors++;
    }

    return (double) num_colors / 51.;
}

double BallPicker::run(const unsigned num_blocks, const unsigned num_passes_per_block)
{
    double color_sum = 0.;

    for (unsigned i = 0; i < num_blocks; i++) {
        for (unsigned j = 0; j < num_passes_per_block; j++) {
            color_sum += pass();
            for (unsigned k = 0; k < 10; k++) {
                rand_swap();
            }
        }
    }

    return (double) color_sum / (num_passes_per_block * num_blocks);
}


inline double get_mean(const std::vector<double>& vec) {
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / vec.size();
}

inline double get_std_dev(const std::vector<double>& vec){
    double sum = 0.;
    double sum_sq = 0.;

    for (auto const& x : vec) {
        sum += x;
        sum_sq += x*x;
    }

    return std::sqrt(1./vec.size()) * std::sqrt(sum_sq/vec.size() - std::pow(sum/vec.size(),2.));
}


int main(void)
{
    BallPicker bp;
    std::cout.precision(9);

    std::vector<double> blocks;
    const unsigned NUM_BLOCKS = 5 * 5000;
    for (unsigned i = 0; i < NUM_BLOCKS; i++) {
        blocks.push_back(bp.run(10, 100));
    }

    std::cout << get_std_dev(blocks) << std::endl;
}
