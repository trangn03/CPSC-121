# Pair Template
In this program, you will be creating a class that utilizes class templates.

**Important note: The compiler needs the implementation of all template functions to create a templated class. The easiest way to ensure this is to have all the code in the header file instead of splitting them into a header and implementation file. For this problem, make sure to place all your code in pair_class_template.h**

## MyPair Template Class
Create a class called `MyPair` that uses `template <class T>` and will have the following:

### Private Member Variables
1. `value1_` which is a `T` object.
1. `value2_` which is a `T` object.

### Non-Default Constructor
Create a non-default constructor that takes in two `T` objects as parameters
and initializes the values to the data member variables respectively.

### Accessors
Create accessors for both data members, `GetValue1` and `GetValue2`.

### Display Member Function
Create a member function called `Display()` that will display the member variables
in the order shown in the output below.

    [value1, value2]

### Display Reverse Member Function
Create a member function called `DisplayReverse()` that will display the member
variables in reverse order as shown in the output below.

    [value2, value1]

### Max Value Member Function
Create a member function called `MaxValue()` that will return a `T` object.
This member function should compare the two member variable values and return
the greater value (if the values are equal, return the second value).

### Min Value Member Function
Create a member function called `MinValue()` that will return a `T` object.
This member function should compare the two member variable values and return
the lesser value (if the values are equal, return the second value).

### Swap Value Member Function
Create a member function called `SwapValue()` that will swap the two member
variable values.

## Other instructions
Complete the `main` function as described. Place your classes in `pair_class_template.h`. Member functions that take more than five lines or use complex constructs should have their function prototype in `pair_class_template.h` and implementation in `pair_class_template.cc`.

# Sample Output
```
[3, 5]
[5, 3]
5
3
[5, 3]
[3, 5]
[9.7, 6.4]
[6.4, 9.7]
9.7
6.4
[6.4, 9.7]
[9.7, 6.4]
[a, z]
[z, a]
z
a
[z, a]
[a, z]
```
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `pair_class_template.cc` and `main.cc`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc pair_class_template.cc -o main
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
