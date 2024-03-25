#include<bits/stdc++.h> // 백준 3474 2K (시간초과 too much)
using namespace std;

int a, n, t, two, five;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		cin >> n;

		two = 0;
		// for (int i = 2; i <= n; i+=2) {
		// 	a = i;
		// 	while(a % 2 == 0) {
		// 		a /= 2;
		// 		two++;
		// 	}
		// }
		for(int i = 2; i <= n; i*=2) {
			two += n/i; // 2로 나누어떨어지는 개수, 2*2로 나누어 떨어지는 개수, .....
		}

		five = 0;
		// for (int i = 5; i <= n; i+=5) {
		// 	a = i;
		// 	while(a % 5 == 0) {
		// 		a /= 5;
		// 		five++;
		// 	}
		// }
		for(int i = 5; i <= n; i*=5) {
			five += n/i; // 5로 나누어떨어지는 개수, 5*5로 나누어 떨어지는 개수, .....
		}

		cout << min(two, five) << "\n";
	
	}
	return 0;
}
