#include <iostream>
#include <cmath>
using namespace std;

long findGCD(long a,long b){
    if(b==0){
        return a;
    }else{
        long r = a%b;
        return findGCD(b,r);
    }
}

int main()
{
    long a;
    long b;
    cin >> a;
    cin >> b;
    
    if(b > a){
        long temp = b;
        b = a;
        a=temp;
    }
    
     long gcd = findGCD(a,b);
     //cout<< gcd;
     int result=0;
     for(long i=1;i<=sqrt(gcd);i++){
         if(gcd%i==0){
             if(gcd/i == i){
                 result+=1;
             }else{
                 result+=2;
             }
                 
             
         }
     }
     cout << result;
     return 0;
}
