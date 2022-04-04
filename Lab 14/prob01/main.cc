#include "pair_class_template.h"

int main() {
  // Create an instance of `MyPair` object called `p1` using `int`
  // and passing in values `3` and `5`
  MyPair<int> p1(3, 5);

  // *Start using `p1` to call methods*
  // Call the Display method
  p1.Display();

  std::cout << "\n";
  // Call the DisplayReverse method
  p1.DisplayReverse();

  std::cout << "\n";
  // Call the MaxValue method and print the value
  std::cout << p1.MaxValue() << "\n";
  // Call the MinValue method and print the value
  std::cout << p1.MinValue() << "\n";
  // Call the SwapValue method;
  p1.SwapValue();

  // Call the Display method
  p1.Display();

  std::cout << "\n";
  // Call the DisplayReverse method
  p1.DisplayReverse();

  std::cout << "\n";
  // Create an instance of `MyPair` object called `p2` using `double`
  // and passing in the values `9.7` and `6.4`
  MyPair<double> p2(9.7, 6.4);

  // *Start using `p2` to call methods*
  // Call the Display method
  p2.Display();

  std::cout << "\n";
  // Call the DisplayReverse method
  p2.DisplayReverse();

  std::cout << "\n";
  // Call the MaxValue method and print the value
  std::cout << p2.MaxValue() << "\n";
  // Call the MinValue method and print the value
  std::cout << p2.MinValue() << "\n";
  // Call the SwapValue method;
  p2.SwapValue();

  // Call the Display method
  p2.Display();

  std::cout << "\n";
  // Call the DisplayReverse method
  p2.DisplayReverse();

  std::cout << "\n";
  // Create an instance of `MyPair` object called `p3` using `char`
  // and passing in the values `a` and `z`
  MyPair<char> p3('a', 'z');

  // *Start using `p3` to call methods*
  // Call the Display method
  p3.Display();

  std::cout << "\n";
  // Call the DisplayReverse method
  p3.DisplayReverse();

  std::cout << "\n";
  // Call the MaxValue method and print the value
  std::cout << p3.MaxValue() << "\n";
  // Call the MinValue method and print the value
  std::cout << p3.MinValue() << "\n";
  // Call the SwapValue method;
  p3.SwapValue();

  // Call the Display method
  p3.Display();

  std::cout << "\n";
  // Call the DisplayReverse method
  p3.DisplayReverse();

  std::cout << "\n";
  return 0;
}
