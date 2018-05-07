#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>


#define RESTART  '1'
#define QUIT     '2'


using u8  = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using s32 = signed int;
using s16 = signed short;
using s8  = signed char; 

using std::cout;
using std::cin;
using std::endl;

//#define TEST_INPUT
//#define DEBUG
//#define TEST_GRAGH
//#define TEST_SNAKE_OPERATION


#define MERGE(v,h)  ((u16)((v<<8)|h))
#define GET_V(x)    ((u8)((u16)x>>8))
#define GET_H(x)    ((u8)x) 




#define V 20
#define H 50
#define DEL_NUM  10

#define EAT_SELF    -1
#define HIT_WALL    -2
#define CONGRAT     -3
typedef enum
{
    KEEP,
    EAST,
    SOUTH,
    WEST,
    NORTH,
}snake_direction_t;


typedef struct
{
    public:
        u16 snake_track[V*H];
        u16 head_location;
        u16 food_location;
        snake_direction_t direction_now;
        //u16 *snake_track;
        u16 snake_len;
        u16 delete_node[DEL_NUM];
        // const u32 V=20;
        // const u32 H=50;      
}snake_data_t;

#endif