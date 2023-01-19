#include<bits/stdc++.h> // lower bound & upper bound 5

using namespace std;
typedef long long ll;

vector<int> a {1, 2, 3, 3, 3, 3, 4, 100};

int main(){
	cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3)<< "\n"; // 3 몇개인지 구하기 
	
	return 0;
}
