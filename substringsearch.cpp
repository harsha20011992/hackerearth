#include <iostream>
using namespace std;
int count =0;
void printArray(int *arr,unsigned int n){
    //cout << "n" << n; 
     for(unsigned int i=0;i<n;i++){
           cout<< arr[i] << " ";
           }
}
int* genPrefixArray(string pattern){
     int len = pattern.length();
     //cout << len; 
     int *prefixArray = (int *)malloc(len * sizeof(int));;
     prefixArray[0] = 0;
     int j=0;
     for(int i=1;i<len;i++){
             if(pattern[i] == pattern[j]){
                           prefixArray[i] = prefixArray[i-1] +1;
                           //cout << "prefixArray[" << i << "]: " << prefixArray[i];
                           j++; 
                  }else{
                        prefixArray[i] =0;
                    //    cout << "prefixArray[" << i << "]: " << prefixArray[i];
                        j=0;
                        }
           }
           //printArray(prefixArray,len);
           return prefixArray;
}
unsigned int getPatternCount(string orgString,string pattern,int *prefixArray){
    //unsigned int len = orgString.length();
    //unsigned int patternLen = pattern.length()-1;
    int j=0;
    //unsigned int countLen = 0;
    for(unsigned int i =0;i<orgString.length();i++){
        if(orgString[i] == pattern[j]){
            //cout << "j: " << j;
            if(j == pattern.length()-1){
                count = count +1;
                j= prefixArray[j];
            }else{
                j++;
            }
        }else{
            if(j-1<0){
                j=0;
                
            }else{
                j = prefixArray[j-1];
            }
            if(orgString[i] == pattern[j]){
                j++;
            }
        }
    }
    return count;
}

int main()
{
    string pattern;
    string orgString;
    cin >> pattern;
    cin >> orgString;
    //cout << "Test";
    int *prefixArray = genPrefixArray(pattern);
    cout << getPatternCount(orgString,pattern,prefixArray);
    
    //printArray(prefixArray,pattern.length());
    return 0;
}
