# Colorful bubbles

Create a ``Bubble`` class that has accessors and mutators for an x and y coordinate, color and size, and a ToString function that prints information about the Bubble object to the terminal.

Complete ``main.cc`` to build and draw ``Bubble`` objects based on user input.

## Create the ``Bubble`` class

Fill in ``bubble.h`` and ``bubble.cc`` to create a ``Bubble`` class.

Your bubble will need to store private member variables to represent integer x and y coordinates, integer size (the radius), and a graphics::Color color.

``Bubble`` needs to have public methods that access and mutate the x, y, color and size (8 methods total: a getter and a setter for each).

Finally, ``Bubble`` needs a method that returns a ``std::string`` representing the bubble. This method should output text with the format,

```
Bubble at (x, y) with size s
```

For example, for a bubble with size 30 at (42, 37), your function would return:

```
Bubble at (42, 37) with size 30
```

You can use the ``std::to_string`` function to convert integers to strings, for example, ``std::to_string(2)`` gives ``"2"``.

``bubble.h`` will need to ``#include <string>`` in order to define a function prototype using a ``std::string``.

You may name these functions however you want. Reference [Functions review](https://github.com/ILXL-guides/function-file-organization) if you are wondering what to put in ``bubble.h`` and ``bubble.cc``.

## Complete ``main.cc``

``main.cc`` already does most of the work to ask the user about bubble creation and to create and save an image as ``bubbles.bmp``. You only need to fill in two parts:

First, in the first ``for`` loop, you will need to create a ``Bubble`` object from your ``Bubble`` class. Ensure you set the x, y and size based on what the user entered.

For the color, use the ``colors`` map to translate between what the user typed in and ``graphics::Color`` objects.

When you have created the ``Bubble`` object, add it to the ``bubbles`` vector.

Second, in the final ``for`` loop, you will need to get the ``Bubble`` object at the current index. Print it to the console using the ``std::string`` method you defined, and also draw it to the ``graphics::Image`` object ``image``. You can use the ``DrawCircle`` method:

```cpp
/**
 * Draws a circle centered at (x, y) with radius |radius|, and color
 * |color|. Returns false if params are out of bounds.
 */
bool DrawCircle(int x, int y, int radius, const Color& color);
```

For example,
```cpp
image.DrawCircle(10, 20, 30, graphics::Color(42, 42, 42));
```

## Run your program and create some bubble bitmaps!

To manually test your code you can compile and run this program with:

```
clang++ -std=c++17 main.cc bubble.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

*Note: you need a few additional flags on Mac which are not shown here.*

However, that's a lot to type, so we've included a shortcut to compile and create ``main``:

```
make build
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
