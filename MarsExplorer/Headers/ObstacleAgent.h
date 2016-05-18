#pragma once
#include "Agent.h"
class ObstacleAgent :
	public Agent
{
private:
	bool _isCristal;

public:

	ObstacleAgent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, int agentIndex, glm::vec4 mapSize, unsigned int textureIndex, bool isCristal);
	~ObstacleAgent();
};

