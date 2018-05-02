#ifndef _SHOW_GRAGH_
#define _SHOW_GRAGH_

#include "common.h"
#include <curses.h>



//#define GRAPH_DEBUG

#define MERGE(v,h)  ((u16)((v<<8)|h))
#define GET_V(x)    ((u8)((u16)x>>8))
#define GET_H(x)    ((u8)x)              


/**显示类
*  显示游戏初始界面
*  显示初始化
*  
**/


class Graph:public Snake_data
{
    public:
        Graph(){};
        ~Graph(){};
        void start_game_gragh();      //显示游戏初始化界面
        void graph_init();             //初始化界面
        void game_gragh();              //游戏的外框
        void game_faile_gragh();        //游戏死亡界面
        void start_graph(){initscr();}  //使能显示界面
        void stop_graph(){endwin();}    //失能界面
        void show_snake();
    private:
        void clean_gragh();              //清除界面信息
        //void snake_init();               //初始化蛇的出现位置
        void show(void){refresh();}      //刷一遍界面
};


#endif