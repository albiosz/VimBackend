#include "normal.h"

Normal::Normal(){
    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
    addInstruction(":q or :quit", "exit from application\n");
    addInstruction(":h or :help", "get help about commands\n");
}

char Normal::normalMode(){
	
	do{
        printMode();
        move(0,0);

        std::string command="";
        int c;
    	c = getch();

    	switch (c){
    		case 'i':
    			return 1;
    			break;
    		case ':':
    			command = write();
    			break;
    		default:
    		break;
    	}

    	if (command != ""){
    		if (command == ":q" || command == ":quit") return -1;
            else if (command ==":h" || command == ":help") help();
    	}
    	else{
    		move(0,0);
    	}

    } while(true);
}

std::string Normal::write(){
	move(rows-1,0);
    clrtoeol();
    printw(":");
    std::string text = ":";
	while(true){
		char c = getch();
		switch(c){
			case 27:
				return "";
				break;
			case 127:
                int x,y;
				getyx(curscr,y,x);
    			move(y,--x);
    			delch();
                text = text.substr(0,text.size()-1);
                break;
    		case 10:
    			return text;
                break;
    		default:
                printw("%c",c);
                text += c;
                // char cstr[text.size()+1];
                // strcpy(cstr, text.c_str());
                // printw("%s",cstr);
                break;
		}
	}
}

void Normal::help(){
    clear();
    move(0,0);
    printw("Help section. Commands with description:\n");
    for (unsigned int i = 0; i < instr.size(); i++){
        char com[instr[i].command.size()+1];
        char des[instr[i].description.size()+1];
        strcpy(com, instr[i].command.c_str());
        strcpy(des, instr[i].description.c_str());
        printw("%s - %s",com,des);
    }
    printw("\n\nPress a KEY to exit help section!");
    getch();
    clear();
}

void Normal::addInstruction(std::string com, std::string des){
    actions temp {com,des};
    instr.push_back(temp);
}

void Normal::printMode(){
    move(rows-1,0);
    clrtoeol();
    printw("-- Normal Mode --");
    move(0,0);
}