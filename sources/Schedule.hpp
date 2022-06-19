//
// Created by netanel on 6/18/22.
//
#pragma once
#ifndef EX6_CPP_SCHEDULE_HPP
#define EX6_CPP_SCHEDULE_HPP
#include <vector>
#include "Game.hpp"

struct Round
{
    std::vector<Game> games;

    std::vector<Game>::iterator begin(){return games.begin();}
    std::vector<Game>::iterator end(){return games.end();}
};

class Schedule
{
    std::vector<Round> rounds;
public:

    Schedule(){};
    ~Schedule(){};

    void update(std::vector<Team*> &teams);

    std::vector<Round>::iterator begin();
    std::vector<Round>::iterator end();

    std::vector<Round> Rounds(){ return this->rounds;}
};


#endif //EX6_CPP_SCHEDULE_HPP
