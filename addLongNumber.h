#ifndef SUMMNUMBERS_ADDLONGNUMBER_H
#define SUMMNUMBERS_ADDLONGNUMBER_H

using namespace std;

struct longNumberElement {
    longNumberElement *next, *prev;
    short data;
};

using namespace std;
using longNumber = longNumberElement*;

class addLongNumber {
private:
    short getCounterDigit();
    void incrementCounterDigit();
    void incrementPrevElement(longNumber &other);

    longNumber operand, last;
    short nDigit;
public:
    addLongNumber(bool requestInput = true);
    addLongNumber(const string& numberPerLine);
    addLongNumber(longNumber &other);

    void addDigital(short digit);
    void initializeFirstElement(short digit);
    void printNumber();

    longNumber getLastElement();

    addLongNumber operator+(addLongNumber& other);

    void insertFirst(short digit);


};


#endif
