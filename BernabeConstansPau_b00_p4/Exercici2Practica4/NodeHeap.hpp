/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeHeap.hpp
 * Author: paubc
 *
 * Created on 19 / de maig / 2018, 17:59
 */

#ifndef NODEHEAP_HPP
#define NODEHEAP_HPP
#include <iostream>
#include <cstdlib>

using namespace std;
template <class Type>
class NodeHeap{
    public:
        NodeHeap(const Type& value,int key);
        //virtual~NodeHeap();
        int getKey();
        const Type& getValue();
        void setKey(int k);
        void setValue(const Type &val);
        
        
    private:
        Type value;
        int key;    
};
template <class Type>
NodeHeap<Type>::NodeHeap(const Type& value,int key){
    this->value=value;
    this->key=key;
}

template <class Type>
void NodeHeap<Type>::setValue(const Type& val){
    this->value=val;
}
template <class Type>
const Type &NodeHeap<Type>::getValue(){
   return value; 
}

template <class Type>
void NodeHeap<Type>::setKey(int k){
    this->key=k;
}

template <class Type>
int NodeHeap<Type>::getKey(){
    return key;
}








#endif /* NODEHEAP_HPP */

