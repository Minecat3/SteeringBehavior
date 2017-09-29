#include "Line.h"

Line::Line() : 
	origin(Vector2D(0, 0)), 
	destiny(Vector2D(0, 0)) 
{
	CalculateVectorArrows();
	setColor(255, 255, 255);
}
Line::Line(const Vector2D& orig, const Vector2D& dest) : 
	origin(orig),
	destiny(dest)
{
	setColor(255, 255, 255);
	CalculateVectorArrows();
}

Line::~Line() {}

void Line::CalculateVectorArrows() {
	Vector2D pointDifference = destiny - origin;
	float angle = atan(pointDifference.y / pointDifference.x);
	//if (angle > M_PI) {
		vectorArrowRight.x = cos(angle - 60) * 20 + destiny.x;
		vectorArrowRight.y = sin(angle - 60) * 20 + destiny.y;

		vectorArrowLeft.x = cos(angle + 60) * 20 + destiny.x;
		vectorArrowLeft.y = sin(angle + 60) * 20 + destiny.y;
	//}
}
void Line::drawLine() {
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), red, green, blue, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), origin.x, origin.y, destiny.x, destiny.y);
}
void Line::drawVector() {
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), red, green, blue, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), origin.x, origin.y, destiny.x, destiny.y);
	SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), destiny.x, destiny.y, vectorArrowRight.x, vectorArrowRight.y);
	SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), destiny.x, destiny.y, vectorArrowLeft.x, vectorArrowLeft.y);
}