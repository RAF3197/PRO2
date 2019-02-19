#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;
bool comp(const pair<string, int>& elem1, const pair<string, int>& elem2){
	if (elem1.second == elem2.second){
		if (elem2.first.size() == elem1.first.size()){
			return elem2.first > elem1.first;
		}
		else return elem1.first.size() > elem2.first.size();
	}
	else return elem1.second > elem2.second;
}

void normalitzar (string& linia){
	size_t found = linia.find(".");
	while (found != string::npos){
		linia.replace(found, 1, " . ");
		found =linia.find(".", found+3);
	}
	found = linia.find(",");
	while (found != string::npos){
		linia.replace(found, 1, " , ");
		found =linia.find(",", found+3);
	}
	found = linia.find(";");
	while (found != string::npos){
		linia.replace(found, 1, " ; ");
		found =linia.find(";", found+3);
	}
	found = linia.find(":");
	while (found != string::npos){
		linia.replace(found, 1, " : ");
		found =linia.find(":", found+3);
	}
	found = linia.find("?");
	while (found != string::npos){
		linia.replace(found, 1, " ? ");
		found =linia.find("?", found+3);
	}
	found = linia.find("!");
	while (found != string::npos){
		linia.replace(found, 1, " ! ");
		found =linia.find("!", found+3);
	}
}

int main (){
	string comanda, op, m;
	set <string> paraules;
 	getline(cin, comanda);
 	istringstream iss(comanda);
	iss >> op;
    if (op == "afegir") {
    	cout << comanda << endl;
    	iss >> op;
    	if (op == "text") {
			comanda.erase(0,13);
			comanda.erase(comanda.size()-1);
			//normalitzar(comanda)
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
			    normalitzar (linia);
			    /*size_t found = linia.find(".");
				while (found != string::npos){
					linia.replace(found, 1, " . ");
					found =linia.find(".", found+3);
				}*/
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
  			int nombrefrases = 0;
  			int nombreparaules = 0;
  			map <string, int> mapfreq;
  			//set<pair <int, string> > taulafreq;
  			//pair<int, string> paux;
			for (int i = 0; i < int(contingut.size()); ++i) {
				nombrefrases +=1;
		    	for (int j = 0; j < int(contingut[i].size()); ++j){
		     		string auxiliar = contingut[i][j];
		     		

		     		char c = auxiliar[auxiliar.size()-1];
		     		if (c == ',' or c == ';' or c == ':' or c == '.' or c == '?' or c == '!') {
		     			auxiliar.erase(auxiliar.size()-1);
		     		}
		     		else{ 
		     			nombreparaules +=1;
		     			map<string, int>::iterator it = mapfreq.find(auxiliar) ;
		     			//set<pair <int, string> >::iterator it = taulafreq.find(auxiliar) ;
		     			if (it != mapfreq.end()){
			     			int aux = it->second;
			     			aux += 1;
			     			//paux = *it;
			     			//paux.first += 1;
			     			mapfreq[auxiliar]=aux;
		     			}
			     		else {
			     			mapfreq.insert(make_pair(auxiliar, 1));
			     		}
		     		}
		     		
		     	}
		    }
		    vector <pair<string, int> > taulafreq;
		   	for (map <string, int>::iterator tfav = mapfreq.begin(); tfav != mapfreq.end(); ++tfav){
		   		taulafreq.push_back(make_pair(tfav->first,tfav->second));
		    }
		    sort (taulafreq.begin(), taulafreq.end(), comp);
		    for (int b = 0; b < int(taulafreq.size()); ++b){
		    	cout << taulafreq[b].first << " " << taulafreq[b].second << endl; 
		    }
		   /*	map<string, int>::iterator it = taulafreq.begin();
			while (it != taulafreq.end()){
			cout << it->first << " " << it->second << endl;
			++it;	      
		  	}
		  	cout << "nombre de frases: " << nombrefrases << endl;
		  	cout << "nombre de paraules: " << nombreparaules << endl;

		  	for (int i = 0; i < int(contingut.size()); ++i) {
          	for (int j = 0; j < int(contingut[i].size()); ++j) 
            
            cout<<contingut[i][j]<<' ';
          	cout<<endl;
        	}*/
			
		}
			
	       //gestor.AfegirText(titol);
		
	}
}