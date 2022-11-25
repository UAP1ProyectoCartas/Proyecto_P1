#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

const int KMAXCHAR = 100;
const int KMAXCARTAS = 4;
const string RULE_1 = "EL juego consiste en una pelea de numeros, al principio se repartiran 3 cartas a cada jugador. Cada carta tendra su VIDA Y ATAQUE, el cual es igual a su numero. Y cada jugador al principio de cada partida tendra 10 de vida. Mediante ataques de las cartas en el momento en que uno de los dos pierda las 3 cartas que tiene acabara la partida perdiendo.";
const string RULE_2 = "Enter list name: ";
const string RULE_3 = "Enter list name: ";

// Estructura de la carta
struct TCarta{
  int vida;
  int ataque;
};  

// Estructura del jugador
struct TUsuario{
    int opcion;
    int vida;
    bool magica;
    TCarta cartasu[KMAXCARTAS];
};

// Estructura de la maquina
struct TMaquina{
    int opcion;
    int vida;
    char naturaleza;
    TCarta cartasm[KMAXCARTAS];
};

// Ejemplos de errores que se pueden dar
enum Error {
    ERR_OPTION,
    ERR_NUMBER
};

// Funcion que muestra los errores
void error(Error e) {
  switch (e) {
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_NUMBER:
      cout << "ERROR: wrong number" << endl;
      break;
  }
}

// Función auxiliar para ayudar a que no hayan errores internos en el programa
void correccionnumeros(bool usuario, bool maquina,TUsuario &usu, TMaquina &maq){
    cout<<"Por el bien del juego, hemos hecho unos cambios en los valores de sus cartas los cuales no afectaran mucho." << endl;
    if(usuario==true && maquina==false){
        do{
            for(int i=0; i<KMAXCARTAS-1; i++){
                for(int j=0; j<KMAXCARTAS-1; j++){
                    for(int k=0; k<KMAXCARTAS-1; k++){
                        if(usu.cartasu[i].vida==usu.cartasu[j].vida){
                            usu.cartasu[i].vida=usu.cartasu[i].vida-1;
                            usu.cartasu[j].vida=usu.cartasu[j].vida+1;
                        }
                        if(usu.cartasu[j].vida == usu.cartasu[k].vida){
                            usu.cartasu[j].vida=usu.cartasu[j].vida-1;
                            usu.cartasu[k].vida=usu.cartasu[k].vida+1;
                        }
                        if(usu.cartasu[i].vida==usu.cartasu[k].vida){
                            usu.cartasu[i].vida=usu.cartasu[i].vida-1;
                            usu.cartasu[k].vida=usu.cartasu[k].vida+1;
                        }
                    }
                }
            }
        }while(usu.cartasu[0].vida==usu.cartasu[1].vida || usu.cartasu[0].vida==usu.cartasu[2].vida || usu.cartasu[0].vida==usu.cartasu[3].vida || usu.cartasu[1].vida==usu.cartasu[2].vida);
    }
    if(maquina==true && usuario==false){
        do{
            for(int i=0; i<KMAXCARTAS-1; i++){
                for(int j=0; j<KMAXCARTAS-1; j++){
                    for(int k=0; k<KMAXCARTAS-1; k++){
                        if(maq.cartasm[i].vida==maq.cartasm[j].vida){
                            maq.cartasm[i].vida=maq.cartasm[i].vida-1;
                            maq.cartasm[j].vida=maq.cartasm[j].vida+1;
                        }
                        if(maq.cartasm[j].vida == maq.cartasm[k].vida){
                            maq.cartasm[j].vida=maq.cartasm[j].vida-1;
                            maq.cartasm[k].vida=maq.cartasm[k].vida+1;
                        }
                        if(maq.cartasm[i].vida==maq.cartasm[k].vida){
                            maq.cartasm[i].vida=maq.cartasm[i].vida-1;
                            maq.cartasm[k].vida=maq.cartasm[k].vida+1;
                        }
                    }
                }
            }
        }while(maq.cartasm[0].vida==maq.cartasm[1].vida || maq.cartasm[0].vida==maq.cartasm[2].vida || maq.cartasm[1].vida==maq.cartasm[2].vida);
    }
 }


 void correccionzeros(bool usuario, bool maquina,TUsuario &usu, TMaquina &maq){
    if(usuario==true && maquina==false){
            for(int i=0; i<KMAXCARTAS-1; i++){
                for(int j=0; j<KMAXCARTAS-1; j++){
                    for(int k=0; k<KMAXCARTAS-1; k++){
                            if(usu.cartasu[i].vida==0 && usu.cartasu[j].ataque==0){
                                usu.cartasu[i].vida=0;
                                usu.cartasu[j].vida=0;
                            }
                            if( usu.cartasu[i].vida==0 && usu.cartasu[k].vida==0){
                                usu.cartasu[i].vida=0;
                                usu.cartasu[k].vida=0;
                            }
                            if(usu.cartasu[j].ataque==0 && usu.cartasu[k].vida==0){
                                usu.cartasu[j].vida=0;
                                usu.cartasu[k].vida=0;
                            }
                        }
                }
            }
        }
    if(maquina==true && usuario==false){
        for(int i=0; i<KMAXCARTAS-1; i++){
            for(int j=0; j<KMAXCARTAS-1; j++){
                for(int k=0; k<KMAXCARTAS-1; k++){
                        if(maq.cartasm[i].vida==0 && maq.cartasm[j].ataque==0){
                            maq.cartasm[i].vida=0;
                            maq.cartasm[j].vida=0;
                        }
                        if(maq.cartasm[i].vida==0 && maq.cartasm[k].vida==0){
                            maq.cartasm[i].vida=0;
                            maq.cartasm[k].vida=0;
                        }
                        if(maq.cartasm[j].ataque==0 && maq.cartasm[k].vida==0){
                            maq.cartasm[j].vida=0;
                            maq.cartasm[k].vida=0;
                        }
                    }
                }
            }
        }
 }

 void mapa(TUsuario &usu, TMaquina &maq){
    cout<<"Sus cartas   Las de la Maquina"<<endl;
    for(int i=0; i<KMAXCARTAS-1;i++){
        cout<<usu.cartasu[i].vida<<" ";
    }
    cout<<"         ";
    for(int i=0;i<KMAXCARTAS-1;i++){
        cout<<maq.cartasm[i].vida<<" ";
    }
    cout<<endl;
 }


