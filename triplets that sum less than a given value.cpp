//I have used two pointer method which is of complexity O(N^2) whereas niave method is of O(N^3) complexity.
//corner case=> Array size should be >=3


#include<iostream> 
#include<algorithm>

using namespace std;

void find_triplet(int a[],int n,int sum)
{
	int i,count=0;
	
	//sorting the array first to decrease the complexity!
	sort(a,a+n);
		
	for(i=0;i<(n-2);i++)    //agar i=(n-2), then j=left=n-1 as well as right=n-1 and we want left<right always 
	{
		//initialising left and right pointers
		int right=n-1;  //right pointer is fixed!
		int left=i+1;   //left pointer 
	
		while(left<right)
		{
			if((a[i]+a[left]+a[right])<sum)
			{
				count++;
				cout<<"\n\n The triplet no. "<<count<<" is => ( "<<a[i]<<" "<<a[left]<<" "<<a[right]<<" )";
				break;
			}
			else if((a[i]+a[left]+a[right])>sum)
			{
				right--;
			}
			else  //((a[i]+left+right)==sum)
			{
				left++;
			}
		}
	}
	//after searching all possibilities
	if(count==0)
	{
		cout<<"\n\nNo such triplets exist in this array. Plz start with another array.";
	}
}

int main()
{
	int a[100],n,i,sum;
	cout<<"\t\t\nHow many elements do you want? => ";
	cin>>n;
	
	//corner case
	if(n>=3)
	{
		cout<<"\t\t\nEnter the sum => ";
		cin>>sum;
		cout<<"\t\nPlz start filling your elements one by one.";

		//Feeding the array!
		for(i=0;i<n;i++)
		{
			cout<<"\n\nElement no "<<i+1<<" ";
			cin>>a[i];
		}
		
		find_triplet(a,n,sum);
	}
	else
	{
		cout<<"\n\n\t\tWARNING!!  Array size should be greater than or equal to 3";
	}
return 0;	
}
