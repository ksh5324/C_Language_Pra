#include<stdio.h>
// �̸��� ���̸� �Է¹޾� ����ϴ� ���α׷�

typedef struct person
{
	char name[20];
	int age;
} Student;
int main() {
	Student me;
	printf("�̸� �Է� : ");
	scanf("%s", me.name);
	printf("���� �Է� : ");
	scanf("%d", &me.age);
	printf("�̸�: %s, ����: %d", me.name, me.age);
	return 0;
}