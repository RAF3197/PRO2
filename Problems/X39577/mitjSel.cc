#include "Estudiant.hh"
#include <vector>
using namespace std;

int main(){
	int nest,nass,sel;
	cin>>nest>>nass>>sel;
	vector<bool> selec(nass,false);
	for (int i=0;i<sel;++i){
		int x;
		cin>>x;
		selec[x-1]=true;
	}
	vector<Estudiant> v(nest);
	for (int i=0;i<nest;++i){
		int dni;
		cin>>dni;
		Estudiant e(dni);
		double mitja=0;
		for (int j=0;j<nass;++j){
			double nota;
			cin>>nota;
			if (selec[j]){
				mitja+=nota;
			}
		}
		mitja/=sel;
		e.afegir_nota(mitja);
		v[i]=e;
	}
	for (int i=0;i<nest;++i){
		v[i].escriure();
	}
}
