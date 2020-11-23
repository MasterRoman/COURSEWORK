#pragma once
#include "AbstractFigure.h"
struct Points
{
    int x, y;
    Points *next;
};

ref class LineFunc :
    public AbstractFigure
{
public:
    int width;
    Points* headLine;
    LineFunc();
    ~LineFunc();
    void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) override;
};

