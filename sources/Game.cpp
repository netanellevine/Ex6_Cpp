//
// Created by netanel on 6/18/22.
//

#include "Game.hpp"
constexpr float EXPECTATION_A = 75;
constexpr float VARIANCE_A = (50.0*50.0)/12.0;
constexpr int MIN_SCORE_A =55;
constexpr int MAX_SCORE_A =100;
constexpr int DEFAULT_NUM =-1;
constexpr int MAX_SCORE_B =100;
constexpr int MIN_SCORE_B =50;
constexpr int TRIES =10;

void Game::play()
{
    if (!this->played)
    {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> normalDistributionRand{75, 8.0};

        // set random score between 50-100 (for home team starting from 55)
        this->home_score = std::round(normalDistributionRand(gen)) + std::round(this->home->skill * 10);
        this->outdoor_score = std::round(normalDistributionRand(gen)) + std::round(this->outdoor->skill * 10);

        // update the scores for home team
        this->home->scored_points += this->home_score;
        this->home->points_lost += this->outdoor_score;

        // update the scores for outdoor team
        this->outdoor->scored_points += this->outdoor_score;
        this->outdoor->points_lost += this->home_score;

        this->played = true;
    }
}

Team *Game::winner()
{
    if (this->home_score > this->outdoor_score)
    {
        setWinLose(1);
        return this->home;
    }
    else if (this->home_score < this->outdoor_score)
    {
        setWinLose(2);
        return this->outdoor;
    }
    else
    {
        int win = std::experimental::randint(1, 2);
        setWinLose(win);
        return win == 1 ? this->home : this->outdoor;
    }
}

void Game::setWinLose(int winner) const
{
    if (1 == winner)
    {
        this->home->wins += 1;
        this->outdoor->loses += 1;
    }
    else
    {
        this->home->loses += 1;
        this->outdoor->wins += 1;
    }
}
