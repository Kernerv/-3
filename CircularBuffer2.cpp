#include <iostream>
#include <stdio.h>
#include "CircularBuffer.h"
#include "Iterator.h"
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    CircularBuffer* circleB = new CircularBuffer(7);
    circleB->addElement(3);
    circleB->addElement(5);
    circleB->addElement(7);
    CircularBuffer* circleA = new CircularBuffer(*circleB);
    CircularBuffer* circleC = new CircularBuffer(5);
    circleA->addElement(0);
    if (circleA->checkEmpty()) {
        cout << "queue is empty" << endl;
    }
    if (circleC->checkEmpty()) {
        cout << "queue is empty" << endl;
    }
    Iterator iteratorA = Iterator(circleA);
    Iterator iteratorB = Iterator(circleB);
    while (!iteratorB.finish()) {
        iteratorB.next();
        cout << iteratorB.getValue() << endl;

    }
    while (!iteratorA.finish()) {
        iteratorA.next();
        cout << iteratorA.getValue() << endl;

    }
    cout << "size circleA : " << circleA->getSize() << endl;
    circleA->doEmptyQueue();
    if (circleA->checkEmpty()) {
        cout << "circleA is empty" << endl;
    }
    iteratorA.start();
    while (!iteratorA.finish()) {
        iteratorA.next();
        cout << iteratorA.getValue() << endl;

    }
    cout << circleB->getElem() << endl;
    delete circleA;
    delete circleB;
    delete circleC;
    system("pause");
    return 0;
}