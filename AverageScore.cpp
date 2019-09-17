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
		mov ebx, 0; //ebx will hold the sum of all the scores (note that calling a function may overwrite eax)

	WhileLoop:
		call getInput;
		cmp input, -1;
		je ExitLoop; //exit the loop if input==-1
		add ebx, input;
		inc amountOfScores; // amountOfScores is the number we divide by to get the average of the scores
		jmp WhileLoop; //go back up

	ExitLoop:
		mov eax, ebx; //move to eax for division
		cdq; //edx:eax = ebx (convert double word to quad word)
		idiv amountOfScores; //eax = ebx/amountOfScores (edx = ebx%amountOfScores)
		mov averageScore, eax;
	}

	cout << "Your average score is: " << averageScore;

	return 0;
}