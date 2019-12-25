#include "normal.h"


Normal::Normal(){
    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
    // addCommandClass(":h", &this->printHelp);
    // addCommandClass(":help", &this->printHelp);
}

void Normal::addCommand(std::string com, void (*func)(void)){
    commands.push_back(Command{com, func});
}

void Normal::chooseFuction(std::string com){
    for (Command comm : commands){
        if (comm.com == com){
            comm.function();
            break;
        }
    }
}

char Normal::normalMode(){

	getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
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
            case 'Z': // press double 'Z' to exit
                if (getch() == 'Z') return quit();
                break;
            case 10:
                
    		case ':':
    			command = write();
    			break;
    		default:
    		break;
    	}

    	if (command != ""){
    		if (command == ":q" || command == ":quit") return quit();
            else if (command ==":h" || command == ":help") printHelp();
            else chooseFuction(command);
            
    	}
    	else{
    		move(0,0);
    	}

    } while(true);
}

int Normal::quit(){
    return -1;
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
                break;
		}
	}
}


void Normal::printMode(){
    move(rows-1,0);
    clrtoeol();
    printw("-- Normal Mode --");
    move(0,0);
}

