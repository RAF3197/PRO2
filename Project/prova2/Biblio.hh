#include <set>
#include <map>
#include <string>
#include <vector>
#include "Text.hh"
#include "Cita.hh"
#include "Autor.hh"



class Biblioteca{
  //Creem una estructura on guardarem tant els textos com les cites, en dues estructures de dades diferenciades
  
	private:
	  
	  //textos
	map<string, map<string, text> > biblio; //map <autor, map <títol, text> > biblioteca
	
	map<string, map<string, text> >::iterator ultimtxt; //iterador a l'últim text triat
	
	  //Cites
	set<Cita> cites;  //Conjunt de cites ordenades per referència
	
	map<string,set<set<Cita>::iterator> >_citesAutor; //soluciona citesAutor.
	
	map<string,set<Cita>::iterator>>_citesRef;
        
	map<string,int>_refIni; 
	
	map<set<Text>::iterator,set<Cita>::iterator> >_citestxt; //solventa cites?.
	
	
	
	public:
	
        //Constructores
        
        Biblioteca();
        /* Pre: cert */
        /* Post: el resultat es una biblioteca amb un diccionari d'autors i els seus textos buit.  */
        
        //Destructora
        
        ~Biblioteca();
        //esborra automaticament els objectes locals en sortir
        //d'un ambit de visibilitat
        
        //Modificadores de Textos
        
        void AfegirText(const Text &txt);
	/* pre: cert*/
        /* post: Si l'autor ja existia, s'ha                                                                        
         * afegit aquest text com un més a la seva colecció de textos ordenats         
         * alfabèticament per títol. Si no hi era, es crea una nova entrada 
         *       amb el nom de l'autor i se li afegeix aquest text.
                 Si el text que s'intenta afegir coincideix en títol i autor amb un que ja és al sistema, es produeix un missatge d'error*/
	
	void TriarText(vector<string> paraules);
	//pre:l'entrada és una seqüència de paraules
	//post: si les paraules es troben a un text i a cap més, ultimtxt apunta al text triat, sinó, es produeix un missatge d'error
	
	void EliminarText();
	/* pre: la biblioteca no és buida i s'ha seleccionat un text amb l'opció TriarText
	 * post: s'elimina del sistema l'últim text triat*/
	
	void SubText(string paraula1, string paraula2);
	//pre: paraula1 i paraula2 són paraules de ultimtxt
	//post: canvia les aparicions de <paraula1> per <paraula2> en el contingut de l'últim text triat.
	
        
        //Consultora de textos
        
	void TextosAutor(string autor);
	//pre: l'autor existeix a la biblioteca
	//post: mostra tots els textos d'un determinat autor (només el títol de cada text) ordenats alfabèticament per títol
	
	void TotsTextos();
	//pre:cert
	//post: mostra tots els textos enmagatzemats al sistema (només el títol i l'autor de cada text) ordenats alfabèticament per títol.
	
	void TotsAutors();
	//pre: cert
	//post: mostra tots els autors amb textos en el sistema indicant per a cadascun el nombre de textos que hi consten, el nombre total de frases i de paraules del contingut dels seus textos (els autors apareixen ordenats alfabèticament).
	
	void info();
	//pre: hi ha un text seleccionat
	//post: mostra informació de l'últim text triat: autor, títol, nombre de frases, nombre de paraules i cites associades.
	
	void autor();
	//pre: hi ha un text seleccionat
	//post: mostra l'autor de l'últim text triat
	
	void contingut();
	//pre: hi ha un text seleccionat 
	//post: mostra el contingut de l'últim text triat amb les seves frases numerades a partir de l'1.
	
	void frases(int x, int y);
	//pre: hi ha un text seleccionat i l'interval de frases és vàlid, és a dir, 1<=x<=y<=n, on n és el nombre total de frases
	//post: mostra les frases entre la x-èssima i la y-èssima del contingut de l'últim text triat
	
	void nombrefrases();
	//pre: hi ha un text seleccionat
	//post: mostra el nombre de frases del contingut de l'últim text triat
	
	void nombreparaules();
	//pre: hi ha un text seleccionat
	//post: mostra el nombre de paraules del contingut de l'últim text triat
	
	void tauladefrecuencies();
	//pre: hi ha un text seleccionat
	//post: mostra totes les paraules de l'últim text triat ordenades decreixentment per freqüència. 
	
	void frasesexpresio(vector<string> paraula1,char simbol ,vector <string> paraula2);
	//pre: hi ha un text seleccionat i el símbol és "&" o "|"
	//post: mostra les frases del contingut de l'últim text triat que compleixen l'expressió boleana determinada pel "símbol"
	
	void frasesparaules(vector<string> paraules);
	//pre: hi ha un text seleccionat
	//post:mostra les frases on hi apareix, consecutivament, obviant els signes de puntuació, la seqüència de paraules <paraula1>, <paraula2>...<paraulaN> en el contingut de l'últim text triat.
	
        
        //Modificadores de Cites
	
        void afegircita(int x, int y);
	//pre: hi ha un text seleccionat
	//post: si no existia una cita amb el mateix nom i autor que la que s'està introduïnt, i l'interval de x i y està entre 1<=x<=y<=n, on n és el nombre total de frases, afegeix una cita al sistema basada en les frases que van de la x-èsima a la y-èsima del contingut del text triat. Altrament es produeix un error.
        
        void eliminarcita(referencia);
	//pre: cert
	//post: si existeix, elimina la cita amb codi <referencia> del sistema, altrament produeix un missatge d'error.
	
        //Consultora de cites
        
	void infocita(referencia);
	//pre: cert
	//post: si existeix, mostra informació de la cita: l'autor, el títol, el número de frase inicial i número de frase final, contingut de la frase o frases que la componen. Si no existeix, es genera un missatge d'error.
	
	void citesAutor(const comanda &c);
	//pre: cert
	//post:
	
	void cites();
	//pre:
	//post:
	
	void totescites();
	//pre:
	//post:
	
	
	
}