// Funcion que muestra lo que puede hacer el usuario
void showTurnUsu(TUsuario &usu, TMaquina &maq) {
    if(maq.cartasm[0].vida==0 && maq.cartasm[1].vida==0 && maq.cartasm[2].vida==0 || usu.cartasu[0].vida==0 && usu.cartasu[1].vida==0 || usu.cartasu[0].vida==0 && usu.cartasu[2].vida==0 || usu.cartasu[1].vida==0 && usu.cartasu[2].vida==0 || usu.cartasu[1].vida==0 && usu.cartasu[2].vida==0 && usu.cartasu[0].vida==0){
        correccionzeros(true,false,usu, maq);
    }
    if(usu.cartasu[0].vida==0 && usu.cartasu[1].vida==0 && usu.cartasu[2].vida==0 || maq.cartasm[0].vida==0 && maq.cartasm[1].vida==0 || maq.cartasm[0].vida==0 && maq.cartasm[2].vida==0 || maq.cartasm[1].vida==0 && maq.cartasm[2].vida==0 || maq.cartasm[0].vida==0 && maq.cartasm[1].vida==0 && maq.cartasm[2].vida==0){
        correccionzeros(false,true,usu, maq);
    }
    if((usu.cartasu[0].vida==usu.cartasu[1].vida && usu.cartasu[0].vida!=0 && usu.cartasu[1].vida!=0) || (usu.cartasu[0].vida==usu.cartasu[2].vida && usu.cartasu[0].vida!=0 && usu.cartasu[2].vida!=0) || (usu.cartasu[1].vida==usu.cartasu[2].vida && usu.cartasu[1].vida!=0 && usu.cartasu[2].vida!=0)){
        correccionnumeros(true,false,usu, maq);
    }
    if((maq.cartasm[0].vida==maq.cartasm[1].vida && maq.cartasm[0].vida!=0 && maq.cartasm[1].vida!=0) || (maq.cartasm[0].vida==maq.cartasm[2].vida && maq.cartasm[0].vida!=0 && maq.cartasm[2].vida!=0) || (maq.cartasm[1].vida==maq.cartasm[2].vida && maq.cartasm[1].vida!=0 && maq.cartasm[2].vida!=0)){
        correccionnumeros(false,true,usu, maq);
    }

    mapa(usu, maq);
    
    if(usu.magica==true){
        cout << "Que vas a querer hacer?" << endl
       << "1- Atacar" << endl
       << "2- Usar magia" << endl
       << "Opcion:";
    }
    else{
        cout << "Que vas a querer hacer?" << endl
       << "1- Atacar" << endl
       << "Opcion:";
    }
    cout<<usu.vida<<"   "<<maq.vida<<endl;
  
}

// Funcion que muestra los diferentes poderes de la magia
void magia(){
    int magic=rand() % 5 + 1;
    switch(magic){
        case 1: cout<<"Tu poder otorga a una carta tuya +2 de Ataque"<<endl;
            break;
        case 2: cout<<"Tu carta obtiene +1 de vida"<<endl;
            break;
        case 3: cout<<"Se te elimina una carta automaticamente"<<endl;
            break;
        case 4: cout<<"El enemigo tiene +3 de vida"<<endl;
            break;
    }
}

