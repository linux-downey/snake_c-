#include "snake_operation.h"



/**
 * */
void Snake_opt::snake_init()
{
    srand(time(0));               
    snake_data.head_location=MERGE(V/2,4);      //
	snake_data.snake_track[2]=MERGE(V/2,1);    
    snake_data.snake_track[1]=MERGE(V/2,2);    
    snake_data.snake_track[0]=MERGE(V/2,3);    //

	
    snake_data.snake_len=3;
    snake_data.direction_now=EAST;
    generate_food();                        //
}


//移动原理示例：如果蛇身体长４，head-a[0]-a[1]-a[2]-a[3],移动后　新head-a[0](原head)-a[1](原a[0])-a[2](原a[1])-a[3](原a[2]),删除原a[3]，即完成移动


void Snake_opt::moving(snake_direction_t snake_direction)
{
	u32 v=0,h=0;
    u16 i=0;
    u16 temp[V*H]={0};
    u16 head_temp=0;
    head_temp=snake_data.head_location;    	//get head node location
    
    v=GET_V(snake_data.head_location);
    h=GET_H(snake_data.head_location);
 	switch(snake_direction)
 	{
 		case EAST:
		h+=1;
		//printf("east\r\n");
		break;
		case WEST:
		h-=1;
		//printf("west\r\n");
		break;
		case SOUTH:
		v+=1;
		//printf("south\r\n");
		break;
		case NORTH:
		v-=1;
		//printf("north\r\n");
		break;
		default:break;
 	}
    snake_data.head_location=(MERGE(v,h));     //

    memcpy(temp,snake_data.snake_track,snake_data.snake_len*sizeof(u16));     //
    
    snake_data.delete_node[0]=snake_data.snake_track[snake_data.snake_len-1];   //

    for(i=0;i<snake_data.snake_len-1;i++)           //
    {
        snake_data.snake_track[i+1]=temp[i];
    }
    snake_data.snake_track[0]=head_temp;   //
	snake_data.direction_now=snake_direction;
}




void Snake_opt::generate_food()                                 
{
	u8 food_V=0,food_H=0;
    u8 food_is_in_body_flag=0;
    u32 i=0;
    while(1)
    {
        food_is_in_body_flag=0;
        food_V=rand()%V+1;
        food_H=rand()%H+1;
        snake_data.food_location=MERGE(food_V,food_H);
        for(i=0;i<snake_data.snake_len;i++)         
        {
            if(snake_data.food_location==snake_data.snake_track[i])   //
            {
                food_is_in_body_flag=1;
                break;
            }
        }
        if(!food_is_in_body_flag)    //
        {
            return;
        }
    }
}


void Snake_opt::eat_food_operation()
{
	snake_data.snake_len+=1;
	snake_data.snake_track[snake_data.snake_len-1]=snake_data.delete_node[0];
    snake_data.delete_node[0]=0;
}

/**
 *  
 * */
s8 Snake_opt::eating_food()                                 //
{
	if(snake_data.head_location==snake_data.food_location)	   //
		{
			return 1;
		}

    return 0;
}

/**
 *  
 * */
s8 Snake_opt::check_eat_self()                                //
{
	int i=0;
    for(i=0;i<snake_data.snake_len;i++)
    {
        if(snake_data.head_location==snake_data.snake_track[i])
        {
            return 1;
        }
    }
    return 0;
}

/**
 *  
 * */
s8 Snake_opt::check_hit_wall()
{
	//u16 head_temp=0;
	u8 v,h;
	//head_temp=snake_data.head_location;
	v=GET_V(snake_data.head_location);
    h=GET_H(snake_data.head_location);
	if((0==v)||(v>=V+1)||(0==h)||(h>=H+1))
	{
		return 1;
	}
	
    return 0;
}

/**
 *  
 * 
 * */
s8 Snake_opt::congratulations()
{
	if(V*H==snake_data.snake_len)
	{
		return 1;
	}
    return 0;
}


/**
 * 
 * */
snake_direction_t Snake_opt::convert_input_key(s8 input_key)
{
    switch(input_key)
    {
        case 'w':
        case 'W':
        //printf("up\r\n");
        return NORTH;
        break;
        case 's':
        case 'S':
        //printf("down\r\n");
        return SOUTH;
        break;
        case 'a':
        case 'A':
        //printf("left\r\n");
        return WEST;
        break;
        case 'd':
        case 'D':
        //printf("right\r\n");
        return EAST;
        break;
		default:break;
    }
    return KEEP;                    //If no input or other undefined key value,return KEEP.
}


/**
 * 
 * 
 * */
snake_data_t* Snake_opt::snake_control(s8 input_key)
{
    snake_direction_t dire;
    dire = convert_input_key(input_key);       /*Conver ch to move direction!! */
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



void Snake_opt::snake_move(snake_direction_t snake_direction)
{
	
    switch(snake_direction)
    {
    
        case KEEP:
        moving(snake_data.direction_now);
        break;
        case EAST:
        if(WEST==snake_data.direction_now)
        {
            moving(WEST);
        }
		else
		{
			moving(EAST);
		}
        break;
        case SOUTH:
        if(NORTH==snake_data.direction_now)
        {
            moving(NORTH);
        }
		else
		{
			moving(SOUTH);
		}
        break;
        case WEST:
        if(EAST==snake_data.direction_now)
        {
            moving(EAST);
        }
		else
		{
			moving(WEST);
		}
        break;
        case NORTH:
        if(SOUTH==snake_data.direction_now)
        {
            moving(SOUTH);
        }
		else
		{
			moving(NORTH);
		}
        break;
        default:
			break;
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
