// VECTOR와 pair 라이브러리를 사용한 정렬법(정렬기준이 2개이하일경우)

#include <iostream>
#include<algorithm>		//단순 배열
#include<vector>

using namespace std;		// std는 입출력 함수 사용간 std::사용을 생략해도 되도록 정의해주는 라이브러리

bool compare(pair<string, pair<int, int>>a, pair<string, pair<int, int>>b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;			//점수가 높은 사람부터 벡터 첫번째에 삽입
	}
}

int main()
{
	vector<pair<string, pair<int, int>>>v;	//한 쌍의 데이터를 pair라이브러리로 묶어 벡터에 넣음(int형과 string형)
	v.push_back(pair<string, pair<int, int>>("박승섭", pair<int, int>(90, 19950915)));
	v.push_back(pair<string, pair<int, int>>("박찬호", pair<int, int>(85, 19930925)));
	v.push_back(pair<string, pair<int, int>>("박근원", pair<int, int>(70, 19950903)));

	sort(v.begin(), v.end(), compare);		// 벡터의 첫번째부터, 마지막까지 정렬
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';		//second는 pair의 두번째 값:string >> 즉, 이름
	}
}