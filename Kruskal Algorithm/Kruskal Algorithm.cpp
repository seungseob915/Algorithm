// Kruskal Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 가장 적은 비용으로 모든 노드를 연결하기 위한 알고리즘(최소 비용 신장 트리 구성)
// 간선의 거리가 짧은 순서대로 그래프에 포함: 간선정보를 오름차순으로 정렬 후 그래프에 포함
// 단, 사이클이 형성되면 안됨

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int[], int);  //부모노드 찾기
void unionParent(int [], int, int);  //노드 연결
int find(int[], int, int);  //부모 노드가 같은지 확인

//간선 클래스 선언
class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator < (Edge& edge) {      //거리가 작은 것부터 정렬되도록
        return this->distance < edge.distance;
    }
};

int main()
{
    const int n = 7;
    int m = 11;

    vector<Edge> v;
    v.emplace_back(Edge(1, 7, 12));
    v.emplace_back(Edge(4, 7, 13));
    v.emplace_back(Edge(1, 5, 17));
    v.emplace_back(Edge(3, 5, 20));
    v.emplace_back(Edge(2, 4, 24));
    v.emplace_back(Edge(1, 4, 28));
    v.emplace_back(Edge(3, 6, 37));
    v.emplace_back(Edge(5, 6, 45));
    v.emplace_back(Edge(2, 5, 62));
    v.emplace_back(Edge(1, 2, 67));
    v.emplace_back(Edge(5, 7, 73));

    sort(v.begin(), v.end());
    
    //각 노드에 숫자를 저장
    int set[n];
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }

    //거리의 합을 0으로 초기화
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        //사이클 발생하지 않을때 그래프에 포함한다
        if (!find(set, v[i].node[0]-1, v[i].node[1]-1)) {
            sum += v[i].distance;
            unionParent(set, v[i].node[0]-1, v[i].node[1]-1);
        }
    }
    printf("%d\n", sum);
}

int getParent(int set[], int a) {  //부모노드 찾기
    if (set[a] == a)
        return a;
    return set[a]=getParent(set, set[a]);
}

void unionParent(int set[], int a, int b) {  //노드 연결
    a = getParent(set, a);
    b = getParent(set, b);

    if (a > b)
        set[a] = b;
    else set[b] = a;
}

int find(int set[], int a, int b) {  //부모 노드가 같은지 확인
    a = getParent(set, a);
    b = getParent(set, b);

    if (a == b)
        return 1;
    else return 0;
}