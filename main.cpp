#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

const int KMAXCHAR = 100;
const int KMAXCARTAS = 4;

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
    bool usado;
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

// Función auxiliar para que no hayan errores en el juego
 void correccionzeros(bool correcto,TUsuario &usu, TMaquina &maq){
    if(correcto==true){
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
    if(correcto==false){
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

// Función auxiliar para ayudar a que no hayan errores internos en el programa
void correccionnumeros(bool correcto, TUsuario &usu, TMaquina &maq){
    if(correcto ==true){
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
                        else{
                            correccionzeros(true, usu, maq);
                        }
                    }
                }
            }
        }while(usu.cartasu[0].vida==usu.cartasu[1].vida|| usu.cartasu[0].vida==usu.cartasu[2].vida|| usu.cartasu[1].vida==usu.cartasu[2].vida);
    }
    if(correcto==false){
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
                        else{
                            correccionzeros(false, usu, maq);
                        }
                    }
                }
            }
        }while(maq.cartasm[0].vida==maq.cartasm[1].vida || maq.cartasm[0].vida==maq.cartasm[2].vida || maq.cartasm[1].vida==maq.cartasm[2].vida);
    }
 }

 // Menú final del juego que nos muestra quien ha ganado y perdido
 void ganarperder(bool ganado,TUsuario &usu, TMaquina &maq){
    if(ganado==true){
        cout<<"Felicidades, has ganado el juego." << endl;
        cout<<"Este ha sido el resultado:" << endl;
    }
    else{
        cout<<"Lo siento, has perdido el juego." << endl;
        cout<<"Este ha sido el resultado:" << endl;
    }
    cout<< "Vida del jugador: " << usu.vida << endl;
    cout<< "Vida de la maquina: "<< maq.vida << endl;
    cout<<endl;
 }

// Mapa del juego donde podemos observar la vida y ataque adicional de cada una de las cartas
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
 }


// Funcion que muestra lo que puede hacer el usuario
void showTurnUsu(TUsuario &usu, TMaquina &maq) {
    if(maq.cartasm[0].vida==0 && maq.cartasm[1].vida==0 && maq.cartasm[2].vida==0 || usu.cartasu[0].vida==0 && usu.cartasu[1].vida==0 || usu.cartasu[0].vida==0 && usu.cartasu[2].vida==0 || usu.cartasu[1].vida==0 && usu.cartasu[2].vida==0 || usu.cartasu[1].vida==0 && usu.cartasu[2].vida==0 && usu.cartasu[0].vida==0){
        correccionzeros(true,usu, maq);
    }
    if(usu.cartasu[0].vida==0 && usu.cartasu[1].vida==0 && usu.cartasu[2].vida==0 || maq.cartasm[0].vida==0 && maq.cartasm[1].vida==0 || maq.cartasm[0].vida==0 && maq.cartasm[2].vida==0 || maq.cartasm[1].vida==0 && maq.cartasm[2].vida==0 || maq.cartasm[0].vida==0 && maq.cartasm[1].vida==0 && maq.cartasm[2].vida==0){
        correccionzeros(false,usu, maq);
    }
    if((usu.cartasu[0].vida==usu.cartasu[1].vida && usu.cartasu[0].vida!=0 && usu.cartasu[1].vida!=0) || (usu.cartasu[0].vida==usu.cartasu[2].vida && usu.cartasu[0].vida!=0 && usu.cartasu[2].vida!=0) || (usu.cartasu[1].vida==usu.cartasu[2].vida && usu.cartasu[1].vida!=0 && usu.cartasu[2].vida!=0)){
        correccionnumeros(true,usu, maq);
    }
    if((maq.cartasm[0].vida==maq.cartasm[1].vida && maq.cartasm[0].vida!=0 && maq.cartasm[1].vida!=0) || (maq.cartasm[0].vida==maq.cartasm[2].vida && maq.cartasm[0].vida!=0 && maq.cartasm[2].vida!=0) || (maq.cartasm[1].vida==maq.cartasm[2].vida && maq.cartasm[1].vida!=0 && maq.cartasm[2].vida!=0)){
        correccionnumeros(false,usu, maq);
    }

    mapa(usu, maq);
    cout << endl;
    cout << "Que vas a querer hacer?" << endl
    << "1- Atacar" << endl;
    if(usu.magica==true){
       cout<< "2- Usar magia" << endl
       << "Opcion:";
    }
    else{
       cout<< "Opcion:";
    }
}

