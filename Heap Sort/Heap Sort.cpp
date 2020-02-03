/* Heap Sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
시간복잡도: O(nlogn)	
*/

#include <stdio.h>

void max_Heapify(int);
int number = 9;
int heap[9] = { 7,6,5,8,10,5,9,1,6 };

int main()
{
	int i = number - 1;
	max_Heapify(number);

	// 크기를 줄여가며 힙정렬 (오름차순 구성) → 제일큰 데이터를 마지막 배열로 옮기고 제외시킨후 다시 히피파이 이후 다시 힙정렬 재귀반복 
	do {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		i--;
		max_Heapify(i);
	} while (i > 0);
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}

//힙 구조 생성(MAX Heapify) o(nlogn)
void max_Heapify(int length) {
	for (int root = length / 2 - 1; root >= 0; root--) {
		int leaf1 = 2 * root + 1;
		int leaf2 = 2 * root + 2;
		if (leaf2 >= length)	leaf2 = leaf1;

		if (heap[root] < heap[leaf1] || heap[root] < heap[leaf2]) {	//자식이 부모보다 크면
			if (heap[leaf1] >= heap[leaf2]) {
				int temp = heap[root];
				heap[root] = heap[leaf1];
				heap[leaf1] = temp;
			}
			else {
				int temp = heap[root];
				heap[root] = heap[leaf2];
				heap[leaf2] = temp;
			}
		}
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
