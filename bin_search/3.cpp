// C++ file 1.cpp
#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[100100], brr[100100];


int
check(int x)
{
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += upper_bound(brr, brr + n, arr[i]) - brr;
	}

	return ans < k;
}

void
solve()
{

	cin>>n>>k;

	for(int i=0;i<n;i++)
	{
		cout<<"arr["<<i<<"]:"<<endl;
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"brr["<<i<<"]:"<<endl;
		cin>>brr[i];
	}

	sort(arr, arr + n);
	sort(brr, brr + n);

	int low = 0;
	int high = arr[n-1] + brr[n-1];
	int ans = -1;



	while(low<=high)
	{
		int mid = (low+high)/2;

		if(check(arr[mid]))
		{

		}
		else
		{

		}
	}
	cout<<"\n"<<ans<<endl;

}

signed
main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}

