#pragma once
#include "frontend.h"

class OneFrontend : public Frontend {
private:
	static void eraseChar(){
    int x,y;
    getyx(curscr,y,x);
    move(y,--x);
    delch();
	}

public:
	//void setEntry(std::string entry, std::string entry_value) override {std::cout << "Entry's been set. " << "Entry: " << entry << " Entry value: " << entry_value << std::endl;}
	void setEntry(std::string entry, std::string entry_value) override {move(0,0);printw("Entry set\n");}
	std::string getEntry(std::string) override {move(0,0);printw("Entry get");return "NO";}

	static void methA(){
		move(1,0);
	    printw("%s\n", "methA");
	}
	static void editMode(){
		static int columns,rows; // size of a window
		static int x=0,y=0; // position of a cursor
	    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
	    move(rows-1,0);
	    clrtoeol();
	    printw("-- Edit Mode --");
	    move(y,x);
	    char c;
		do{
	        c = getch();
	    	switch (c){
	    		case 27:
	                getyx(curscr,y,x);
	    			return;
	    			break;
	    		case 127:
	                eraseChar();
	                break;
	    		default:
	                printw("%c",c);
	    		break;
	    	}

	    } while(true);
	}

	static void editMode2(){
		static int columns,rows; // size of a window
		static int x=0,y=0; // position of a cursor
	    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
	    move(rows-1,0);
	    clrtoeol();
	    printw("-- Edit Mode --");
	    move(y,x);
	}
};