//Your code here to implement the function
#include <iostream>
#include <string>
#include "input.h"

//conditional statement
bool GetYesOrNoInput(){
std::string answer;

while(1) {
std::cin >> answer; // Taking user input 

// If the user enter yes 
if (answer == "yes" ) {
return true; 
}
// If the user enter no 
else if ( answer == "no" ) {
return false;
}
// Otherwise, loop again and keep on taking input
else {
std::cout << "Sorry. I didn't understand. Try again: ";
}
}
} 
