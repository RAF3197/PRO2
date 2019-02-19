/** @file Autor.hh
    @brief Especificació de la classe Autor
*/
#ifndef AUTOR_HH
#define AUTOR_HH
#ifndef NO_DIAGRAM
#include <string>
#include <sstream>
#include <iostream>
#endif

using namespace std;
/** @class Autor
    @brief Representa un autor i les seves dades. 
    
    Conté informació relativa als autors per clarificar el codi en funcions complexes.
*/
class Autor {
    private:
        string nom_autor;
        string inicials_priv;
        int num_paraules_aut;
        int num_frases_aut;
    
    public:
        //Constructora
        /** @brief Creadora. 

        S'executa automàticament en declarar un autor.
        \pre <em>cert</em>
        \post el resultat és un autor amb nom = nomautor
  */ 
	Autor (string nomautor);
    
    Autor();
        
    //Destructora
    /** @brief Destructora per defecte. 

        Esborra automàticament els objectes locals en sortir
        d'un àmbit de visibilitat
  */ 
  ~Autor();
        
  //Consultora
  /** @brief Nom de l'autor
      \pre <em>cert</em>
      \post es retorna el nom del paràmetre implícit
  */   
	string nom() const;

  /** @brief Inicials de l'autor
      \pre <em>cert</em>
      \post es retorna les inicials del paràmetre implícit
  */        
	string inicials() const;

  int consultar_numparaules() const;

  int consultar_numfrases() const;

  void afegir_paraules (int paraules);

  void eliminar_paraules (int paraules);

  void afegir_frases(int frases);

  void eliminar_frases(int frases);

};
#endif