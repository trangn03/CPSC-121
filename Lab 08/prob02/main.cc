// Include any headers you might need.
#include <iostream>
#include <string>

#include "doe.h"
#include "joey.h"
#include "kangaroo.h"

int main() {
  // 1. Ask the user for the doe's name, and the joey's name.
  std::string k, j;
  std::cout << "What is the doe's name? ";
  std::cin >> k;
  std::cout << "What is the joey's name? ";
  std::cin >> j;
  // 2. Create a Doe with these names.
  Doe d(k, j);
  // 3. Get a reference to the Doe's Joey.
  Joey& o = d.GetJoey();

  std::string answer;
  do {
    // 4. Bounce the Doe once and then the Joey once.
    d.Bounce();
    o.Bounce();
    // 5. Print a message about the number of bounces for the Doe and then the
    // Joey using the format from the README.
    std::cout << d.GetName() << " has bounced " << d.GetBounceCount()
              << " times.\n";
    std::cout << o.GetName() << " has bounced " << o.GetBounceCount()
              << " times.\n";
    // 6. Check if the user wants to bounce again.
    std::cout << "Do you want to bounce again? \"n\" to exit ";
    std::cin >> answer;

  } while (answer != "n");

  return 0;
}
