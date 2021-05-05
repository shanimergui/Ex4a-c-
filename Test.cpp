#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "OperationsExpert.hpp"
#include "Virologist.hpp"
#include "Researcher.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "Dispatcher.hpp"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
using namespace pandemic;

TEST_CASE("Test OperationsExpert"){
  Board b;

  OperationsExpert player {b,City::Tokyo};
  CHECK_NOTHROW(player.take_card(City::Sydney)
	      .take_card(City::HoChiMinhCity)
	      .take_card(City::HongKong)
	      .take_card(City::Bangkok));
  CHECK_THROWS(player.discover_cure(Color::Yellow));
  CHECK_NOTHROW(player.take_card(City::Santiago));
  CHECK_NOTHROW(player.build());
  CHECK_NOTHROW(player.take_card(City::SaoPaulo).fly_direct(City::SaoPaulo));
  CHECK(player.role()=="OperationsExpert");
}

TEST_CASE("Test Dispatcher and Virologist"){
  Board b;
  Dispatcher shani{b,City::Tokyo};
  Virologist avi{b,City::Tokyo};

  CHECK_NOTHROW(shani.take_card(City::Seoul).take_card(City::Shanghai).take_card(City::HongKong));
  CHECK_NOTHROW(avi.take_card(City::Seoul).take_card(City::Shanghai));

  CHECK_THROWS(shani.drive(City::HongKong));
  CHECK_NOTHROW(shani.drive(City::Shanghai));
  CHECK_NOTHROW(shani.drive(City::HongKong));
  CHECK_NOTHROW(shani.build());
  CHECK_NOTHROW(shani.drive(City::Shanghai));
  CHECK_THROWS(shani.drive(City::HongKong));
  CHECK_NOTHROW(shani.drive(City::Tokyo));
  CHECK_NOTHROW(shani.build());
  CHECK_NOTHROW(shani.take_card(City::HongKong));
  CHECK_NOTHROW(shani.fly_direct(City::HongKong));
  CHECK_NOTHROW(shani.drive(City::Shanghai));
  CHECK_NOTHROW(shani.drive(City::HongKong));


  CHECK_NOTHROW(avi.treat(City::Seoul));
  CHECK_THROWS(avi.discover_cure(Color::Red));
  //card not exsist
  CHECK_THROWS(avi.fly_shuttle(City::HongKong));

}

TEST_CASE("Test GeneSplicer"){
  Board b;
  GeneSplicer shani{b,City::Tokyo};
  CHECK_NOTHROW(shani.take_card(City::Seoul).take_card(City::Shanghai).take_card(City::HongKong)
  .take_card(City::Delhi).take_card(City::Mumbai));
  CHECK_NOTHROW(shani.build());
  CHECK_NOTHROW(shani.discover_cure(Color::Red));


}
TEST_CASE("Test Medic"){
  Board b;
  Medic shani{b,City::Tokyo};
  CHECK_NOTHROW(shani.take_card(City::Seoul).take_card(City::Shanghai).take_card(City::HongKong)
  .take_card(City::Delhi).take_card(City::Mumbai));
  CHECK_NOTHROW(shani.build());
  CHECK_THROWS(shani.discover_cure(Color::Red));


  CHECK_NOTHROW(shani.take_card(City::Beijing).take_card(City::Manila));
  CHECK_NOTHROW(shani.discover_cure(Color::Red));
}

TEST_CASE("Test FieldDoctor"){

  Board b;
  CHECK(b.is_clean()==true);
  b[City::Lima] = 2;
  CHECK(b[City::Lima] == 2);
  CHECK(b.is_clean()==false);
  //conctractur
  FieldDoctor shani{b,City::Santiago};
  //take_card function get city
  CHECK_NOTHROW(shani.take_card(City::Bogota).take_card(City::BuenosAires).take_card(City::Miami)
  .take_card(City::SaoPaulo).take_card(City::Lima));
  //current city is santigao treat to lime city connect to santigo
  CHECK_NOTHROW(shani.treat(City::Lima));
  CHECK(b[City::Lima] == 1);
  //current city is santigao treat to SaoPaulo city not connect to santigo
  CHECK_THROWS(shani.treat(City::SaoPaulo));
}
// TEST_CASE("Test Scientist"){
//   Board b;
//   Scientist shani{b,City::NewYork};
//   CHECK_NOTHROW(shani.take_card(City::London).take_card(City::Paris).take_card(City::Chicago)
//   .take_card(City::Essen).take_card(City::Milan));
//    CHECK_NOTHROW(shani.build());
  

// }
