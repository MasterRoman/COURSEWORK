#include "RectFunctions.h"
#include "DataTypes.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "PictureView.h"

ProcessFunc::ProcessFunc() {

}

ProcessFunc::ProcessFunc(System::Drawing::Point points)
{
	this->leftCoords.X = points.X - 44;
	this->leftCoords.Y = points.Y - 24;
	this->rightCoords.X = points.X + 44;
	this->rightCoords.Y = points.Y + 24;
	this->type = PROCESS;
}

ProcessFunc::~ProcessFunc()
{
}

void ProcessFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e,bool isVertex) {
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = 2.0f;

	e->Graphics->DrawRectangle(pen, this->leftCoords.X, this->leftCoords.Y,88,48);

	if (isVertex) {
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
	}
	delete pen;

}

DecissionFunc::DecissionFunc()
{
}

DecissionFunc::DecissionFunc(System::Drawing::Point points)
{
	//
	this->leftCoords.X = points.X - 44;
	this->leftCoords.Y = points.Y - 24;
	this->rightCoords.X = points.X + 44;
	this->rightCoords.Y = points.Y + 24;
	this->type = DECISSION;
}

DecissionFunc::~DecissionFunc()
{
}

void DecissionFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) {

	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = 2.0f;
	array<System::Drawing::Point>^ poligonPoints = gcnew array<System::Drawing::Point>{
		System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y + 24),
		System::Drawing::Point(this->leftCoords.X + 44, (int)this->leftCoords.Y), 
		System::Drawing::Point(this->rightCoords.X, (int)this->leftCoords.Y + 24),
		System::Drawing::Point(this->rightCoords.X - 44, (int)this->rightCoords.Y)};
	e->Graphics->DrawPolygon(pen,poligonPoints);
	
	if (isVertex) {
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
	}
	delete pen;
	delete poligonPoints;

}

TerminatorFunc::TerminatorFunc()
{
}

TerminatorFunc::TerminatorFunc(System::Drawing::Point points)
{
	//
	this->leftCoords.X = points.X - 44;
	this->leftCoords.Y = points.Y - 16;
	this->rightCoords.X = points.X + 44;
	this->rightCoords.Y = points.Y + 16;
	this->type = TERMINATOR;
}


TerminatorFunc::~TerminatorFunc()
{
}

void TerminatorFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) {
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = 2.0f;

	e->Graphics->DrawArc(pen, this->leftCoords.X, this->leftCoords.Y,30,32, 90, 180);
	e->Graphics->DrawLine(pen, this->leftCoords.X+16, this->leftCoords.Y+1, this->leftCoords.X + 72, this->leftCoords.Y);
	e->Graphics->DrawArc(pen, this->rightCoords.X-32, this->leftCoords.Y, 30, 32,90,-180);
	e->Graphics->DrawLine(pen, this->leftCoords.X+16, this->rightCoords.Y, this->leftCoords.X + 72, this->rightCoords.Y);
	
	if (isVertex) {
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
	}
	delete pen;
	
}

DataFunc::DataFunc()
{
}


DataFunc::DataFunc(System::Drawing::Point points)
{
	//
	this->leftCoords.X = points.X - 29;
	this->leftCoords.Y = points.Y - 24;
	this->rightCoords.X = points.X + 59;
	this->rightCoords.Y = points.Y + 24;
	this->type = DATA;
}

DataFunc::~DataFunc()
{
}

void DataFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) {
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = 2.0f;
	array<System::Drawing::Point>^ poligonPoints = gcnew array<System::Drawing::Point>{
			System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y),
			System::Drawing::Point(this->rightCoords.X,this->leftCoords.Y),
			System::Drawing::Point(this->rightCoords.X - 29, this->rightCoords.Y),
			System::Drawing::Point(this->leftCoords.X - 29, this->rightCoords.Y)};
	e->Graphics->DrawPolygon(pen, poligonPoints);

	if (isVertex) {
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X - 29, this->rightCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->leftCoords.X - 29, this->rightCoords.Y), System::Drawing::Color::Black);
	}
	delete pen;
	delete poligonPoints;
}


PageRefFunc::PageRefFunc()
{
}

PageRefFunc::PageRefFunc(System::Drawing::Point points)
{
	//
	this->leftCoords.X = points.X - 16;
	this->leftCoords.Y = points.Y - 16;
	this->rightCoords.X = points.X + 16;
	this->rightCoords.Y = points.Y + 16;
	this->type = PAGEREFERENCE;
}

PageRefFunc::~PageRefFunc()
{
}

void PageRefFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex) {
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = 2.0f;
	e->Graphics->DrawEllipse(pen, this->leftCoords.X, this->leftCoords.Y, 32, 32);
	
	if (isVertex) {
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->leftCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->leftCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
		drawVertex(e, System::Drawing::Point(this->rightCoords.X, this->rightCoords.Y), System::Drawing::Color::Black);
	}

	delete pen;
	
}