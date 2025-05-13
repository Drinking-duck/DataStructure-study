#include"sqlist.h"

#include<iostream>
using namespace std;
int main()
{
	SqList L;
	ElemType a[] = { 13,14,250,22,33,55,66,99 }, e = 520;
	if (InitList(L)) 
	{
		cout<<"˳����ʼ���ɹ���"<<endl;
	}
	else
	{
		cout << "˳����ʼ��ʧ��" << endl;
		exit(1);
	}
	cout << endl;
	cout << "ʹ��ѭ�����β���a[]����" << endl;
	for (int i = 1; i <=sizeof(a)/sizeof(ElemType); i++) {
		ListInsert(L, i,a[i-1]);
	}
	TraverseList(L);
	cout << endl;
	
	int pos = 4;
	cout << "��˳���ĵ�" << pos << "��λ�ò���Ԫ��" << e << endl;
	ListInsert(L, pos, e);
	TraverseList(L);
	cout << endl;

	int po = 6;
	int delelem;
	cout << "ɾ����" << po << "��Ԫ��" << endl;
	ListDelete(L, po, delelem);
	cout << delelem << endl;
	TraverseList(L);
	cout << endl;

	int ax;
	cout << "���ҵڶ�����" << endl;
	GetElem(L,2,ax);
	cout << ax << endl;
	cout << endl;

	cout << "250��λ��"<<endl;
	cout << LocateElem(L, 250) << endl;
	
	cout << "˳���ĳ���" << endl;
	cout << ListLength(L) << endl;

	cout << "˳����Ƿ�Ϊ��" << endl;
	cout << ListEmpty(L) << endl;
	
	cout << "�ÿ�˳���" << endl;
	ClearList(L);
	cout << "����˳���"<<endl;
	DestroyList(L);

	return 0;
}