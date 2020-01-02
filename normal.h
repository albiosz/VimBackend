#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "help.h"
#include "frontend.h"


struct Command{
	std::string com;
	std::string entry;
	bool edit_mode;
	void (*function)(void);
};

struct Key
{
    std::string text;
    int num;
};

const Key keys[] {Key{"<ENTER>", 10}, Key{"<ESC>", 27}};

class Normal : public Help {
private:
	int columns,rows; // rozmiary okna
	std::vector<Command> commands;
	std::string write();
	Frontend *frontend;
	void printMode();

protected:
	void (*edition)(void);

public:
	Normal(Frontend* front);
	char normalMode();
	void addCommand(std::string, std::string, bool edit_mode, void (*func)(void));
	// void addCommandClass(std::string, std::string, void (Frontend::*func)(void));
	bool chooseFunction(std::string com);
	int changeTextToInt(std::string text);
	void eraseChar();
	int quit();
};