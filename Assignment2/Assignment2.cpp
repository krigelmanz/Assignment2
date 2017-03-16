#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Tickets
{
	string issue;
	string cName;
	string note;
	int users;
	char replay;
	int ID;
	char status;
public:
	Tickets();
	Tickets(int c);
	void ShowTicket(int c);
	~Tickets();
	void CloseTicket(int a);
};
Tickets::Tickets()
{}
void Tickets::CloseTicket(int a)
{
	status = 'c';
	cout << endl << "Ticket " << a << " is closed" << endl;
}

Tickets::Tickets(int c)
{
	ID = c;
		cout << "Enter the caller's name:" << endl;
		getline(cin, cName, '\n');
		cout << "Server, application or access issue?" << endl;
		getline(cin, issue, '\n');
		cout << "Number of users affected?" << endl;
		cin >> users;
		cin.clear(); cin.ignore();
		cout << "Description of the issue?" << endl;
		getline(cin, note, '\n');
		status = 'O';
}
void Tickets::ShowTicket(int c)
{
	cout << endl << "Ticket Number " << c + 1 << ":" << endl;
	cout << "Caller: " << cName << endl;
	cout << "Issue Type: " << issue << endl;
	if (users < 10)
	{
		cout << "Priority Level: Low" << endl;
	}
	else if (users >= 10 && users < 50)
	{
		cout << "Priority Level: Medium" << endl;
	}
	else if (users >= 50)
	{
		cout << "Priority Level: High" << endl;
	}
	cout << "Number of users affected: " << users << endl;
	cout << "Description: " << note << endl;
	if (status == 'O')
	{
		cout << "Status: Open" << endl;
	}
	else
	{
		cout << "Status: Closed" << endl;
	}
}

Tickets::~Tickets()
{}
int main()
{
	const int MAXTICKETS = 100;
	char replay = 'Y';
	int i;

	Tickets myTicket[MAXTICKETS];

	for (i = 0, replay ='Y'; i < MAXTICKETS, replay == 'Y' || replay == 'y'; i++)
	{
			myTicket[i].Tickets::Tickets(i);
			cout << "Would you like to add another ticket? Enter Y or N" << endl;
			cin >> replay;
			cin.clear(); cin.ignore();
	}
	for (int j = 0; j < i; j++)
	{
		myTicket[j].Tickets::ShowTicket(j);
	}
	for (int j = 0; j < i; j++)
	{
		myTicket[j].Tickets::~Tickets();
	}
	myTicket[1].Tickets::CloseTicket(1);
	return 0;
}