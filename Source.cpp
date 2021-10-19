#include"Main_Menu.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
using namespace cs200;

int main()
{
	string choice;
	string username, password;
	Main_Menu m_menu;
	cout << "********************LMS********************" << endl;
	cout << "           Library Management System         " << endl;
	cout << "        Made By: Abdullah " << endl << endl;
	string userName;
	string userPassword;
	int loginAttempt = 0;
	while (loginAttempt < 5)
	{
		cout << "Please enter your user name: ";
		cin >> userName;
		cout << "Please enter your user password: ";
		cin >> userPassword;

		if (userName == "user" && userPassword == "user")
		{
			cout << endl;
			cout << "Welcome to Main Menu" << endl;
			m_menu.main_menu();
			break;
		}
		else if (userName == "abd" && userPassword == "1998")
		{
			cout << "Welcome Abdullah!\n";
			m_menu.main_menu();
			break;
		}
		else
		{
			cout << "Invalid login attempt. Please try again.\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 5)
	{
		cout << "Too many login attempts! The program will now terminate.";
		return 0;
	}
	_getch();
	return 0;
}
