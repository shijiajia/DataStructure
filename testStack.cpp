/*************************************************************************
	> File Name: testStack.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年10月17日 星期六 08时30分49秒
 ************************************************************************/

#include<iostream>
#include"Stack.cpp"
using namespace std;
int main()
{
	Stack<int> S,S1;
	for (int i=0;i<=120;i++)
		S.Push(i);
	cout<<S.Top()<<endl;
	S1=S;
	S1.Pop();
	cout<<S1.Top()<<endl;
	cout<<S1.GetSize()<<endl;
	Stack<int> S2(S);
	cout<<S2.Top()<<endl;
	return 0;
}
