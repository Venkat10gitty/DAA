// find GCD of two numbers

#include <iostream>
using namespace std;

int main(){
    // find GCD of two numbers
    void findGCD(int a, int b);{
        int gcd = 1;
        for(int i = 1; i <= a && i <= b; i++){
            if(a % i == 0 && b % i == 0){
                gcd = i;
            }
        }
        cout << gcd << endl;
    }
    
}