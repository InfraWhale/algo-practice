#include<bits/stdc++.h> // vector
using namespace std;

vector<int> v;

int main(){
	for(int i = 1; i <= 10; i++)
		v.push_back(i); // 맨 뒤에 요소 더함
		 
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	v.pop_back(); // 맨 뒤 요소 지움 
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	v.erase(v.begin(), v.begin() + 1); // 해당 범위 요소 지움
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	auto a = find(v.begin(), v.end(), 10); // 해당 원소 찾으면 해당 원소의 반복자 반환, 존재하지 않으면 해당 범위의 마지막 end() 반복자 반환 
	cout << *v.end() << "\n"; // * 연산자를 오버로딩해서 마치 포인터처럼 동작하게 한거...? 
	
	if(a == v.end()) 
		cout << "not found" << "\n";
	
	fill(v.begin(), v.end(), 10); // 배열 지정 범위를 3번째에 지정한 값으로 채움 
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	v.clear(); // 배열 초기화 
	cout << "아무것도 없을까?\n";
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	return 0;
}
