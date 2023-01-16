#include <bits/stdc++.h> // 이터레이터
// -> 컨테이너에 저장되어 있는 요소의 주소를 가리키는 개체
// -> 포인터를 일반화한 것 

using namespace std;
vector<int> v;

int main(){
	
	for(int i = 1; i <= 5; i++)v.push_back(i);
	
	for(int i = 0; i < 5; i++){
		cout << i << "번째 요소 : " << *(v.begin() + i) << "\n"; // begin() : 컨테이너의 시작위치 
		cout << &*(v.begin() + i) << '\n';
	}
	
	for(auto it = v.begin(); it != v.end(); it++){ // end() : 컨테이너의 끝 다음위치 
		cout << *it << ' ';
	}
	cout << '\n';
	
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){ //::는 스코프 지정자 
		cout << *it << ' ';
	}
	
	auto it = v.begin();
	advance(it, 3); //advance() : iterator(it)를 cnt(3)까지 증가 
	cout << '\n';
	cout << *it << '\n';
	// cout << v.begin() << '\n'; //에러
}
