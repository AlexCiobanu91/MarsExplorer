#pragma once
#include "Includes.h"
#include "Agent.h"
#include "Structures.h"

class Container
{
private:
  unsigned int _vbo;
  unsigned int _ibo;
  unsigned int _vao;
  unsigned int _numIndices;
  unsigned int _glProgramShader;
  int _swarmSize;
  float _moveRadius;
  float _boundingRadius;
  float _centerDistance;
  float _agentDistance;
  float _distanceThreshold;
  int _agentIndex;

  glm::vec3 _centerPosition;

  glm::vec3 _minMaxY;
  glm::vec3 _modelSize;
  glm::vec3 _startPosition;
  glm::vec3 _speed;

  glm::vec3 _swarmCenter;
  glm::vec3 _moveSpeed;

  glm::mat4 _modelMatrix;
  std::vector<Agent*> _swarmReference;

  unsigned int _texture;
  glm::vec4 _mapSize;
public:

  Container(unsigned int gl_program_shader, glm::vec4 mapSize, unsigned int texture);

  //void SetAgentReference(std::vector<Agent*> &agents);

  void Draw(glm::mat4 matView, glm::mat4 matProjection);

  void Create();

};