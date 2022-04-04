# POGIL Group Grading

When grading labs it's easier for your instructors to give one grade to a whole group rather than grading each student individually. In this lab we will use objects and pointers to recreate group grading using a ``Student`` class and a ``PogilGroup`` class which has pointers to individual students.

As background, POGIL is a teaching methodology where students work in teams, and each team member is typically assigned a specific role. Roles help to engage all team members, and remind them of key responsibilities. Typical roles include Manager, Presenter, Recorder and Reflector.

## ``Student`` class

Declare ``Student`` in ``pogil.h`` and put implementation in ``pogil.cc`` as needed.

Create a constructor that takes a ``std::string`` the name of the student and an integer for the number of points the student already has.

Create a const getter for that name, ``GetName``, and a const getter for the points, ``GetPoints``, that returns the student's total number of points.

Create a member function, ``AddPoints``, that takes a ``int`` of points and adds it to the current number of points.

## ``PogilGroup`` class

Declare ``PogilGroup`` in ``pogil.h`` and put implementation in ``pogil.cc`` as needed.

Create a constructor that takes four pointers to ``Student`` objects, a manager, presenter, recorder and reflector (in that order).

Create ``const`` getters which return the ``Student*`` (``Student`` pointers) from the constructor, ``GetManager``, ``GetPresenter``, ``GetRecorder``, and ``GetReflector``.

Finally create a ``Grade`` function which takes a ``int`` the points the group gets and calls ``AddPoints`` on each of the four ``Student*`` in the group.

## ``PrintGroupInformation`` helper function

Declare ``PrintGroupInformation`` in ``pogil.h`` and put implementation in ``pogil.cc``.

``PrintGroupInformation`` is a function that is not associated with a class. It takes a ``PogilGroup*`` and does not return anything. This function should use ``cout`` to print information about a ``PogilGroup``, including the role, name, and the points for each role. For example, if a ``PogilGroup`` had pointers to students named "John", "Paul", George" and "Ringo" who all had a '10' points, we would expect ``PrintGroupInformation`` to say:

```
Manager John has 10 points
Presenter Paul has 10 points
Recorder George has 10 points
Reflector Ringo has 10 points
```

## Complete ``main.cc``

We've provided starter code in ``main.cc`` to get the four names for the Manager, Presenter, Recorder and Reflector, as well as a integer for the initial points.

Create ``Student`` objects for each of the names, then a ``PogilGroup`` with pointers to each of those ``Students``.

Use the ``Grade`` function on the ``PogilGroup`` you created to add the points the user entered to the students in the group, then call the ``PrintGroupInformation`` function with a pointer to the ``PogilGroup``.

Here's the expected result in the terminal:

```
Enter the Manager's name: Leonardo
Enter the Manager's current points: 4
Enter the Presenter's name: Raphael
Enter the Manager's current points: 7
Enter the Recorder's name: Michelangelo
Enter the Recorder's current points: 6
Enter the Reflector's name: Donatello
Enter the Reflector's current points: 8
How many points do you give this group? (between 0 and 10): 9

Manager Leonardo has 13 points
Presenter Raphael has 16 points
Recorder Michelangelo has 15 points
Reflector Donatello has 17 points
```

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc pogil.cc -o main
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

#Submission checklist
1. Declared classes and functions in ``pogil.h`` and implemented in ``pogil.cc``
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

#Code evaluation
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` `pogil.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc pogil.cc -o main
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

#Submission

We recommend pushing to Github frequently to back up your work.
