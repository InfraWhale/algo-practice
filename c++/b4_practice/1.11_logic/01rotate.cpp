#include<bits/stdc++.h> // rotate

using namespace std;
vector<int> v;

int main(){
	for (int i=1; i<10; ++i) v.push_back(i); // 1 2 3 4 5 6 7 8 9
		
	rotate(v.begin(), v.begin()+1, v.end()); // 안에 들어가는건 모두 이터레이터 
	// 2 3 4 5 6 7 8 9 1 앞으로 할 땐 이렇게
	
	for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
	
	rotate(v.begin(), v.begin() + v.size() - 1, v.end());
	// 9 1 2 3 4 5 6 7 8 뒤로 갈 땐 이렇게
	
	for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}
