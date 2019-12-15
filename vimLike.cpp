#include "vimLike.h"

VimLike::VimLike() : Normal(), Edit(){
	mode = 0;
}

void VimLike::runBackend(){
	initscr(); //start
	noecho();
    while (getMode() >= 0){
    	switch(getMode()){
		case 0:
    		setMode(normalMode());
    		break;
    	case 1:
    		setMode(editMode());
    	default:
    		break;
    	}
    }
    endwin();
}

char VimLike::getMode(){
	return mode;
}

void VimLike::setMode(char mode){
    this -> mode = mode;
}

void VimLike::bind(std::string key_comb, void (*func)(void), std::string instr){
	if (key_comb.substr(0,5) == "#vim#" or key_comb[0] != '#'){

		std::string key_comb1 = key_comb;
		if (key_comb1.substr(0,5) == "#vim#"){
			key_comb1 = key_comb1.substr(5);
		}

		addHelpLine(key_comb1,instr);
		addCommand(key_comb1,func);
	}
}



// void VimLike::bind(std::string key_comb, std::string instr){
// 	if (key_comb.substr(0,5) == "#vim#" or key_comb[0] != '#'){
// 		std::string key_comb1 = key_comb;
// 		if (key_comb1.substr(0,5) == "#vim#"){
// 			key_comb1 = key_comb1.substr(5);
// 		}
// 		addHelpLine(key_comb1,instr);
// 	}
// }

