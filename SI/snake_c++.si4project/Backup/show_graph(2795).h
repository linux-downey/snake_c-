#ifndef _SHOW_GRAGH_
#define _SHOW_GRAGH_

#include "common.h"
#include <curses.h>



            


/**
*  
*  
*  
**/


class Graph
{
    public:
        Graph(){};
        ~Graph(){};
		void clean_gragh();              //
		void show_string(s32 y,s32 x,char* str);
        void start_game_gragh();      //
        void graph_init();             //
        void game_gragh();              //
 		void show_game_over_gragh(u32 reason);
        void start_graph(){initscr();}  //
        void stop_graph(){endwin();}    //
        void show_snake(snake_data_t* snake_data);
    private:
        
        void show(void){refresh();}      //
 		void reselect();
		void game_over_congratulations();
		void game_over_eat_self();
		 void game_over_hit_wall();
};


#endif