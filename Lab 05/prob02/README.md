# Friendly Robot Class

You will create a ``Robot`` class which will be able to draw a little robot icon at a particular place on the screen. Your robot will alternate drawing from two possible icons to create a small animation. We've provided ``main.cc`` that uses your ``Robot`` class to draw an animated robot that follows your cursor around.

![robot icon](robot4.bmp)

## Details

``Robot`` needs a constructor, getters and setters for pixel location, and a drawing function.

### Constructor

Your ``Robot`` Class constructor should take two string parameters, the filename for the image icon to show first, and the filename for the image icon to show second. Your constructor should save these filenames in member variables but should not construct the images yet.

*Why not load the images in the constructor? It's not good practice to do [work in constructors](https://google.github.io/styleguide/cppguide.html#Doing_Work_in_Constructors) because if there is an error it leaves the program in a bad state.*

### Location

The ``Robot`` class tracks its (x, y) pixel location with two private integer member variables. It must provide public getters for x and y, ``GetX()`` and ``GetY()`` which both return ``int``s. To set the (x, y) location ``Robot`` should provide a public function ``SetPosition`` which takes two arguments, the ``int`` x position and ``int`` y position.

### Drawing the icon

``Robot`` must implement a function, ``Draw``, that takes a reference to a ``graphics::Image``, and draws the robot icon on that image.

The ``Draw`` function will be called repeatedly by ``main.cc``. Each time ``Draw`` is called ``Robot`` should draw an icon centered at (x, y). ``Robot`` must alternate which icon is drawn from the the two filenames in the constructor: The first time ``Draw`` is called it shows the first icon, and the second time the second icon, etc.

To implement, first the ``Draw`` function should load the image assets passed in the filenames. Use this method from ``graphics::Image``:

```cpp
/*
 * Loads an image from a file. Returns false if the image could
 * not be loaded. Note: this clears any current state, including
 * pixel values, width and height.
 */
bool Load(const std::string& filename);
```

For example,

```cpp
graphics::Image my_image;
my_image.Load("filename.bmp");
```

Second, to draw the icon onto the big image, the ``Draw`` function should copy the pixels from the active icon into the ``graphics::Image`` reference that was passed as a parameter. The icon should be centered at the (x, y) position stored in ``Robot``'s private member variables.

#### Hints

*You could store the ``graphics::Image`` images for these icons as member variables, which would be more efficient than loading them every time.*

*The modulus operator could be helpful when deciding which icon to draw.*

*It might reduce complexity to create a helper method in the ``Robot`` class that takes two ``graphics::Image&`` to draw icon 1 or icon 2 on the larger image, but this is optional!*

*When the ``Robot`` is too close to the edge of the image you'll need to check that you don't draw pixels out of bounds.*

## Run your program and play with the friendly robot!

We've provided some robot icons, but feel free to add your own. You can use ``robot1.bmp``, ``robot2.bmp``, ``robot3.bmp``, and ``robot4.bmp``.

![robot icon](robot1.bmp) ![robot icon](robot2.bmp) ![robot icon](robot3.bmp) ![robot icon](robot4.bmp)

To manually test your code you can compile and run this program with:

```
clang++ -std=c++17 main.cc robot.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
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
clang++ -std=c++17 main.cc robot.cc -o main -lm -lX11 -lpthread
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
