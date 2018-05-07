#include <stdio.h>  
#include <stdlib.h>  
#include <curses.h>
#include <unistd.h>
#include <pthread.h>

#include "common.h"
#include "get_input.h"
#include "show_graph.h"                      
#include "snake_operation.h"

#ifndef DEBUG
userInput Input(8);
Graph snake_graph;
Snake_opt snake_opt;
int main()
{
    s8 ch=KEEP;
    snake_data_t *snake_data=NULL;
	snake_graph.start_graph();						/*Enable gragp display*/
    snake_graph.graph_init();                       /*Graph param init */
    snake_graph.game_gragh();						/*Show game gragp*/
    Input.getInputInit();							/*Input init*/
    snake_opt.snake_init();							/*Snake init*/
	
    while(1)
    {
    	snake_data=snake_opt.snake_control(ch);		/*Move the snake according to input char */
		if((s32)snake_data<0)
		{
			snake_graph.clean_gragh();
			snake_graph.show_game_over_gragh((s32)snake_data );
			ch=Input.getUserInput();
			/*switch(ch)
			{}*/
			while(1);
		}
		else
		{
			snake_graph.show_snake(snake_data);
        	ch=Input.getUserInput();					/*Get input*/      
		}
    }
}

#endif






