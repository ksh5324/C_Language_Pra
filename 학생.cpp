#include<stdio.h>
#include<string.h>

struct Student {
	char name[20];
	int stuNum;
	int age;
	char address[100];
};

int main() {
	struct Student class13[20];
	strcpy(class13[0].name, "������");
	class13[0].age = 17;
	class13[0].stuNum = 1301;
	strcpy(class13[0].address, "�뱸�� �޼��� â���� 11��");
	printf("1�г� 3�� �л� ����\n");
	printf("�̸� : %s\n", class13[0].name);
	printf("���� : %d\n", class13[0].age);
	printf("�й� : %d\n", class13[0].stuNum);
	printf("�ּ� : %s\n", class13[0].address);
	return 0;
}