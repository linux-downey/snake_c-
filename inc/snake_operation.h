#ifndef _SNAKE_OPERATION_H
#define _SNAKE_OPERATION_H


#include "common.h"




class Snake_opt
{
    public:
        snake_data_t* snake_control(s8 input_key);
		snake_data_t* get_snake_data();
		void snake_init();
		void restart();
    private:
    	void snake_move(snake_direction_t snake_direction);
        void generate_food();                                 
        s8 eating_food();                                 
        s8 check_eat_self();                                
        s8 check_hit_wall();     
		void moving(snake_direction_t snake_direction);
        void eat_food_operation();
        s8 congratulations();
        snake_direction_t convert_input_key(s8 input_key);
        snake_data_t snake_data;
};

#endif