#include<bits/stdc++.h> // vector
using namespace std;

vector<int> v;

int main(){
	for(int i = 1; i <= 10; i++)
		v.push_back(i); // �� �ڿ� ��� ����
		 
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	v.pop_back(); // �� �� ��� ���� 
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	v.erase(v.begin(), v.begin() + 1); // �ش� ���� ��� ����
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	auto a = find(v.begin(), v.end(), 10); // �ش� ���� ã���� �ش� ������ �ݺ��� ��ȯ, �������� ������ �ش� ������ ������ end() �ݺ��� ��ȯ 
	cout << *v.end() << "\n"; // * �����ڸ� �����ε��ؼ� ��ġ ������ó�� �����ϰ� �Ѱ�...? 
	
	if(a == v.end()) 
		cout << "not found" << "\n";
	
	fill(v.begin(), v.end(), 10); // �迭 ���� ������ 3��°�� ������ ������ ä�� 
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	v.clear(); // �迭 �ʱ�ȭ 
	cout << "�ƹ��͵� ������?\n";
	
	for(int a : v) 
		cout << a << " ";
	cout << "\n";
	
	return 0;
}
