#include<stdio.h>
#include<string.h>

struct Student {
	char name[20];
	int stuNum;
	int age;
	char address[100];
};

int main() {
	struct Student a[5];
	for (int i = 0; i < 5; i++) {
		printf("�̸�: ");
		scanf("%s", a[i].name);
		printf("�й�: ");
		scanf("%d", &a[i].stuNum);
		printf("����: ");
		scanf("%d", &a[i].age);
		printf("�ּ�: ");
		scanf("%s", a[i].address);
	}
	for (int i = 0; i < 5; i++) {
		printf("�̸� : %s\n", a[i].name);
		printf("���� : %d\n", a[i].age);
		printf("�й� : %d\n", a[i].stuNum);
		printf("�ּ� : %s\n", a[i].address);
		printf("\n");
	}
}