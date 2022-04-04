# Class Average
Create a program that dynamically creates a vector whose size depends on the user's preference. Pass the vector to a `calculate_avg` function that is responsible for computing the average GPA of the given vector.

### calculate_avg
Implement a function called `CalculateAvg` in ``calculate_avg.cc`` that calculates the average of a `double` vector and returns that average.

`CalculateAvg()` will have one parameter, a `std::vector<double>&` referring to the vector.

When the vector is size is greater than 0, the function should calculate the average GPA from the given vector of grades.

However, when the size of the vector is 0, then the function should return 0.

### main
The `main` function has mostly been built for you. It is your task to dynamically create a `double` vector, store users' grades into the vector, and pass the vector to `CalculateAvg` to compute and then display the students' average GPA. Read the instructions in `main.cc` for more details.

If the user happens to provide a class size of `0`, then the program should output `"You have no class!"` and then end the execution of the program without attempting to calculate the average.

Place the `CalculateAvg`'s function's' implementation in `calculate_avg.cc`. We have provided the prototype in `calculate_avg.h`.

# Sample Output
<pre>
How many students are in your class? <b>5</b>
Enter the GPA for the students in your class (0.0 - 4.0)
Enter the GPA for student #1: <b>3.8</b>
Enter the GPA for student #2: <b>2.5</b>
Enter the GPA for student #3: <b>4.0</b>
Enter the GPA for student #4: <b>1.9</b>
Enter the GPA for student #5: <b>3.6</b>
Class average: 3.16
</pre>

<pre>
How many students are in your class? <b>0</b>
You have no class!
</pre>

## Compile

You need to include ``calculate_avg.cc`` when compiling so that clang can find the implementation of CalculateAvg:

```
clang++ -std=c++17 main.cc calculate_avg.cc -o main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

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
