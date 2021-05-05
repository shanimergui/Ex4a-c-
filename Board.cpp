#include "Board.hpp"
namespace pandemic{
  bool Board::is_clean(){
    return false;
  }
  int & Board::operator[](City city){
    return diseasCubes[city];
  }
  ostream& operator<<(ostream& os,const Board& board){
    return os;
  }
}
