//
// CopyRight 2024
//

#include "ItemToPurchase.h"
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(std::string name, std::string description, int price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
    itemDescription = description;
}

// Setters
void ItemToPurchase::SetName(const std::string& name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

// Getters
std::string ItemToPurchase::GetName() const {
    return itemName;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

std::string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

void ItemToPurchase::SetDescription(const std::string& description) {
    itemDescription = description;
}

