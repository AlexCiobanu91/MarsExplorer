#include "..\Headers\ObstacleAgent.h"



ObstacleAgent::ObstacleAgent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, int agentIndex, glm::vec4 mapSize, unsigned int textureIndex, bool isCristal) :
	Agent(gl_program_shader, modelSize, startPosition, agentIndex, glm::vec3(0, 0, 0), mapSize, textureIndex)
{
	_isCristal = isCristal;
}


ObstacleAgent::~ObstacleAgent()
{
}

