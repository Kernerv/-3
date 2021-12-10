#include <iostream>
#include <stdio.h>
#include "CircularBuffer.h"
#include "Iterator.h"

Iterator::Iterator(CircularBuffer*& que) {
    this->index = que->firstelem - 1;
    this->queue = que;
}
//начать перебор элементов
void Iterator::start() {
    index = queue->firstelem - 1;

}
//перейти к следующему элементу
void Iterator::next() {
    index++;
    index = index % queue->size;
}
//проверка, все ли проитерировано
bool Iterator::finish() {
    if (queue->lastelem != index && !queue->checkEmpty()) {
        return false;
    } return true;
}
//получить очередной элемент очереди
int Iterator::getValue() {
    return queue->arr[index];
}