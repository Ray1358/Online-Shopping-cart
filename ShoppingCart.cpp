//
// Copyright 2024
//

#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <iostream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;


ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(const std::string& name, const std::string& date) {
    customerName = name;
    currentDate = date;
}

std::string ShoppingCart::GetCustomerName() const {
    return customerName;
}

std::string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(const std::string& name) {
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == name) {
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() const {
    int numItems = 0;
    for (int i = 0; i < cartItems.size(); i++) {
        numItems += cartItems.at(i).GetQuantity();
    }
    return numItems;
}

int ShoppingCart::GetCostOfCart() const {
    int totalCost = 0;
    for (int i = 0; i < cartItems.size(); i++) {
        totalCost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << std::endl << endl;
    if (cartItems.size() == 0) {
        std::cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        for (int i = 0; i < cartItems.size(); i++) {
            cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice() << " = $" << cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity() << endl;
        }
    }
    cout << std::endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (int i = 0; i < cartItems.size(); i++) {
        cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetQuantity() << endl;
    }
}

