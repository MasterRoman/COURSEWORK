#pragma once

#include "DataTypes.h"

// Абстрактный базовый класс 

ref class AbstractFigure {
 
public:
    virtual void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) = 0;
    FunctionType type;
    AbstractFigure();
    virtual ~AbstractFigure();
};

