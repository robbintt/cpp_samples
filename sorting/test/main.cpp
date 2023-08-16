#include "tour_vector.cpp"

int main()
{
  Vector a = Vector(5);
  a.print();
  a.push_back(2);
  a.print();
  a.push_back(3);
  a.print();
  // disabled for now
  //Vector b = { 1,2,3,4 };
  return 0;
}
