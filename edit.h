#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>

class Edit{
private:
	int columns,rows; // size of a window
	int x,y; // position of a cursor

public:
	Edit();
	char editMode();
	void eraseChar();

};