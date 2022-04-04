# Person Pointers

In this lab you will create a ``Person`` class where each ``Person`` contains a pointer to another ``Person`` representing their child.

## ``Person`` class

Create a ``Person`` class with a constructor that takes a ``std::string`` the name of the person, and a ``const`` getter ``GetName``.

``Person`` should also have a setter and a ``const`` getter for a ``Person*``, ``SetChild`` and ``GetChild``. Store the child in a member variable which is initialized to ``nullptr``.

Finally, ``Person`` should have a ``const`` method called ``Print`` that is type void and takes no arguments. ``Print`` should ``cout`` the person's own name. Then if the person has a child it should ``cout`` ", parent of " followed by calling ``Print`` on that child. If it has no child, it should follow the person's own name by a newline.

For example, for a ``Person`` named "Elmo" you would simply see "Elmo" followed by a newline. Or, for a ``Person`` named "Kris Jenner" with a child named "Kourtney Kardashian" which has a ``nullptr`` child, you would see the result, "Kris Jenner, parent of Kourtney Kardashian" (followed by a newline).

## ``main.cc``

Prompt the user for a great-grandparent name, a grandparent name, a parent name, and a kid name.

Construct a great-grandparent ``Person`` object, a grandparent ``Person``, a parent ``Person``, and a kid ``Person`` from those names.

Set the family relationships by calling ``SetChild`` on each parent with a pointer to its child.

Finally, print the family tree by calling ``Print`` on the great-grandparent object.

For example:

```
What is the great-grandparent's name? Elizabeth
What is the grandparent's name? Charles
What is the parent's name? William
What is the kid's name? Charlotte
The family tree is:
Elizabeth, parent of Charles, parent of William, parent of Charlotte
```

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc parent.cc -o main
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Completed ``parent.h`` and ``parent.cc``.
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` `parent.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc parent.cc -o main
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
