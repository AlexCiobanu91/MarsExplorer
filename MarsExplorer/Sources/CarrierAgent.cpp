#include "..\Headers\CarrierAgent.h"



CarrierAgent::CarrierAgent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, int agentIndex, glm::vec3 moveSpeed, glm::vec4 mapSize, unsigned int textureIndex) :
	Agent(gl_program_shader, modelSize, startPosition, agentIndex, moveSpeed, mapSize, textureIndex)
{

}


CarrierAgent::~CarrierAgent()
{
}

