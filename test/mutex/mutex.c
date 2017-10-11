//  gcc -g mutex.c  -lpthread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t t1;           //pthread_t变量t1，用于获取线程1的ID
pthread_t t2;           //pthread_t变量t2，用于获取线程2的ID
char Share[10];         //共享资源区
pthread_mutex_t work_mutex; //声明互斥量work_mutex

void* My_thread_1(void* args)
{
  while(1)
  {
    char *p=Share;
    pthread_mutex_lock(&work_mutex);      //加锁
    int i = 0;
    for(i = 0; i < 9; i++)
    {
      *p = 'a';             //线程1将Share写成aaaaaaaa
      sleep(1);
      p++;
    }
    
    p++;
    *p = '\0';
    printf("1 Share is : %s\n",Share);
    pthread_mutex_unlock(&work_mutex);   //解锁
    sleep(1);            //启用互斥量时也去除注释，为进程调度提供时间
  }

  return NULL;
}

void* My_thread_2(void* args)
{
  while(1)
  {
    char *p=Share;
    pthread_mutex_lock(&work_mutex);     //加锁
    int i = 0;
    for(i = 0; i < 9; i++)
    {
      *p = 'e';             //线程1将Share写成eeeeeeee
      sleep(1);
      p++;
    }
    p++;
    *p = '\0';
    printf("2 Share is : %s\n",Share);
    pthread_mutex_unlock(&work_mutex);   //解锁
    sleep(1);            //启用互斥量时也去除注释，为进程调度提供时间
  }

  return NULL;
}

int main()
{
	pthread_mutex_init(&work_mutex, NULL);   //初始化互斥量
  pthread_create(&t1,NULL,My_thread_1,NULL);
  pthread_create(&t2,NULL,My_thread_2,NULL);
  sleep(1000);
  pthread_mutex_destroy(&work_mutex);      //销毁互斥量
  return 0;
}
