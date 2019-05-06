#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *PthreadFunc(void* arg)
{
	pthread_detach(pthread_self());
	sleep(2);
	return "SSS";
}

int main()
{
	pthread_t tid;
	int val = pthread_create(&tid, NULL, PthreadFunc, NULL);
	if(val != 0)
	{
		printf("pthread create error\n");
		return -1;
	}
	// 线程分离
	// int pthread_detach(pthread_t thread);
	// 被分离的线程退出后，自动回收资源。
	//pthread_detach(tid);

	//int pthread_join(pthread_t thread, void **retval);
	//  阻塞等待线程退出
	//  thread: 等待的线程ID
	//  retval：用户获取线程退出的返回值
    //char* retval;
	sleep(1);
	void* retval;
	val = pthread_join(tid, &retval);
	if(val == EINVAL)
	{
		printf("thread is not a joinable thread\n");
	}
	printf("retval:%s\n", retval);
	while(1)
	{
		sleep(1);
		printf("join~~~~\n");
	}
	return 0;
}
