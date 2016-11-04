#ifndef _TREE_HPP_
#define _TREE_HPP_
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>

using namespace std;
struct date_open
{
	int year;
	int month;
	int day;
};

class account
{
	private:
		int account_number;
		char *surname;
		date_open date;
		float balance;
		bool b;
	public:
		account()
		{
			account_number=rand()%500+1;
			surname=nullptr;
			date.year=rand()%32+1985;
			date.month=rand()%12+1;
			date.day=rand()%30+1;
			balance=rand()%10000+1;
			bool b=false;
		}
		int bills_after_date(account list[],int n);
		void bills_of_one_person(account list[], int n,int k);
		int biggest_balance(account list[], int length);
		void show();
		int set_surname();
		~account()
		{
			delete[] surname;
		}
		
		//this methods work, but i dont use them
		int set_account_number();
		int set_date();
		int set_balance();
};

#endif