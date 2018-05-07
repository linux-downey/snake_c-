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
	s32 ret=0;
    snake_data_t *snake_data=NULL;
	snake_graph.start_graph();						/*Enable gragp display*/
    snake_graph.graph_init();                       /*Graph param init */
    snake_graph.game_gragh();						/*Show game gragh*/
    Input.getInputInit();							/*Input init*/

	snake_graph.select_gragh();
	Input.select_speed();
	
	snake_graph.clean_gragh();
	
    snake_opt.snake_init();							/*Snake init*/
	
    while(1)
    {
    	ret=snake_opt.snake_control(ch);		/*Move the snake according to input char */
		
		if(ret<0)
		{
			snake_graph.clean_gragh();
			snake_graph.show_game_over_gragh(ret );

			
			while(1)
			{
				ch=Input.getUserInput();
				if(RESTART==ch)
				{
					snake_graph.clean_gragh();
					snake_graph.select_gragh();
					Input.select_speed();
					snake_graph.clean_gragh();

					
					snake_opt.restart();

					
					break;
				}
				else if(QUIT==ch)
				{
					snake_graph.stop_graph();
					return 0;
				}
			}
			
		}
		else
		{
			snake_data=snake_opt.get_snake_data();
			snake_graph.show_snake(snake_data);
        	ch=Input.getUserInput();					/*Get input*/      
		}
    }
}

#endif






