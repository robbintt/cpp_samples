#include <initializer_list>
#include <algorithm>

/* Ch 4.2 vector
 *
 */
class Vector {
public:
  Vector(int s)
    : elem{new double[s]},
    sz{s}
  {
    for (int i=0; i!=s; ++i)
      elem[i]=0;
  }

  Vector(std::initializer_list<double> lst)
    :elem{new double[lst.size()]},
    sz{static_cast<int>(lst.size())}
  {
    std::copy(lst.begin(),lst.end(),elem);
  }

  // ch 5.2.2
  Vector(const Vector& a);              // copy constructor
  Vector& operator=(const Vector& a);   // copy assignment

  Vector(Vector&& a);                   // move constructor
  // && is rvalue, no one else can assign to it, so we can steal its value
  // IMPORTANT: move is initiated when rvalue is used in either: constructor OR right hand side of an argument
  // stadard library move() doesn't move, it just uses rvalue and follows same mechanics, "like a cast"
  Vector& operator=(Vector&& a);        // move assignment


  void push_back(double);


  ~Vector() { delete[] elem; }

  double& operator[](int i);
  int size() const;
private:
  double* elem;
  int sz;
};

/** Ch 10 Vector Template
 */
/*
template<typename T>
class Vector {
  T* elem;
  T* space;
  T* last;
public:
  int size();
  int capacity();

  void reserve(int newsz);

  void push_back(const T& t);
  void push_back(T&& t);
}

// why does he include this again
template<typename T>
void vector<t>::push_back(const t& t)
{
  if (capacity()<size()+1)
    reserve(size()==0?8:2*size());
  new(space) T{t};
  ++space;
}
*/
