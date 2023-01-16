#include<bits/stdc++.h> // unordered_map 

using namespace std;
unordered_map<string, int> umap;

int main(){
	umap["bcd"] = 1;
	umap["aaa"] = 1;
	umap["aba"] = 1;
	
	for(auto it : umap){
		cout << it.first << " : " << it.second << '\n';
	}
}

// 느릴때도 많으니 (O(N)) 그냥 map 쓰는걸 권장  
