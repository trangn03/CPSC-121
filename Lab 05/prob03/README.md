# Digicup
This program simulates interactions with a `Cup` object for getting a drink, refilling a drink, emptying a drink, and drinking from it.

## Output
All of the output statements (`std::cout`) should be in `main` and are mostly provided for you. You will only need to complete the menu functionality by calling the appropriate member functions from the `Cup` object. Your member functions are designed to only perform calculations and return values.

The `Cup` object will be used to ask the user for the type of drink they prefer and the amount they want to drink.

The menu options are shown below for your reference:

```
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
```

## The `Cup` class
### Data members
Create a class called `Cup` with the following member variables:

1. `drink_type_` which is an `std::string` that will be the name of the drink.
1. `fluid_oz_` which is a `double` that will be the amount of fluid in the cup.

### Constructors
#### Default constructor
The default constructor should initialize `drink_type_` to `"Water"` and initialize `fluid_oz_` to `16.0`.

#### Non-default constructor
The non-default constructor should take in an `std::string` parameter that will be the name of the drink type and a `double` parameter that will be the amount of drink in the cup. It should set the passed parameter values to the corresponding data members.

### Member functions
#### ``Drink``
Drinking reduces the amount of liquid in the `Cup` based on a given `amount` that is passed as a parameter. Take note that `fluid_oz_` should never be negative such that if you drink an `amount` that is greater that `fluid_oz_`, then `fluid_oz_` should be set to `0`.

##### ``Refill``
Refilling the cup increases the amount of liquid in the `Cup` based on the given parameter, `amount`. Assume the cup is bottomless.

##### ``NewDrink``
Throw out your current drink and replace it with a new drink. The function accepts two parameters. The first is the name of the new drink type and the second is the amount of the new drink type.

##### ``Empty``
*Empties out* the contents of the cup in its entirety. `fluid_oz_` should be set to 0, and `drink_type_` should be set to `"nothing"`.

##### Accessors
Create the accessors for `fluid_oz_` and `drink_type_`, ``GetFluidOz`` and ``GetDrinkType``.

## Other information
Place the `Cup` class prototypes in `cup.h` and implementation in ``cup.cc``, and complete the code in `main.cc` (labeled 1-5).

## Compilation

This program can be compiled by linking to ``main.cc`` and ``cup.cc``:

```
clang++ -std=c++17 main.cc cup.cc -o main
./main
```

## Sample Output
<pre>
What kind of drink can I get you?: <b>Kool Aid</b>
How much do you want?: <b>32</b>
Your cup currently has 32 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>16</b>
Your cup currently has 16 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>6</b>
Your cup currently has 10 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>R</b>
How much do you want to refill your cup?: <b>2</b>
Your cup currently has 12 oz. of Kool Aid
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>E</b>
Emptying your cup
Your cup currently has 0 oz. of nothing
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>N</b>
What is the new drink you want?: <b>Coke</b>
What is the amount you want?: <b>16</b>
Your cup currently has 16 oz. of Coke
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>D</b>
How much do you want to drink from the cup?: <b>8</b>
Your cup currently has 8 oz. of Coke
Please select what you want to do with your drink/cup?:
D: Drink
R: Refill
N: Get a brand new drink
E: Empty
X: Exit
Selection: <b>X</b>
Thank you for using Digicup!
</pre>

# Submission checklist
1. Created function prototype and stored in `.h` file.
1. Created function implementation and stored in `.cc` file (see [reference](https://github.com/ILXL-guides/function-file-organization)).
1. Create objects and call methods in the driver.
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readbility (`make formatcheck`).

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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cc`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc cup.cc -o main
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

We recommend pushing to GitHub frequently to back up your work.
