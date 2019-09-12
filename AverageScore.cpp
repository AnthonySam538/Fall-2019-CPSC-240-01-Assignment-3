#include <iostream>

using namespace std;

int input, averageScore, amountOfScores = 0;

void getInput()
{
	cout << "Enter a score: (type -1 to stop) ";
	cin >> input;
}

int main()
{
	_asm
	{
		mov ebx, 0; //ebx will hold the sum of all the scores

	WhileLoop:
		call getInput;
		mov eax, input;
		cmp eax, -1;
		je ExitTheLoop; //exit the loop if input==eax==-1
		add ebx, eax;
		inc amountOfScores; // amountOfScores is the number we divide by
		jmp WhileLoop; //go back up

	ExitTheLoop:
		mov eax, ebx; //move to eax for division
		cdq;
		idiv amountOfScores;
		mov averageScore, eax;
	}

	cout << "Your average score is: " << averageScore;

	return 0;
}