#include <iostream>

using namespace std;

short amountOfCustomers, amountOfDrinks, amountOfSandwiches, sandwichSize, total, sodaCost = 2, waterCost = 1, tenInchCost = 3, twelveInchCost = 5;
char drinkKind;

void getData()
{
	cout << "\nHow many drinks? ";
	cin >> amountOfDrinks;
	cout << "(S)oda cans or (W)ater bottles? ";
	cin >> drinkKind;

	cout << "How many sandwiches? ";
	cin >> amountOfSandwiches;
	cout << "Which size? (10/12 inches) ";
	cin >> sandwichSize;
}

void displayBill()
{
	cout << "\nYour total bill: $" << total << endl;
}

int main()
{
	cout << "----7-Eleven Convenience Store----\n\nDrinks\n\tSoda....................$2\n\tWater...................$1\n\nSandwiches\n\t10 inch.................$3\n\t12 inch.................$5\n";

	cout << "\nHow many people are ordering? ";
	cin >> amountOfCustomers;

	_asm
	{
	WhileLoop:
		cmp amountOfCustomers, 0; //first, check if there are any more customers
		je ExitWhileLoop; //if there aren't, exit the while loop
		dec amountOfCustomers; //otherwise, decrement amountOfCustomers and keep going
		call getData;
	
	DrinkCost:
		mov ax, amountOfDrinks; //move amountOfDrinks to ax for multiplication
		cmp drinkKind, 'S';
		jne WaterCost; //if it's not (S)oda, skip over SodaCost and go to WaterCost, otherwise keep going into SodaCost
  //SodaCost:
		imul sodaCost;
		jmp SandwichCost; //now skip over WaterCost
	WaterCost:
		imul waterCost;

	SandWichCost:
		mov total, ax; //add this person's drink cost onto total
		mov ax, amountOfSandwiches; //move amountOfSandwiches to ax for multiplication
		cmp sandwichSize, 10;
		jne TwelveInchCost; //same logic with the DrinkCost
  //TenInchCost:
		imul tenInchCost;
		jmp Total;
	TwelveInchCost:
		imul twelveInchCost;

    Total:
		add total, ax; //add this person's sandwich cost onto total
		call displayBill;
		jmp WhileLoop; //go back up

	ExitWhileLoop:

	}
	
	return 0;
}