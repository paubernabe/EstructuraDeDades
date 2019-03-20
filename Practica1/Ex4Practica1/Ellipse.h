/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: paubc
 *
 * Created on 25 / de febrer / 2018, 16:27
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse{
private:
    double radi1,radi2,area;
public:
    
    double getAreac();
    double getAreae();
    
    void setRadi1(double radi1);
    double getRadi1();
    void setRadi2(double radi2);
    double getRadi2();
};






#endif /* ELLIPSE_H */

