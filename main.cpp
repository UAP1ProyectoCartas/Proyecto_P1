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
    usu.cartasu[3].vida=max(usu);
    maq.cartasm[3].vida=max(maq);
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
