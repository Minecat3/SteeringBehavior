#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"
#include "Image.h"
#include "Line.h"

class FlockingScene :
	public Scene
{
public:
	FlockingScene();
	~FlockingScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	bool showRadius;
	std::vector<Agent*> agents;
	Image* text;
	Vector2D target;
};

