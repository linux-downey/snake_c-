#include "show_graph.h"



void Graph::clean_gragh()
{
    
}

void Graph::start_game_gragh()
{
    int i=0,j=0;
    for(i=0;i<V+2;i++)
    {
        for(j=0;j<H+2;j++)
        {
            move(i,j);
            addch(' ');
        }
    }
}

void Graph::graph_init()
{
    cbreak();                    //把终端的CBREAK模式打开  
    noecho();                    //关闭回显,输入的数据被缓存到buf中  
    curs_set(0);                //把光标置为不可见  
    keypad(stdscr, true);        //使用用户终端的键盘上的小键盘  
    //srand(time(0));                //设置随机数种子  
}


// void Graph::snake_init()
// {
//     head_location=MERGE(V/2,3);      //竖坐标从中点处开始
//     snake_track[1]=MERGE(V/2,1);    
//     snake_track[0]=MERGE(V/2,2);    //初始化长度为3
//     snake_len=2;
//     direction_now=EAST;
// }

void Graph::game_gragh()
{
    int i=0;
    char boundary[H+3]={0};
    memset(&boundary[1],'-',H);
    boundary[0]='|';
    boundary[H+1]='|';
    //printf("%s\r\n",boundary);
    mvaddstr(0,0,boundary);
    for(i=1;i<V+1;i++)
    {
        move(i,0);
        addch('|');
    }
    for(i=1;i<V+1;i++)
    {
        move(i,H+1);
        addch('|');
    }
    mvaddstr(V+1,0,boundary);
    show();
}


void Graph::show_snake()
{
    u32 i=0,j=0;
    
    for(i=0;i<snake_len;i++)
    {
        move(GET_V(snake_track[i]),GET_H(snake_track[i]));
        addch('-');
    }
    move(GET_V(food_location),GET_H(food_location));
    addch('*');
    if(0!=delete_node[0])
    {
        move(GET_V(delete_node[0]),GET_H(delete_node[0]));
        addch(' ');
    }

    move(GET_V(head_location),GET_H(head_location));
    addch('>');
    show();
}


void Graph::game_faile_gragh()
{
    
}





#ifdef GRAPH_DEBUG
Graph snake;
int main()
{
    snake.graph_init();
    snake.start_graph();
    snake.game_gragh();
    sleep(10);
    snake.stop_graph();
}

#endif
