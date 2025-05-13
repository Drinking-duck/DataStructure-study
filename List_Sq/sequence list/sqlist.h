/*
��ʼ��InitList(&L)���ͷ�DestroyList(&L)���ÿ�ClearList(&L)��
����ListTraverse(L)��ȡֵGetElem(L,i,&e)������LocateElem(L, e)��
����ListInsert(&L, i, e)��ɾ��ListDelete(&L, i, &e)��
ListLength(L)��ListEmpty(L)
*/


#pragma once

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef  struct
{
	ElemType* elem;
	int length;
}SqList;

Status InitList(SqList&L);
Status DestroyList(SqList &L);
Status ClearList(SqList& L);

void TraverseList(const SqList& L);
Status GetElem(SqList L,int i,ElemType &e);
int LocateElem(SqList L, ElemType e);

Status ListInsert(SqList& L, int i,ElemType e);
Status ListDelete(SqList& L,int i,ElemType& e);

int ListLength(SqList L);
int ListEmpty(SqList L);