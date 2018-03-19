/***
 *      _                             _      
 *     <_> ___  ___  ___  ___  _ _  _| | _ _ 
 *     | |/ ._>/ . \| . \<_> || '_>/ . || | |
 *     | |\___.\___/|  _/<___||_|  \___|`_. |
 *    <__'          |_|                 <___'
 *       _  _                                
 *     _| |<_> ___  ___                      
 *    / . || |/ | '/ ._>                     
 *    \___||_|\_|_.\___.                     
 *                                           
 */

// initialize_randomness is a setup function that should be called one
// time at the beginning of your program execution that should seed
// the random number generator. It is important to do the seeding in
// this function and NOT in your main() function because the unit
// tests won't run your main() function (or play_game() for that
// matter).
//
// it should return true (so the unit tests know you've done it).
bool initialize_randomness();

// print_current_player prints a statement indicating whose turn it is.
//
// If it is the computer's turn, it prints "It is now computer's
// turn", and if it is the user's turn it should print "It is now
// human's turn".
void print_current_player(bool is_user_turn);

// roll_die returns a random number between one and six (inclusive).
int roll_die();

// take_turn simulates a single turn for either the user (if
// is_user_turn is true), or for the computer (if is_user_turn is
// false) and returns the number of points earned during this turn.
//
// A turn is governed by the following rules:
//
// 1. The player rolls a six sided die.
//
// 2. If the roll is 1, the player gets one point and their turn
// automatically ends. Even if the player accumulated points from
// previous rolls, if they roll a 1 their score for the entire turn
// will only be one point.
//
// 3. If the roll is any other number, the roll score is added to the
// turn total.
//
// 4. Following a non-1 roll, the player has the option to continue
// rolling or to stop rolling, also known as 'holding'. There is no
// restriction on how many times a player can roll in a turn. If the
// player is human, it asks if they'd like to roll again. If the
// player is the computer, it will hold if the turn's score is equal
// to or greater than computer_hold_threshold.
//
// 5. If the player holds, the accumulated turn's score is
// returned. For example, if the player rolled a 3, 4, and 2, then
// decides to hold, the turn yields 9 points.
int take_turn(bool is_user_turn, int computer_hold_threshold);

// report_points prints a report of how many points each player
// has. Example:
//
// human: 6
// computer: 10
void report_points(int human_total, int computer_total);

// get_next_player returns the opposite of the value passed
// in. E.g. if is_user_turn is true, the function returns false.
bool get_next_player(bool is_user_turn);

// play_game is the function that starts an interactive session
// pitting human vs. machine. This will be called from
// jeopardy_main.cpp:main(). You should treat this as the surrogate
// for a main function.
//
// Note that this function isn't tested, but you still have to
// implement it so that the game is playable.
void play_game();
