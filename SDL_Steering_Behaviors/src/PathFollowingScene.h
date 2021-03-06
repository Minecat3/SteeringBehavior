#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"
#include "Image.h"

class PathFollowingScene :
	public Scene
{
public:
	PathFollowingScene();
	~PathFollowingScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	std::queue<Vector2D> path;
	std::vector<Agent*> agents;
	Image* text;
	Vector2D target;
};
