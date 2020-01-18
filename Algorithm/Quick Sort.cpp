/*
퀵 정렬: 대표적인 분할 정복 알고리즘으로, 특정한 값을 기준으로 나누어서 반복적 계산하는 알고리즘.
시간복잡도(빅오 표기법): o(N*logN). 굉장히 빠름, pivot(피봇:기준점) 사용
but, 최악의 시간복잡도는 o(N^2): 이미 정렬이 다되어있을때
*/


#include <stdio.h>

int number = 10;
int data[] = { 1, 3, 7, 2, 4, 5, 9, 8, 10, 6 };

void quickSort(int *data, int start, int end) {
	if (start >= end) { //원소가 1개인경우
		return;
	}

	int key = start; // 키(pivot)는 첫번째 원소
	int i = start + 1;		//i는 왼쪽출발지점
	int j = end;			//j는 오른쪽출발지점
	int temp;

	while (i <= j) {		//엇갈릴 때 까지 반복
		while (data[i] <= data[key] && i <= end) {
			i++;
		}
		while (data[j] >= data[key] && j> start) {		//key 값보다 작은값을 만날때까지 연산
			j--;
		}
		if (i > j) {	//현재 엇갈린 상태이면 키값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j+1, end);
}

int main() {

	quickSort(data, 0, number - 1);

	// 결과 출력	
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}
