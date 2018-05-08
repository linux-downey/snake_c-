
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


#ifndef _SNAKE_OPERATION_H
#define _SNAKE_OPERATION_H


#include "common.h"




class Snake_opt
{
    public:
        s32 snake_control(s8 input_key);
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