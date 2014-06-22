#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    void compFactors(int n) {
      vector<int> factors;
      factors.push_back(1);
      helper(n, 2, factors);
    }
  
    void helper(int num, int start, vector<int> &factors) {
      factors.push_back(num);
      printFactors(factors);
      factors.pop_back();
      for(int i = start; i <= sqrt(num); ++i) {
        if(num % i == 0) {
          factors.push_back(i);
          helper(num/i, i, factors);
          factors.pop_back();
        }
      }
    }
  
    void printFactors(const vector<int> &factors) {
      for(int i = factors.size()-1; i >= 0; --i) {
        cout << factors[i];
        if(i > 0) cout << "*";
      }
      cout << endl;
    }
};

// To execute C++, please define "int main()"

int main() {
  Solution sol;
  sol.compFactors(1000);
  return 0;
}
