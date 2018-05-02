#include <stdio.h>  
#include <stdlib.h>  
#include <curses.h>
#include <unistd.h>
#include <pthread.h>


#include "common.h"

#ifdef DEBUG

int main()
{
    initscr();
    cbreak();                    //把终端的CBREAK模式打开  
    noecho();                    //关闭回显,输入的数据被缓存到buf中  
    curs_set(0);                //把光标置为不可见  
    keypad(stdscr, true);        //使用用户终端的键盘上的小键盘  
    srand(time(0));
    move(5,5);
    addch('*');
    refresh();
    sleep(20);
    endwin();
}

#endif
