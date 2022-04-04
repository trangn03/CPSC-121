# Utensil classes
This program uses three classes: `Utensil`, `Spoon`, and `Food`.

## Utensil class
Create a `Utensil` class with two data members: `double` `size_`, and `std::string` `color_`.

Create a default constructor for `Utensil` that sets the size to `8.5` and its color to `"silver"`.

Create a constructor that receives a `double` size and `std::string` color that sets `size_` and `color_` accordingly.

Create accessor and mutator functions for both data members,  `Size`, `SetSize`, `Color` and `SetColor`.

Create a function `Use` that receives a reference to a `Food` object, but does nothing to it (i.e., the member function's body is empty).

## Spoon class
`Spoon` inherits from `Utensil` and has an additional data member, a `double` `bite_size_`.

Create a default constructor for `Spoon` that sets the size to 6, color to silver and `bite_size_` to 25.

Create a nondefault constructor that receives a `double` size, an `std::string` color, and a `double` bite_size then assigns the values to the data member accordingly.

Create an accessor and mutator function for the data member `bite_size_`, `BiteSize` and `SetBiteSize`.

Create a function `Use` that receives a reference to a `Food` object and removes *`bite_size_` grams* of mass from the object (i.e., eating the food). You will need to call that object's `eat` member function and provide the appropriate arguments.

## Food class
Create a `Food` class with two data members, an `std::string` `name_` and `double` `mass_` (in grams).

Create a default constructor for `Food` that sets the name to ``"Apple Pie"`` and mass to `1000`.

Create a constructor that receives an `std::string` name and `double` mass.

Create accessor and mutator functions for both data members, `name_` and `mass_`, `Name`, `SetName`, `Mass`, and `SetMass`.

Create a function `Eat` that receives a `double` and subtracts it from `mass_` if there is enough left. Otherwise, set the mass to 0 (can't have a negative mass of an object).

Create a function `Print` that prints the food's name and mass.

## Other instructions
Complete the `main` function as described. Place your classes prototypes in `utensils.h`, and implement them in `utensils.cc`.

## Sample Output:
<pre>
Please enter the name of a food item: <b>Pumpkin Pie</b>
Please enter the mass of the food item: <b>1250</b>
Please enter the size of the spoon: <b>5</b>
Please enter the color of the spoon: <b>gold</b>
Please enter your bite size using the spoon: <b>20</b>
Food before being eaten:
Pumpkin Pie 1250g
Food after spoon used:
Pumpkin Pie 1230g
</pre>

# Submission checklist
1. Created function prototype and stored in `.h` file.
1. Created function implementation and stored in `.cc` file (see [reference](https://github.com/ILXL-guides/function-file-organization)).
1. Call function in the driver
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `utensils.cc` and `main.cc`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc utensils.cc -o main
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
