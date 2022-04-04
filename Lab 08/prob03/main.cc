#include <iomanip>
#include <iostream>

#include "utensils.h"

int main() {
  std::string name;
  std::string color;
  double mass;
  double size;
  double bite_size;

  std::cout << "Please enter the name of a food item: ";
  std::getline(std::cin, name);
  std::cout << "Please enter the mass of the food item: ";
  std::cin >> mass;
  // Create a Food object and pass the user's input to the constructor
  Food food(name, mass);
  std::cout << "Please enter the size of the spoon: ";
  std::cin >> size;
  std::cout << "Please enter the color of the spoon: ";
  std::cin.ignore();
  std::getline(std::cin, color);
  std::cout << "Please enter your bite size using the spoon: ";
  std::cin >> bite_size;
  // Create a Spoon object and pass the user's input to the constructor
  Spoon spoon(size, color, bite_size);
  std::cout << "Food before being eaten:\n";
  // Call the food object's print member function
  food.print();
  std::cout << "Food after spoon used:\n";
  // Call the spoon object's use function and pass your food object as the
  // argument
  spoon.use(food);
  food.print();
  // Call the food object's print member function again
  return 0;
}
