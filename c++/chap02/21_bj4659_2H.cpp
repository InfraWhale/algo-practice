#include<bits/stdc++.h> // 백준 4659 2G
using namespace std;

vector<char> v = {'a', 'e', 'i', 'o', 'u'};
string s, ret;
int cnt1, cnt2, cnt3;
bool is_vowel, b4_is_vowel;

int main(){
	cin >> s;

	do {

		cnt1 = 0;
		cnt2 = 0; 
		cnt3 = 0;

		for (int i = 0; i < s.size(); i++) {
			is_vowel = (find(v.begin(), v.end(), s[i]) != v.end());

			if(is_vowel) {
				cnt1++;
			}

			if(cnt2 == 0 || is_vowel == b4_is_vowel) {
				cnt2++;
				if(cnt2 == 3) {
					break;
				}
			} else {
				cnt2 = 1;
			}
			b4_is_vowel = is_vowel;

			if(i > 0 && s[i] == s[i-1]) {
				if(s[i] != 'e' && s[i] != 'o') {
					cnt3++;
					break;
				}
			}
		}
		ret = '<' + s + '>';

		if(cnt1 == 0 || cnt2 == 3 || cnt3 == 1 ) {
			ret += " is not acceptable.";
		} else{
			ret += " is acceptable.";
		}
			
		cout << ret << "\n";

		cin >> s;
	} while (s != "end");
	
    return 0;
}
