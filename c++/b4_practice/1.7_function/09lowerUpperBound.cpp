#include<bits/stdc++.h> // lower bound & upper bound

// lower bound & upper bound�� �� ������ �� ��� �� 

using namespace std;
typedef long long ll;

int main(){
	vector<int> a {1, 2, 3, 3, 3, 4};
	
	cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 2 -> 3�� ó�� ������ ��ġ 
	
	cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 5 -> 3�� �� ������ ������ ���� ��ġ 
	
	return 0;
}

// ���ͷ����͸� ��ȯ�ϹǷ� �迭 ��ü�� ���� �ּڰ��� ���� �ʿ䰡 ���� 
