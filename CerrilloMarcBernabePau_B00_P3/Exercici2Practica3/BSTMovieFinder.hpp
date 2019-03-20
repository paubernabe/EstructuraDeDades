/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTMovieFinder.hpp
 * Author: paubc
 *
 * Created on 23 / d’abril / 2018, 19:51
 */

#ifndef BSTMOVIEFINDER_HPP
#define BSTMOVIEFINDER_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ios>
#include <ctime>
#include <chrono>
#include "movie.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

class bstmoviefinder{
public:
    bstmoviefinder();
    BinarySearchTree<TADMovie> *b;
    void appendmovies(string filename);
    void insertmovie(int movieID, string pelicula, double rating);
    string showmovie(int movieID);
    TADMovie* findmovie(int movieID);
    double findratingmovie(int movieID);
    
    void showinorder();
    void readcerca();
    void getprof();
    
};

bstmoviefinder::bstmoviefinder(){
    b=new BinarySearchTree<TADMovie>();
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
    
    title=(pelicula.substr(posid+2,pos-1));
    
    string titol=(title.substr(0,(title.length()-5)));
    //retallem l'string pelicula, cada linea i el convertim en el seu tipus (int, float, string)
    //el passem pel constructor i l'insertem al nostre bst
    //quan inserim, hem utilitzat també la id per qüestió de la nostra cerca
    // el nostre node tindra dues parts, ID/OBJECTE MOVIE
    TADMovie m= TADMovie(id,titol,rating);
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
    cout<<count<<endl;
     auto finish = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << endl;
    
    
    
    
    
}

void bstmoviefinder::getprof(){
    
    cout<<b->getHeight()<<endl;
    
}

#endif /* BSTMOVIEFINDER_HPP */

