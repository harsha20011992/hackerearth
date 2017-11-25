#include <iostream>
using namespace std;

int main() {
	int noOfTests;
	cin >> noOfTests;
	for(int testCounter = 0; testCounter < noOfTests; testCounter++){
	    int noOfInputs;
	    cin >> noOfInputs;
	    int countryCount = 0;
	    int noOfMembersFromCurrentCountry;
	    int inputCounter = 0;
	    int noOfMembersToBeVerified=0;
	    while(inputCounter < noOfInputs){
	        cin >> noOfMembersFromCurrentCountry;
	        inputCounter++;
	        countryCount++;
	        noOfMembersToBeVerified = noOfMembersFromCurrentCountry - 1;
	        while(inputCounter < noOfInputs && noOfMembersToBeVerified > 0){
	            
	            int noOfMembersFromCurrentUserCountry;
	            cin >> noOfMembersFromCurrentUserCountry;
	            inputCounter++;
	            noOfMembersToBeVerified -- ;
	            
	            if(noOfMembersFromCurrentUserCountry != noOfMembersFromCurrentCountry){
	                noOfMembersToBeVerified ++;
	               //loop to end
	               while(inputCounter < noOfInputs){
	                   cin >> noOfMembersFromCurrentUserCountry;
	                   inputCounter++;
	               }
	            }
	        }
	    }
	    if(noOfMembersToBeVerified > 0){
	        cout<<"Invalid Data"<<endl;
	    } else {
	        cout << countryCount << endl;
	    }
	}
	return 0;
}
