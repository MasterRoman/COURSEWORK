#pragma once
#include "RectFunc.h"

ref class ProcessFunc : RectFunc
{
public:
	ProcessFunc();
	ProcessFunc(System::Drawing::Point points);
	~ProcessFunc();
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e,bool isVertex) override;
private:

};



ref class DecissionFunc : RectFunc
{
public:
	DecissionFunc();
	DecissionFunc(System::Drawing::Point);
	~DecissionFunc();
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) override;
private:

};



ref class TerminatorFunc : RectFunc
{
public:
	TerminatorFunc();
	TerminatorFunc(System::Drawing::Point);
	~TerminatorFunc();
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) override;
private:

};



ref class DataFunc : RectFunc
{
public:
	DataFunc();
	DataFunc(System::Drawing::Point);
	~DataFunc();
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) override;
private:

};


ref class PageRefFunc : RectFunc
{
public:
	PageRefFunc();
	PageRefFunc(System::Drawing::Point);
	~PageRefFunc();
	void drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) override;
private:

};


