/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 25 / de febrer / 2018, 16:21
 */

#include <iostream>
#include "Ellipse.h"
#include <vector>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Ellipse elip;
    int option,eCount=0,cCount=0;
    int seeMenu();
    int r1, r2, count; 
    char lletra;
    
    
        do{
    cout << "Hola, que vols fer?" << endl;
    
    seeMenu();
    
    cin >> option;

    
    switch(option){
        case 1:
            cout << "Fins la proxima!" << endl;
            break;
        case 2:
            cout << "Afegeix comando C i el radi per calcular l'area d'un cercle " << endl << "Afeixeix comando E radi gran i radi petit per calcular l'area d'una elipse"<< endl;
            cin >> lletra;
            
            if (lletra=='C'){
                cin >> r1;
                try{
                if (r1<=0){
                    throw 000;
                }
                }
                catch(int x){
                    cout << "Valor no adequat. ERROR " << x << endl;
                    break;
                }
                elip.setRadi1(r1);
                cout << "L'area del cercle es " << elip.getAreac() << endl;
                cCount=cCount+1;
            }
            else if (lletra=='E'){
                cin >> r1;
                
                elip.setRadi1(r1);
                cin >> r2;
                elip.setRadi2(r2);
                 try{
                if (r2<=0 or r1<=0){
                    throw 000;
                }
                }
                catch(int x){
                    cout << "Valor no adequat. ERROR " << x << endl;
                    break;
                }
                
                cout << "L'area de la elipse és  " << elip.getAreae() << endl;
                eCount=eCount+1;
            }
        
            break;
        case 3:
            cout << "Hi han " << eCount << "  Ellipses i  " << cCount << "  Cercles introduits  " << endl ;
            break;
            
            
    }
    
    
    }while(option!=1);
    
    return 0;
}


//MENU
int seeMenu(){
     
    int option,i;
    
string opt []={ "SORTIR", "INTRODUIR FIGURA","GLOSSARI DE FIGURES" };
vector <string> arr_options (opt, opt+3);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}

void Ellipse::setRadi1(double radi1){
    this->radi1=radi1;
}
void Ellipse::setRadi2(double radi2){
    this->radi2=radi2;
}


double Ellipse::getRadi1(){
    return radi1;
    
}
double Ellipse::getRadi2(){
    return radi2;
   
}


double Ellipse::getAreac(){
    area=(3.14*(radi1*radi1));
    return area;
}
double Ellipse::getAreae(){
    area=(3.14*(radi1*radi2));
    return area;
}