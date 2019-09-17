#include <iostream>

using namespace std;

short a, b, c, d, e, f, x=0, y=0;

void getData()
{
	cout << "Enter the values of a, b, c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, f: ";
	cin >> d >> e >> f;
}

int main()
{
	cout << "This program solves the system\n\taX + bY = c\n\tdX + eY = f\n";
	
	_asm
	{
		call getData;

		//Firstly, calculate a*e-b*d, since it's used when calculating both x and y
		//  Calculate a*e
		mov ax, a;
		imul e;
		mov bx, ax; //bx = a*e
		//    Calculate b*d
		mov ax, b;
		imul d; //dx:ax = b*d
		sub bx, ax; //Store a*e-b*d in bx for later use (make sure not to replace bx with anything)

		//Calculate Y = (a*f-c*d)/(a*e-b*d)
		//  Calculate a*f-c*d
		//    Calculate c*d
		mov ax, c;
		imul d;
		mov cx, ax; //Store c*d in cx
		//    Calculate a*f
		mov ax, a;
		imul f; //Store a*f in dx:ax
		sub ax, cx; //Store a*f-c*d in dx:ax
		idiv bx; //divide what's in ax (a*f-c*d) by bx (a*e-b*d)
		mov y, ax;

		//Calculate X = (c*d-b*f)/(a*e-b*d)
		//  Calculate c*e-b*f
		//    Calculate b*f
		mov ax, b;
		imul f;
		mov cx, ax; //Store b*f in cx
		//    Calculate c*e
		mov ax, c;
		imul e; //Store c*e in dx:ax
		sub ax, cx; //Store c*e-b*f in dx:ax
		idiv bx; //divide what's in ax (c*e-b*f) by bx (a*e-b*d)
		mov x, ax;
	}

	cout << "\tX = " << x << "\n\tY = " << y;

	return 0;
}