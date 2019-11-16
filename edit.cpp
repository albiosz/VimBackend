#include "edit.h"

Edit::Edit(){
    getmaxyx( stdscr, rows, columns ); //Pobieranie wartości okna do zmiennych
    x = 0;
    y = 0;
}


char Edit::editMode(){
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
    			return 0;
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

void Edit::eraseChar(){
    int x,y;
    getyx(curscr,y,x);
    move(y,--x);
    delch();
}