#include "dispense.h"
#include "coininsert.h"

using namespace std; 

void CoinInsert::dispense(FoodVendingMachine *m){
    cout << "   going from coininsert to dispense ";
   m->setCurrent( new Dispense() );
   delete this;
}
