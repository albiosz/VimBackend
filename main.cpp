#include <ncurses.h>
#include "backend.h"

int main()
{
	initscr(); //start
	VimLike vim;
	vim.addInstruction(":")
	noecho();

    while (vim.getMode() >= 0){
    	switch(vim.getMode()){
		case 0:
    		vim.setMode(vim.normalMode());
    		break;
    	case 1:
    		vim.setMode(vim.editMode());
    	default:
    		break;
    	}
    	
    }
    
    endwin();
    return 0;
}
