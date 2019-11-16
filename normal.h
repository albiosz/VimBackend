#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

struct actions{
	std::string command;
	std::string description;
};

class Normal{
private:
	int columns,rows; // rozmiary okna
	std::string write();
	std::vector <actions> instr;
	void printMode();

public:
	Normal();
	char normalMode();
	void help();
	void addInstruction(std::string, std::string);

};