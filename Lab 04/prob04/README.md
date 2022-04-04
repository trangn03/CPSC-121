# Chirper: A lonely social network

Create a social network, Chirper, that lets the user add new Chirps and like existing Chirps. It's lonely because only one person can add and like messages -- so there's really not much "social" about it. At least you can practice using objects in C++!

Here's an example of how this program will run (from ``./main``):

```
You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? chirp
What's your message? This is my first chirp!
Chirper has 1 chirps:
1. This is my first chirp! (0 likes)

You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? like
Which index do you want to like? 1
Chirper has 1 chirps:
1. This is my first chirp! (1 likes)

You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? chirp
What's your message? Second chirp is the best chirp.
Chirper has 2 chirps:
1. This is my first chirp! (1 likes)
2. Second chirp is the best chirp (0 likes)

You can "chirp" a new message to Chirper, or "like" an existing chirp, or "exit". What do you want to do? exit
Goodbye!
```

## Create the ``Chirp`` class

The ``Chirp`` class should have four member functions:
``SetMessage`` which takes a ``std::string``, ``GetMessage`` which returns a ``std::string``, ``GetLikes`` which returns an integer, and ``AddLike`` which increments the number of likes.

``Chirp`` objects need two member variables: one to track the message and one to track the number of likes.

Put the ``Chirp`` function prototypes in ``chirp.h`` and the ``Chirp`` function definitions in ``chirp.cc``. Reference [functions review](https://github.com/ILXL-guides/function-file-organization).

## Create ``main.cc``

``main.cc`` will implement the not-so-social network, Chirper. We've provided some input and output code, but haven't yet created any ``Chirp`` objects. You need to:

1. Create a ``std::vector`` into which you can store ``Chirp`` objects.

2. Create new ``Chirp`` objects when the user wants to add a new message.

3. Add likes to ``Chirp``s based on user input.

4. Complete the functionality to print the full list of chirps to the console. You should print the total number of chirps, and then you should have one line for each chirp, starting with the (1-based) index of the chirp, the message, and then the number of likes, for example:

```
Chirper has 2 chirps:
1. This is my first chirp! (1 likes)
2. 2021 can't come soon enough (3 likes)
```

*Notes: we aren't checking for grammar (1 chirps vs 1 chirp). You can assume that the user will not enter invalid input.*

Ensure you include ``chirp.h`` in ``main.cc`` so the compiler can find the function prototypes.

## Try your program

Compile with:

```
clang++ -std=c++17 main.cc chirp.cc -o main
```

Try running ``./main`` to chirp to all your friends (well, just you, actually).

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
clang++ -std=c++17 main.cc chirp.cc -o main
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
