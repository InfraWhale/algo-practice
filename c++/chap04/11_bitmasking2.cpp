#include<bits/stdc++.h> // 비트마스킹 2
using namespace std;

// 매개변수 전달
const int n = 4;
string a[n] = {"사과", "딸기", "포도", "배"};

void go(int num) {
	string ret = "";
	for(int i = 0; i < 4; i++) {
		if(num & (1 << i)) ret += a[i] + " ";
	}
	cout << ret << '\n';
	return;
}

int main() {   
	for(int i = 1; i < n; i++) {
		go(1 | (1 << i));
	}
	
    return 0;
}

