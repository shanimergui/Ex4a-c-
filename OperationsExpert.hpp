#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class OperationsExpert: public Player{
    public:
      OperationsExpert(Board board_,City city_):Player(board_,city_,"OperationsExpert"){}
      Player& build() override;
  };
}
