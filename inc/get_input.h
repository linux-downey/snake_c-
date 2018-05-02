#ifndef _GET_INPUT_H
#define _GET_INPUT_H

#include "common.h"

//#define INPUT_DEBUG

class userInput
{
    typedef struct
    {
        s8 *q_buf;
        u32 q_len;
    }QUEUE;
    static void* getInputCallback(void *arg);
    public:
        userInput();
        ~userInput();
        void getInputInit();
        s8 getUserInput();
        s32 error_code;
    private:
        QUEUE *Q;
        pthread_t get_user_input_thread;
        u8 saveUserInput(s8 c);
        
        void initQueue();
        s8 q_push(s8 data);
        s8 q_pop();
        u32 get_q_len();
        u32 Q_BUF_MAX_LEN;
};

#endif
