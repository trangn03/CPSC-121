# Eating Cupcakes

In this lab you will create a simple ``Cupcake`` class and a ``Stomach`` class that has several ways to consume ``Cupcake`` from pointers. This lab makes use of dynamic memory allocation and compares raw pointers with unique pointers.

## ``Cupcake`` class

Create a ``Cupcake`` class in ``cupcake.h`` and ``cupcake.cc``. It should have a member variable for a ``std::string`` the flavor of the cupcake, a setter, ``SetFlavor``, and a const getter, ``GetFlavor``.

## ``Stomach`` class

Create a ``Stomach`` class in ``stomach.h`` and ``stomach.cc``.  It should have a member variable to track the number of cupcakes eaten, initialized to 0, and a const getter, ``GetCupcakeCount``, which returns that number.

The goal of the ``Stomach`` class is to be able to consume cupcakes and deallocate them from memory during consumption. In real life, eating real cupcakes means those cupcakes are actually gone. We will simulate this by having the ``Stomach`` deallocate memory when consuming cupakes.

### ``EatAndDeallocate``, raw pointer version

Create an ``EatAndDeallocate`` method in ``Stomach`` that takes a pointer to a pointer to a cupcake (that's not a typo!) and consumes and deallocates the ``Cupcake``.

*Why a pointer to a pointer to a ``Cupcake``? Because we want to change the pointer to the cupcake to be ``nullptr`` after running ``EatAndDeallocate`` to ensure that no one else tries to access that ``Cupcake`` after deallocation. If we passed in just a pointer to a Cupcake, setting that pointer to ``nullptr`` wouldn't change the original pointer from where the ``EatAndDeallocate`` function was called, because pointers are passed by copy like other types.*

This method should check if the pointer points to a ``nullptr``, and if so, print out a message about there being "no cupcake" and return.

But if the pointer points to a valid pointer to a ``Cupcake``, the ``EatAndDeallocate`` method should:
1. "eat" the cupcake by incrementing the cupcake count member variable and printing out the flavor of the cupcake being eaten, and
2. deallocate the memory for the cupcake using delete, and
3. set the Cupcake's pointer to nullptr.

For example, if we were to call ``EatAndDeallocate(ptr)`` where ``*ptr == nullptr``, then we would see "There is no cupcake" printed in the console. But if ``*ptr`` pointed to a ``Cupcake`` with flavor "chocolate", we would see "Eating a chocolate cupcake" printed in the console.

### ``EatAndDeallocate``, unique pointer version

Create a second ``EatAndDeallocate`` method in ``Stomach`` that takes ``std::unique_ptr`` to a ``Cupcake``. This should have the same output as the previous version but will be much simpler, illustrating the value of unique pointers when doing memory management.

This method should check if the pointer points to a ``nullptr``, and if so, print out a message about there being "no cupcake" and return.

But if the pointer points to a valid pointer to a ``Cupcake``, the ``EatAndDeallocate`` method should "eat" the cupcake by incrementing the cupcake count member variable and printing out the flavor of the cupcake.

For example, if we were to call ``EatAndDeallocate(uptr)`` where ``uptr == nullptr``, then we would see "There is no cupcake" printed in the console. But if ``uptr`` pointed to a ``Cupcake`` with flavor "chocolate", we would see "Eating a chocolate cupcake" printed in the console.

*Note that you don't need to do any manual deallocation as the ``std::unique_ptr`` will deallocate the ``Cupcake`` when it goes out of scope at the end of the function.*

## main

Implement the ``main`` function in ``main.cc``. Your function should ask the user to input two std::string flavors of cupcake.

```
What is the first flavor? raspberry
What is the second flavor? funfetti
Stomach cupcake count: 0
Eating a raspberry cupcake          
Stomach cupcake count: 1
Eating a funfetti cupcake           
Stomach cupcake count: 2
```

1. Dynamically allocate a ``Cupcake`` object and SetFlavor to one of the std::string flavors.
2. Create a ``std::unique_ptr`` to another ``Cupcake`` object and ``SetFlavor`` to the other std::string from the user.
3. Create a ``Stomach`` object, and print out the number of cupcakes eaten with "count: " proceeding it.
4. Have the ``Stomach`` ``EatAndDeallocate`` the address of the pointer to the ``Cupcake`` object, then print the number of cupcakes eaten in the same way.
5. Have the ``Stomach`` ``EatAndDeallocate`` the unique pointer (using ``std::move``), then print the number of cupcakes eaten in the same way.

Note that both pointers should be ``nullptr`` after ``EatAndDeallocate`` is completed.

## Run the program

To manually test your code you can compile and run with a shortcut to create ``main``:

```
make build
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

Make sure to fix any address sanitizer errors as these count towards your test correctness grade.

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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cc`  `cupcake.cc` `stomach.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc cupcake.cc stomach.cc -o main
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
