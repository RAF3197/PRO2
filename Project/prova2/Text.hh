#include <string>
#include <vector>
#include <set>
#include <map>
#include "Cita.hh"
#include "Autor.hh"
#include "Expressio.hh"
class Text{
	private:
	string titol; //titulo del texto
	Autor autor; //autor del texto
        vector<string> contingut; //contenido del texto ya dividido
        int frases;
        int paraules;
        set<Cita> citassoci; // cites associades
	map<string,int> TaulaFreq;
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
	}
	public:
            
	//Constructores  
	
	Text (string titoltxt,string autortxt,vector<string> continguttxt); 
        /*Pre: cert*/ 
        /*Post: el resultat és un text amb titol = titoltxt, autor = autortxt i contingut = vector <string> continguttxt, on a cada posició del vector hi haurà una frase del text(que s'ha hagut de desglossar).
        TaulaFreq s'inicialitza i s'omple ara per a fer més ràpid "void taulafreq();" */
	
        
	//Destructores
	
	~Text();
        // esborra automaticament els objectes locals en sortir
        // d'un ambit de visibilitat
	
        
        //Modificadores
        
        void substitueix(text ultimtxt, string paraula1, string paraula2);
            /*Pre: cert */
            /*Post: canvia totes les aparicions de <paraula1> per <paraula2> en el contingut de ultimtxt*/
            
            
        //Consultores
        
	bool conteParaules(vector<string>paraules); 
        /* Pre: cert
         * Post: retorna cert si es troba en el paràmetre implicit totes les paraules contingudes al vector, altrament, retorna fals */
	        
	void info(); 
            /*Pre:cert */
            /*Post: mostra l'autor, títol, nombre de frases, nombre de paraules i cites associades del paràmetre implicit */
	void consulta_auto()const;
            /*Pre: cert*/
            /*Post: mostra l'autor del paràmetre implicit*/
	void consulta_contingut()const;
            /*Pre: cert*/
            /*Post: mostra el contingut del paràmetre implicit amb les seves frases numerades a partir de l'1*/
	void frases(int x,int y);
            /*Pre:cert */
            /*Post: mostra les frases entre la x-èssima i la y-èssima del contingut del paràmetre implicit*/
	int num_frases();
            /*Pre: cert */
            /*Post: mostra el nombre de frases del contingut del paràmetre implicit */
	int num_par();
            /*Pre: cert */
            /*Post: mostra el nombre de paraules del contingut del paràmetre implicit*/
	void taulafreq();
            /*Pre: cert */
            /*Post: mostra totes les paraules del paràmetre implicit ordenades decreixentment per freqüència*/
	void frasesexpresio(vector<string> paraula1,char simbol ,vector <string> paraula2);
            /*Pre: cert*/
            /*Post: mostra les frases del contingut del paràmetre implicit que compleixen l'expressió boleana determinada pel "símbol" */
	void frasesparaules(vector<string> paraules);
            /*Pre: cert*/
            /*Post: mostra les frases on hi apareix, consecutivament, obviant els signes de puntuació, la seqüència de paraules <paraula1>, <paraula2>...<paraulaN> en el contingut del paràmetre implicit*/
}
