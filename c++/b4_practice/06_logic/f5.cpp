#include <bits/stdc++.h> // �迭�� �� 
using namespace std;

int main(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(v.begin(), v.end(), 0); // �� ��° ���ڴ� ���� �ʱⰪ 
	cout << sum << '\n'; // 55
}
