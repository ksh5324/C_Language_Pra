#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int result = 0;

int f(char y) {
x:
	printf("�ֻ��� ������ �Ͻðڽ��ϱ�(y/n) ");
	scanf(" %c", &y);
	if (y == 'n' || y == 'N') {
		exit(1);
	}
	else if (y == 'y' || y == 'Y') {
		result = 0;
		return 0;
	}
	else {
		printf("�߸��Է� �ϼ̽��ϴ�.\n");
		goto x;
	}
}

int main() {
	srand(time(NULL));
	int i, j;
	char y=' ';
	f(y);
	while (1) {
	i = rand() % 6 + 1;
	j = rand() % 6 + 1;
		printf("�ֻ���: %d %d\n", i, j);
		result = result + i + j;
		if (i == j) {
			printf("�����Դϴ�.\n");
		}
		else {
			printf("%dĭ �����ϼ���\n", result);
			f(y);
		}
	}
	return 0;
}