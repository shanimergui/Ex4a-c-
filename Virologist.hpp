#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Virologist: public Player{
    public:
      Virologist(Board board_,City city_):Player(board_,city_,"Virologist"){}
      Player& treat(City c) override;
  };
}
