#include <iostream>
#include <string>
#include <cassert>

#include "GiftCard.h"
#include "Retailer.h"

using namespace std;

int main() {

	GiftCard cardT("Starbucks", 100.00);
	assert(cardT.getRetailer() == "Starbucks");
	assert(cardT.getRetailer() != "Apple");
	assert(std::to_string(cardT.getAmount()) == "100.000000");
	cardT.setAmount(150.00);
	assert(std::to_string(cardT.getAmount()) == "150.000000");
	cardT.empty();
	assert(std::to_string(cardT.getAmount()) == "0.000000");

	cardT.setAmount(60.00);
	assert(cardT.canBeUsedToPurchase(30.00) == true);
	assert(cardT.canBeUsedToPurchase(60.00) == true);
	assert(cardT.canBeUsedToPurchase(70.00) == false);
	assert(cardT.canBeUsedToPurchase(-10.00) == false);
	assert(cardT.canBeUsedToPurchase(0.00) == false);

	Retailer a("Starbucks");
	assert(a.getName() == "Starbucks");
	assert(a.getName() != "Amazon");

	Retailer c("Amazon");
	GiftCard cardB("Starbucks", 90.00);
	//assert(a.purchaseItem("frappe", 20.00, cardB) == true);
	//assert(a.purchaseItem("frappe", 5.00, cardB) == true);
	//assert(a.purchaseItem("beans", 100.00, cardB) == false);
	//assert(a.purchaseItem("other beans", 90.00, cardB) == true);

	//assert(c.purchaseItem("bracelet", 50.00, cardB) == false);
	GiftCard cardC("Starbucks", 40.00);
	GiftCard cardD("Apple", 100.00);

	assert(a.purchaseItem("200 frappe", 10.00, cardB, cardC) == true);

	//assert(a.purchaseItem("60 frappe", 60.00, cardC, cardB) == true);
	//assert(std::to_string(cardC.getAmount()) == "0.000000");
	//assert(std::to_string(cardB.getAmount()) == "80.000000");

	//assert(a.purchaseItem("50 frappe", 50.00, cardC, cardB) == true);
	//assert(std::to_string(cardC.getAmount()) == "0.000000");
	//assert(std::to_string(cardB.getAmount()) == "90.000000");

	//assert(a.purchaseItem("40 frappe", 40.00, cardC, cardB) == true);
	//assert(std::to_string(cardC.getAmount()) == "10.000000");
	//assert(std::to_string(cardB.getAmount()) == "90.000000");

	assert(a.returnItem("tumbler", 20.00, cardC) == true);
	//assert(std::to_string(cardC.getAmount()) == "70.000000");

	assert(c.returnItem("tumbler", 20.00, cardC) == false);
	assert(c.returnItem("tumbler", 0.00, cardC) == false);
	assert(c.returnItem("tumbler", -10.00, cardC) == false);



	GiftCard card("Amazon", 100.00);
	assert(card.getRetailer() == "Amazon");
	assert(std::to_string(card.getAmount()) == "100.000000");
	assert(card.isEmpty() == false);
	assert(card.canBeUsedToPurchase(200.00) == false);
	assert(card.canBeUsedToPurchase(10.00));
	card.empty();
	assert(card.canBeUsedToPurchase(10.00) == false);

	card.setAmount(100.00);
	assert(card.canBeUsedToPurchase(10.00));

	Retailer r("Apple Store");
	assert(r.getName() == "Apple Store");
	assert(r.purchaseItem("Air Tags", 49.00, card) == false);
	Retailer b("Amazon");
	assert(b.purchaseItem("item1", 110.00, card) == false);
	assert(b.purchaseItem("item1", 90.00, card) == true);

	assert(r.returnItem("Apple Pencil", 99.00, card) == false);
	GiftCard card1("Apple Store", 100.00);
	GiftCard card2("Apple Store", 100.00);
	//assert(r.purchaseItem("Apple Watch", 200.00, card1, card2) == true);
	//assert(r.purchaseItem("Apple Watch", 210.00, card1, card2) == false);
	//assert(r.purchaseItem("Apple Watch", 190.00, card1, card2) == true);

	assert(r.purchaseItem("Air Pods", 99.00, card1) == true);
	assert(std::to_string(card1.getAmount()) == "1.000000");
	assert(r.returnItem("Air Pods", 99.00, card1) == true);
	assert(std::to_string(card1.getAmount()) == "100.000000");

	assert(r.purchaseItem("Apple Watch", 189.00, card1, card2) == true);
	assert(card1.isEmpty());
	assert(std::to_string(card2.getAmount()) == "11.000000");

	cout << "all tests passed!" << endl;
	return(0);


}