#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() : itemName("none"), itemPrice(0), itemQuantity(0), itemDescription("none"){}
ItemToPurchase::ItemToPurchase(string n, string d, int p, int q) : itemName(n), itemDescription(d), itemPrice(p), itemQuantity(q) {}

void ItemToPurchase::SetName(string n) {
    itemName = n;
}

void ItemToPurchase::SetPrice(int p) {
    itemPrice = p;
}

void ItemToPurchase::SetQuantity(int q) {
    itemQuantity = q;
}

void ItemToPurchase::SetDescription(string d) {
    itemDescription = d;
}

string ItemToPurchase::GetName() {
    return itemName;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

ItemToPurchase ItemToPurchase::operator+(ItemToPurchase rhs) {
    ItemToPurchase addTotal;
    addTotal.itemPrice = itemPrice * itemQuantity + rhs.itemPrice * rhs.itemQuantity;
    return addTotal;
}

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}