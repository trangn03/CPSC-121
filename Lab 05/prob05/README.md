# Rectangle Class
Create a `Rectangle` class that has two data members: int `length_` and int `width_`. Create the corresponding accessor and mutator functions to access and change both data members.

Create a member function `Area` that returns the area of the `Rectangle` object. Finally, create a function `LongestRectangle` that accepts two `Rectangle` objects as parameters and returns the `Rectangle` object with the longer length.

Write the `Rectangle` class and the `LongestRectangle` function prototype in `rectangle.h`. Take note that `LongestRectangle` is not a member function of the `Rectangle` class. Provide the function's implementation in `rectangle.cc`.

Complete `main.cc` according to the comments provided in the file.

# Sample Output:
<pre>
Rectangle 1
Please enter the length: <b>2</b>
Please enter the width: <b>3</b>
Rectangle 1 created with length 2 and width 3
The area of Rectangle 1 is: 6

Rectangle 2
Please enter the length: <b>4</b>
Please enter the width: <b>5</b>
Rectangle 2 created with length 4 and width 5
The area of Rectangle 2 is: 20

The longest rectangle has a length of 4, a width of 5, and an area of 20.
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `rectangle.cc` and `main.cc`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc rectangle.cc -o main
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
