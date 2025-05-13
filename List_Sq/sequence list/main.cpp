#include"sqlist.h"

#include<iostream>
using namespace std;
int main()
{
	SqList L;
	ElemType a[] = { 13,14,250,22,33,55,66,99 }, e = 520;
	if (InitList(L)) 
	{
		cout<<"顺序表初始化成功！"<<endl;
	}
	else
	{
		cout << "顺序表初始化失败" << endl;
		exit(1);
	}
	cout << endl;
	cout << "使用循环依次插入a[]数据" << endl;
	for (int i = 1; i <=sizeof(a)/sizeof(ElemType); i++) {
		ListInsert(L, i,a[i-1]);
	}
	TraverseList(L);
	cout << endl;
	
	int pos = 4;
	cout << "在顺序表的第" << pos << "个位置插入元素" << e << endl;
	ListInsert(L, pos, e);
	TraverseList(L);
	cout << endl;

	int po = 6;
	int delelem;
	cout << "删除第" << po << "个元素" << endl;
	ListDelete(L, po, delelem);
	cout << delelem << endl;
	TraverseList(L);
	cout << endl;

	int ax;
	cout << "查找第二个数" << endl;
	GetElem(L,2,ax);
	cout << ax << endl;
	cout << endl;

	cout << "250的位置"<<endl;
	cout << LocateElem(L, 250) << endl;
	
	cout << "顺序表的长度" << endl;
	cout << ListLength(L) << endl;

	cout << "顺序表是否为空" << endl;
	cout << ListEmpty(L) << endl;
	
	cout << "置空顺序表" << endl;
	ClearList(L);
	cout << "销毁顺序表"<<endl;
	DestroyList(L);

	return 0;
}