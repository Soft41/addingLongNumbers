#include <iostream>
#include "addLongNumber.h"
#include <string>

using namespace std;

addLongNumber::addLongNumber(bool requestInput) {
    cout << "Default constructor class \n";

    operand = nullptr;
    nDigit = 0;
    short digit = 0;

    if (requestInput) {
        cout << "Input pls first digit of a long number \n";
        cout << "If you are finished entering `999` \n";

        do {
            cin >> digit;

            if (digit > 9) {
                cout << "Enter pls digit > 9 \n";
                continue;
            }

            if (operand == nullptr) {
                if (digit == 0) {
                    cout << "First digit != 0 \n";
                    continue;
                } else {
                    initializeFirstElement(digit);
                }
            } else {
                addDigital(digit);
            }

            incrementCounterDigit();

        } while(digit != 999);
    }
}

addLongNumber::addLongNumber(const string& numberPerLine) {
    cout << "Constructor that takes a string \n";

    operand = nullptr;
    nDigit = 0;

    for (char digit : numberPerLine) {
        //symbol to digital
        if (operand == nullptr) {
            if (digit-48 == 0) {
                cout << "Error string, first digit != 0 \n";
                break;
            } else {
                initializeFirstElement(digit-48);
            }
        } else {
            addDigital(digit-48);
        }

        incrementCounterDigit();

    }
}

addLongNumber::addLongNumber(longNumber &other) {
    operand = other;
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

short addLongNumber::getCounterDigit() {
    return nDigit;
}

void addLongNumber::incrementCounterDigit() {
    nDigit++;
}

void addLongNumber::printNumber() {
    longNumber temp = operand;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

void addLongNumber::insertFirst(short digit) {
    if (operand == nullptr) {
        initializeFirstElement(digit);
    } else {
        longNumber temp = new longNumberElement;
        temp->data = digit;
        temp->next = operand;
        temp->prev = nullptr;
        operand->prev = temp;
        operand = temp;
        }
    incrementCounterDigit();
}


addLongNumber addLongNumber::operator+(addLongNumber &other) {
    cout << "Summ operator \n";
    this->printNumber();
    other.printNumber();

    longNumber nTemp = this->getLastElement();
    longNumber oTemp = other.getLastElement();

    addLongNumber tempObject(false);

    do {
        short data = nTemp->data + oTemp->data;

        tempObject.insertFirst(data >= 10 ? data % 10 : data);

        if (data >= 10) {
            incrementPrevElement(nTemp->prev);
        }

        nTemp = nTemp->prev;
        oTemp = oTemp->prev;
    } while (oTemp != nullptr && nTemp != nullptr);

    while (oTemp != nullptr || nTemp != nullptr) {
        tempObject.insertFirst((oTemp != nullptr) ? oTemp->data : nTemp->data);
        oTemp = (oTemp != nullptr) ? oTemp->prev : oTemp;
        nTemp = (nTemp != nullptr) ? nTemp->prev : nTemp;
    }

    return tempObject;

}

void addLongNumber::incrementPrevElement(longNumber &other) {
    if (other != nullptr) {
        other->data++;
    }
}


