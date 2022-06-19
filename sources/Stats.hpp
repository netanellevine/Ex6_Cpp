//
// Created by netanel on 6/18/22.
//

#pragma once
#include "Team.hpp"

struct cmpByPoints
{
    inline bool operator() (Team *team1, Team *team2)
    {
        return (team1->scored_points - team1->points_lost> team2->scored_points - team2->points_lost);
    }
};

struct cmpByWins
{
    inline bool operator() (Team *team1, Team *team2)
    {
        if(team1->wins== team2->wins)
        {
            return cmpByPoints()(team1, team2);
        }
        return (team1->wins> team2->wins);
    }
};

struct cmpByAvg
{
    inline bool operator() (Team *team1, Team *team2)
    {
        return (team1->scored_points / 38 > team2->scored_points / 38);
    }
};