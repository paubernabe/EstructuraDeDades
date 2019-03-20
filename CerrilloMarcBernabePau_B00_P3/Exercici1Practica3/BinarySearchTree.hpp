/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.hpp
 * Author: paubc
 *
 * Created on 16 / d’abril / 2018, 18:26
 */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "NodeTree.hpp"
using namespace std;
template <class Type>
class BinarySearchTree{
public:
 /*Constructors i Destructors*/
 BinarySearchTree();
 BinarySearchTree(const BinarySearchTree& orig);
 virtual ~BinarySearchTree();
 /*Consultors*/
 int size() const;
 bool isEmpty() const; 
 NodeTree<Type>* root();
 bool search(int id);
 bool searchini(int id,NodeTree<Type>*tmp);
 void printInorder() const;
 void printPreorder() const;
 void printPostorder() const;
 int getHeight();
 void publicMirror();
 void printMirror() const;
/*Modificadors*/
 void insert(const Type& element);
 void insertini(const Type& element,NodeTree<Type> * tmp);
 
private:
 void mirror(NodeTree<Type>*p);
 void postDelete(NodeTree<Type>* p);
 int size(NodeTree<Type>* p) const;
 void printPreorder(NodeTree<Type>* p) const;
 void printPostorder(NodeTree<Type>* p) const;
 void printInorder(NodeTree<Type>* p) const;
 void printPreMirror(NodeTree<Type>*p)const;
int getHeight(NodeTree<Type>* p);
/*Atributs*/
NodeTree<Type>* pRoot;
};

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(){
    
    pRoot=nullptr;
    
   
}


template <class Type>
BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){
    
    if (pRoot!=nullptr){
        
        
    }
    
}



template <class Type>
BinarySearchTree<Type>::~BinarySearchTree(){
    this->postDelete(pRoot);
    
}
template <class Type>
int BinarySearchTree<Type>::size() const{
    this->size(pRoot);
    
    
}
template <class Type>
bool BinarySearchTree<Type>::isEmpty() const{
    return (pRoot==nullptr);
    
}
template <class Type>
NodeTree<Type> * BinarySearchTree<Type>::root(){
    return &pRoot;
    
}

//CERCA D'UN ELEMENT A L'ARBRE
template <class Type>
bool BinarySearchTree<Type>::searchini(int ele, NodeTree<Type>*tmp){
    
    if (tmp==nullptr){
        return false;
        
    }else{   
    if (tmp->getElement()==ele){
        return true;
    }
    else if (tmp->getElement()>ele){
        
        return searchini(ele,tmp->getleft());
    }
    else if (tmp->getElement()<ele){
        return searchini (ele,tmp->getright());
    }else{
        return false;
    }
    
    }
    
}


//funcions auxiliars recursives
template <class Type>
bool BinarySearchTree<Type>::search(int ele){
   
   return this->searchini(ele,pRoot);
    
}
template <class Type>

void BinarySearchTree<Type>::printInorder() const{
    
    this->printInorder(pRoot);
    
}
template <class Type>
void BinarySearchTree<Type>::printPostorder() const{
    this->printPostorder(pRoot);
    
}

template <class Type>
void BinarySearchTree<Type>::printPreorder() const{
    this->printPreorder(pRoot);
    
}
template <class Type>
int BinarySearchTree<Type>:: getHeight(){
    this->getHeight(pRoot);
    
    
}
//*****************

//INSERIM UN NODE
template <class Type>
void BinarySearchTree<Type>::insertini(const Type& element,NodeTree<Type> * tmp){
    
     
    if (pRoot==nullptr){
        
        pRoot=new NodeTree<Type>(element);
        
    }
    
    else if (tmp->getElement()<element){
        if (tmp->hasRight()){
            tmp=tmp->getright();
            insertini(element,tmp);
            
        }else{
            NodeTree<Type> *node=new NodeTree<Type>(element);
            node->setParent(tmp);
            tmp->setRight(node);
            
        }

        
    }
    else if (tmp->getElement()>element){
        if (tmp->hasLeft()){
            tmp=tmp->getleft();
            insertini(element,tmp);
        }else{
            
            NodeTree<Type> *node = new NodeTree<Type>(element);
            node->setParent(tmp);
            tmp->setLeft(node);
                        
        }
    }
    
}

//funcio auxiliar recursiva del insertini
template <class Type>
void BinarySearchTree<Type>::insert(const Type& element){
 
    this->insertini(element,pRoot);
     
    
}

//METODE delete postordre


template <class Type>
void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    if (p!=nullptr){
      
    
        
        postDelete(p->getleft());
        postDelete(p->getright());
        delete p;
    }
        
}
//METODES D'IMPRESSIÓ

//INORDER (esquerra, arrel, dreta)
template <class Type>
void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{
    
    if (p!=nullptr){
        printInorder(p->getleft());
        cout<<"("<<p->getElement()<<")"<<endl;
        printInorder(p->getright());
    }
    
    
     

}

//POSTORDRE (arrel,esquerra,dreta)
template <class Type>
void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{
    if (p!=nullptr){
        printPostorder(p->getleft());
        printPostorder(p->getright());
        cout<<"("<<p->getElement()<<")"<<endl;;    
    }
    
}
//PREORDRE (arrel,dreta,esquerra)
template <class Type>
void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{
    
    if (p!=nullptr){
        cout<<"("<<p->getElement()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
}

//CALCULEM LA PROFUNDITAT DE L'ARBRE
template <class Type>
int BinarySearchTree<Type>::getHeight(NodeTree<Type>* p){
    int l;
    int r;
    
    if(p==nullptr){
        return -1;
    }
        l=getHeight(p->getleft());
        r=getHeight(p->getright());
        
        return max(l,r)+1;
    
    
}

//TAMANY DE L'ARBRE
template <class Type>
int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    if (p==nullptr){
        return 0;
    }else{
        return 1+(size(p->getright())+size(p->getleft()));
    }
    
}

//FEM L'ARBRE MIRALL
template <class Type>
void BinarySearchTree<Type>::mirror(NodeTree<Type>* p){
    
    if(p!=nullptr){
        NodeTree<Type>*tmp;
        
        mirror(p->getleft());
        mirror(p->getright());
        
        tmp=p->getleft();
        
        
        p->setLeft(p->getright());
        p->setRight(tmp); 
        
    }
    
}

//FUNCIO auxiliar arbre mirall recursiva
template <class Type>
void BinarySearchTree<Type>::publicMirror(){
    this->mirror(pRoot);
}

//funcio auxiliar arbre mirall recursiva
template <class Type>
void BinarySearchTree<Type>::printMirror() const{
   this->printPreMirror(pRoot);
}

//imprimim l'arbre mirall en preordre
template <class Type>
void BinarySearchTree<Type>::printPreMirror(NodeTree<Type>* p) const{
    if (p!=nullptr){
        cout<<"("<<p->getElement()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
    
}
#endif /* BINARYSEARCHTREE_HPP */

