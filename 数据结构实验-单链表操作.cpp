#define	_CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAX 100
#define LISTINCREMENT 10
typedef int elemtype;

//������Ķ���

typedef struct Lnode {
	elemtype data;	//data��Ž���������
	struct Lnode* next;//ָ����
}Lnode,*LinkList;//���嵥����������

//ͷ�巨����������

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

//β�巨����������

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

//�ڵ�����ĵ�i���ڵ�ǰ��һ�����

void ListInsert_L(LinkList&L, int i, elemtype e) {
	Lnode* p = L;
	Lnode* s = new Lnode;
	if (s != NULL) {
		int j = 1;
		while (p && j < i) {
			p = p->next;
			++j;
		}//pָ��i-1���
		if (p == NULL || j > i)
			cout << "iֵ���Ϸ�" << endl;
		else{
			s->data = e;
			s->next = p->next;
			p->next = s;
		}
	}
	
}

//��ӡ����

void print(LinkList L) {
	Lnode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//�ڵ������в��ҵ�i���ڵ�

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
		cout << "iֵ���Ϸ�" << endl;
		return -1;
	}
		
	else
		e = p->data;
	return e;
}

//��ֵ����

int GetElem2(LinkList L, elemtype e) {
	Lnode* p = L->next;
	int i = 0;//iΪ������
	while (p) {
		if (p->data == e) {
			return i;	//�ҵ�Ŀ��ֵ���������±�
		}
		else {
			p = p->next;
			i++;
		}	
	}
	return -1;//�Ҳ���Ŀ��ֵ������-1
}

//����������

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
	cout << "�����������ȣ�";
	cin >> n;
	createList2(L, n);
	print(L);
	cout << "�����������Ԫ�ص�λ�ü���ֵ��";
	cin >> i >> a;
	ListInsert_L(L, i, a);
	cout << "���������ȡ��jԪ�ص�λ�ã�";
	cin >> j;
	cout << GetElem(L, j, e) << endl;
	cout << "����������Ҫ��ѯֵΪm��Ԫ���ڵڼ���λ�ã�";
	cin >> m;
	cout << GetElem2(L, m) << endl;
	cout << "��ӡ��" << endl;
	print(L);
}
