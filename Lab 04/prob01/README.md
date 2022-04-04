# Generate color swatches from hex codes

In this lab you will generate .bmp images which will allow users to preview hexidecimal colors. Users can enter a hex code into the terminal, and you will generate an image file that is completely that color. The image size does not matter, but we will test that the whole image is the correct color.

Example:

```
Enter a hex code: 34b7eb
Color swatch saved to 34b7eb.bmp
```

You can assume that the user enters the hex code in the proper format: six characters without any proceeding "#". You do not have to handle invalid inputs.

## Details

### 1. Convert input string to three integers

The first two characters of a color hex code converted to decimal represent red, the second two characters represent green, and the third two represent blue. You need to convert these three substrings into three numbers.

First, to get the substring of a string, use the string ``substr`` function ([reference](http://www.cplusplus.com/reference/string/string/substr/)) which takes two arguments: the starting index in the string and the length of the substring. For example:

```cpp
std::string cat = "Mr. Radish";
std::string first_name = cat.substr(4, 6);  // first_name == "Radish"
```

Second, we've provided a function ``HexToInteger`` in ``main.cc``. which you can use to convert two-character hexidecimal strings into their integer value.

*``HexToInteger`` will fail if you pass a hex string which is longer than two characters, so you can make use of the substring function to process two characters at a time.*

### 2. Create graphics::Color object

Instead of specifying red, green and blue separately, it can often be easier to work with these channels grouped into a single object. The ``graphics::Color`` class is defined in ``image.h``. ``graphics::Color`` object can be created as follows:

```cpp
graphics::Color color(255, 0, 0);
```

For example,

```cpp
graphics::Color green(20, 255, 100);
graphics::Color orange(255, 127, 0);
```

You can get the red, green and blue channels as follows, although you probably won't need this for this lab exercise:
```cpp
int red = color.Red();
int green = color.Green();
int blue = color.Blue();
```

Now create a graphics::Color object from the integers you created in part 1.

### 3. Draw and save the image

Create the ``graphics::Image`` using the constructor which takes an integer width and height:

```cpp
graphics::Image image(width, height);
```

Then fill the whole thing with the color. You could use pixel level manipulation to set the color of each pixel in the image, but it's easier to just draw a rectangle.

Here is the ``graphics::Image`` function prototype to draw a rectangle:

```cpp
/**
 * Draws a rectangle with upper left corner at (x, y) and size
 * |width| by |height|, colored by |color|.
 * Returns false if params are out of bounds.
 */
bool DrawRectangle(int x, int y, int width, int height, graphics::Color color);
```

You can specify the top left corner of the rectangle with x and y, and then the width and height.

For example, to draw an orange rectangle over the right of the screen:

![orange rect](tools/orange_rect.bmp)

```cpp
const int size = 100;
image.DrawRectangle(size / 2, 0, size / 2 - 1, size, orange);
```

Note that you cannot draw rectangles outside the image bounds, or a error message is printed.

Using the ``DrawRectangle`` function, use the ``graphics::Color`` you created in part 2 to completely fill an image with a solid color.

### 4. Save the image

Then save the image to a file that is named based on the input they intered, for example, if the user entered "ffcc00" then the file should be "ffcc00.bmp".

You can save to a bitmap file using ``SaveImageBmp``. For example, the snippet below saves the current image to a file named "my_image.bmp".

```cpp
image.SaveImageBmp("my_image.bmp");
```

## Run the program to generate color swatches

To manually test your code you can compile and run this program with:

```
clang++ -std=c++17 main.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
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
clang++ -std=c++17 main.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
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
