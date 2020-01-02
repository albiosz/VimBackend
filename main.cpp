#include <ncurses.h>

#include "vimLike.h"
#include "oneFrontend.h"

void testFunc(){
    move(0,0);
    printw("%s\n", "testFunc");
}

void testFunc1(){
    move(0,0);
    printw("%s\n", "testFunc1");
}

int main(){

    OneFrontend front;
    VimLike vim(&front);
    //VimLike vim;
    Backend* back = &vim;

    back -> bind("#vim#:a<ENTER>%somecomment",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> bind("#vim#:b<ENTER>",testFunc1,"This is sample instruction which prints 'testFunc1'");
    back -> bind(":c<ENTER>.somecomment",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> bind(".:d<ENTER>.somecomment",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> bind("#nano#:ab",testFunc1,"This is sample instruction which prints 'testFunc'");
    back -> bind("#nano#:ab",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> bind("#vim#:open ${FILE_NAME}<ENTER>", &OneFrontend::methA, "Open a file from class");
    //back -> bind("#vim#:open ${FILE_NAME}<ENTER>",testFunc, "Open a file"); <-- the same command but different function
    //back -> bind("^R", &OneFrontend::methA, "Open a file ctrl R"); // <-- does not work
    back -> bind("<EDITION>",&OneFrontend::editMode2, "Edition mode");
    back -> bind("#vim#:edit!EDIT", &OneFrontend::methA, "Enter edit mode but first run methA");

    back -> runBackend();

    return 0;
}







// int main()
// {
// 	initscr(); //start
// 	VimLike vim;
//     vim.bind("#vim#:a",testFunc,"This is sample instruction which prints 'testFunc'");
//     vim.bind("#vim#:b",testFunc,"This is sample instruction which prints 'testFunc'");
//     vim.bind("#vim#:c",testFunc,"This is sample instruction which prints 'testFunc'");
//     vim.bind("#nano#:ab",testFunc1,"This is sample instruction which prints 'testFunc'");
//     vim.bind("#nano#:ab",testFunc,"This is sample instruction which prints 'testFunc'");
//     // vim.bind("#vim#:a",&FrontEnd::met,"This is sample instruction which prints 'testFunc'");
//     // vim.bind("#vim#:a","This is sample instruction which prints 'testFunc'");
// 	noecho();
//     while (vim.getMode() >= 0){
//     	switch(vim.getMode()){
// 		case 0:
//     		vim.setMode(vim.normalMode());
//     		break;
//     	case 1:
//     		vim.setMode(vim.editMode());
//     	default:
//     		break;
//     	}
//     }
    
//     endwin();
//     return 0;
// }
