#include <iostream>
#include "addLongNumber.h"
#include <string>

using namespace std;

addLongNumber::addLongNumber() {
    cout << "Default constructor class \n";

    operand = nullptr;

    short digit = 0;
    longNumber lastPrev;


    cout << "Input pls first digit of a long number \n";
    cout << "If you are finished entering `999` \n";

    do {
        cin >> digit;

        if (digit > 9) {
            cout << "Enter pls digit > 9 \n";
            continue;
        }

        if (operand == nullptr) {
            initializeFirstElement(digit);
        } else {
            addDigital(digit);
        }

    } while(digit != 999);
}

addLongNumber::addLongNumber(const string& numberPerLine) {
    cout << "Constructor that takes a string \n";

    operand = nullptr;

    for (char digit : numberPerLine) {
        //symbol to digital
        if (operand == nullptr) {
            initializeFirstElement(digit-48);
        } else {
            addDigital(digit-48);
        }
    }
}

void addLongNumber::initializeFirstElement(short digit) {
    operand = new longNumberElement;
    operand->data = digit;
    operand->next = nullptr;
    operand->prev = nullptr;
    last = operand;
};

void addLongNumber::addDigital(short digit) {
    longNumber temp = getLastElement();
    longNumber addElement = new longNumberElement;
    addElement->data = digit;
    addElement->prev = temp;
    addElement->next = nullptr;
    temp->next = addElement;
    last = addElement;
    temp = nullptr;
}

longNumber addLongNumber::getLastElement() {
    return last;
}

void addLongNumber::printNumber() {
    longNumber temp = operand;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

addLongNumber addLongNumber::operator+(addLongNumber &other) {
    cout << "Summ operator \n";
    this->printNumber();
    other.printNumber();
}