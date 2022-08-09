#include <bits/stdc++.h> // set
using namespace std;

int main(){
	set<pair<string, int>> st;
	
	st.insert({"test", 1});
	st.insert({"test", 1});
	st.insert({"test", 1});
	st.insert({"test", 1});
	
	cout << st.size() <<"\n";
	
	for(auto it : st){
		cout << it.first << '\n';
	}
	

	set<int> st2;
	
	st2.insert(1);
	st2.insert(2);
	st2.insert(2);
	
	for(auto it : st2){
		cout << it << '\n';
	}
	
	return 0;
}
