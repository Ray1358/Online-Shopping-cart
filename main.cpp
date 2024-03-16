#include <iostream>
#include "ShoppingCart.h"
using namespace std;

void PrintMenu() {
    cout << "\nMENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

void ExecuteMenu(char option, ShoppingCart& cart) {
    if (option == 'a') {
        cout << "ADD ITEM TO CART" << endl;
        ItemToPurchase newItem;
        string itemName, itemDescription;
        int itemPrice, itemQuantity;

        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, itemName);
        newItem.SetName(itemName);

        cout << "Enter the item description:" << endl;
        getline(cin, itemDescription);
        newItem.SetDescription(itemDescription);

        cout << "Enter the item price:" << endl;
        cin >> itemPrice;
        newItem.SetPrice(itemPrice);

        cout << "Enter the item quantity:" << endl;
        cin >> itemQuantity;
        newItem.SetQuantity(itemQuantity);

        cart.AddItem(newItem);
    } else if (option == 'd') {
        cout << "REMOVE ITEM FROM CART" << endl;
        string itemName;
        cout << "Enter name of item to remove:" << endl;
        cin.ignore();
        getline(cin, itemName);
        cart.RemoveItem(itemName);
    } else if (option == 'c') {
        cout << "CHANGE ITEM QUANTITY" << endl;
        string itemName;
        int newQuantity;
        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, itemName);
        cout << "Enter the new quantity:" << endl;
        cin >> newQuantity;

        ItemToPurchase modifiedItem(itemName, "none", 0, newQuantity);
        cart.ModifyItem(modifiedItem);
    } else if (option == 'i') {
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        cart.PrintDescriptions();
    } else if (option == 'o') {
        cout << "OUTPUT SHOPPING CART" << endl;
        cart.PrintTotal();
    } else if (option == 'q') {
        // Do nothing, 'q' is handled outside of the function
    } else {
        return;
    }
}
int main() {
    string customerName, currentDate;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    cout <<endl;
    getline(cin, currentDate);

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;
    cout << endl;

    ShoppingCart cart(customerName, currentDate);
    PrintMenu();
    char menuOption;
    do {
        cout <<"choose an option: " <<endl;
        cin >> menuOption;
        ExecuteMenu(menuOption, cart);
    } while (menuOption != 'q');

    return 0;
}
