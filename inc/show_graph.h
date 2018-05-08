//  
//                                  _oo8oo_
//                                 o8888888o
//                                 88" . "88
//                                 (| -_- |)
//                                 0\  =  /0
//                               ___/'==='\___
//                             .' \\|     |// '.
//                            / \\|||  :  |||// \
//                           / _||||| -:- |||||_ \
//                          |   | \\\  -  /// |   |
//                          | \_|  ''\---/''  |_/ |
//                          \  .-\__  '-'  __/-.  /
//                        ___'. .'  /--.--\  '. .'___
//                     ."" '<  '.___\_<|>_/___.'  >' "".
//                    | | :  `- \`.:`\ _ /`:.`/ -`  : | |
//                    \  \ `-.   \_ __\ /__ _/   .-` /  /
//                =====`-.____`.___ \_____/ ___.`____.-`=====
//                                  `=---=`
//  
//  
//       ~~~~~~~Powered by https://github.com/ottomao/bugfreejs~~~~~~~
// 
//                          佛祖保佑         永无bug
// 



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
		void show_string(s32 y,s32 x,const char* str);
        void start_game_gragh();      //
        void graph_init();             //
        void game_gragh();              //
 		void show_game_over_gragh(s32 reason);
        void start_graph(){initscr();}  //
        void stop_graph(){endwin();}    //
        void show_snake(snake_data_t* snake_data);
		void select_gragh();
    private:
        
        void show(void){refresh();}      //
 		void reselect();
		void game_over_congratulations();
		void game_over_eat_self();
		 void game_over_hit_wall();
};


#endif