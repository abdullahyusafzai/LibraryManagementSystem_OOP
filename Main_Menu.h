#pragma once
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
using namespace std;
namespace cs200
{
	class Main_Menu
	{
	public:
		Main_Menu();
		Main_Menu(string bookname, int bookno);
		void setbookname(string bookname);
		void setbookno(int bookno);
		string getbookname();
		int getbookno();
		void add_books();
		void remove_books();
		void issue_books();
		void main_menu();
		void show_book();
		void show_issue_books();
	private:
		int bookno;
		string bookname;
		string username, password;
		ofstream outfile, store_data_o;
		ifstream infile, store_data_i;
	};

	//class Books : public Main_Menu
	//{
	//public:
	//	Books();
	//	
	//private:
	//	int bookNo;
	//	string bookname;
	//};
}