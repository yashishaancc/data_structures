#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	map<string,int> marks;
	marks["Apple"] = 100;
	marks["Bat"] = 98;
	marks["Cat"] = 96;
	marks["Dog"] = 0;
	map<string,int> :: iterator itr;
	for(itr = marks.begin(); itr != marks.end(); itr++){
		cout << (*itr).first << " " << (*itr).second << endl;
	}
	return 0;
}