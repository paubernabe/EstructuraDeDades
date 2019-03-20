/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   movie.hpp
 * Author: paubc
 *
 * Created on 23 / d’abril / 2018, 19:10
 */

#ifndef MOVIE_HPP
#define MOVIE_HPP


using namespace std;
#include <string>
#include <sstream>

class TADMovie {
public:
    /*Constructor*/
    TADMovie(int movieID,string title,float rating);
    TADMovie();
    /*Destructor*/
    //~TADMovie();
    /*Consultors*/
    int getMovieID() const;
    string getTitle() const;
    float getRating() const;
    TADMovie getMovie()const;
    /*Modificadors*/
    void setMovie(const TADMovie &movie);
    void setMovieID(int movieID);
    void setTitle(string title);
    void setRating(float rating);   
    string toString(const TADMovie &movie);
private:
    int movieID;
    string title;
    float rating;


};


TADMovie::TADMovie(int movieID, string title, float rating){
    this->movieID=movieID;
    this->title=title;
    this->rating=rating;
}

TADMovie::TADMovie(){
    this->movieID=0;
    this->title="";
    this->rating=0.0;
}

string TADMovie::toString(const TADMovie& movie){
    
     stringstream ss;
     ss << "[" << "ID: "<<movie.getMovieID()<< " titol: "<<movie.getTitle()<< " Puntuacio "<<movie.getRating() << "]";
     string s=ss.str();
     return s;
     
    
}




void TADMovie::setMovieID(int movieID){
    this->movieID=movieID;
}
int TADMovie::getMovieID() const{
    return movieID;
}

void TADMovie::setTitle(string title){
    this->title=title;
}
string TADMovie::getTitle() const{
    return title;
}

void TADMovie::setRating(float rating){
    this->rating=rating;
}
float TADMovie::getRating() const{
    return rating;
}


#endif /* MOVIE_HPP */