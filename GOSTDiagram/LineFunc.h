#pragma once
#include "AbstractFigure.h"
struct Points  // структура точек линии
{
    int x, y;
    Points *next;
};
 

// класс линии 
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

