#ifndef COIN_INSERT_H
#define COIN_INSERT_H
#include "vending-state.h"
class CoinInsert : public VMState {
public:
   CoinInsert()  {
       cout << "   coin inserted-ctor ";  
   }
   ~CoinInsert() { 
      cout << "   dtor-coin inserted\n"; 
   }
   void dispense( FoodVendingMachine* m );
};
#endif