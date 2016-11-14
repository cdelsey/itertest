#include <vector>
#include <iterator>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <boost/iterator/filter_iterator.hpp>
#include <boost/range/adaptor/strided.hpp>
#include <boost/range/adaptor/sliced.hpp>
#include <boost/range/algorithm/transform.hpp>
#include "itertest.h"

using namespace std;

template <class T> T pairwise_reduce(vector<T>& c);
template <class T> T fold_in_half_reduce(vector<T>& c);
template <class T> T filter_pairwise_reduce(vector<T>& c);
template <class T> T strided_pairwise_reduce(vector<T>& c);
template <class T> T strided_std_pairwise_reduce(vector<T>& c);

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
    
    cout << "Fold in half\t\t" << fold_in_half_reduce(cam) << '\n';
    cout << "Filtered\t\t" << filter_pairwise_reduce(cam) << '\n';
    cout << "Strided\t\t" << strided_pairwise_reduce(cam) << '\n';
    cout << "Strided:std\t\t" << strided_std_pairwise_reduce(cam) << '\n';
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

template <class T> T filter_pairwise_reduce(vector<T>& c) {
  int length = c.size();
  if (length == 1)
    return c[0];
  else {
    int newsize = length/2;
    vector<T> output(newsize);
    everyNthFunctor<T> evens(2);
    everyNthFunctor<T> odds(2, 1);
    transform(boost::make_filter_iterator(evens, begin(c), end(c)), boost::make_filter_iterator(evens, end(c), end(c)), boost::make_filter_iterator(odds, begin(c), end(c)), begin(output), concatenate);
    
    return filter_pairwise_reduce(output);
  }
}

template <class T> T strided_pairwise_reduce(vector<T>& c) {
  int length = c.size();
  if (length == 1)
    return c[0];
  else {
    int newsize = length/2;
    vector<T> output(newsize);
    boost::transform(c | boost::adaptors::strided(2), c | boost::adaptors::sliced(1, length) | boost::adaptors::strided(2), begin(output), concatenate);
    
    return strided_pairwise_reduce(output);
  }
}

template <class T> T strided_std_pairwise_reduce(vector<T>& c) {
  int length = c.size();
  if (length == 1)
    return c[0];
  else {
    int newsize = length/2;
    vector<T> output(newsize);
    auto evens = c | boost::adaptors::strided(2);
    auto odds = c | boost::adaptors::sliced(1, length) | boost::adaptors::strided(2);
    transform(begin(evens), end(evens), begin(odds), begin(output), concatenate);
    
    return strided_pairwise_reduce(output);
  }
}

