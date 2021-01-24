#pragma once
#include "FigureModel.h"

enum UndoTypes  // типы действий ,которые можно отменить
{
	FUNC_MOVE_UNDO,
	LINE_MOVE_UNDO,
	POINT_ADD_UNDO,
	FIGURE_INSERT_UNDO,
	DELETE_UNDO,

};

ref struct UndoStack   // структура стека 
{
	List^ figure;
	UndoTypes type;
	System::String^ str;
	UndoStack^ next;
};

// основные функции для работы со стеком 
UndoStack^ stackInit(UndoStack^ head);
bool stackIsEmpty(UndoStack^ head);
void pushStack(UndoStack^ head, List^ figure, UndoTypes type, System::String^ str);
UndoStack^ popStack(UndoStack^ head);
void cleanStack(UndoStack^ head);

void undoStackAction(UndoStack^ cur,List^ listHead);