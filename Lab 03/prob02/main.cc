#include <iostream>
#include <map>
#include <string>

int main() {
  // define a map to store information
  std::map<char, int> my_map;
  std::string input;
  std::cout << "Enter text input to analyze: ";
  std::getline(std::cin, input);
  // store the character in map
  for (int i = 0; i < input.size(); i++) {
    // if the character has in the map, count the character
    if (my_map[input[i]]) {
      my_map[input[i]] += 1;
    } else {
      my_map[input[i]] = 1;
    }
  }
  // Your code here to analyze the input and let the user see what letters
  // are in it.
  // get stat for user to input
  std::string stats;
  while (stats != "quit") {
    std::cout << "What character do you want stats on? ";
    std::cin >> stats;
    if (stats == "quit") {
      std::cout << "Goodbye!" << std::endl;
      return 0;
    }
    std::cout << "The character " << stats[0] << " appears " << my_map[stats[0]]
              << " times. \n";
  }
  return 0;
}
