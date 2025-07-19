#include <bits/stdc++.h>

using namespace std;
/* Bit Manipulation:
  number_to_be_shifted << times_to_shift (left shift - multiplication by 2)
  number_to_be_shifted >> times_to_shift (right shift - division by 2)
  & (bitwise AND)
  | (bitwise OR)
  ^ (bitwise XOR - odd 1s detector)
  ~ (bitwise NOT)
  (1 << x)  This is a number with the xth bit as 1.
  ~(1 << x) This is a number with xth bit 0 and all others 1.
  Ex:
  1 << 3 = 1000

  n & ~(1 << x) This clears xth bit 
  n | (1 << x) This sets xth bit
  n ^ (1 << x) This flips xth bit
*/

int clearBit(unsigned int num, int x){
  return num & ~(1 << x);
}

int setBit(unsigned int num, int x){
  return num | (1 << x);
}

int flipBit(unsigned int num, int x){
  return num ^ (1 << x);
}

int getBit(unsigned int num, int x){
  return (num >> x) & 1;
}

/* Clear the rightmost set bit 
  hint: n-1 flips bit till first set bit
  n   = 00110100
  n-1 = 00110011 & 
  ans = 00110000

  n & n-1
*/

/* Count set bits
  hint: keep turning off the rightmost set bit
*/

int countSetBits(int n){
  int count = 0;
  while(n){
    n = n & (n-1);
    count++;
  }
  return count;
}


int main(){
  int n = 42; // 101010
  cout << "Start: " << n << endl;

  // flip 2nd bit add 4 - 46 - 101110
  n = flipBit(n, 2);
  cout << n << endl;

  // clear 3rd bit sub 8 - 38 - 100110
  n = clearBit(n, 3);
  cout << n << endl;

  // set 0th bit add 1 - 39 - 100111
  n = setBit(n, 0);
  cout << n << endl;

  // get 6 bits
  for(int i=5; i>=0; i--){
    cout << getBit(n, i);
  }
  cout << endl;

  // count set bits
  cout << "Count Set Bits: " << countSetBits(n) << endl;

  return 0;
}