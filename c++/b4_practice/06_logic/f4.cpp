#include<bits/stdc++.h> // �ð���� & �ݽð���� ȸ�� 
using namespace std;

vector<int> v;

int main(){
	for (int i=1; i<10; ++i) v.push_back(i); // 1 2 3 4 5 6 7 8 9
	//rotate(v.begin(),v.begin()+1, v.end());
	// 2 3 4 5 6 7 8 9 1 ������ �� �� �̷���
	// rotate(v.begin(),v.begin() + v.size() - 1, v.end());
	rotate(v.begin(),v.end() - 1, v.end());
	// 9 1 2 3 4 5 6 7 8 �ڷ� �� �� �̷���
	for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
	cout << ' ' << *it;
	cout << '\n';
}
