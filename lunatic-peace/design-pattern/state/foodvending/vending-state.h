#ifndef VENDING_STATE_H
#define VENDING_STATE_H
#include <iostream>
using namespace std;
class FoodVendingMachine;

class VMState {
public:
        virtual void coininsert( FoodVendingMachine* m ) = 0; 
        virtual void dispense( FoodVendingMachine* m ) = 0;
protected:
    void changestate(FoodVendingMachine* m, VMState *s){
        VMState *vs = m->current;
    }
};
#endif