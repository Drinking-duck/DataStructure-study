#include"Union_Sqlist.h"

Status InitList(SqList& L)
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
	if ((i < 1) || (i > L.length + 1))
	{
		return ERROR;
	}
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
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

void Merge(SqList& La, SqList& Lb)
{
	ElemType e;
	int la_len, lb_len;
	la_len = ListLength(La);
	lb_len = ListLength(Lb);
	for (int i = 1; i <= lb_len; i++)
	{
		GetElem(Lb, i, e);
		if (LocateElem(La, e) == 0)
			ListInsert(La, ++la_len, e);
	}
}

void Merge_Pluse(SqList& La, SqList& Lb, SqList& Lc)
{
	int i = 0, j = 0, k = 0;
	while (i < La.length && j < Lb.length)
	{
		if (La.elem[i] < Lb.elem[j])
		{
			Lc.elem[k] = La.elem[i];
			i++;
		}
		else
		{
			Lc.elem[k] = Lb.elem[j];
			j++;
		}
		k++;
	}
	while (i < La.length)
	{
		Lc.elem[k] = La.elem[i];
		i++;
		k++;
	}
	while (j < Lb.length)
	{
		Lc.elem[k] = Lb.elem[j];
		j++;
		k++;
	}
	Lc.length = k;

	//ШЅжи

	int m = 0;
	for (int n = 1; n < Lc.length; n++)
	{
		if (Lc.elem[n] != Lc.elem[m])
		{
			Lc.elem[++m] = Lc.elem[n];
		}
	}

	Lc.length = m + 1;
}