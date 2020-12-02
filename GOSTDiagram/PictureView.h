#pragma once

#include "FigureModel.h"
#include "LineFunc.h"
#include "RectFunc.h"

void cleanScreen(System::Windows::Forms::PaintEventArgs^ e, int width, int height);
void drawFunctions(System::Windows::Forms::PaintEventArgs^ e, List^ head,bool);


void drawPath(System::Windows::Forms::PaintEventArgs^,LineFunc^, System::Drawing::Point);
void drawSelectedRect(System::Windows::Forms::PaintEventArgs^ ,Rect);
void drawVertex(System::Windows::Forms::PaintEventArgs^,System::Drawing::Point, System::Drawing::Color);
void repaintSelectedFunc(System::Windows::Forms::PaintEventArgs^, List^);

void drawText(System::Windows::Forms::PaintEventArgs^,RectFunc^);