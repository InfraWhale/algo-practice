#include<bits/stdc++.h> // 백준 2529 3M
using namespace std;

int k, a[14];
vector<char> vc;
vector<int> vMax, vMin;
bool flagMax, flagMin;

bool bs(char c, int a, int b) {
	if(c == '<') return a < b;
	else return a > b;
}

void getMax(int depth) {
	if(depth == k) {
		flagMax = 1;
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if(!a[i] && bs(vc[depth], vMax[depth], i)) {
			a[i] = 1;
			vMax.push_back(i);	
			// cout << "+ " << i << "\n";		
			getMax(depth+1);
			if(flagMax) return;
			a[i] = 0;
			vMax.pop_back();
		}
	}
}

void getMin(int depth) {
	if(depth == k) {
		flagMin = 1;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if(!a[i] && bs(vc[depth], vMin[depth], i)) {
			a[i] = 1;
			vMin.push_back(i);
			// cout << "+ " << i << "\n";	
			getMin(depth+1);
			if(flagMin) return;
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
		char temp;
		cin >> temp;
		vc.push_back(temp);
	}

	fill(&a[0], &a[0] + 10, 0);

	for (int i = 9; i >= 0; i--) {
		vMax.push_back(i); // 벡터에 i를 할당하기 전에 =를 써서 값을 넣으면 오류 발생 (vMax[0] = i 안됨)
		a[i] = 1;
		getMax(0);
		if(flagMax) break;
		vMax.clear();
		a[i] = 0;
	}

	fill(&a[0], &a[0] + 10, 0);

	for (int i = 0; i <= 9; i++) {
		vMin.push_back(i);
		a[i] = 1;
		getMin(0);
		if(flagMin) break;
		vMin.clear();
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