#include <iostream>

using namespace std;

class Toy {
    protected:
        string m_name;
        float price;
    
    public:
        virtual void prepareParts() = 0;
        virtual void combineParts() = 0;
        virtual void assembleParts() = 0;
        virtual void applyLabel() = 0;
        virtual void showProducts() = 0;
};

class Car : public Toy {
    public:
        void prepareParts() {
            cout << "Preparing Car parts" << endl;
        }

        void combineParts() {
            cout << "Combining Car parts" << endl;
        }

        void assembleParts() {
            cout << "Assembling  car Parts" << endl;
        }

        void applyLabel() {
            cout << "Applying car Label" <<  endl;
            m_name  = "Car";
            price =  10;
        }

        void showProducts() {
            cout << "Name: " << m_name << " Float: " << price <<   endl;
        }
};

class Bike : public Toy {
    public:
            void prepareParts() {
            cout << "Preparing Bike parts" << endl;
        }

        void combineParts() {
            cout << "Combining Bike parts" << endl;
        }

        void assembleParts() {
            cout << "Assembling  Bike Parts" << endl;
        }

        void applyLabel() {
            cout << "Applying Bike Label" << endl;
            m_name = "Bike";
            price = 100.00;
        }

        void showProducts() {
            cout << "Name: " << m_name << " Float: " << price <<   endl;
        }
};


class Plane : public Toy {
    public:
            void prepareParts() {
            cout << "Preparing Plane parts" << endl;
        }

        void combineParts() {
            cout << "Combining Plane  parts" << endl;
        }

        void assembleParts() {
            cout << "Assembling  Plane  Parts" << endl;
        }

        void applyLabel() {
            cout << "Applying Plane Lable" << endl;
            m_name = "Plane";
            price = 200.00;
        }

        void showProducts() {
            cout << "Name: " << m_name << " Float: " << price <<   endl;
        }
};