//
// CopyRight 2024
//

#ifndef INC_7_38_ITEMTOPURCHASE_H
#define INC_7_38_ITEMTOPURCHASE_H
#include "string"
using std::string;

class ItemToPurchase {
private:
    std::string itemName;
    int itemPrice;
    int itemQuantity;
    std::string itemDescription;


public:
    // Default constructor
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    // Setters
    void SetName(const std::string& name);
    void SetPrice(int price);
    void SetQuantity(int quantity);
    void SetDescription(const std::string& description);

    // Getters
    std::string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    std::string GetDescription() const;


};


#endif //INC_7_38_ITEMTOPURCHASE_H
