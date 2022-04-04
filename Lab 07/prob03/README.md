# Fibonacci Sequence Function
Create a recursive Fibonacci sequence function called `Fibonacci` that receives an `int` parameter. The function should return the nth number in the Fibonacci sequence.

Although Fibonacci can be solved iteratively, you must solve this problem with recursion.

## Base and Recursive Case

The Fibonacci sequence is composed of numbers in which each number is the sum of the two preceding numbers.

`1, 1, 2, 3, 5, 8, 13, ...`

The nth Fibonacci number can be generated using a recursive function such that

```
Fibonacci(n) = 0                                if n == 0       // base case
             = 1                                if n == 1       // base case
             = Fibonacci(n-1) + Fibonacci(n-2)  if n > 1        // recursive case
```

### Output

Complete the `main` function, to retrieve user input and display the appropriate text as shown below. The Fibonacci number should be generated by the `Fibonacci` function whose returned value is added to the screen output.

Make sure that the ordinal indicator (-st -nd -rd -th) matches with the given n

* 1 -> 1st
* 22 -> 22nd
* 33 -> 33rd
* 11 -> 11th, 12 -> 12th, 13 -> 13th
* 5 -> 5th

Sample Output:
```
Enter a number n: 32
The 32nd number in the Fibonacci Sequence is: 2178309
```
```
Enter a number n: 12
The 12th number in the Fibonacci Sequence is: 144
```

# Submission checklist
1. Created function prototype in ``fib.h``
1. Created function implementation in ``fib.cc``
1. Call function in the driver, ``main.cc``
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex08-tuffy
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `fib.cc` and `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc fib.cc -o main
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