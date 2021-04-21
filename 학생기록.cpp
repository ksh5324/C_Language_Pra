#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
struct student
{
	int student_num;
	char name[10];
	char address[50];
	int Phone_num;
	int kor;
	int str;
};
struct student a[100];
int len = 0;

void mix(int i) {
	struct student temp;
	for (; i < len; i++) {
		temp.student_num = a[i].student_num;
		a[i].student_num = a[i - 1].student_num;
		a[i - 1].student_num = temp.student_num;

		*temp.name = *a[i].name;
		*a[i].name = *a[i - 1].name;
		*a[i - 1].name = *temp.name;

		*temp.address = *a[i].address;
		*a[i].address = *a[i - 1].address;
		*a[i - 1].address = *temp.address;


		temp.Phone_num = a[i].Phone_num;
		a[i].Phone_num = a[i - 1].Phone_num;
		a[i - 1].Phone_num = temp.Phone_num;

		temp.kor = a[i].kor;
		a[i].kor = a[i - 1].kor;
		a[i - 1].kor = temp.kor;

		temp.str = a[i].str;
		a[i].str = a[i - 1].str;
		a[i - 1].str = temp.str;
	}
}

void p(int i) {
	printf("----------%d---------\n", i + 1);
	printf("�й�: %d\n", a[i].student_num);
	printf("�̸�: %s\n", a[i].name);
	printf("�ּ�: %s\n", a[i].address);
	printf("��ȭ��ȣ: %d\n", a[i].Phone_num);
	printf("��������: %d\n", a[i].kor);
	printf("�˰��� ����: %d\n", a[i].str);
	printf("---------------------\n\n");
}
void create() {
	printf("����\n");
	Sleep(500);
	printf("�й�: ");
	scanf_s("%d", &a[len].student_num);

	printf("�̸�: ");
	scanf("%s", a[len].name);
	fflush(stdout);
	printf("�ּ�: ");
	scanf("%s", a[len].address);

	printf("��ȭ��ȣ: ");
	scanf_s("%d", &a[len].Phone_num);

	printf("��������: ");
	scanf_s("%d", &a[len].kor);

	printf("�˰��� ����: ");
	scanf_s("%d", &a[len].str);
	printf("\n\n\n");
	len++;
}

void print() {
	printf("���\n");
	Sleep(500);
	for (int i = 0; i < len; i++) {
		p(i);
	}
	printf("\n\n\n");
}

void search() {
	printf("�˻�\n");
	Sleep(500);
	int Sea;
	printf("ã����� �й�: ");
	scanf("%d", &Sea);
	int i = 0;
	while (1) {
		if (Sea == a[i].student_num) {
			p(i); printf("\n\n\n");  break;
		}
		else {
			i++;
		}
	}
}

void delete_() {
	printf("����\n");
	Sleep(500);
	printf("������ �й�: ");
	int R;
	scanf("%d", &R);
	int i = 0;
	while (1) {
		if (R == a[i].student_num)
		{
			mix(i);
			len--;
			Sleep(300);
			printf("������\n");
			printf("\n\n\n");
			break;
		}
		else {
			i++;
		}
	}
}

void mix_2(int j, int i) {
	struct student temp;
	temp.student_num = a[j].student_num;
	a[j].student_num = a[i].student_num;
	a[i].student_num = temp.student_num;

	*temp.name = *a[j].name;
	*a[j].name = *a[i].name;
	*a[i].name = *temp.name;

	*temp.address = *a[j].address;
	*a[j].address = *a[i].address;
	*a[i].address = *temp.address;


	temp.Phone_num = a[j].Phone_num;
	a[j].Phone_num = a[i].Phone_num;
	a[i].Phone_num = temp.Phone_num;

	temp.kor = a[j].kor;
	a[j].kor = a[i].kor;
	a[i].kor = temp.kor;

	temp.str = a[j].str;
	a[j].str = a[i].str;
	a[i].str = temp.str;
}

void num() {
	printf("1.��������  2.��������\n");
	int b;
	b = getch() - 48;
	if (b == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].student_num >= a[i].student_num) {
					mix_2(j, i);
				}
			}
		}
	}
	else if (b == 2) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].student_num <= a[i].student_num) {
					mix_2(j, i);
				}
			}
		}
	}
	Sleep(300);
	printf("���ĵ�\n\n\n\n");
}

void name() {
	printf("1.��������  2.��������\n");
	int b;
	b = getch() - 48;
	if (b == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].name[0] >= a[i].name[0]) {
					mix_2(j, i);
				}
			}
		}
	}
	else if (b == 2) {
		for(int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].name[0] <= a[i].name[0]) {
					mix_2(j, i);
				}
			}
		}
	}
}

void grade() {
	printf("1.��������  2.��������\n");
	int b;
	b = getch() - 48;
	if (b == 1) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].str >= a[i].str) {
					mix_2(j, i);
				}
			}
		}
	}
	else if (b == 2) {
		for (int j = 0; j < len; j++) {
			for (int i = j + 1; i <= len - 1; i++) {
				if (a[j].str <= a[i].str) {
					mix_2(j, i);
				}
			}
		}
	}
}

void Sort() {
	printf("����\n");
	Sleep(500);
	printf("���Ŀ� ����\n1.�й� 2.�̸�//��� ���� 3.�˰��� ����\n");
	int c;
	c = getch() - 48;
	switch (c) {
	case 1: num(); break;
	case 2: name(); break;
	case 3: grade(); break;
	}
}

void Change() {
	printf("����\n");
	printf("�����ų ����� �й�: ");
	int c;
	scanf("%d", &c);
	int i;
	for (i = 0; c != a[i].student_num; i++) {
	}
	printf("�й�: ");
	scanf_s("%d", &a[i].student_num);

	printf("�̸�: ");
	scanf("%s", a[i].name);
	fflush(stdout);
	printf("�ּ�: ");
	scanf("%s", a[i].address);

	printf("��ȭ��ȣ: ");
	scanf_s("%d", &a[i].Phone_num);

	printf("��������: ");
	scanf_s("%d", &a[i].kor);

	printf("�˰��� ����: ");
	scanf_s("%d", &a[i].str);
	printf("\n\n\n");
}

int main() {
	int choose=0; 
	printf("* �� ���α׷����� �����ҽ� �� 0.5�� ������ ��ٸ��� �ֽ��ϴ� *\n");
	system("pause");
	system("cls");
	while (1) {
		printf("1.����  2.�˻�  3.����  4.��� ���  5.����  6.����  7.ȭ�����\n");
		choose = getch() - 48;
		switch (choose)
		{
		case 1: create(); break;
		case 2: search(); break;
		case 3: delete_(); break;
		case 4: print(); break;
		case 5: Sort(); break;
		case 6: Change(); break;
		case 7: system("cls"); break;
		}
	}
	return 0;
}