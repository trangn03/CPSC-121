#include <iostream>

int main () {

//create variable

int pepperoni, onion, jalapeno; 

//asking the user 
std::cout << "How many pepperoni do you want? " ;
std::cin >> pepperoni;
std::cout << "How many onions do you want? " ;
std::cin >> onion ; 
std::cout << "How many jalapenos do you want? ";
std::cin >> jalapeno; 

//create an new string
std::string toppings = ""; 

//add pizza toppings
for ( int i = 0; i < pepperoni; i++){
toppings = toppings + "pepperoni ";
}
for ( int i = 0; i < onion; i++){
toppings = toppings + "onion ";
}
for ( int i = 0; i < jalapeno; i++){
toppings = toppings + "jalapeno ";
}

//output of toppings

if (!toppings.empty()) {
std::cout << "Here's your pizza! \n";
std::cout << "Pizza with: " + toppings;
}
else {
std::cout << "Looks like you weren't hungry. Maybe next time? "; 
}
}

