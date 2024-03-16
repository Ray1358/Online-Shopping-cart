//
// Copyright 2024
//

#ifndef INC_7_38_SHOPPINGCART_H
#define INC_7_38_SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <string>
#include <vector>



class ShoppingCart {
private:
    string customerName;
    string currentDate;
    std::vector<ItemToPurchase> cartItems;
public:
    ShoppingCart();
    ShoppingCart(const std::string& name, const std::string& date);
    std::string GetCustomerName() const;
    std::string GetDate() const;
    void AddItem(const ItemToPurchase& item);
    void RemoveItem(const std::string& name);
    void ModifyItem(const ItemToPurchase& item);
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void PrintTotal() const;
    void PrintDescriptions() const;



};


#endif //INC_7_38_SHOPPINGCART_H
