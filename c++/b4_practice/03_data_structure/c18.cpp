#include <bits/stdc++.h>//deque
using namespace std;

int main(){
	deque<int> dq;
	
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	cout << "front : " << dq.front() << "\n";
	cout << "back : " << dq.back() << "\n";
	cout << "size : " << dq.size() << "\n";
	
	dq.pop_back();
	dq.pop_front();
	cout << "size : " << dq.size() << "\n";
	return 0;
}
