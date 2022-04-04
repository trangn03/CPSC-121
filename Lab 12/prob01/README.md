# Cat adoption

In this lab you will create a ``Cat`` class and a ``Human`` class. The ``Human`` objects can adopt or transfer ``Cat`` objects between each other using ``std::unique_ptr`` to handle ownership.

## ``Cat`` class

Create a ``Cat`` class in ``cat.h`` and implement it in ``cat.cc``. This class needs:

* A member variable tracking the ``Cat``'s name,

* A destructor which prints out the cat's name plus " stalks away". For example, if the ``Cat`` was named ``Radish``, it would print out "Radish stalks away" in the destructor.

* A setter, ``SetName``, and a const getter, ``GetName``, for the ``std::string`` representing the ``Cat``'s name.

## ``CreateKitty`` helper function

Declare a ``CreateKitty`` function in ``cat.h`` and implement it in ``cat.cc``.

This function should create a ``std::unique_ptr<Cat>`` which points to a dynamically allocated ``Cat`` object. The ``CreateKitty`` function should take a ``std::string``, the name of the ``Cat``, and set that on the dynamically allocated ``Cat`` before returning.

Make use of ``std::move`` to change ownership of the ``std::unique_ptr<Cat>`` when returning.

Don't forget to ``include <memory>`` to use ``std::unique_ptr``.

*Note: It's common to create a method which generates ``std::unique_ptr``. This is usually called a "Factory", for example a "CatFactory" ([Google style guide](https://google.github.io/styleguide/cppguide.html#Ownership_and_Smart_Pointers)).*

## ``Human`` class

Create a ``Human`` class in ``human.h`` and implement it in ``human.cc``. This class needs:

* Member variables for a ``std::string`` name and a ``std::unique_ptr<Cat>`` a cat (may be nullptr).

* A destructor which prints out the human's name plus " walks away". For example, if the ``Human`` was named ``T'Challa``, it would print out "T'Challa walks away" in the destructor.

* A setter, ``SetName``, and a const getter, ``GetName``, for the ``std::string`` name.

* A void function, ``Adopt``, which takes a ``std::unique_ptr<Cat>`` and moves ownership to the ``Human``.

* A void function, ``TransferTo``, which takes a pointer to another ``Human`` object. This should call ``Adopt`` on that human in the parameter to transfer ownership of the ``std::unique_ptr<Cat>`` member variable to the other human.

* A void and constant function, ``Print``, which takes no arguments. This should print out a different message depending on whether the ``Human`` has a ``Cat``. Examples:
  * If a ``Human`` named "Monica" has a ``Cat`` named "Zuri", this should print "Monica is a human with a cat named Zuri".
  * If the ``Human`` has no cat, it should print "Monica is a human with no cat".

Don't forget to ``include <memory>`` to use ``std::unique_ptr``. Use ``std::move`` when transferring ownership of unique pointers.

## Complete ``main.cc``

The main program will create two Human objects and a unique_ptr to a Cat object. It will:
1. Ask the user for three names (done in starter code)
2. Print information about the two Human objects
3. Use the ``CreateKitty`` function to create a Cat
4. Have the first Human adopt the Cat and print the Human objects again
5. Have the first Human transfer their Cat to the second Human and print the Human objects once more

```
What is the first human's name? Katie
What is the second human's name? Lyra
What is the cat's name? Vega

Katie is a human with no cat
Lyra is a human with no cat
First human is adopting...
Katie is a human with a cat named Vega
Lyra is a human with no cat
First human is transferring to second human...
Katie is a human with no cat
Lyra is a human with a cat named Vega
Lyra walks away.
Vega stalks away.
Katie walks away.
```

``main.cc`` has some starter code to get names from the user. You need to fill in the "TODO" sections. Don't forget to ``#include`` any necessary headers.

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc human.cc cat.cc -o main
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cc` `cat.cc` `human.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc cat.cc human.cc -o main
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
