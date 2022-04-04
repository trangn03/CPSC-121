# MadLibs

Goal: Learn about the basics of C++ by creating a MadLibs game:

* Create a C++ program from scratch
* Import standard headers
* Print output to the terminal
* Get input from the terminal
* Basic types, including integer, double, character
* String types

We assume a basic understanding of input, output, variables and types in any programming
language. This is meant to be a review of how these concepts work in C++.

## Overview and Specification

MadLibs is a template game in which a player will provide words which are substituted into
blanks in a story, generally resulting in a nonsensical and funny result.

You will use the following template:

```
Dear <name>,
I am <emotion> that I was not able to complete my homework on time. My pet <animal>
ate my textbook, and I was only able to retrieve <number> pages from its jaws. I
hope I can get at least a <character> grade because I've done <floating point number
between 0 and 100>% of the work.
Sincerely,
<name>
```

The user will be prompted for the name, emotion, animal, number, character, floating point
number, and second name, and the program will input those into the story and display the result.

Here is how the program would look when it is executed. Text in **bold** represents input
entered by the user.

<pre>
Welcome to MadLibs!
Name: <b>Paul</b>
Emotion: <b>ecstatic</b>
Animal: <b>kitten</b>
Number: <b>3</b>
Letter: <b>G</b>
Floating point number between 0 and 100: <b>3.1415</b>
Name: <b>Katie</b>
Dear Paul,
I am ecstatic that I was not able to complete my homework on time. My pet kitten
ate my textbook, and I was only able to retrieve 3 pages from its jaws. I hope I
can get at least a G grade because I've done 3.1415% of the work.
Sincerely,
Katie

</pre>

All the words must have the proper spacing / punctuation around them.

## Writing MadLibs

### Part 1: Setup

