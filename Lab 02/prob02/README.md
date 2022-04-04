# Yes or No input function

## Goal:

Using conditional statements and while loops, implement a function that gets a "yes" or "no" input from the user.

Use this function in ``main.cc`` to ask a user if they like chocolate chip cookies.

## Background:

This lab will require you to implement a function prototype and definition in different files. If this is new to you you can read about [function prototypes and definitions](https://github.com/ILXL-guides/function-file-organization). Note that our files will be '.cc' and '.h' instead of '.cpp' and '.hpp'.
## Details:

Write a ``GetYesOrNoInput`` function in ``input.cc`` and use it in ``main.cc`` where you ask the user for input. The function takes no arguments and returns a boolean of whether the user answered ``yes`` (true) or ``no`` (false).

Do not assume that the user will type their input correctly. ``GetYesOrNoInput`` needs to keep trying to get input from the user until either the input is exactly ``yes`` or the input is exactly ``no``. If the user types the input incorrectly, your function should print, ``Sorry, I didn't understand. Try again: `` and then wait for the user to enter another response.

You will need to define ``GetYesOrNoInput`` in ``input.h`` and include ``input.h`` from ``main.cc`` so the compiler knows about the function's definition.

To compile and run your program, you'll need to ensure that the function implementation in ``input.cc`` can be found, so pass is as another argument to clang++:

```
clang++ -std=c++17 main.cc input.cc -o main
./main
```

Here's an example of running ``main`` after your function is implemented:

```
Do you like chocolate chip cookies? Enter "yes" or "no": potato
Sorry, I didn't understand. Try again: 3
Sorry, I didn't understand. Try again: YES
Sorry, I didn't understand. Try again: yes
Yummy yummy chocolate chip cookies!
```

## Tips

You may use the ``<string>`` standard library in c++. Make sure to

``include <string>``

at the beginning of main.cc.

You can concatenate strings using the "+" symbol. You can get the length of a string using the
``string.size()``. For example:

```
// Create a new string.
std::string my_cat = "Vega";

// Concatenate.
my_cat += " is the cutest";

// Get the length of the string.
int length = my_cat.size();
```

# Submission checklist
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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc input.cc -o main
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
