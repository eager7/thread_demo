/****************************************************************************
 *
 * MODULE:             ThreadInfo
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

namespace mThread
{
    void ThreadInfo::_init() {
        this->thread_id = 0;
        this->name = "Null_";
        this->pthread_data = NULL;
        this->detach = E_THREAD_JOINABLE;
        this->state = E_THREAD_STOPPED;
    }

    ThreadInfo::ThreadInfo() {
        this->_init();
    }

    ThreadInfo::ThreadInfo(string name, void *pthread_data, detach_t detach) {
        this->_init();
        this->name = name;
        this->pthread_data = pthread_data;
        this->detach = detach;
    }
}