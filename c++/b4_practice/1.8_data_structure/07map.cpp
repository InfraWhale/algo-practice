#include <bits/stdc++.h> // map

using namespace std;
map<string, int> mp;
string a[] = {"��ȫö", "�翵��", "������"};

int main(){
	for(int i = 0; i < 3; i++){
		mp.insert({a[i], i + 1});
		mp[a[i]] = i + 1;
	}
	// mp�� �ش� Ű�� ���ٸ� 0���� �ʱ�ȭ �Ǿ� �Ҵ��.(int�� ���)
	// ���� mp�� �ش� Ű�� ������ Ȯ���ϰ� �Ͱ�
	// �ʱ갪���� 0���� �Ҵ���� �ʾƾ� �Ǵ� ��Ȳ�̶��
	// find�� ��� ��.
	cout << mp["kundol"] << '\n';
	
	// ���ȣ�� ��������.
	mp["kundol"] = 4; //insert�� �� ������� ������ �ڵ����� 
	cout << mp.size() << '\n';
	mp.erase("kundol");
	
	auto it = mp.find("kundol"); // ���ͷ����ͷ� ��ȯ 
	if(it == mp.end()){ // ��ã���� end()���ͷ����� ��ȯ 
		cout << "��ã�ڳ� �Ҳ���\n";
	}
	mp["kundol"] = 100;
	it = mp.find("kundol");
	if(it != mp.end()){
		cout << (*it).first << " : " << (*it).second << '\n';
	}
	
	for(auto it : mp){
		cout << (it).first << " : " << (it).second << '\n';
	}
	
	for(auto it = mp.begin(); it != mp.end(); it++){
		cout << (*it).first << " : " << (*it).second << '\n';
	}
	mp.clear();
	return 0;
}
