/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paubc
 *
 * Created on 8 / de març / 2018, 12:20
 */
#include <cstdlib>
#include "arraydequeue.h"
#include <iostream>
#include <vector>



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    ArrayDequeue* arraydeque= new ArrayDequeue(5);
    
    int option,seeMenu(),ele;
    
    do{
        seeMenu();
        cin >> option;

        switch(option){
            
        
        case 1:
            cin >> ele;
            arraydeque->insertFront(ele);
            cout << "Element " << ele << " introduit" << endl;
            
            
            break;
            
        case 2:
            cin >> ele;
            arraydeque->insertRear(ele);
            cout << "Element " << ele<< " introduit" << endl;
            break;
            
        case 3:
            
            arraydeque->deleteFront();
            cout << "Element " << arraydeque->getFront() << " eliminat" << endl;
            break;
        
            
        case 4:
            
            
            arraydeque->deleteRear();
            cout << "Element " << arraydeque->getRear() << " eliminat" << endl;
                        
            
            break;
                    
        
        case 5:
            arraydeque->print();
            
            break;
         
        case 6:
            arraydeque->casProva1();
                
            break;
        case 7:
            arraydeque->casProva2();
            
            break;
                
                
        case 8:
            cout << "Fins la proxima" << endl;
            
            break;
            
                
        }
            
    } while (option!=8);
    
return 0;
}

int seeMenu(){
     
    int option,i;
    
string opt []={ "Inserir element pel davant", "Inserir element pel final","Eliminar element pel davant","Eliminar element pel final","Imprimir contingut de l'ArrayDEQUE","Imprimir Cas Prova 1","Imprimir Cas Prova 2", "Sortir" };
vector <string> arr_options (opt, opt+8);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}

//***************************************************************************************
//Metodes arraydequeue.h


ArrayDequeue::ArrayDequeue(int maxSize){
    this->size=maxSize;
    vector <int> vtemp (maxSize);
    this->data=vtemp;
    this->count=0;
    this->front=0;
    this->rear=0;
    
    
    
    
    cout << "Array de " << size << " posicions creada" << endl;
    
}

ArrayDequeue::~ArrayDequeue(){}

void ArrayDequeue::deleteFront(){
    
    try {
        if (isEmpty()==true){
            throw 0;
        }
    }catch (int i){
        cout << "EXCEPTION: deque buida" << endl;
    }
    
    
    if (!isEmpty()){
        
        this->rear=rear;
        this->front=front;
        
        data[front]=0;
        front=(front+1)%size;
        --count;
        
        
          
        
    }
}
    
    


void ArrayDequeue::deleteRear(){
    
        try {
        if (isEmpty()==true){
            throw 0;
        }
    }catch (int i){
        cout << "EXCEPTION: deque buida" << endl;
    }

    if(!isEmpty()){
        this->rear=rear;
        
        data[rear]=0;
        rear=(rear-1)%size;
        --count;
        
    }
    
}


void ArrayDequeue::insertFront(int element){
    
        try {
        if (isFull()){
            throw 0;
        }
    }catch (int i){
        cout << "EXCEPTION: deque plena" << endl;
    }
    
    if (isEmpty()){
        this->front=0;
        this->rear=0;
        this->data[front]=element;
        this->data[rear]=element;
        ++this->count;
        
    }
    else{
        
        if (front==0){
            front=size-1;
            this->data[front]=element;
            ++this->count;
            
        }else{
            front=(front-1)%size;
            this->data[front]=element;
            ++this->count;
        }
        
    
        
    }
    
}
void ArrayDequeue::insertRear(int element){
    
    try {
        if (isFull()==true){
            throw 0;
        }
    }catch (int i){
        cout << "EXCEPTION: deque plena" << endl;
    }
    if (isEmpty()){
        this->front=0;
        this->rear=0;
        data[rear]=element;
        data[front]=element;
        ++this->count;
    }
    
   
    else{
                
        this->rear=rear;
        
        rear=(rear+1)%size;
        
        this->data[rear]=element;
        ++this->count;    
        


        
    }
            
}

bool ArrayDequeue::isEmpty() const {
    
    return (count==0);
}


bool ArrayDequeue::isFull() const{
    return (count==size);

}



int ArrayDequeue::getFront() const{
    
    return this->data[front];
    
}

int ArrayDequeue::getRear() const {
    return this->data[rear];
    
}


void ArrayDequeue::print() const{
   
    vector <int> ::const_iterator i;
    
    for (i= data.begin(); i!=data.end(); ++i){
        cout << "["<< *i << "]"<< endl;
    }    
}
 
void ArrayDequeue:: casProva1(){
    
    ArrayDequeue* arraydeque= new ArrayDequeue(5);
    arraydeque->deleteFront();
    arraydeque->deleteRear();
    arraydeque->insertFront(20);
    arraydeque->insertFront(30);
    arraydeque->insertRear(80);
    arraydeque->insertRear(45);
    arraydeque->deleteFront();
    arraydeque->print();
    
    
}

void ArrayDequeue:: casProva2(){
    ArrayDequeue* arraydeque= new ArrayDequeue(3);
    arraydeque->deleteFront();
    arraydeque->deleteRear();
    arraydeque->insertFront(2);
    arraydeque->insertFront(3);
    arraydeque->insertRear(8);
    arraydeque->insertRear(4);
    arraydeque->deleteFront();
    arraydeque->print();
    
}



