# Pointer Problems

In this lab you will complete a series of pointer-related functions in ``pointer_utils.cc`` and then call those functions from ``main.cc``.

You do not need to edit ``pointer_utils.h``.

You may prefer do these one at a time (finish the function in pointer_utils.cc and call the function from main.cc) in order to manually test with ``./main`` as you go.

## Negate

The ``Negate`` function takes a pointer to a ``bool`` and negates the boolean at that address. So if you pass it a pointer to a boolean with value ``true`` it should in-place change that boolean to be a ``false``.

## Increment

The ``Increment`` function takes a pointer to an ``int`` and adds one to the integer at that address. So if you pass it a pointer to a integer with value ``3`` it should increment it in-place, causing the value at that address to become ``4``.

## ComputeSum

The ``ComputeSum`` function takes pointers to two different ``double``s and returns their sum.

## Swap

The ``Swap`` function takes pointers to two different integers and swaps the values at that address. So if you pass it a pointer to an integer with value ``42`` and a pointer to an integer with value ``34`` it would cause the first integer to be ``34`` and the second to become ``42``.

## MakeSus

The ``MakeSus`` function takes a pointer to a ``std::string`` and modifies it in-place by appending the substring " is sus" ("sus" is short-hand for "suspicious"). Note the space at the beginning of the appended string.

## GetLongestString

The ``GetLongestString`` function takes a pointer to a ``std::vector<std::string>`` and returns a pointer to the longest string in the vector, or ``nullptr`` if the vector is length 0.

You can use the ``std::vector`` member functions ``at(int index)`` to access elements of the vector from its pointer, or the square bracket notation on the dereferenced pointer, and use ``size()`` to get the size of the vector.

Make sure to return a pointer to the longest string with the vector.

## Complete main.cc

For each of the six functions, complete the ``TODO`` sections in ``main.cc`` to call the function with the parameters.

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc pointer_utils.cc -o main
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Completed `pointer_utils.cc`.
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and `pointer_utils.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc pointer_utils.cc -o main
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
