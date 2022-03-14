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

     // Remove the element at the index
     void erase(int index);

     // Remove the elements starting at start_index and ending at end_index
     void erase(int start_index, int end_index);

     // Return the number of times the element appears in the sequence
     int count(double element);

     // Return the first index of the element, else return -1 if not found
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
