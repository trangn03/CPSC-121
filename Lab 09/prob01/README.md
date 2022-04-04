# Shapes and Polymorphism

In this program you will be implementing classes using inheritance, and making use of polymorphism.

Put your classes into ``shapes.h`` and ``shapes.cc``.

## ``Shape`` class

Create a ``Shape`` class that has:

* a constructor which takes an integer width and height, which are stored in private member variables
* public getters for the width and height
* a pure virtual member function called ``GetArea`` which returns an integer. Recall that "pure virtual" means that the function should be set equal to 0 and should not have an implementation. That's because we don't know how to calculate the area of a shape without knowing what specific type of shape it is (triangle, rectangle, etc).
* a pure virtual member function called ``GetType`` which returns a std::string, the type of the shape.

## ``Rectangle`` class

Create ``Rectangle`` which inherits from ``Shape``. It should have:

* a constructor which takes an integer width and height and calls the superclass constructor.
* an implementation of ``GetArea``. For a rectangle the area is width * height. Use the public ``GetWidth`` and ``GetHeight`` on ``Shape`` rather than accessing ``Shape``'s member variables.
* an implementation of ``GetType`` which returns "rectangle".

## ``Triangle`` class

Create ``Triangle`` which inherits from ``Shape``. It should have:

* a constructor which takes an integer width and height and calls the superclass constructor.
* an implementation of ``GetArea``. For a triangle the area is 1/2 * width * height.
* an implementation of ``GetType`` which returns "triangle".

## ``Ellipse`` class

An ellipse, also known as an oval, is a rounded shape defined by a horizontal and a vertical diameter. Create ``Ellipse`` which inherits from ``Shape``. It should have:

* a constructor which takes an integer width and height and calls the superclass constructor.
* an implementation of ``GetArea``. For an ellipse the area is width / 2 * height / 2 * pi. Use 3.14159 for pi, and cast the result to integer without rounding.
* an implementation of ``GetType`` which returns "ellipse".

## Helper function, ``PrintShapeInfo``

In shapes.h define, and in shapes.cc implement a function called ``PrintShapeInfo`` (not associated with any class). This function should take a reference to a ``Shape`` and print its name and area, for example:

```
rectangle with area 25
ellipse with area 16
```

## ``main.cc``

We can compare the area of different types of shapes that have the same width and height.

Ask the user for an integer width and height in that order (you can use any prompt you like).

Use these values to create a ``Rectangle``, ``Triangle`` and ``Ellipse``.

Use ``PrintShapeInfo`` to print information about the ``Rectangle``, ``Triangle`` and ``Ellipse`` you created.

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc shapes.cc -o main
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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` `shapes.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc shapes.cc -o main
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
