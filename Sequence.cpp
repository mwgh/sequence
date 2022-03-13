#include "Sequence.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

Sequence::Sequence() {
    maxSize = 2;
    currSize = 0;
    arr = new double[maxSize];
}

Sequence::Sequence(const Sequence& seq) {
    maxSize = seq.maxSize;
    currSize = seq.currSize;

    arr = new double[maxSize];
    for (int i = 0; i < maxSize; i++) {
        arr[i] = seq.arr[i];
    }
}

Sequence::~Sequence() {
    delete[] arr;
}

Sequence& Sequence::operator=(const Sequence& seq) {
    if (&seq == this) {
        return *this;
    }
    *this = Sequence(seq);
    return *this;
}

void Sequence::insert(double element) {
    if (currSize == maxSize) {
        maxSize *= 2;
        double* newArr = new double[maxSize];
        
        for (int i = 0; i < currSize; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    arr[currSize++] = element;
}

void Sequence::insert(double elements[], int size) {
    int newCurrSize = currSize + size;

    if (newCurrSize >= maxSize) {
        maxSize = newCurrSize;
        double* newArr = new double[maxSize];
        
        for (int i = 0; i < currSize; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    for (int i = currSize, j = 0; i < newCurrSize; i++, j++) {
        arr[i] = elements[j];
        currSize++;
    }
}

int Sequence::find(double element) {
    int count = 0;
    for (int i = 0; i < currSize; i++) {
        if (arr[i] == element) {
            count++;
        }
    }

    return count;
}

int Sequence::size() {
    return currSize;
}

double Sequence::sum() {
    double sum = 0;
    for (int i = 0; i < currSize; i++) {
        sum += arr[i];
    }
    return sum;
}

double Sequence::mean() {
    double mean = sum() / currSize;
    return mean;
}

double Sequence::median() {
    std::sort(arr, arr + currSize);
    int middle = (int) currSize / 2;

    if (currSize % 2 != 0) {
        return arr[middle];
    }
    return (arr[middle - 1] + arr[middle]) / 2;
}

double Sequence::stddev() {
    double average = mean();
    double sumDifferenceSquared = 0;

    for (int i = 0; i < currSize; i++) {
        sumDifferenceSquared += pow(arr[i] - average, 2);
    }

    return sqrt(sumDifferenceSquared / currSize);
}

Sequence Sequence::concatenate(const Sequence& seq) {
    insert(seq.arr, seq.currSize);
    return *this;
}

void Sequence::print() {
    std::cout << "Array: ";
    for (int i = 0; i < currSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
