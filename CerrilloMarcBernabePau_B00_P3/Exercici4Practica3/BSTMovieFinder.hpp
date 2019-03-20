#ifndef BSTMOVIEFINDER_HPP
#define BSTMOVIEFINDER_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ios>
#include <ctime>
#include <chrono>
#include "TADMovie.hpp"
#include "BalancedBST.hpp"

using namespace std;

class bstmoviefinder{
public:
    bstmoviefinder();
    BalancedBST<TADMovie> *b;
    void appendmovies(string filename);
    void insertmovie(int movieID, string pelicula, double rating);
    string showmovie(int movieID);
    TADMovie* findmovie(int movieID);
    double findratingmovie(int movieID);
    
    void getlongesttitle();
    void gethighestrating();
    void getlowestrating();
    
    void showinorder();
    void readcerca();
    void getprof();
    TADMovie m;
};

bstmoviefinder::bstmoviefinder(){
    b=new BalancedBST<TADMovie>();
}



void bstmoviefinder::appendmovies(string filename){
    int id;
    string title;
    double rating;
    
    ifstream fin (filename);
    string pelicula;
    
    while(getline(fin,pelicula)){
   
    
    for (int i=0; i<pelicula.length();i++){
        if (pelicula[i]==':' and pelicula[i+1]==':'){
            id=stoi(pelicula.substr(0,i));
            
        }
        
       }
     
    
    
    int posid=pelicula.find(':');
    int pos=pelicula.rfind(':');
    
    rating=stod(pelicula.substr(pos+1));
    
    string titol=(title.substr(0,(title.length()-6)));
    
    title=(pelicula.substr(posid+2,pos-1));
    
    
    
    TADMovie m= TADMovie(id,titol,rating);
    m.setRating(rating);
    
    b->insert(m,id);
    
        
    } 
       
    
    fin.close();
    
    
    
}

void bstmoviefinder::insertmovie(int movieID, string title, double rating){
    
    TADMovie m= TADMovie(movieID, title, rating);
    
    b->insert(m,movieID);
    
   
}

string bstmoviefinder::showmovie(int movieID){
    
    b->searchmovie(movieID);
        
        
        
   
}

TADMovie *bstmoviefinder::findmovie(int movieID){
    b->searchfind(movieID);
}

double bstmoviefinder::findratingmovie(int movieID){
    b->searchr(movieID);
    
    
}

void bstmoviefinder::showinorder(){
    
    b->printInorder();
    
}

void bstmoviefinder::readcerca(){
    ifstream fin ("cercaPelicules.txt");
    string pelicula;
    
    int count=0;
    auto start = std::chrono::high_resolution_clock::now();
    while(getline(fin,pelicula)){
        
        int idcerca=stoi(pelicula);
        
        if(b->search(idcerca)){
           
           count=count+1; 
            
        }
         

        
        
    }
     auto finish = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << endl;
    
    cout<<count<<endl;
    
    
    
}

void bstmoviefinder::getprof(){
    
    cout<<b->getHeight()<<endl;
    
}


void bstmoviefinder::gethighestrating(){
    b->maxr();
}

void bstmoviefinder::getlowestrating(){
    
}

void bstmoviefinder::getlongesttitle(){
    
}

#endif /* BSTMOVIEFINDER_HPP */

