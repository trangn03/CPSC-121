# Linear Search Vector

Create a recursive `LinearSearch` function that receives an integer vector (`std::vector<int>`) and a number to find in the vector, as well as an start_index into the vector at where to start searching. The function should return the index of the number in the vector if it exists at that start_index or later, and returns -1 if it isn't in the vector.

Place the `LinearSearch`'s function prototype in `linear_search.h` and its implementation in `linear_search.cc`. The `main` function already contains some code, but you need to complete the requirements that is described inside the file.

# Sample output:
<pre>
vector: 3 16 22 8 11 0 55 34 27 31
Please enter a number you want to search for: <b>8</b>
The index of 8 in the vector is: 3
</pre>

## Sample output #2:
<pre>
vector: 3 16 22 8 11 0 55 34 27 31
Please enter a number you want to search for: <b>15</b>
15 is not in the vector
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and `linear_search.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc linear_search.cc -o main
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
