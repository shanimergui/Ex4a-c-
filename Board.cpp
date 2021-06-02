#include "Board.hpp"
namespace pandemic{
  bool Board::is_clean(){
    return false;
  }
  int & Board::operator[](City city){
    return diseasCubes[city];
  }
   void Board::remove_cures(){

   }
  ostream& operator<<(ostream& os,const Board& board){
    return os;
  }
}
