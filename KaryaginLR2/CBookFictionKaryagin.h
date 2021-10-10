#pragma once
#include "CBookKaryagin.h"



class CBookFictionKaryagin :
    public CBookKaryagin
{
    string genre;
    int pageCount;

public:
    DECLARE_SERIAL(CBookFictionKaryagin);

    CBookFictionKaryagin();
    ~CBookFictionKaryagin();

    void newBook() override;
    void outputOnDisplay() override;
    void Serialize(CArchive& ar) override;
};

