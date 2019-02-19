/** @file Cita.hh
    @brief Especificació de la classe Cita
*/
#ifndef CITA_HH
#define CITA_HH

#include "Text.hh"
#ifndef NO_DIAGRAM 
#include <string>
#include <vector>
#include <iostream>
#endif
using namespace std;
/** @class Cita
    @brief Representa una cita dins del tetx

    Conté identificador, contingut, text de procedència, frase inicial i final.
*/
class Cita{
     private:
       string id;
       vector <vector <string> >contingut_cita;
       int _x; //línia inicial
       int _y; // línia final
       string titlprocedent; //texto de procedencia para sacar el contenido, autor...*/
       string autrprocedent;
     public:
         
        //Creadores
    /** @brief Creadora. 

        S'executa automàticament al declarar una cita.
        \pre <em>cert</em>
        \post el resultat és una cita amb un id = referencia, amb un contingut i un valor x (frase inicial) i un valor y (frase final) del text d'on procedeixen
  */           
	Cita(string referencia,const Text &proceden,int ini,int fi);

        
        //Consultores
  /** @brief Informació de la cita
      \pre <em>cert</em>
      \post retorna informació de la cita: autor, títol, número de la frase inicial i número de la frase final i contingut de la frase o frases que la composen.
  */  
	void info(); 

  /** @brief Referència de la cita
      \pre <em>cert</em>
      \post retorna la referència de la cita.
  */          
	string referencia(); //serveix per donar la referència de set<Cita>

  /** @brief Text de procedència de la cita
      \pre <em>cert</em>
      \post retorna el text de procedència de la cita.
  */          
	string txt();

  /** @brief Frase inicial de la cita
      \pre <em>cert</em>
      \post retorna la frase inicial de la cita.
  */        
	int valor_x();

  /** @brief Frase final de la cita
      \pre <em>cert</em>
      \post retorna la frase final de la cita.
  */          
	int valor_y();
	
	string aut_procedent() const;
	
	string cita_num(int x) const;
	
	string tit_proc () const;
	void imp_contingut();
};
#endif
	
