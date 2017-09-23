//from vs c++  https://github.com/tylerzhu/CppObjectModel.git
//to gnu linux some change to do
//


//#pragma once
#include<iostream>
#include<string>
#include"type_info.h"
using namespace std;

class Base
{
public:
  Base(int);
  virtual ~Base(void);

  int getIBase() const;
  static int instanceCount();
  virtual void print() const;

protected:

  int iBase;
  static int count;
};

//初始化静态成员数据
int Base::count = 0;
//静态方法
int Base::instanceCount()
{
	cout<<"Base::instanceCount()\tcount地址： " << &count << endl;
	return count;
}

Base::Base(int i)
{
	iBase = i;
	count++;
	cout<<"Base::Base()"<<endl;
}


Base::~Base(void)
{
	cout<<"Base::~Base()" <<endl;
}

int Base::getIBase() const
{
	cout<< "实际iBase地址：" << &iBase << endl;
	return iBase;
}

void Base::print(void) const
{
	cout<<"Base::print()， iBase " << iBase << endl;
}

int main()
{
    Base b1(1000);
    cout << "对象b1的起始内存地址：" << &b1 << endl;
    cout << "type_info信息：" << ((int*)*(int*)(&b1) - 1) << endl;
    RTTICompleteObjectLocator str=
        *((RTTICompleteObjectLocator*) ((int*)*(int*)(&b1) - 1));
    //abstract class name from RTTI
    string classname(str.pTypeDescriptor->name);
    classname = classname.substr(4,classname.find("@@")-4);
    cout << classname <<endl;
    cout << "虚函数表地址：\t\t\t" << (int*)(&b1) << endl;
    cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&b1) << "\t即析构函数地址：" << (int*)*((int*)*(int*)(&b1)) << endl;
    cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&b1) + 1) << "\t";
    typedef void(*Fun)(void *); //bug fix
    Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);
    pFun();
    b1.print();
    cout << endl;
    cout << "推测数据成员iBase地址：\t\t" << ((int*)(&b1) +1) << "\t通过地址取值iBase的值：" << *((int*)(&b1) +1) << endl;
    cout << "Base::getIBase(): " << b1.getIBase() << endl;
 
    b1.instanceCount();
    cout << "静态函数instanceCount地址： " << b1.instanceCount << endl;

    return 0;
}
