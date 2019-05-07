#ifndef DISPENSE_H
#define DISPENSE_H
#include "vending-state.h"

class Dispense : public VMState{
    public:
    Dispense() {
        cout << "Dispense Construtor \n";
    }
   ~Dispense() {
      cout<< "Dispense Destructor \n"; 
   }
    void coininsert(FoodVendingMachine *m) {
        cout << "   going from dispense to coinInserted state";
        m->setCurrent(new CoinInsert() );
        delete this;
    }
};
#endif