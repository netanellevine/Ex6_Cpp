//
// Created by netanel on 6/18/22.
//
#pragma once
#ifndef EX6_CPP_LEAGUE_HPP
#define EX6_CPP_LEAGUE_HPP

#include "Schedule.hpp"

const size_t MAX_SIZE = 20;
//class Schedule;

class League {
public:
    std::vector<Team*> teams;
    Schedule* curr_schedule;

    League();
    League(std::vector<Team*> teams);
    League(const League& other);

    ~League();

    void start_season();

    void printRoster();

    void printSchedule() const;

    void printTopTeams() const;

    void printTopByPoints() const;

    int printPositiveScoreTeams();
};


#endif //EX6_CPP_LEAGUE_HPP
