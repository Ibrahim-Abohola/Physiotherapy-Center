//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file StackADT.h */

#ifndef STACK_ADT_
#define STACK_ADT_

template<typename T>
class StackADT
{
public:
    
    virtual bool isEmpty() const = 0;

    virtual bool push(const T& newEntry) = 0;

    virtual bool pop(T& TopEntry) = 0;

 
    virtual bool peek(T& TopEntry) const = 0;

    virtual ~StackADT() {}
}; 
#endif