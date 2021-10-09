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
}

void CBookFictionKaryagin::outputOnDisplay()
{
	CBookKaryagin::outputOnDisplay();
	cout << "Genre:   " << genre << endl;
}

void CBookFictionKaryagin::Serialize(CArchive& ar)
{
	CBookKaryagin::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << CString(genre.c_str());
	}
	else
	{
		CString stroka;
		ar >> stroka;
		genre = stroka;
	}
}
