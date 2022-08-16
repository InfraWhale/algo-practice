#include <bits/stdc++.h> // 배열 부분 회전 
using namespace std;
vector<int> v;
int main(){
	for(int i= 1; i <= 6; i++) v.push_back(i);
	
	for(int i : v) cout << i << ' ' ;
	cout << "\n";
	
	int i = 1;
	int temp = v[i];
	
	v[i] = v[i + 1];
	v[i + 1] = v[i + 2];
	v[i + 2] = v[i + 3];
	v[i + 3] = temp;
	
	for(int i : v) cout << i << ' ';
}
