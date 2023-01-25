#include <bits/stdc++.h> // 쓰지 못하는 변수명2

using namespace std;
#define end aaa // end를 사용하고 있으므로 재할당 불가 
vector<int> v;

int main() {
	for(int i : {1, 2, 3, 4, 5}) v.push_back(i);
	sort(v.begin(), v.end());
}
