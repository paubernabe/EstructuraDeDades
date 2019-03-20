/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cercle.h
 * Author: paubc
 *
 * Created on 23 / de febrer / 2018, 16:57
 */

#ifndef CERCLE_H
#define CERCLE_H

class Cercle{
    
private:
    double radi;
    double area;
    

    //declaració de mètodes
public:
    
    double getArea();
    Cercle();
    
    void setRadi(double radi);
    double getRadi();


};




#endif /* CERCLE_H */

