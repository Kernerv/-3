#include <iostream>
#include <stdio.h>
#include "CircularBuffer.h"
#include "Iterator.h"


CircularBuffer::CircularBuffer(int size) {
    mark = true;
    arr = new double[size];
    this->size = size;
    firstelem = 0;
    lastelem = 0;

}
CircularBuffer::CircularBuffer(const CircularBuffer& copy) {
    mark = copy.mark;
    this->size = copy.size;
    firstelem = copy.firstelem;
    lastelem = copy.lastelem;
    arr = new double[copy.size];
    for (int i = 0; i < size; i++) {
        arr[i] = copy.arr[i];
    }
}
//добавить элемент в конец очереди
void CircularBuffer::addElement(double element) {
    if ((lastelem + 1) % size == firstelem) {
        std::cout << "lenght error" << std::endl;
    }
    if (mark) {
        arr[lastelem] = element;
        mark = false;
    }
    else {
        lastelem++;
        lastelem = lastelem % size;
        arr[lastelem] = element;
    }
}
//взять элемент в начале очереди
double CircularBuffer::getElem() {
    if (mark) {
        std::cout << "error" << std::endl;
    }
    if (firstelem == lastelem) {
        mark = true;
        return arr[firstelem];
    }
    if (firstelem != lastelem) {
        firstelem++;
        return arr[firstelem - 1];
    }
}
//получить элемент в начале очереди
double CircularBuffer::seeElem() {
    if (mark) {
        std::cout << "error" << std::endl;
    }
    return arr[firstelem];
}
//размер очереди
int CircularBuffer::getSize() {
    return size;
}
//сделать очередь пустой
void CircularBuffer::doEmptyQueue() {
    firstelem = lastelem;
    mark = true;
}
//проверка очереди на пустоту
bool CircularBuffer::checkEmpty() {
    if (mark) { return true; }
    return false;
}