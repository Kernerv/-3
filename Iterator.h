#pragma once
#include "CircularBuffer.h"

class Iterator {
    int index;
    CircularBuffer* queue;
public:
    friend class CircularBuffer;
    Iterator(CircularBuffer*& que);
    void start();
    void next();
    bool finish();
    int getValue();
};
