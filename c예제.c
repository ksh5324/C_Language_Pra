#define _CRT_SECURE_NO_WARNINGS //scanf ���
#include <stdio.h>
#include <Windows.h> //������ ������ ���� �� �ְ� �ϱ� ���ؼ�
#include <string.h> //strcmp, strcpy, memcpy
#include <conio.h> //getch

int i = 0; // ������ ����� �˷��ִ� ����

typedef struct _p {
    char name[20];
    int price;
    int count;
}Pdt; //Product ��ǰ

int act[4] = { 1,2,3,4, }; //�԰�, ����, ��ġȮ��, ��ġ����
int act_s; //�԰�, ����, ��� �߿��� ���ڷ� �Է¹ޱ�

typedef struct p
{
    int position; // �� ������ �����Ѵ�. ������ ���� 10�� ���ϸ� � ���� �� �� �̻��̸� �ٸ� ����� ǥ���Ͽ� ������ ������� �������� Ȯ��
    char name[20];
}position;

void Show(Pdt* p, position position_[7][7]) //���� ��ǰ�� ��ġ�� �����ִ� �Լ�
{
    int com;

    for (int k = 0; k < 7; k++) {
        for (int j = 0; j < 7; j++) {
            if (position_[k][j].position == 1) {
                for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                if (p[com].count <= 3) { //��ǰ�� 3�� ���ϸ� ������
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                }
                if (p[com].count > 3 && p[com].count <= 10) { //��ǰ�� 3������ ���� 10�� ���ϸ� �����
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                }
                if (p[com].count > 10) { //��ǰ�� 10������ ������ �ʷϻ�
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                }
                printf("��");
            }
            else { //������ �� �ڸ��� ��� �� �׸�
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("��");
            }
        }
        printf("\n");
    }
}


