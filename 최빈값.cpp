#include <stdio.h>

#include <stdlib.h>

#include<time.h>

#include<Windows.h>

int main()

{

    int arr[10] = { 0 };

    int arr2[10] = { 0 };

    int j, k = 0;

    int result = 0;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {

        printf("%d��° ��: %d\n", i + 1, arr[i] = rand() % 10 + 1);

    }

    for (int i = 0; i < 10; i++) {

        j = arr[i];

        arr2[j - 1] += 1;

    }

    for (int i = 1; i < 10; i++) {

        if (result < arr2[i]) {

            result = arr2[i];

            k++;

        }

    }

    printf("���� ���� ���� ��: %d\nȽ��: %d\n", arr[k], result);

    return 0;

}



