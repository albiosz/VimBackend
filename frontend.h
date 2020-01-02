#pragma once
#include <ncurses.h>

class Frontend {
  public:
  	virtual void setEntry(std::string,std::string) = 0;
  	virtual std::string getEntry(std::string) = 0;
};