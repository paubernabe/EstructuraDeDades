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
class BalancedBST{
public:
 /*Constructors i Destructors*/
 BalancedBST();
 virtual ~BalancedBST();
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
 
 void rotacioesquerra(NodeTree<Type> *p);
 void rotaciodreta(NodeTree<Type> *p);
 
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
int balanceig;
};

template <class Type>
BalancedBST<Type>::BalancedBST(){
    
    pRoot=nullptr;
    
   
}




template <class Type>
BalancedBST<Type>::~BalancedBST(){
    this->postDelete(pRoot);
    
}
template <class Type>
int BalancedBST<Type>::size() const{
    this->size(pRoot);
    
    
}
template <class Type>
bool BalancedBST<Type>::isEmpty() const{
    return (pRoot==nullptr);
    
}
template <class Type>
NodeTree<Type> * BalancedBST<Type>::root(){
    return &pRoot;
    
}
template <class Type>
bool BalancedBST<Type>::searchini(int ele, NodeTree<Type>*tmp){
    
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



template <class Type>
bool BalancedBST<Type>::search(int ele){
   
   return this->searchini(ele,pRoot);
    
}
template <class Type>

void BalancedBST<Type>::printInorder() const{
    
    this->printInorder(pRoot);
    
}
template <class Type>
void BalancedBST<Type>::printPostorder() const{
    this->printPostorder(pRoot);
    
}

template <class Type>
void BalancedBST<Type>::printPreorder() const{
    this->printPreorder(pRoot);
    
}
template <class Type>
int BalancedBST<Type>:: getHeight(){
    this->getHeight(pRoot);
    
    
}
template <class Type>
void BalancedBST<Type>::insertini(const Type& element,NodeTree<Type> * tmp){
    
     
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
            
            
            //quan inserim el node actualitzarem l'alçada i el factor de balanceig
             pRoot->setHeight(1+max(getHeight(pRoot->getleft()),getHeight(pRoot->getright())));
            balanceig = (getHeight(pRoot->getright())-getHeight(pRoot->getleft()));
            
            
            //si el supera cridarem al metode de rotacio
            if (balanceig>1){
                rotacioesquerra(pRoot);
                
            }
            
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
            
             pRoot->setHeight(1+max(getHeight(pRoot->getleft()),getHeight(pRoot->getright())));
            balanceig = (getHeight(pRoot->getright())-getHeight(pRoot->getleft()));
    
            
            if (balanceig<-1){
                rotaciodreta(pRoot);
            }
                        
        }
    }
    
}


template <class Type>
void BalancedBST<Type>::insert(const Type& element){
 
    this->insertini(element,pRoot);
     
    
}


template <class Type>
void BalancedBST<Type>::postDelete(NodeTree<Type>* p){
    if (p!=nullptr){
      
    
        
        postDelete(p->getleft());
        postDelete(p->getright());
        delete p;
    }
        
}

template <class Type>
void BalancedBST<Type>::printInorder(NodeTree<Type>* p) const{
    
    if (p!=nullptr){
        printInorder(p->getleft());
        cout<<"("<<p->getElement()<<")"<<endl;
        printInorder(p->getright());
    }else{
        
    }
    
    
     

}

template <class Type>
void BalancedBST<Type>::printPostorder(NodeTree<Type>* p) const{
    if (p!=nullptr){
        printPostorder(p->getleft());
        printPostorder(p->getright());
        cout<<"("<<p->getElement()<<")"<<endl;;    
    }
    
}

template <class Type>
void BalancedBST<Type>::printPreorder(NodeTree<Type>* p) const{
    
    if (p!=nullptr){
        cout<<"("<<p->getElement()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
}

template <class Type>
int BalancedBST<Type>::getHeight(NodeTree<Type>* p){
    int l;
    int r;
    
    if(p==nullptr){
        return -1;
    }
        l=getHeight(p->getleft());
        r=getHeight(p->getright());
        
        return max(l,r)+1;
    
    
}
template <class Type>
int BalancedBST<Type>::size(NodeTree<Type>* p) const{
    if (p==nullptr){
        return 0;
    }else{
        return 1+(size(p->getright())+size(p->getleft()));
    }
    
}

template <class Type>
void BalancedBST<Type>::mirror(NodeTree<Type>* p){
    
    if(p!=nullptr){
        NodeTree<Type>*tmp;
        
        mirror(p->getleft());
        mirror(p->getright());
        
        tmp=p->getleft();
        
        
        p->setLeft(p->getright());
        p->setRight(tmp); 
        
    }
    
}

template <class Type>
void BalancedBST<Type>::publicMirror(){
    this->mirror(pRoot);
}

template <class Type>
void BalancedBST<Type>::printMirror() const{
   this->printPreMirror(pRoot);
}

template <class Type>
void BalancedBST<Type>::printPreMirror(NodeTree<Type>* p) const{
    if (p!=nullptr){
        cout<<"("<<p->getElement()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
    
}

template <class Type>
void BalancedBST<Type>::rotaciodreta(NodeTree<Type>* node){
    
    NodeTree<Type>* tmp=node;
    NodeTree<Type>* left=node->getleft();
    NodeTree<Type>*parent=node->getparent();
    if(!tmp->isRoot()){
        
        if(left->getElement()>parent->getElement()){
            parent->setRight(left);
            left->setParent(parent);
        }else if(left->getElement()<parent->getElement()){
            parent->setLeft(left);
            left->setParent(parent);
        }
    }else{
        left->setParent(nullptr);
        pRoot=left;
    }
    tmp->setParent(left);
    if(left->getright()!=nullptr){
        left->getright()->setParent(tmp);
        tmp->setLeft(left->getright());
    }else{
        tmp->setLeft(nullptr);
        left->setRight(tmp);
    }
    
    
    node->setHeight(1+max(getHeight(node->getleft()),getHeight(node->getright())));
    balanceig = (getHeight(node->getright())-getHeight(node->getleft()));
    

    
}


template <class Type>
void BalancedBST<Type>::rotacioesquerra(NodeTree<Type>* node){
    NodeTree<Type>* tmp=node;
    NodeTree<Type>* right=node->getright();
    NodeTree<Type>* parent=node->getparent();
    if(!tmp->isRoot()){
        
        if(right->getElement()>parent->getElement()){
            tmp->getparent()->setLeft(right);
            right->setParent(parent);
        }else if (right->getElement()>parent->getElement()){
            parent->setRight(right);
            right->setParent(parent);
        }
    }else{
        right->setParent(nullptr);
        pRoot=right;
    }
    tmp->setParent(right);
    if(right->getleft()!=nullptr){
        right->getleft()->setParent(tmp);
        tmp->setRight(right->getleft());
    }else{
        tmp->setRight(nullptr);
        right->setLeft(tmp);
    }
    
    node->setHeight(1+max(getHeight(node->getleft()),getHeight(node->getright())));
    balanceig = (getHeight(node->getright())-getHeight(node->getleft()));
    
    
}
#endif /* BINARYSEARCHTREE_HPP */

