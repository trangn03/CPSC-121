# Tic Tac Toe

Tic-tac-toe is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner ([Wikipedia](https://en.wikipedia.org/wiki/Tic-tac-toe)).

We've provided a ``main.cc`` which gets input from the user and draws a tic-tac-toe board. Users take turns entering their preferred move into the terminal until one of the player wins or no spaces are left.

**Your task is to implement the function ``CheckGame`` in ``tic_tac_toe.cc`` which will determine if the game is over, and if so, the result.**

## Implement CheckGame

Here is the function prototype for ``CheckGame`` defined in `tic_tac_toe.h`:

```cpp
// Return 1 if player 1 wins, 2 if player 2 wins, 0 if no one has won but
// there's still space, and -1 if the board is full.
int CheckGame(std::vector<std::vector<int>>& game);
```

Here the ``game`` parameter is a vector of vectors. Specifically, ``game[0]`` is a ``vector<int>`` which represents the first row in the board, ``game[1]`` is a ``vector<int>`` representing the second row, and ``game[2]`` represents the third row.

Each number in the ``game`` grid represents the state of a cell in the board. ``0`` means no one has played that square, ``1`` means player 1 has gone there, and ``2`` means player 2 has gone there.

For example, in the grid below, you could access the bottom left cell (value `1`) with ``game[2][0]`` or the middle cell (value `2`) with ``game[1][1]``.

```
 0 0 0
 0 2 0
 1 0 0
```

Your task is to look at the ``game`` and determine whether someone has won. Return ``1`` if player 1 has won, ``2`` if player 2 has won, ``0`` if no one has won but there are still empty spaces, or ``-1`` if there are no empty spaces and no one has won.

Here are some example situations.

No one has won yet, return 0:
```
 0 0 0
 0 1 0
 0 0 2
```

Player 1 wins horizontally, return 1:
```
 0 0 2
 1 1 1
 0 2 0
```

Player 2 wins vertically, return 2:
```
 1 0 2
 0 1 2
 0 0 2
```

Player 1 wins diagonally, return 1:
```
 0 2 1
 2 1 0
 1 0 2
```

No one wins and no space left, return -1
```
 1 2 1
 2 1 2
 2 1 2
```

## Try playing tic tac toe

You can run ``make build`` to build tic tac toe, and ``./main`` to run it. ``main.cc`` will use your function to check the game. Enter your input into the command line. Use "ctrl" + "c" in the terminal if you want to cancel execution early.

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission

We recommend pushing to Github frequently to back up your work.
