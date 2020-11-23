#pragma once
#include "AbstractFigure.h"
ref class RectFunc : public AbstractFigure
{
public: 
	System::Drawing::Point leftCoords;
	System::Drawing::Point rightCoords;
	System::String^ text;
	RectFunc();
	RectFunc(System::Drawing::Point, System::Drawing::Point);
	~RectFunc();
	virtual void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) override = 0;
	
};

