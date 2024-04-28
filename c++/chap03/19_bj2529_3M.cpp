#include<bits/stdc++.h> // 백준 2529 3M
using namespace std;

int k, a[10], maxStart, minStart;
vector<char> vc;
vector<int> vMax, vMin;
bool flagMax, flagMin;

bool bs(char c, int a, int b) {
	if(c == '<') {
		if(a > b) {
			return 0;
		} else {
			return 1;
		}
	} else {
		if(a > b) {
			return 1;
		} else {
			return 0;
		}
	}
}

void getMax(int depth) {
	if(depth == k + 1) {
		flagMax = 1;
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if(!a[i] && bs(vc[depth], vMax[depth], i)) {
			a[i] = 1;
			vMax.push_back(i);
			getMax(depth+1);
			a[i] = 0;
			vMax.pop_back();
		}
	}
}

void getMin(int depth) {
	if(depth == k + 1) {
		flagMin = 1;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if(!a[i] && bs(vc[depth], vMin[depth], i)) {
			a[i] = 1;
			vMin.push_back(i);
			getMin(depth+1);
			a[i] = 0;
			vMin.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> vc[i];
	}

	for (int i = 9; i >= 0; i--) {
		vMax[0] = i;
		a[i] = 1;
		getMax(0);
		if(flagMax) break;
		a[i] = 0;
	}

	for (int i = 0; i <= 9; i++) {
		vMin[0] = i;
		a[i] = 1;
		getMin(0);
		if(flagMin) break;
		a[i] = 0;
	}

	for(auto it : vMax) {
		cout << it;
	}
	cout << "\n";
	for(auto it : vMin) {
		cout << it;
	}

	return 0;
}