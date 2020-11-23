#include "PictureView.h"
#include "DataTypes.h"
#include "RectFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>


using namespace System::Drawing;

void cleanScreen(System::Windows::Forms::PaintEventArgs^ e, int width, int height){
	e->Graphics->FillRectangle(Brushes::White,0,0,width,height);
}

void drawFunctions(System::Windows::Forms::PaintEventArgs^ e, List^ head,bool isVertex) {
	List^ cur = head->next;
	while (cur != nullptr)
	{

		cur->fig->drawFigure(e,isVertex);

		cur = cur->next;
	}



}

void drawPath(System::Windows::Forms::PaintEventArgs^ e, LineFunc^ line, System::Drawing::Point points) {

	if (line->headLine == nullptr) {
		return;
	}
Points *cur = line->headLine;
while (cur->next != nullptr)
{
	cur = cur->next;

}

int curX = cur->x;
int curY = cur->y;
// Запрещаем проводить прямую под углом
if (((points.X - curX) != 0) && (atan(abs((points.Y - curY) / (points.X - curX))) < M_PI_4)) {

	points.Y = curY;
}
else
{
	points.X = curX;
}
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = 2.0f;
	pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;

	e->Graphics->DrawLine(pen, cur->x, cur->y, points.X, points.Y);
	delete pen;
}


void drawSelectedRect(System::Windows::Forms::PaintEventArgs^ e, Rect rect) {
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
	if ((rect.right > rect.left) && (rect.top > rect.bottom))
		e->Graphics->DrawRectangle(pen, rect.left, rect.bottom, (rect.right - rect.left), (rect.top - rect.bottom));
	else if ((rect.left > rect.right) && (rect.bottom > rect.top))
		e->Graphics->DrawRectangle(pen, rect.right, rect.top, (rect.left - rect.right), (rect.bottom - rect.top));
	else if (rect.right > rect.left)
		e->Graphics->DrawRectangle(pen, rect.left, rect.top, (rect.right - rect.left), (rect.bottom - rect.top));
	else if (rect.left > rect.right)
		e->Graphics->DrawRectangle(pen, rect.right, rect.bottom, (rect.left - rect.right), (rect.top - rect.bottom));
	delete pen;
}


void drawVertex(System::Windows::Forms::PaintEventArgs^ e,System::Drawing::Point points, System::Drawing::Color color) {
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(color);
	pen->Width = 1.0f;
	System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(color);
	e->Graphics->DrawRectangle(pen, float(points.X - 4), float(points.Y - 4), 4*sqrt(2), 4 * sqrt(2));
	if (color == System::Drawing::Color::Black) {
	   e->Graphics->FillRectangle(System::Drawing::Brushes::White, float(points.X - 3), float(points.Y - 3), 3 * sqrt(2), 3 * sqrt(2));
	}
	else {
		e->Graphics->FillRectangle(brush, float(points.X - 3), float(points.Y - 3), 3 * sqrt(2), 3 * sqrt(2));
	}
	delete brush;
	delete pen;
}


void repaintSelectedFunc(System::Windows::Forms::PaintEventArgs^ e, List^ selectedFunc) {
	if (selectedFunc->fig->type != LINE) {
		RectFunc^ curF = (RectFunc^)selectedFunc->fig;
		drawVertex(e, System::Drawing::Point(curF->leftCoords.X, curF->leftCoords.Y), System::Drawing::Color::Blue);
		drawVertex(e, System::Drawing::Point(curF->rightCoords.X, curF->leftCoords.Y), System::Drawing::Color::Blue);
		if (curF->type != DATA) {
			//usual behavior
			drawVertex(e, System::Drawing::Point(curF->leftCoords.X, curF->rightCoords.Y), System::Drawing::Color::Blue);
			drawVertex(e, System::Drawing::Point(curF->rightCoords.X, curF->rightCoords.Y), System::Drawing::Color::Blue);
		}
		else {
			//костыль для даты 
			drawVertex(e, System::Drawing::Point(curF->rightCoords.X - 29, curF->rightCoords.Y), System::Drawing::Color::Blue);
			drawVertex(e, System::Drawing::Point(curF->leftCoords.X - 29, curF->rightCoords.Y), System::Drawing::Color::Blue);
		}
		return;
	}
	else
	{
		LineFunc^ curL = (LineFunc^)selectedFunc->fig;
		Points* curP = curL->headLine->next;
		while (curP!=nullptr)
		{
			drawVertex(e, System::Drawing::Point(curP->x, curP->y), System::Drawing::Color::Blue);
			curP = curP->next;
		}
	}
}