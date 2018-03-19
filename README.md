# Jeopardy Dice in C++

This assignment is _almost_ just like the Python version. It isn't
super critical that you've done that one. But if you have... the main
differences are:

1. There are unit tests for the functions that return values.
2. You must babysit the random number seed.
3. The `main` function is in its own file.
4. The `take_turn` function takes a `bool` and an `int` (just to clarify).

I'll explain those differences at the end of the file, so if you're
feeling impatient, you can just skip to the 'Unit Tests' section.

First, I'll re-explain the assignment.

## Game Objective

Two players take turns until one of them has reached 100 points. One
player is human, the other is the computer. The human player always
starts.

Each turn goes like this:

1. Roll a 6-sided die; if it comes up 1, the player's score for the
   entire round is 1 and play is ceded to the other player.

2. If it comes up with 2--6, the value of the die is added to their
   score for the turn (the score starts off at zero).

3. After rolling a 2--6, the player can choose to 'hold', or roll
   again (go back to step 1). The computer chooses to roll until its
   score is at or above some threshold, in which case it chooses to
   hold. Human players are prompted for their choice.

4. If the player holds, their current score for the turn is added to
   ther overall score.

## Getting User Input

As a recap, here's one way to get user input. You have to declare the
string variable before it is used.

```cpp
string answer;
cin >> answer;
if (answer != "y") {
  // treat this as a 'no'.
}
```

## Example

The file sample-output-1.txt in this directory has a recording of a
particularly stunning and rousing game of Jeopardy Dice. Consult it to
get a sense of how the game proceeds.

## Unit Tests

To run the unit tests, first run 

```
$ make
``` 

from the command line, and if it completes without errors, it creates
an executable `jeopardy_test`. You can run it directly:

```
$ ./jeopardy_test
```

The preferred way to run the tests is with the python grading script,
however:

```
$ python grade.py jeopardy_test
```

I recommend that your first step should be to get all the tests to
work except for "turn". Once they work, then go ahead with the
`take_turn` function.

When the unit tests play the game, the human player will always hit
'y' three times, then 'n'.

## Running the Game

Once you have something worth playing, here's an easy way to build the
project and (if it built) run the game immediately:

```bash
$ make jeopardy_main && ./jeopardy_main
```

This command tries to build the `jeopardy_main` binary. If it can't
(maybe there's a syntax error?), it just stops there. But if it does,
it then immediately executes the program. Double ampersands are the
bomb.

## Random Numbers

There are at least two ways to do random numbers in C++. One is to
`include <random>`, but this forces you to pass random number
generators around. The function signatures don't allow for that. So
instead I recommend you use the older C-style functions.

First, `#include <cstdlib>` and `#include<ctime>` at the top of your
implementation file. That tells the compiler to give you access to
some library functions. The functions we're interested in are `srand`,
`rand`, and `time`.

`srand` seeds the system (globally) with an initial state for its
random number sequence. If you don't do this, you'll get the same
"random" sequence every time. To seed the random number generator (in
the `initialize_randomness()` function, just have the line
`srand(time(NULL));`. This uses the current time as the seed, so every
time you run it you'll get a different "random" sequence.

You should implement the `initialize_randomness` function (it should
be two lines), and call it from the top of your `main` function, but
not from anywhere else.

To get a random number between `0` and `RAND_MAX` (which is
a [big number](https://en.wikipedia.org/wiki/2,147,483,647), on my
system it happens to be `2,147,483,647`), or between `0` and a more
reasonable number like `100`, follow this general pattern:

```cpp
int gigantic = rand();         // rand() gives int from 0 to 2,147,483,647
int smaller = gigantic % 100;  // squish it to a random from 0--99 inclusive
int pct = smaller + 1;         // final number in range from 1 to 100 inclusive
int pct2 = (rand() % 100) + 1; // same as previous 3 lines, in compact form
```

## Main Function

Speaking of main... there's actually two files for your implementation
to live: `jeopardy_main.cpp` for the `main` function, and
`jeopardy.cpp` for everything else.

The reason for this has to do with how C and C++ produces the
intermediate binary objects and the final executable. The unit test
program has its own main function, but so does your interactive
program. So what's a hacker to do? Answer:

```
jeopardy.cpp + jeopardy_main.cpp ---> jeopardy_main
jeopardy.cpp + jeopardy_test.cpp ---> jeopardy_test
```

This is roughly what the Makefile does for you. It combines all the
functions in your `jeopardy.cpp` file plus the functions from
somewhere else to produce an executable with exactly one main function
in it.

There's nothing really brain-melty going on here; it is just splitting
the program up into different files. Read the comments in
`jeopardy_main.cpp` for more guidance.

To compile and link the interactive game binary, run this command:

```
$ make jeopardy_main
```

And to complie and link the unit tests, just run `make` without any
other arguments.

## Take Turn Function

The `take_turn` function now has this signature:

```
int take_turn(bool is_user_turn, int computer_hold_threshold);
```

When it is the computer's turn you should check if the current score
is greater than or equal to `computer_hold_threshold`, and if it is,
the computer holds.

