#pragma once
#pragma region MFC Serialization
#include "pch.h"
#include "framework.h"
#include <string>
#include <fstream>

using namespace std;

class CBookKaryagin : public CObject
{
	string bookTitle;
	string author;
	int amount = 0;
	int price = 0;

public:
	DECLARE_SERIAL(CBookKaryagin);

	CBookKaryagin();
	~CBookKaryagin();
	virtual void newBook();
	virtual void outputOnDisplay();
	virtual void Serialize(CArchive& ar);
};

