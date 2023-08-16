#include <initializer_list>
#include <algorithm>
#include <iostream>

/* Ch 4.2 vector
 *
 */
class Vector {
public:
  Vector(int s)
    : elem{new double[s]},
    _size{s}
  {
    // not sure if should reserve size or nearest 2^i
    reserve(_size);
    // TODO why initialize as zero here and not as asdf[]{0} or something?
    for (int i=0; i!=s; ++i)
      elem[i]=0;
  }

  // need to ensure _capacity is reserve()'d before using
  /*
  Vector(std::initializer_list<double> lst)
    :elem{new double[lst.size()]},
    _size{static_cast<int>(lst.size())},
    // capacity must be allocated based on size anyways, so why is the resize impl in push_back? bad.
    // TODO
    _capacity{0}
  {
    std::copy(lst.begin(),lst.end(),elem);
  }
  */

  // ch 5.2.2
  Vector(const Vector& a);              // copy constructor
  Vector& operator=(const Vector& a);   // copy assignment
  Vector(Vector&& a);                   // move constructor
  // && is rvalue, no one else can assign to it, so we can steal its value
  // IMPORTANT: move is initiated when rvalue is used in either: constructor OR right hand side of an argument
  // stadard library move() doesn't move, it just uses rvalue and follows same mechanics, "like a cast"
  Vector& operator=(Vector&& a);        // move assignment


  // put reserve() logic back where it came from
  void push_back(double v) {
    if (_size == _capacity) {
      reserve(_capacity == 0 ? 8 : 2 * _capacity);
    }
  }

  int size() const {
    return _size;
  }
  int capacity() const {
    return _capacity;
  }

  void reserve(int newCapacity) {
    if (newCapacity > _capacity) {
      double* newElem = new double[newCapacity];
      // slice convention of adding an int to a begin to get the desired end
      std::copy(elem, elem + _size, newElem);
      delete[] elem;
      elem = newElem;
      _capacity = newCapacity;
    }
  }

  ~Vector() { delete[] elem; }

  double& operator[](int i);

  void print() const {
    std::cout << "[";
    for (int i = 0; i < _size; ++i) {
      std::cout << elem[i];
      if (i < _size  - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "]\n";
  }

private:
  double* elem;
  int _size;
  int _capacity;
};
