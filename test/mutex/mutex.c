//  gcc -g mutex.c  -lpthread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t t1;           //pthread_t����t1�����ڻ�ȡ�߳�1��ID
pthread_t t2;           //pthread_t����t2�����ڻ�ȡ�߳�2��ID
char Share[10];         //������Դ��
pthread_mutex_t work_mutex; //����������work_mutex

void* My_thread_1(void* args)
{
  while(1)
  {
    char *p=Share;
    pthread_mutex_lock(&work_mutex);      //����
    int i = 0;
    for(i = 0; i < 9; i++)
    {
      *p = 'a';             //�߳�1��Shareд��aaaaaaaa
      sleep(1);
      p++;
    }
    
    p++;
    *p = '\0';
    printf("1 Share is : %s\n",Share);
    pthread_mutex_unlock(&work_mutex);   //����
    sleep(1);            //���û�����ʱҲȥ��ע�ͣ�Ϊ���̵����ṩʱ��
  }

  return NULL;
}

void* My_thread_2(void* args)
{
  while(1)
  {
    char *p=Share;
    pthread_mutex_lock(&work_mutex);     //����
    int i = 0;
    for(i = 0; i < 9; i++)
    {
      *p = 'e';             //�߳�1��Shareд��eeeeeeee
      sleep(1);
      p++;
    }
    p++;
    *p = '\0';
    printf("2 Share is : %s\n",Share);
    pthread_mutex_unlock(&work_mutex);   //����
    sleep(1);            //���û�����ʱҲȥ��ע�ͣ�Ϊ���̵����ṩʱ��
  }

  return NULL;
}

int main()
{
	pthread_mutex_init(&work_mutex, NULL);   //��ʼ��������
  pthread_create(&t1,NULL,My_thread_1,NULL);
  pthread_create(&t2,NULL,My_thread_2,NULL);
  sleep(1000);
  pthread_mutex_destroy(&work_mutex);      //���ٻ�����
  return 0;
}
