#include<bits/stdc++.h> // lower bound & upper bound 2

using namespace std;
typedef long long ll;

int main(){
	vector<int> a {1, 2, 3, 3, 3, 4};
	
	cout << &*lower_bound(a.begin(), a.end(), 3)<< "\n";
	cout << &*a.begin()<< "\n";
	cout << &*(a.begin() + 1)<< "\n";
	
	return 0;
}

/*
0xd21518
0xd21510
0xd21514
*/

// 주소값끼리 -를 하면 해당 주소값에서 몇번째에 이 요소가 들어있는지를 반환함 
