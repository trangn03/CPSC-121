# Dice rolling

Create a game that lets the user roll three six-sided dice to try to get a Yahtzee, that is, a three-of-a-kind. (Rolling five dice, like the real game, will take too long!)

Here's an example of how the game will be played (from ``./main``):

```
Do you want to roll? y/n y
2 5 4     
Do you want to roll again? y
2 6 2
Do you want to roll again? y
5 5 5
Yahtzee!
Do you want to roll again? n
Goodbye!
```

## Create the ``Dice`` class

The ``Dice`` class should have two public functions, a void function ``Roll()`` and an integer function ``GetValue()``. It needs one member variable to store the current value.

When the ``Roll`` function is called, the current value should be updated using the ``rand()`` function found in ``<stdlib.h>`` [reference](http://www.cplusplus.com/reference/cstdlib/rand/). ``rand()`` returns a very large integer, so you will need to convert it to a number between 1 and 6 (inclusive).

Reference [functions review](https://github.com/ILXL-guides/function-file-organization) if you are wondering what to put in ``dice.h`` and ``dice.cc``.

## Create the ``PlayYahtzee`` function

``PlayYahtzee`` should create three dice. It may make sense to store these in a ``std::vector``.

Place the function prototype in ``dice.h`` and the definition in ``dice.cc``.

While the user hasn't entered "n", you should re-roll all three dice, print out their values (separated by a space), and then check if they are a Yahtzee (if they are all three the same value). See the sample input/output above for the expected syntax. When they are a Yahtzee, print out "Yahtzee!". Then ask the user if they want to roll again.

## Try your program

Compile with:

```
clang++ -std=c++17 main.cc dice.cc -o main
```

Try running main to play the game!

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
clang++ -std=c++17 main.cc dice.cc -o main
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
