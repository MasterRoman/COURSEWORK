#include "RectFunc.h"



RectFunc::RectFunc() {
}

RectFunc::~RectFunc() {
}

RectFunc::RectFunc(System::Drawing::Point leftP, System::Drawing::Point rightP) {
	this->leftCoords = leftP;
	this->rightCoords = rightP;
}