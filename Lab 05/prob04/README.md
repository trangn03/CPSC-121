# Stars

This lab exercise will practice creating objects with constructors and destructors and demonstrate when constructors and destructors are called.

## `Star` class

Create a class, ``Star``. This class should have a constructor which takes a std::string, the name of the star, and a double, the solar radius of the star.

In the constructor, the ``Star`` class should print to the terminal that the star was born. For example, if you create a ``Star`` as follows:

```cpp
Star my_star("Saiph", 22.2);
```

Then the constructor should print:

```
The star Saiph was born.
```

In the destructor, the ``Star`` class should print to the terminal that the star was destroyed, along with the number of times the volume of the sun that that star was, formatted to two decimal places. For example, when ``my_star`` above has its destructor called, we would see something like:

```
The star Saiph has gone supernova. It was 492.84 times the volume of our sun.
```

The ``Star`` class will need member variables to store the information passed in the constructor.

Additionally, the ``Star`` class needs a getter, ``GetName()``, to return the name string.

### Calculating volume

A [solar radius](https://en.wikipedia.org/wiki/Solar_radius) is the number of times bigger a star's radius is than our sun's radius. You can use it to determine the relative volume between a star and our sun:

The equation for volume of a sphere is ``4 / 3 * pi * r ^ 2``.

Since ``4 / 3 * pi`` is constant, and the solar radius ``r`` of the sun is by definition 1, you need only calculate the solar radius of your star squared.

So if the solar radius of the star is 2, you would return 2 * 2 which is 4.

## Main program

Your main program should ask the user for how many stars they want to create, and then for each of those stars it should ask for the star name and solar radius to create a ``Star`` object. After creation, your ``main`` program should print "Created star <name>" for the user's given star name.

For example:

```
How many stars? 2
Enter star 0's name: Mintaka
What is the solar radius? 16.5     
The star Mintaka was born  
Created star Mintaka
The star Mintaka has gone supernova. It was 272.25 times the volume of our sun.      
Enter star 1's name: Alnilam
What is the solar radius? 32.4     
The star Alnilam was born
Created star Alnilam
The star Alnilam has gone supernova. It was 1049.76 times the volume of our sun.
```

*Note: Because your ``Star`` objects are created within a loop, their deconstructors are automatically called at the end of each pass through the loop!*

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc star.cc -o main
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
clang++ -std=c++17 main.cc star.cc -o main
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
