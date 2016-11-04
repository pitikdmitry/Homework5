//Homework5 Var1
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include "tree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"How many people to add?: ";
	int n;
	cin>>n;

	account list[n];
	
	for(auto i=0;i<n;i++)
	{
		list[i];
		if(!list[i].set_surname())
		{
			exit(1);
		}
	}
	
	cout<<endl;
	
	for(int j=0;j<n;j++)
	{
		list[j].show();
	}
	
	for(auto k=0;k<n;k++)
	{
		list[k].bills_of_one_person(list, n, k);
	}
	cout<<endl;
	
	if(!list[0].bills_after_date(list,n))
	{
		exit(1);
	}
	cout<<endl;
	
	if(!list[0].biggest_balance(list, n))
	{
		exit(1);
	}
	cout<<endl;

//	if(!set_account_number())
//	{
//		exit(1);
//	}
//	if(!set_date())
//	{
//		exit(1);
//	}
//	if(!set_balance())
//	{
//		exit(1);
//	}
//	if(!get())
//	{
//		exit(1);
//	}	
	
	return 0;
}
