#pragma once
#include <unordered_set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
  class Player{
  private:
    Board board;
    City city;
    unordered_set<City> cards;
    string playerRole;
  public:
    Player(Board board_ ,City city_,string role_):board(board_),city(city_),playerRole(role_){}

    Player& take_card(City c);
    string role();
    Player& drive(City c);
    Player& fly_charter(City c);
    Player& fly_shuttle(City c);

    virtual Player& build();
    virtual Player& fly_direct(City c);
    virtual Player& discover_cure(Color c);
    virtual Player& treat(City c);
  };
}
