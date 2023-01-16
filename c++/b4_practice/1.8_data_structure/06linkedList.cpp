#include <bits/stdc++.h> // 연결 리스트 
using namespace std;
list<int> a;

void print(list <int> a){
	for(auto it : a) cout << it << " ";
	cout << '\n';
}

int main(){
	for(int i = 1; i <= 3; i++)a.push_back(i);
	for(int i = 1; i <= 3; i++)a.push_front(i);
	
	auto it = a.begin(); // begin() -> beginning iterator 반환(여기선 0번째 위치)   
	it++;
	a.insert(it, 1000); // it 위치에 1000 추가 (기존꺼 삭제하는게 아니라 밀어냄) 
	print(a);
	
	it = a.begin(); 
	it++;
	a.erase(it);
	print(a);
	
	a.pop_front();
	a.pop_back();
	print(a);
	
	cout << a.front() << " : " << a.back() << '\n';
	a.clear();
	return 0;
}
