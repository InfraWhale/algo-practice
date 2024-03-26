#include<bits/stdc++.h> // 백준 1436 2M 정답
using namespace std;
// 문제가 주어지면 일단 무식하게 풀 수 있을지 생각을 해야 함
// 경우의 수가 1000만 이하면 무식 가능

int n;

int main(){

	cin >> n;
	int i = 666;
	for(;; i++) { // i를 올리면서 무한루프
		if(to_string(i).find("666") != string::npos) {
			n--; // 결과가 있을 시 n 줄임
		// cout << i << "\n";		
		}
		if(n == 0)break;
	}
	cout << i << "\n";
	return 0;
}
