#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "jeopardy.h"
#include <string>
#include <time.h>

using namespace std;

TEST_CASE("Jeopardy Dice: sanity check", "[sanity]") {
  REQUIRE(true);
}

TEST_CASE("Jeopardy Dice: initialize random seed", "[seed]") {
  REQUIRE(initialize_randomness());
}

TEST_CASE("Jeopardy Dice: roll dice", "[roll]") {
  REQUIRE(initialize_randomness());
  int numOne = 0;
  int numSix = 0;
  for (int i=0; i < 1000; i++) {
    int result = roll_die();
    REQUIRE(result >= 1);
    REQUIRE(result <= 6);
    if (result == 1) {
      numOne++;
    }
    if (result == 6) {
      numSix++;
    }
  }
  REQUIRE(numOne > 0); // it is mathematically possible for this to
  REQUIRE(numSix > 0); // fail, but it is super duper not likely.
}

TEST_CASE("Jeopardy Dice: take a turn", "[turn]") {
  initialize_randomness();
  std::streambuf* orig = std::cin.rdbuf();
  for (int i=0; i < 100; i++) {
    std::istringstream input("yyyn");
    std::cin.rdbuf(input.rdbuf());
    int result = take_turn(true, 0);
    cout << "result from human turn: " << result << endl;
    REQUIRE(result >= 1);
    REQUIRE(result <= 24); // initial roll plus three more maxes out at 24.
  }
  std::cin.rdbuf(orig);
  for (int i=0; i < 100; i++) {
    int result = take_turn(false, 14); // last turn might start at 13
    REQUIRE(result >= 1);
    REQUIRE(result <= 19); // 13 + 6 == 19
  }
}

TEST_CASE("Jeopardy Dice: get next player", "[next]") {
  REQUIRE(get_next_player(true) == false);
  REQUIRE(get_next_player(false) == true);
}
