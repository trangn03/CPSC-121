#include <iostream>
#include <string>
#include <cstdlib> 

#include "cpputils/graphics/image.h"
#include "pizza.h"

using graphics::Image;

int main() { 

Image my_image (500,500);
my_image.SaveImageBmp ("pizza.bmp"); 
char pizza; 
char sauce;
char cheese;
char pepperoni;
char jalapeno;
char onion; 
 
std::cout << "Welcome to PizzaMaker 2.0!" << std::endl;

// ask the user for pizza with toppings. 
std::cout << "Would you like a pizza? \n(y/n): "; 
std::cin >> pizza;
if ( pizza == 'y' ){
AddCrust (my_image);


std::cout << "Would you like tomato sauce?\n(y/n): ";
std::cin >> sauce;
if ( sauce == 'y' ) {
AddSauce (my_image);
} 
std::cout << "Would you like cheese with that? \n(y/n): ";
std::cin >> cheese;
if ( cheese == 'y' ) {
AddCheese (my_image);
} 
std::cout << "Would you like pepperoni? \n(y/n): ";
std::cin >> pepperoni;
if ( pepperoni == 'y' ) {
AddPepperoni (my_image);
} 
 
std::cout << "Would you like jalapeno with that? \n(y/n): ";
std::cin >> jalapeno;
if ( jalapeno == 'y' ) {
AddJalapeno (my_image);
}
 
std::cout << "Would you like onion? \n(y/n): ";
std::cin >> onion;
if ( onion == 'y' ) {
AddOnion (my_image);
} 

std::cout << "Great! Your pizza is at pizza.bmp. Enjoy!";
} 
else {
} 
return 0;
}  
