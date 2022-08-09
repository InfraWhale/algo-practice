#include <bits/stdc++.h> //map
using namespace std;

int v[10];

int main(){
	
	unordered_map<string, int> umap;
	
	// ��� ����  
	umap.insert({"test1", 1});
	umap.emplace("test5", 5);
	
	// ����� (����, ���� ��� �����ϴ�) 
	umap["test1"] = 4;
	umap["test9"] = 9;
	
	for(auto element : umap){
		cout << element.first << " :: " << element.second << '\n';
	}
	
	//map�� find�޼ҵ�� ã�� ���ϸ� end() ���ͷ����͸� ��ȯ�Ѵ� 
	auto search = umap.find("test4"); //���⼭ search�� �ּ�(������) 
	if(search != umap.end()){
		cout << "found :" << search -> first << " " << (*search).second << '\n'; // ȭ��ǥ�� .�� �뵵�� ����ϴ�. �տ� �����Ͱ� ���� ȭ��ǥ�� ���°� | *�� �����Ϳ� �پ� �ش��ϴ� ���� ��ȯ�Ѵ�. 
	}else{
		cout << "not found.." << '\n';
	}
	
	auto search2 = umap.find("test9");
	if(search2 != umap.end()){
		cout << "found :" << search2 -> first << " " << (*search2).second << '\n';
	}else{
		cout << "not found.." << '\n';
	}
	
	//�̷������� �ٷ� test1�� ����� �� ���� ����.
	umap["test1"]++;
	cout << umap["test1"] << "\n";
	cout <<umap.size() <<"\n"; // umap�� ũ��  
	umap.erase("test1");
	cout <<umap.size() <<"\n";
	
	return 0;
}
