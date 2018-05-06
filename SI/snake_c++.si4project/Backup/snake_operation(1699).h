#ifndef _SNAKE_OPERATION_H
#define _SNAKE_OPERATION_H


#include "common.h"




class Snake_opt
{
    public:
        snake_data_t* snake_control(s8 input_key);
        void snake_move(snake_direction_t snake_direction);   //蛇的移动,做一层方向过滤
        void snake_init();                                    //最开始蛇的形状
        void generate_food();                                 //生成食物
        s8 eating_food();                                 //检测吃到食物
        s8 check_eat_self();                                //检测是否吃到自己
        s8 check_hit_wall();                                //检测是否撞墙
    private:
        void turnEast();
        void turnSouth();
        void turnWest();         //蛇的移动子处理函数
        void turnNorth();
        void eat_food_operation();
        s8 congratulations();
        snake_direction_t convert_input_key(s8 input_key);
        snake_data_t snake_data;
};

#endif