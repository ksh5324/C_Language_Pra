
#include<stdio.h>
#include<Windows.h>
char arr[12][31] = {
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   0,0,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,0
   },
   {
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1,1,1,1,1,
   1,1,1
   },
};

void date_show();
void plus(int month, int date_);
void print_date(int month, int date_);
void del(int month, int date_);
void print_month(int month);

struct date
{
    char todo[10][50];
    int cnt = 0;
};

struct date a[12][31];

int main() {
    int month, day, date_;
    int n;
    while (1) {
        printf("\n1.�߰�, 2.����, 3.���ϴ� �� ���, 4.���ϴ� �� ���, 5.�޷�\n");
        scanf("%d", &n);
        if (n == 1 || n == 2 || n == 4) {
            printf("���� ���� ��� ����� �������ּ���\n[ex)4�� 5 -> 4 5]\n");
            scanf("%d %d", &month, &date_);
            if (arr[month-1][date_-1] == 0) {
                printf("���� ��¥�Դϴ�\n");
            }
        }
        else if (n == 3) {
            printf("����(��)�� �Է����ּ���\n[ex)4�� -> 4]\n");
            scanf("%d", &month);
            if (month-1 > 12) {
                printf("���� ���Դϴ�\n");
            }
        }
        switch (n) {
        case 1: plus(month, date_); break;
        case 2: del(month, date_); break;
        case 3: print_month(month); break;
        case 4: print_date(month, date_); break;
        case 5: date_show(); break;
        default: system("cls");
        }
    }
    return 0;
}

void plus(int month, int date_) {
    printf("�߰��� ���� �Է����ּ���\n");
    scanf("%s", a[month - 1][date_ - 1].todo[a[month - 1][date_ - 1].cnt]);
    a[month - 1][date_ - 1].cnt++;
}

void print_date(int month, int date_) {
    for (int i = 0; i < a[month - 1][date_ - 1].cnt; i++) {
        printf("%d. %s\n", i + 1, a[month - 1][date_ - 1].todo[i]);
    }
}

void print_month(int month) {
    printf("----------------------\n");
    for (int i = 0; i < 31; i++) {
        if (a[month - 1][i].cnt == 0) {
            continue;
        }
        printf("[%d��]\n", i+1);
        print_date(month, i+1);
        printf("----------------------\n");
    }
}

void del(int month, int date_) {
    int t;
    print_date(month, date_);
    printf("���° ���� ����ڽ��ϱ�\n");
    scanf("%d", &t);
    char* temp;
    for (int i = t - 1; i < a[month - 1][date_ - 1].cnt; i++) {
        temp = a[month - 1][date_ - 1].todo[i];
        *a[month - 1][date_ - 1].todo[i] = *a[month - 1][date_ - 1].todo[i + 1];
        *a[month - 1][date_ - 1].todo[i + 1] = *temp;
    }
    a[month-1][date_-1].cnt--;
}

void date_show() {
    printf("�ؾ������� �ִ� ��¥���� ���������� �������ϴ�.\n");
    int count = 2;
    for (int i = 0; i < 12; i++) {
        printf("[%d��]\n", i + 1);
        for (int k = 0; k < count; k++) {
            printf("    ");
        }
        for (int j = 0; j < 31; j++) {
            if (arr[i][j] == 0) {
                break;
            }
            if (a[i][j].cnt != 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            printf("%3d ", j + 1);
            count++;
            if (count == 6) {
                count = 0;
                printf("\n");
            }
        }
        printf("\n---------------------------\n");
    }
}