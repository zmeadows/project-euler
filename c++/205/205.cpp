#include <random>
#include <iostream>
#include <thread>
#include <memory>
#include <vector>

struct dice_contest
{
    unsigned peter_wins = 0;
    unsigned colin_wins = 0;
    unsigned draws = 0;
};

void play_n_games(struct dice_contest *dc, unsigned int n)
{
    std::random_device rd;

    std::mt19937_64 pe(rd());
    std::mt19937_64 ce(rd());

    std::uniform_int_distribution<unsigned int> peter_distribution(1, 4);
    std::uniform_int_distribution<unsigned int> colin_distribution(1, 6);

    unsigned int num_peter_rolls, num_colin_rolls;
    unsigned int peter_sum, colin_sum;
    for (int i = 0; i < n; i++)
    {
        peter_sum = 0;
        colin_sum = 0;
        num_peter_rolls = 0;
        num_colin_rolls = 0;

        while (num_peter_rolls < 9)
        {
            peter_sum += peter_distribution(pe);
            num_peter_rolls++;

            if (num_colin_rolls < 6)
            {
                colin_sum += colin_distribution(ce);
                num_colin_rolls++;
            }
        }

        if (peter_sum > colin_sum) {
            dc->peter_wins++;
        } else if (colin_sum > peter_sum) {
            dc->colin_wins++;
        } else {
            dc->draws++;
        }
    }
}


int main(void)
{
    std::vector<std::unique_ptr<struct dice_contest>> dcs;

    for (int i = 0; i < std::thread::hardware_concurrency(); i++)
    {
        dcs.push_back(std::unique_ptr<struct dice_contest>(new struct dice_contest));
    }

    std::vector<std::thread> contest_threads;

    for (auto &c : dcs)
    {
        contest_threads.push_back(std::thread(play_n_games, c.get(), 1000000000));
    }

    unsigned int total_colin = 0;
    unsigned int total_peter = 0;
    unsigned int total_draws = 0;

    while (!contest_threads.empty())
    {
        auto &t = contest_threads.back();
        if (t.joinable()) t.join();
        contest_threads.pop_back();
    }

    for (auto &c : dcs)
    {
        total_peter += c->peter_wins;
        total_colin += c->colin_wins;
        total_draws += c->draws;
    }

    std::cout << "TOTAL PETER: " << total_peter << std::endl;
    std::cout << "TOTAL COLIN: " << total_colin << std::endl;
    std::cout << "TOTAL DRAWS: " << total_draws << std::endl;

    std::cout.precision(10);

    std::cout << (double) total_peter / (double) (total_colin+total_peter+total_draws) << std::endl;
}
