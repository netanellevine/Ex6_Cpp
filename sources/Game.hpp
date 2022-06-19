//
// Created by netanel on 6/18/22.
//
#pragma once
#ifndef EX6_CPP_GAME_HPP
#define EX6_CPP_GAME_HPP
#include "Team.hpp"

class Game
{
public:
    Team* home;
    Team* outdoor;
    int home_score;
    int outdoor_score;
    bool played = false;


    void init()
    {
        this->home_score = 0;
        this->outdoor_score = 0;
    }

    Game(Team& home, Team& out) : home(&home), outdoor(&out)
    {
        init();
    };

    ~Game() = default;

    void play();

    Team* winner();

    void setWinLose(int winner) const;

};


#endif //EX6_CPP_GAME_HPP
