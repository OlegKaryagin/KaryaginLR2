#pragma once
#include "pch.h"
#include "CBookStoreKaryagin.h"
#include "CBookKaryagin.h"
#include "CBookFictionKaryagin.h"

using namespace std;

CBookStoreKaryagin::CBookStoreKaryagin()
{
}

void CBookStoreKaryagin::enterBook()
{
	CBookKaryagin* book = new CBookKaryagin;
	book->newBook();
	listOfBooks.push_back(book);
}


CBookStoreKaryagin::~CBookStoreKaryagin()
{
	for (CBookKaryagin* book : listOfBooks)
		delete book;
}

void CBookStoreKaryagin::outputBooksListOnDisplay()
{
	for (int i = 0; i < listOfBooks.size(); i++)
	{
		listOfBooks[i]->outputOnDisplay();
		cout << "--------------------" << endl;
	}
}

void CBookStoreKaryagin::enterBookFiction()
{
	CBookFictionKaryagin* book = new CBookFictionKaryagin;
	book->newBook();
	listOfBooks.push_back(book);
}

void CBookStoreKaryagin::readBooksListFromFile()
{
	string fileName;
	cout << "Please enter the file name:" << endl;
	cin >> fileName;
	fileName = fileName + ".dat";
	CFile f(CString(fileName.c_str()), CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	int sizeOfList;
	ar >> sizeOfList;
	for (int i = 0; i < sizeOfList; i++)
	{
		CBookKaryagin* o;
		ar >> o;
		listOfBooks.push_back(o);
	}
}

void CBookStoreKaryagin::writeBooksListInFile()
{
	string fileName;
	cout << "Please enter the file name:" << endl;
	cin >> fileName;
	fileName = fileName + ".dat";
	CFile f(CString(fileName.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);
	ar << listOfBooks.size();
	for (auto o : listOfBooks)
	{
		ar << o;
		delete o;
	}
	listOfBooks.clear();
}

void CBookStoreKaryagin::clearBooksList()
{
	for (int i = 0; i < listOfBooks.size(); i++)
		delete listOfBooks[i];
	listOfBooks.clear();
}