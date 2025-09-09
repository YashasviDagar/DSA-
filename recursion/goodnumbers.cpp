//Question: Good numbers are those which have even numbs are even place and prime digit in odd place.. since digit are  0..9 so 5 even and 4 odd..
#include <iostream>
using namespace std;
#define MOD 1000000007
// for this case n is provided to give the length of the number. so with that use permutations and combinations to solve! 
long long modPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        //here if no odd power then how does res gives the correct answer? -> so after each iteration exp is divided and base is squared.. so at the end iteration of 0 the remainder will be 1 as every power of 2 in binary always has exactly one bit set (the lowest).So for positive exponents greater than 0, the binary representation always has at least one bit set to 1, so the if (exp % 2 == 1) condition will be true at some iteration. Thats the only reason!
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

int countGoodNumbers(long long n) {
    long long evenCount = (n + 1) / 2;
    long long oddCount = n / 2;
    long long res = modPow(5, evenCount) * modPow(4, oddCount);
    return res % MOD;
}

int main() {
    long long n;
    cin >> n;
    cout << countGoodNumbers(n) << endl;
    return 0;
}
