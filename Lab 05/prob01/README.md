# Accessible buttons

When designing user interfaces it is important to have enough contrast between text and background. Too frequently we can find important content, like buttons, are hard to read because the designer or developer did not make the text stand out enough against the background. Difficulties can be exacerbated for all users by non-ideal external situations like looking at the display on a sunny day or with the brightness turned way down. In addition, for some users with visual impairments it can be extremely difficult to read low contrast text.

For this reason, the Web Content Accessibility Guidelines require that all buttons have a contrast ratio of at least 4.5:1 ([WCAG 2.0 definition](https://www.w3.org/TR/WCAG20/#contrast-ratiodef)). What does that mean?

Contrast ratio is defined as:

**(L1 + 0.05) / (L2 + 0.05)**, where

* L1 is the [relative luminance](https://en.wikipedia.org/wiki/Relative_luminance) of the lighter of the colors, and
* L2 is the relative luminance of the darker of the colors.

For a color with (red, green, blue) channels scaled to 0 to 1, relative luminance is defined as:

**.2126 * red + .7152 * green + .0722 * blue**

For example, black has a relative luminance of 0, white has a relative luminance of 100%, and red has a relative luminance of 21.26%. ([online calculator](https://planetcalc.com/7779/)).

*Note: Our eyes are least sensitive to blue, so the blue component of a color counts the least towards its relative luminance!*

Here are some examples:

<div style="padding: 6px; background-color: black; color: white">#ffffff on #000000: Contrast ratio 21 to 1</div><br/>
<div style="padding: 6px; background-color: #DDDDDD; color: #000080">#000080 on #dddddd: 11.787 to 1</div><br/>
<div style="padding: 6px; background-color: #7B0000; color: #FF9900">#7b0000 on #ff9900: 5.324 to 1</div><br/>
<div style="padding: 6px; background-color: #ff0000; color: #ffffff">#ffffff on #ff0000: 3.998 to 1 (not accessible)</div><br/>
<div style="padding: 6px; background-color: #FF9999; color: #FF0000">#ff0000 on #ff9999: Contrast ratio 1.955 to 1 (not accessible)</div><br/>

In this lab, you will create a class ``Button`` which has a text color, a background color, and can calculate its contrast ratio and whether it is accessible.

## ``Button`` class

Create a ``Button`` class that has public methods as follows:

1. A constructor which takes two ``graphics::Color`` objects, the foreground and background colors,
2. ``GetTextColor`` which takes no parameters and returns the text color,
3. ``GetBackgroundColor`` which takes no parameters and returns the background color,
4. ``GetContrastRatio`` which takes no parameters and returns a ``double`` based on the formulas above, and
5. ``IsAccessible`` which takes no parameters and returns a bool, ``true`` if the contrast ratio is at least 4.5, and false otherwise.

The ``GetContrastRatio`` will need to use a provided function, ``GetScaledChannel``, to scale each color channel (map an integer between 0 and 255 to a linear scale between 0 and 1), before performing the relative luminance formula, .2126 * red + .7152 * green + .0722 * blue. You can find ``GetScaledChannel`` already defined in ``button.cc``.

Use the relative luminance formula on the foreground and background colors to calculate the contrast ratio, and make sure the brighter (higher relative luminance) color is in the numerator in (L1 + 0.05) / (L2 + 0.05).

### Tips:

* You will need to ``#include "cpputils/graphics/image.h"`` to use a ``graphics::Color`` object.

* It might be helpful to create a helper function to calculate a ``double`` relative luminance for a ``graphics::Color``.

* Don't forget that L1 must be greater than L2 when calculating the contrast ratio.

## Method to find button with highest contrast

Within ``button.h`` you should also define the prototype for a function to find the ``Button`` with the biggest contrast ratio in a ``std::vector``. The prototype looks like this:

```cpp
int ButtonWithMostContrast(const std::vector<Button>& buttons);
```

This function is not a method of the ``Button`` class although it is defined in ``button.h``.

Implement the ``ButtonWithMostContrast`` function in ``button.cc``. It should return the index of the button with the biggest contrast ratio within the vector. Assume the vector always has at least one ``Button``.

## Run the program

We've provided a ``main.cc`` which will create a ``std::vector<Button>`` based on user inputted hex codes, and then use your function ``ButtonWithMostContrast`` to find the button with the highest contrast ratio. It will then display all the colors the user entered.

You do not need to edit ``main.cc`` but you can take a look at the ``int main()`` function to see how this works!

To manually test your code you can compile and run with a shortcut to create ``main``:

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
clang++ -std=c++17 main.cc button.cc cpputils/graphics/image.h -o main -lm -lX11 -lpthread
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
