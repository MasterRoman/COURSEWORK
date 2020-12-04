#pragma once
#include "FigureModel.h"

enum UndoTypes
{
	FUNC_MOVE_UNDO,
	LINE_MOVE_UNDO,
	POINT_ADD_UNDO,
	FIGURE_INSERT_UNDO,
	DELETE_UNDO,

};

ref struct UndoStack
{
	List^ figure;
	UndoTypes type;
	System::String^ str;
	UndoStack^ next;
};


UndoStack^ stackInit(UndoStack^ head);
bool stackIsEmpty(UndoStack^ head);
void pushStack(UndoStack^ head, List^ figure, UndoTypes type, System::String^ str);
UndoStack^ popStack(UndoStack^ head);
void cleanStack(UndoStack^ head);

void undoStackAction(UndoStack^ cur,List^ listHead);