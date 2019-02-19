#include "Estudiant.hh"
#include <vector>
using namespace std;


void llegir_evaluar(vector<Estudiant> &v,int n){
	int dni_ant;
	for (int i=0;i<n;++i){
		Estudiant e; e.llegir();
		if (e.consultar_DNI()!=dni_ant){
			v.push_back(e);
		}
		else {
			Estudiant &e_ant=v[v.size()-1];
			if (e.te_nota()){
				if (not e_ant.te_nota()) e_ant.afegir_nota(e.consultar_nota());
				else if (e_ant.consultar_nota()<e.consultar_nota()) e_ant.modificar_nota(e.consultar_nota());
			}
		}
		dni_ant=e.consultar_DNI();
	}
}
				

int main(){
	int n;
	cin>>n;
	vector<Estudiant> v;
	llegir_evaluar(v,n);
	for (int i=0;i<v.size();++i){
		v[i].escriure();
	}
}
	
