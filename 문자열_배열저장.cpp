#include<stdio.h>
// ���ڿ� �����ϴ� �迭�� ���Ͽ�
int main() {
	char str[] = "Hello World\n";
	printf("str=%s\n", str);
	printf("str�� ũ�� : %d\n", sizeof(str));
	printf("%d\n", sizeof("Hello"));
	char str1[10];
	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0';
	str1[4] = 'd';
	printf("str1=%s\n", str1);
	printf("str1=%d\n", sizeof(str1));
	return 0;
}