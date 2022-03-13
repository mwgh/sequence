#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

class Sequence {
 private:
     double* arr;
     int maxSize;
     int currSize;

 public:
     Sequence();
     Sequence(const Sequence& seq);
     ~Sequence();
     Sequence& operator=(const Sequence& seq);
     bool operator==(const Sequence& seq) const;
     bool operator!=(const Sequence& seq) const;

     void insert(double element);
     void insert(double elements[], int size);
     int find(double element);
     int size();
     double sum();
     double mean();
     double median();
     double stddev();
     Sequence concatenate(const Sequence& seq);
     void print();
};

#endif  // SEQUENCE_HPP_
