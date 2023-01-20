#include <bits/stdc++.h> // max_element, min_element

using namespace std;

int main(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	int a = *max_element(v.begin(), v.end()); // 이터레이터로 반환 
	cout << a << '\n'; // 10
	
	int b = *min_element(v.begin(), v.end());
	cout << b << '\n';
}
