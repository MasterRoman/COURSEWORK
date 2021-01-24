#include "UndoStack.h"
#include "LineFunc.h"
#include "RectFunc.h"

UndoStack^ stackInit(UndoStack^ head) {  // создание стека 
	head = gcnew UndoStack;
	head->str = nullptr;
	head->next = nullptr;

	return head;
}
bool stackIsEmpty(UndoStack^ head) {  // проверка стека на пустоту  
	if (head->next == nullptr)
		return true;
	return false;
}

void pushStack(UndoStack^ head, List^ figure, UndoTypes type,System::String^ str) {  // добавление в стек 
	UndoStack^ newEl = gcnew UndoStack;
	newEl->figure = figure;
	newEl->type = type;
	newEl->str = str;
	newEl->next = nullptr;
	if (stackIsEmpty(head)) {
		head->next = newEl;
		return;
	}
	newEl->next = head->next;
	head->next = newEl;
}

UndoStack^ popStack(UndoStack^ head) {  // изъятие из стека 
	if (!stackIsEmpty(head)) {
		UndoStack^ cur = head->next;
		head->next = head->next->next;
		//delete vertex after using!
		return cur;
	}
	else 
		return nullptr;

}

void cleanStack(UndoStack^ head) {  // очистка стека 
	UndoStack^ cur = head->next;
	while (cur != nullptr) {
		UndoStack^ temp = cur;
		cur = cur->next;
		//delete temp->str;
		delete temp;
	}
}

void undoStackAction(UndoStack^ cur, List^ listHead){  // действия отмены  
	if (cur != nullptr) {
		switch (cur->type){
			// перебор различных вариантов и реагирование на них
		case FUNC_MOVE_UNDO: {
			RectFunc^ curF = (RectFunc^)cur->figure->fig;
			System::String^ str = cur->str;
			curF->leftCoords = parseStringToPoints(str);
			curF->rightCoords = parseStringToPoints(str);
			break;
		}
		case LINE_MOVE_UNDO: {
			System::String^ str = cur->str;
			LineFunc^ curL = (LineFunc^)cur->figure->fig;
			Points* pointsP = curL->headLine->next;
			while (pointsP != nullptr) {
				System::Drawing::Point points = parseStringToPoints(str);
				pointsP->x = points.X;
				pointsP->y = points.Y;
				pointsP = pointsP->next;
			}
		}
			break;

		case POINT_ADD_UNDO: {
			LineFunc^ line = (LineFunc^)cur->figure->fig;
			Points* points = line->headLine;
			if (points->next != nullptr && points->next->next != nullptr)
			{
				while (points->next->next != nullptr) {
					points = points->next;
				}
				delete points->next;
				points->next = nullptr;
				
			}
			
			break;
		}

		case FIGURE_INSERT_UNDO:
			deleteElement(listHead,cur->figure);
			if (cur->figure->fig->type == LINE) {
				LineFunc^ line = (LineFunc^)cur->figure->fig;
				//delete line->headLine->next;
				line->headLine->next = nullptr;
			
			}
			break;

		case DELETE_UNDO:
			pushExistingFunc(listHead, cur->figure->fig);
			break;

		}

		delete cur;
	}
}

