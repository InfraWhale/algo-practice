#include <bits/stdc++.h> //map
using namespace std;

int v[10];

int main(){
	
	unordered_map<string, int> umap;
	
	// 요소 삽입  
	umap.insert({"test1", 1});
	umap.emplace("test5", 5);
	
	// 덮어쓰기 (수정, 삽입 모두 가능하다) 
	umap["test1"] = 4;
	umap["test9"] = 9;
	
	for(auto element : umap){
		cout << element.first << " :: " << element.second << '\n';
	}
	
	//map의 find메소드는 찾지 못하면 end() 이터레이터를 반환한다 
	auto search = umap.find("test4"); //여기서 search는 주소(포인터) 
	if(search != umap.end()){
		cout << "found :" << search -> first << " " << (*search).second << '\n'; // 화살표는 .과 용도가 비슷하다. 앞에 포인터가 오면 화살표를 쓰는것 | *는 포인터에 붙어 해당하는 값을 반환한다. 
	}else{
		cout << "not found.." << '\n';
	}
	
	auto search2 = umap.find("test9");
	if(search2 != umap.end()){
		cout << "found :" << search2 -> first << " " << (*search2).second << '\n';
	}else{
		cout << "not found.." << '\n';
	}
	
	//이런식으로 바로 test1에 저장된 값 증가 가능.
	umap["test1"]++;
	cout << umap["test1"] << "\n";
	cout <<umap.size() <<"\n"; // umap의 크기  
	umap.erase("test1");
	cout <<umap.size() <<"\n";
	
	return 0;
}
