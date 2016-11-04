#include "tree.hpp"
int account::bills_after_date(account list[],int n)
{	
	decltype(date.year) year_buf;
	decltype(date.month) month_buf;
	decltype(date.day) day_buf;
	
	cout<<"enter year between 1984 and 2016: ";
	cin>>year_buf;
	
	if(year_buf<1984 || year_buf>2016)
	{
		cout<<"wrong year"<<endl;
		return 0;
	}	
	
	cout<<"enter month from 1 to 12: ";
	cin>>month_buf;
	
	if(month_buf<1 || month_buf>12)
	{
		cout<<"wrong month"<<endl;
		return 0;
	}
	
	cout<<"enter day between 1 and 30: ";
	cin>>day_buf;
	
	if(day_buf<1 || day_buf>30)
	{
		cout<<"wrong day"<<endl;
		return 0;
	}
	
	cout<<"bills after "<<day_buf<<"."<<month_buf<<"."<<year_buf<<" : ";
	
	for(int i=0;i<n;i++)
	{
		if(year_buf<list[i].date.year)
		{
			cout<<list[i].account_number;
					cout<<" , ";
					
					continue;
		}
		if(year_buf==list[i].date.year)
		{
			if(month_buf<list[i].date.month)
			{
				cout<<list[i].account_number;
					cout<<" , ";
					
					continue;
			}
		}
		if(year_buf==list[i].date.year)
		{
			if(month_buf==list[i].date.month)
			{
				if(day_buf<list[i].date.day)
				{
					cout<<list[i].account_number;	
					cout<<" , ";
					
					continue;
				}
			}
		}
	}
	
	return 1;
}

void account::bills_of_one_person(account list[],int n,int k)
{
	if(b==false)
		{
			cout<<"Bills of person "<<surname<<" :"<<account_number<<" , ";
			b=true;
		}
	
	for(auto i=k+1;i<n;i++)
	{	
		if((!strcmp(surname,list[i].surname))&&(list[i].b==false))
		{
			cout<<list[i].account_number<<" , ";
			list[i].b=true;
		}	
		
	}
	cout<<endl;
}

int account::biggest_balance(account list[], int length)
{
	cout<<"How many people with the biggest balance to show?(less then "<<length+1<<"): ";
	int number;
	cin>>number;
	
	if(number>length)
	{ 
		return 0;
	}
	
	for(int current=0;current<length && current<number;current++)
	{
		float temp=list[0].balance;
	
		for(int search=current;search<length && search<number;search++)
		{
			if(list[current].balance<list[search].balance)
			{
				temp=list[current].balance;
				list[current].balance=list[search].balance;
				list[search].balance=temp;
			}		
		}
	}

	for(auto i=0;i<length && i<number;i++)
	{
		cout<<"person "<<list[i].surname<<" have balance : ";
		cout<<list[i].balance;
		cout<<endl;
	}

	return 1;
}

void account::show()
{
	cout<<"person's account number is: "<<account_number<<endl;
	cout<<"person's surname is: "<<surname<<endl;
	cout<<"date of open is: "<<date.day<<"."<<date.month<<"."<<date.year<<endl;
	cout<<"person's balance is: "<<balance<<endl;
	cout<<endl;
}

int account::set_surname()
{
	surname=new char[50];
	cout<<"enter surname: ";
	char buf[50];

	if(strlen(buf)<49)
	{
		cin>>buf;
		strcpy(surname,buf);

		return 1;
	}
	return 0;
}

int account::set_account_number()
{
	cout<<"enter person's account number: ";
	decltype(account_number) buf;
	cin>>buf;
	if(buf>0)
	{
		account_number=buf;
		return 1;
	}
	cout<<"account number must be > 0."<<endl;
	return 0;
}

int account::set_date()
{	
	decltype(date.year) year_buf;
	decltype(date.month) month_buf;
	decltype(date.day) day_buf;
	cout<<"enter year of opening between 1984 and 2016: ";
	cin>>year_buf;
	if(year_buf>1983 && year_buf<2017)
	{
		date.year=year_buf;
	}	
	else
	{
		cout<<"wrong year"<<endl;
		return 0;
	}
	cout<<"enter month from 1 to 12";
	cin>>month_buf;
	if(month_buf>0 && month_buf<13)
	{
		date.month=month_buf;
	}
	else
	{
		cout<<"wrong month"<<endl;
		return 0;
	}
	cout<<"enter day of opening from 1 to 30: ";
	cin>>day_buf;
	if(day_buf>0 && day_buf<31)
	{
		date.day=day_buf;
		return 1;
	}
	cout<<"wrong day"<<endl;
	return 0;
}

int account::set_balance()
{
	cout<<"enter : "<<surname<<"'s balance:";
	decltype(balance) bal_buf;
	cin>>bal_buf;
	if(bal_buf>0)
	{
		balance=bal_buf;
		cout<<endl;
		return 1;
	}
	cout<<"balance must be > 0."<<endl;
	return 0;
}