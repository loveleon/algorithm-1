#include <iostream>
#include <string.h>
using namespace std;

#define BITMAP_LEN 100 //bitmap的大小，即bit位的个数
char *g_bitmap = NULL;    
int g_size = 0;
int g_base = 0;

//功能：初始化bitmap   
//参数： size：bitmap的大小，即bit位的个数   
//      start：起始值   
//返回值：0表示失败，1表示成功   
int bitmap_init(int size, int start)    
{
  g_size = size/8 + 1;
  g_base = start;
  g_bitmap = new char[g_size];
  if (g_bitmap == NULL)
  {
    return 0;
  }
  memset(g_bitmap, 0x0, g_size);
  return 1;
}

//功能：将值index的对应位设为1   
//index:要设的值   
//返回值：0表示失败，1表示成功   
int bitmap_set(int index)    
{
  int quo = (index-g_base)/8 ;  //确定所在的字节  
  int remainder = (index-g_base)%8;  //字节内的偏移    
  unsigned char x = (0x1 << remainder);
  if( quo > g_size)
    return 0;
  g_bitmap[quo] |= x;   //所在字节内的特定位置为1    
  return 1;
}    

//功能：取bitmap第i位的值   
//i：待取位   
//返回值：-1表示失败，否则返回对应位的值   
int bitmap_get(int i)
{
  int quo = (i)/8 ;
  int remainder = (i)%8;
  unsigned char x = (0x1 << remainder);
  unsigned char res;
  if( quo > g_size)
    return -1;
  
  res = g_bitmap[quo] & x;
  return res > 0 ? 1 : 0;
}

//功能：返回index位对应的值     
int bitmap_data(int index)
{
  return (index + g_base);
}

//释放内存   
int bitmap_free()
{    
  delete [] g_bitmap;  
  return 0;  
}

int main()
{    
  int a[] = {5,8,7,6,3,1,10,78,56,34,23,12,43,54,65,76,87,98,89,100};
  int i;
  bitmap_init(BITMAP_LEN, 0);

  int len = (sizeof(a) / sizeof(int));
  for (i = 0; i < len; i++)
  {
    bitmap_set(a[i]);  
  }

  for (i = 0; i <= BITMAP_LEN; i++)
  {
    if(bitmap_get(i) > 0 )  
      cout << bitmap_data(i)<< " ";  
  }

  cout << endl;

  bitmap_free();

  return 0;
} 