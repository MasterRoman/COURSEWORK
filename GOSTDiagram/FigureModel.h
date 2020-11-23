#pragma once
#include "AbstractFigure.h"
#include "DataTypes.h"
#include "LineFunc.h"


ref struct List
{
	AbstractFigure^ fig;
	List^ next;
};



List^ initList(List^);
void cleanList(List^);

List^ push(List^, FunctionType, System::Drawing::Point);
void pushExistingFunc(List^, AbstractFigure^);

void deleteElement(List^, List^);

List^ addLine(List^, System::Drawing::Point);
Points* addPoints(LineFunc^, System::Drawing::Point);


AbstractFigure^ figureFromType(FunctionType fType, System::Drawing::Point points);


//define selected Figure
List^ hitTest(List^ head, System::Drawing::Point points);

void getSelectedFuncFromRect(List^, List^, Rect);

int max(int, int);
int min(int, int);
void swap(int& first, int& second);