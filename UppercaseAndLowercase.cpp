#include <iostream>

using namespace std;

char current;
short upperCase = 0, lowerCase = 0;

void getNextChar()
{
	current = cin.get();
}

int main()
{
	cout << "Type some text: ";
	//Note that taking in the input is done in getNextChar(), rather than through something like cin >> current;
	
	_asm
	{
	WhileLoop:
	  call getNextChar;
		cmp current, 10; //(char)10 is the newline character
		je ExitWhileLoop;

		/* Usually in a sentence, lowerCase > upperCase > other
		General outline: 
		First, check if current is lowercase
		  greater than or equal to 'a'
		  less than or equal to 'z'
		Second, check if current is uppercase
		  greater than or equal to 'A'
		  less than or equal to 'Z'
		*/

  //MayBeLowercase:
		cmp current, 'a';
		jl MayBeUppercase;
		cmp current, 'z';
		jg WhileLoop;
		inc lowerCase;
		jmp WhileLoop;

	MayBeUppercase:
		cmp current, 'A';
		jl WhileLoop;
		cmp current, 'Z';
		jg WhileLoop;
		inc upperCase;
		jmp WhileLoop;

	ExitWhileLoop:

	}

	cout << "Number of uppercase letters: " << upperCase << "\nNumber of lowercase letters: " << lowerCase;

	return 0;
}