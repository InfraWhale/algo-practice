#include<bits/stdc++.h> // lower bound & upper bound 4

using namespace std;
typedef long long ll;
vector<int> a {1, 2, 3, 3, 4, 100};

int main(){
	cout << *lower_bound(a.begin(), a.end(), 100)<< "\n"; // 값 자체 출력 

	return 0;
}
