#include "snake_operation.h"



/**初始化蛇的位置
 * */
void Snake_opt::snake_init()
{
    srand(time(0));                //设置随机数种子  
    snake_data.head_location=MERGE(V/2,3);      //竖坐标从中点处开始
    snake_data.snake_track[1]=MERGE(V/2,1);    
    snake_data.snake_track[0]=MERGE(V/2,2);    //初始化长度为3
    snake_data.snake_len=2;
    snake_data.direction_now=EAST;
    generate_food();                        //生成食物
}


//移动原理示例：如果蛇身体长４，head-a[0]-a[1]-a[2]-a[3],移动后　新head-a[0](原head)-a[1](原a[0])-a[2](原a[1])-a[3](原a[2]),删除原a[3]，即完成移动

void Snake_opt::turnEast()  
{

}

void Snake_opt::turnSouth()
{

}

void Snake_opt::turnWest()                      //蛇的移动子处理函数
{

}

void Snake_opt::turnNorth()
{
    
}

void Snake_opt::generate_food()                                 //生成食物
{

}


void Snake_opt::eat_food_operation()
{

}

/**
 *  返回１表示吃到食物，０表示未吃到
 * */
s8 Snake_opt::eating_food()                                 //检测吃到食物
{
    return 0;
}

/**
 *  返回１表示吃到自己，０表示未吃到
 * */
s8 Snake_opt::check_eat_self()                                //检测是否吃到自己
{
    return 0;
}

/**
 *  返回１表示撞墙，０表示未撞墙
 * */
s8 Snake_opt::check_hit_wall()
{
    return 0;
}

/**
 *  通关
 * 
 * */
s8 Snake_opt::congratulations()
{
    return 0;
}


/**获取键值并且转换成移动的方向
 * 
 * */
snake_direction_t Snake_opt::convert_input_key(s8 input_key)
{
    switch(input_key)
    {
        case 'w':
        case 'W':
        case 0x26: 
        //printf("up\r\n");
        return NORTH;
        break;
        case 's':
        case 'S':
        case 0x28:
        //printf("down\r\n");
        return SOUTH;
        break;
        case 'a':
        case 'A':
        case 0x25:
        //printf("left\r\n");
        return WEST;
        break;
        case 'd':
        case 'D':
        case 0x27:
        //printf("right\r\n");
        return EAST;
        break;
    }
    return KEEP;
}


/**返回显示所需要参数结构体
 * 
 * 
 * */
snake_data_t* Snake_opt::snake_control(s8 input_key)
{
    snake_direction_t dire;
    dire = convert_input_key(input_key);
    snake_move(dire);
    if(eating_food())
    {
        eat_food_operation();
        generate_food();
    }
    if(check_eat_self())
    {
        return (snake_data_t*)EAT_SELF;
    }
    if(check_hit_wall())
    {
        return (snake_data_t*)HIT_WALL;
    }
    if(congratulations())
    {
        return (snake_data_t*)CONGRAT;
    }
    return &snake_data;
}


/*过滤掉相反方向和方向不动的移动*/
void Snake_opt::snake_move(snake_direction_t snake_direction)
{
    switch(snake_direction)
    {
        case KEEP:
        snake_move(snake_data.direction_now);
        break;
        case EAST:
        if(WEST!=snake_data.direction_now)
        {
            turnEast();
        }
        break;
        case SOUTH:
        if(NORTH!=snake_data.direction_now)
        {
            turnSouth();
        }
        break;
        case WEST:
        if(EAST!=snake_data.direction_now)
        {
            turnWest();
        }
        break;
        case NORTH:
        if(SOUTH!=snake_data.direction_now)
        {
            turnNorth();
        }
        break;
        default:break;
    }
}




#ifdef OPERATION_DEBUG

Snake_opt snake;
void main()
{
    snake.graph_init();
    snake.start_graph();
    snake.game_gragh();
    sleep(10);
    snake.stop_graph();
}


#endif
