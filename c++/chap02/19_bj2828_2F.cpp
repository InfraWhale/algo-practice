#include<bits/stdc++.h> // 백준 2828 2F 
using namespace std;

int n, m, j, bMin, bMax, ret;

int main(){
	cin >> n >> m >> j;

	bMin = 1;
	bMax = m;

	while(j) {
		int temp;
		cin >> temp;
		if(temp < bMin) {
			int minus = (bMin - temp);
			bMin -= minus;
			bMax -= minus;
			ret += minus;
		} else if (temp > bMax) {
			int plus = (temp - bMax);
			bMin += plus;
			bMax += plus;
			ret += plus;
		}
		j--;
	}

	cout << ret << "\n";

    return 0;
}
