#include<bits/stdc++.h> // 백준 2852 2L 
using namespace std;

int n, a, flag, w, start_min, start_sec, end_min, end_sec, min1, min2, sec1, sec2;
string b;

int main(){
	
	cin >> n;
	while(n--) {

		cin >> a >> b;

		if(a == 1) { // 팀 1 득점
			w++;
		} else { // 팀 2 득점
			w--;
		}

		if((w == 1 || w == -1) && flag == 0) { // 동점 -> 한 팀이 득점
			start_min = stoi(b.substr(0,2));
			start_sec = stoi(b.substr(3,2));
			flag = w;
		} else if(w == 0) {
			end_min = stoi(b.substr(0,2));
			end_sec = stoi(b.substr(3,2));
			if(end_sec < start_sec) {
				end_sec+=60;
				end_min--;
			}
			end_min -= start_min;
			end_sec -= start_sec;

			if(flag > 0) {
				min1 += end_min;
				sec1 += end_sec;
				
				min1 += sec1 / 60; //sec 가 60 이상인 경우 나눠주기
				sec1 %= 60;
			} else if(flag < 0) {
				min2 += end_min;
				sec2 += end_sec; 

				min2 += sec2 / 60;
				sec2 %= 60;
			}
			flag = 0;
		}
	}
	if(w != 0) { // 경기 종료 시, 동점이 아닌 경우
			end_min = 48;
			end_sec = 0;
			if(end_sec < start_sec) {
				end_sec+=60;
				end_min--;
			}
			end_min -= start_min;
			end_sec -= start_sec;

			if(flag > 0) {
				min1 += end_min;
				sec1 += end_sec;

				min1 += sec1 / 60;
				sec1 %= 60; 
			} else if(flag < 0) {
				min2 += end_min;
				sec2 += end_sec;

				min2 += sec2 / 60;
				sec2 %= 60;  
			}
			flag = 0;
	}
	

	printf("%02d:%02d\n", min1, sec1);
	printf("%02d:%02d\n", min2, sec2);
	return 0;
}
