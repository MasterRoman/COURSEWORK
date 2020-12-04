#include "LineFunc.h"
#include "PictureView.h"

LineFunc::LineFunc() {
	this->type = LINE;
}

LineFunc::~LineFunc() {
}

const int arrowWidth = 7; 
const int arrowLength = 14;

void LineFunc::drawFigure(System::Windows::Forms::PaintEventArgs^ e, bool isVertex){
	Points* cur = this->headLine->next;
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	pen->Width = this->width;
	Points* lastPoint = nullptr;
	Points* prevLastPoint = nullptr;
	if (cur != nullptr)
	while (cur->next != nullptr)
	{
		
		e->Graphics->DrawLine(pen,cur->x,cur->y,cur->next->x,cur->next->y);
		if (isVertex) {
			drawVertex(e, System::Drawing::Point(cur->x, cur->y), System::Drawing::Color::Black);
		}
		prevLastPoint = cur;
		lastPoint = cur->next;
		cur = cur->next;
	}

	if (lastPoint!=nullptr && prevLastPoint!=nullptr) {
		if (lastPoint->x == prevLastPoint->x) {
			if (lastPoint->y > prevLastPoint->y) {
				e->Graphics->DrawLine(pen, lastPoint->x - arrowWidth, lastPoint->y - arrowLength, lastPoint->x, lastPoint->y);
				e->Graphics->DrawLine(pen, lastPoint->x + arrowWidth, lastPoint->y - arrowLength, lastPoint->x, lastPoint->y);
			}
			else {
				e->Graphics->DrawLine(pen, lastPoint->x - arrowWidth, lastPoint->y + arrowLength, lastPoint->x, lastPoint->y);
				e->Graphics->DrawLine(pen, lastPoint->x + arrowWidth, lastPoint->y + arrowLength, lastPoint->x, lastPoint->y);
			}

		}
		else {
			if (lastPoint->x > prevLastPoint->x) {
				e->Graphics->DrawLine(pen, lastPoint->x - arrowLength, lastPoint->y + arrowWidth, lastPoint->x, lastPoint->y);
				e->Graphics->DrawLine(pen, lastPoint->x - arrowLength, lastPoint->y - arrowWidth, lastPoint->x, lastPoint->y);
			}
			else {
				e->Graphics->DrawLine(pen, lastPoint->x + arrowLength, lastPoint->y + arrowWidth, lastPoint->x, lastPoint->y);
				e->Graphics->DrawLine(pen, lastPoint->x + arrowLength, lastPoint->y - arrowWidth, lastPoint->x, lastPoint->y);
			}

		}
	}

	if (isVertex) {
		drawVertex(e, System::Drawing::Point(cur->x, cur->y), System::Drawing::Color::Black);
	}

	delete pen;
}