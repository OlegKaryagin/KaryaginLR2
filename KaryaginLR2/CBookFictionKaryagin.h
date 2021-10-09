#pragma once
#include "CBookKaryagin.h"



class CBookFictionKaryagin :
    public CBookKaryagin
{
    string genre;

public:
    DECLARE_SERIAL(CBookFictionKaryagin);

    CBookFictionKaryagin();
    ~CBookFictionKaryagin();

    void newBook() override;
    void outputOnDisplay() override;
    void Serialize(CArchive& ar) override;
};

