#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main() {
	int i, j, a, b;
	char ar[200][200] = {};
	printf("�����Է�: ex) 08, 13, 01\n ���ڸ� ���� ������ �ʿ� �ڸ� 0����\n");
	a = getch() - 48;
	b = getch() - 48;
	for (i = 0; i < (a * 10 + b) * 2 - 1; i++) {
		for (j = 0; j < (a * 10 + b) * 2 - 1; j++)
			if (i == j || i + j == (a * 10 + b) * 2 - 2 || i == 0 || i == (a * 10 + b) * 2 - 2) {
				ar[i][j] = '*';
			}
			else {
				ar[i][j] = 32;
			}
	}
	for (i = 0; i < ((a * 10 + b) * 2); i++) {
		for (j = 0; j < ((a * 10 + b) * 2); j++) {
			printf("%c", ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}