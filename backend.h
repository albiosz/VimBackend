#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstring>
#include "normal.h"
#include "edit.h"

class VimLike : public Normal, public Edit{
private:
	char mode;

public:
	VimLike();
	//editMode();
	//std::string write();
	char getMode();
	void setMode(char);
};