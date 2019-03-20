/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 22 / de març / 2018, 13:07
 */

#include <cstdlib>
#include "LinkedDeque.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {


        LinkedDeque<int> linked;

    
    
    
    int option, seeMenu(),ele; 
    
    do{
        seeMenu();
        cin >> option;

        switch(option){
            
        
        case 1:
            cin >> ele;
            linked.insertFront(ele);
            
            cout << "Element " << ele << " introduit" << endl;
            
            
            break;
            
        case 2:
            cin >> ele;
            linked.insertRear(ele);
            cout << "Element " << ele<< " introduit" << endl;
            break;
            
        case 3:
            try{
            linked.deleteFront();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
            cout << "Element " << linked.getFront() << " eliminat" << endl;
            break;
        
            
        case 4:
            
            try{
            linked.deleteRear();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
            cout << "Element " << linked.getRear() << " eliminat" << endl;
                        
            
            break;
                    
        
        case 5:
            
            linked.print();
            
            break;
       
        case 6:
            
            linked.deleteFront();
            linked.deleteRear();
            linked.insertFront(20);
            linked.insertFront(30);
            linked.insertRear(80);
            linked.insertRear(45);
            linked.deleteFront();
            linked.print();
                
            break;
        case 7:
            
            
            linked.deleteFront();
            linked.deleteRear();
            linked.insertFront(2);
            linked.insertFront(3);
            linked.insertRear(8);
            linked.insertRear(4);
            linked.deleteFront();
            linked.print();
            
            
            break;
             
                
        case 8:
            cout << "Fins la proxima" << endl;
            linked.~LinkedDeque();
            
            break;
            
                
        }
            
    } while (option!=8);
    
return 0;
}

int seeMenu(){
     
    int option,i;
    
string opt []={ "Inserir element pel davant", "Inserir element pel final","Eliminar element pel davant","Eliminar element pel final","Imprimir contingut de LINKED DEQUE","Imprimir Cas Prova 1","Imprimir Cas Prova 2", "Sortir" };
vector <string> arr_options (opt, opt+8);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}


//**PREGUNTES*****************************************

/*
  1. Has implementat la LinkedDeque amb templates? Sigui quina sigui la teva resposta,
justifica el motiu pel qual has pres aquesta decisió
 * 
 * Si, l'he implementat amb template, d'aquesta manera podem afegir tot tipus d'elements
 * a la nostra LinkedDeque i a més podrem reutilitzar codi en gran varietat de casos.
 * 
2. Tenint en compte la teva implementació del TAD LinkedDeque, indica per a cadascuna
de les operacions del TAD LinkedDeque quin és el seu cost computacional teòric.
Justifica la resposta
 * 
 * Els inserts i deletes podem trobar un cost de O(1), això es deu a que 
 * al estar enllaçats els nodes amb punters, el cost es redueix dràsticament
 * a diferència que ho fessim amb llista, ja que amb llista, quan estem tractant elements són 
 * molt més pesades en sentit computacionals, ja que quan inserim o borrem, acostuma a afectar a tota
 * la llista sencera i cada procés suma, amb els nombres que utilitzem ara, no ho notem, però
 * amb una gran quantitat, l'array queda obsoleta.
 * 
 * Llavors podriem considerar que el print, al fer un recorregut, te un cost més elevat als altres
 * ja que passa per tota la llista.
 * 
 * 
3. Creieu que la classe Node hauria estat millor implementar-la amb encadenaments
simples? Justifica la teva resposta
 * 
 * Jo crec que si, podriem haver utilitzar un sol encadenament.
 * Aquestes dues(single i double linked) tenen la mateixa complexitat en les operacions que hem vist a la 
 * practica 2, O(1) a la gran majoria.
 * Però en alguns casos, com per exemple borrar, ens aniria millor la double linked, ja que 
 * amb un sol enllaç, perdriem totalment el contacte amb l'altre node i hauràs de buscar aquell node
 * cosa que augmenta la complexitat.
 * Un punt en contra del double linked és que utilitza molta més memòria.
 * 
 * 
 */
