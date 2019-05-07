/**************************************************************************************************************************************
 * posix标准信号量的使用
 * 使用信号量实现一个线程安全的队列
 * **********************************************************************************************************************************/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
using namespace std;
#include<semaphore.h>

class RingQueue
{
	public:
		RingQueue(int cap = 10)
			:capacity(cap)
		{
			ProductorStep = 0;
			CustomerStep = 0;
			pthread_mutex_init(&mutex, NULL);
			// int sem_init(sem_t *sem, int pshared, unsigned int value);
			// 信号量的初始化
			// sem: 信号量
			// pshared： 
			//       0    用于线程间同步与互斥
			//       !0   用于进程间同步与互斥
			// value:   信号量的计数初值
			sem_init(&IdleSpace, 0, capacity);
			sem_init(&DataSpace, 0, 0);
		}
		~RingQueue()
		{
			pthread_mutex_destroy(&mutex);
			// int sem_destroy(sem_t *sem);
			// 销毁信号量
			sem_destroy(&IdleSpace);
			sem_destroy(&DataSpace);
		}
		void QueuePush(int data)
		{
		}
		void QueuePop(int* data)
		{
		}
	private:
		void QueueLock()
		{
			pthread_mutex_lock(&mutex, NULL);
		}
		void QueueUnlock()
		{
			pthread_mutex_unlock(&mutex);
		}
		void CustomerWait()
		{
			//int sem_wait(sem_t *sem);
			//计数判断，若<=0;则阻塞等待
			//int sem_trywait(sem_t *sem);
			//计数判断，若<=0;则报错返回
			//int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
			//计数判断,若<=0;则现时等待
			sem_wait(&DataSpace);
		}
		void CustomerSignal()
		{
			// int sem_post(sem_t *sem);
			// 唤醒sem信号量等待队列上的线程
			sem_post(&DataSpace);
		}
		void ProductorWait()
		{
			sem_wait(&IdleSpace);
		}
		void ProductorSignal()
		{
			sem_post(&IdleSpace);
		}
	private:
		vector<int> q;
		int capacity;
		int CustomerStep;
		int ProductorStep;
		pthread_mutex_t mutex;
		sem_t IdleSpace; //空闲空间
		sem_t DataSpace; //数据个数
};
