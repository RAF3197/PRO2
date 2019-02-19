#include "Cjt_estudiants.hh"
using namespace std;

void modificar(Cjt_estudiants &con1,const Cjt_estudiants &con2){
	for (int i=0;i<con1.mida();++i){
		bool canvi=false;
		Estudiant e1=con1.consultar_iessim(i+1);
		Estudiant e2=con2.consultar_iessim(i+1);
		if (not e1.te_nota() and e2.te_nota()){
			e1=e2;
			canvi=true;
		}
		else if (e1.te_nota() and e2.te_nota()){
			if (e1.consultar_nota()<e2.consultar_nota()){
				e1=e2;
				canvi=true;
			}
		}
		if (canvi){
			con1.modificar_iessim(i+1,e1);
		}
	}
}		

int main(){
	Cjt_estudiants con1,con2;
	con1.llegir();
	con2.llegir();
	modificar(con1,con2);
	con1.escriure();
}
