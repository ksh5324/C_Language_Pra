#include<stdio.h>

int func(int n) {
	static int a = 0;
	a++;
	printf("n=%d, a=%d\n", n, a);
	return 0;
}

int _main() {
	//static ������ ����ϴ� ������?
	int n = 5;
	func(n);
	func(n);
	return 0;
}