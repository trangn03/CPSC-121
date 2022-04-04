# Double Bubble
For this exercise you need to create a `Bubble` class and construct two instances of the `Bubble` object. You will then take the two `Bubble` objects and combine them to create a new, larger combined `Bubble` object. This will be done using functions that take in these `Bubble` objects as parameters.

The `Bubble` class contains one data member, `radius_`, and the corresponding accessor and mutator methods for `radius_`, ``GetRadius`` and ``SetRadius``. Create a member function called `CalculateVolume` that computes for the [volume of a bubble (sphere)](https://en.wikipedia.org/wiki/Sphere#Enclosed_volume). Use the value 3.1415 for `PI`.

Your `main` function has some skeleton code that asks the user for the radius of two bubbles. You will use this to create the two `Bubble` objects. You will create a `CombineBubble` function that receives two parameters (two `Bubble` objects) and returns a `Bubble` object. Combining bubbles simply means creating a new `Bubble` object whose radius is the sum of the two `Bubble` objects' radii. Take note that the `CombineBubble` function is not part  of the `Bubble` class.

Place the `Bubble` class and the `CombineBubble`'s function prototype in `bubble.h`. Place `CombineBubble`'s implementation in `bubble.cc`. The `main` function already contains some code, but you need to complete the requirements that is described inside the file.

Please see the sample output below to guide the design of your program.

## Sample Output
<pre>
Please enter the radius of the first bubble: <b>4.5</b>
Please enter the radius of the second bubble: <b>2.3</b>
The bubbles have now combined and created a bubble with the volume of: 1317.05
</pre>

# Submission checklist
1. Created function prototype and stored in `.h` file.
1. Created function implementation and stored in `.cc` file (see [reference](https://github.com/ILXL-guides/function-file-organization)).
1. Call function in the driver
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `bubble.cc` and `main.cc`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc bubble.cc -o main
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
