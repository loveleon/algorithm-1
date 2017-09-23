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

//��ʼ����̬��Ա����
int Base::count = 0;
//��̬����
int Base::instanceCount()
{
	cout<<"Base::instanceCount()\tcount��ַ�� " << &count << endl;
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
	cout<< "ʵ��iBase��ַ��" << &iBase << endl;
	return iBase;
}

void Base::print(void) const
{
	cout<<"Base::print()�� iBase " << iBase << endl;
}

int main()
{
    Base b1(1000);
    cout << "����b1����ʼ�ڴ��ַ��" << &b1 << endl;
    cout << "type_info��Ϣ��" << ((int*)*(int*)(&b1) - 1) << endl;
    RTTICompleteObjectLocator str=
        *((RTTICompleteObjectLocator*) ((int*)*(int*)(&b1) - 1));
    //abstract class name from RTTI
    string classname(str.pTypeDescriptor->name);
    classname = classname.substr(4,classname.find("@@")-4);
    cout << classname <<endl;
    cout << "�麯�����ַ��\t\t\t" << (int*)(&b1) << endl;
    cout << "�麯���� �� ��1��������ַ��\t" << (int*)*(int*)(&b1) << "\t������������ַ��" << (int*)*((int*)*(int*)(&b1)) << endl;
    cout << "�麯���� �� ��2��������ַ��\t" << ((int*)*(int*)(&b1) + 1) << "\t";
    typedef void(*Fun)(void *); //bug fix
    Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);
    pFun();
    b1.print();
    cout << endl;
    cout << "�Ʋ����ݳ�ԱiBase��ַ��\t\t" << ((int*)(&b1) +1) << "\tͨ����ַȡֵiBase��ֵ��" << *((int*)(&b1) +1) << endl;
    cout << "Base::getIBase(): " << b1.getIBase() << endl;
 
    b1.instanceCount();
    cout << "��̬����instanceCount��ַ�� " << b1.instanceCount << endl;

    return 0;
}
