#include <bits/stdc++.h> // ���ͷ�����
// -> �����̳ʿ� ����Ǿ� �ִ� ����� �ּҸ� ����Ű�� ��ü
// -> �����͸� �Ϲ�ȭ�� �� 

using namespace std;
vector<int> v;

int main(){
	
	for(int i = 1; i <= 5; i++)v.push_back(i);
	
	for(int i = 0; i < 5; i++){
		cout << i << "��° ��� : " << *(v.begin() + i) << "\n"; // begin() : �����̳��� ������ġ 
		cout << &*(v.begin() + i) << '\n';
	}
	
	for(auto it = v.begin(); it != v.end(); it++){ // end() : �����̳��� �� ������ġ 
		cout << *it << ' ';
	}
	cout << '\n';
	
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){ //::�� ������ ������ 
		cout << *it << ' ';
	}
	
	auto it = v.begin();
	advance(it, 3); //advance() : iterator(it)�� cnt(3)���� ���� 
	cout << '\n';
	cout << *it << '\n';
	// cout << v.begin() << '\n'; //����
}