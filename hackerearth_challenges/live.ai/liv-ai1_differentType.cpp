#include<bits/stdc++.h>
#include <queue> 
#include <stack>
using namespace std;


//vector<vector<int> > queue_and_stack (vector<int> A) {
vector<vector<int> > queue_and_stack (vector<int> A){
   // Write your code here
   cout << "function start";
   int max = 0;
   for(int i=0;i<A.size();i++){
       if(A[i] > max){
           max = A[i];
       }
   }
   cout << max;
   
   vector<int> B(max+1);
   for(int i=2;i<max+1;i++){
   	B[i] = 0;
   }
   
   for(int i=2;i<max+1;i++){
   	
   	if(B[i] == 0){
   	int j=i;
   	for(int k=i*i;k<max+1;k=k*j){
   		B[k] = 1;
   		
   	}
   	
   		
   	}
   }
   
   std::stack<int> compositeStack;
   std::queue<int> primeQueue;
   for(int i=0;i<A.size();i++){
   	if(B[A[i]] == 0){
   		primeQueue.push(A[i]);
   	}else{
   		compositeStack.push(A[i]);
   	}
   }
   
   
   
   vector<vector<int> > matrix(2);
   matrix[0].resize(primeQueue.size());
   matrix[1].resize(compositeStack.size());
   for ( int i = 0 ; i <  primeQueue.size(); i++ ){
	matrix[0][i] = primeQueue.front();
	cout<< matrix[0][i] << " ";
	 primeQueue.pop();
	 
   }
   cout<<endl;
   for ( int i = 0 ; i <  compositeStack.size(); i++ ){
	matrix[1][i] = compositeStack.top();
	 compositeStack.pop();
	 cout << matrix[1][i] << " ";
   }
   cout<<endl;
    //vector<vector<int> > matrix(2);
   return matrix;
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

    vector<vector<int> > out_;
    cout << "test";
    //out_ = queue_and_stack(A);
    out_ = queue_and_stack(A);
      cout << "testNow";
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