int main()
{
    position abc = { 0, };
    Pdt ab = { 0, };
    char name[20];
    Pdt p[100] = { 0, };
    position position_[7][7]; // {0, ""},

    while (1)
    {
        printf("--------------------------------------------------\n");
        printf("\"1. �԰�\", \"2. ����\", \"3. Ȯ��\" \"4. ��ġ����\" \n");
        printf("--------------------------------------------------\n");
        scanf("%d", &act_s);
        //� �ൿ�� ����
        //�԰�, ����, Ȯ��, ��ġ���� �߿��� �Է¹ޱ�
        int com4;
        int com, com2;
        for (com = 0; act_s != act[com] && com < 3; com++);
        //���� �ൿ�� ���� �Է¹ް� 
        //�� ������ �����ϴ� ���� com�� ����

        int x, y; // ��ġ�� ��ġ
        int count; //�԰��� ��ǰ�� ������ �Է¹޾Ƽ� �����ִ� ����
        int mcount; //������ ��ǰ�� ������ �Է¹޾Ƽ� ���ִ� ����
        int com3;

        char tt; //��й�ȣ�� �Է¹޴� �Լ�
        char pw[100] = { "1234" }; //�԰��� �� �Է��ؾ��ϴ� ��й�ȣ ����
        char pwcom[100] = { 0, }; //��й�ȣ�� �Է¹��� ��

        switch (com) {

        case 0: //�԰�
            printf("-------------------------------------------------------\n");
            printf("\n�԰�\n\n");
            printf("password : ");

            for (int h = 0;; h++) {
                tt = getch();
                if (tt == 13) {
                    break;
                    //enter�� �Է¹޾Ҵٸ� ����������
                }
                else {
                    pwcom[h] = tt;
                    printf("*"); //���� ��й�ȣ�� �� �� ������ *�� ���̵��� �ϱ�
                }
            }
            printf("\n");

            if (strcmp(pw, pwcom) == 0) {
                printf("\n� ��ǰ�� �԰��Ͻðڽ��ϱ�? ");
                scanf("%s", p[i].name);
                printf("�� ��ǰ�� ������ ���Դϱ�? ");
                scanf("%d", &p[i].price);
                printf("��ǰ�� ������ ��Դϱ�? ");
                scanf("%d", &count);
                p[i].count += count;
                //�̹� �ִ� ��ǰ�� �߰��� �԰��� �� 
                //��ǰ�� ������ ���� �������� �ʵ��� count�� ���� ���� += ����
                printf("��ġ\n");
                scanf("%d", &x);
                scanf("%d", &y);
                //��ǰ�� ��ġ ���� �Է¹ޱ�
                position_[y - 1][x - 1].position = 1;
                strcpy(position_[y - 1][x - 1].name, p[i].name);
                printf("%s %d���� ���������� �԰�Ǿ����ϴ�.\n", p[i].name, count);
                i++;
                //���� �� ù��° ��ǰ�� ������ �Է¹޾Ҵٸ�
                //������ �԰���� �� �ι�° ��ǰ�� �Է¹ޱ� ���ؼ� i++ �� ����
                Show(&p, position_); //���� ��ǰ�� ��ġ���� Ȯ��
            }
            else {
                printf("��й�ȣ�� �߸��Ǿ����ϴ�.\n");
                //��й�ȣ�� 1234�� �ƴ� �ٸ� ���ڳ� ���ڰ� �ԷµǾ��� �� 
                //��й�ȣ�� �߸��Ǿ����� �˷��ִ� �ڵ�
            }
            break;

        case 1: //����
            printf("\n����\n\n");
            printf("� ��ǰ�� �����Ͻðڽ��ϱ�? ");
            scanf("%s", name); //������ ��ǰ�� �̸� �Է¹ޱ�
            for (com2 = 0; strcmp(name, p[com2].name) != 0 && com2 < 3; com2++);
            //com2��° ��ǰ�� �̸��� �����ϰ����ϴ� ��ǰ�� �̸��� ���� ������ �����ֱ�
            printf("��ǰ�� � �����Ͻǰǰ���? ");
            scanf("%d", &mcount); //������ ���� �Է¹ޱ�
            if (p[com2].count - mcount < 0) {
                //������ ��ŭ ��ǰ�� �������� ���ֱ�
                printf("��� �����մϴ�.\n");
            }
            p[com2].count -= mcount;
            //�Է¹��� ��ǰ�� ������ ������ ��ǰ�� ����ŭ ���ֱ�
            if (p[com2].count - mcount == 0) {
                memcpy(&p[com], &ab, sizeof(Pdt));
                memcpy(&position_[com4][com3], &abc, sizeof(position));
                //���� �Ŀ� �� ��ǰ�� ���� ������ 0����� �� ��ǰ�� ������ ���ֱ�
            }
            for (com4 = 0; com4 < 7; com4++) {
                for (com3 = 0; com3 < 7; com3++) {
                    if (strcmp(position_[com4][com3].name, name) == 0) {
                        break;
                        //��ü ������ �ϳ��� Ȯ���ϰ� �Է��� �̸��� ��ǥ�� 
                        //�� ��ǥ�� �ִ� ��ǰ�� �̸��� ���ٸ� for���� ������
                    }
                }
                if (strcmp(position_[com4][com3].name, name) == 0) {
                    break;
                    //��ü ������ �ϳ��� Ȯ���ϰ� �Է��� �̸��� ��ǥ�� 
                    //�� ��ǥ�� �ִ� ��ǰ�� �̸��� ���ٸ� for���� ������
                }
            }

            printf("%s��(��) %d�� �����ֽ��ϴ�.\n", p[com2].name, p[com2].count);
            break;

        case 2: //��ǰ ��ġ���� Ȯ��
            printf("\n��ǰ ��ġ���� Ȯ��\n\n");
            for (int k = 0; k < 7; k++) {
                for (int j = 0; j < 7; j++) { //��ü ��ǰ�� ��ġ������ ����ϴ� �ڵ�
                    if (position_[k][j].position == 1) {
                        for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                        //com��° ��ǥ�� �Ҵ�� �̸��� �Է¹��� �̸��� ���ٸ� �������� ���
                        if (p[com].count <= 3) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            //3�� ���϶�� ������
                        }
                        if (p[com].count > 3 && p[com].count <= 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            //3�� �ʰ� 10�� ���϶�� �����
                        }
                        if (p[com].count > 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            //10�� �ʰ���� �ʷϻ�
                        }
                        printf("��");
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("��");
                        //������ ĭ�� �Ͼ�� �׸�� ���
                    }
                }
                printf("\n");
            }
            break;

        case 3: //��ǰ ��ġ ����
            printf("\n��ǰ ��ġ ����\n\n");
            printf("� ��ǰ�� ��ġ�� �����Ͻðڽ��ϱ�? ");
            scanf("%s", name);
            for (com2 = 0; com2 < 7; com2++) {
                for (com3 = 0; com3 < 7; com3++) {
                    if (strcmp(position_[com2][com3].name, name) == 0) {
                        break;
                        //��ü ������ �ϳ��� Ȯ���ϰ� �Է��� �̸��� ��ǥ�� 
                        //�� ��ǥ�� �ִ� ��ǰ�� �̸��� ���ٸ� for���� ������
                    }
                }
                if (strcmp(position_[com2][com3].name, name) == 0) {
                    break;
                    //��ü ������ �ϳ��� Ȯ���ϰ� �Է��� �̸��� ��ǥ�� 
                    //�� ��ǥ�� �ִ� ��ǰ�� �̸��� ���ٸ� for���� ������
                }
            }

            for (int k = 0; k < 7; k++) {
                for (int j = 0; j < 7; j++) {
                    //��ǰ�� ��ġ�� �����ϱ� ����
                    //��ü ��ǰ�� ��ġ������ ����ϴ� �ڵ�
                    if (position_[k][j].position == 1) {
                        for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                        //com��° ��ǥ�� �Ҵ�� �̸��� �Է¹��� �̸��� ���ٸ� 
                        //if���� �ִ� ����� ������ ���
                        if (p[com].count <= 3) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            //3�� ���ϸ� ������
                        }
                        if (p[com].count > 3 && p[com].count <= 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            //3�� �ʰ� 10�� ���ϸ� �����
                        }
                        if (p[com].count > 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            //10�� �ʰ��� �ʷϻ�
                        }
                        if (k == com2 && j == com3) {
                            //������ ��ǥ��� �Է¹��� ��ġ���� �ٲ� ��ǰ�� �����Ƿ�
                            //�Ķ������� ǥ�õǵ��� �ϴ� �ڵ�
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                        }
                        printf("��");
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("��");
                        //������ ĭ�� �Ͼ�� �׸�� ���
                    }
                }
                printf("\n");
            }
            printf("\n");
            printf("(�Ķ����� ������ ��ǰ�� ��ġ)\n");
            printf("\n");
            printf("���� �����Ͻðڽ��ϱ�? ");
            //������ ��ġ �Է¹ޱ�
            scanf("%d %d", &x, &y);
            if (position_[y - 1][x - 1].position == 1) {
                printf("�� �ڸ����� �ٸ� ��ǰ�� �ֽ��ϴ�\n");
                break;
            }
            memcpy(&position_[y - 1][x - 1], &position_[com2][com3], sizeof(position));
            memcpy(&position_[com2][com3], &abc, sizeof(position));
            //������ ��ǥ�� ��ǰ�� ������ �����ϰ�
            //������� ������ �ٲ� ��ġ�� �����ϱ�

            for (int k = 0; k < 7; k++) {
                for (int j = 0; j < 7; j++) {
                    //��ǰ�� ��ġ�� �����ϰ� ���� �ٽ� �� �� ��ǰ�� ��ġ�� �����ִ� �ڵ�
                    if (position_[k][j].position == 1) {
                        for (com = 0; strcmp(position_[k][j].name, p[com].name) != 0 && com < i; com++);
                        if (p[com].count <= 3) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            //3�� ���϶�� ������
                        }
                        if (p[com].count > 3 && p[com].count <= 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            //3�� �ʰ� 10�� ���϶�� �����
                        }
                        if (p[com].count > 10) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                            //10�� �ʰ���� �ʷϻ�
                        }
                        printf("��");
                    }
                    else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        printf("��");
                        //�������� �Ͼ�� �׸�� ���
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}