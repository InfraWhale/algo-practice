#include <bits/stdc++.h> // accumulate 

using namespace std;

int main(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(v.begin(), v.end(), 0); // 세 번쨰 인자는 합의 초기값 
	cout << sum << '\n'; // 55
	
	sum = accumulate(v.begin(), v.end(), 10);
	cout << sum << '\n'; // 65
}
