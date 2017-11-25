#include <iostream>
using namespace std;

long getMinNumToSortArray(long array[],int numberOfElements){
    int cumulativeArray[numberOfElements];
    cumulativeArray[0]  = 0;
    long result =0;
    for(int i=1;i<numberOfElements;i++){
        cumulativeArray[i] =0;	
        if(array[i] > array[i-1]){
            if(cumulativeArray[i-1] + array[i-1] >= array[i]){
                cumulativeArray[i] = cumulativeArray[i-1] + array[i-1] - array[i] + 1;
            }
        }else if(array[i] < array[i-1]){
            cumulativeArray[i] = cumulativeArray[i-1] + (array[i-1] - array[i]) + 1;
        }else{
            cumulativeArray[i] = cumulativeArray[i-1] + 1;
        }
        result += cumulativeArray[i];
    }
    
    return result;
}

int main() {
	// your code goes here
	int numberOfElements;
    cin >> numberOfElements;
    
        long *array = (long *) malloc( numberOfElements * sizeof(long));
        for(int inputCounter = 0; inputCounter < numberOfElements; inputCounter++){
            cin >> array[inputCounter];
        }
        cout << getMinNumToSortArray(array,numberOfElements);
}
