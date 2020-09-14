#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout << "Create Test Obj:" << this << endl;
	}
	~Test()
	{
		cout << "Free Test Obj:" << this << endl;
	}
public:
	void* operator new(size_t sz)//申请空间
	{
		void *ptr = malloc(sz);
		assert(ptr != nullptr);
		return ptr;
	}

	void operator delete(void *ptr)//释放空间
	{
		if (ptr != nullptr)
			free(ptr);
	}

	void* operator new[](size_t sz)
	{
		void *ptr = malloc(sz);
		assert(ptr != nullptr);
		return ptr;
	}

	void operator delete[](void *ptr)
	{
		if (ptr != nullptr)
			free(ptr);
	}
private:
	int m_data;
};
int main()
{
	Test *pt = new Test; //new 操作符  1申请空间  2构造对象
	Test *pt1 = (Test*)::operator new(sizeof(Test));  //malloc 申请空间
	Test *pt2 = new Test[10];	
	Test *pt3 = new Test;
	delete pt;//1.析构对象  2.释放空间
	delete pt1;
	delete []pt2;
	operator delete(pt3);//delete 释放空间
}