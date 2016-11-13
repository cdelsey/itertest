#include <vector>
#include <iterator>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T> T pairwise_reduce(vector<T>& c);
template <class T> T fold_in_half_reduce(vector<T>& c);

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
    
    cout << fold_in_half_reduce(cam) << '\n';
    return 0;
}

template <class T> T fold_in_half_reduce(vector<T>& c) {
  int length = c.size();
  if (length == 1)
    return c[0];
  else {
    int newsize = length/2;
    vector<T> output(newsize);
    transform(mid(c), end(c), begin(c), begin(output), concatenate);
    
    return fold_in_half_reduce(output);
  }
}

