#include "pch.h"
#include "CBookFictionKaryagin.h"
#include "CBookKaryagin.h"
#include <iostream>

IMPLEMENT_SERIAL(CBookFictionKaryagin, CBookKaryagin, 0)

CBookFictionKaryagin::CBookFictionKaryagin()
{
}

CBookFictionKaryagin::~CBookFictionKaryagin()
{
}

void CBookFictionKaryagin::newBook()
{
	CBookKaryagin::newBook();
	cout << "Enter the genre:" << endl;
	cin >> genre;
	cout << "Enter the number of pages:" << endl;
	cin >> pageCount;
}

void CBookFictionKaryagin::outputOnDisplay()
{
	CBookKaryagin::outputOnDisplay();
	cout << "Genre:   " << genre << endl
		<< "Number of pages:    " << endl;
}

void CBookFictionKaryagin::Serialize(CArchive& ar)
{
	CBookKaryagin::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << CString(genre.c_str());
		ar << pageCount;
	}
	else
	{
		CString stroka;
		ar >> stroka;
		genre = stroka;
		ar >> pageCount;
	}
}
