#include <iostream>
#include "Sequence.hpp"

using std::cout;
using std::endl;

void basic_test() {
    Sequence sq1;
    double numbers[] = {1.1, 2.2, 3.3};
    int n = 3;

    sq1.insert(3.14);
    sq1.print();
    sq1.insert(numbers, n);
    sq1.print();

    int pies = sq1.count(3.14);
    cout << "pies = " << pies << endl;
    int sq_size = sq1.size();
    cout << "sq_size = " << sq_size << endl;
    double sq_sum = sq1.sum();
    cout << "sq_sum = " << sq_sum << endl;
    double sq_mean = sq1.mean();
    cout << "sq_mean = " << sq_mean << endl;
    double sq_median = sq1.median();
    cout << "sq_median = " << sq_median << endl;
    double sq_stddev = sq1.stddev();
    cout << "sq_stddev = " << sq_stddev << endl;

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

void check_equality(const Sequence& sq1, const Sequence& sq2) {
    cout << "sq1 == sq2 ? " << (sq1 == sq2) << endl;
    cout << "sq1 != sq2 ? " << (sq1 != sq2) << endl;
}

void equality_test() {
    Sequence sq1;
    double numbers[] = {3.14, 1.1, 2.2, 3.3};
    int n = 4;

    sq1.insert(numbers, n);
    Sequence sq2 = sq1;
    sq1.print();
    sq2.print();

    check_equality(sq1, sq2);

    double num = 10.1;
    sq1.insert(num);
    cout << "inserted " << num << " into sq1" << endl;

    check_equality(sq1, sq2);

    cout << "sq2 == sq2 ? " << (sq2 == sq2) << endl;
    cout << "sq2 != sq2 ? " << (sq2 != sq2) << endl;

    cout << "end equality test" << endl;
}

void erase_test() {
    Sequence sq1;
    double numbers[] = {1.1, 2.2, 3.3};
    int n = 3;

    sq1.insert(numbers, n);
    sq1.print(); // 1.1 2.2 3.3
    sq1.erase(1);
    sq1.print(); // 1.1 3.3
    sq1.erase(1);
    sq1.print(); // 1.1
    sq1.erase(0);
    sq1.print();

    sq1.insert(10.1);
    sq1.erase(1);
    sq1.print();
    sq1.erase(0);
    sq1.print();
    sq1.erase(0);
    sq1.print();

    sq1.insert(numbers, n);
    sq1.print();
    int i = sq1.index_of(numbers[2]);
    if (i != -1) {
        sq1.erase(i);
        cout << "We erased the item with the index " << i
                << " from the sequence." << endl;
        sq1.print();
    }

    Sequence sq2;
    sq2.insert(numbers, n);
    sq2.insert(numbers, n);
    sq2.print();
    sq2.erase(1, 5);
    /* sq2.erase(5, 1); */
    sq2.print();
    sq2.erase(0, 0);
    sq2.print();

    cout << "end erase test" << endl;
}

int main() {
    basic_test();
    cout << endl;
    equality_test();
    cout << endl;
    erase_test();
}
