#ifndef NODETREE_HPP
#define NODETREE_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>
class NodeTree {
public:
    NodeTree(const Type& value,int key);
    NodeTree(const NodeTree& orig);
    virtual ~NodeTree(); // destructor
    /*Consultors*/
    const int getKey() const;
    const Type& getValue() const;

    NodeTree<Type>* getright() const;
    NodeTree<Type>* getleft() const;
    NodeTree<Type>* getparent() const;
    bool hasRight() const;
    bool hasLeft() const;
    bool isRoot() const;
    bool isExternal() const;
    int getHeight() const;
    
    /*Modificadors*/
    void setValue(const Type& newValue);
    void setKey(int newKey);
    void setHeight(int h);
    void setRight(NodeTree<Type>* newRight);
    void setLeft(NodeTree<Type>* newLeft);
    void setParent(NodeTree<Type>* newParent);
private:
    NodeTree<Type>* pParent;
    NodeTree<Type>* pLeft;
    NodeTree<Type>* pRight;
    Type value;
    int key;
    int height=1;
};


//Constructor
template <class Type>
NodeTree<Type>::NodeTree(const Type& value,int key){
    
    this->value=value;
    this->key=key;
    
    this->pParent=nullptr;
    this->pLeft=nullptr;
    this->pRight=nullptr;
    
}
//Destructor
template <class Type>
NodeTree<Type>::~NodeTree(){
    
}

template <class Type>
const int NodeTree<Type>::getKey() const{
    return key;
}
template <class Type>
const Type& NodeTree<Type>::getValue() const{
    return value;
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
bool NodeTree<Type>::hasRight() const{
    return (pRight!=nullptr);
}
template <class Type>
bool NodeTree<Type>::hasLeft() const{
    return (pLeft!=nullptr);
}
template <class Type>
bool NodeTree<Type>::isRoot() const{
    return (pParent==nullptr);
}
template <class Type>
bool NodeTree<Type>::isExternal() const{
    return (pRight==nullptr and pLeft==nullptr);
}


template <class Type>
int NodeTree<Type>::getHeight() const{
    return height;
}


template <class Type>
void NodeTree<Type>::setValue(const Type& newValue){
    this->value=newValue;
}
template <class Type>
void NodeTree<Type>::setKey(int newKey){
    this->key=newKey;
}
template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    this->pRight=newRight;
}
template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
   this->pLeft=newLeft;
}
template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
   this->pParent=newParent;
}
template <class Type>
void NodeTree<Type>::setHeight(int h){
    this->height=h;
}


#endif /* NODETREE_HPP */