// Funcion que devuelve la carta del usuario con más vida
int maxusu(TUsuario &usu){
    int max=0;
    for(int i=0; i<KMAXCARTAS-1; i++){
        if(usu.cartasu[i].vida>max){
            max=usu.cartasu[i].vida;
        }
    }
    return max;
}

// Funcion que devuelve la carta de la maquina con más vida
int maxmaq(TMaquina &maq){
    int max=0;
    for(int i=0; i<KMAXCARTAS-1; i++){
        if(maq.cartasm[i].vida>max){
            max=maq.cartasm[i].vida;
        }
    }
    return max;
}

// Funcion que devuelve la carta de la maquina con menos vida
int minmaq(TMaquina &maq){
    int min=100;
    for(int i=0; i<KMAXCARTAS-1; i++){
        if(maq.cartasm[i].vida<min){
            min=maq.cartasm[i].vida;
        }
    }
    return min;
}

// Devuelve el tipo de magia que nos ha tocado
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

// Módulo para cuando queramos usar los diferentes tipos de magia
void usomagico(TUsuario &usu,int &contador, TMaquina &maq){
    int option;
    switch(usu.tipo_magia){
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
                mapa(usu, maq);
            break;
        case 4: for(int i=0;i<KMAXCARTAS-1;i++){
                    if(usu.cartasu[i].vida==0){
                        usu.cartasu[i].vida=1;
                        break;
                    }
                }
                mapa( usu, maq);
            break;
    }
    contador++;
}

// Devuelvela naturaleza que obtendrá la maquina
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

