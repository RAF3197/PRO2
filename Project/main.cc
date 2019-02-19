#include "Biblio.hh"
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
  Biblio gestor;
  string comanda, op, m;
  getline(cin, comanda);
    while (comanda!="sortir"){
	    istringstream iss(comanda);
	    iss >> op;
      if (op == "afegir") {
        cout << comanda << endl;
        iss >> op;
        if (op == "text") {
	       comanda.erase(0,13);
	       comanda.erase(comanda.size()-1);
	       string titol = comanda;
	       gestor.AfegirText(titol);
	
        } 
        else if (op == "cita") {
	       if (gestor.hihatexttriat()){
	       int x, y;
	       iss >> x;
	       iss >> y;
	       gestor.afegircita(x,y);
	       }
	       else cout << "error";
	       
        }
      }
      else if (op == "triar"){
        cout << comanda << endl;
        iss>>op;
		    if (op == "text"){
          comanda.erase(0,12);
          comanda.erase(comanda.length()-1);
			    gestor.TriarText(comanda);
		    }
      }
      else if (op == "eliminar"){
        cout << comanda << endl;
        iss >> op;
        if (op == "text") {
          if (gestor.hihatexttriat()){
            gestor.EliminarText();
          }
          else cout << "error" << endl;
          
        }
        else if (op == "cita") {
          string referencia;
          iss >> referencia;
          referencia.erase(0,1);
          referencia.erase(referencia.length()-1);
          //gestor.eliminarcita(referencia);
        }
      }
      else if (op == "substitueix"){
        cout << comanda << endl;
        iss >> op;
        op.erase(0,1);
        op.erase(op.length()-1);
        string paraula1 = op;
        iss >> op;
        iss >> op;
        op.erase(0,1);
        op.erase(op.length()-1);
        string paraula2 = op;
        if (gestor.hihatexttriat()){
          gestor.SubText(paraula1, paraula2);
        }
        else cout << "error" << endl;
      }
      else if (op == "textos"){
        cout << comanda << endl;
		    iss>>op;
		    if (op =="autor"){
		      string autor;    // pillar autor
          iss >> autor;
          autor.erase(0,1);
          autor.erase(autor.length()-1);
          iss >> op;
          if (op == "?"){
            gestor.TextosAutor(autor);
          }
		    } 
      }
      else if (op == "tots"){
        cout << comanda << endl;
        iss >> op;
        if (op == "textos") {
		      iss >> op;
          if (op == "?"){
            gestor.TotsTextos();
          }
        }
        else if (op == "autors") {
		      iss >> op;
          if (op == "?"){
            //gestor.TotsAutors();
          }
        }
      }
      else if (op == "info"){
        cout << comanda << endl;
        iss >> op;
        if (op == "?") {
          if (gestor.hihatexttriat()){
            //gestor.info();
          }
          else cout << "error" << endl;
        }
        else if (op == "cita") {
          string referencia;
          iss >> referencia;
          referencia.erase(0,1);
          referencia.erase(referencia.length()-1);
          iss >> op;
          if (op == "?"){
            gestor.infocita(referencia);
          }

        }
      }
      else if (op == "autor"){
        cout << comanda << endl;
		    iss >> op;
		    if (op == "?"){
          if (gestor.hihatexttriat()){
            gestor.autor();
          }
          else cout << "error" << endl;
		    }
      }
      else if (op == "contingut"){
        cout << comanda << endl;
		    iss>>op;
		    if (op == "?"){
          if (gestor.hihatexttriat()){
            gestor.contingut();
          }
          else cout << "error" << endl;
		    }
      }
      else if (op == "frases"){
        cout << comanda << endl;
        iss >> op;
        if (op[0] == '('){
          comanda.erase(0,7);
          int aux = comanda.size()-1;
          char aux2 = comanda[aux];
          if (aux2 == '?'){
            comanda.erase(comanda.length()-2, comanda.length()-1);
          /*if (gestor.hihatexttriat()){
              gestor.frasesexpresio(comanda);
            }
            else cout << "error" << endl;*/
          }
        }
        else if (op[0] == '"'){
          comanda.erase(0,8);
          int aux = comanda.size()-1;
          char aux2 = comanda[aux];
          if (aux2 == '?'){
            comanda.erase(comanda.length()-3, comanda.length()-1);
            istringstream com(comanda);
            vector<string> paraules;
            while (com >> comanda){
              paraules.push_back(comanda);
            }
            /*if (gestor.hihatexttriat()){
              gestor.frasesparaules(paraules);
            }
            else cout << "error" << endl;*/  
          }
        }
        else {
		    int x,y;
        comanda.erase(0,7);
        istringstream com(comanda);
		    com >> x ;
        com >> y;
		    com >> op;
		    if (op == "?"){
          if (gestor.hihatexttriat()){
          gestor.frases(x, y);
          }
          else cout << "error" << endl;
		    }
      }
      }
      else if (op == "nombre"){
        cout << comanda << endl;
		    iss >> op;
		    if (op == "de"){
			   iss >> op;
			   if (op == "frases"){
				  iss >> op;
          if (op == "?"){
            if (gestor.hihatexttriat()){
              gestor.nombrefrases();
            }
            else cout << "error" << endl;
          }
			   }
			   else if (op == "paraules"){
				  iss >> op;
          if (op == "?"){
            if (gestor.hihatexttriat()){
              gestor.nombreparaules();
            }
            else cout << "error" << endl;
          }
			   }
		    }
      }

      else if (op == "taula"){
        cout << comanda << endl;
        iss >> op;
        if (op == "de"){
          iss >> op;
          if (op == "frequencies"){
            iss >> op;
            if (op == "?"){
              if (gestor.hihatexttriat()){
                gestor.tauladefrecuencies();
              }
              else cout << "error" << endl;

            }
          }
        }
      }

      else if (op == "cites") {
        cout << comanda << endl;
		    iss >> op;
		    if (op == "autor"){
          string autor;
          iss >> autor;
          autor.erase(0,1);
          autor.erase(autor.length()-1);
          iss >> op;
          if (op == "?"){
            //gestor.citesAutor(autor);
          }
		    }
		    else if (op == "?"){
          /*if (gestor.hihatexttriat()){
            gestor.cites();
          }*/
		    }
	     }
       else if (op == "totes"){
        cout << comanda << endl;
        iss >> op;
        if (op == "cites"){
          iss >> op;
          if (op == "?"){
            gestor.totescites();
          }
        }
       }
       
    getline(cin, comanda);
    getline(cin, comanda);
    
  }
  //return 0;
}


