#ifndef FOOD_VENDING_MACHINE_H
#define FOOD_VENDING_MACHINE_H
#include <iostream>
#include "vending-state.h"
using namespace std;

class VMState;
class FoodVendingMachine {
    private:
        VMState* current;
        int m_stock_qty;
    public:

        FoodVendingMachine(int stockqty) {
            m_stock_qty = stockqty;
            if (m_stock_qty > 0) {
                current = new    
            }
            current = new Dis();
        }
        void setCurrent( VMState* s ) {
             current = new VMState();
        }
        void coinInsert() {
            cout << "Inserting coin in VM \n";
            current->coininsert(  this ); 
        }
        void dispense() {
            cout << "Vending Machine dispensing\n"; 
            current->dispense( this ); 
            this->m_stock_qty--;
        }
        int getcurrentstock() {
            return this->m_stock_qty;
        }
};
#endif