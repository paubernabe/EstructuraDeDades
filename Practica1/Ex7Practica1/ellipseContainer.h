/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ellipseContainer.h
 * Author: paubc
 *
 * Created on 1 / de març / 2018, 19:16
 */

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H
#include <vector>


using namespace std;
#include <iostream>


class ellipseContainer{
private:
    vector <Ellipse*> container (10);
    
    
   
public:
    void addEllipse (Ellipse *n);
    float getAreas();
    ellipseContainer();
};

#endif /* ELLIPSECONTAINER_H */
 
