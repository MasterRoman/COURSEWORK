#pragma once


enum WriteType {  //типы для записи в фигуру 
	WRITE,
	NOT_WRITE
};

enum FunctionType{ //типы фигур 
	POINTER,
	LINE,
	PROCESS,
	DECISSION,
	DATA,
	TERMINATOR,
	PAGEREFERENCE,
	TEXT
};

enum TDrawMode   // типы режимов рисования 
{
	DRAW,
	NOT_DRAW,
	DRAW_LINE
};



enum EditMode   // типы режимов редактировния  
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
};

struct  Rect // структура для прямоугольой области 
{
	int top,bottom,right,left;

};

System::String^ functionTypeToString(FunctionType v);  // перевод типа фигуры в строку 

