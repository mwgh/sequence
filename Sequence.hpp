#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

class Sequence {
 private:
     double* arr;
     int maxSize;
     int currSize;

     bool in_bounds(int index);

 public:
     Sequence();
     Sequence(const Sequence& seq);
     ~Sequence();
     Sequence& operator=(const Sequence& seq);
     bool operator==(const Sequence& seq) const;
     bool operator!=(const Sequence& seq) const;

     void insert(double element);
     void insert(double elements[], int size);
     void erase(int index);
     void erase(int start_index, int end_index);
     int count(double element);
     int index_of(double element);
     int size();
     double sum();
     double mean();
     double median();
     double stddev();
     Sequence concatenate(const Sequence& seq);
     void print();
};

#endif  // SEQUENCE_HPP_
