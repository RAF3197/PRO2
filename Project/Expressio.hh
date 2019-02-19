/** @file Expressio.hh
    @brief Especificació de la classe Expressió
*/

#ifndef EXPRESSIO_HH
#define EXPRESSIO_HH
#include <string>
using namespace std;
/** @class Expressio
    @brief 

    .
*/
class Expressio{
    /*private:
    int tipo;
    string etiquet;*/
    public:
            //Constructores
    /** @brief Creadora. 

        S'executa automàticament al declarar una expressió.
        \pre <em>cert</em>
        \post Retorna una expressió amb TIPUS = tipus i ETIQUETA = etiqueta
  */          
	Expressio (int tipus, string etiqueta);

        
        //Consultores
  /** @brief Mostrar el tipus d'expressió
      \pre <em>cert</em>
      \post retorna el tipus d'etiqueta.
  */        
        int tipus() const;

  /** @brief Mostrar l'etiqueta de l'expressió
      \pre <em>cert</em>
      \post retorna l'etiqueta de l'Expressió.
  */          
	string etiqueta () const;

};
#endif
