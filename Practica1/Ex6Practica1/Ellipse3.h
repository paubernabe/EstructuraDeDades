/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   classesCE.h
 * Author: paubc
 *
 * Created on 27 / de febrer / 2018, 10:44
 */

#ifndef CLASSESCE_H
#define CLASSESCE_H

class Ellipse{
private:
    double radi1,radi2,area;
public:
    
    Ellipse();
    
    double getAreac();
    virtual double getAreae();
    
    void setRadi1(double radi1);
    double getRadi1();
    void setRadi2(double radi2);
    double getRadi2();
    
};




#endif /* CLASSESCE_H */

