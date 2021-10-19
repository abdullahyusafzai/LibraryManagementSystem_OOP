#include"Main_Menu.h"
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
//globally declaration of variables
string choice;
namespace cs200
{
	Main_Menu::Main_Menu() : Main_Menu("", 0)
	{}
	Main_Menu::Main_Menu(string bookname, int bookno) : bookname(bookname), bookno(bookno)
	{}
	void Main_Menu::setbookname(string bookname)
	{
		this->bookname = bookname;
	}
	void Main_Menu::setbookno(int bookno)
	{
		this->bookno = bookno;
	}
	string Main_Menu::getbookname()
	{
		return this->bookname;
	}
	int Main_Menu::getbookno()
	{
		return this->bookno;
	}
	void Main_Menu::issue_books()
	{
		store_data_o.open("issue.txt", ios::out);
		string choice;
		string name, lstname;
		do
		{
			cout << "Enter book No: ";
			cin >> bookno;
			cout << "Enter Student First name: ";
			cin >> name;
			cout << "Enter Student Last name:";
			cin >> lstname;
			cout << "Add more data yes or no: ";
			cin >> choice;
			store_data_o << bookno <<" "<< name<< "," << lstname << endl;
		} while (choice=="yes" || choice=="YES");
		cout << "Do you want to go to main menu yes or no: ";
		cin >> choice;
		if (choice == "yes" || choice == "YES")
		{
			main_menu();
		}
		else
		{
			exit(0);
		}
	}
	void Main_Menu::show_issue_books()
	{
		string name, lstname;
		store_data_i.open("issue.txt", ios::in);
		while (!store_data_i.eof())
		{
			store_data_i >> bookno >> name >> lstname;
			cout << "Data of issued Book to this person" << endl;
			cout << "Book Number: " << bookno << endl;
			cout << "Name: " << name << " " << lstname << endl;

		}
		store_data_i.close();
	}
	void Main_Menu::remove_books()
	{
		outfile.open("data.txt", ios::trunc);
		infile.close();
		cout << "Your All data has been removed" << endl;
		cout << "Do you want to go to main menu yes or no: ";
		cin >> choice;
		if (choice == "YES" || choice == "yes")
		{
			main_menu();
		}
		else
		{
			exit(0);
		}

	}
	void Main_Menu::add_books()
	{
		outfile.open("data.txt", ios::out);
		string abc;
		do {
			cout << "Enter book no: ";
			cin >> bookno;
			cout << "Enter Name of the Book: ";
			cin >> bookname;
			cout << "Do you want to continue yes or no: ";
			cin >> abc;
			outfile << bookno << bookname << endl;

		} while (abc == "yes" || abc == "YES");
		cout << "Do you want to go to the main menu 'yes' or 'no' : ";
		cin >> abc;
		if (abc == "yes" || abc == "YES")
		{
			main_menu();
		}
		else
		{
			exit(0);
		}
		outfile.close();

	}
	void Main_Menu::show_book()
	{
		infile.open("data.txt", ios::in);
		cout << "Details of stored books" << endl;
		
		while (!infile.eof())
		{
			infile >> bookno >> bookname;
			cout << endl << endl;
			cout << "Book ID: " << bookno << endl;
			cout << "Book Name:" << bookname << endl;
		}
		cout << "Do you want main menu yes or no : ";
		cin >> choice;
		if (choice == "YES" || choice == "yes")
		{
			main_menu();
		}
		else
		{
			exit(0);
		}
		infile.close();
	}
	void Main_Menu::main_menu()
	{
		int select;
		cout << endl << endl;
		cout << " MAIN MENU" << endl;
		cout << "Select from the following options:" << endl;
		cout << "1 . Add Books" << endl;
		cout << "2 . Remove Books" << endl;
		cout << "3 . Show Books" << endl;
		cout << "4 . Issue Books" << endl;
		cout << "5 . Show Issue Books" << endl;
		cout << "6. Exit" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			add_books();
			break;
		case 2:
			remove_books();
			break;
		case 3:
			show_book();
			break;
		case 4:
			issue_books();
			break;
		case 5:
			show_issue_books();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "\n";
			break;
		}
	}

}