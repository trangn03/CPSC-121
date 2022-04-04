#include "cup.hpp"
#include <iomanip>
#include <iostream>

int main() {
  std::string drink_name;
  double amount;
  std::cout << "What kind of drink can I get you?: ";
  std::getline(std::cin, drink_name);
  std::cout << "How much do you want?: ";
  std::cin >> amount;
  //
  // 1. Construct the Cup object using the non-default constructor.
  //

  char menu_input = ' ';
  do {
    std::cout << "Your cup currently has " << mug.fluid_oz() << " oz. of "
              << mug.drink_type() << "\n";
    std::cout << "Please select what you want to do with your drink/cup?:\n";
    std::cout << "D: Drink\n";
    std::cout << "R: Refill\n";
    std::cout << "N: Get a brand new drink\n";
    std::cout << "E: Empty\n";
    std::cout << "X: Exit\n";
    std::cout << "Selection: ";
    std::cin >> menu_input;
    std::cin.ignore();
    if (menu_input == 'D' || menu_input == 'd') {
      double drink_amount;
      std::cout << "How much do you want to drink from the cup?: ";
      std::cin >> drink_amount;
      std::cin.ignore();
      //
      // 2. Call the right cup function here to drink from the cup.
      //

    } else if (menu_input == 'R' || menu_input == 'r') {
      double refill_amount;
      std::cout << "How much do you want to refill your cup?: ";
      std::cin >> refill_amount;
      std::cin.ignore();
      //
      // 3. Call the right cup function here to refill the cup.
      //

    } else if (menu_input == 'N' || menu_input == 'n') {
      std::string new_drink_name;
      std::cout << "What is the new drink you want?: ";
      std::getline(std::cin, new_drink_name);
      std::cout << "What is the amount you want?: ";
      std::cin >> amount;
      std::cin.ignore();
      //
      // 4. Call the right cup function to get a brand new drink.
      //

    } else if (menu_input == 'E' || menu_input == 'e') {
      std::cout << "Emptying your cup\n";
      //
      // 5. Call the right cup function to empty the cup.
      //

    } else if (menu_input == 'X' || menu_input == 'x') {
      std::cout << "Thank you for using Digicup!\n";
    } else {
      std::cout << "Invalid use of Digicup!\n";
    }
  } while (menu_input != 'X' && menu_input != 'x');
  return 0;
}
