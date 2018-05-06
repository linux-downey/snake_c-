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
    cbreak();                    
    noecho();                   
    curs_set(0);                
    keypad(stdscr, true);       
    
}




/**                                 (0,0)         (0,H+1)
 *                      
 * 
 *                                  (V+1,0)       (V+1,H+1)
 * 图像的Y坐标在前，因为curses库中的move定位是以(竖坐标，横坐标)来计算的．
 * */
 
/*
void Graph::game_gragh()
{
    int i=0;
    char boundary[H+3]={0};
    memset(&boundary[1],'-',H);
    boundary[0]='|';
    boundary[H+1]='|';
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
*/
 void Graph::game_gragh()
 {
 	 
	 int i=0;
	 char boundary[H+3]={0};
	 memset(&boundary[1],'+',H);
	 boundary[0]='<';
	 boundary[H+1]='<';
	 mvaddstr(0,0,boundary);
	 for(i=1;i<V+1;i++)
	 {
		 move(i,0);
		 addch('<');
	 }
	 for(i=1;i<V+1;i++)
	 {
		 move(i,H+1);
		 addch('<');
	 }
	 mvaddstr(V+1,0,boundary);
	 show();
 }



 void Graph::show_snake(snake_data_t* snake_data)
 {
     u32 i=0;
    
     for(i=0;i<snake_data->snake_len;i++)
     {
         move(GET_V(snake_data->snake_track[i]),GET_H(snake_data->snake_track[i]));
		 //printf("s%d=(%d,%d)\r\n",i,snake_data->snake_track[i]>>8,(u8)snake_data->snake_track[i]);
         addch('*');
     }
	 
	 if(0!=snake_data->food_location)
	 {
	 	move(GET_V(snake_data->food_location),GET_H(snake_data->food_location));
     	addch('+');
	 }
     
     if(0!=snake_data->delete_node[0])
     {
         move(GET_V(snake_data->delete_node[0]),GET_H(snake_data->delete_node[0]));               //!!!!delete node!!!!
         addch(' ');
     }
	
	 //printf("s=(%d,%d)\r\n",i,GET_V(snake_data->head_location),(u8)GET_V(snake_data->head_location));
     move(GET_V(snake_data->head_location),GET_H(snake_data->head_location));
     addch('*');
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
