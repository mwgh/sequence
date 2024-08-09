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
    if (this == &seq) {
        return *this;
    }
    *this = Sequence(seq);
    return *this;
}

bool Sequence::operator==(const Sequence& seq) const {
    if (this == &seq) {
        return true;
    }
    for (int i = 0; i < std::max(currSize, seq.currSize); i++) {
        if (arr[i] != seq.arr[i]) {
            return false;
        }
    }
    return true;
}

bool Sequence::operator!=(const Sequence& seq) const {
    return !(*this == seq);
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
    }
    currSize = newCurrSize;
}

bool Sequence::in_bounds(int index) {
    if (index < 0 || index >= currSize) {
        return false;
    }
    return true;
}

void Sequence::erase(int index) {
    if (!in_bounds(index)) {
        std::cerr << "We cannot erase the item because the index " << index
                << " is out of bounds." << std::endl;
        return;
    }
    for (int i = index; i < currSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    currSize--;

    arr[currSize] = 0;
}

void Sequence::erase(int start_index, int end_index) {
    if (start_index == end_index) {
        erase(start_index);
        return;
    } else if (end_index < start_index) {
        std::cerr << "The end index should be greater than or equal to the "
                << "start index." << std::endl;
        return;
    } else if (!in_bounds(start_index) || !in_bounds(end_index - 1)) {
        std::cerr << "We cannot erase the item because the start index "
                << start_index << " or the (end index - 1) = "
                << (end_index - 1) << " is out of bounds." << std::endl;
        return;
    }
    for (int i = start_index; i < end_index - 1; i++) {
        arr[i] = arr[i + 1];
    }
    currSize -= end_index - start_index;

    for (int i = currSize; i < maxSize; i++) {
        arr[i] = 0;
    }
}

int Sequence::count(double element) {
    int count = 0;
    for (int i = 0; i < currSize; i++) {
        if (arr[i] == element) {
            count++;
        }
    }

    return count;
}

int Sequence::index_of(double element) {
    for (int i = 0; i < currSize; i++) {
        if (arr[i] == element) {
            return i;
        }
    }

    return -1;
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
    int middle = currSize / 2;

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
