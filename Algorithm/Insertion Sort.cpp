/*
삽입 정렬: 필요할 때만 위치를 변경시킴.
시간복잡도(빅오 표기법): o(n*n), 선택, 버블정렬 중 제일 빠름, 최초에 거의 정렬되있을때는 엄청 빠름
*/

#include <stdio.h>

int main() {
	int i, j, temp;
	int array[10] = { 1, 3, 7, 2, 4, 5, 9, 8, 10, 6 };

	for (i = 0; i < 9; i++) {
		j = i;
		while (array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
			if (j < 0)
				break;
		}
	}

	// 결과 출력	
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
