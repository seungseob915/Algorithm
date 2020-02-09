// Dynamic Programming Tiling(3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://www.acmicpc.net/problem/2133

#include <iostream>

int d[31];

int dp(int x) {
    if (x == 0) //아무것도 놓지 않는 방법
        return 1;
    if (x == 1)
        return 0;
    if (x == 2)
        return 3;
    if (d[x] != 0) 
        return d[x];
    int result = 3 * dp(x - 2);
    for(int i=3;i<=x;i++){
        if (i % 2 == 0)
            result += 2 * dp(x - i);
    }
    return d[x]=result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", dp(n));
}