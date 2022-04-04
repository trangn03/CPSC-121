# Sentence Statistics

Create a command line tool that can tell a user how many times a particular character appears in text input. Your program will analyze the input, then prompt the user to enter characters to get stats. When the user types "quit" the program will exit.

```
Enter text input to analyze: The quick brown fox jumped over the lazy dog.
What character do you want stats on? a
The character a appears 1 times.
What character do you want stats on? e
The character e appears 4 times.
What character do you want stats on? z
The character z appears 1 times.
What character do you want stats on? quit
Goodbye!
```

## Analyzing the sentence

We've provided starter code in `main.cc` to get input from the user. Now you need to analyze it. You can use a ``std::map`` to store information about each character and the number of times it appears in the sentence.

A ``std::map`` maps keys of one type to values of another type. In this case, your keys could be ``std::string`` or ``char``, and your values could be integers. To declare a new map of ``char`` to ``int``, for example, you could do:

```
std::map<char, int> my_map;
```

Then you can access elements with square bracket notation, for example:

```
// Set the key 'c' to have the value 3:
my_map['c'] = 3;

// Get the value for key 'd', or default value 0
// if 'd' is not in the map:
int value = my_map['d'];
```

## Responding to the user

Once you have your map about character counts, you can enter a loop that will exit only when the user types "quit". Get characters from the user and tell them how many times each character appears in the sentence.

*You will probably need to ``cin`` into a ``std::string`` so you can check if it is "quit".*

## Running the program

Compile and run with:

```
clang++ -std=c++17 main.cc -o main
```

You can copy-paste really long input into this program, just make sure to remove newline characters. Once a newline character is reached the analysis will start.

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
