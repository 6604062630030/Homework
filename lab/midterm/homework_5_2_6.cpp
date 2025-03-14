// need help
// #include <iostream>
// #include <math.h>
// #include <vector>

// using namespace std;

// vector<int> print;

// int Multiply(string a, string b) {

//   // make same length
//   int lendif = a.length() - b.length();
//   int n = max(a.length(), b.length());
//   if (lendif > 0) {
//     for (int i = 0; i < lendif; i++) {
//       b = '0' + b;
//     }
//   }
//   else if (lendif < 0) {
//     for (int i = 0; i < abs(lendif); i++) {
//       a = '0' + a;
//     }
//   }

//   // cout << "a = " << a << " b = " << b << endl;

//   // base case
//   if (n == 1) return stoi(a) * stoi(b);

//   // divide
//   int mid = n / 2;
//   string xLeft = a.substr(0, mid); // a
//   string xRight = a.substr(mid, n - mid); // b
//   string yLeft = b.substr(0, mid); // c
//   string yRight = b.substr(mid, n - mid); // d

//   int ac = Multiply(xLeft, yLeft);
//   int ad = Multiply(xLeft, yRight);
//   int bc = Multiply(xRight, yLeft);
//   int bd = Multiply(xRight, yRight);

//   cout << ac << " " << bc << " " << ad << " " << bd << endl;
//   print.push_back(bd);
//   print.push_back(ad);
//   print.push_back(bc);
//   print.push_back(ac);

//   return ac * pow(10, n) + (ad + bc) * pow(10, n / 2) + bd;
// }

// int main() {
//   int a;
//   int b;
//   cin >> a >> b;

//   int result = Multiply(to_string(a), to_string(b));

//   int count = 0;
//   // for (int i = print.size() - 1; i >= 0; i--) {
//   //   cout << print[i];

//   //   if (count == 3) {
//   //     cout << endl;
//   //     count = 0;
//   //   }
//   //   else {
//   //     cout << " ";
//   //     count++;
//   //   }
//   // }
//   cout << result;

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int exp) {
  long long result = 1;
  while (exp--) {
    result *= base;
  }
  return result;
}

long long multiply(long long a, long long b) {
  if (a < 10) {
    return a * b;
  }

  int n = max(to_string(a).length(), to_string(b).length());
  int n2 = n / 2;

  long long a1 = a / power(10, n2);
  long long a2 = a % power(10, n2);
  long long b1 = b / power(10, n2);
  long long b2 = b % power(10, n2);

  long long D = multiply(a2, b2);
  long long B = multiply(a2, b1);
  long long C = multiply(a1, b2);
  long long A = multiply(a1, b1);

  cout << A << " " << B << " " << C << " " << D << endl;

  return A * power(10, 2 * n2) + (B + C) * power(10, n2) + D;
}

int main() {
  long long a, b;
  cin >> a >> b;

  cout << multiply(a, b) << endl;
  return 0;
}