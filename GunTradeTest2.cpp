#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void options();

bool shipmentFull = false;
int money;

class gun {
public:
	gun(string NAME, int VALUE) {
		name = NAME, value = VALUE;
	}
private:
	string name;
	int value;
	friend class shipment;
};

gun AK47("AK47", 250);
gun Glock17("Glock 17", 475);
gun RPG7("RPG 7", 500);
gun Mossberg590("Mossberg 590", 600);
gun Barrett("Barrett 82A1", 3000);
gun arsenal[5] = { AK47, Glock17, RPG7, Mossberg590, Barrett };

class shipment {
public:
	shipment(gun G, int QUANTITY, int PRICE) : g(G) {
		quantity = QUANTITY, price = PRICE, total = price * quantity;
	}
private:
	gun g;
	int quantity;
	int price;
	int total;
	friend void buy();
	friend void sell();
};

class country {
public:
	country(string NAME) : name(NAME) {}
	string name;
	int buyPrice = 0;
	int sellPrice = 0;
	friend void buy();
	friend void sell();
};

country china("China");
country america("America");
country russia("Russia");
country mexico("Mexico");
country afghanistan("Afghanistan");
country world[5] = { china, america, russia, mexico, afghanistan };

void buy() {
	if (!shipmentFull) {
		// WIP
	}
	else {
		std::cout << "You already have a shipment, you need to sell it before you can buy another!" << endl;
		system("pause");
		system("CLS");
		options();
	}
}

void sell() {
	if (shipmentFull) {
		// WIP
	}
	else {
		std::cout << "You do not have a shipment. If you want to sell a shipment, you need to buy one first!" << endl;
		system("pause");
		system("CLS");
		options();
	}
}

int startMoney() {
	int x;
	std::cout << "How much money would you like to start with?" << endl << "Min: 5000" << endl << "Max: 20000" << endl;
	std::cin >> x;
	if (money <= 20000 && x >= 5000) {
		system("CLS");
		return x;
	}
	else {
		system("CLS");
		std::cout << "Invalid number, please try again!" << endl;
		system("pause");
		system("CLS");
		startMoney();
	}
}

void options() {
	std::cout << "1: Buy a shipment" << endl << "2: Sell a shipment" << endl;
	int option;
	std::cin >> option;
	switch (option) {
	case 1:
		system("CLS");
		buy();
	case 2:
		system("CLS");
		sell();
	default:
		system("CLS");
		std::cout << "Error, invalid input." << endl;
		system("pause");
		system("CLS");
		options();
	}
}

int main() {
	int start = 0;
	return 0;
	if (start == 0) {
		money = startMoney();
		start += 1;
	}
	options();
	system("CLS");
	main();
}