//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//typedef struct _m {
//    int num; //���¹�ȣ
//    int money; //�Աݵ� ��
//}Money;
//
//Money maxMoney(Money m[], int n) {
//    Money max = m[0];
//    for (int i = 1; i < n; i++) {
//        if (max.money < m[i].money)
//            max = m[i];
//    }
//    return max;
//}
//
//int main()
//{
//    Money m[5], king; //�����
//    int i;
//    for (i = 0; i < 5; i++) {
//        printf("���¹�ȣ�� �ݾ�\n");
//        m[i].num = i; //���¹�ȣ�� �ڵ� �Է�
//        scanf("%d", &m[i].money);
//    }
//    king = maxMoney(m, 5); //5���� ���������� �ѱ�
//    printf("����� %d�� %d��\n", king.num, king.money);
//    return 0;
//}