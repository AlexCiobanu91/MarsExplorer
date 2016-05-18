#pragma once
#include "Includes.h"
#include "Structures.h"
class Agent
{
	unsigned int _vbo, _ibo, _vao, _numIndices;
	unsigned int _glProgramShader;
	unsigned int _texture;
	glm::vec4 _mapSize;


	int _swarmSize;
	float _moveRadius;
	float _boundingRadius;
	float _centerDistance;
	float _agentDistance;
	float _distanceThreshold;
	float _minX, _maxX, _minZ, _maxZ, _minY, _maxY;
	float _collisionSpeed;
	float _adoptionThreshold;

	float _influenceTime;
	float _leaderLifeSpan;
	float _leaderLifeTime;

	int _agentIndex;
	int _collisionType;
	int _followers;
	int _neighbors;

	bool _collision;
	bool _reposition;
	bool _isLeader;
	bool _hasLeader;



	bool _startTimer;
	bool _startTimerNoLeader;



	glm::vec3 _centerPosition;
	glm::vec3 _modelSize;
	glm::vec3 _startPosition;
	glm::vec3 _speed;
	glm::vec3 _startSpeed;
	glm::vec3 _leaderSpeed;
	glm::vec3 _swarmCenter;
	glm::vec3 _moveSpeed;
	glm::vec3 _leaderColor;
	glm::vec3 _influenceDistance;
	glm::mat4 _modelMatrix, _circleModelMatrix;
	std::vector<Agent> _agents;

	time_t _influenceStartTimer;
	time_t _noLeaderTimer;
	time_t _leaderLifeTimer;


public:
	Agent();

	Agent::Agent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, int agentIndex, glm::vec3 moveSpeed, glm::vec4 mapSize, unsigned int textureIndex);

	void Create();

	void Draw();
		
	void Move();

	void CheckCollision();

	glm::vec3 getPosition();

	glm::vec3 getModelSize();

};

