#include <iostream>
using namespace std;

int main() {
    double item1Price, item2Price, taxRate;
    char haveClubCard;
    double basePrice, priceAfterDiscounts, totalPrice;
    double const HALFOFF = 0.5, TENPERCENTOFF = 0.9, PERCENT = 0.01;

    cout << "Enter the price of first item: ";
    cin >> item1Price;
    cout << "Enter the price of Second item: ";
    cin >> item2Price;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> haveClubCard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    basePrice = item1Price + item2Price;

    if (item1Price < item2Price)
        priceAfterDiscounts = (HALFOFF * item1Price) + item2Price;
    else
        priceAfterDiscounts = (HALFOFF * item2Price) + item1Price;

    if (haveClubCard == 'y' || haveClubCard == 'Y')
        priceAfterDiscounts *= TENPERCENTOFF;

    totalPrice = priceAfterDiscounts * (1 + taxRate * PERCENT);

    cout << "Base Price: " << basePrice << endl;
    cout << "Price after discounts: " << priceAfterDiscounts << endl;
    cout << "Total Price: " << totalPrice << endl;

}
