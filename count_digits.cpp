#include <iostream>
#include <cstdio>
using namespace std;

int* countDigitOccurence(string s,int* a){
    for(unsigned int i=0;i<s.length();i++){
        int numAtI = (int)s[i] - 48;
        //cout << numAtI << " ";
        a[numAtI]++;
    }
    return a;
}

int main()
{
    string s;
    int a[10];
    for(int i=0;i<10;i++){
        a[i] = 0;
    }
    cin >> s;
    int *b = countDigitOccurence(s,a);
    for(int i=0;i<10;i++){
        cout<<i << " " << *(b+i) <<"\n";
    }
}
/*
You are given a string S. Count the number of occurrences of all the digits in the string S.

Input: 
First line contains string S.

Output: 
For each digit starting from 
0
0 to 
9
9, print the count of their occurrences in the string 
S
S. So, print 
10
10 lines, each line containing 
2
2 space separated integers. First integer 
i
i and second integer count of occurrence of 
i
i. See sample output for clarification.

Constraints:
 1
=
|
S
|
=
100
*/
