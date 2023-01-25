#include <bits/stdc++.h> // 버퍼플러시 

using namespace std;

int main(){
	//버퍼플러시 전
	for (int i = 1; i <= 5; ++i){
		cout << i << "\n";
		this_thread::sleep_for(chrono::seconds(1)); // 1초 지연? 
	}
	cout << endl;
	
	//버퍼 플러시 후
	for (int i = 1; i <= 5; ++i){
		cout << i << "\n" << flush;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << endl;
	
	//버퍼 플러시 후 : 위와 동일한 코드
	for (int i = 1; i <= 5; ++i){
		cout << i << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	
	cout << endl;
	return 0;
}
