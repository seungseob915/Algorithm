// Dynamic Programming Tiling.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://www.acmicpc.net/problem/14852

#include <iostream>

long long int d[2][1000001];

long long int dp(int x) {
    d[0][0] = 1;
    d[0][1] = 2;
    d[0][2] = 7;
    d[1][2] = 0;

    for (int i = 3; i <= x; i++) {
        d[1][i] = (d[1][i - 1] + d[0][i-3]) % 1000000007;
        d[0][i] = (2 * d[0][i - 1] + 3 * d[0][i - 2] + 2 * d[1][i]) % 1000000007;
    }
    return d[0][x];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", dp(n));
}