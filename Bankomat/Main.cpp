#include "Bankomat.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    int choice = 0;
    Bankomat bankomat("A4312", 10, 1000,15000);

    cout << "ATM ID number: " << bankomat.getIdBank() << endl;
    
    while (true) {
        cout << "Choose: " <<  endl;
        cout << "1. Withdraw money" << endl;
        cout << "2. Put money" << endl;
        cout << "3. Remaining Balance" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            // withdrawals money
            int amountToWithdraw;
            cout << "Input the amount to withdraw: ";
            cin >> amountToWithdraw;
            bankomat.withdrawSum(amountToWithdraw);
            break;
        case 2:
            // Put it money
            int amountToDeposit;
            cout << "Input the amount to top up: ";
            cin >> amountToDeposit;
            bankomat.loadSum(amountToDeposit);
            break;
        case 3:
            // print balance
            cout << "Remaining Balance: " << bankomat.convToString() << endl;
            break;
        case 0:
            // exit
            return 0;
        default:
            cout << "Wrong choice. Try again." << endl;
        }
    }

    return 0;
}
