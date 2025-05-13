#include"Union_Sqlist.h"

int main()
{
	SqList LA, LB, LC, LD, LE;
	ElemType e;
	if (InitList(LA))
		cout << "LA初始化成功" << endl;
	if (InitList(LB))
		cout << "LB初始化成功" << endl;
	if (InitList(LC))
		cout << "LC初始化成功" << endl;
	if (InitList(LD))
		cout << "LD初始化成功" << endl;
	if (InitList(LE))
		cout << "LE初始化成功" << endl;
	cout << endl;

	cout << "Merge的测试过程" << endl;
	cout << endl;
	ListInsert(LA, 1, 7);
	ListInsert(LA, 2, 3);
	ListInsert(LA, 3, 5);
	ListInsert(LA, 4, 2);
	TraverseList(LA);
	cout << endl;
	ListInsert(LB, 1, 1);
	ListInsert(LB, 1, 2);
	ListInsert(LB, 1, 6);
	TraverseList(LB);
	cout << endl;
	Merge(LA, LB);
	TraverseList(LA);

	cout << endl;
	cout << "Merge_Pluse的测试过程" << endl;
	ListInsert(LD, 1, 1);
	ListInsert(LD, 2, 2);
	ListInsert(LD, 3, 3);
	ListInsert(LD, 4, 4);
	cout << endl;
	TraverseList(LD);
	cout << endl;
	ListInsert(LE, 1, 4);
	ListInsert(LE, 2, 5);
	ListInsert(LE, 3, 6);
	TraverseList(LE);
	cout << endl;
	Merge_Pluse(LD, LE, LC);
	TraverseList(LC);

	return 0;
}