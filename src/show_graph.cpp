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

#include <string.h>
#include "show_graph.h"



void Graph::clean_gragh()
{
    int i=1,j=1;
	char str[H+1]={0};
	memset(str,' ',H);
	
    for(;i<V+1;i++)
    {
        show_string(i,1,str);
    }
	
	//show();
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
 * 
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
	 show_string(0,0,boundary);
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
	 show_string(V+1,0,boundary);
	 //show();
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



void Graph::show_string(s32 y,s32 x,const char* str)
 {
 	mvaddstr(y,x,str);
 }


void Graph::select_gragh()
{
	const char* str="Please select level,1-9";
	show_string(V/2,H/2-strlen(str)/2,str);
	show();
}


 void Graph::reselect()
{
	const char *str_restart="Enter 1 for restart!";	
	const char *str_quit="Enter 2 for quit!!";
	show_string(V/2+1,H/2-strlen(str_restart)/2,str_restart);
	show_string(V/2+2,H/2-strlen(str_restart)/2,str_quit);       //keep alignment
}

 void Graph::game_over_hit_wall()
 {
	 const char* str="HIT THE WALL!!!!!";
	 show_string(V/2-2,H/2-strlen(str)/2,str);
	 reselect();
 }


void Graph::game_over_eat_self()
{
     const char* str="EAT SELF!!!!!";
	 mvaddstr(V/2-2,H/2-strlen(str)/2,str);
	 reselect();
}

void Graph::game_over_congratulations()
{
    const char* str="NIUBI NIUBI NIUBI !!!!!";
	show_string(V/2-2,H/2-strlen(str)/2,str);
	reselect();
}




void Graph::show_game_over_gragh(s32 reason)
{
	switch(reason)
	{
		case EAT_SELF:
			game_over_eat_self();
		break;
		case HIT_WALL:
			game_over_hit_wall();
		break;
		case CONGRAT:
			game_over_congratulations();
		break;
		default:
		break;
	}
	show();
}





