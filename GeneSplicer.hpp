#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class GeneSplicer: public Player{
    public:
      GeneSplicer(Board board_,City city_):Player(board_,city_,"GeneSplicer"){}
      Player& discover_cure(Color c) override;
  };
}
