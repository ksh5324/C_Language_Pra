#include<stdio.h>

int main() {
	int a[5] = { 0,1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%d %d\n", &a[0], &a[1]);
	printf("a�ּ�=%d a[0]�ּ�=%d\n", a, &a[0]);
	int* p = a;
	printf("a�ּ�=%d\n", p);
	return 0;
}