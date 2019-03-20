/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 21 / de febrer / 2018, 17:18
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    string nom;
    int opcio,i;
    int seeMenu();
    
    
    
    cout << "HOLA, COM ET DIUS?" << endl;
    
    cin >> nom;
    
    do{
        cout << "Hola,  " << nom << "  que vols fer?" << endl;
        
        seeMenu();
        cin >> opcio;
        
        switch (opcio){
                case 1:
                    cout << "Sortir" << endl;
                    break;
                case 2:
                    cout << "BENVINGUT A LA ASSIGNATURA ED!!!!" << endl;
                    break;
                case 3:
                    cout << "Redefinir nom" << endl;
                    cin >> nom;
                    break;
        }
        }while (opcio!=1);

    return 0;
}

 int seeMenu(){
     
    int opcio,i;
    
    string arr[] =  {"SORTIR", "BENVINGUDA", "REDEFINIR NOM"};
    vector <string> arr_options (arr, arr+3);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}

