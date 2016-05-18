#pragma once
#include "Agent.h"
class BaseAgent :
	public Agent
{
public:
	BaseAgent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, glm::vec4 mapSize, unsigned int textureIndex);
	~BaseAgent();
};

