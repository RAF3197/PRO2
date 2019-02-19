#include "Cita.hh"
Cita::Cita(){}
Cita::Cita(string referencia,const Text &proceden,int ini,int fi){
    _x=ini;
    _y=fi;
    id=referencia;
    titlprocedent=proceden.consulta_titol();
    autrprocedent=proceden.consulta_auto();
    vector<vector<string> >aux=proceden.consulta_contingut();
    contingut_cita.resize(fi-ini+1);
    int fila = 0;
    for (int k=ini-1;k<fi;++k){
        contingut_cita[fila]=aux[k];
        ++fila;
    }
}


void Cita::info(){
    cout<<autrprocedent<<" "<<'"'<<titlprocedent<<'"'<<endl;
    cout<<_x<<"-"<<_y<<endl;
    int numero=_x;
    for (int i=0;i<contingut_cita.size();++i){
        cout<<numero<<" "<<contingut_cita[i]<<endl;
        ++numero;
    }
}

string Cita::referencia(){
    return id;
}

string Cita::txt(){
    return titlprocedent;
}

int Cita::valor_x(){
    return _x;
}

int Cita::valor_y(){
    return _y;
}

string Cita::aut_procedent() const{
    return autrprocedent;
}

string Cita::cita_num(int x) const{ //mirar y corregir esta
    return contingut_cita[x-1];
}

string Cita::tit_proc() const{
    return titlprocedent;
}

void Cita::imp_contingut(){
    int k=valor_x();

    for (int i=0;i<contingut_cita.size();++i){
    bool primer = true;
    bool ultim = false;
    cout << k << " ";
    for (int j=0;j<contingut_cita[i].size();++j){
      bool puntuacio =false;
      if (j == contingut_cita[i].size()-1) {ultim = true;}
      if (contingut_cita[i][j] == "," or contingut_cita[i][j] == ";" or contingut_cita[i][j] == ":") puntuacio = true;
      if (primer){
        primer = false;
        cout << contingut_cita[i][j];
      }
      else if (ultim) cout << contingut_cita[i][j];
      else if (puntuacio) cout << contingut_cita[i][j];
      else cout<<" "<<contingut_cita[i][j];
    }
    cout <<endl;
    ++k;
  }
}