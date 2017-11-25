#include<bits/stdc++.h>
#include <queue> 
#include <stack>
using namespace std;

bool isPrime(int num){
      for (int i = 2; i*i <= num; ++i)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}
//vector<vector<int> > queue_and_stack (vector<int> A) {
void queue_and_stack (vector<int> A){
   // Write your code here
   //cout << "function start" << "\n";
    
   std::stack<int> compositeStack;
   std::queue<int> primeQueue;
   for(int i=0;i<A.size();i++){
   	//cout<< "A[i]: " << A[i] << " ";
   	if(isPrime(A[i])){
   	    primeQueue.push(A[i]);
   	}else{
   	    compositeStack.push(A[i]);
   	}
   }
   
   
   
   //vector<vector<int> > matrix(2);
   //matrix[0].resize(primeQueue.size());
   //matrix[1].resize(compositeStack.size());
   /*for ( int i = 0 ; i <=  primeQueue.size(); i++ ){
	matrix[0][i] = primeQueue.front();
	cout<< matrix[0][i] << " ";
	 primeQueue.pop();
	 
   }*/
   
   while (!primeQueue.empty())
  {
     std::cout << primeQueue.front() << " ";
      primeQueue.pop();
  }
  std::cout << '\n';
   while (!compositeStack.empty())
  {
     std::cout << compositeStack.top()<<" " ;
     compositeStack.pop();
  }
  std::cout << '\n';
   
   /*for ( int i = 0 ; i <=  compositeStack.size(); i++ ){
	matrix[1][i] = compositeStack.top();
	 compositeStack.pop();
	 cout << matrix[1][i] << " ";
   }*/
    //vector<vector<int> > matrix(2);
   //return matrix;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i_A=0; i_A<n; i_A++)
    {
    	cin >> A[i_A];
    }

    //vector<vector<int> > out_;
    //cout << "test";
    //out_ = queue_and_stack(A);
    queue_and_stack(A);
     // cout << "testNow";
    /*for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_][0];
    	for(int j_out_=1; j_out_<out_[i_out_].size(); j_out_++)
    	{
    		cout << " " << out_[i_out_][j_out_];
    	}
    	cout << "\n";
    }*/
}