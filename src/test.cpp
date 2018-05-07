#include <stdio.h>  
#include <stdlib.h>  
#include <curses.h>
#include <unistd.h>
#include <pthread.h>


#include "common.h"
#include "get_input.h"
#include "show_graph.h"                      
#include "snake_operation.h"




#ifdef TEST_INPUT
userInput Input(2);

int main()                       
{
    s8 ch=0;
    initscr();
    Input.getInputInit();
    while(1)
    {
        ch=Input.getUserInput();
        if(ch!=-1)
        {
            cout<<ch+1<<endl;
        }
        //sleep(1);
    }
}
#endif

#ifdef TEST_GRAGH
Graph snake;
int main()
{
    snake.graph_init();
    snake.start_graph();
    snake.game_gragh();
    sleep(10);
    snake.stop_graph();
}
#endif

#ifdef TEST_SNAKE_OPERATION
Graph snake_graph; 
userInput Input(3);

int main()
{
    snake.graph_init();
    snake.start_graph();
    snake.game_gragh();

    return 0;
}
#endif


