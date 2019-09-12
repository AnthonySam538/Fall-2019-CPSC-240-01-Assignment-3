#include <iostream>

using namespace std;

short amountOfCustomers, amountOfDrinks, amountOfSandwiches, sandwichSize, total, sodaCost = 2, waterCost = 1, tenInchCost = 3, twelveInchCost = 5;
char drinkKind;

void getData()
{
	cout << "How many drinks? ";
	cin >> amountOfDrinks;
	cout << "(S)oda cans or (W)ater bottles? ";
	cin >> drinkKind;

	cout << "How many sandwiches? ";
	cin >> amountOfSandwiches;
	cout << "Which size? (10/12 inches) ";
	cin >> sandwichSize;
}

int main()
{
	cout << "----7-Eleven Convenience Store----\n\nDrinks\n\tSoda....................$2\n\tWater...................$1\n\nSandwiches\n\t10 inch.................$3\n\t12 inch.................$5\n";

	cout << "How many people are ordering? ";
	cin >> amountOfCustomers;

	_asm
	{
	WhileLoop:
		call getData;
	
	DrinkCost:
		mov ax, amountOfDrinks;
		cmp drinkKind, 'S';
		jne WaterCost;
  //SodaCost:
		imul sodaCost;
		jmp SandwichCost;
	WaterCost:
		imul waterCost;

	SandWichCost:
		mov total, ax;
		mov ax, amountOfSandwiches;
		cmp sandwichSize, 10;
		jne TwelveInchCost;
  //TenInchCost:
		imul tenInchCost;
		jmp Total;
	TwelveInchCost:
		imul twelveInchCost;

    Total:
		add total, ax;
		dec amountOfCustomers;
		cmp amountOfCustomers, 0;
		jne WhileLoop;
	}

	cout << "Your total bill: $" << total;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// void getNextChar(){input = cin.get();}