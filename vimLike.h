#pragma once

#include "normal.h"
#include "edit.h"
#include "backend.h"

#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>


class VimLike : public Normal, public Edit, public Backend {
private:
	char mode;

public:
	VimLike();
	void runBackend();
	char getMode();
	void setMode(char);
	void bind(std::string,void (*func)(void ),std::string);
	// void bind(std::string,void (FrontEnd::*func)(void ),std::string);
	// void bind(std::string,std::string);
};