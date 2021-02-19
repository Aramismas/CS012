#ifndef _ITEMTOPURCHASE_H_
#define _ITEMTOPURCHASE_H_
#include <string>
class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(std::string n, std::string d, int p, int q);
        void SetName(std::string n);
        void SetPrice(int p);
        void SetQuantity(int q);
        void SetDescription(std::string d);
        std::string GetName();
        std::string GetDescription();
        int GetPrice();
        int GetQuantity();
        ItemToPurchase operator+(ItemToPurchase rhs);
        void PrintItemCost();
        void PrintItemDescription();
    private:
        std::string itemName;
        std::string itemDescription;
        int itemPrice;
        int itemQuantity; 
};

#endif