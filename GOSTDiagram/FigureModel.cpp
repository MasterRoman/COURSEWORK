#include "FigureModel.h"
#include "RectFunctions.h"
#define _USE_MATH_DEFINES
#include <math.h>



List^ initList(List^ head) {
    head = gcnew List;
	head->next = nullptr;

	return head;
}

void cleanList(List^ head) {
	List^ temp = nullptr;
	List^ cur = head->next;
	while (cur!=nullptr)
	{
		temp = cur;
		delete temp;
		cur = cur->next;
	}
	head->next = nullptr;
}

List^ push(List^ head, FunctionType fType, System::Drawing::Point points){
	List^ cur = head;
	while (cur->next!=nullptr)
	{
		cur = cur->next;
	}
	cur->next = gcnew List;
	cur = cur->next;
	cur->next = nullptr;
	//add figure 

    cur->fig = figureFromType(fType,points);
	return cur;
}

void pushExistingFunc(List^ head, AbstractFigure^ element) {
	List^ cur = head;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = gcnew List;
	cur = cur->next;
	cur->next = nullptr;
	cur->fig = element;

}

void deleteElement(List^ head, List^ elementToDelete) {
	List^ cur = head;
	List^ curEl;
	while (cur->next!=nullptr)
	{
		curEl = cur->next;
		if (curEl->fig == elementToDelete->fig) {
			cur->next = curEl->next;
			return;
		}
		else
			cur = cur->next;

	}
}

AbstractFigure^ figureFromType(FunctionType fType, System::Drawing::Point points) {
    RectFunc^ cur;
	switch (fType)
	{
	case PROCESS: 
		cur = gcnew ProcessFunc(points);
		break;
	case DECISSION: 
		cur = gcnew DecissionFunc(points);
		break;
	case DATA:   
		cur = gcnew DataFunc(points);
		break;
	case TERMINATOR:   
		cur = gcnew TerminatorFunc(points);
		break;
	case PAGEREFERENCE: 
		cur = gcnew PageRefFunc(points);
		break;


		//Write logic!!!
	case TEXT:
		//cur =
		break;
	}
	
	return cur;
}


//Line Model

List^ addLine(List^ head, System::Drawing::Point points) {
	List^ cur = head;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	cur->next = gcnew List;
	cur = cur->next;
	cur->next = nullptr;
	
	
	LineFunc^ line = gcnew LineFunc;
	line->headLine = new Points;
	line->headLine->next = nullptr;
	line->width = 2.0f;
	addPoints(line,points);

	cur->fig = line;
	

	return cur;
}

Points* addPoints(LineFunc^ line, System::Drawing::Point points) {
	Points *cur = line->headLine;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	int curX, curY;

	if (cur != line->headLine) {
		curX = cur->x;
	    curY = cur->y;
		// Запрещаем проводить прямую под углом
		
		if (((points.X - curX) != 0) && (atan(abs((points.Y - curY) / (points.X - curX))) < M_PI_4)) {

			points.Y = curY;
		}
		else 
		{
			points.X = curX;
		}

	}

	cur->next = new Points;
	cur = cur->next;
	cur->next = nullptr;



	cur->x = points.X;
	cur->y = points.Y;

	return cur;
}

List^ hitTest(List^ head, System::Drawing::Point points) {
	int closeObject = 5;

	if (head == nullptr) {
		return nullptr;
	}
	List^ cur = head->next;
	while (cur != nullptr)
	{
		if (cur->fig->type != LINE) {
			RectFunc^ curF = (RectFunc^)cur->fig;
			if ((points.X >= curF->leftCoords.X) && (points.X <= curF->rightCoords.X) && (points.Y >= curF->leftCoords.Y) &&
				(points.Y <= curF->rightCoords.Y)) {
				return cur;
			}
		}
		else
		{
			LineFunc^ curL = (LineFunc^)cur->fig;
			Points* curP = curL->headLine->next;
			while (curP != nullptr)
			{
				if ((abs(points.X - curP->x) <= closeObject) && // если это вершина
					(abs(points.Y - curP->y) <= closeObject)) {
					return cur;
				}

				if (curP->next != nullptr) { // если проверяем точку на линии
					if (((abs(points.Y - curP->y) <= closeObject) && // горизонтальная
						(points.X >= min(curP->x, curP->next->x)) &&
						(points.X <= max(curP->x, curP->next->x))) ||
						((abs(points.X - curP->x) <= closeObject) && // вертикальная
							(points.Y >= min(curP->y, curP->next->y)) &&
							(points.Y <= max(curP->y, curP->next->y)))) {

						return cur;
					};
				}

				curP = curP->next;
			}
		}
		cur = cur->next;
	}

	return nullptr;
}

int max(int first, int second) {
	if (first > second)
		return first;
	else
		return second;
}
int min(int first, int second) {
	if (first < second)
		return first;
	else
		return second;
}

void swap(int &first, int &second) {
	int t = first;
	first = second;
	second = t;
}

void getSelectedFuncFromRect(List^ head, List^ selectedHead, Rect rect) {
	if (rect.right < rect.left) {
		swap(rect.right, rect.left);
	}
	if (rect.top < rect.bottom) {
		swap(rect.top, rect.bottom);
	}

	List^ cur = head->next;
	while (cur!=nullptr)
	{
		if (cur->fig->type != LINE) {
			RectFunc^ curF = (RectFunc^)cur->fig;
			if ((((curF->leftCoords.X > rect.left) && (curF->leftCoords.X < rect.right))
				|| ((curF->rightCoords.X > rect.left)) && (curF->rightCoords.X < rect.right))
				&& (((curF->leftCoords.Y < rect.top) && (curF->leftCoords.Y > rect.bottom)
					) || ((curF->rightCoords.Y < rect.top) &&
						(curF->rightCoords.Y > rect.bottom)))) {
				pushExistingFunc(selectedHead, curF);
			}
		}
		else
		{
			LineFunc^ curL = (LineFunc^)cur->fig;
			Points* curP = curL->headLine->next;
			while (curP != nullptr)
			{
				if ((curP->x > rect.left) && (curP->x < rect.right) &&
					(curP->y < rect.top) && (curP->y > rect.bottom)) {
					//push figure
					pushExistingFunc(selectedHead, curL);
				}

				curP = curP->next;
			}
		}
		cur = cur->next;
	}
}