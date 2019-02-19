/** @file Text.hh
    @brief Especificació de la classe Text 
*/
#ifndef TEXT_HH
#define TEXT_HH

//#include "Cita.hh"
//#include "Expressio.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#endif
using namespace std;
/** @class Text
    @brief Representa un text i les seves propietats. 
    
    Permet operar amb un text i retornar valors de consulta fàcilment.
*/
class Text{
	private:
	string titol; //titulo del texto
	string autor; //autor del texto
  vector< vector<string> > contingut; //contenido del texto ya dividido
  int num_frases;
  int num_paraules;
  map <string, int> mapfreq; //per a les funcions de cerca
  vector <pair<string,int> > taulafreq; //per a la funcio taula freqs
  set <string> paraules;
  string inicials_priv;
	/*void arbreExpresio(const string &exp,Arbre<Expressio> &a){ //a partir de un string construim un arbre d'expresions.
		
	}
	void i_arbreExpressio(const string &exp,Arbre<Expressio> &a,int &i){
		Arbre<Expressio>a1,a2;
		if(exp[i]=='('){
			++i; i_arbreExpressio(exp,a1,i);
		}
		else {
			string etiq;
			llegir_etiq(exp,i,etiq);
			Expressio e("tipus_paraula",etiq);
			Arbre<Expressio> b1,b2;
			a1.plantar(e,b1,b2);
		}
		char op=exp[i]; ++i;
		if(exp[i]=='('){
			++i; i_arbreExpressio(exp,a2,i);
		}
		else {
			string etiq;
			llegir_etiq(exp,i,etiq);
			Expressio e("tipus_paraula",etiq);
			Arbre<Expressio> b1,b2;
			a1.plantar(e,b1,b2);
		}
		int tipus=2; //and.
		if (op==',') tipus=3; //OR.
		Expressio e(tipus,'');
		a.plantar(a1,a2);
		++i;*/
//}
	public:
  Text(); //constructora por defecto para el ulttext          
	//Constructores  
  /** @brief Creadora de textos. 

      
      \pre <em>cert</em>
      \post el resultat és un text amb titol = titoltxt, autor = autortxt i contingut = vector <string> continguttxt, on a cada posició del vector hi haurà una frase del text.
        TaulaFreq s'inicialitza i s'omple ara per a fer més ràpid "void taulafreq();"
  */ 
	Text (string titoltxt,string autortxt,vector< vector<string> > contingutaux); 

	
        
	//Destructores
  /** @brief Destructora de textos. 

      
      esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat
  */ 	
	~Text();
	
        
        //Modificadores
  /** @brief Substitueix paraules. 

      
      \pre <em>cert</em>
      \post  canvia totes les aparicions de <paraula1> per <paraula2> en el contingut del paràmetre implicit.
  */         
  void substitueix(string paraula1, string paraula2);

  void taulafrequs (vector<vector<string> > continguttxt);
            
            
        //Consultores
  /** @brief Comprovador de presència. 

      Mira si al text es troben les paraules desitjades
      \pre <em>cert</em>
      \post  retorna cert si es troba en el paràmetre implícit totes les paraules contingudes al vector, altrament, retorna fals.
  */         
	bool conteParaules(vector <string>paraulesbuscar); 

  /** @brief Informació del text. 

      \pre <em>cert</em>
      \post  mostra l'autor, títol, nombre de frases, nombre de paraules i cites associades del paràmetre implícit.
  */   	        
//	void info(); 

  /** @brief Autor. 

      \pre <em>cert</em>
      \post  mostra l'autor del paràmetre implícit.
  */         
	string consulta_auto()const;
	
	string consulta_inicials()const;
	
	string consulta_titol() const;

  /** @brief Contingut. 

      \pre <em>cert</em>
      \post mostra el contingut del paràmetre implicit amb les seves frases numerades a partir de l'1.
  */            
	vector<vector<string> > consulta_contingut() const;



  /** @brief Número de frases. 

      \pre <em>cert</em>
      \post mostra el nombre de frases del contingut del paràmetre implícit.
  */ 
	int numero_frases();

  /** @brief Número de paraules. 

      \pre <em>cert</em>
      \post mostra el nombre de paraules del contingut del paràmetre implícit.
  */         
	int num_par();

  /** @brief Taula de freqüències. 

      \pre <em>cert</em>
      \post  Trenca el contingut paraula per paraula i conta quans cops apareix cada una d'elles en el transcurs del text.
  */           
	vector <pair<string,int> > taulafreqs();

  /** @brief Frases amb expressió. 

      \pre <em>cert</em>
      \post  mostra les frases del contingut del paràmetre implícit que compleixen l'expressió boleana determinada pel "símbol".
  */        
	void frasesexpresio(vector<string> paraula1,char simbol ,vector <string> paraula2);

  /** @brief Frases seqüència de paraules. 

      \pre <em>cert</em>
      \post  mostra les frases on hi apareix, consecutivament, obviant els signes de puntuació, la seqüència de paraules <em>paraula1</em>, <em>paraula2</em>...<em>paraulaN</em> en el contingut del paràmetre implícit

  */          
	void frasesparaules(vector<string> paraules);
        
};
#endif
