#ifndef _SNAKE_OPERATION_H
#define _SNAKE_OPERATION_H


#include "common.h"


class Snake_opt:public Snake_data
{
    public:
        void snake_move(snake_direction_t snake_direction);   //蛇的移动,做一层方向过滤
        void snake_init();                                    //最开始蛇的形状
        void generate_food();                                 //生成食物
        void eating_food();                                 //检测吃到食物
        s8 check_eat_self();                                //检测是否吃到自己
        s8 check_hit_wall();                                //检测是否撞墙
    private:
        void turnEast();
        void turnSouth();
        void turnWest();         //蛇的移动子处理函数
        void turnNorth();
};

#endif