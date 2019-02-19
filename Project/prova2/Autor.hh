#ifndef AUTOR_HH
#define AUTOR_HH

#include <string>

using namespace std;

class Autor {
    private:
        string nom;
        string inicials;
    
    public:
        //Constructora
	Autor (string nomautor);
        /* Pre: cert.
         * Post: el resultat és un autor amb nom = nomautor */
        
        //Destructora
        ~Autor();
        
        //Consultora
	string nom() const;
        /* Pre: cert
         * Post: es retorna el nom del paràmetre implicit */
        
	string inicials() const;
        /* Pre: cert
         * Post: es retornen les inicials del paràmetre implicit */
};
#endif
		
