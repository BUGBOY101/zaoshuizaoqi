#define	_CRT_SECURE_NO_WARNINGS
#include<iostream>
#define N 2//定义数组个数
using namespace std;
struct student
{
	long long id;
	char name[20];
	float score1;
	float score2;
	float score3;
	float score4;
	float average;
};
int main() {
	int i;
	struct student stu[N], *p;
	p = stu;
	for (i = 0; i < N; i++) {
		cin >> stu[i].id >> stu[i].name >> stu[i].score1 >> stu[i].score2 >> stu[i].score3 >> stu[i].score4;
	}

	for (i = 0; i < N; i++) {
		if ((stu[i].score1 < 0 || stu[i].score1>100) || (stu[i].score2 < 0 || stu[i].score2>100) || (stu[i].score3 < 0 || stu[i].score3>100) || (stu[i].score4 < 0 || stu[i].score4>100)) {
			cout << "输入错误" << endl;
			break;
		}
		else {
			cout << "考试没有通过的同学姓名：";

			for (i = 0; i < N; i++) {

				if (stu[i].score1 < 60 || stu[i].score2 < 60 || stu[i].score3 < 60 || stu[i].score4 < 60) {


					if (i < N - 1)
						cout << stu[i].name << " ";
					else
						cout << stu[i].name << endl;
				}

			}
			cout << endl;

			cout << "考试成绩超过90的同学姓名：";

			for (i = 0; i < N; i++) {

				if (stu[i].score1 > 90 || stu[i].score2 > 90 || stu[i].score3 > 90 || stu[i].score4 > 90) {

					if (i < N - 1)
						cout << stu[i].name << " ";
					else
						cout << stu[i].name << endl;
				}
			}
			cout << endl;
		}
	}
}

/*for (i = 0; i < N; i++) {
		if ((stu[i].score1 < 0 || stu[i].score1>100) || (stu[i].score2 < 0 || stu[i].score2>100) || (stu[i].score3 < 0 || stu[i].score3>100) || (stu[i].score4 < 0 || stu[i].score4>100)) {
			cout << "输入错误" << endl;
			break;
		}
		else {
			for (p; p < stu + N; p++) {
				cin >> p->id >> p->name >> p->score1 >> p->score2 >> p->score3 >> p->score4;
			}

			cout << "成绩不及格的同学姓名：";

			for (p = stu; p < stu + N; p++) {
				if (p->score1 < 60 || p->score2 < 60 || p->score3 < 60 || p->score4 < 60) {
					cout << p->name;
					if (p < stu + N - 1)
						cout << " ";
					else
						cout << endl;
				}
			}
			cout << endl;
			cout << "成绩超过90的同学姓名：";
			for (p = stu; p < stu + N; p++) {
				if (p->score1 > 90 || p->score2 > 90 || p->score3 > 90 || p->score4 > 90) {
					cout << p->name;
					if (p < stu + N - 1)
						cout << " ";
					else
						cout << endl;
				}
			}
			cout << endl;
		}
	}*/
	
	
	
