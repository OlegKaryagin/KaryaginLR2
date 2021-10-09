#include "pch.h"
#include "framework.h"
#include "CBookKaryagin.h"


IMPLEMENT_SERIAL(CBookKaryagin, CObject, 0)

CBookKaryagin::CBookKaryagin()
{
}

CBookKaryagin::~CBookKaryagin()
{
}

void CBookKaryagin::newBook()
{
	cout << "Enter the book title:" << endl;
	cin.ignore(10000, '\n');
	getline(cin, bookTitle);
	cout << "Enter the author of book" << endl;
	getline(cin, author);
	cout << "Enter the amount of books in stock:" << endl;
	cin >> amount;
	cout << "Enter price of book:" << endl;
	cin >> price;
}





void CBookKaryagin::outputOnDisplay()
{
	cout << "Title:  " + bookTitle << endl
		<< "Author:  " + author << endl
		<< "Amount of stock:  " << amount << endl
		<< "Book price  " << price << endl;
}



void CBookKaryagin::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << CString(bookTitle.c_str());
		ar << CString(author.c_str());
		ar << amount;
		ar << price;
	}
	else
	{
		CString stroka;
		ar >> stroka;
		bookTitle = stroka;
		ar >> stroka;
		author = stroka;
		ar >> amount;
		ar >> price;
	}
}
