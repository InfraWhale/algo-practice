#include <bits/stdc++.h> // queue
using namespace std;

int main(){
	
	queue<int> q;
	
	q.push(1);
	cout << q.front() << "\n";
	
	q.pop();
	cout << q.size() << "\n";
	
	return 0;
}
