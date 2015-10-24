/*************************************************************************
	> File Name: TestSeqQueue.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年10月24日 星期六 09时58分48秒
 ************************************************************************/

#include<iostream>
#include"SeqQueue.cpp"
using namespace std;
int main()
{
	SeqQueue<int> s;
	for (int i=1;i<=108;i++)
		s.EnQueue(i);
	SeqQueue<int> s1=s;
	s1.DeQueue();
	cout<<s1.GetSize()<<endl;
	cout<<s1<<endl;
	return 0;
}