// Donde se haran todos los calculos de los ataques y de las defensas
void operaciones(TUsuario &usu, TMaquina &maq, int &contador){
    int resultado;
    bool dead;
    if(usu.cartasu[3].vida>=maq.cartasm[3].vida){
        resultado=0;
        maq.vida=maq.vida-maq.cartasm[3].vida;
    }
    else{
        resultado=maq.cartasm[3].vida-usu.cartasu[3].vida;
        maq.vida=maq.vida-resultado;
    }
        
    cout<<"Has hecho un ataque de "<<usu.cartasu[3].vida<<" de ATK. Con lo cual ahora a la carta enemiga le queda de vida: "<<resultado<<endl;
    
    for(int i=0;i<KMAXCARTAS-1;i++){
        if(maq.cartasm[3].vida==usu.cartasu[3].vida+resultado && maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[i].vida=resultado;
            dead=false;
        }
        if(resultado==0 && usu.cartasu[3].vida>=maq.cartasm[3].vida && maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[i].vida=resultado;
            dead=true;
        }
    }
    if(dead==true){
        cout<<"Has derribado una carta"<<endl;
        contador++;
    }
    mapa(usu, maq);

}

void usomagico(TUsuario &usu, TMaquina &maq){
    cout<<"Tu poder era: ";
}



// Funcion donde el usuario elegirá que carta atacar y con cual
void attack(TUsuario &usu, TMaquina &maq,int &contador){
    int option;
    bool mal=true;
    do{
        mal=true;
        cout<<"Con que carta vas a querer atacar ("<<usu.cartasu[0].vida<<" "<<usu.cartasu[1].vida<<" "<<usu.cartasu[2].vida<<") ->";
        cin>>option;
        if((option==usu.cartasu[0].vida) || (option==usu.cartasu[1].vida) || (option==usu.cartasu[2].vida)){
            mal=true;
            usu.cartasu[3].vida=option;
        }
        else{
            error(ERR_NUMBER);
            mal=false;
        }
    }while(mal!=true);
    
    do{
        mal=true;
        cout<<"A que carta vas a querer atacar ("<<maq.cartasm[0].vida<<" "<<maq.cartasm[1].vida<<" "<<maq.cartasm[2].vida<<") ->";
        cin>>option;
        if((option==maq.cartasm[0].vida) || (option==maq.cartasm[1].vida) || (option==maq.cartasm[2].vida)){
            mal=true;
            maq.cartasm[3].vida=option;
        }
        else{
            error(ERR_NUMBER);
            mal=false;
        }
    }while(mal!=true || option==0);
    operaciones(usu,maq,contador);
}



int maxusu(TUsuario &usu){
    int max=0;
    for(int i=0; i<KMAXCARTAS-1; i++){
        if(usu.cartasu[i].vida>max){
            max=usu.cartasu[i].vida;
        }
    }
    return max;
}

int maxmaq(TMaquina &maq){
    int max=0;
    for(int i=0; i<KMAXCARTAS-1; i++){
        if(maq.cartasm[i].vida>max){
            max=maq.cartasm[i].vida;
        }
    }
    return max;
}


