#include <iostream>
#include "Bankomat.h"
#include <string>

using namespace std;

Bankomat::Bankomat()
{
	idBank = "";
	minSum = 10;
	maxSum = 1000;
	balance = 0;
}

Bankomat::Bankomat(string id, int min, int max, int bal)
{
	idBank = id;
	minSum = min;
	maxSum = max;
	balance = bal;
}


int Bankomat::loadSum(int amount)
{
	if (amount >= minSum && amount <= maxSum) {
		balance += amount;
		cout << "Sum " << amount << " successfully added to balance." << endl;;
	}
	else {
		cout << "Incorrect amount to top up." << endl;
	}
	return balance;
}

int Bankomat::withdrawSum(int amount)
{
    if (amount >= minSum && amount <= maxSum && amount <= balance) {
        for (int i = 6; i >= 0; i--) {
            int noms = nominals[i];
            while (amount >= noms && balance >= noms) {
                amount -= noms;
                balance -= noms;
            }
        }
        if (amount == 0) {
			cout << "The amount was successfully withdrawn." << endl;
            return 1;
        }
    }
	else {
		cout << "It was not possible to withdraw the specified amount." << endl;
	}
    return 0;
}


string Bankomat::getIdBank() const
{
	return idBank;
}

string Bankomat::convToString()
{
	string sumString = to_string(balance);
	return sumString;
}
