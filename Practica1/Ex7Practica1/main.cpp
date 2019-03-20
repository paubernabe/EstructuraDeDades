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
#include "Ellipse7.h"
#include "Circle7.h"
#include "ellipseContainer.h"
#include <fstream>

using namespace std;

#include <iostream>
/*
 * 
 */
int main(int argc, char** argv) {
    
Ellipse* elip= new Ellipse;
Circle* c= new Circle;
ellipseContainer* ec= new ellipseContainer;

    int option,eCount=0,cCount=0;
    int seeMenu();
    double r1, r2; 
    char lletra;
    ifstream myfile ("figures7.txt"); 
    
    
  
    
    
    
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
                
                c->setRadi1(r1);
                Circle();
                ec->addEllipse(c);
                cout << "L'area del cercle es " << c->getAreac() << endl;
                
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
                ec->addEllipse(elip);
                
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

                
                    c->setRadi1(r1);
                    Circle();
                    ec->addEllipse(c);
                    cout << c->getAreac() << endl;
                    cCount=cCount+1;
                }
                if (lletra=='E'){
                    
                    myfile >> r1;
                    
                    elip->setRadi1(r1);
                    myfile >> r2;
                    elip->setRadi2(r2);
                    
                    Ellipse();
                    ec->addEllipse(elip);
                    cout << elip->getAreae() << endl;
                    eCount=eCount+1;
                    
                    
                }

                
   
            }
            }else{
                cout << "not open" << endl;
            }
            
            myfile.close();
            
        case 5:
            
            

            
            break;
            
            
            
            
            
            
    }
    
    
    }while(option!=1);
    

    
    return 0;
}


//MENU
int seeMenu(){
     
    int option,i;
    
string opt []={ "SORTIR", "INTRODUIR FIGURA","GLOSSARI DE FIGURES", "LLEGIR FITXER", "SUMA TOTAL D'AREES" };
vector <string> arr_options (opt, opt+5);
     
    
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

ellipseContainer::ellipseContainer(){
    
}
Ellipse::~Ellipse(){
    cout << "Hola soc el destructor de la Ellipse" << endl;
   
}
Circle::~Circle(){
    cout << "Hola soc el destructor del cercle" << endl;
    
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



void ellipseContainer::addEllipse(Ellipse* n){
    //vector <Ellipse*> container (10);
    
    
    if (this->container.size()>10){
        cout << "Exceed size" << endl;
    }else{
        this->container.push_back(n);
    }
    
       
        
    
}


float ellipseContainer::getAreas(){
    float suma=0;
    vector<Ellipse*>::iterator ite;
    
    for (vector<ite = this->container.begin(); ite != this->container.end(); ite++){
        suma+=(*ite)->getAreas();
    }
    return suma;
}

/*
a. Què ens permet fer l’herència que no podríem fer altrament?
 * Ens permet reutilitzar molt de codi i d'aquesta manera no haver de picar tant codi.
 * 
b. Que passa si getArea() de la classe Ellipse no és virtual? Perquè?
 * Els metodes virtuals ens permeten "manipular" els metodes de les superclasses a les
 * subclasses per a aconseguir adaptarles. Si no fos virtual tindriem certs problemes en rebre les arees.
c. Perquè els constructors i destructors els hem de cridar a les classes derivades i no a
la classe base?
 * Perquè inicialitza i elimina els objectes de la classe derivada, la relació d'herencia faria
 * que no fossin inicialitzats si els coloquessim a la classe base
 * 
d. Es podria fer que getArea() fos un mètode de la classe pare “Ellipse”?
 * Podria ser-ho si comptem que el vector esta compost per objectes d'aquesta classe.
 * 
e. Anomena els membres de dades definits en els teus programes i digues a quina
classe pertanyen. Explica les decisions de visibilitat de cadascun
 * private en els atributs de cada classe per a la seva encapsulació
 * public en els seus mètodes per a poder accedir desde diferents classes.
f. L’iterador que recorre les figures, quant s’incrementa cada cop? Perquè?
 * S'incrementa un a un, cada pas pels index del vector.
 */