/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 20 / de febrer / 2018, 19:18
 */

#include <iostream>
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
    string nom;
    int opcio,i;
    
    string arr_options[] = {"Sortir", "Benvinguda"};
    
    cout << "HOLA, COM ET DIUS?" << endl;
    
    cin >> nom;
    
    
    
    
    do{
        cout << "Hola,  " << nom << "  que vols fer?" << endl;
    
        for (i=0;i<2;++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
        
        
    }
         cin >> opcio;
    if (opcio==2){
        cout << "BENVINGUT A LA MILLOR ASSIGNATURA ED!!!!" << endl;
    }else if(opcio==1){
        cout << "Sortir" << endl;
    }
        
    
    }while (opcio!=1);
    
                
    
    
   
    
    
    
    
    
    
    
    

    return 0;
}

