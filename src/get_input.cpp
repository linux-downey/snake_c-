#include "get_input.h"
#include <unistd.h>
#include <curses.h>


userInput Input;


userInput::userInput()
{
    Q_BUF_MAX_LEN=3;
    Q=new QUEUE;
    Q->q_buf=new s8[Q_BUF_MAX_LEN];
    memset(Q->q_buf,0,Q_BUF_MAX_LEN);
}

userInput::~userInput()
{
    delete []Q->q_buf;
    delete Q;
}


/**************************queue operation**************************************/
void userInput::initQueue()
{
    
}

s8 userInput::q_push(s8 data)
{

    if(Q==NULL) return 0;
    if(Q->q_len>=Q_BUF_MAX_LEN)
    {
        return -1;
    }
    Q->q_buf[Q->q_len]=data;

    Q->q_len+=1;
    return 1;
}

s8 userInput::q_pop()         //取出一个数据
{
    s8 data=0;
    s8 temp[Q_BUF_MAX_LEN]={0};
    if(Q==NULL) return 0;
    if(Q->q_len==0)
    {
        return -1;
    } 
    data=Q->q_buf[0];
    memcpy(temp,Q->q_buf,sizeof(temp)); 
    memcpy(Q->q_buf,&temp[1],sizeof(temp)-1);   //将后面的节点依次往前放
    Q->q_len-=1;
    return data;
}

u32 userInput::get_q_len()  //获取长度
{
    if(Q==NULL) return 0;
    return Q->q_len;
}

/*******************************queue end*****************************************/

s8 userInput::getUserInput()
{
    return q_pop();
}

u8 userInput::saveUserInput(s8 c)
{
    return q_push(c);
}

void* userInput::getInputCallback(void *arg)
{
    userInput* input=(userInput*)arg;
    s8 ch=0;
    while(1)
    {
        if(ch=getch())
        {
            input->saveUserInput(ch);
        }
    }
    return NULL;
}


void userInput::getInputInit()
{
    if(pthread_create(&get_user_input_thread, NULL,
                          userInput::getInputCallback, this))
    {
        cout<<"create thread failed!!"<<endl;
    }
}



#ifdef INPUT_DEBUG
int main()                       //已经测试过
{
    s8 ch=0;
    initscr();
    Input.getInputInit();
    while(1)
    {
        ch=Input.getUserInput();
        if(ch!=-1)
        {
            cout<<ch+1<<endl;
        }
        sleep(1);
    }
}

#endif
