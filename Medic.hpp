#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Medic: public Player{
    public:
      Medic(Board board_,City city_):Player(board_,city_,"Medic"){}
      Player& treat(City c) override;
  };
}
