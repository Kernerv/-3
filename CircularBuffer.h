#pragma once
class CircularBuffer {
private:
    double* arr;
    int size;
    int firstelem;
    int lastelem;
    bool mark;
public:
    friend class Iterator;
    CircularBuffer(int size);
    CircularBuffer(const CircularBuffer& copy);
    void addElement(double element);
    double getElem();
    double seeElem();
    void doEmptyQueue();
    int getSize();
    bool checkEmpty();
};