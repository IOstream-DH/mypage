#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>

//#include "�Ű�_���_���.h"
//#include "�Ű�_���_��������.h"

using namespace std;

CONSOLE_SCREEN_BUFFER_INFO currentCood;
extern int curXcood;
extern int curYcood;

void script(const string& sentence);
void setCursorCood(int x, int y);
void enter();

int curXcood;
int curYcood;




void script(const string& sentence)
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &currentCood);

	//string sentecne;

	curXcood = currentCood.dwCursorPosition.X;
	curXcood = currentCood.dwCursorPosition.Y;

	cout << sentence;
	enter();
	setCursorCood(curXcood, curYcood + 2);
}

void setCursorCood(int x, int y)
{
	COORD coord = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void enter()
{
	string enter;
	cin >> enter;
	cout << enter;
}





int main()
{
	script("Hello World");


	return 0;
}