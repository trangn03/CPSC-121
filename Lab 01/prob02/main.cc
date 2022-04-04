#include <iostream> 
#include <iomanip>
#include <string>

int main(){

//create integer type
double meal_cost; 
double tip_percentage; 
double subtotal; 
double taxes;  
double tip;
double total; 

//create user input
std::cout <<"Please input meal cost: ";
std::cin >> meal_cost;
std::cout <<"Please input tip percentage: ";
std::cin >> tip_percentage; 
std::cout << std::setprecision(2);
std::cout << std::fixed; 

//calculate the cost
subtotal = meal_cost; 
taxes = (0.075)*meal_cost;
tip =  meal_cost*(tip_percentage/100);
total = subtotal + taxes + tip;

//Output - Print the value that calculated
std::cout << "\n" <<"Restaurant Bill" << "\n"
<<"====================" << "\n" 
<<"Subtotal: $" << subtotal << "\n"  
<<"Taxes: $" << taxes << "\n" 
<<"Tip: $" << tip <<"\n" 
<<"====================" << "\n" 
<<"Total: $" << total << "\n"; 

return 0;
}
