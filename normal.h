#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "help.h"

struct Command{
	std::string com;
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
	void printMode();

public:
	Normal();
	char normalMode();
	void addCommand(std::string, void (*func)(void));
	void addCommandClass(std::string com, void (Normal::*func)(void));
	void chooseFuction(std::string com);
	int changeTextToInt(std::string text);
	int quit();
};