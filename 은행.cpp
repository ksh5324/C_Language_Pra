#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

FILE* fp[20];

FILE* fpp[10];


struct bankBook
{
	char Name[10];
	char id[30];
	char password[30];
	int money = 0;
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
	struct people people[10];
	int i = 0, j = 0;
}bank;

// ���� ���̵� ����� (O)
// ���� ����� (0)
// �� �ֱ� 
// �� ������
// �� ������
// �׼� Ȯ��
// ��� �ٲٱ�
// ���� ���ֱ�
// ��� Ȯ�� (X)

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



int makeBankBook() { // ���� ����
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
		else {
			return 0;
		}
	}
	printf("���¹�ȣ��: ");
	for (int zz = 0; zz < 10; zz++) {
		bank1.bank[bank1.i].id[zz] = rand() % 10;
		printf("%d", bank1.bank[bank1.i].id[zz]);
	}
	printf("\n");
	printf("�����̸�: ");
	scanf("%s", bank1.bank[bank1.i].Name);
re:
	printf("��й�ȣ: ");
	for (int k = 0;; k++) {
		bank1.bank[bank1.i].password[k] = getch();
		if (bank1.bank[bank1.i].password[k] == 13) {
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
	if (strcmp(bank1.bank[bank1.i].password, bankEx) != 0) {
		printf("\n");
		printf("Ʋ�Ƚ��ϴ�\n��й�ȣ�� �ٽ� �������ּ���\n");
		goto re;
	}
	bank1.i++;
	printf("\n������ �����Ǿ����ϴ�\n");
	return 0;
}

int checkMoney() { // �׼� Ȯ��
	int searchBankBook;
	int searchBankBookPassword;
	int searchBankBookPassword2;
	int num[10];
	char pass2[30] = { 0, };
	printf("\n----------�׼� Ȯ���ϱ�-----------\n");
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	char Name[30] = { 0, };
	int bankBook;
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
		if (strcmp(bank1.people[searchBankBook].password, pass) == 0) {
			printf("%s�� �ݰ����ϴ�\n", bank1.people[searchBankBook].userName);
		}
		else {
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ�\n");
			return 0;
		}
	}
	else {
		printf("���� ���̵��Դϴ�\n");
		return 0;
	}
	printf("������ �������ּ���: ");
	scanf("%s", Name);
	for (bankBook = 0; strcmp(bank1.bank[bankBook].Name, Name) != 0 && bankBook <= bank1.i; bankBook++);
	if (bankBook <= bank1.i) {
		printf("��й�ȣ: ");
		for (int k = 0;; k++) {
			pass2[k] = getch();
			if (pass2[k] == 13) {
				break;
			}
			printf("*");
		}
		if (strcmp(pass2, bank1.bank[bankBook].password) == 0) {
			printf("\n�ܾ�: ");
			printf("%d", bank1.bank[bankBook].money);
		}
		else {
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ�\n");
		}
		
	}
	else {
		printf("���� �����Դϴ�\n");
	}
	return 0;
}

int putMoney() {
	int searchBankBook;
	int searchBankBookPassword, money = 0;
	int num[10];
	printf("\n----------�� �ֱ�-----------\n");
	char pass2[30] = { 0, };
	char userId[30] = { 0, };
	char pass[30] = { 0, };
	char Name[30] = { 0, };
	int bankBook;
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
		if (strcmp(bank1.people[searchBankBook].password, pass) == 0) {
			printf("%s�� �ݰ����ϴ�\n", bank1.people[searchBankBook].userName);
		}
		else {
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ�\n");
			return 0;
		}
	}
	else {
		printf("���� ���̵��Դϴ�\n");
		return 0;
	}
	printf("������ �������ּ���: ");
	scanf("%s", Name);
	for (bankBook = 0; strcmp(bank1.bank[bankBook].Name, Name) != 0 && bankBook <= bank1.i; bankBook++);
	if (bankBook <= bank1.i) {
		printf("��й�ȣ: ");
		for (int k = 0;; k++) {
			pass2[k] = getch();
			if (pass2[k] == 13) {
				break;
			}
			printf("*");
		}
		if (strcmp(pass2, bank1.bank[bankBook].password) == 0) {
			printf("\n���� �ݾ�: ");
			int result;
			scanf("%d", &result);
			bank1.bank[bankBook].money += result;
			printf("%d��\n", bank1.bank[bankBook].money);
			printf("�߰� �Ǿ����ϴ�\n");
		}
		else {
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ�\n");
		}

	}
	else {
		printf("���� �����Դϴ�\n");
	}
	return 0;

}

void makeFile() {
	fp[0] = fopen("����1.txt", "w");
	fp[1] = fopen("����2.txt", "w");
	fp[2] = fopen("����3.txt", "w");
	fp[3] = fopen("����4.txt", "w");
	fp[4] = fopen("����5.txt", "w");
	fp[5] = fopen("����6.txt", "w");
	fp[6] = fopen("����7.txt", "w");
	fp[7] = fopen("����8.txt", "w");
	fp[8] = fopen("����9.txt", "w");
	fp[9] = fopen("����10.txt", "w");
	fp[10] = fopen("����11.txt", "w");
	fp[11] = fopen("����12.txt", "w");
	fp[12] = fopen("����13.txt", "w");
	fp[13] = fopen("����14.txt", "w");
	fp[14] = fopen("����15.txt", "w");
	fp[15] = fopen("����16.txt", "w");
	fp[16] = fopen("����17.txt", "w");
	fp[17] = fopen("����18.txt", "w");
	fp[18] = fopen("����19.txt", "w");
	fp[19] = fopen("����20.txt", "w");

	fpp[0] = fopen("���̵�1.txt", "w");
	fpp[1] = fopen("���̵�2.txt", "w");
	fpp[2] = fopen("���̵�3.txt", "w");
	fpp[3] = fopen("���̵�4.txt", "w");
	fpp[4] = fopen("���̵�5.txt", "w");
	fpp[5] = fopen("���̵�6.txt", "w");
	fpp[6] = fopen("���̵�7.txt", "w");
	fpp[7] = fopen("���̵�8.txt", "w");
	fpp[8] = fopen("���̵�9.txt", "w");
	fpp[9] = fopen("���̵�10.txt", "w");
}

int main() {
	makeFile();
	srand(time(NULL));
	makeBankID();
	makeBankBook();
	putMoney();
	checkMoney();

	return 0;
}