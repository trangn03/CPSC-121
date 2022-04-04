vector# Print Vector Reverse
Create a program that displays the contents of an vector in reverse.

### PrintVectorReverse
Create a function called `PrintVectorReverse` that prints out the contents of an integer vector in reverse.

`PrintVectorReverse` will have one parameter: an `std::vector<int>*` pointer that refers to a vector.

Your function has two main scenarios it could encounter.

When you have an vector with a size that is greater than 0, then it should behave normally and output the vector's contents in reverse.

But, if your function encounters an vector with size of 0 then it should output `There are no contents in this vector!` and go to the next line.

Refer to the sample output to see instances of both. Note that the elements of the vector are all printed on one line.

Complete the code in `main.cc`, provide the headers in `print_vector_reverse.h` and the implementation in `print_vector_reverse.cc`.

# Sample Output
<pre>
Enter an integer for the size of the vector: <b>10</b>
Inputs for the vector:
Enter the integer for index 0: <b>4</b>
Enter the integer for index 1: <b>3</b>
Enter the integer for index 2: <b>2</b>
Enter the integer for index 3: <b>1</b>
Enter the integer for index 4: <b>89</b>
Enter the integer for index 5: <b>15</b>
Enter the integer for index 6: <b>100</b>
Enter the integer for index 7: <b>24</b>
Enter the integer for index 8: <b>254</b>
Enter the integer for index 9: <b>2</b>
The contents of the vector in reverse are:
2 254 24 100 15 89 1 2 3 4
</pre>

<pre>
Enter an integer for the size of the vector: <b>0</b>
Inputs for the vector:
There are no contents in this array!
</pre>

Submission checklist
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and `print_vector_reverse` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc print_vector_reverse.cc -o main
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
