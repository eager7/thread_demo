/****************************************************************************
 *
 * MODULE:             CommonThread
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


#include "mThread.hpp"


using namespace std;

namespace mThread
{
    CommonThread::CommonThread() { }

    CommonThread::CommonThread(thread_loop func, string name, void *pthread_data, detach_t detach) {
        this->_create = T_FALSE;
        this->func = func;
        this->thread_info = ThreadInfo(name, pthread_data, detach);
    }

    void CommonThread::create(detach_t detach, void *info) {
        if(!this->_create){
            if(pthread_create(&this->thread_info.thread_id, NULL, this->func, info) != 0) {
                throw ThreadException("[create] create thread failed");
            }
            if (detach == E_THREAD_DETACHED)
            {
                cout << "Detached Thread:" << this->thread_info.name << endl;
                if (pthread_detach(this->thread_info.thread_id))
                {
                    throw ThreadException("[detach] can't create detached thread");
                }
            }
            this->_create = T_TRUE;
        }
    }

    void CommonThread::start() {
        this->create(E_THREAD_JOINABLE, this->thread_info.pthread_data);
        this->thread_info.state = E_THREAD_RUNNING;
    }
}
