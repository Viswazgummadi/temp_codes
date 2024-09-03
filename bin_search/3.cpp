// C++ file 1.cpp
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[100100];


int
check(int val)
{
	return val>=arr[0]?1:0;
}

void
solve()
{

	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"arr["<<i<<"]:"<<endl;
		cin>>arr[i];
	}

	int low = 0;
	int high = n-1;
	int ans = 0;


	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<check(arr[i])<<endl;
	}

}

signed
main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}

