#include<bits/stdc++.h> // define

using namespace std;
#define PI 3.14159 // 상수 정의 
#define loop(x,n) for(int x = 0; x < n; x++) //매크로 정의 

int main(){
	cout << PI << '\n';
	int sum = 0;
	loop(i, 10){
		sum += i;
	}
	cout << sum << '\n';
	return 0;
}

