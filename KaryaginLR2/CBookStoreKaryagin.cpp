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
	auto book = make_shared<CBookKaryagin>();
	listOfBooks.push_back(book);
}


CBookStoreKaryagin::~CBookStoreKaryagin()
{
	clearBooksList();
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
	auto book = make_shared<CBookKaryagin>();
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
		shared_ptr<CBookKaryagin> lp(o);
		listOfBooks.push_back(lp);
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
	for (auto& pObj : listOfBooks)
	{
		CBookKaryagin* p = pObj.get();
		ar << p;
	}
	listOfBooks.clear();
}

void CBookStoreKaryagin::clearBooksList()
{
	listOfBooks.clear();
}