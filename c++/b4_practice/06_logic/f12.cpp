#include <bits/stdc++.h> // Ŀ���� ���� - �������� 
using namespace std;

vector<int> v;

bool cmp(int a, int b){
	return a > b; // �տ� ���°� �� ũ�� -> ��������...? �� �̷��� ����ϸ� ���� ������? 
}

int main(){
	for(int i= 1; i <= 6; i++) v.push_back(i);
	
	for(int i : v) cout << i << ' ';
	cout << "\n"; 
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i : v) cout << i << ' ';
}
