// Union-Find.cpp :합집합 찾기, 서로소 알고리즘 → 여러개 노드 존재시 두개 노드선택하여 서로 같은 그래프에 속하는지 판별하는 알고리즘
//

#include <stdio.h>

int getParent(int[], int);				// 부모노드 찾기
void unionParent(int[], int, int);		// 각 부모노드를 합침
int findParent(int[], int, int);			// 같은 부모노드를 가지는지 확인

int main()
{
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5의 연결여부: %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5의 연결여부: %d\n", findParent(parent, 1, 5));
}


int getParent(int parent[], int x) {
	if (parent[x] == x)		// 자기와 부모노드가 같으면
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {		// 각 부모노드를 합침
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int findParent(int parent[], int a, int b) {			// 같은 부모노드를 가지는지 확인
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	else
		return 0;
}