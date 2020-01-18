//선택 정렬: 가장 작은것을 앞으로 서로 스와핑

#include <stdio.h>

int main() {
	int i, j, min, index, temp;
	int array[10] = {1, 3, 7, 2, 4, 5, 9, 8, 10, 6};

	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
		}
// 출력	
		for (i = 0; i < 10; i++) {
			printf("%d ", array[i]);
		}
		return 0;
}
