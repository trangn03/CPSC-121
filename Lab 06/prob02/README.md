# Recursion Problemset

In this lab you will complete three recursive problems. These problems seem easy to solve with loops, but you must use recursion instead. This is to practice the thought process of coming up with a recursive solution. You will not get credit for solving these problems without recursion even if all the tests pass.

We've written the function prototypes in ``recursion.h`` and some code in ``main.cc`` that lets you try out your functions. All you need to do is implement the functions in ``recursion.cc``.

You should build and run ``main`` frequently to test your work. You can even run it now to see how it will work, although none of the functions are implemented yet!

## Run the program (yes, you can try now!)

To manually test your code you can compile and run by linking to ``main.cc`` and ``recursion.cc``:

```
clang++ -std=c++17 main.cc recursion.cc -o main
./main
```

You can pick which function to try and follow the prompts. All input should be integers greater than or equal to zero. We will not test your functions with negative integers.

## 1. Recursively determine if a number is even in ``IsEven``

We know that zero is even, and that each number after zero alternates odd and even. Use this information to determine your recursive solution with a base case and a recursive case.

## 2. Recursively raise an integer to a power in ``RaiseIntToPower``

Any integer raised to the power of zero is 1. In addition, for any `n`, we know that `n ^ k` is equal to `n * n ^ (k - 1)`. Use this information to determine your recursive solution with a base case and a recursive case.

## 3. Recursively sum the integers in an array in ``SumArray``

An empty array has a sum of zero, and an array of elements is just the first element plus the sum of the rest of the array. Use this information to determine your recursive solution with a base case and a recursive case.

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Filled in function definitions in ``recursion.cc`` using recursion.
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cc` and `recursion.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc recursion.cc -o main
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
