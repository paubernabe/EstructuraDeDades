/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 26 / de febrer / 2018, 12:22
 */
#include <vector>
#include "Ellipse3.h"
#include "Circle.h"

#include <fstream>

using namespace std;

#include <iostream>
/*
 * 
 */
int main(int argc, char** argv) {
    
Ellipse* elip= new Ellipse;
Circle* c= new Circle;

    int option,eCount=0,cCount=0,count;
    int seeMenu();
    double r1, r2; 
    char lletra;
    ifstream myfile ("figures2.txt"); 
    
  
    
    
    
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
                
                elip->setRadi1(r1);
                Circle();
                cout << "L'area del cercle es " << elip->getAreac() << endl;
                cCount=cCount+1;
            }
            else if (lletra=='E'){
                cin >> r1;
                
                elip->setRadi1(r1);
                cin >> r2;
                elip->setRadi2(r2);
                 try{
                if (r2<=0 or r1<=0){
                    throw 000;
                }
                }
                catch(int x){
                    cout << "Valor no adequat. ERROR " << x << endl;
                    break;
                }
                Ellipse();
                cout << "L'area de la elipse és  " << elip->getAreae() << endl;
                eCount=eCount+1;
            }
        
            break;
        case 3:
            cout << "Hi han " << eCount << "  Ellipses i  " << cCount << "  Cercles introduits  " << endl ;
            break;
            
        case 4:
            
            if (myfile.is_open()){
                
            
            while (!myfile.eof()){
                
                myfile >> lletra;
                                
                if (lletra=='C'){
                    
                    myfile>>r1;

                
                    elip->setRadi1(r1);
                    Circle();
                    cout << elip->getAreac() << endl;
                    cCount=cCount+1;
                }
                if (lletra=='E'){
                    
                    myfile >> r1;
                    
                    elip->setRadi1(r1);
                    myfile >> r2;
                    elip->setRadi2(r2);
                    
                    Ellipse();
                    cout << elip->getAreae() << endl;
                    eCount=eCount+1;
                    
                    
                }

                
   
            }
            }else{
                cout << "not open" << endl;
            }
            
            myfile.close();

            
            break;
            
            
            
            
            
            
    }
    
    
    }while(option!=1);
    
    return 0;
}


//MENU
int seeMenu(){
     
    int option,i;
    
string opt []={ "SORTIR", "INTRODUIR FIGURA","GLOSSARI DE FIGURES", "LLEGIR FITXER" };
vector <string> arr_options (opt, opt+4);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}

Ellipse::Ellipse(){
    
    cout << "Hola soc el constructor de la ellipse" << endl;
    
}

Circle::Circle():Ellipse(){
    cout << "Hola soc el constructor del cercle" << endl;
    
    
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


