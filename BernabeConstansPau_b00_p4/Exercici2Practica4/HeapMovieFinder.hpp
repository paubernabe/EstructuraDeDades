/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMovieFinder.hpp
 * Author: paubc
 *
 * Created on 26 / de maig / 2018, 18:05
 */

#ifndef HEAPMOVIEFINDER_HPP
#define HEAPMOVIEFINDER_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ios>
#include <ctime>
#include <chrono>
#include "movie.hpp"
#include "MinHeap.hpp"
using namespace std;

class HeapMovieFinder{
public:
    HeapMovieFinder();
    MinHeap<TADMovie> h;
    void appendmovies(string filename);
    void insertmovie(int movieID, string pelicula, double rating);
    string showmovie(int movieID);
    bool findmovie(int movieID);
    
    void readcerca();
    void printTheHeap();
    int getSize();
};
       
HeapMovieFinder::HeapMovieFinder(){
    h=MinHeap<TADMovie>();
}
void HeapMovieFinder::appendmovies(string filename){
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
    
    title=(pelicula.substr(posid+2,pos-1));
    
    string titol=(title.substr(0,(title.length()-5)));
    //retallem l'string pelicula, cada linea i el convertim en el seu tipus (int, float, string)
    //el passem pel constructor i l'insertem al nostre bst
    //quan inserim, hem utilitzat també la id per qüestió de la nostra cerca
    // el nostre node tindra dues parts, ID/OBJECTE MOVIE
    TADMovie m= TADMovie(id,titol,rating);
    h.insert(m,id);
    
        
    } 
       
    
    fin.close();
    
    
}


void HeapMovieFinder::insertmovie(int movieID, string title, double rating){
    
    TADMovie m= TADMovie(movieID, title, rating);
    
    h.insert(m,movieID);
    
   
}

string HeapMovieFinder::showmovie(int movieID){
    cout<< h.Search(movieID)<<endl;
}
//revisar
bool HeapMovieFinder::findmovie(int movieID){
    cout<<h.Search(movieID)<<endl;
}

void HeapMovieFinder::readcerca(){
    ifstream fin ("cercaPelicules.txt");
    string pelicula;
    
    int count=0;
    auto start = std::chrono::high_resolution_clock::now();
    while(getline(fin,pelicula)){
        
        int idcerca=stoi(pelicula);
        
        if(h.Search(idcerca)==true){
           
           ++count; 
            
        }
        

        
        
    }
    cout<<count<<endl;
     auto finish = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << endl;
    
    
    
    
    
}
void HeapMovieFinder::printTheHeap(){
    h.printHeap();
}

int HeapMovieFinder::getSize(){
    cout<< h.sizeHeap()<<endl;
}

#endif /* HEAPMOVIEFINDER_HPP */

