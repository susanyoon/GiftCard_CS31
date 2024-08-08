#include <iostream>
#include <string>
#include <cassert>

#include "GiftCard.h"
#include "Retailer.h"    

using namespace std;

Retailer::Retailer(string name)
{
	mName = name;
}
string Retailer::getName() const
{
	return(mName);
}
bool Retailer::purchaseItem(string item, double cost, GiftCard& card)
{
	bool result = true;

	if (card.getRetailer() != mName)
	{
		result = false;
	}

	else if (cost < 0.000000 || cost == 0.000000)
	{
		result = false;
	}

	else if (card.getAmount() == 0.000000 || card.getAmount() < 0.000000)
	{
		result = false;
	}
	
	else if (card.getAmount() > cost || card.getAmount() == cost)
	{
		card.setAmount(card.getAmount() - cost);
		result = true;
	}
	else
	{
		result = false;
	}
	
	return (result);
}

// With two GiftCards, purchaseItem(…) should use up the outstanding card amount of card1 in its entirety before reducing any amount of card2.

bool Retailer::purchaseItem(string item, double cost, GiftCard& card1, GiftCard& card2)
{
	bool result = false;

	if (card1.getAmount() <= 0.000000 && card2.getAmount() <= 0.000000) 
	{
		result = false;
	}
	else if (card1.getAmount() < 0.000000 || card2.getAmount() < 0.000000)
	{
		result = false;
	}
	
	else if (cost <= 0.000000)
	{
		result = false;
	}

	else if (card1.getRetailer() == mName && card2.getRetailer() == mName)
		{
			if (cost < card1.getAmount() + card2.getAmount() || cost == card1.getAmount() + card2.getAmount())
			{
				result = true;

				if (cost == card1.getAmount())
				{
					card1.setAmount(0.000000);
				}
				else if (cost > card1.getAmount())
				{
					card2.setAmount(card2.getAmount() - (cost - card1.getAmount()));
					card1.setAmount(0.000000);
				}
				else if (cost < card1.getAmount())                         // have to add cases when cost is less than card1 amount
				{
					card1.setAmount(card1.getAmount() - cost);
				}
			}
			else if (card2.getAmount() + card1.getAmount() < cost)
			{
				result = false;
			}
		}
	
	
	return (result);
}

//Retailer also allows for returned items, crediting a GiftCard for the cost of the returned item.  
// If the names of the Retailer and the GiftCard do match,then calls to returnItem( … ) 
// should verify first that the item's cost is greater than zero and then increase the GiftCard’s amount by the item’s cost.  
// When returnItem( … ) successfully returns an item, it should return true.  
// In all other circumstances, it should return false.
bool Retailer::returnItem(string item, double cost, GiftCard& card)
{
	bool result = false;

	if (card.getRetailer() != mName)
	{
		result = false;
	}
	else
	{
		if (cost > 0)
		{
			card.setAmount(card.getAmount() + cost);
			result = true;
		}
		else {
			result = false;
		}
	}
	
	return (result);
}