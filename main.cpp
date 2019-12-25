#include <ncurses.h>
#include "vimLike.h"

class FrontEnd {
   public:
       void methA(){
            printw("%s\n", "testFunc");
        }
};

void testFunc(){
    move(0,0);
    printw("%s\n", "testFunc");
}


void testFunc1(){
    move(0,0);
    printw("%s\n", "testFunc1");
}

int main(){
    VimLike vim;
    Backend* back = &vim;
    back -> bind("#vim#:a<ENTER>%somecomment",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> bind("#vim#:b<ENTER>",testFunc1,"This is sample instruction which prints 'testFunc1'");
    back -> bind(":c<ENTER>.somecomment",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> bind("#nano#:ab",testFunc1,"This is sample instruction which prints 'testFunc'");
    back -> bind("#nano#:ab",testFunc,"This is sample instruction which prints 'testFunc'");
    back -> runBackend();
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
