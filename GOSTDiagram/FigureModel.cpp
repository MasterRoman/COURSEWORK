#include "FigureModel.h"
#include "RectFunctions.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int closeObject = 5;


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


void transformFunc(List^ cur, System::Drawing::Point startPoints, System::Drawing::Point endPoints, EditMode mode) {
	int dX = endPoints.X - startPoints.X;
	int dY = endPoints.Y - startPoints.Y;
	
	if (cur != nullptr) {
	
	
		switch (mode)
		{
		case MOVE:
			{
				
				if (cur->fig->type != LINE) {
					RectFunc^ curF = (RectFunc^)cur->fig;
					curF->leftCoords.X -= dX;
					curF->rightCoords.X -=  dX;
					curF->leftCoords.Y -= dY;
					curF->rightCoords.Y -= dY;
				}
				else
				{
				LineFunc^ curL = (LineFunc^)cur->fig;
				Points* curP = curL->headLine->next;
				while (curP != nullptr) {
					
					curP->x = curP->x - dX;
					curP->y = curP->y - dY;
					curP = curP->next;
					}
				}
				break;
		}

		case TOP:
			{
				// смещаем верхнюю сторону
				RectFunc^ curF = (RectFunc^)cur->fig;
			//	if ((curF->leftCoords.Y - dY) < (curF->rightCoords.Y - 20))
				curF->leftCoords.Y = curF->leftCoords.Y - dY;
				break;
			}
		case BOTTOM:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				// Смещаем нижнюю сторону
				
				curF->rightCoords.Y = curF->rightCoords.Y - dY;
				break;
			}
		case RIGHT:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				// Смещаем правую сторону
				curF->rightCoords.X = curF->rightCoords.X - dX;
				break;
			}
		case LEFT:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				curF->leftCoords.X = curF->leftCoords.X - dX;
				break;
			}
		case LEFT_TOP:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				curF->leftCoords.X = curF->leftCoords.X - dX;
				curF->leftCoords.Y = curF->leftCoords.Y - dY;
				break;
			}
		case RIGHT_TOP:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				curF->rightCoords.X = curF->rightCoords.X - dX;
				curF->leftCoords.Y = curF->leftCoords.Y - dY;
				break;
			}
		case LEFT_BOTTOM:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				curF->leftCoords.X = curF->leftCoords.X - dX;
				curF->rightCoords.Y = curF->rightCoords.Y - dY;
				break;
			}
		case RIGHT_BOTTOM:
			{
				RectFunc^ curF = (RectFunc^)cur->fig;
				curF->rightCoords.X = curF->rightCoords.X - dX;
				curF->rightCoords.Y = curF->rightCoords.Y - dY;
					break;
			}
		case RESIZE_LINE:
			{
				LineFunc^ curL = (LineFunc^)cur->fig;
			
				
				
				break;
			}
		}
	}
}


