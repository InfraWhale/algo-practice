#include<bits/stdc++.h> // lower bound & upper bound

// lower bound & upper bound는 꼭 정렬한 후 써야 함 

using namespace std;
typedef long long ll;

int main(){
	vector<int> a {1, 2, 3, 3, 3, 4};
	
	cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 2 -> 3이 처음 등장한 위치 
	
	cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 5 -> 3이 맨 마지막 등장한 다음 위치 
	
	return 0;
}

// 이터레이터를 반환하므로 배열 자체의 원본 주솟값을 빼줄 필요가 있음 
