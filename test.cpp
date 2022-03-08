#include "Sequence.hpp"
#include <iostream>

using std::cout;
using std::endl;

void basicTest()
{
    Sequence sq1;
    double numbers[] = { 1.1,2.2,3.3 };
    int n = 3;
 
    sq1.insert(3.14);
    sq1.print();
    sq1.insert(numbers, n);
    sq1.print();
 
    int pies = sq1.find(3.14);
    cout << "pies = " << pies << endl;
    int sqSize = sq1.size();
    cout << "sqSize = " << sqSize << endl;
    double sqSum = sq1.sum();
    cout << "sqSum = " << sqSum << endl;
    double sqMean = sq1.mean();
    cout << "sqMean = " << sqMean << endl;
    double sqMedian = sq1.median();
    cout << "sqMedian = " << sqMedian << endl;
    double sqStddev = sq1.stddev();
    cout << "sqStddev = " << sqStddev << endl;
 
    Sequence sq2(sq1);
    Sequence sq3 = sq2.concatenate(sq1);
    sq2.insert(100);
    sq1.print();
    sq2.print();
    sq3.print();

    Sequence sq4 = sq1;
    sq1.insert(10.1);
    sq1.print();
    sq4.print();
 
    cout << "end basic test" << endl;
}

int main() {
    basicTest();
}
