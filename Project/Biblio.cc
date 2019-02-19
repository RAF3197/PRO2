#include "Biblio.hh"
#include "Text.hh"
#include "Cita.hh"

Biblio::Biblio() {
  ulttext = false;
}

Biblio::~Biblio() {}

void Biblio::AfegirText(string titol){ //funciona
  
	string autor;                   // pillar autor
  getline(cin, autor);
  istringstream issAutor(autor);
	autor.erase(0,7);
	autor.erase(autor.size()-1);
	
	vector< vector<string> > contingut;
  bool saltlin = true;            // indica si haurem d'insertar una nova linia
  string linia;
  getline(cin, linia);
  while (linia != "****") {         // llegim linies fins trobar els 4 asteriscs
    normalitzar (linia);
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
  Text a(titol, autor, contingut);
  BiblioAutor[autor][titol] = a;
}



void Biblio::normalitzar (string& linia){ //funciona
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
void Biblio::TriarText(string &paraules){ //funciona
  Text aux;
  bool trobat = false;
  bool error = false;
  istringstream issavect(paraules);
  vector <string> palabrasbuscar;
  while (issavect >> paraules) {
    palabrasbuscar.push_back(paraules);
  }
  map<string,map<string,Text> >::iterator it1;
  for (it1=BiblioAutor.begin();it1!=BiblioAutor.end();++it1){
    map<string, Text> textos = it1->second;
    map<string, Text>::iterator it2;
    it2 = textos.begin();
    while(not error and it2 != textos.end()){
      Text b = it2->second;
      bool auxiliar = b.conteParaules(palabrasbuscar);
      if (auxiliar and not trobat){
        trobat = true;
        aux = b;
      }
      else if (auxiliar and trobat) error = true;
      ++it2;
    }
  }
  if (error or not trobat) cout << "error" <<endl;
  else{
    ulttext = true;
    ultxt = aux;
  }
}

void Biblio::EliminarText(){ //funciona
  string autortodl = ultxt.consulta_auto();
  string tltdel = ultxt.consulta_titol();
  map<string,map<string, Text> >::iterator todelate = BiblioAutor.find(autortodl);
  map<string,Text>::iterator it_aux = (todelate->second).find(tltdel);
  (todelate->second).erase(tltdel);
  ulttext = false; 
}

void Biblio::SubText(string paraula1, string paraula2){//funciona
	ultxt.substitueix(paraula1, paraula2);
}

bool Biblio::hihatexttriat(){//funciona
  return ulttext;
}
void Biblio::TextosAutor(string autor){ //funciona
  map <string, map<string, Text> >::iterator autores = BiblioAutor.find(autor);
  if (autores != BiblioAutor.end()){
    map<string,Text> comodin = autores->second;
    for (map<string, Text>::iterator it3 = comodin.begin(); it3 != comodin.end(); ++it3){
      cout << it3->first << endl;
    }
  }
}

void Biblio::TotsTextos(){ //funciona
  map<string,map<string,Text> >::iterator it1;
  for (it1=BiblioAutor.begin();it1!=BiblioAutor.end();++it1){
    map<string,Text> aux=it1->second;
    map<string,Text>::iterator it2;
    string aut=it1->first;
    for (it2=aux.begin();it2!=aux.end();++it2){
      cout<<aut<<" "<<'"'<<it2->first<<'"'<<endl;
    }
  }
}

void Biblio::TotsAutors(){
  
}

void Biblio::info(){
  cout<<ultxt.consulta_auto()<<'"'<<ultxt.consulta_titol()<<endl;
  cout<<"Cites associades:"<<endl;
  //faltan citas, imprimir ref i las citas numeradas;
}

void Biblio::autor(){ //funciona
  cout<<ultxt.consulta_auto()<<endl;
}

void Biblio::contingut(){ //modificada y ya funciona
  vector<vector<string> > auxcont=ultxt.consulta_contingut();
  for (int i=0;i<auxcont.size();++i){
    bool primer = true;
    bool ultim = false;
    cout << i+1 << " ";
    for (int j=0;j<auxcont[i].size();++j){
      bool puntuacio =false;
      if (j == auxcont[i].size()-1) {ultim = true;}
      if (auxcont[i][j] == "," or auxcont[i][j] == ";" or auxcont[i][j] == ":") puntuacio = true;
      if (primer){
        primer = false;
        cout << auxcont[i][j];
      }
      else if (ultim) cout << auxcont[i][j];
      else if (puntuacio) cout << auxcont[i][j];
      else cout<<" "<<auxcont[i][j];
    }
    cout <<endl;
  }
}

void Biblio::frases(int x,int y){//modificada y funciona
    vector<vector<string> > auxcont=ultxt.consulta_contingut();
    for (int i = x-1; i < y; ++i){
    bool primer = true;
    bool ultim = false;
    cout << i+1 << " ";
    for (int j=0;j<auxcont[i].size();++j){
      bool puntuacio =false;
      if (j == auxcont[i].size()-1) {ultim = true;}
      if (auxcont[i][j] == "," or auxcont[i][j] == ";" or auxcont[i][j] == ":") puntuacio = true;
      if (primer){
        primer = false;
        cout << auxcont[i][j];
      }
      else if (ultim) cout << auxcont[i][j];
      else if (puntuacio) cout << auxcont[i][j];
      else cout<<" "<<auxcont[i][j];
    }
    cout <<endl;
  }
}


void Biblio::nombrefrases(){ //funciona
  cout<<ultxt.numero_frases()<<endl;
}

void Biblio::nombreparaules(){ //funciona
  cout<<ultxt.num_par()<<endl;
}

void Biblio::tauladefrecuencies(){ //funciona
  vector <pair<string,int> > auxiliar = ultxt.taulafreqs();
  for (int z = 0; z < auxiliar.size(); ++z){
    cout << auxiliar[z].first << " " << auxiliar[z].second << endl;
  }
  
}

void Biblio::frasesexpresio(vector<string> paraula1,char simbol ,vector <string> paraula2){
  //declaracio correcta ? this or string expresio??
}

void Biblio::frasesparaules(vector<string> paraules){
  
}

void Biblio::afegircita(int x, int y){ //funciona
  if (x>0 and y>0 and x<=ultxt.numero_frases() and y<=ultxt.numero_frases() and x<=y){
    string inis = ultxt.consulta_inicials();
    int idnumeric = contador[inis];
    ++idnumeric;
    contador[inis] +=1;
    Cita auxcita (inis, ultxt, x, y);
    ostringstream reff;
    reff << idnumeric;
    inis += reff.str();
    mapcites[inis] = auxcita;
    cout << inis << endl;
  	}
  
}

void Biblio::eliminarcita(string iniciales, int _id){
  map<string, map <int, Cita> >::iterator it_cita;
  it_cita = mapcites.find(iniciales);
  if (it_cita!=mapcites.end()){
    map<int,Cita>::iterator it_aux=it_cita->second.find(_id);
    if (it_aux!=map_aux.end()){
      (it_cita->second).erase(it_aux);
    }
  }
  else cout<<"error"<<endl;
}

void Biblio::infocita(string referencia){ //funciona
  map<string,Cita>::iterator indice=mapcites.find(referencia);
  if (indice!=mapcites.end()){
    cout<<(indice->second).aut_procedent()<<" "<<'"'<<(indice->second).tit_proc()<<'"'<<endl;
    cout<<(indice->second).valor_x()<<"-"<<(indice->second).valor_y()<<endl;
    indice->second.imp_contingut();
  }
  else cout<< "error" <<endl;
}

void Biblio::citesAutor(string autor_cita){
  string iniciales;
	istringstream issini(autor_cita);
	while (issini >> autor_cita){
		iniciales += autor_cita[0];
	}
	map<string,map<int,Cita> >::iterator it_citaut=mapcites.find(iniciales);
	if (it_citaut!=mapcites.end()){
	  map<int,Cita>::iterator it_aux;
	  for (it_aux=it_citaut->second.begin();it_aux!=it_citaut->second.end();++it_aux){
	    if (it_aux->second.aut_procedent()==autor_cita){
	      cout<<iniciales<<it_aux->first<<endl;
	      int x=it_aux->second.valor_x();
	      while (x!=it_aux->second.valor_y){
	        cout<<x<<cita_num(x)<<endl;
	        ++x;
	      }
	      cout<<it_aux->second.aut_procedent()<<" "<<'"'<<it_aux->second.tit_proc()<<'"'<<endl;
	    }
	  }
	}
}

void Biblio::cites(){
  const list< map<string,Cita>::iterator> &list_cit=citatxt[ultxt.consulta_auto()][ultxt.consulta_titol()];
  list< map<string,Cita>::iterator>::const_iterator indice;
  for (indice=list_cit.begin();indice!=list_cit.end();++indice){
    cout<<indice.first<<endl;
    (indice.second).imp_contingut();
  }
  cout<<ultxt.consulta_auto()<<" "<<'"'<<ultxt.consulta_titol()<<'"'<<endl;
}

void Biblio::totescites(){ //funciona
  map<string,Cita>::iterator indice;
  for (indice=mapcites.begin();indice!=mapcites.end();++indice){
    cout<<(indice->first)<<endl;
    (indice->second).imp_contingut();
    cout<<(indice->second).aut_procedent()<<" "<<'"'<<(indice->second).tit_proc()<<'"'<<endl;
  }
}
