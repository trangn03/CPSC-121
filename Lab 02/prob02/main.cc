#include <iostream>
#include <string>
#include "input.h"
#include "input.cc"

//start code 
int main () {
std::cout << "Do you like chocolate chip cookies? Enter \"yes\" or \"no\": ";

bool likes_cookies = false;

//Call the GetYesOrNoInput function you defined in input.h, and store the result in likes_cookies.

likes_cookies = GetYesOrNoInput();

if (likes_cookies) {
std::cout << "Yummy yummy chocolate chip cookies!" << std::endl;
} else {
std::cout << "To each their own!" << std::endl;
}
return 0;
}

