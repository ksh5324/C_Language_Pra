#include<stdio.h>
#include<Windows.h>
int m[9][9] = {
	{2,2,2,2,2,2,2,2,2},
	{2,0,0,0,0,0,0,0,2},
	{2,0,2,2,0,2,2,0,2},
	{2,0,2,0,0,2,0,0,2},
	{2,0,2,0,2,0,2,0,2},
	{2,0,0,0,0,0,2,0,2},
	{2,2,0,2,2,0,2,2,2},
	{2,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2}
};
int Si, Sj, Ei, Ej, success, idx, Path_i[100], Path_j[100];
// S : start, E: end, idx ��� �迭 �ε���
// ri, rj : ������ ���� ����

int visit(int, int);

int main() {
	idx = 0;
	success = 0;
	printf("�̷�Ż�� ����\n");
	Si = 1, Sj = 1;
	Ei = 7, Ej = 7;
	if (visit(Si, Sj) == 0) {
		printf("�� ã����\n");
	}
	else {
		printf("��� ��θ� ã����\n");
	}
	return 0;
}

int visit(int i, int j) {
	static int path = 1; // ã�� ��� ����
	m[i][j] = 1;
	Path_i[idx] = i, Path_j[idx] = j; // ��� Path�� ����
	idx++;
	// ���� �������� �����ߴٸ�
	if (i == Ei && j == Ej) {
		printf(" %d��° ã�� ���\n", path++);
		//for (int k = 0; k < idx; k++) { // ��� ���
		//	printf("(%d, %d) ", Path_i[k], Path_j[k]);
		//}
		for (int k = 0; k < 9; k++) {
			for (int z = 0; z < 9; z++) {
				if (m[k][z] == 1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					printf("��");
				}
				else if (m[k][z] == 2) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					printf("��");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("��");
				}
			}
			printf("\n");
		}
		printf("\n");
		success = 1; // ��� ã�� ����
	}

	// �̷θ� ���������� Ž���ϴ� �ڵ�
	if (m[i][j + 1] == 0) // ������ �� ã��
		visit(i, j + 1);
	if (m[i + 1][j] == 0) // �Ʒ��� Ž��
		visit(i + 1, j);
	if (m[i][j - 1] == 0) // ���� Ž��
		visit(i, j - 1);
	if (m[i - 1][j] == 0) // ���� Ž��
		visit(i - 1, j);
	idx--;
	m[i][j] = 0;
	return success;
		
}