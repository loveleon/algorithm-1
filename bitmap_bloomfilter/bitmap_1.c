// not to test

#include <iostream>
#include <fstream>
using namespace std;

#define BIT_INT 32   // 1个unsigned int可以标志32个坑
#define SHIFT 5
#define MASK 0x1f
#define N 4294967296 // 2^32

unsigned int *a = NULL;

// heap
void createArr()
{
	a = new unsigned int[1 + N / BIT_INT];
}

void deleteArr()
{
  delete []a;
  a = NULL;
}

// init 0
void setAllZero()
{
	memset(a, 0, (1 + N / BIT_INT) * sizeof(unsigned int));
}

// i = 1
void setOne(unsigned int i)
{
	a[i >> SHIFT] |= (1 << (i & MASK));
}

// 设置第i位为1
void setZero(unsigned int i)
{
	a[i >> SHIFT] &= ~(1 << (i & MASK));
}

// get index=i
int getState(unsigned int i)
{
	return (a[i >> SHIFT] & (1 << (i & MASK))) && 1;
}

// bit
void setStateFromFile()
{
	ifstream cin("a.txt");
  unsigned int n;
  while(cin >> n)  
  {
    setOne(n);
  }  
}

//
void printCommonNumber()
{
  ifstream cin("b.txt");
  unsigned int n;
  while(cin >> n)  
  {
    if(1 == getState(n))
  	{
  		cout << n << " ";
  	}
  }  

  cout << endl;
}

int main() 
{
	createArr();
	setAllZero();

	// a.txt: 4 5 7 2 9 2 4 8 0 11   (in a.txt 40 * 1 0000 0000)
	// b.txt: 6 11 0 2 3   (b.txt 10000)

	setStateFromFile();
	printCommonNumber(); // 11 0 2
	deleteArr();

	return 0;
}
