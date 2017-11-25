#include <iostream>
using namespace std;

int calculateCountryCount(int *userResponseArray, int numOfPeople){
  int countryCount=0;
  int personIndex=0;
  while(personIndex < numOfPeople){
    if(userResponseArray[personIndex] == 1){
      countryCount+=1;
      personIndex++;
    } else{
      int noOfPeopleInCurrentCountry = userResponseArray[personIndex];
      for(int neighbourIndex=1;neighbourIndex<noOfPeopleInCurrentCountry;neighbourIndex++){
        if((personIndex+neighbourIndex>=numOfPeople) || (userResponseArray[personIndex+neighbourIndex] != noOfPeopleInCurrentCountry)){
          return -1;
        }
      }
      countryCount+=1;
      personIndex+=noOfPeopleInCurrentCountry;
    }
  }
  return countryCount;
}

int main() {
  int numOfTests;
  cin >> numOfTests;
  for(int testCounter=0; testCounter < numOfTests; testCounter++){
    int numOfPeople;
    cin >> numOfPeople;
    int userResponseArray[numOfPeople];
    for(int personCounter=0; personCounter < numOfPeople; personCounter++){
      cin >> userResponseArray[personCounter];
    }
    int countryCount = calculateCountryCount( userResponseArray, numOfPeople);
    if(countryCount == -1){
      cout << "Invalid Data" << endl;
    } else{
      cout << countryCount << endl;
    }
  }
  return 0;
}
