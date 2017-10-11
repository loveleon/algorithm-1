#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex; // 互斥量
pthread_cond_t  cond; // 条件变量

void* child1( void* param )
{
  pthread_cleanup_push( (void (*)(void*))pthread_mutex_unlock, (void*)&mutex );
  while( 1 )
  {
    printf( "thread 1 get running\n" );
    printf( "thread 1 pthread_mutex_lock returns %d\n", pthread_mutex_lock( &mutex ));
    pthread_cond_wait( &cond, &mutex ); // 无条件等待
    printf( "thread 1 condition applied\n" );
    pthread_mutex_unlock( &mutex );

    sleep( 5 );
  }
  pthread_cleanup_pop( 0 );

  return ( void* )0;
}

void* child2( void* param )
{
  while( 1 )
  {
    sleep( 3 );
    printf( "thread 2 get running\n" );
    printf( "thread 2 pthread_mutex_lock returns %d\n", pthread_mutex_lock( &mutex ) );
    pthread_cond_wait( &cond, &mutex ); // 无条件等待
    printf( "thread 2 condition applied\n" );
    pthread_mutex_unlock( &mutex );

    sleep( 1 );
  }

  return ( void* )0;
}

int main()
{
  pthread_t tid1, tid2;
  printf( "hello, condition variable test\n" );

  pthread_mutex_init( &mutex, NULL ); // 初始化 互斥锁
  pthread_cond_init( &cond, NULL ); // 初始化 条件变量

  pthread_create( &tid1, NULL, child1, NULL ); // new 线程 tid1
  pthread_create( &tid2, NULL, child2, NULL ); // new 线程 tid2

  do
  {
    sleep( 2 );
    pthread_cancel( tid1 ); // 发送终止信号给 tid1,具体请google取消点 cancel point
    sleep( 2 );
    pthread_cond_signal( &cond ); // 激活一个等待该条件的线程
  }while( 1 );

  sleep( 100 );
  pthread_exit( 0 );

  return 0;
}




