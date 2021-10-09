// KaryaginLR2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "KaryaginLR2.h"
#include "CBookKaryagin.h"
#include "CBookFictionKaryagin.h"
#include "CBookStoreKaryagin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

using namespace std;

void MainMenu()
{
    cout << "1. Add book in book list." << endl
        << "2. Print book list on display." << endl
        << "3. Load book list from file." << endl
        << "4. Save book list in file." << endl
        << "5. Clear book list." << endl
        << "6. Add fiction book in book list." << endl
        << "0. Exit." << endl
        << "Enter the code menu:" << endl;
}

int codeMenu()
{
    int code;
    while ((cin >> code).fail() || code < 0 || code>6)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input error!" << endl;
    }
    return code;
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
			CBookStoreKaryagin bookList;
			while (1)
			{
				MainMenu();
				switch (codeMenu())
				{
				case 1:
				{
					bookList.enterBook();
					break;
				}
				case 2:
				{
					bookList.outputBooksListOnDisplay();
					break;
				}
				case 3:
				{
					bookList.readBooksListFromFile();
					break;
				}
				case 4:
				{
					bookList.writeBooksListInFile();
					break;
				}
				case 5:
				{
					bookList.clearBooksList();
					break;
				}
				case 6:
				{
					bookList.enterBookFiction();
					break;
				}
				case 0:
				{
					return 0;
				}
				}
			}
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
