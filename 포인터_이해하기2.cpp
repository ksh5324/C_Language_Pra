#include<stdio.h>

int main() {
	int n1 = 100;
	int* p;
	p = &n1;// �ּҿ� �ּ� ����
	printf("%p, %p\n", p, &n1);
	printf("����, ��: %d, %d\n", *p, n1);
	for (int i = 0; i < 5; i++) {
		printf("%4d", (*p)++);
	}
	return 0;
}