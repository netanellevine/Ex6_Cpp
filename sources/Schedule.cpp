//
// Created by netanel on 6/18/22.
//

#include "Schedule.hpp"
#include <algorithm>
#include <list>

constexpr size_t MAX_SIZE = 20;

// round-robin algorithm to schedule the league
std::vector<Round> createSchedule(std::vector<Team*> &roster)
{
    std::vector<Round> ans;

    vector<size_t> team_as_nums;
    team_as_nums.reserve(MAX_SIZE);
    for (size_t i = 0; i < MAX_SIZE; i++) {
        team_as_nums.emplace_back(i) = i;
    }

    for (size_t i = 0; i < MAX_SIZE - 1; i++) {
        Round round;
        for (size_t j = 0; j < MAX_SIZE / 2; j++) {
            round.games.emplace_back(*(roster.at(team_as_nums.at(j))),
                                         *(roster.at(team_as_nums.at(MAX_SIZE - 1 - j))));
            round.games.emplace_back(*(roster.at(team_as_nums.at(MAX_SIZE - 1 - j))),
                                         *(roster.at(team_as_nums.at(j))));
        }

        size_t last = team_as_nums.at(team_as_nums.size() - 1);
        for (size_t j = team_as_nums.size() - 1; j >= 2; j--) {
            team_as_nums.at(j) = team_as_nums.at(j - 1);
        }
        team_as_nums.at(1) = last;
        ans.emplace_back(round);
    }
    return ans;
}

void Schedule::update(vector<Team*> &teams)
{
    this->rounds = createSchedule(teams);
}

std::vector<Round>::iterator Schedule::begin()
{
    return this->rounds.begin();
}

std::vector<Round>::iterator Schedule::end()
{
    return this->rounds.end();
}
