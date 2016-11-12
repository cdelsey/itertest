#include <vector>
#include <iterator>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T> T pairwise_reduce(vector<T>& c);

int concatenate(int a, int b) { return a+b; }

template <class T> 
auto mid(T& c) -> decltype(begin(c)) {
  auto b = begin(c);
  advance(b, c.size()/2);
  return b;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    vector<int> cam(8);
    iota(begin(cam), end(cam), 0);
    for(auto i : cam)
        cout << i;
    cout << '\n';
    
    cout << pairwise_reduce(cam);
    return 0;
}

template <class T> T pairwise_reduce(vector<T>& c) {
  int length = c.size();
  if (length == 1)
    return c[0];
  else {
    int newsize = length/2;
    vector<T> output(newsize);
    transform(mid(c), end(c), begin(c), begin(output), concatenate);
    return pairwise_reduce(output);
  }
}

