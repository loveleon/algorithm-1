#include<stdio.h>

int main()
{
  char *p = "hello";
  char a = 'a';
  char *p1 = &a;
  char c[1] = {'a'};

 
  printf("the pointer is %llx.\n", p);
  printf("the pointer is %llx.\n", p1);

  printf("the pointer is %llx.\n", c);
  printf("the pointer is %d.\n", c[0]);

  return 0;
}
