/*************************************************************************
	> File Name: DbListtest.cpp
	> Author: JiaShi
	> Mail: 838357982@qq.com 
	> Created Time: 2015年10月11日 星期日 10时40分44秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"DbList.cpp"
using namespace std;
int main()
{
	vector<int> v;
	for (int i=0;i<=10;i++)
		v.push_back(i);
	DbList<int> L(v),L1;
	DbList<int> L2(v);
	L2.Fister();
	for(int i=7;i<=7;i++)
	{
		if (L2.Find(i)) L2.Remove();
	}
	int b;
	L2.GetData(b);
	cout<<"asdfadfasdf"<<b<<endl;
	L2.InsertR(7);
	L2.Fister();
	while(L2.Next())
	{
		int a;
		L2.GetData(a);
		cout<<a<<endl;
	}
	return 0;
}
