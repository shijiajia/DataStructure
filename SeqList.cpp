/*************************************************************************
	> File Name: SeqList.cpp
	> Author: JiaShi
	> Mail: 838357982@qq.com 
	> Created Time: 2015年10月07日 星期三 10时35分42秒
 ************************************************************************/
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class SeqList
{
	private:
		static const int defaultSize=100;
		int maxSize;//允许的最大的容量 
		int last;//当前的最后一个元素的下标
		T *data;//模板类型的顺序存储数组
		void _OverFlowProcess();//溢出处理，每次数据动态曾长defaultSize大小
	public:
		SeqList(int sz=defaultSize);
		SeqList(SeqList<T> &L);
		~SeqList();
		SeqList<T>& operator=(SeqList<T>&L);
		int Length() const;
		int Find(T& x) const;
		int Locate(int i) const;
		bool Insert(int i,T& x);
		bool Remove (T &x);
		bool IsEmpty();
		void Push(T& x);
		bool Getdata(int i,T& x);
		bool Setdata(int i,T& x);
		int Size() const;
};

template<class T>
SeqList<T>::SeqList(int sz)
{
	if (sz>0)
	{
		maxSize=sz;
		last = -1;
		data = new T[maxSize];
		if (!data)
		{
			cerr<<"存储分配错误!"<<endl;
			return;
		}
	}
};

template<class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
	if (this!=&L)
	{
		if (maxSize!=L.Size())
		{
			maxSize=L.Size();
			delete [] data;
			data=new T[maxSize];
			if (!data)
			{
				cerr<<"存储分配错误！"<<endl;
				return ;
			}
		}
		last=L.Length()-1;
		T value;
		for (int i=0;i<=last;i++)
		{
			L.Getdata(i,value);
			data[i]=value;
		}
	}
};

template<class T>
SeqList<T>& SeqList<T>::operator = (SeqList<T> &L)
{
	if (this!=&L)
	{
		if (maxSize!=L.Size())
		{
			maxSize=L.Size();
			delete [] data;
			data=new T[maxSize];
			assert(data!=NULL);
		}
		last=L.Length()-1;
		T value;
		for (int i=0;i<=last;i++)
		{
			L.Getdata(i,value);
			data[i]=value;
		}
	}
	return *this;
};

template<class T>
SeqList<T>::~SeqList()
{
	delete[] data;
};

template<class T>
void SeqList<T>::_OverFlowProcess()
{
	maxSize+=defaultSize;
	T* tdata=new T[maxSize];
	if (!tdata)
	{
		cerr<<"存储分配错误！"<<endl;
		return ;
	}
	for(int i=0;i<=last;i++) tdata[i]=data[i];
	delete[] data;
	data=tdata;
};

template<class T>
int SeqList<T>::Size() const
{
	return maxSize;
};

template<class T>
bool SeqList<T>::Setdata(int i,T& x)
{
	if (i<0||i>last)
	{
		cerr<<"位置不合法"<<endl;
		return false;
	}
	data[i]=x;
	return true;
};

template<class T>
bool SeqList<T>::Getdata(int i,T& x)
{
	if (i<0||i>last)
	{
		cerr<<"位置不合法"<<endl;
		return false;
	}
	x=data[i];
	return true;
};

template<class T>
int SeqList<T>::Length() const
{
	return last+1;
};

template<class T>
void SeqList<T>::Push(T& x)
{
	data[++last]=x;
	if (last==maxSize-1) _OverFlowProcess();
};

template<class T>
int SeqList<T>::Find(T& x) const
{
	for (int i=0;i<=last;i++)
		if (data[i]==x) return i;
	return -1;
};

template<class T>
int SeqList<T>::Locate(int i) const
{
};

template<class T>
bool SeqList<T>::Insert(int i,T& x)
{
	if (i<0||i>last+1)
	{
		cerr<<"位置不合法！"<<endl;
		return false;
	}
	for (int j=last;j>=i;j--)
		data[j+1]=data[j];
	last++;
	data[i]=x;
	if (last==maxSize-1) _OverFlowProcess();
	return true;
};

template<class T>
bool SeqList<T>::Remove(T& x)
{
	int i;
	if(Find(x)==-1) return false;
	while(-1!=(i=Find(x)))
	{
		for (int j=i;j<=last-1;j++)
			data[j]=data[j+1];
		last--;
	}
	return true;
};

template<class T>
bool SeqList<T>::IsEmpty()
{
	return last==-1;
};
