#include "normal.h"



Normal::Normal(Frontend* front){
    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
    frontend = front;
    // addCommandClass(":h", &this->printHelp);
    // addCommandClass(":help", &this->printHelp);
}

void Normal::addCommand(std::string com, std::string entry, bool edit_mode, void (*func)(void)){
    commands.push_back(Command{com, entry, edit_mode, func});
}

// void Normal::addCommandClass(std::string com, std::string entry, void (Frontend::*func)(void)){
//     commands.push_back(Command{com, entry, func});
// }

bool Normal::chooseFunction(std::string com){

    std::string comI = com.substr(0,com.find(' '));
    
    for (Command comm : commands){
        if (comm.com == comI){
            printw("inside\n");
            if (comm.entry.length() > 0){

                int pos = com.find(' ');
                if (pos != std::string::npos){

                    std::string entry_value = com.substr(com.find(' ') + 1);
                    frontend -> setEntry(comm.entry, entry_value);
                }
            }

            comm.function();

            if (comm.edit_mode){
                edition();

                char c;
                do{
                    c = getch();
                    frontend -> setEntry("KEY", std::string(1,c));
                } while(c != 27);
            }
            break;
        }
    }
}

char Normal::normalMode(){

	getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
    std::string command="";
	do{
        printMode();
        move(0,0);

        char c;
    	c = getch();
        // printw("%d",c);
    	switch (c){
    		case 'i':
    			return 1;
    			break;
            case 'Z': // press double 'Z' to exit
                if (getch() == 'Z') return quit();
                break;
    		case ':':
    			command = write(); // command which starting with : and confirmed by enter
    			break;
    		default:
                command = std::string(1,c); // one character command
    		break;
    	}
        move(0,0);
    	if (command != ""){
    		if (command == ":q" || command == ":quit") return quit();
            else if (command ==":h" || command == ":help") printHelp();
            else chooseFunction(command);

    	}
        
        command = "";

    } while(true);
}

int Normal::quit(){
    if (frontend -> getEntry("IS_SAVED") == "NO"){
        move(rows-1,0);
        clrtoeol();
        printw("Unsaved files! If you want to exit press 'y': ");
        char c = getch();
        if (c != 'y') return 0;
    }
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
                eraseChar();
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

void Normal::eraseChar(){
    int x,y;
    getyx(curscr,y,x);
    move(y,--x);
    delch();
}