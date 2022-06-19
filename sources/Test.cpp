//
// Created by netanel on 6/18/22.
//

#include "../doctest.h"
#include <string>
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "League.hpp"
#include "Schedule.hpp"
using namespace std;

TEST_CASE("Running The League"){

    auto* league = new League();
    CHECK_NOTHROW(league->start_season());
    CHECK_NOTHROW(league->printRoster());
    CHECK_NOTHROW(league->printSchedule());
    CHECK_NOTHROW(league->printTopTeams());
    CHECK_NOTHROW(league->printTopByPoints());
    CHECK_NOTHROW(league->printPositiveScoreTeams());

//    for(auto& team : league->teams) {
//        CHECK_NOTHROW(team->wins > 0 );
//        CHECK_NOTHROW(team->loses > 2) ;
//        CHECK_NOTHROW(team->scored_points > 5);
//        CHECK_NOTHROW(team->points_lost < 4);
//    }
//    for(auto& round : *league->curr_schedule) {
//        for(auto& game : round.games) {
//            CHECK_NOTHROW(game.home_score > 10);
//            CHECK_NOTHROW(game.outdoor_score < 10);
//            CHECK_NOTHROW(game.home->name != "");
//            CHECK_NOTHROW(game.outdoor);
//        }
//    }
}