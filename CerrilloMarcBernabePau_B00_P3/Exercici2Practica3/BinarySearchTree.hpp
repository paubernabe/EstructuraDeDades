#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <cstdlib>
#include "movie.hpp"
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
 bool searchini(int id,NodeTree<Type>*tmp);//tmp
 void printInorder() ;
 void printPreorder() const;
 void printPostorder() const;
 int getHeight();
 void publicMirror();
 void printMirror() const;
/*Modificadors*/
 void insert(const Type& element,int id);
 void insertini(const Type& element,int id,NodeTree<Type> *tmp);//tmp

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
int count=0;
TADMovie m;
};

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(){
    
    pRoot=nullptr;
    
   
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
bool BinarySearchTree<Type>::searchini(int ele, NodeTree<Type>*tmp){
    
    if (tmp==nullptr){
        return false;
        
    }else if (tmp->getKey()==ele){
        return true;
    }
    else if (tmp->getKey()>ele){
        
        return searchini(ele,tmp->getleft());
    }
    else if (tmp->getKey()<ele){
        return searchini (ele,tmp->getright());
    
    
    }
    
}

//Aquests search ens han permes trobar la pelicula
//i que ens retorni l'objecte o la dada que volem
/********************************/
template <class Type>
bool BinarySearchTree<Type>::search(int ele){
   
   return this->searchini(ele,pRoot);
    
}

template <class Type>
string BinarySearchTree<Type>::searchshowm(int ele, NodeTree<Type>*tmp){
    
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
string BinarySearchTree<Type>::searchmovie(int ele){
   
   return this->searchshowm(ele,pRoot);
    
}

template <class Type>
TADMovie BinarySearchTree<Type>::searchfindm(int ele, NodeTree<Type>*tmp){
    
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
TADMovie BinarySearchTree<Type>::searchfind(int ele){
   
   return this->searchfindm(ele,pRoot);
    
}

template <class Type>
float BinarySearchTree<Type>::searchrating(int ele, NodeTree<Type>*tmp){
    
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
float BinarySearchTree<Type>::searchr(int ele){
   
   return this->searchrating(ele,pRoot);
    
}
/************************************/

template <class Type>

void BinarySearchTree<Type>::printInorder() {
    
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

template <class Type>
void BinarySearchTree<Type>::insertini(const Type& element,int id,NodeTree<Type> * tmp){
    
     
    if (pRoot==nullptr){
        
        pRoot=new NodeTree<Type>(element,id);
        
    }
    
    else if (tmp->getKey()<id){
        if (tmp->hasRight()){
            tmp=tmp->getright();
            insertini(element,id,tmp);
            
        }else{
            NodeTree<Type> *node=new NodeTree<Type>(element,id);
            node->setParent(tmp);
            tmp->setRight(node);
            
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
                        
        }
    }
    
}


template <class Type>
void BinarySearchTree<Type>::insert(const Type& element,int id){
    this->insertini(element,id,pRoot);
    
}


template <class Type>
void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    if (p!=nullptr){
        postDelete(p->getleft());
        postDelete(p->getright());
        delete p;
        
    }
    
        
}

//fem el comptador de pelicules per a cada 40, si apretem qualsevol tecla, continuara mostrant
//fins a finalitzar el document
template <class Type>
void BinarySearchTree<Type>::printInorder(NodeTree<Type>* tmp)  {
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
void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{
    if (p!=nullptr){
        printPostorder(p->getleft());
        printPostorder(p->getright());
        cout<<"("<<p->getKey()<<")"<<endl;;    
    }
    
}

template <class Type>
void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{
    
    if (p!=nullptr){
        cout<<"("<<p->getKey()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
}

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
template <class Type>
int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    if (p==nullptr){
        return 0;
    }else{
        return 1+(size(p->getright())+size(p->getleft()));
    }
    
}

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

template <class Type>
void BinarySearchTree<Type>::publicMirror(){
    this->mirror(pRoot);
}

template <class Type>
void BinarySearchTree<Type>::printMirror() const{
   this->printPreMirror(pRoot);
}

template <class Type>
void BinarySearchTree<Type>::printPreMirror(NodeTree<Type>* p) const{
    if (p!=nullptr){
        cout<<"("<<p->getValue()<<")"<<endl;;
        
        printPreorder(p->getleft());
        printPreorder(p->getright());
    }
    
    
}



#endif /* BINARYSEARCHTREE_HPP */



