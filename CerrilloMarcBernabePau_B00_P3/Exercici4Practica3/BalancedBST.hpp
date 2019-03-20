/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalancedBST.hpp
 * Author: paubc
 *
 * Created on 7 / de maig / 2018, 14:35
 */

#ifndef BALANCEDBST_HPP
#define BALANCEDBST_HPP
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "TADMovie.hpp"
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
 bool search(int ele);
 bool searchini(int ele, NodeTree<Type>*tmp);
 void printInorder() ;
 void printPreorder() const;
 void printPostorder() const;
 int getHeight();
 void publicMirror();
 void printMirror() const;
/*Modificadors*/
 void insert(const Type& element,int id);
 void insertini(const Type& element,int id,NodeTree<Type> * tmp);
 //Rotacions//
 void rotacioesquerra(NodeTree<Type> *p);
 void rotaciodreta(NodeTree<Type> *p);
 
 //maxims
 void maxtitol(NodeTree<Type>*p);
 float maxr();
 float maxrating(NodeTree<Type>*p);
 float minrating(NodeTree<Type>*p);
 
string searchmovie(int ele);
 string searchshowm(int ele, NodeTree<Type>*tmp);
 TADMovie searchfind(int ele);
 TADMovie searchfindm(int ele, NodeTree<Type>*tmp);
 float searchr(int ele);
 float searchrating(int ele, NodeTree<Type>*tmp);
 
private:
 void mirror(NodeTree<Type>*p);
 void postDelete(NodeTree<Type>* p);
 int size(NodeTree<Type>* p) const;
 void printPreorder(NodeTree<Type>* p) const;
 void printPostorder(NodeTree<Type>* p) const;
 void printInorder(NodeTree<Type>* p) ;
 void printPreMirror(NodeTree<Type>*p)const;
