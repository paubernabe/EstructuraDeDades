/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 26 / de maig / 2018, 18:03
 */

#include <cstdlib>

using namespace std;
/*
 
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include "HeapMovieFinder.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int seeMenu(),option;
    char l;
    HeapMovieFinder heap;
    
    do{
        seeMenu();
        cin>>option;
        switch(option){
            
            case 1:  
                cin >> l;
                if (l=='P' or l=='p'){
                    auto start = std::chrono::high_resolution_clock::now();
                   
                    heap.appendmovies("movie_rating_small.txt");
                    auto finish = std::chrono::high_resolution_clock::now();
                    chrono::duration<double> elapsed = finish - start;
                    cout << "Elapsed time: " << elapsed.count() << endl;  
                }
                else if(l=='G' or l=='g'){
                    auto start = std::chrono::high_resolution_clock::now();
                    heap.appendmovies("movie_rating.txt");
                    auto finish = std::chrono::high_resolution_clock::now();
                    chrono::duration<double> elapsed = finish - start;
                    cout << "Elapsed time: " << elapsed.count() << endl;
                    
                }else{    
                    cout<<"introdueix una opcio valida"<<endl;
                }
                break;
            case 2:
             
                heap.printTheHeap();
                break;
            case 3:
                heap.readcerca();
                
              
                break;
            case 4:
                heap.getSize();
                break;
            case 5:
                                
                break;
           
           
        }
        
    }while(option!=5);
    
    
    

    return 0;
    
}

int seeMenu(){
     
    int option,i;
    
string opt []={"Quin fitxer vols? (P / G)","ID en ordre creixent","Llegir cercapelicules.txt","Profunditat","SORTIR" };
vector <string> arr_options (opt, opt+5);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}


