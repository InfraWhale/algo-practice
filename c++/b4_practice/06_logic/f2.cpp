#include<bits/stdc++.h> // lower_bound & upper_bound 2
using namespace std;
typedef long long ll;
int main(){
	vector<int> a;
	for(int i =1 ; i<= 3; i++)a.push_back(i);
	for(int i =5 ; i<= 10; i++)a.push_back(i);
	
	cout << lower_bound(a.begin(), a.end(), 4) - a.begin() << "\n"; // 3
	cout << upper_bound(a.begin(), a.end(), 4) - a.begin() << "\n"; // 3
	
	return 0;
}
