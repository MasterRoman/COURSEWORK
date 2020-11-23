#include "LineFunc.h"
#include "PictureView.h"

LineFunc::LineFunc() {
	this->type = LINE;
}

LineFunc::~LineFunc() {
}

void LineFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex){
	Points* cur = this->headLine->next;
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = this->width;
	if (cur != nullptr)
	while (cur->next != nullptr)
	{
		
		e->Graphics->DrawLine(pen,cur->x,cur->y,cur->next->x,cur->next->y);
		if (isVertex) {
			drawVertex(e, System::Drawing::Point(cur->x, cur->y), System::Drawing::Color::Black);
		}
		cur = cur->next;
	}

	if (isVertex) {
		drawVertex(e, System::Drawing::Point(cur->x, cur->y), System::Drawing::Color::Black);
	}

	delete pen;
}