int getHeight(NodeTree<Type>* p);
/*Atributs*/
NodeTree<Type>* pRoot;
int balanceig;
int count=0;
TADMovie m;
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
    return (size()==0);
    
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
    if (tmp->getKey()==ele){
        return true;
    }
    else if (tmp->getKey()>ele){
        
        return searchini(ele,tmp->getleft());
    }
    else if (tmp->getKey()<ele){
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

void BalancedBST<Type>::printInorder(){
    
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
void BalancedBST<Type>::insertini(const Type& element,int id,NodeTree<Type> * tmp){
    
     
    if (pRoot==nullptr){
        
        pRoot=new NodeTree<Type>(element,id);
        
        pRoot->setHeight(1+max(getHeight(pRoot->getleft()),getHeight(pRoot->getright())));
        balanceig = (getHeight(pRoot->getright())-getHeight(pRoot->getleft()));
        
        
    }
    
    else if (tmp->getKey()<id){
        if (tmp->hasRight()){
            tmp=tmp->getright();
            insertini(element,id,tmp);
            
        }else{
            NodeTree<Type> *node=new NodeTree<Type>(element,id);
            node->setParent(tmp);
            tmp->setRight(node);
           
            
            pRoot->setHeight(1+max(getHeight(pRoot->getleft()),getHeight(pRoot->getright())));
            balanceig = (getHeight(pRoot->getright())-getHeight(pRoot->getleft()));
            
            
            
            if (balanceig>1){
                rotacioesquerra(pRoot);
                
            }
           

        }
        

        
    }
    else if (tmp->getKey()>id){
        if (tmp->hasLeft()){
            tmp=tmp->getleft();
            insertini(element,id,tmp);
            
            
        }else{
            
            NodeTree<Type> *node = new NodeTree<Type>(element,id);
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
void BalancedBST<Type>::insert(const Type& element, int id){
 
    this->insertini(element,id,pRoot);
     
    
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
void BalancedBST<Type>::printInorder(NodeTree<Type>* tmp)  {
    char op;
    if (tmp!=nullptr){
        if (this->count!=40){
            this->count++;
        printInorder(tmp->getleft());
        cout<<m.toString(tmp->getValue())<<endl;
        printInorder(tmp->getright()); 
        }else{
            this->count=0;
            cout<<"Continuar mostrant?"<<endl;
            cin.get();
        }
    }

}

template <class Type>
void BalancedBST<Type>::printPostorder(NodeTree<Type>* p) const{
    if (p!=nullptr){
        printPostorder(p->getleft());
        printPostorder(p->getright());
        cout<<"("<<p->getValue()<<")"<<endl;;    
    }
    
}

template <class Type>
void BalancedBST<Type>::printPreorder(NodeTree<Type>* p) const{
    
    if (p!=nullptr){
        cout<<"("<<p->getValue()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
}

template <class Type>
int BalancedBST<Type>::getHeight(NodeTree<Type>* p){
    int l;
    int r;
    
    if(p==nullptr){
        return 0;
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
        cout<<"("<<p->getKey()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
    
}
template <class Type>
void BalancedBST<Type>::rotaciodreta(NodeTree<Type>* node){
    
    NodeTree<Type>* tmp=node;
    NodeTree<Type>* left=node->getleft();
    NodeTree<Type>*parent=tmp->getparent();
    
    if(!tmp->isRoot()){
        
        if(left->getKey()>parent->getKey()){
            parent->setRight(left);
            left->setParent(parent);
        }else if(left->getKey()<parent->getKey()){
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
    }
    left->setRight(tmp);
    
    node->setHeight(1+max(getHeight(node->getleft()),getHeight(node->getright())));
    balanceig = (getHeight(node->getright())-getHeight(node->getleft()));
    }

    



template <class Type>
void BalancedBST<Type>::rotacioesquerra(NodeTree<Type>* node){
    NodeTree<Type>* tmp=node;
    NodeTree<Type>* right=node->getright();
    NodeTree<Type>*parent=node->getparent();
    
    if(!tmp->isRoot()){
        right->setParent(parent);
        if(right->getKey()>parent->getKey()){
            parent->setLeft(right);
        }else if (right->getKey()>parent->getKey()){
            parent->setRight(right);
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
    }
    right->setLeft(tmp);
   
        node->setHeight(1+max(getHeight(node->getleft()),getHeight(node->getright())));
        balanceig = (getHeight(node->getright())-getHeight(node->getleft()));
    
    
}



template <class Type>
string BalancedBST<Type>::searchshowm(int ele, NodeTree<Type>*tmp){
    
    if (tmp==nullptr){
        cout<<"no existeix"<<endl;
        
    }else{   
    if (tmp->getKey()==ele){
        return m.toString(tmp->getValue());
    
    }else if (tmp->getKey()>ele){
        
        return searchshowm(ele,tmp->getleft());
    }
    else if (tmp->getKey()<ele){
        return searchshowm(ele,tmp->getright());
    }else{
        cout<<"no existeix"<<endl;
    }
    
    }
    
}

template <class Type>
string BalancedBST<Type>::searchmovie(int ele){
   
   return this->searchshowm(ele,pRoot);
    
}

template <class Type>
TADMovie BalancedBST<Type>::searchfindm(int ele, NodeTree<Type>*tmp){
    
    if (tmp==nullptr){
        cout<<"no existeix"<<endl;
        
    }else{   
    if (tmp->getKey()==ele){
        return m;
    
    }else if (tmp->getKey()>ele){
        
        return searchfindm(ele,tmp->getleft());
    }
    else if (tmp->getKey()<ele){
        return searchfindm(ele,tmp->getright());
    }else{
        cout<<"no existeix"<<endl;
    }
    
    }
    
}

template <class Type>
TADMovie BalancedBST<Type>::searchfind(int ele){
   
   return this->searchfindm(ele,pRoot);
    
}

template <class Type>
float BalancedBST<Type>::searchrating(int ele, NodeTree<Type>*tmp){
    
    if (tmp==nullptr){
        cout<<"no existeix"<<endl;
        
    }else{   
    if (tmp->getKey()==ele){
        TADMovie m1=tmp->getValue();
        cout<<m1.getRating()<<endl;
        return m1.getRating();
    
    }else if (tmp->getKey()>ele){
        
        return searchrating(ele,tmp->getleft());
    }
    else if (tmp->getKey()<ele){
        return searchrating(ele,tmp->getright());
    }else{
        cout<<"no existeix"<<endl;
    }
    
    }
    
}

template <class Type>
float BalancedBST<Type>::searchr(int ele){
   
   return this->searchrating(ele,pRoot);
    
}





template <class Type>
float BalancedBST<Type>::maxr(){
   this->maxrating(pRoot);
}
template <class Type>
float BalancedBST<Type>::maxrating(NodeTree<Type>* p){
    TADMovie m= p->getValue();
    float lrating=m.getRating();
    float rrating=m.getRating();
    float maxrat=m.getRating();
    
        if (p->getleft()!=nullptr){
             lrating=max(lrating,maxrating(p->getleft()));
        }
        if (p->getright()!=nullptr){
            rrating=max(rrating,maxrating(p->getright()));
        }
        else{
            maxrat=max(rrating,lrating);
        }
    
    cout<<maxrat<<endl;
    cout<<m.toString(m)<<endl;
            
        
        
        
    
    
    
    
    
}






#endif /* BALANCEDBST_HPP */

