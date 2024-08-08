#ifndef RETAILER_H
#define RETAILER_H

#include <iostream>
#include <string>
#include "GiftCard.h"   // had to add this since some member variables are from GiftCard.h

using namespace std;

// define my structure or class here

class Retailer
{
private:
	string mName;

public:
	Retailer(string name);       // constructor

	string getName() const;

	bool purchaseItem(string item, double cost, GiftCard& card);
	bool purchaseItem(string item, double cost, GiftCard& card1, GiftCard& card2);
	bool returnItem(string item, double cost, GiftCard& card);

};


#endif
