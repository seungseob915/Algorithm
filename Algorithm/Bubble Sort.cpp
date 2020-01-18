/*
버블 정렬: 기준점에서 바로 우측에 있는 것을 비교하여 1개씩 바꿈, 뒤에서부터 정렬됨.
시간복잡도(빅오 표기법): o(n*n) but, 선택정렬보다 느림 ㅡ> 그이유는, 옆에것과 항상 연산 후 매번 교체해야하기 때문 
*/

#include <stdio.h>

int main() {
	int i, j, temp;
	int array[10] = { 1, 3, 7, 2, 4, 5, 9, 8, 10, 6 };

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	// 결과 출력	
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