// Módulo para cuando queramos usar los diferentes tipos de naturaleza
void usonaturaleza(TMaquina &maq, TUsuario &usu){
    int elegido;
    elegido=maxusu(usu); 
    int minimo;
    minimo= minmaq(maq);
    switch(maq.naturaleza){
        case 'a': for(int i=0;i<KMAXCARTAS-1;i++){
                    if(maq.cartasm[i].vida==minimo){
                        maq.cartasm[i].vida=maq.cartasm[i].vida+3;
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
                mapa(usu,maq);
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
void operaciones(TUsuario &usu, TMaquina &maq){
    int resultado;
    if(usu.cartasu[3].vida+usu.cartasu[3].ataque>=maq.cartasm[3].vida){
        resultado=0;
        maq.vida=maq.vida-maq.cartasm[3].vida;
    }
    else{
        resultado=maq.cartasm[3].vida-(usu.cartasu[3].vida+usu.cartasu[3].ataque);
        maq.vida=maq.vida-usu.cartasu[3].vida+usu.cartasu[3].ataque;
    }
        
    cout<<"Has hecho un ataque de "<<usu.cartasu[3].vida << "+" << usu.cartasu[3].ataque<<" de ATK. Con lo cual ahora a la carta enemiga le queda de vida: "<<resultado<<endl;
    if(resultado==0){
        cout<<"Has derribado una carta"<<endl;
    }

    for(int i=0;i<KMAXCARTAS-1;i++){
        if(maq.cartasm[3].vida==usu.cartasu[3].vida+usu.cartasu[3].ataque+resultado && maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[i].vida=resultado;
        }
        if(resultado==0 && usu.cartasu[3].vida+usu.cartasu[3].ataque>=maq.cartasm[3].vida && maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[i].vida=resultado;
        }
    }
    cout << endl;
    mapa(usu, maq);
    cout << endl;
}


// Funcion donde el usuario elegirá que carta atacar y con cual
void attack(TUsuario &usu, TMaquina &maq){
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
    operaciones(usu,maq);
}

// Funcion donde la maquina elegirá que carta atacar y con cual
void ataqueia(TUsuario &usu, TMaquina &maq){
    int resultado;
    usu.cartasu[3].vida=maxusu(usu);
    maq.cartasm[3].vida=maxmaq(maq);
    for(int i=0;i<KMAXCARTAS-1;i++){
        if(maq.cartasm[i].vida==maq.cartasm[3].vida){
            maq.cartasm[3].ataque=maq.cartasm[i].ataque;
        }
    }
    cout<<"Turno del enemigo: Te va a atacar con su -> "<<maq.cartasm[3].vida<<"+"<<maq.cartasm[3].ataque<<" a tu siguiente carta -> "<<usu.cartasu[3].vida<<endl;
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

// Módulo que da el valor a cada una de las cartas del juego inicialmente
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
    usu.vida=usu.cartasu[0].vida+usu.cartasu[1].vida+usu.cartasu[2].vida;
    maq.vida=maq.cartasm[0].vida+maq.cartasm[1].vida+maq.cartasm[2].vida;
}

// Módulo prinicipal del modo de jugar contra la maquina
void versusmachine(TUsuario &usu, TMaquina &maq){
        int cont=0;
        usu.magica=true;
        maq.usado=true;

        usu.tipo_magia=switchmagia();
        maq.naturaleza=switchnature();

        repartircartas(usu,maq);
        cout<<"Se reparten 3 cartas"<<endl;

        do{
            showTurnUsu(usu, maq);
            int option;
            cin>>option;
            switch(option){
                case 1:attack(usu, maq);
                    if(maq.vida<=6 && maq.usado==true){
                        usonaturaleza(maq,usu);
                        maq.usado=false;
                    }
                    if(maq.vida!=0){
                        ataqueia(usu, maq);
                    }
                    break;
                case 2: if(usu.tipo_magia==4 && usu.cartasu[0].vida!=0 && usu.cartasu[1].vida!=0 && usu.cartasu[2].vida!=0){
                            cout<<"No puedes usar la magia ahora"<<endl;
                        }
                        if(cont==0 && usu.magica==true){
                            usomagico(usu,cont,maq);
                            usu.magica=false;
                            if(maq.vida!=0){
                                ataqueia(usu, maq);
                            }
                        }
                        else{
                            error(ERR_MAGIC);
                        }
                    break;
                default:error(ERR_OPTION);
            }
            cout<<endl;
            usu.vida=usu.cartasu[0].vida+usu.cartasu[1].vida+usu.cartasu[2].vida;
            maq.vida=maq.cartasm[0].vida+maq.cartasm[1].vida+maq.cartasm[2].vida;

        }while(usu.vida!=0 && maq.vida!=0);

        if(maq.vida==0){
            ganarperder(true,usu,maq);
        }
        else{
            ganarperder(false,usu,maq);
        }
}


void showRulesMenu() {
  cout << "[REGLAS]" << endl
       << "1- ¿Como jugar?" << endl
       << "2- Cartas" << endl
       << "3- Magia" << endl
       << "4- Naturaleza" << endl
       << "5- Mapa" << endl
       << "v- Volver al menu"<< endl
       << "Opcion:";
}

void maparegla(){
    cout<<endl;
    cout<<"Sus cartas   Las de la Maquina"<<endl;
    for(int i=0; i<KMAXCARTAS-1;i++){
        cout<<'x'<<" ";
    }
    cout<<"         ";
    for(int i=0;i<KMAXCARTAS-1;i++){
        cout<<'x'<<" ";
    }
    
    cout<<endl;
    for(int i=0; i<KMAXCARTAS-1;i++){
        cout<<"("<<'y'<<")";
    }
    cout<<"     ";
    for(int i=0;i<KMAXCARTAS-1;i++){
        cout<<"("<<'y'<<")";
    }
    cout<<endl;
    cout<<"Las x son las cartas que se juegan, representando su vida y ataque en función de la carta."<<endl;
    cout<<"Las y son el bonus añadido a las cartas que se consigue a través de las magias. Sólo afectan en el ataque."<<endl;
    cout<<endl;
    
}


void rules(){
    char option;
    do{
        showRulesMenu();
        cin>>option;
        switch (option) {
          case '1': cout<<"Se reparten 3 cartas, y un poder o naturaleza a cada jugador. Y mediante las vidas de sus cartas y ataque adicional que pueden obtener deberán derrotar a las cartas de sus contricantes."<<endl;
             break;
          case '2': cout<<"Cada cartas tiene dos características: La vida (iniciada al principio de cada partida), y el ataque (el ataque en si es la vida de cada carta pero a ese se le puede sumar ataque adicional gracias a la magia o naturaleza)."<<endl;
             break;
          case '3': cout<<"El jugador obtiene en cada partida un tipo de magia para beneficarse y así poder obtener la victoria. Una vez usada no podrá volver a usarla."<<endl;
            break;
          case '4': cout<<"La máquina obtiene en cada partida un tipo de naturaleza el cual le ofrece beneficios a la hora de derrotarnos y acabar la partida ganando."<<endl;
            break;
          case '5': maparegla();
          case 'v':
             break;
          default:
            error(ERR_OPTION);
        }
    }while(option!='v');
}

void showMainMenu() {
  cout << "[MENU]" << endl
       << "1- Jugar contra la Maquina" << endl
       << "2- Reglas" << endl
       << "s- Salir"<< endl
       << "Opcion:";
}

int main(){
    TMaquina maq;
    TUsuario usu;
    char option;
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
          case '1': versusmachine(usu,maq);
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
