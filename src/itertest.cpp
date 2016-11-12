#include <vector>
#include <iterator>
#include <numeric>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    vector<int> cam(8);
    iota(begin(cam), end(cam), 0);
    for(auto i : cam)
        cout << i;
    cout << '\n';
    return 0;
}