C++ programs share a common format. Every program must contain a function **main()**
which is the start of the program. **main()** will return 0 when the program completes
successfully. ([More about Main](https://en.cppreference.com/w/cpp/language/main_function))

In this project, we will create our **main()** function in main.cc. Open main.cc
in a text editor, and then add:

```cpp
int main() {
  // Your code here

  return 0;
}
```

*Note: In c++ you can write single line by beginning with two slashes ``//``, as shown above on
line 2. Lines which are commented out are ignored by the compiler.*

The contents of your program will always be called from within the **main()** function,
i.e. line 3 above.

We can compile and run this program right away, although it doesn't do anything yet.
You can try this by running these commands in the terminal:

1. First use the compiler clang++ to compile main.cc to create an executable file named
madlibs:
````
clang++ -std=c++17 main.cc -o main
````

2. Execute madlibs from the terminal:
```
./main
```

3. Nothing happens! That's expected, because we haven't done anything yet.

### Part 2: Writing output

Now let's print a message to the user. To do this we will need the C++ standard library
``iostream``. Add this line to the top of main.cc so that our program knows about input
and output functions:

```cpp
#include <iostream>
```

*C++ lets programmers ``#include`` other libraries to expand functionality. You can
``#include`` built-in libraries with <>, i.e. ``#include <library>``, or local header files
by name, i.e. ``#include "library.h"``.*

Now we can change **main()** to print something to the terminal. Add this line to
the **main()** function to print "Name:" using the standard library's ``cout``
functionality. ``std::cout`` uses the insertion operator ``<<`` to display text.

```cpp
std::cout << "Welcome to MadLibs!\n";
```

* *As a reminder, in C++ every statement must end with a semicolon.*
* *``\n`` is the newline character.*

Now save your file, then try building and running your program again (use the clang++
command and ./main above). It should print "Welcome to MadLibs" and then exit.

### Part 2: Variables and types

#### Built-in types

Some of the blanks in our MadLibs are built-in types. We will use an integer type to store the
 number of pages, a floating point to store the percent of work completed, and a character to
 store the grade. C++ has built-in types ``int`` (integer), ``double`` (floating point number)
  and ``char`` (character) which we can use. You can declare a variable with a particular a type
   in C++ by specifying the type name and then the variable name, for example:

```cpp
int num_puppies;
double cuteness_percentage;
char initial;
```

This creates variables ``num_puppies`` of type integer, ``cuteness_percentage`` of type double,
and ``initial`` of type character.

#### An aside on initialization
These are unintialized, meaning we don't yet know their value. We can assign value to them using
the ``=`` sign, for example,

```cpp
num_puppies = 3;
cuteness_percentage = 99.5;
initial = 'k';
```

You can also do this all in one line, for example:

```cpp
int num_puppies = 3;
```

And you can change the value later, for example,

```
// Lots of puppies now!
num_pupies = 20;
```

#### String type

We also will want to work with strings to create MadLibs, so lets add the C++ standard library
``string``. Add this to the top of main.cc (just below ``#include <iostream>``):

```cpp
#include <string>
```

Now we can also declare a string, for example:

```cpp
std::string name;
```

The type of variable ``name`` is a ``std::string``.

Now we can update our program to create variables for each of the MadLibs blanks. Add variables
for each of the blanks to main.cc within the **main()** function. You do not need to
initialize them because we will get those values from the user.

Try to do this on your own! But if you need help, here's an example answer.

<details>
<summary>Show possible answer</summary>
<p>
<i>Don't copy-paste this into main.cc! Typing it up will help you learn the material.</i>
</p>
<p>

```cpp
#include <iostream>
#include <string>

int main() {
  std::cout << "Welcome to MadLibs!\n";

  // Create variables.
  std::string name;
  std::string emotion;
  std::string animal;
  int number;
  char character;
  double percentage;
  std::string your_name;

  return 0;
}
```

</p>
</details>

### Part 3: User input
Now we are ready to get input from the user. We will use ``std::cin`` from the same C++ library ``iostream``. ``std::cin`` waits for the user to enter something in the terminal, and then stores that value into a provided variable. For example, here's a small snippet that would let you greet someone by name:

```cpp
std::string name;
std::cout << "What is your name? ";
std::cin >> name;
std::cout << "Hello, " << name;
```

What's going on here?
* Line 1 creates the variable of type ``std::string`` named ``name``.
* Line 2 prints a message to the user to prompt them to enter their name.
* Line 3 gets text entered by the user and stores it in the variable ``name``. Note the carets are
going in a different direction than with cout in line 2.
* Finally, line 4 prints "Hello, " followed by the name entered.

To a user, this would look like:

<pre>
What is your name? <b>Katie</b>
Hello, Katie
</pre>

You can use ``std::cin`` to get multiple types of input from the user, including integers, doubles,
strings, and more.

Based on this example, update main.cc to prompt the user for words and to store those in the
variables you created in part 2.

Try compiling and running your program with the ``clang++`` and ``./main`` commands from
earlier. If you are getting compiler errors, don't worry! That's normal. Check the direction
of your carets for ``std::cin`` and ``std::cout``, and that you have semicolons after every
statement.

<details>
<summary>Show possible answer</summary>
<p>
<i>Don't copy-paste this into main.cc! Typing it up will help you learn the material.</i>
</p>
<p>

```cpp
#include <iostream>
#include <string>

int main() {
  std::cout << "Welcome to MadLibs!\n";

  std::string name;
  std::string emotion;
  std::string animal;
  int number;
  char character;
  double percentage;

  // Get input from the user.
  std::cout << "Name: ";
  std::cin >> name;
  std::cout << "Emotion: ";
  std::cin >> emotion;
  std::cout << "Animal: ";
  std::cin >> animal;
  std::cout << "Number: ";
  std::cin >> number;
  std::cout << "Letter: ";
  std::cin >> character;
  std::cout << "Floating point number between 0 and 100: ";
  std::cin >> percentage;
  std::cout << "Name: ";
  std::cin >> your_name;

  return 0;
}

```

</p>
</details>

### Part 4: Creating the MadLibs story

Now that we have all the input from the user, we can generate the MadLibs story. Use the exact
format specified in the Specification, using the ``\n`` character to create newlines. Make sure
you user proper spacing around the user's words!

Now build and run your program. What's the funniest story you can come up with using this template?

<details>
<summary>Show possible answer</summary>
<p>
<i>Don't copy-paste this into main.cc! Typing it up will help you learn the material.</i>
</p>
<p>

```cpp
#include <iostream>
#include <string>

int main() {
  std::cout << "Welcome to MadLibs!\n";

  std::string name;
  std::string emotion;
  std::string animal;
  int number;
  char character;
  double percentage;
  std::string your_name;

  std::cout << "Name: ";
  std::cin >> name;
  std::cout << "Emotion: ";
  std::cin >> emotion;
  std::cout << "Animal: ";
  std::cin >> animal;
  std::cout << "Number: ";
  std::cin >> number;
  std::cout << "Letter: ";
  std::cin >> character;
  std::cout << "Floating point number between 0 and 100: ";
  std::cin >> percentage;
  std::cout << "Name: ";
  std::cin >> your_name;

  // Display the MadLib story.
  std::cout << "Dear " << name << ",\n"
            << "I am " << emotion
            << " that I was not able to complete my homework on time. My pet "
            << animal << " ate my textbook, and I was only able to retrieve "
            << number << " pages from its jaws. I hope I can get at least a "
            << character << " grade because I've done " << percentage
            << "% of the work.\nSincerely,\n"
            << your_name << "\n";

  return 0;
}

```
</p>
</details>

### Part 5: Testing

We've created a unittest for your program. The test is in test/unittest.cc, which you can take a
 look at if you are curious!

To run the test over your code, we will need to compile unittest.cc. We've included a shortcut
to compile and run the unittest: You can simply type `make test`. Feel free to peak into the
Makefile to see how this works.

The unittest will execute your program and see if it meets the standards set out in this
specification. It will print the results of the test run to the console. The test runs against
the compiled program you wrote, madlibs. If you make a change to main.cc make sure to
compile it again with clang++ before running `make test`, or you won't be testing the latest
version!

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex01-tuffy
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

We recommend pushing to github frequently to back up your work.
