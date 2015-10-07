/*************************************************************************
	> File Name: main.cpp
	> Author: JiaShi
	> Mail: 838357982@qq.com 
	> Created Time: 2015年10月07日 星期三 13时54分07秒
 ************************************************************************/

#include<iostream>
#include"SeqList.cpp"
using namespace std;
int main()
{
	SeqList<int> L(10),L1,L3(2);
	for(int i=0;i<=20;i++)
		L.Push(i);
	SeqList<int > L2(L);
    L1=L2;
	for (int i=0;i<=10;i++)
	{
		L3.Insert(0,i);
	}
	for (int i=0;i<=10;i++)
	{
		int value;
		L3.Getdata(i,value);
		cout<<value<<endl;
	}
	int value;
	for (int i=0;i<=10;i++)
	{
		L2.Getdata(i,value);
		cout<<value<<endl;
	}
	return 0;
}
