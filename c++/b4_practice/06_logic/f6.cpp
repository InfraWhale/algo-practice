#include <bits/stdc++.h> // �迭 �� ���� ū ���, ���� ��� 
using namespace std;

	int main(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int a = *max_element(v.begin(), v.end());
	int b = *min_element(v.begin(), v.end()); 
	
	cout << a << '\n'; // 10
	cout << b << '\n'; // 10
}
