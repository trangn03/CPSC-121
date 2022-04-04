# Header maker
Create a function called `DisplayHeader` that displays text surrounded by a rectangle composed of asterisks. The function receives a `std::string` text as input and does not return anything as an output, but displays the header. For example, given the text `Hello World`, the function should display this on screen:

```
****************
* Hello World! *
****************
```

Create another function called `WithinWidth` that helps make sure that the header does not exceed the width of the screen. The function accepts two parameters: a `std::string` text that is the text input used for displaying the header, and an `unsigned short int` which is the maximum width of the screen. Typically, this is 80 characters, but this parameter makes it more flexible for the user. The function returns a `bool` value indicating whether the text will fit on the screen or not.

*Note: Make sure you account for the added `*` and ` ` when the header is created. The function should return true if the length of the text together with the `*` and ` ` fit within the width.*

A very important member function you will need to use is the `std::string` object's `length` function. This will allow you to get the length of the string that you need for your function implementations. This is a good [reference](http://www.cplusplus.com/reference/string/string/length/) for the member function. Don't forget to include the `string` header.

Make sure that you write the `DisplayHeader` and `WithinWidth` function prototypes in `header.h` and their implementations in `header.cc`, and call them from inside of `main.cc`. You'll find that skeleton code has already been provided and you simply need to call the function and include the necessary header files.

# Submission checklist
1. Created function prototype and stored in `.h` file.
1. Created function implementation and stored in `.cc` file (see [reference](https://github.com/ILXL-guides/function-file-organization)).
1. Call function in the driver
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readbility (`make formatcheck`).

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

Use the `clang++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile codes saved in `header.cc` and `main.cc`, and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc header.cc -o main
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
