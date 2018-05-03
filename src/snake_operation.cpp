#include "snake_operation.h"
#include "show_graph.h"


/**初始化蛇的位置
 * */
void Snake_opt::snake_init()
{
    head_location=MERGE(V/2,3);      //竖坐标从中点处开始
    snake_track[1]=MERGE(V/2,1);    
    snake_track[0]=MERGE(V/2,2);    //初始化长度为3
    snake_len=2;
    direction_now=EAST;
}


//移动原理示例：如果蛇身体长４，head-a[0]-a[1]-a[2]-a[3],移动后　新head-a[0](原head)-a[1](原a[0])-a[2](原a[1])-a[3](原a[2]),删除原a[3]，即完成移动

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

void Snake_opt::generate_food()                                 //生成食物
{

}
void Snake_opt::eating_food()                                 //检测吃到食物
{

}
s8 Snake_opt::check_eat_self()                                //检测是否吃到自己
{

}
s8 Snake_opt::check_hit_wall()
{
    
}



/*过滤掉相反方向和方向不动的移动*/
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
