#include <cstdlib>
#include "MinHeap.hpp"
#include <vector>
#include <iostream>
#include "movie.hpp"

using namespace std;
/*
 
 */
int main(int argc, char** argv) {
   
  
 
    MinHeap<TADMovie> b;
    int testArray [8] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int option, seeMenu(),ele,key; 
    int n=0;  
    TADMovie movie= TADMovie(12,"titol",1.2);
    TADMovie movie1= TADMovie(2,"titol",1.2);
    TADMovie movie2= TADMovie(15,"titol",1.2);
    TADMovie movie3= TADMovie(5,"titol",1.2);
    TADMovie movie4= TADMovie(16,"titol",1.2);
    TADMovie movie5= TADMovie(8,"titol",1.2);
    TADMovie movie6= TADMovie(28,"titol",1.2);
    TADMovie movie7= TADMovie(1,"titol",1.2);
    TADMovie movie8= TADMovie(150,"titol",1.2);
    TADMovie movie9= TADMovie(50,"titol",1.2);
   TADMovie movie10= TADMovie(6,"titol",1.2);
    TADMovie movie11= TADMovie(3,"titol",1.2);
             
    do{
        seeMenu();
        cin >> option;

        switch(option){
            
       
         
        case 1:
            
            
            
            b.insert(movie,movie.getMovieID());
            b.insert(movie1,movie1.getMovieID());
            b.insert(movie2,movie2.getMovieID());
            b.insert(movie3,movie3.getMovieID());
            b.insert(movie4,movie4.getMovieID());
            b.insert(movie5,movie5.getMovieID());
            b.insert(movie6,movie6.getMovieID());     
            b.insert(movie7,movie7.getMovieID());
            b.insert(movie8,movie8.getMovieID());
            b.insert(movie9,movie9.getMovieID());
            b.insert(movie10,movie10.getMovieID());
            b.insert(movie11,movie11.getMovieID());
           
         
             
             
            break;
            
        case 2:
          
            b.printHeap();
            
            cout<<"Menor " << " " <<b.min()<<endl;
            cout<< "Menor Valor"; b.minValues();
            cout << "Cerca"; b.Search(2);
           
            break;
            
        case 3:
            b.removemin();
            
              
         
            break;
     
        case 4:
                
            break;
    
            
               
        }
            
    } while (option!=4);
    
    
    return 0;
} 

int seeMenu(){
    
    int option,i;
    
string opt []={ "Inserir element/s","Imprimir Heap","Remove Min","SORTIR" };
vector <string> arr_options (opt, opt+4);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}
