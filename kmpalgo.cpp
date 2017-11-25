#include <iostream>
using namespace std;

void printArray(int *arr,int n){
     for(unsigned int i=0;i<n;i++){
           cout<< arr[i] + " ";
           }
}
int* genPrefixArray(string pattern){
     int len = pattern.length();
     int *prefixArray = (int *)malloc(len * sizeof(int));;
     prefixArray[0] = 0;
     int j=0;
     for(int i=1;i<len;i++){
             if(pattern[i] == pattern[j]){
                           prefixArray[i] = prefixArray[i-1] +1;
                           j++; 
                  }else{
                        prefixArray[i] =0;
                        j=0;
                        }
           }
           return prefixArray;
}

int main()
{
    string pattern;
    string orgString;
    cin >> pattern;
    cin >> orgString;
    int *prefixArray = genPrefixArray(pattern);
    printArray(prefixArray,pattern.length());
    return 0;
}
