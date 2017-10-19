#include <iostream>
#include <stack>
int k; 
using namespace std;
int printReverseStack(stack<int>& gq){
        if(gq.empty()){
          return -1;  
        }else{
            int elem=gq.top();
            gq.pop();
            printReverseStack(gq);
            cout<<elem << " ";
            return -1;
        }
     /*   while(!gq.empty())
{
    int w = gq.top();
    std::cout << w << " ";
    gq.pop();
}*/
    }
void stackCheck(stack <int>& gq,int nextElem){
        while(!gq.empty() && k>0){
        int topElem = gq.top();
        if(topElem < nextElem){
             //cout << "topElem: " << topElem << "\n";
             gq.pop();
             k--;
        }else{
            break;
        }
        
        }
        
        gq.push(nextElem);
        //cout<< "pushed nextElem: " << gq.top() << "\n";
        //printReverseStack(gq);
    } 
    

int main()
{
    //cout << "Hello World!" << endl;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        stack <int> gq;
        int n;
        cin >> n >> k;
        int firstElem;
        cin>>firstElem;
        gq.push(firstElem);
        int nextElem;
        for(int j=1;j<n;j++){
            cin >> nextElem;
            //cout<< nextElem;
            stackCheck(gq,nextElem);
            //printReverseStack(gq);
        }
        printReverseStack(gq);
        cout<<endl;
        
    }
    
    
    
}
/*
After getting her PhD, Christie has become a celebrity at her university, and her facebook profile is full of friend requests. Being the nice girl she is, Christie has accepted all the requests.

Now Kuldeep is jealous of all the attention she is getting from other guys, so he asks her to delete some of the guys from her friend list.

To avoid a 'scene', Christie decides to remove some friends from her friend list, since she knows the popularity of each of the friend she has, she uses the following algorithm to delete a friend.

Algorithm Delete(Friend):
    DeleteFriend=false
    for i = 1 to Friend.length-1
         if (Friend[i].popularity < Friend[i+1].popularity)
            delete i th friend
            DeleteFriend=true
            break
    if(DeleteFriend == false)
        delete the last friend

Input: 
First line contains T number of test cases. First line of each test case contains N, the number of friends Christie currently has and K ,the number of friends Christie decides to delete. Next lines contains popularity of her friends separated by space.

Output: 
For each test case print N-K numbers which represent popularity of Christie friend's after deleting K friends.

Constraints
1<=T<=1000
1<=N<=100000
0<=K< N 
0<=popularity_of_friend<=100

NOTE:
Order of friends after deleting exactly K friends should be maintained as given in input.

SAMPLE INPUT 
3
3 1
3 100 1
5 2
19 12 3 4 17
5 3
23 45 11 77 18
SAMPLE OUTPUT 
100 1 
19 12 17 
77 18 

*/
