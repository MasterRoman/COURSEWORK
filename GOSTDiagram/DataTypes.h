#pragma once


enum WriteType {
	WRITE,
	NOT_WRITE
};

enum FunctionType{
	POINTER,
	LINE,
	PROCESS,
	DECISSION,
	DATA,
	TERMINATOR,
	PAGEREFERENCE,
	TEXT
};

enum TDrawMode
{
	DRAW,
	NOT_DRAW,
	DRAW_LINE,
	WRITE_TEXT
};



enum EditMode
{
	NOT_EDIT, 
	MOVE, 
	LEFT, 
	RIGHT, 
	TOP, 
	BOTTOM, 
	LEFT_TOP, 
	RIGHT_TOP,
	LEFT_BOTTOM,
	RIGHT_BOTTOM,
	RESIZE_LINE
};

struct  Rect
{
	int top,bottom,right,left;

};

System::String^ functionTypeToString(FunctionType v);

