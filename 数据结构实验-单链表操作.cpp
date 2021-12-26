#define	_CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAX 100
#define LISTINCREMENT 10
typedef int elemtype;

//单链表的定义

typedef struct Lnode {
	elemtype data;	//data存放结点的数据域
	struct Lnode* next;//指针域
}Lnode,*LinkList;//定义单链表结点类型

//头插法建立单链表

//void createList(LinkList &L,int n) {
//	Lnode* p;
//	int i;
//	L = (Lnode*)malloc(sizeof(Lnode));
//	L->next = NULL;
//	for (i = 0; i < n; i++) {
//		p = (Lnode*)malloc(sizeof(Lnode));
//		cin >> p->data;;
//		p->next = L->next;
//		L->next = p;
//	}
//}

//尾插法建立单链表

void createList2(LinkList& L, int n) {
	int i;
	L = (Lnode*)malloc(sizeof(Lnode));
	if (L == NULL) {
		return;
	}
	L->next = NULL;
	Lnode* p, * q;
	q = L;
	for (i = 0; i < n; i++) {
		p = (Lnode*)malloc(sizeof(Lnode));
		if (p != NULL) {
			cin >> (p->data);
			q->next = p;
			p->next = NULL;
			q = p;
		}
	}
}

//在单链表的第i个节点前插一个结点

void ListInsert_L(LinkList&L, int i, elemtype e) {
	Lnode* p = L;
	Lnode* s = new Lnode;
	if (s != NULL) {
		int j = 1;
		while (p && j < i) {
			p = p->next;
			++j;
		}//p指向i-1结点
		if (p == NULL || j > i)
			cout << "i值不合法" << endl;
		else{
			s->data = e;
			s->next = p->next;
			p->next = s;
		}
	}
	
}

//打印链表

void print(LinkList L) {
	Lnode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//在单链表中查找第i个节点

int GetElem(LinkList L,int i, elemtype &e) {
	LinkList p = L;
	if (p == NULL) {
		return 0;
	}
	int j = 1;
	while (p && j <= i) {
		p = p->next;
		++j;
	}
	if (p == NULL) {
		cout << "i值不合法" << endl;
		return -1;
	}
		
	else
		e = p->data;
	return e;
}

//按值查找

int GetElem2(LinkList L, elemtype e) {
	Lnode* p = L->next;
	int i = 0;//i为计数器
	while (p) {
		if (p->data == e) {
			return i;	//找到目标值，返回其下标
		}
		else {
			p = p->next;
			i++;
		}	
	}
	return -1;//找不到目标值，返回-1
}

//遍历单链表

void Traverse(LinkList L) {
	Lnode* p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	int n, e, i, a, j, m;
	Lnode* L;
	cout << "请输入链表长度：";
	cin >> n;
	createList2(L, n);
	print(L);
	cout << "请输入需插入元素的位置及其值：";
	cin >> i >> a;
	ListInsert_L(L, i, a);
	cout << "请输入需获取第j元素的位置：";
	cin >> j;
	cout << GetElem(L, j, e) << endl;
	cout << "请输入你需要查询值为m的元素在第几个位置：";
	cin >> m;
	cout << GetElem2(L, m) << endl;
	cout << "打印表" << endl;
	print(L);
}
