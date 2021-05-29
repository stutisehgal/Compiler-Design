#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	char a[10],b[50][10]={""},d[50][10]={""},ch;
	int i,n,c[10]={0},j,k,t,n1;
	cout<<"\nEnter the NON TERMINALS: ";
	cin>>a;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the number of productions for "<<a[i]<<": ";
		cin>>c[i];
	}
	t=0;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the productions for "<<a[i]<<": ";
		k=t;
		for(j=0;j<c[i];j++)
		{
			cout<<"\n"<<a[i]<<"->";
			do
			{
				cin>>b[k];
				k++;
			}while(k<j);
		}
		t=t+10;
	}
	t=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==b[t][0])
		{
			n1=strlen(b[t]);
			for(k=1;k<n1;k++)
			{
				d[t][k-1]=b[t][k];
			}
		}
		t=t+10;
	}
	t=0;
	cout<<"\n\nThe resulting productions after eliminating Left Recursion are : \n";
	for(i=0;i<n;i++)
	{
		if(a[i]==b[t][0])
		{
			for(j=1;j<c[i];j++)
			{
				cout<<"\n"<<a[i]<<"->"<<b[t+j]<<a[i]<<"'";
			}
		}
		t=t+10;
	}
	t=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==b[t][0])
			cout<<"\n"<<a[i]<<"' -> "<<d[t]<<a[i]<<"'|"<<((char)238);
		else
			for(j=0;j<c[i];j++)
				cout<<"\n"<<a[i]<<" -> "<<b[t+j];
		t=t+10;
	}
	return 0;
}
