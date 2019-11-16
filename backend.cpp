#include "backend.h"

VimLike::VimLike() : Normal(){
	mode = 0;
}

char VimLike::getMode(){
	return mode;
}

void VimLike::setMode(char mode){
    this -> mode = mode;
}