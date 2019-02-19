#include <string>
#include "Text.hh"
class Cita{
	inline friend bool operator <(const Cita &a,const Cita &b);
     private:
       string id; //id
       int x; //línia inicial
       int y; // línia final
       Text procedent; //texto de procedencia para sacar el contenido, autor...
     public:
         
        //Creadores
	Cita(string referencia,Text procedent,int x,int y);
	
	void info(); //relacionada amb info cita.
	
	string referencia(); //serveix per donar la referència de set<Cita>
	
	Text txt();
	
	int x();//??
	
	int y();//??
}
	
