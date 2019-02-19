#include <set>
#include <iostream>
using namespace std;

int main (){
	set<pair <int, string> > test;
	pair<int, string> paux;
	for (int i = 0; i < 4; ++i){
		string aux;
		cin >> aux;
		int num;
		cin >> num;
		paux = make_pair (num,aux);
		test.insert(paux);
	}
	set<pair <int, string> >::iterator it = test.end();
	
	while (it != test.begin()){
		--it;
		paux = *it;
		cout << paux.second << endl;
	}
}