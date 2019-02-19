#include "Text.hh"

bool comp(const pair<string, int>& elem1, const pair<string, int>& elem2){
	if (elem1.second == elem2.second){
		if (elem2.first.size() == elem1.first.size()){
			return elem2.first > elem1.first;
		}
		else return elem1.first.size() > elem2.first.size();
	}
	else return elem1.second > elem2.second;
}
Text::Text(){}
Text::Text(string titoltxt,string autortxt,vector<vector<string> > contingutaux){
    titol = titoltxt;
    autor = autortxt;
    contingut = contingutaux;
    string nomautor;
	istringstream issini(autortxt);
	while (issini >> nomautor){
		inicials_priv += nomautor[0];
	}

    string comanda = titoltxt;
	istringstream a1(comanda);
	while (a1 >> comanda){
		paraules.insert(comanda);
	}
	string autoraux = autortxt;
	istringstream a2(autoraux);
	while (a2 >> autoraux){
		paraules.insert(autoraux);
	}
	
	taulafrequs(contingutaux);

}

Text::~Text();

void Text::taulafrequs (vector<vector<string> > continguttxt){//funciona
	num_frases = 0;
	num_paraules = 0;
	map <string, int> mapfreqaux;
    for (int i = 0; i < int(continguttxt.size()); ++i) {
        num_frases += 1;
	    for (int j = 0; j < int(continguttxt[i].size()); ++j){
		    string auxiliar = continguttxt[i][j];
		    char c = auxiliar[auxiliar.size()-1];
		    if (c == ',' or c == ';' or c == ':' or c == '.' or c == '?' or c == '!') auxiliar.erase(auxiliar.size()-1);
		    else {
		    	num_paraules += 1;
		    	map<string, int>::iterator it = mapfreqaux.find(auxiliar) ;
		    	if (it != mapfreqaux.end()){
		        	int aux = it->second;
		   			aux += 1;
		   			mapfreqaux[auxiliar]=aux;
				}
		    	else {
		    		mapfreqaux.insert(make_pair(auxiliar, 1));
		    	}
		    	
		    }
		    
		    
		}
	}
	mapfreq = mapfreqaux;
	vector <pair<string,int> > taulafreqaux;
	for (map <string, int>::iterator tfav = mapfreq.begin(); tfav != mapfreq.end(); ++tfav){
		taulafreqaux.push_back(make_pair(tfav->first,tfav->second));
	}
	taulafreq = taulafreqaux;
	sort (taulafreq.begin(), taulafreq.end(), comp);
}
	        
void Text::substitueix(string paraula1, string paraula2){
	for (int i=0;i<contingut.size();++i){
		for (int j=0;j<contingut[i].size();++j){
			if (contingut[i][j] == paraula1){
				contingut[i][j] = paraula2;
			}
		}
	}
	taulafrequs(contingut);
}

            
            
        //Consultores
  /** @brief Comprovador de presència. 

      Mira si al text es troben les paraules desitjades
      \pre <em>cert</em>
      \post  retorna cert si es troba en el paràmetre implícit totes les paraules contingudes al vector, altrament, retorna fals.
  */         
	bool conteParaules(vector<string>paraulabuscar){
		int conter = 0;
		for(int s = 0; s < int(paraulesbuscar.size()); ++s){
			if (mapfreq.find(paraulesbuscar[s]) != mapfreq.end() or  paraules.find(paraulesbuscar[s]) != paraules.end() ){
				conter += 1;
			}
		}
		if(conter == int(paraulesbuscar.size())) return true;
		else return false;	
	} 
	string Text::consulta_inicials()const{
		return inicials_priv;
	}
  /** @brief Informació del text. 

      \pre <em>cert</em>
      \post  mostra l'autor, títol, nombre de frases, nombre de paraules i cites associades del paràmetre implícit.
  */   	        
//	void info(); 

	string Text::consulta_titol() const{
	  return titol;
	}

  /** @brief Autor. 

      \pre <em>cert</em>
      \post  mostra l'autor del paràmetre implícit.
  */         
	string Text::consulta_auto()const{
	    return autor;
	}

  /** @brief Contingut. 

      \pre <em>cert</em>
      \post mostra el contingut del paràmetre implicit amb les seves frases numerades a partir de l'1.
  */            
	vector<vector<string> > Text::consulta_contingut()const{
	    return contingut;
	}


  /** @brief Número de frases. 

      \pre <em>cert</em>
      \post mostra el nombre de frases del contingut del paràmetre implícit.
  */ 
	int Text::numero_frases(){
		return num_frases;
	}

  /** @brief Número de paraules. 

      \pre <em>cert</em>
      \post mostra el nombre de paraules del contingut del paràmetre implícit.
  */         
	int Text::num_par(){
		return num_paraules;
	}

  /** @brief Taula de freqüències. 

      \pre <em>cert</em>
      \post  Trenca el contingut paraula per paraula i conta quans cops apareix cada una d'elles en el transcurs del text.
  */           
	vector <pair<string,int> >Text::taulafreqs(){
		return taulafreq;
	}

  /** @brief Frases amb expressió. 

      \pre <em>cert</em>
      \post  mostra les frases del contingut del paràmetre implícit que compleixen l'expressió boleana determinada pel "símbol".
  */        
	void Text::frasesexpresio(vector<string> paraula1,char simbol ,vector <string> paraula2);

  /** @brief Frases seqüència de paraules. 

      \pre <em>cert</em>
      \post  mostra les frases on hi apareix, consecutivament, obviant els signes de puntuació, la seqüència de paraules <em>paraula1</em>, <em>paraula2</em>...<em>paraulaN</em> en el contingut del paràmetre implícit

  */          
	void Text::frasesparaules(vector<string> paraules);