// Funcion donde la maquina elegirá que carta atacar y con cual
void ataqueia(TUsuario &usu, TMaquina &maq){
    int aux=0;
    int resultado;
    bool dead;
    usu.cartasu[3].vida=maxusu(usu);
    maq.cartasm[3].vida=maxmaq(maq);
    cout<<"Turno del enemigo: Te va a atacar con su -> "<<maq.cartasm[3].vida<<" a tu siguiente carta -> "<<usu.cartasu[3].vida<<endl;
    if(usu.cartasu[3].vida<=maq.cartasm[3].vida){
        resultado=0;
        usu.vida=usu.vida-usu.cartasu[3].vida;
    }
    else{
        resultado=usu.cartasu[3].vida-maq.cartasm[3].vida;
        usu.vida=usu.vida-resultado;
    }
    for(int i=0;i<KMAXCARTAS-1;i++){
        if(usu.cartasu[3].vida==maq.cartasm[3].vida+resultado && usu.cartasu[i].vida==usu.cartasu[3].vida){
            usu.cartasu[i].vida=resultado;
            dead=false;
        }
        if(resultado==0 && usu.cartasu[3].vida<=maq.cartasm[3].vida && usu.cartasu[i].vida==usu.cartasu[3].vida){
            usu.cartasu[i].vida=resultado;
            dead=true;
        }
    }
    if(dead==true){
        cout<<"Te han derribado una carta"<<endl;
    }
}
// 
void repartircartas(TUsuario &usu, TMaquina &maq){
    
    for(int i=0;i<KMAXCARTAS-1;i++){
        usu.cartasu[i].vida=rand() % 7 + 1;
        do{
            if(usu.cartasu[0].vida==usu.cartasu[1].vida || usu.cartasu[0].vida==usu.cartasu[2].vida){
                usu.cartasu[0].vida=rand() % 7 + 1;
            } 
            if(usu.cartasu[1].vida==usu.cartasu[2].vida){
                usu.cartasu[1].vida=rand() % 7 + 1;
            }
        }while(usu.cartasu[0].vida==usu.cartasu[1].vida && usu.cartasu[0].vida==usu.cartasu[2].vida && usu.cartasu[1].vida==usu.cartasu[2].vida);
    }
    
    for(int i=0;i<KMAXCARTAS-1;i++){
        maq.cartasm[i].vida=rand() % 7 + 1;
        do{
            if(maq.cartasm[0].vida==maq.cartasm[1].vida || maq.cartasm[0].vida==maq.cartasm[2].vida){
                maq.cartasm[0].vida=rand() % 7 + 1;
            } 
            if(maq.cartasm[1].vida==maq.cartasm[2].vida){
                maq.cartasm[2].vida=rand() % 7 + 1;
            }
        }while(maq.cartasm[0].vida==maq.cartasm[1].vida && maq.cartasm[0].vida==maq.cartasm[2].vida && maq.cartasm[1].vida==maq.cartasm[2].vida);
        
    }
    for(int i=0;i<KMAXCARTAS-1;i++){
        usu.vida=usu.vida+usu.cartasu[i].vida;
    }
    maq.vida=maq.cartasm[0].vida+maq.cartasm[1].vida+maq.cartasm[2].vida;
    cout<<endl;
    
    if(usu.magica==false && ((usu.vida-maq.vida)>=4 || (maq.vida-usu.vida)>=4)){
        usu.magica=true;
        maq.naturaleza=true;
    }
}

void versusmachine(TUsuario &usu, TMaquina &maq, int &contador){
        maq.vida=20;
        if((rand() % 2)==1){
            usu.magica=false;
        }
        else{
            usu.magica=true;
            maq.naturaleza=true;
        }
        repartircartas(usu,maq);
        
        
        if(usu.magica==false){
            cout<<"No tienes ninguna carta mágica"<<endl;
            cout<<endl;
        }
        else{
            cout<<"Tienes solo 1 carta mágica"<<endl;
            magia();
            cout<<"El enemigo puede tener una Naturaleza"<<endl;
            cout<<endl;
        }
        cout<<"Se reparten 3 cartas"<<endl;    
        do{
            showTurnUsu(usu, maq);
            int option;
            cin>>option;
            switch(option){
                case 1:attack(usu, maq,contador);
                    break;
                case 2: usomagico(usu,maq);
                    break;
                default:error(ERR_OPTION);
            }
            if(maq.vida!=0){
                ataqueia(usu,maq);
            }
        }while((usu.vida!=0 || maq.vida!=0) || contador!=3);
}


void showRulesMenu() {
  cout << "[REGLAS]" << endl
       << "1- ¿Como jugar?" << endl
       << "2- Cartas" << endl
       << "3- Naturaleza" << endl
       << "v- Volver al menu"<< endl
       << "Opcion:";
}


void rules(){
    char option;
    do{
        showRulesMenu();
        cin>>option;
        switch (option) {
          case '1': cout<<RULE_1<<endl;
             break;
          case '2': cout<<RULE_2<<endl;
             break;
          case '3': cout<<RULE_3<<endl;
            break;
          case 'v':
             break;
          default:
            error(ERR_OPTION);
        }
    }while(option!='v');
}

void showMainMenu() {
  cout << "[MENU]" << endl
       << "1- Con Poderes" << endl
       << "2- Reglas" << endl
       << "s- Salir"<< endl
       << "Opcion:";
}

int main(){
    TMaquina maq;
    TUsuario usu;
    char option;
    int contador=0;
    usu.vida=maq.vida=0;
    do{
        srand(time(NULL));
        showMainMenu();
        cin>>option;
        cin.get();
        
        switch (option) {
            //En vez de crear dos modulos distintos para cada tipo de juego por si lo queremos con o sin magia
            //lo hacemos todo con el mismo modulo con un booleano el cual pasara true o false al modulo y se pondra uno o otro
          case '1': versusmachine(usu,maq,contador);
             break;
          case '2': rules();
            break;
          case 's':
             break;
          default:
            error(ERR_OPTION);
        }
    }while(option!='s'); 
    return 0;
}
