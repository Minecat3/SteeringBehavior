#pragma once

#include <vector>
#include "Scene.h"
#include "Agent.h"
#include "Image.h"
#include <vector>

class ObstacleAvoidanceScene :
	public Scene
{
public:
	ObstacleAvoidanceScene();
	~ObstacleAvoidanceScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
	std::vector<Vector2D> path;
private:
	std::vector<Agent*> agents;
	Image* text;
	Vector2D target;
};