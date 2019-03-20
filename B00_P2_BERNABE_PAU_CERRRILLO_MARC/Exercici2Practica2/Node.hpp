/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.hpp
 * Author: paubc
 *
 * Created on 9 / d’abril / 2018, 22:44
 */

#ifndef NODE_HPP
#define NODE_HPP
#include <cstdlib>

template <class Element>
class Node{ 
public:
    Node(Element e);
    ~Node();
    const Element& getElement()const;
    void setNext(Node<Element> *e);
    Node <Element> *getNext()const;
    void setPrevious(Node<Element> *e);
    Node <Element> *getPrevious()const;
private:
    Element e;
    Node <Element> *next;
    Node <Element> *prev;
        
    
};


template <class Element>
Node<Element>::Node(Element e){
    
    this->e=e;
    
    this->next=nullptr;
    this->prev=nullptr;
    
}

template <class Element>
Node <Element>::~Node(){
    
}
template <class Element>
void Node<Element>::setNext(Node<Element>* e){
    this->next=e;
    
}
template <class Element>
void Node<Element>::setPrevious(Node<Element>* e){
    this->prev=e;
}
template <class Element>
Node <Element> *Node<Element>::getNext() const{
    return next;
}
template <class Element>
Node <Element> *Node<Element>::getPrevious() const{
    return prev;
}
template <class Element>
const Element& Node<Element>::getElement()const{
    return e;
}

#endif /* NODE_HPP */


