#include "..\Headers\BaseAgent.h"



BaseAgent::BaseAgent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, glm::vec4 mapSize, unsigned int textureIndex):
	Agent(gl_program_shader, modelSize, startPosition, 0, glm::vec3(0,0,0), mapSize, textureIndex)
{

}


BaseAgent::~BaseAgent()
{
}

