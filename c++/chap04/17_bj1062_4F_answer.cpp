#include<bits/stdc++.h> // 백준 1062 4F 정답 (생각보다 어렵다)
using namespace std;

int n, m, words[51];
string s;

int count(int mask) {
	int cnt = 0;
	for (int word : words) {
		if(word && (word & mask) == word) cnt++; // 일치하면 cnt
	}
	return cnt;
}

int go(int index, int k, int mask) {
	if (k < 0) return 0;
	if(index == 26) return count(mask);
	int ret = go(index+1, k-1, mask | (1 << index)); // 배우는 경우
	if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') { // antic 다 아니면
		ret = max(ret, go(index+1, k, mask)); // 안배우는 경우 // 위에서 구한 ret하고 비교해서 큰걸 return
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i= 0; i < n; i++) {
		cin >> s;
		for (char str : s) {
			words[i] |= (1 << (str - 'a')); // 각 단어 비트마스킹으로 입력
		}
	}
	cout << go(0, m, 0) << '\n';
    return 0;
}

