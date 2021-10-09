#pragma once
#include "CBookKaryagin.h"


class CBookStoreKaryagin
{
	vector<shared_ptr<CBookKaryagin>> listOfBooks;
public:
	CBookStoreKaryagin();
	void enterBook();
	~CBookStoreKaryagin();
	void outputBooksListOnDisplay();
	void enterBookFiction();
	void readBooksListFromFile();
	void writeBooksListInFile();
	void clearBooksList();
};

