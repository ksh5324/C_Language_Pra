#include <stdio.h>



int main() {

    char arr[30] = { 0 };

    int i;

    char j;

    printf("�ʱⰪ�� �Է��ϼ���: ");

    scanf("%s", arr);

    while (1) {

        printf("��ġ�� ���� �ε���: ");

        scanf("%d", &i);

        getchar();

        printf("�ٲ� ��: ");

        scanf("%c", &j);

        arr[i - 1] = j;

        printf("%s\n", arr);

    }

    return 0;

}