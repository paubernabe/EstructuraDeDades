/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinHeap.hpp
 * Author: paubc
 *
 * Created on 19 / de maig / 2018, 17:58
 */

#ifndef MINHEAP_HPP
#define MINHEAP_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "NodeHeap.hpp"
#include "movie.hpp"
using namespace std;

template <class Type>
class MinHeap{
    public:
        MinHeap();
        void MinHeapCopied();
        int Size();
        bool Empty();
        void insert(const Type& element, int key);
        int min();
        void minValues();//retorna els valors de la clau minima
        void removemin();
        void printHeap();
        bool Search(int key);
        //get left, right and parent 
        int getLeft(int parent);
        int getRight(int parent);
        int getParent(int child);
        
        int sizeHeap();
        void upheap();
        void downheap();
        
    private:
         vector<NodeHeap<Type>> heap;
         int i=0;
         int count=0;

};

template <class Type>
MinHeap<Type>::MinHeap(){
    this->heap=heap;
}






template <class Type>
void MinHeap<Type>::insert(const Type& element, int key){
    
    if(heap.size()==0){
        NodeHeap<Type> node= NodeHeap<Type>(element,key);
        heap.push_back(node);
        heap[0]=node;
    }
    else{
        
        NodeHeap<Type> node= NodeHeap<Type>(element,key);
        heap.push_back(node);
        
        upheap();
        
    }
    
   
}

template <class Type>
void MinHeap<Type>::upheap(){
    
     int fill=heap.size()-1;
     int pare=this->getParent(fill);
     
     while(fill!=0 and this->heap.at(fill).getKey() < this->heap.at(pare).getKey()){
         swap(heap[fill],heap[pare]);
         fill=pare;
         pare=this->getParent(fill);
         
          
    }
    
}

template <class Type>
void MinHeap<Type>::printHeap(){
    
    TADMovie m;
    while(heap.size()!=0){
        if (count!=40){
            this->removemin();
            ++count;
        }else{
            this->count=0;
            cout<<"Continuar mostrant?"<<endl;
            cin.get();
        }
        
        
    }
}
template <class Type>
int MinHeap<Type>::min(){
    return heap[0].getKey();
}
template <class Type>
void MinHeap<Type>::minValues(){
    TADMovie m;
    cout<< m.toString(heap[0].getValue())<<endl;;
}
template <class Type>
bool MinHeap<Type>::Search(int key){
    TADMovie m;
    for(int k=0; k<heap.size()-1;k++){
        if (key==heap[k].getKey()){
            cout<<m.toString(heap[k].getValue())<<endl;
            
            return true;
        }
        
    }
    return false;
}
template <class Type>
void MinHeap<Type>::removemin(){
    TADMovie m;
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downheap();
    cout<< m.toString(heap[0].getValue())<<endl;
    
}
template <class Type>
void MinHeap<Type>::downheap(){
    
    int pare=0;
    int filldret=this->getRight(pare);
    int fillesquerra=this->getLeft(pare);
    
    while(pare!=heap.size()-1 and  (heap[pare].getKey()>heap[filldret].getKey() or heap[pare].getKey()>heap[fillesquerra].getKey())){
         if(fillesquerra>=heap.size()-1 or filldret>=heap.size()-1){
            return;
    }
        if (heap[filldret].getKey()<heap[fillesquerra].getKey()){
            swap(heap[pare],heap[filldret]);
            
            pare=filldret;
            filldret=this->getRight(pare);
            
            
            
        }
        
        else if (heap[fillesquerra].getKey()<heap[filldret].getKey()){
             swap(heap[pare],heap[fillesquerra]);
             
             pare=fillesquerra;
             fillesquerra=this->getLeft(pare);
            
            
            
        }
        
    }
  
    
    
}


template <class Type>
int MinHeap<Type>:: sizeHeap(){
    int ctr=0;
    int fill=heap.size()-1;
    int pare=this->getParent(fill);
    
    while(fill!=0){
        fill=pare;
        pare=this->getParent(fill);
        ++ctr;
    }
    return ctr;
    
}


//GETS PARENT, LEFT & RIGHT
template <class Type>
int MinHeap<Type>::getLeft(int parent){
    return parent*2+1;
}
template <class Type>
int MinHeap<Type>::getRight(int parent){
    return parent*2+2;
}
template <class Type>
int MinHeap<Type>::getParent(int child){
    
    if(child%2==1){
        
        return (child-1)/2;
        
    }else if (child%2==0){
        return (child-2)/2;
    }
}


#endif /* MINHEAP_HPP */

