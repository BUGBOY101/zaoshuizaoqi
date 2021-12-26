#define	_CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAX 100
#define LISTINCREMENT 10
typedef int elemtype;

//定义一个顺序表

typedef struct {
	elemtype* elem;
	int length;
	int listsize;
}SqList;

//建立一个线性表

void CreatList(SqList& L) {
	int i;
	L.elem = (elemtype*)malloc(MAX * sizeof(elemtype));
	if (!L.elem)
		return;
	L.listsize = MAX;
	cin >> L.length;
	for (i = 0; i < L.length; i++) {
		cin >> L.elem[i];
	}
}

//在顺序表的第i个元素之前插入一个元素

void ListInsert(SqList& L, int i, elemtype e) {
	if (i<1 || i>L.length + 1) {
		cout << "i值不合法" << endl;
		return;
	}
	/*if (L.length >= L.listsize) {
		elemtype *newbase = (elemtype*)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(elemtype));
		if (!newbase)
			cout << "存储分配失败" << endl;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}*/
	int j;
	for (j = L.length-1; j >= i-1; j--) {
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
}

//在顺组表中查找第i个元素,用e返回其值

int LocateElem(SqList L, int i) {
	if (i<1 || i>L.length + 1) {
		return -1;
	}//i值不合法
	else {
		elemtype e = L.elem[i - 1];
		return e;
	}
}

//按值查找

int LocateElem2(SqList L, elemtype e) {
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i+1;
	}
	return -1;//找不到目标值，返回-1
}

//更新顺序表中第i个元素的值

void ListReplace(SqList& L, int i, elemtype e) {
	if (i<1 || i>L.length + 1) {
		cout << "i值不合法" << endl;
		exit(1);
	}
	L.elem[i - 1] = e;
}

int main() {
	SqList L;
	CreatList(L);
	int i, j, k, m, a, b;
	cout << "请输入插入元素的位置以及其值：";
	cin >> i >> a;
	ListInsert(L, i, a);//在第i个元素之前插入a
	cout << "请输入需要替换的元素位置及其值：";
	cin >> j >> b;
	ListReplace(L, j, b);
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i] << " ";
	}//打印L
	cout << endl;
	cout << "请输入你需要查找的第k个元素：";
	cin >> k;
	cout << LocateElem(L,k) << endl;//在L中查找第k个元素
	cout << "请输入你需要找到值为m的元素在第几个位置：";
	cin >> m;
	cout << LocateElem(L,m) << endl;//在L中找到值为m的元素在第几个位置
}


