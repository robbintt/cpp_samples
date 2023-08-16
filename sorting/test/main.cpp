#include "tour_vector.cpp"
#include "functional"

int main()
{
  Vector a = Vector(0);
  a.print();
  a.push_back(2);
  a.print();
  a.push_back(3);
  a.print();
  // try with leading 0s
  Vector b = Vector(5);
  b.print();
  b.push_back(2);
  b.print();
  b.push_back(3);
  b.print();
  // test swap
  std::swap(b[5], b[0]);
  std::swap(b[6], b[1]);
  b.print();
  // disabled for now
  //Vector b = { 1,2,3,4 };
  return 0;
}
