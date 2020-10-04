#include<bits/stdc++.h>
using namespace std;
  
// Driver program 
int randomfoo(int arr[])
{
	// This program will create same sequence of  
    // random numbers on every program run 
	int x=rand();
	if(arr[x]==0)
	{
		arr[x]=1;
		return x;
	}
	else
		randomfoo(arr);
}
int main(void) 
{ 
     
  	int arr[1000+1];
  	for(int i=0; i<1000+1; i++)
  		arr[i]=0;
    int ans=randomfoo(arr);
    cout<<ans<<" ";
} 
