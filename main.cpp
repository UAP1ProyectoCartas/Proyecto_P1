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
    int tipo_magia;
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
    ERR_NUMBER,
    ERR_MAGIC
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
    case ERR_MAGIC:
        cout << "ERROR: wrong magic" << endl;
        break;
  }
}

// Función auxiliar para ayudar a que no hayan errores internos en el programa
void correccionnumeros(bool usuario, bool maquina,TUsuario &usu, TMaquina &maq){
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
                            if(usu.cartasu[i].vida==0 && usu.cartasu[j].vida==0){
                                usu.cartasu[i].vida=0;
                                usu.cartasu[j].vida=0;
                            }
                            if( usu.cartasu[i].vida==0 && usu.cartasu[k].vida==0){
                                usu.cartasu[i].vida=0;
                                usu.cartasu[k].vida=0;
                            }
                            if(usu.cartasu[j].vida==0 && usu.cartasu[k].vida==0){
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
                        if(maq.cartasm[i].vida==0 && maq.cartasm[j].vida==0){
                            maq.cartasm[i].vida=0;
                            maq.cartasm[j].vida=0;
                        }
                        if(maq.cartasm[i].vida==0 && maq.cartasm[k].vida==0){
                            maq.cartasm[i].vida=0;
                            maq.cartasm[k].vida=0;
                        }
                        if(maq.cartasm[j].vida==0 && maq.cartasm[k].vida==0){
                            maq.cartasm[j].vida=0;
                            maq.cartasm[k].vida=0;
                        }
                    }
                }
            }
        }
 }

 void ganarperder(bool ganado, bool perdido, TUsuario &usu, TMaquina &maq){
    if(ganado==true){
        cout<<"Felicidades, has ganado el juego." << endl;
        cout<<"Este ha sido el resultado:" << endl;
        cout<< "Vida del jugador: " << usu.vida << endl;
        cout<< "Vida de la maquina: "<< maq.vida << endl;
    }
    if(perdido==true){
        cout<<"Lo siento, has perdido el juego." << endl;
        cout<<"Este ha sido el resultado:" << endl;
        cout<< "Vida del jugador: " << usu.vida << endl;
        cout<< "Vida de la maquina: "<< maq.vida << endl;
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
    for(int i=0; i<KMAXCARTAS-1;i++){
        cout<<"("<<usu.cartasu[i].ataque<<")";
    }
    cout<<"     ";
    for(int i=0;i<KMAXCARTAS-1;i++){
        cout<<"("<<maq.cartasm[i].ataque<<")";
    }
    cout<<endl;
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

// Funcion que muestra los diferentes poderes de la magia
int switchmagia(){
    int magic=rand() % 4 + 1;
    switch(magic){
        case 1: cout<<"Tu poder otorga a una carta tuya +2 de Ataque"<<endl;
            break;
        case 2: cout<<"Tu carta obtiene +1 de vida"<<endl;
            break;
        case 3: cout<<"Todas las cartas obtienen +1 de ataque y -1 de vida"<<endl;
            break;
        case 4: cout<<"Puedes revivir un carta pero solo tendrá 1 de vida"<<endl;
            break;
    }
    return magic;
}

void usomagico(TUsuario &usu, int &type_magic, int &contador){
    int option;
    switch(type_magic){
        case 1: cout<<"Que carta quieres que aumente su ataque? ("<<usu.cartasu[0].vida<<" "<<usu.cartasu[1].vida<<" "<<usu.cartasu[2].vida<<") ->";
                cin>>option;
                if((option==usu.cartasu[0].vida) || (option==usu.cartasu[1].vida) || (option==usu.cartasu[2].vida)){
                    usu.cartasu[3].vida=option;
                }
                for(int i=0;i<KMAXCARTAS-1;i++){
                    if(usu.cartasu[i].vida==usu.cartasu[3].vida){
                        usu.cartasu[i].ataque=usu.cartasu[i].ataque+2;
                    }
                }
            break;
        case 2: cout<<"Que carta quieres que aumente su vida? ("<<usu.cartasu[0].vida<<" "<<usu.cartasu[1].vida<<" "<<usu.cartasu[2].vida<<") ->";
                cin>>option;
                if((option==usu.cartasu[0].vida) || (option==usu.cartasu[1].vida) || (option==usu.cartasu[2].vida)){
                    usu.cartasu[3].vida=option;
                }
                for(int i=0;i<KMAXCARTAS-1;i++){
                    if(usu.cartasu[i].vida==usu.cartasu[3].vida){
                        usu.cartasu[i].vida=usu.cartasu[i].vida+1;
                    }
                }
            break;
        case 3: for(int i=0;i<KMAXCARTAS-1;i++){
                    if(usu.cartasu[i].vida!=0){
                        usu.cartasu[i].vida=usu.cartasu[i].vida-1;
                        usu.cartasu[i].ataque=usu.cartasu[i].ataque+1;
                    }
                }
            break;
        case 4: for(int i=0;i<KMAXCARTAS-1;i++){
                    if(usu.cartasu[i].vida==0){
                        usu.cartasu[i].vida=1;
                        break;
                    }
                }
            break;
    }
    contador++;
}

char switchnature(){
    char nature='a' + rand() % 4; 
    switch(nature){
        case 'a': cout<<"El enemigo tiene la Naturaleza del Agua"<<endl;
                cout<<" "<<endl;
            break;
        case 'b': cout<<"El enemigo tiene la Naturaleza del Fuego"<<endl;
                cout<<" "<<endl;
            break;
        case 'c': cout<<"El enemigo tiene la naturaleza de la Tierra"<<endl;
                cout<<" "<<endl;   
            break;
        case 'd': cout<<"El enemigo tiene la naturaleza del Aire"<<endl;
                cout<<" "<<endl;
    }
    return nature;
}

void usonaturaleza(TMaquina &maq){
    TUsuario usu;
    int elegido;
    elegido=maxusu(usu); 
    switch(maq.naturaleza){
        case 'a': for(int i=0;i<KMAXCARTAS-1;i++){
                    if(maq.cartasm[i].vida==1){
                        maq.cartasm[i].vida=maq.cartasm[i].vida+3;
                        break;
                    }
                }
                cout<< "El enemigo ha usado su naturaleza y ha aumentado la vida de una carta en 3" << endl;
         break;
        case 'b': for(int i=0;i<KMAXCARTAS-1;i++){
                    if(maq.cartasm[i].vida==0){
                        maq.cartasm[i].vida=maq.cartasm[i].vida+3;
                        break;
                    }
                }
                cout<< "El enemigo ha usado su naturaleza y ha revivido" << endl;
         break;
        case 'c': 
                cout<< "El enemigo ha usado su naturaleza y ha restado a una carta tuya ("<<elegido<<") la mitad de su vida" << endl;
                for(int i=0;i<KMAXCARTAS-1;i++){
                    if(usu.cartasu[i].vida==elegido){
                        usu.cartasu[i].vida=usu.cartasu[i].vida/2;
                    }
                }
         break;
        case 'd': for(int i=0;i<KMAXCARTAS-1;i++){
                    maq.cartasm[i].ataque=maq.cartasm[i].ataque+1;
                }
                cout<< "El enemigo ha usado su naturaleza y ha aumentado el ataque en sus cartas en +1" << endl;
        break;
        default: break;
    }
}


// Donde se haran todos los calculos de los ataques y de las defensas
void operaciones(TUsuario &usu, TMaquina &maq, int &contador){
    int resultado;
    if(usu.cartasu[3].vida+usu.cartasu[3].ataque>=maq.cartasm[3].vida){
        resultado=0;
        maq.vida=maq.vida-maq.cartasm[3].vida;
    }
    else{
        resultado=maq.cartasm[3].vida-(usu.cartasu[3].vida+usu.cartasu[3].ataque);
        maq.vida=maq.vida-usu.cartasu[3].vida+usu.cartasu[3].ataque;
    }
        
    cout<<"Has hecho un ataque de "<<usu.cartasu[3].vida+usu.cartasu[3].ataque<<" de ATK. Con lo cual ahora a la carta enemiga le queda de vida: "<<resultado<<endl;
    if(resultado==0){
        cout<<"Has derribado una carta"<<endl;
        contador++;
    }

    for(int i=0;i<KMAXCARTAS-1;i++){
        if(maq.cartasm[3].vida==usu.cartasu[3].vida+usu.cartasu[3].ataque+resultado && maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[i].vida=resultado;
        }
        if(resultado==0 && usu.cartasu[3].vida+usu.cartasu[3].ataque>=maq.cartasm[3].vida && maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[i].vida=resultado;
        }
    }
   
    mapa(usu, maq);
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
            for(int i=0;i<KMAXCARTAS-1;i++){
                if(usu.cartasu[i].vida==usu.cartasu[3].vida){
                    usu.cartasu[3].ataque=usu.cartasu[i].ataque;
                }
            }
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

// Funcion donde la maquina elegirá que carta atacar y con cual
void ataqueia(TUsuario &usu, TMaquina &maq, int &contadorm){
    int resultado;
    usu.cartasu[3].vida=maxusu(usu);
    maq.cartasm[3].vida=maxmaq(maq);
    for(int i=0;i<KMAXCARTAS-1;i++){
        if(maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[3].ataque=maq.cartasm[i].ataque;
        }
    }
    cout<<"Turno del enemigo: Te va a atacar con su -> "<<maq.cartasm[3].vida+maq.cartasm[3].ataque<<" a tu siguiente carta -> "<<usu.cartasu[3].vida<<endl;
    if(maq.cartasm[3].vida+maq.cartasm[3].ataque>=usu.cartasu[3].vida){
        resultado=0;
        usu.vida=usu.vida-usu.cartasu[3].vida;
    }
    else{
        resultado=usu.cartasu[3].vida-maq.cartasm[3].vida+maq.cartasm[3].ataque;
        usu.vida=usu.vida-maq.cartasm[3].vida+maq.cartasm[3].ataque;
    }
    if(resultado==0){
        cout<<"Te han derribado una carta"<<endl;
        contadorm++;
    }
    for(int i=0;i<KMAXCARTAS-1;i++){
        if(usu.cartasu[3].vida==maq.cartasm[3].vida+maq.cartasm[3].ataque+resultado && usu.cartasu[i].vida==usu.cartasu[3].vida){
            usu.cartasu[i].vida=resultado;
        }
        if(resultado==0 && usu.cartasu[3].vida<=maq.cartasm[3].vida+maq.cartasm[3].ataque && usu.cartasu[i].vida==usu.cartasu[3].vida){
            usu.cartasu[i].vida=resultado;
        }
    }
}

void repartircartas(TUsuario &usu, TMaquina &maq){
    
    for(int i=0;i<KMAXCARTAS-1;i++){
        usu.cartasu[i].vida=rand() % 7 + 1;
        usu.cartasu[i].ataque=0;
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
        maq.cartasm[i].ataque=0;
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
    
    if(usu.magica==false && ((usu.vida-maq.vida)>=4 || (maq.vida-usu.vida)>=4)){
        usu.magica=true;
        maq.naturaleza=true;
    }
}

void versusmachine(TUsuario &usu, TMaquina &maq, int &contador, int &contadorm){
        int cont=0;
        if((rand() % 2)==1){
            usu.magica=false;
            cout<<"No tienes ninguna carta mágica"<<endl;
            cout<<endl;
        }
        else{
            usu.magica=true;
            maq.naturaleza=true;
            cout<<"Tienes solo 1 carta mágica"<<endl;
            usu.tipo_magia=switchmagia();
            maq.naturaleza=switchnature();
            cout<<endl;
        }
        repartircartas(usu,maq);
        cout<<"Se reparten 3 cartas"<<endl;    
        do{
            showTurnUsu(usu, maq);
            int option;
            cin>>option;
            switch(option){
                case 1:attack(usu, maq,contador);
                    if(maq.vida<=6){
                        usonaturaleza(maq);
                    }
                    if(maq.vida!=0){
                        ataqueia(usu, maq, contadorm);
                    }
                    break;
                case 2: if(cont==0){
                            usomagico(usu,usu.tipo_magia,cont);
                            if(maq.vida!=0){
                                ataqueia(usu, maq, contadorm);
                            }
                        }
                        else{
                            error(ERR_MAGIC);
                        }
                    break;
                default:error(ERR_OPTION);
            }
            cout<<endl;
        }while(contador!=3 && contadorm!=3);

        if(contador==3){
            ganarperder(true,false,usu,maq);
        }
        else{
            ganarperder(false,true,usu,maq);
        }
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
    int contadorm=0;
    usu.vida=maq.vida=0;
    do{
        srand(time(NULL));
        showMainMenu();
        cin>>option;
        cin.get();
        cout<<endl;
        
        switch (option) {
            //En vez de crear dos modulos distintos para cada tipo de juego por si lo queremos con o sin magia
            //lo hacemos todo con el mismo modulo con un booleano el cual pasara true o false al modulo y se pondra uno o otro
          case '1': versusmachine(usu,maq,contador, contadorm);
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
