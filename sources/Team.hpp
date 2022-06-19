//
// Created by netanel on 6/18/22.
//

#ifndef EX6_CPP_TEAM_HPP
#define EX6_CPP_TEAM_HPP
#pragma once
#include "iostream"
#include <string>
#include <utility>
#include <experimental/random>
using namespace std;
static double random_skill();

class Team {
public:
    string name;
    double skill;
    int wins;
    int loses;
    int scored_points;
    int points_lost;



    Team()  : name("0"), skill(random_skill()), wins(0), loses(0), scored_points(0), points_lost(0){};
    Team(string  name, double skill) : name(move(name)), skill(skill), wins(0), loses(0), scored_points(0), points_lost(0){};
    ~Team() = default;
    bool operator ==(const Team& other) const{
        return this->name == other.name;
    }

};

static double random_skill(){
    return (double) std::experimental::randint(1, 10000) / 10000;
}


#endif //EX6_CPP_TEAM_HPP
