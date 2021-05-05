#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
namespace pandemic{
  class Scientist: public Player{
    private:
    int n;
    public:
      Scientist(Board board_,City city_,int n_):Player(board_,city_,"Scientist"),n(n_){}
      Player& discover_cure(Color c) override;
  };
}
