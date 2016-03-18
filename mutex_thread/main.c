#include "mthread.h"

pthread_mutex_t psLock;
int x = 1;
int y = 0;

static void * Producter1(void *psThreadInfoVoid)
{
	while(1)
	{
		mLockLock(&psLock);
		x++;
		DBG_vPrintf(1, "Producter1:%d\n", x);
		mLockUnlock(&psLock);
		//usleep(100);
	}
	return NULL;
}

static void * Producter2(void *psThreadInfoVoid)
{
	while(1)
	{
		mLockLock(&psLock);
		x--;
		INF_vPrintf(1, "Producter2:%d\n", x);
		mLockUnlock(&psLock);
		//usleep(100);
	}
	return NULL;
}

int main()
{
	printf("mutex thread test...\n");
	
	mLockCreate(&psLock, E_NUM_PTHREAD_MUTEX_RECURSIVE);
	tsThread sThread1;
	tsThread sThread2;

	mThreadStart(Producter1, &sThread1, E_THREAD_JOINABLE);
	mThreadStart(Producter2, &sThread2, E_THREAD_JOINABLE);
	sleep(1);
	return 0;
}
