#include "snake_operation.h"
#include "show_graph.h"



void Snake_opt::snake_init()
{
    head_location=MERGE(V/2,3);      //竖坐标从中点处开始
    snake_track[1]=MERGE(V/2,1);    
    snake_track[0]=MERGE(V/2,2);    //初始化长度为3
    snake_len=2;
    direction_now=EAST;
}

void Snake_opt::turnEast()
{

}

void Snake_opt::turnSouth()
{

}
void Snake_opt::turnWest()         //蛇的移动子处理函数
{

}
void Snake_opt::turnNorth()
{
    
}



void Snake_opt::snake_move(snake_direction_t snake_direction)
{
    switch(snake_direction)
    {
        case KEEP:
        case EAST:
        case SOUTH:
        case WEST:
        case NORTH:
        default:break;
    }
}


void Snake_opt::move(snake_direction_t snake_direction_t)
{

}



#ifdef OPERATION_DEBUG

void main()
{

}


#endif
