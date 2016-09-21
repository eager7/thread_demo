/****************************************************************************
 *
 * MODULE:             mThread
 *
 * COMPONENT:          steerMotor define
 *
 * REVISION:           $Revision:  0.1$
 *
 * DATED:              $Date: 2016-09-06 15:13:17
 *
 * AUTHOR:             PCT
 *
 ****************************************************************************
 *
 * Copyright changtao.pan@kuang-chi.com B.V. 2016. All rights reserved
 *
 ***************************************************************************/

#ifndef THREAD_CPP_MTHREAD_H
#define THREAD_CPP_MTHREAD_H

#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>
#include <fstream>

#include <pthread.h>
#include <unistd.h>

using namespace std;

namespace mThread
{
    typedef enum{
        T_TRUE = 0x01,
        T_FALSE = 0x00,
    }bool_t;

    typedef enum {
        E_THREAD_JOINABLE,      /**< Thread is created so that it can be waited on and joined */
        E_THREAD_DETACHED,      /**< Thread is created detached so all resources are automatically free'd at exit. */
    } detach_t;

    typedef enum {
        E_THREAD_STOPPED = 0x00,   /**< Thread stopped */
        E_THREAD_RUNNING = 0x01,   /**< Thread running */
        E_THREAD_STOPPING = 0x02,  /**< Thread signaled to stop */
    } state_t;

    typedef void *(*thread_loop)(void *info);

    class ThreadException : public exception
    {
    private:
        string _error;
    public:
        ThreadException(const string &error_str);
        ~ThreadException() throw();

        virtual const char *what() const throw();
        friend ostream &operator << (ostream &out, ThreadException &e);
    };

    struct ThreadInfo
    {
    private:
        void _init();

    public:
        pthread_t thread_id;
        string name;
        void *pthread_data;
        detach_t detach;
        state_t state;

    public:
        ThreadInfo();
        ThreadInfo(string name, void *pthread_data, detach_t detach);


    };

    class CommonThread
    {
    public:
        CommonThread();
        CommonThread(thread_loop func, string name = "None", void *pthread_data = NULL, detach_t detach = E_THREAD_JOINABLE);

        void create(detach_t detach, void *info);
        void start(void);

    protected:
        bool_t _create;

    public:
        thread_loop func;
        ThreadInfo thread_info;
    };
}


#endif //THREAD_CPP_MTHREAD_H
