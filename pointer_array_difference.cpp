#include<stdio.h>

int main() {
	int a[5] = { 0,1,2,3,4 };
	int* p;
	int b = 10;
	a = &a; // �Ľ� �����Ҽ��ִ� lvalue���� �մϴ�.
	b = &b;
}