/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TADlinkeddeque.hpp
 * Author: paubc
 *
 * Created on 15 / d’abril / 2018, 16:27
 */

#ifndef TADLINKEDDEQUE_HPP
#define TADLINKEDDEQUE_HPP
#include <iostream>
#include <cstdlib>

using namespace std;
#include "TADnode.hpp"
template <class Element>
class LinkedDeque{
public:
LinkedDeque();
~LinkedDeque();

LinkedDeque(const LinkedDeque<Element>& deque);
bool isEmpty()const;
void insertFront(const Element & element);
void insertRear(const Element & element);
void deleteFront();
void deleteRear();
void print();

const Element& getFront()const;
const Element& getRear()const;
private:
Node<Element> *_front;
Node<Element> *_rear;
int num_elements;
};


template <class Element>
LinkedDeque<Element>::LinkedDeque(){
    Node <Element> *c1=new Node<Element>(0);
    Node <Element> *c2=new Node<Element>(0);
    this->_front=c1;
    this->_rear=c2;
    this->_front->setNext(c2);
    this->_front->setPrevious(nullptr);
    this->_rear->setNext(nullptr);
    this->_rear->setPrevious(c1);
    
    
    this->num_elements=0;
}

template <class Element>
LinkedDeque<Element>::~LinkedDeque(){
    
}


template <class Element>
bool LinkedDeque<Element>::isEmpty()const{

    return (this->num_elements==0);
    
}
template <class Element>
void LinkedDeque<Element>::insertFront(const Element& element){
    
    Node <Element> *nouNode = new Node<Element>(element);
    
    if (num_elements==0){
        this->_rear->setPrevious(nouNode);
        nouNode->setNext(this->_rear);
        this->_front->setNext(nouNode);
        nouNode->setPrevious(this->_front);
    }
     
    else if(num_elements==1){
        nouNode->setNext(this->_front->getNext());
        this->_front->getNext()->setPrevious(nouNode);
        this->_front->setNext(nouNode);
        nouNode->setPrevious(this->_front);}
      
    else{
        nouNode->setNext(this->_front->getNext());
        this->_front->getNext()->setPrevious(nouNode);
        this->_front->setNext(nouNode);
        nouNode->setPrevious(this->_front);
        
    }
    num_elements++;
   


}
template <class Element>
void LinkedDeque<Element>::insertRear(const Element& element){
    
    Node <Element> *nouNode = new Node<Element>(element);
    
    
    if (num_elements==0) {
        this->_rear->setPrevious(nouNode);
        nouNode->setNext(this->_rear);
        this->_front->setNext(nouNode);
        nouNode->setPrevious(this->_front);
    
    }
    
    else if(num_elements==1){
            
        nouNode->setPrevious(this->_rear->getPrevious());
        this->_rear->getPrevious()->setNext(nouNode);
        nouNode->setNext(this->_rear);
        this->_rear->setPrevious(nouNode);
        
    }else {
        nouNode->setPrevious(this->_rear->getPrevious());
        this->_rear->getPrevious()->setNext(nouNode);
        this->_rear->setPrevious(nouNode);
        nouNode->setNext(this->_rear);
    }
    num_elements++;
}
template <class Element>
void LinkedDeque<Element>::deleteFront(){
   Node<Element> *tmp=_front->getNext();

    if (num_elements==0){
        throw invalid_argument ("EXCEPTION: LINKED DEQUE BUIDA");
    }
    
    else if (num_elements==1){
        this->_front->setNext(this->_rear);
        this->_rear->setPrevious(this->_front);
        delete tmp;
        num_elements--;
        
        
        
    }else{
        this->_front->setNext(tmp->getNext());
        tmp->getNext()->setPrevious(this->_front);
        delete tmp;
        num_elements--;
        
    }
      
    
    
}
template <class Element>
void LinkedDeque<Element>::deleteRear(){
    Node <Element> *tmp=_rear->getPrevious();

    if (num_elements==0){
        throw invalid_argument ("EXCEPTION: LINKED DEQUE BUIDA");
    }
    else if (num_elements==1){
        this->_front->setNext(this->_rear);
        this->_rear->setPrevious(this->_front);
        delete tmp;
        num_elements--;
        
    }else{
        this->_rear->setNext(tmp->getPrevious());
        tmp->getPrevious()->setNext(this->_front);
        delete tmp;
        num_elements--;
        
    }
}
template <class Element>
const Element& LinkedDeque<Element>::getFront() const{
    return _front->getNext()->getElement();
}
template <class Element>
const Element & LinkedDeque<Element>::getRear() const{
    return _rear->getPrevious()->getElement();
}

template <class Element>
void LinkedDeque<Element>::print(){
    Node <Element> *imp;
    
    imp=_front->getNext();
    for(int i=0;i<this->num_elements;i++){
        cout<<"["<<imp->getElement()<<"]"<<endl;
        imp=imp->getNext();
        
        
    }
}
    
 
       
    
    
    
    




#endif /* TADLINKEDDEQUE_HPP */

