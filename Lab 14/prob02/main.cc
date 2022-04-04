#include <iostream>

#include "array_double.h"

int main() {
  int num_elements;
  int location;
  double value;
  std::cout << "Please enter the number of elements for your array: ";
  std::cin >> num_elements;

  try {
    // TODO(labex): Create an instance of the ArrayDouble class using the user
    //              input value
    ArrayDouble arr(num_elements);

    if (num_elements > 0) {
      std::cout << "Enter a value you would like to add to the array: ";
      std::cin >> value;
      std::cout << "Where would you like to add this number"
                << " (array index 0 to " << num_elements - 1 << ")? ";
      std::cin >> location;

      // TODO(labex): Set the value of the array at the location provided by the
      //              user
      arr[location] = value;

      std::cout << "Value at location " << location << " now contains "
                << arr[location] << std::endl;
    }
    arr.Display();
  } catch (const InvalidArrayLengthException &e) {
    std::cout << e.GetMessage() << std::endl;
  }
  // TODO(labex): Add another catch block to handle IndexOutOfRangeException.
  //              Display the error message just like the
  //              InvalidArrayLengthException above
  catch (const IndexOutOfRangeException &e) {
    std::cout << e.GetMessage() << std::endl;
  }
  return 0;
}
