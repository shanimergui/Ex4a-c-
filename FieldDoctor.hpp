#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class FieldDoctor: public Player{
    public:
      FieldDoctor(Board board_,City city_):Player(board_,city_,"FieldDoctor"){}
      Player& treat(City c) override;
  };
}
