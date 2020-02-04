// Algorithm_EX1(13).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<algorithm>

using namespace std;
bool compare(string, string);
int getSum(string);

string a[50];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, compare);

	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
}


bool compare(string a, string b) {
	//길이가 다른경우 짧은 단어가 먼저
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	//길이가 같은경우 a의 숫자합과 b의 숫자합 비교
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		//글자에 포함된 숫자의 합이 다르다면
		if (aSum != bSum)
			return aSum < bSum;
		else {
			return a < b;
		}
	}
}

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9)
			sum += a[i] - '0';
	}
	return sum;
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
