/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arraydequeue.h
 * Author: paubc
 *
 * Created on 8 / de març / 2018, 12:50
 */

#ifndef ARRAYDEQUEUE_H
#define ARRAYDEQUEUE_H


#include <cstdlib>
#include <vector>
using namespace std;

class ArrayDequeue{
public:
    ArrayDequeue( int maxSize) ;
    ~ArrayDequeue();
    bool isEmpty() const;
    bool isFull()const ;
    void insertFront(int element);
    void insertRear(int element);
    void deleteFront();
    void deleteRear();
    void print() const;
    
    int getFront()const;
    int getRear()const;
    
    
    //Metodes cas de prova
    void casProva1();
    void casProva2();

private:
    int size;
    vector<int> data ;
    int front;
    int rear;
    int count;
};



#endif /* ARRAYDEQUEUE_H */

