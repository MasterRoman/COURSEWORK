#include "RectFunc.h"



RectFunc::RectFunc() {
	this->text = nullptr;
}

RectFunc::~RectFunc() {
}

RectFunc::RectFunc(System::Drawing::Point leftP, System::Drawing::Point rightP) {
	// конструктор для фигур
	this->leftCoords = leftP;
	this->rightCoords = rightP;
}