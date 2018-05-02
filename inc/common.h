#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>


//#define DEBUG


using u8  = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using s32 = signed int;
using s16 = signed short;
using s8  = signed char; 

using std::cout;
using std::cin;
using std::endl;


#define DEL_NUM  10
class Snake_data
{
   
    public:
        typedef enum
        {
            KEEP,
            EAST,
            SOUTH,
            WEST,
            NORTH,
        }snake_direction_t;
        Snake_data(){
            snake_track=new u16[V*H];
        }
        ~Snake_data()
        {
            delete []snake_track;
        }
        u16 head_location;
        u16 food_location;
        snake_direction_t direction_now;
        u16 *snake_track;
        u16 snake_len;
        u16 delete_node[DEL_NUM];
        const u32 V=20;
        const u32 H=50;

        
};

#endif