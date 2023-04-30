#include <iostream>
#include "addLongNumber.h"

using namespace std;

addLongNumber::addLongNumber() {
    cout << "Default constructor class \n";

    firstOperand = nullptr;
    secondOperand = nullptr;


    int number = 0;
    longNumber lastPrev;


    cout << "Input pls first digit of a first long number \n";
    cout << "If you are finished entering `00` \n";

    do {
        cin >> number;

        if (number > 9) {
            cout << "Enter pls number > 9 \n";
            continue;
        }

        if (firstOperand == nullptr) {
            firstOperand = new longNumberElement;
            firstOperand->data = number;
            firstOperand->next = nullptr;
            firstOperand->prev = nullptr;
            lastPrev = firstOperand;
        } else {
            longNumber temp = new longNumberElement;
            temp->data = number;
            temp->prev = lastPrev;
            temp->next = nullptr;
            lastPrev->next = temp;
        }

    } while(number != 00);

    cout << "Input pls first digit of a second long number \n";
    cout << "If you are finished entering `00` \n";

    lastPrev = nullptr;
    number = 0;

    do {
        cin >> number;

        if (number > 9) {
            cout << "Enter pls number > 9 \n";
            continue;
        }

        if (secondOperand == nullptr) {
            secondOperand = new longNumberElement;
            secondOperand->data = number;
            secondOperand->next = nullptr;
            secondOperand->prev = nullptr;
            lastPrev = secondOperand;
        } else {
            longNumber temp = new longNumberElement;
            temp->data = number;
            temp->prev = lastPrev;
            temp->next = nullptr;
            lastPrev->next = temp;
        }

    } while(number != 00);

}

addLongNumber::addLongNumber(char numberPerLine) {
    cout << "Constructor that takes a string \n";

}