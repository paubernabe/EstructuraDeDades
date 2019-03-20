/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 21 / de febrer / 2018, 18:06
 */

#include <iostream>
#include "Cercle.h"
#include <vector>


using namespace std;

/*
 * 
 */

int main() {
    
    Cercle cercle;
    int option;
    int count=1;
    int seeMenu();
    double rad;

    
    
    
    do{
    cout << "Hola, que vols fer?" << endl;
    
    seeMenu();
    
    cin >> option;

    
    switch(option){
        case 1:
            cout << "Fins la proxima!" << endl;
            break;
        case 2:
            cout << "Cercle numero " << count << endl;
            cout << "Quin radi te el teu cercle?" << endl;
            cin >> rad;
            try{
            
            if (rad<=0){
                throw 0;
            }
            }
            
            
            catch (int x){
                cout << "El valor " << rad << " no es adequat" << "ERROR NUM: " << x << endl;
                break;
            }
            
            
            
            
            cercle.setRadi(rad);
            
            cout << "L'area d'aquest cercle es:  " << cercle.getArea() << endl;
            count=count+1;
            break;
    }
    
    
    }while(option!=1);
    
    return 0;
}



//MENU
int seeMenu(){
     
    int option,i;
    
string opt []={ "SORTIR", "INTRODUIR CERCLE" };
vector <string> arr_options (opt, opt+2);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}

//Constructor

Cercle::Cercle(){
    radi=0.0;
    
}


//definició de mètodes en .cpp classe Cercle


double Cercle::getArea(){
    area=(3.14*(radi*radi));
        return area;
                
    }

void Cercle::setRadi(double radi){
    this->radi=radi;
    
}
double Cercle::getRadi(){
    return this->radi;
}

