// Binary Tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//이진트리 탐색방법: 1. 전위순회 2. 중위순회 3. 후위순회
//완전 이진트리가 아닌이상 배열이 아닌 포인터를 사용해야됨->배열을 사용하면 메모리 낭비
//후위 순회 방식을 많이 사용함

#include <iostream>

using namespace std;

const int number = 15;

//하나의 노드 정보를 선언
typedef struct node* treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
}node;

//전위 순회 구현
void preorder(treePointer ptr) {
    if (ptr) {  //ptr이 널값이 아니라면
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}


//중위 순회 구현
void inorder(treePointer ptr) {
    if (ptr) {
        preorder(ptr->leftChild);
        cout << ptr->data << ' ';
        preorder(ptr->rightChild);
    }
}

//후위 순회 구현
void postorder(treePointer ptr) {
    if (ptr) {
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}


int main()
{
    //노드 생성
    node nodes[number + 1];
    for (int i = 1; i <= number; i++) {//데이터 삽입
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    //그래프 구현
    for (int i = 1; i <= number; i++) {
        if (i % 2 == 0) 
            nodes[i / 2].leftChild = &nodes[i];
        else
            nodes[i / 2].rightChild = &nodes[i];
        }

    //1번 노드를 기준으로 전위순회 실시
    preorder(&nodes[1]);
    return 0;
}