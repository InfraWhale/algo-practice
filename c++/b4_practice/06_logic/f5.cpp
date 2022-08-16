#include <bits/stdc++.h> // 배열의 합 
using namespace std;

int main(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(v.begin(), v.end(), 0); // 세 번째 인자는 합의 초기값 
	cout << sum << '\n'; // 55
}
