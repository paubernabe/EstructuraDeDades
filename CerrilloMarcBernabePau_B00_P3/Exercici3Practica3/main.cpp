/*
 * To change this license header, choose License Headers in Project Properties.
 * o change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pau
 * 
 *
 * Created on 16 / d’abril / 2018, 18:03
 */

#include <cstdlib>
#include "BalancedBST.hpp"
#include <vector>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    BalancedBST<int> b;
    int testArray [8] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int option, seeMenu(),ele; 
    int n=0;

    do{
        seeMenu();
        cin >> option;

        switch(option){
            
        
        case 1:
           
            for (int i=0;i<8;i++){
                b.insert(testArray[i]);
                cout<< testArray[i] << " afegit" << endl;
            }
            
            break;
            
        case 2:
            try{
            b.printPreorder();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
            
            break;
            
        case 3:
            try{
            b.printInorder();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
            break;
        
            
        case 4:
            try{
            b.printPostorder();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
                        
            
            break;
                    
        
        case 5:
            try{
            b.publicMirror();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
            
            break;
            
       
        case 6:
            try{
            b.printMirror();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
                
            break;
        case 7:
            try{
            b.~BalancedBST();
            }catch(invalid_argument&exception){
                cout<<exception.what()<<endl;
            }
            
            break;
             
                
        case 8:
            
            cout<<"Fins aviat!"<<endl;
            break;
            
    
            
                
        }
            
    } while (option!=8);
    

    return 0;
}

int seeMenu(){
     
    int option,i;
    
string opt []={ "Inserir element/s","Imprimir PREORDRE","Imprimir INORDRE","Imprimir POSTORDRE","Fer ARBRE MIRALL","Imprimir PREORDRE arbre mirall", "ELIMINAR ARBRE", "SORTIR" };
vector <string> arr_options (opt, opt+8);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}

