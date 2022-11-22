#include<bits/stdc++.h>
using namespace std;

//If there exits a subset in the given array having sum equal to given sum then this function returns true.
bool isSubsetsum(int arr[],int n,int sum){
    bool dp[sum+1][n+1];
    //If sum is 0,then store true.
    for(int i=0;i<=n;i++){
        dp[0][i]=true;
    }

    //If n=0 but sum!=0 then store false.
    for(int i=1;i<=sum;i++){
        dp[i][0]=false;
    }

    //Filling the dp array.
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];  //Excluding last element
            if(i>=arr[j-1]){
                dp[i][j]=(dp[i][j]||dp[i-arr[j-1]][j-1]); //If last element is not greater than sum then we are considering both the possibilities i.e. either include the last element or exclude it.If any possibility returns true then store true in the array.
            }
         }
     }

     return dp[sum][n];    
}

 //This function returns true if arr[] can be partitioned in two subsets of equal sum.
bool partition(int arr[],int n){
    int sum=0;
    //calculate sum of the elements in array.
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    //If sum is odd,there cannot be two subsets with equal sum.
    if(sum%2!=0){
        return false;
    }

    //If sum is even,then call function isSubsetsum()
    return isSubsetsum(arr,n,sum/2);
}

 int main(){
    int arr[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    cout<<"{";
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    	if (i>0)
    		cout<<",";
    	cout<<arr[i];
    	
	}
	
    cout<<"}"<<endl;
    int n=sizeof(arr)/sizeof(arr[0]);
    if(partition(arr,n)){
        cout<<"Can be divided into two subsets of equal sum"<<endl;
    }else{
        cout<<"Can not be divided into two subsets of equal sum"<<endl;
    }

    return 0;
}
