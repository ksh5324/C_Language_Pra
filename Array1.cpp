#include<stdio.h>

int main() {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		printf("%d�� �л��� ��C ���� : ", i+1);
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < 5; i++) {
		if (arr[0] <= arr[i]) {
			arr[0] = arr[i];
		}
	}
	printf("�ְ� ���� : %d", arr[0]);
	return 0;
}