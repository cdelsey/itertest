#ifndef ITERTEST_H
#define ITERTEST_H

template <class T>
class everyNthFunctor {
public:
  everyNthFunctor(int n, int offset=0) : interval(n), start(offset), current(0) {}
  bool operator() (T y) { 
    int x = (current-start)%interval;
    current++;
    if (x == 0)
      return true;
    else
      return false;
  }
private:
  int interval;
  int start;
  int current;
};

#endif        //  #ifndef ITERTEST_H
