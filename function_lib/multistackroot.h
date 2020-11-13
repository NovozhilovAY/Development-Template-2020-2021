#pragma once
#define MemLimit 100 // размер памяти
#define StackNum 10 // количество стеков

#include "stack.h"

class TMultiRoot
{
protected:
  TElem Mem[MemLimit]; // память для стеков
  int DefaultStack;    // номер текущего стека
public:
    TMultiRoot() { DefaultStack = 0;}

  virtual bool IsEmpty(int ns) const = 0;             // контроль пустоты СД
  virtual bool IsFull(int ns) const = 0;              // контроль переполнения СД
  virtual void Put(int ns, const TData &Val) = 0;     // положить в стек
  virtual TData Get(int ns) = 0;                      // взять из стека с удалением

                                                      // методы для работы с текущим стеком
  void SetDefaultStack(int ns) { DefaultStack = ns; }           // текущий стек
  int  IsEmpty(void) const { return IsEmpty(DefaultStack); }    // пуст ?
  int  IsFull(void) const { return IsFull(DefaultStack); }      // полон ?
  void Put(const TData &Val) { Put(DefaultStack, Val); }        // в стек
  TData Get(void) { return Get(DefaultStack); }                 // из стека
};
