#include <iomanip>
#include <iostream>

int main() {
  int size;
  std::cout << "How many students are in your class? ";
  std::cin >> size;
  // Get the number of students
  if (size <= 0) {
    std::cout << "You have no class!\n";
  } else {

    //
    // Dynamically create a vector whose size is the same as
    // the number of students in the class (based on the size they provided
    // in the previous question, stored in the size variable).
    // Don't forget to #include <vector>.
    //

    std::cout << "Enter the GPA for the students in your class (0.0 - 4.0)\n";
    for (int i = 0; i < size; i++) {
      std::cout << "Enter the GPA for student #" << i + 1 << ": ";

      //
      // Assign values from cin into the corresponding element of the vector.
      //

    }
    double average;

    //
    // Call your CalculateAvg function and provide the necessary parameters
    // then store the results in the average variable.
    // Make sure to include calculate_avg.h before you use CalculateAvg.
    //

    std::cout << "Class average: " << std::setprecision(2) << std::fixed
              <<  average << "\n";
  }

  return 0;
}
