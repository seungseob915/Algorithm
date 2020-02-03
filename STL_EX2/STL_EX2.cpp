// VECTOR와 pair 라이브러리를 사용한 정렬법

#include <iostream>
#include<algorithm>		//단순 배열
#include<vector>

using namespace std;		// std는 입출력 함수 사용간 std::사용을 생략해도 되도록 정의해주는 라이브러리


int main()
{
	vector<pair<int, string>>v;	//한 쌍의 데이터를 pair라이브러리로 묶어 벡터에 넣음(int형과 string형)
	v.push_back(pair<int, string>(90, "박승섭"));
	v.push_back(pair<int, string>(85, "박찬호"));
	v.push_back(pair<int, string>(82, "박근원"));

	sort(v.begin(), v.end());		// 벡터의 첫번째부터, 마지막까지 정렬
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';		//second는 pair의 두번째 값:string >> 즉, 이름
	}
}