// GiftCard.cpp 
//

#include <iostream>
#include <string>
#include <cassert>

#include "GiftCard.h"

using namespace std;

GiftCard::GiftCard(string retailer, double amount)
{
	mRetailer = retailer;
	mAmount = amount;
}


string GiftCard::getRetailer() const
{
	return(mRetailer);
}


double GiftCard::getAmount() const
{
	return(mAmount);
}

void GiftCard::setAmount(double amount)
{
	mAmount = amount;
}

void GiftCard::empty()
{
	mAmount = 0.000000;
}

bool GiftCard::isEmpty()
{
	bool result = false;
	if (mAmount == 0.000000 || mAmount < 0.000000)
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return (result);
	
}
//.canBeUsedToPurchase(…) verifies that the passed amount parameter is equal to or smaller than the outstanding card amount and returns true.
// If the passed amount is zero or less and in all other situations, it should return false.


bool GiftCard::canBeUsedToPurchase(double amount)
{
	bool result = false;
	if (amount == mAmount || amount < mAmount)
	{
		if (amount == 0.000000 || amount < 0.000000)
		{
			result = false;
		}
		else 
		{
			result = true;
		}
	}
	else
	{
		result = false;
	}
	return (result);
}




