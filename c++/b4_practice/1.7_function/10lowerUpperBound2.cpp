#include<bits/stdc++.h> // lower bound & upper bound 2

using namespace std;
typedef long long ll;

int main(){
	vector<int> a;
	for(int i =1 ; i<= 3; i++)a.push_back(i);
	for(int i =5 ; i<= 10; i++)a.push_back(i); // 1 2 3 5 6 7 8 9 10
	
	cout << lower_bound(a.begin(), a.end(), 4) - a.begin() << "\n"; // 3 -> 4가 없으므로 4 이상인 첫번째 지점 반환 
	return 0;
}
