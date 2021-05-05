#pragma once
#include <iostream>
#include <unordered_map>
#include "City.hpp"

using namespace std;

namespace pandemic{
  class Board{
    private:
      unordered_map<City,int> diseasCubes;
    public:
      Board(){}
      bool is_clean();
      int & operator[](City city);
      friend ostream& operator<<(ostream& os,const Board& board);
  };
}
