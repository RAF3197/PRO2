#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main (){
	string comanda, op, m;
	set <string> paraules;
	set<pair <int, string> > taulafreq;
	
 	getline(cin, comanda);
 	istringstream iss(comanda);
	iss >> op;
    if (op == "afegir") {
    	cout << comanda << endl;
    	iss >> op;
    	if (op == "text") {
			comanda.erase(0,13);
			comanda.erase(comanda.size()-1);
			string titol = comanda;
			istringstream a1(comanda); /*el titulo no lo he tocado, 
			se puede seguir pasando el parametro al creador de textos*/

			while (a1 >> comanda){
				paraules.insert(comanda);
			}

			string autor;                   // pillar autor
  			getline(cin, autor);
  			istringstream issAutor(autor);
			autor.erase(0,7);
			autor.erase(autor.size()-1);
			string autoraux = autor;
			istringstream a2(autoraux);
			while (a2 >> autoraux){
				paraules.insert(autoraux);//aqui tambien se puede seguir usando el 
				//parametro autor
			}
			/*ya hecho: conseguir el autor y el titulo 
			y meter sus palabras en un set para la funcion de busqueda */
  
			vector< vector<string> > contingut;
		  	bool saltlin = true;            // indica si haurem d'insertar una nova linia
		  	string linia;
		  	getline(cin, linia);
		  	while (linia != "****") {         // llegim linies fins trobar els 4 asteriscs
			    istringstream issLinia(linia);
			    string paraula;
			    while (issLinia >> paraula) {   // anem paraula per paraula
			      char c = paraula[paraula.size()-1];
			      bool lastword = (c=='.' || c=='?' || c=='!');
			      // si cal afegir vector per desar les paraulas d'una linia nova
			      if (saltlin) contingut.push_back(vector<string>());
			      // desar paraula
			      contingut[contingut.size()-1].push_back(paraula);
			      // si la paraula acaba la linia, a la propera volta ficarem un vector nou a contingut
			      saltlin = lastword;
			    }
			    getline(cin, linia);
  			}
  			pair<int, string> paux;
			for (int i = 0; i < int(contingut.size()); ++i) {
		    	for (int j = 0; j < int(contingut[i].size()); ++j){
		     		istringstream ana(contingut[i][j]);
		     		string aux;
		     		while (ana >> aux){
		     		set<pair <int, string> >::iterator it = taulafreq.find(aux) ;
		     		if (it != taulafreq.end()){
		     			paux = *it;
		     			paux.first += 1;
		     			taulafreq.insert(paux);
		     		}
		     		else {
		     			paux = make_pair(1, aux)
		     			taulafreq.insert(paux);
		     		}
		     		}
		    	}	      
		  	}
			set<pair <int, string> >::iterator it = taulafreq.end();
			while (it != taulafreq.begin()){
			--it;
			paux = *it;
			cout << paux.fisrt << " " << paux.second << endl;
	}
	
	       //gestor.AfegirText(titol);
		}
	}
}
