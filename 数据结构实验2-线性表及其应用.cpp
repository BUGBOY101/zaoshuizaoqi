#define	_CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAX 100
#define LISTINCREMENT 10
typedef int elemtype;

//����һ��˳���

typedef struct {
	elemtype* elem;
	int length;
	int listsize;
}SqList;

//����һ�����Ա�

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

//��˳���ĵ�i��Ԫ��֮ǰ����һ��Ԫ��

void ListInsert(SqList& L, int i, elemtype e) {
	if (i<1 || i>L.length + 1) {
		cout << "iֵ���Ϸ�" << endl;
		return;
	}
	/*if (L.length >= L.listsize) {
		elemtype *newbase = (elemtype*)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(elemtype));
		if (!newbase)
			cout << "�洢����ʧ��" << endl;
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

//��˳����в��ҵ�i��Ԫ��,��e������ֵ

int LocateElem(SqList L, int i) {
	if (i<1 || i>L.length + 1) {
		return -1;
	}//iֵ���Ϸ�
	else {
		elemtype e = L.elem[i - 1];
		return e;
	}
}

//��ֵ����

int LocateElem2(SqList L, elemtype e) {
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i+1;
	}
	return -1;//�Ҳ���Ŀ��ֵ������-1
}

//����˳����е�i��Ԫ�ص�ֵ

void ListReplace(SqList& L, int i, elemtype e) {
	if (i<1 || i>L.length + 1) {
		cout << "iֵ���Ϸ�" << endl;
		exit(1);
	}
	L.elem[i - 1] = e;
}

int main() {
	SqList L;
	CreatList(L);
	int i, j, k, m, a, b;
	cout << "���������Ԫ�ص�λ���Լ���ֵ��";
	cin >> i >> a;
	ListInsert(L, i, a);//�ڵ�i��Ԫ��֮ǰ����a
	cout << "��������Ҫ�滻��Ԫ��λ�ü���ֵ��";
	cin >> j >> b;
	ListReplace(L, j, b);
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i] << " ";
	}//��ӡL
	cout << endl;
	cout << "����������Ҫ���ҵĵ�k��Ԫ�أ�";
	cin >> k;
	cout << LocateElem(L,k) << endl;//��L�в��ҵ�k��Ԫ��
	cout << "����������Ҫ�ҵ�ֵΪm��Ԫ���ڵڼ���λ�ã�";
	cin >> m;
	cout << LocateElem(L,m) << endl;//��L���ҵ�ֵΪm��Ԫ���ڵڼ���λ��
}


