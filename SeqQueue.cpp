/*************************************************************************
	> File Name: SeqQueue.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年10月24日 星期六 09时00分08秒
 ************************************************************************/
#include<assert.h>
#include<iostream>
using namespace std;
template<class T>
class SeqQueue
{
private:
	static const int defaultSize=50;
	int front,rear;
	int maxSize;
	T* data;
	void _OverFlowProcess();
public:
	SeqQueue(int sz=defaultSize);
	SeqQueue(SeqQueue<T>& q);
	SeqQueue<T>& operator=(SeqQueue<T>& q);
	void EnQueue(const T& x);
	bool DeQueue();
	T& GetFrontData();
	bool IsEmpty();
	void MakeEmpty();
	int GetSize();
	inline int GetMaxSize()
	{
		return maxSize;
	}
	inline int GetFront()
	{
		return front;
	}
	inline int GetRear()
	{
		return rear;
	}
	inline T GetIndex(int i)
	{
		return data[i];
	}
	friend ostream& operator<<(ostream& os ,SeqQueue<T>& q)
	{
		for (int i=q.GetFront();i!=q.GetRear();i=(i+1)%q.GetMaxSize())
			os<<q.GetIndex(i)<<" ";
		return os;
	}
	~SeqQueue();
};

template<class T>
SeqQueue<T>::SeqQueue(int sz)
{
	maxSize=sz>0?sz:defaultSize;
	front=rear=0;
	data= new T[maxSize];
	assert(data!=NULL);
}

template<class T>
SeqQueue<T>::SeqQueue(SeqQueue<T>& q)
{
	if (this!=&q)
	{
		maxSize=q.GetMaxSize();
		data = new T[maxSize];
		assert(data!=NULL);
		for (int i=0;i<maxSize;i++)
			data[i]=q.GetIndex(i);
		rear=q.GetRear();
		front=q.GetFront();
	}
}

template<class T>
SeqQueue<T>& SeqQueue<T>::operator=(SeqQueue<T>& q)
{
	if (this!=&q)
	{
		if (maxSize==q.GetMaxSize())
		{
			rear=q.GetRear();
			front=q.GetFront();
			for (int i=0;i<maxSize;i++)
				data[i]=q.GetIndex(i);
		}else{
			maxSize=q.GetMaxSize();
			delete[] data;
			data= new T[maxSize];
			assert(data!=NULL);
			for (int i=0;i<maxSize;i++)
				data[i]=q.GetIndex(i);
			front=q.GetFront();
			rear=q.GetRear();
		}

	}
	return *this;
}
template<class T>
void SeqQueue<T>::_OverFlowProcess()
{
	maxSize=maxSize+defaultSize;
	T* newdata=new T[maxSize];
	assert(newdata!=NULL);
	int index=0;
	for (int i=front;i!=rear;i=(i+1)%maxSize)
	{
		newdata[index]=data[i];
		index++;
	}
	rear=index;
	front=0;
	delete[] data;
	data=newdata;
}
template<class T>
void SeqQueue<T>::EnQueue(const T& x)
{
	if ((rear+1)%maxSize==front) 
		_OverFlowProcess();
	data[rear]=x;
	rear=(rear+1)%maxSize;
}
template<class T>
bool SeqQueue<T>::DeQueue()
{
	if (rear==front)
	{
		cout<<"空队列"<<endl;
		return false;
	}else
	{
		front=(front+1)%maxSize;
		return true;
	}
}

template<class T>
T& SeqQueue<T>::GetFrontData()
{
	if (rear==front)
	{
		T rubbish;
		cout<<"空队列"<<endl;
		return  rubbish;
	}else
		return data[front];
}

template<class T>
bool SeqQueue<T>::IsEmpty()
{
	return rear==front?true:false;
}

template<class T>
void SeqQueue<T>::MakeEmpty()
{
	rear=front=0;
}

template<class T>
int SeqQueue<T>::GetSize()
{
	return ((rear-front)+maxSize)%maxSize;
}

template<class T>
SeqQueue<T>::~SeqQueue()
{
	delete[] data;
}