EditMode getCurEditMode(List^ head,List^ selectedFunc, System::Drawing::Point points) {
	if (head->next == nullptr)
		return NOT_EDIT;

List^ cur  = head->next;
while (cur != nullptr) {
	if (cur->fig->type != LINE) {
		RectFunc^ curF = (RectFunc^)cur->fig;
		if ((selectedFunc != nullptr) && (curF == selectedFunc->fig)) {

			if ((abs(points.Y - curF->leftCoords.Y) < (closeObject)) &&
				(abs(points.X - curF->leftCoords.X) < (closeObject)))
				// Левая верхняя вершина
				return LEFT_TOP;

			if ((abs(points.Y - curF->leftCoords.Y) < (closeObject)) &&
				(abs(points.X - curF->rightCoords.X) < (closeObject)))

				// Правая верхняя вершина
				return RIGHT_TOP;

			if ((abs(points.Y - curF->rightCoords.Y) < (closeObject)) &&
				(abs(points.X - curF->leftCoords.X) < (closeObject))) {

				// Левая нижняя вершина
				return LEFT_BOTTOM;
			}
			if ((abs(points.Y - curF->rightCoords.Y) < (closeObject)) &&
				(abs(points.X - curF->rightCoords.X) < (closeObject)))

				// Правая нижняя вершина
				return RIGHT_BOTTOM;

			if ((points.X >= curF->leftCoords.X) && (points.X <= curF->rightCoords.X) && ((abs(points.Y - curF->leftCoords.Y) < (closeObject))
				|| (abs(points.Y - curF->rightCoords.Y) < (closeObject))))

				// Горизонтальная сторона
				if (abs(points.Y - curF->leftCoords.Y) < (closeObject))
					return TOP;
				else
					return BOTTOM;

			if ((points.Y >= curF->leftCoords.Y) && (points.Y <= curF->rightCoords.Y) && ((abs(points.X - curF->leftCoords.X) < (closeObject))
				|| (abs(points.X - curF->rightCoords.X) < (closeObject)))) {

				// Вертикальная сторона
				if (abs(points.X - curF->leftCoords.X) < (closeObject))
					return LEFT;
				else
					return RIGHT;
			}
			

		}
		if ((curF->leftCoords.X < points.X) && (curF->rightCoords.X > points.X) &&
			(curF->leftCoords.Y < points.Y) && (curF->rightCoords.Y > points.Y))
		{
			return MOVE;
		}
	}
	else
	{
		LineFunc^ curL = (LineFunc^)cur->fig;
		Points* curP = curL->headLine->next;
		while (curP != nullptr) {
			
			if ((selectedFunc != nullptr) && (curL == selectedFunc->fig)) {
				//CHECK IT AGAIN 
				
				if ((abs(points.Y - curP->y) <= closeObject) &&
					(abs(points.X - curP->x) <= closeObject)) {
					
					return RESIZE_LINE;
				
				}
			}

			if (curP->next != nullptr) 
				if (((abs(points.Y - curP->y) <= closeObject) && // горизонтальная
					(points.X >= min(curP->x, curP->next->x)) &&
					(points.X <= max(curP->x, curP->next->x))) ||
					((abs(points.X - curP->x) <= closeObject) && // вертикальная
						(points.Y >= min(curP->y, curP->next->y)) &&
						(points.Y <= max(curP->y, curP->next->y))))
					return MOVE;
		curP = curP->next;
		}
	}
	cur = cur->next;
}

return NOT_EDIT;

}

System::String^ pointsToStr(System::Drawing::Point points) {
	System::String^ res = (points.X).ToString();
	res = res + "|" + (points.Y).ToString()+"|";

	return res;
}

void saveToFile(List^ head, System::String^ path) {
	List^ cur = head->next;
	System::IO::StreamWriter^ file = gcnew  System::IO::StreamWriter(path);
	file->WriteLine("RKZFILE");
	while (cur!=nullptr)
	{
		if (cur->fig->type != LINE) {
			RectFunc^ curF = (RectFunc^)cur->fig;
			
			System::String^ res = "";
			res += functionTypeToString(curF->type) + "|";
			res += curF->text + "|";
			res += pointsToStr(curF->leftCoords);
			res += pointsToStr(curF->rightCoords);
			file->WriteLine(res);
		}
		else
		{
			LineFunc^ line = (LineFunc^)cur->fig;
			Points* points = line->headLine->next;
			System::String^ res = "";
			res += functionTypeToString(line->type) + "|";
			while (points!=nullptr)
			{
				res += pointsToStr(System::Drawing::Point(points->x, points->y));
				points = points->next;
			}
			
			file->WriteLine(res);
		}

		cur = cur->next;
	}

	file->Close();
	
}

System::Drawing::Point parseStringToPoints(System::String^  &str) {
	System::Drawing::Point points;
	int pos = str->IndexOf("|");
	int len = str->Length - pos;
	System::String^ temp = str->Remove(pos, len);
	str = str->Remove(0, pos + 1);
	points.X = int::Parse(temp);
    pos = str->IndexOf("|");
    len = str->Length - pos;
	temp = str->Remove(pos, len);
	str = str->Remove(0, pos + 1);
	points.Y = int::Parse(temp);
	return points;
}

