// #pragma once
#ifndef GIFTCARD_H
#define GIFTCARD_H

#include <iostream>
#include <string>
using namespace std;

// define my structure or class here

class GiftCard 
{
private:
	string mRetailer;
	double mAmount;

public:
	GiftCard(string retailer, double amount);       // constructor
	
	string getRetailer() const;

	double getAmount() const;
	void setAmount(double amount);
	
	void empty();
	bool isEmpty();
	
	bool canBeUsedToPurchase(double amount);
	

};


#endif
