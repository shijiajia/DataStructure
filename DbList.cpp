/*************************************************************************
	> File Name: DbList.cpp
	> Author: JiaShi
	> Mail: 838357982@qq.com 
	> Created Time: 2015年10月11日 星期日 08时42分28秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct DbLNode
{
	T data;
	struct DbLNode *lLink, *rLink;
	DbLNode():lLink(0),rLink(0){};
	DbLNode(T value):data(value),lLink(0),rLink(0){};
};
template<class T>
class DbList
{
private:
	DbLNode<T> *head,*current;
public:
	DbList();
	DbList(T val);
	DbList(const vector<T>& L);
	DbList(DbList<T>& L);
	DbList<T>& operator=(DbList<T>& L);
	void InsertL(const T& val);//当前节点右边插入一个节点
	void InsertR(const T& val);//当前节点左边插入一个节点
	bool Find(const T& val);//查找一个特定值的节点并是cuurent指向此节点
	int Length();//返回链表的长度
	bool IsEmpty();//判断链表是否为空
	bool Next();//currten指向后驱
	bool Prior();//currten指向前继
	bool MakeEmpty();//链表清空
	void Fister();//current指向head
	bool GetData(T& val);
	void Remove();
	~DbList();
};
template<class T>
DbList<T>::DbList()
{
	head=current=new DbLNode<T>();
}

template<class T>
DbList<T>::DbList(T val)
{
	head=current=new DbLNode<T>(val);
}

template<class T>
DbList<T>::DbList(const vector<T>& L)
{
	head=current= new DbLNode<T>();
	for (int i=0;i<L.size();i++) 
	{
		InsertR(L[i]);
		Next();
	}
}

template<class T>
DbList<T>::DbList(DbList<T>& L)
{
	if (this!=&L)
	{
		T tmp;
		MakeEmpty();
		L.Fister();
		while(L.Next())
		{
			L.GetData(tmp);
			InsertR(tmp);
			Next();
		}
	}
}

template<class T>
DbList<T>& DbList<T>::operator=(DbList<T> &L)
{
	if (this!=&L)
	{
		T tmp;
		MakeEmpty();
		L.Fister();
		while(L.Next())
		{
			L.GetData(tmp);
			InsertR(tmp);
			Next();
		}
	}
	return *this;
}

template<class T>
bool DbList<T>::GetData(T& val)
{
	if (current!=NULL&&current!=head)
	{
		val=current->data;
		return true;
	}
	return false;
}

template<class T>
bool DbList<T>::MakeEmpty()
{
	DbLNode<T> *tmp;
	current=head;
	head=head->rLink;
	while(head!=NULL)
	{
		tmp=head;
		head=head->rLink;
		delete tmp;
	}
	head=current;
}

template<class T>
bool DbList<T>::Next()
{
	if (current->rLink!=NULL)
	{
		current=current->rLink;
		return true;
	}
	return false;
}

template<class T>
bool DbList<T>::Prior()
{
	if (current!=head)
	{
		current=current->lLink;
		return true;
	}
	return false;
}

template<class T>
bool DbList<T>::IsEmpty()
{
	return head->rLink==NULL?true:false;
}

template<class T>
int DbList<T>::Length()
{
	int count;
	DbLNode<T>* tmp=head->rLink;
	while(tmp!=NULL)
	{
		++count;
		tmp=tmp->rLink;
	}
	return count;
}

template<class T>
void DbList<T>::InsertR(const T& val)
{
	DbLNode<T>* currentR=current->rLink;
	DbLNode<T> *Node = new DbLNode<T>(val);
	if (currentR==NULL)
	{
		current->rLink=Node;
		Node->lLink=current;
	}else
	{
		current->rLink=Node;
		Node->lLink=current;
		currentR->lLink=Node;
		Node->rLink=currentR;
	}
}

template<class T>
void DbList<T>::InsertL(const T& val)
{
	DbLNode<T>* currentL=current->lLink;
	DbLNode<T>* Node=new DbLNode<T>(val);
	if (currentL==NULL)
	{
		InsertR(val);
	}else
	{
		current->lLink=Node;
		Node->rLink=current;
		currentL->rLink=Node;
		Node->lLink=currentL;
	}
}

template<class T>
void DbList<T>::Remove()
{
	if (head==current)
	{
		cerr<<"Can not remove head Node"<<endl;
	}
	if (IsEmpty())
	{
		cerr<<"Can not remove any Node in an empty List"<<endl;
	}
	DbLNode<T>* tmp=current;
	Prior();
	if (tmp->rLink==NULL)
	{
		current->rLink=NULL;
	}else
	{
		current->rLink=tmp->rLink;
		tmp->rLink->lLink=current;
	}
	delete tmp;
}

template<class T>
bool DbList<T>::Find(const T& val)
{
	DbLNode<T>* fish=head->rLink;
	while(fish!=NULL)
	{
		if (fish->data==val) 
		{
			current=fish;
			return true;
		}
		fish=fish->rLink;
	}
	return false;
}
template<class T>
void DbList<T>::Fister()
{
	current=head;
}
template<class T>
DbList<T>::~DbList()
{
	MakeEmpty();
	delete head;
	head=current=0;
}