bool readFromFile(List^ head, System::String^ path) {
	System::String^ res = "";
	if (System::IO::File::Exists(path)) {
		System::IO::StreamReader^ file = gcnew  System::IO::StreamReader(path);
		res = file->ReadLine();
		if (res == "RKZFILE") {
			while (!file->EndOfStream)
			{
				res = file->ReadLine();
				switch ((FunctionType)(res[0] - '0'))
				{
				case LINE:{
					    res = res->Remove(0, 2);
						List^ line = addLine(head, parseStringToPoints(res));
						while (res->Length != 0) {
							System::Drawing::Point points = parseStringToPoints(res);
							addPoints((LineFunc^)line->fig, points);
						}

						break;
					}
				default:
					AbstractFigure^ fig = figureFromType((FunctionType)(res[0]-'0'), System::Drawing::Point(0, 0));
					fig->type = (FunctionType)(res[0] - '0');
					res = res->Remove(0, 2);
					int pos = res->IndexOf("|");
					RectFunc^ rf = (RectFunc^)fig; 
					int len = res->Length - pos;
					System::String^ temp = res->Remove(pos,len);
					rf->text = temp;
					res = res->Remove(0, pos+1);
					rf->leftCoords = parseStringToPoints(res);
					rf->rightCoords = parseStringToPoints(res);

					pushExistingFunc(head, fig);
					break;

				}
				
			}
	
			file->Close();
			return true;
		}
		else {
			file->Close();
			System::Windows::Forms::MessageBox::Show("Не верный формат или файл поврежден", "Ошибка!",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
			return false;
		}
	}
	else 
	return false;
}

void makeFuncOnOneLine(List^ head, List^ cur) {
	RectFunc^ cFunc = (RectFunc ^)cur->fig;
	int curX = cFunc->leftCoords.X + (cFunc->rightCoords.X - cFunc->leftCoords.X) / 2;
	List^ curL = head->next;
	while (curL != nullptr) {
		if (curL->fig->type == LINE) {
			curL = curL->next;
			continue;
		}
		else if (cur != curL)
		{
			RectFunc^ rectFunc = (RectFunc^)curL->fig;
			int nCurX = rectFunc->leftCoords.X + (rectFunc->rightCoords.X - rectFunc->leftCoords.X) / 2;
			if (abs(nCurX - curX) <= closeObject * 3) {
				cFunc->leftCoords.X = rectFunc->leftCoords.X;
				cFunc->rightCoords.X = rectFunc->rightCoords.X;
				return;
			}
		}
		curL = curL->next;
	}
}

void makeSmoothLine(List^ curLine, System::Drawing::Point newPoints, System::Drawing::Point prevPoints) {
	LineFunc^ line = (LineFunc^)curLine->fig;
	Points* curP = line->headLine->next;
	while (curP != nullptr) {
		if (((curP->x != newPoints.X) && (curP->y != newPoints.Y)) &&
			(((curP->y == prevPoints.Y)) || ((curP->x == prevPoints.X)) ||
				((curP->x == prevPoints.X) && (curP->y == prevPoints.Y))))
		{
			if (curP->y == prevPoints.Y)
				curP->y = newPoints.Y;

		if (curP->x == prevPoints.X)
			curP->x  = newPoints.X;

		}
	curP = curP->next;
	}
}

void makePointOnCenter(List^ head, List^ curL) {
bool fF = false;
bool fE = false;
	List^  cur = head->next;
	LineFunc^ line = (LineFunc^)curL->fig;
	Points *curP = line->headLine->next;
	Points *curPF = curP;
	while (curP->next != nullptr)
{
	curP = curP->next;
	}
Points*  curPE = curP;
	while (cur!=nullptr) {
		if (curL == cur)
		{
			cur = cur->next;
			continue;
		}
	if (cur->fig->type != LINE)
	{
		RectFunc^ curF = (RectFunc^)cur->fig;
	int	curX  = curF->leftCoords.X + (curF->rightCoords.X - curF->leftCoords.X) / 2;
	if (((abs(curPF->y - curF->rightCoords.Y) <= (closeObject+3 )) ||
		(abs(curPF->y - curF->leftCoords.Y) <= (closeObject+3))) &&
		(abs(curPF->x - curX) <= (closeObject+3 )) && (!fF)) 
	{
		fF = true;
	Points* pP = curPF;
	if (abs(curPF->y - curF->rightCoords.Y) <= (closeObject+3))
		curPF->y = curF->rightCoords.Y;
	else
		curPF->y  = curF->leftCoords.Y;
	curPF->x  = curX;
	makeSmoothLine(curL, System::Drawing::Point(curPF->x,curPF->y), System::Drawing::Point(pP->x, pP->y));
	}
	else if (((abs(curPE->y - curF->rightCoords.Y) <= (closeObject +3)) ||
		(abs(curPE->y - curF->leftCoords.Y) <= (closeObject+3 ))) &&
		(abs(curPE->x - curX) <= (closeObject+3 )) &&  (!fE))
	{
		fE = true;
		Points* pP = curPE;
		if (abs(curPE->y - curF->leftCoords.Y) <= (closeObject+3))
			curPE->y = curF->leftCoords.Y;
	else
		curPE->y  = curF->rightCoords.Y;
	curPE->x  = curX;
	makeSmoothLine(curL, System::Drawing::Point(curPE->x, curPE->y), System::Drawing::Point(pP->x, pP->y));
	}
		if (fF && fE)
			return;
	}


	cur = cur->next;
	}
}
