/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.hpp
 * Author: paubc
 *
 * Created on 16 / d’abril / 2018, 18:26
 */

#ifndef NODETREE_HPP
#define NODETREE_HPP
#include <iostream>
#include <cstdlib>
using namespace std;
template <class Type>
class NodeTree {
 public:
 NodeTree(const Type& data);
NodeTree(const NodeTree& orig);
 virtual ~NodeTree(); // destructor
/*Consultors*/
NodeTree<Type>* getright() const;//
 NodeTree<Type>* getleft() const;//
NodeTree<Type>* getparent() const;//
 bool hasRight() const;//
bool hasLeft() const;//
 bool isRoot() const;//
bool isExternal() const;//
 const Type& getElement() const;//
int getHeight() const;//
 void setHeight(int h);//
/*Modificadors*/
 void setData(const Type& data);
void setRight(NodeTree<Type>* newRight);
 void setLeft(NodeTree<Type>* newLeft);
void setParent(NodeTree<Type>* newParent);
 private:
 NodeTree<Type>* pParent;
 NodeTree<Type>* pLeft;
NodeTree<Type>* pRight;
 Type data;
int height;
};

template <class Type>
NodeTree<Type>::NodeTree(const Type& data){
    this->data=data;
    this->pParent=nullptr;
    this->pLeft=nullptr;
    this->pRight=nullptr;
    
}

template <class Type>
NodeTree<Type>::NodeTree(const NodeTree& orig){
    
}

template <class Type>
NodeTree<Type>:: ~NodeTree(){
    
    
}
template <class Type>
NodeTree<Type>*NodeTree<Type>::getright() const{
    return pRight;
}
template <class Type>
NodeTree<Type>*NodeTree<Type>::getleft() const{
    return pLeft;
}
template <class Type>
NodeTree<Type>*NodeTree<Type>::getparent() const{
    return pParent;
}
template <class Type>
bool NodeTree<Type>::hasLeft() const{
    return (pLeft!=nullptr);
    
}
template <class Type>
bool NodeTree<Type>::hasRight() const{
    return (pRight!=nullptr);
    
}
template <class Type>
bool NodeTree<Type>::isExternal() const{
    return (pRight==nullptr and pLeft==nullptr);
    
}
template <class Type>
bool NodeTree<Type>::isRoot() const{
    return (pParent==nullptr);
      
}
template <class Type>
const Type& NodeTree<Type>::getElement()const{
    return data;
    
}
template <class Type>
int NodeTree<Type>::getHeight() const{
    return height;
}
template <class Type>
void NodeTree<Type>::setHeight(int h){
    this->height=h;
}

template <class Type>
void NodeTree<Type>::setData(const Type& data){
    this->data=data;
}
template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    this->pLeft=newLeft;
    
}
template<class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    this->pRight=newRight;
}
template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    this->pParent=newParent;
}

#endif /* NODETREE_HPP */

