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


#ifndef _GET_INPUT_H
#define _GET_INPUT_H

#include "common.h"

#define Q_BUF_MAX_LEN 3



class userInput
{
    typedef struct
    {
        s8 *q_buf;
        u32 q_len;
    }QUEUE;
    static void* getInputCallback(void *arg);
    public:
        userInput(char speed=1);
        ~userInput();
        void getInputInit();
        s8 getUserInput();
        s32 error_code;
		void select_speed();
    private:
        QUEUE *Q;
        pthread_t get_user_input_thread;
        u8 saveUserInput(s8 c);
        
        void initQueue();
        s8 q_push(s8 data);
        s8 q_pop();
        u32 get_q_len();
        u32 wait_us;                         //执行时的等待，每移动一次的间隔时间
        u32 wait_us_default;                //默认的间隔时间
        const u32 speed_up_wait_us=100;     //加速时的间隔时间
};

#endif
