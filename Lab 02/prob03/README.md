# Pizza with toppings

This program will create a pizza string based on the user's chosen toppings. It will begin
by asking the user to provide the number of pepperoni, onions and jalapenos they want, then
print "Here's your pizza!" followed by the words "pepperoni", "onion" and "jalapeno" repeated the
number of times specified by the user.

Please see the samples below to guide the design of your program's output.
Note that **bold** values in the sample represents input by the user.

## Sample input/output:

Sample with toppings:

<pre>
How many pepperoni do you want? <b>3</b>
How many onions do you want? <b>2</b>
How many jalapenos do you want? <b>5</b>
Here's your pizza!
Pizza with: pepperoni pepperoni pepperoni onion onion jalapeno jalapeno jalapeno jalapeno jalapeno
</pre>

Sample with only some toppings:

<pre>
How many pepperoni do you want? <b>0</b>
How many onions do you want? <b>2</b>
How many jalapenos do you want? <b>2</b>
Here's your pizza!
Pizza with: onion onion jalapeno jalapeno
</pre>

Sample with no toppings:

<pre>
How many pepperoni do you want? <b>0</b>
How many onions do you want? <b>0</b>
How many jalapenos do you want? <b>0</b>
Looks like you weren't hungry. Maybe next time?
</pre>

We won't give an example with hundreds of toppings, but you should try it once you get your
program running!

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

## Compiling and executing:

You can compile your program with:

```
clang++ -std=c++17 main.cc -o main
```

and you can execute it with:

```
./main
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
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add main.cc
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
    Alternatively, you could add a comment to the `commit` command in order to skip the *nano* editor step described below.

    ```
    git commit -m "Finished prob01"
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.    
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
