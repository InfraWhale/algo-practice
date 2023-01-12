#include <bits/stdc++.h> // 오버플로
 
using namespace std;

int main(){
	int a = 2147483647;
	cout << a << '\n';
	
	a++;
	cout << a << '\n'; // 최댓값에서 1 더했더니 최솟값으로 돌아가버림. -> UB(Unexpected Behavior) 
}

