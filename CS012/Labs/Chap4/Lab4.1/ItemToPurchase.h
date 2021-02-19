#ifndef _ITEMTOPURCHASE_H_
#define _ITEMTOPURCHASE_H_
#include <string>
class ItemToPurchase {
    public:
        ItemToPurchase();
        void SetName(std::string n);
        void SetPrice(int p);
        void SetQuantity(int q);
        std::string GetName();
        int GetPrice();
        int GetQuantity();
        ItemToPurchase operator+(ItemToPurchase rhs);
    private:
        std::string itemName;
        int itemPrice;
        int itemQuantity; 
};

#endif