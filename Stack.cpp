/*************************************************************************
	> File Name: Stack.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年10月17日 星期六 08时24分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
template<class T>
class Stack
{
private:
	static const int defaultSize=100;
	T* data;
	int top;
	int maxSize;
	void _OverFlowProcess();
public:
	Stack(int sz=defaultSize);
	Stack(const Stack<T>& S);
	Stack<T>& operator=(const Stack<T>& S);
	void Push(const T& x);
	bool Pop();
	T& Top();
	bool IsEmpty();
	void MakeEmpty();
	int GetSize();
	~Stack();
};

template<class T>
Stack<T>::Stack(int sz):top(-1),maxSize(sz>0?sz:defaultSize)
{
	data= new T[sz];
	if (data==NULL) 
	{
		cerr<<"内存分配失败"<<endl;
		return ;
	}
}

template<class T>
Stack<T>::Stack(const Stack<T>& S)
{
	if (this!=&S)
	{
		top=S.top;
		maxSize=S.maxSize;
		data=new T[maxSize];
		if (data==NULL)
		{
			cerr<<"内存分配失败"<<endl;
			return ;
		}
		for (int i=0;i<=top;i++) data[i]=S.data[i];
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& S)
{
	if (this != &S)
	{
		if (maxSize==S.maxSize)
		{
			top=S.top;
			for (int i=0;i<=top;i++)
				data[i]=S.data[i];
		}else
		{
			delete data;
			top = S.top;
			maxSize=S.maxSize;
			data = new T[maxSize];
			for(int i=0;i<=top;i++)
				data[i]=S.data[i];
		}
	}
	return *this;
}

template<class T>
void Stack<T>::_OverFlowProcess()
{
	maxSize+=defaultSize;
	T* newdata= new T[maxSize];
	if (newdata==NULL)
	{
		cerr<<"内存分配错误"<<endl;
		return ;
	}
	for(int i=0;i<=top;i++)
		newdata[i]=data[i];
	delete[] data;
	data = newdata;
}
template<class T>
void Stack<T>::Push(const T& x)
{
	if (top==maxSize-1) _OverFlowProcess();
	data[++top] = x;
}

template<class T>
bool Stack<T>::Pop()
{
	if (top==-1)
	{
		cerr<<"空栈无法弹出栈元素"<<endl;
		return false;
	}
	top--;
	return true;
}

template<class T>
T& Stack<T>::Top()
{
	if (top==-1)
	{
		T rubbish;
		cerr<<"空栈无法弹出栈元素"<<endl;
		return rubbish;
	}
	return data[top];
}

template<class T>
int Stack<T>::GetSize()
{
	return top+1;
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return top==-1?1:0;
}

template<class T>
void Stack<T>::MakeEmpty()
{
	top=-1;
}
template<class T>
Stack<T>::~Stack()
{
	delete[] data;
}
