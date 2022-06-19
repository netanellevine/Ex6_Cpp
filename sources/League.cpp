//
// Created by netanel on 6/18/22.
//

#include "League.hpp"
#include "Stats.hpp"
#include <algorithm>

static int name = 1;

League::League()
{
    this->teams.reserve(MAX_SIZE);
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        this->teams.emplace_back(new Team("Team" + std::to_string(name++), random_skill()));
    }
    this->curr_schedule = new Schedule();
    this->curr_schedule->update(this->teams);
}

League::League(std::vector<Team *> teams)
{
    this->teams.reserve(MAX_SIZE);
    if (teams.size() == MAX_SIZE) {
        this->teams = std::move(teams);
    }
    else
    {
        for (auto & team : teams)
        {
            this->teams.emplace_back(team);
        }

        for (size_t i = teams.size(); i < MAX_SIZE; i++)
        {
            this->teams.emplace_back(new Team("Team" + std::to_string(name++), random_skill()));
        }
    }
    this->curr_schedule = new Schedule();
    this->curr_schedule->update(this->teams);
}

League::League(const League &other) {

}

League::~League()
{
    delete this->curr_schedule;
    for (auto &i: this->teams)
    {
        delete i;
    }
}

void League::start_season()
{
    for (auto &curr_round : *(this->curr_schedule))
    {
        for (auto &game : curr_round)
        {
            game.play();
        }
    }
}

void League::printRoster()
{
    cout << "=========== LEAGUE ROSTER ===========" << endl;
    for (auto &i: this->teams)
    {
        cout << i->name << std::endl;
    }
    cout << "=====================================" << endl;
}

void League::printSchedule() const  {
    cout << "=========== LEAGUE SCHEDULE ===========" << endl;
    for (Round &curr_round: this->curr_schedule->Rounds())
    {
        for (Game &game: curr_round)
        {
            cout << game.home->name<< " vs " << game.outdoor->name << endl;
        }
    }
    cout << "=======================================" << endl;
}

void League::printTopTeams() const  {
    vector<Team *> sorted_teams = this->teams;
    sort(sorted_teams.begin(), sorted_teams.end(), cmpByWins());
    cout << "=========== FINAL LEAGUE STANDINGS BY WINS ===========" << endl;
    for(size_t i = 0; i < sorted_teams.size(); i++) {
        cout << i+1 << ". " << sorted_teams.at(i)->name << " ->" << sorted_teams.at(i)->wins << " total wins." << endl;
    }
}

void League::printTopByPoints() const  {
    vector<Team *> sorted_teams = this->teams;
    sort(sorted_teams.begin(), sorted_teams.end(), cmpByAvg());
    cout << "=========== FINAL LEAGUE BY POINT RANKING ===========" << endl;
    for(size_t i = 0; i < sorted_teams.size(); i++) {
        cout << i+1 << ". " << sorted_teams.at(i)->name << " -> " << sorted_teams.at(i)->scored_points / 38 << " points per game." << endl;
    }
}

int League::printPositiveScoreTeams()  {
    int score_ratio = 0;
    for (Team *team: this->teams) {
        if (team->scored_points / team->points_lost > 0) {
            score_ratio++;
        }
    }
    cout << "No Of Teams Who Have A Positive Score Ratio: " << score_ratio << endl;
    return score_ratio;
}