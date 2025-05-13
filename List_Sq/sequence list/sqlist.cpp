#include"sqlist.h"
#include<iostream>
using namespace std;

Status InitList(SqList &L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
	{
		exit(0);
	}
	L.length = 0;
	return OK;
}
Status DestroyList(SqList& L) {
	if (L.elem)
		delete[]L.elem;
	L.elem = NULL;
	L.length = 0;
	return OK;
}

Status ClearList(SqList& L) {
	L.length = 0;
	return OK;
}

void TraverseList(const SqList& L) {
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
}

Status GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) 
		{
			return i + 1;
			break;
		}
	}
	return 0;
}

Status ListInsert(SqList& L, int i, ElemType e)
{
	//插入的位置i的合法性判断
	if ((i < 1) || (i > L.length + 1))
	{
		return ERROR;
	}
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--)//把萝卜坑腾出来
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

Status ListDelete(SqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

int ListLength(SqList L) {
	return L.length;
}

int ListEmpty(SqList L) {
	if (L.length == 0)
		return 1;
	return 0;
}