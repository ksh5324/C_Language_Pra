#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct bankBook
{
	char userName[10];
	char id[30];
	char password[30];
	double money;
	FILE* fp;
};

struct people
{
	char id[30];
	char userName[30];
	char password[30];
	int phoneNum;
	char addresss[50];
};

typedef struct bank
{
	struct bankBook bank[100];
	struct people people[20];
	int i = 0, j = 0;
}bank;

// ���� ���̵� ����� (O)
// ���� �����
// �� �ֱ�
// �� ������
// �� ������
// �α���
// �׼� Ȯ��
// ��� �ٲٱ�
// ���� ���ֱ�
// ��� Ȯ��

bank bank1;

void makeBankID() { // ���� ���̵� �����
	printf("----------���� ���̵� �����----------\n");
	printf("����� �̸�: ");
	scanf("%s", bank1.people[bank1.j].userName);
	printf("Id: ");
	scanf("%s", bank1.people[bank1.j].id);
re:
	printf("password: ");
	for (int k = 0;; k++) {
		bank1.people[bank1.j].password[k] = getch();
		if (bank1.people[bank1.j].password[k] == 13) {
			break;
		}
		printf("*");
	}
	printf("\n");
	char bankEx[30] = { 0, };
	printf("�ѹ� �� �Է��� �ּ���: ");
	for (int k = 0;; k++) {
		bankEx[k] = getch();
		if (bankEx[k] == 13) {
			break;
		}
		printf("*");
	}
	if (strcmp(bank1.people[bank1.j].password, bankEx) != 0) {
		printf("\n");
		printf("Ʋ�Ƚ��ϴ�\n��й�ȣ�� �ٽ� �������ּ���\n");
		goto re;
	}
	printf("\n��ȭ��ȣ: ");
	scanf("%d", &bank1.people[bank1.j].phoneNum);
	printf("�ּ�: ");
	scanf("%s", bank1.people[bank1.j].addresss);
	bank1.i++;
}



void makeBankBook() { // ���� ����
	int searchBankBook;
	int searchBankBookPassword;
	int num[10];
	printf("----------���� �����-----------\n");
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	printf("���̵�: ");
	scanf("%s", userId);
	for (searchBankBook = 0; strcmp(bank1.people[bank1.j].id, userId) != 0 && searchBankBook <= bank1.j; searchBankBook++);
	if (searchBankBook <= bank1.j) {
		printf("��й�ȣ: ");
		for (int k = 0;; k++) {
			pass[k] = getch();
			if (pass[k] == 13) {
				break;
			}
			printf("*");
		}
		printf("\n");
		for (searchBankBookPassword = 0; strcmp(bank1.people[bank1.j].id, userId) != 0 && searchBankBookPassword <= bank1.j; searchBankBookPassword++);
		if (searchBankBookPassword <= bank1.j) {
			printf("%s�� �ݰ����ϴ�\n", bank1.people[bank1.j].userName);
		}
	}
	printf("���¹�ȣ��: ");
	for (int zz = 0; zz < 10; zz++) {
		bank1.bank[bank1.i].id[zz] = rand() % 10;
		printf("%d", bank1.bank[bank1.i].id[zz]);
	}
	printf("\n");


	/*printf("\n");
	char bankEx[30] = { 0, };
	printf("�ѹ� �� �Է��� �ּ���: ");
	for (int k = 0;; k++) {
		bankEx[k] = getch();
		if (bankEx[k] == 13) {
			break;
		}
		printf("*");
	}
	if (strcmp(bank1.bank[bank1.i].password, bankEx) != 0) {
		printf("\n");
		printf("Ʋ�Ƚ��ϴ�\n��й�ȣ�� �ٽ� �������ּ���\n");
		goto re;
	}*/
}

int main() {
	srand(time(NULL));
	makeBankID();
	makeBankBook();


	return 0;
}