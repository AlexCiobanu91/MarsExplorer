#include "..\Headers\Agent.h"

Agent::Agent()
{
}

Agent::Agent(unsigned int gl_program_shader, glm::vec3 modelSize, glm::vec3 startPosition, int agentIndex, glm::vec3 moveSpeed, glm::vec4 mapSize, unsigned int textureIndex)
{
	_glProgramShader = gl_program_shader;
	_centerPosition = startPosition;
	_modelSize = modelSize;
	_startPosition = startPosition;
	_agentIndex = agentIndex;
	_moveSpeed = moveSpeed;
	_collision = false;
	_reposition = true;
	_collisionType = 0;
	_collisionSpeed = 40.0f;
	_mapSize = mapSize;
	_texture = textureIndex;
	Create();
}

void Agent::Create()
{
	std::vector<VertexTextureFormat> verts;
	std::vector<glm::uvec3> indx;

	// 0 -x -z
	verts.push_back(VertexTextureFormat(_centerPosition.x - 0.5f * _modelSize.x, 
		_agentIndex / 100.0,
										_centerPosition.z -  0.5f * _modelSize.z, 0, 0));

	// 1 +x -z
	verts.push_back(VertexTextureFormat(_centerPosition.x + 0.5f * _modelSize.x,
		_agentIndex / 100.0,
		_centerPosition.z - 0.5f * _modelSize.z, 1, 0));

	// 2 +x +z
	verts.push_back(VertexTextureFormat(_centerPosition.x + 0.5f * _modelSize.x,
		_agentIndex / 100.0,
		_centerPosition.z + 0.5f * _modelSize.z, 1, 1));

	// 3 -x +z
	verts.push_back(VertexTextureFormat(_centerPosition.x - 0.5f * _modelSize.x,
		_agentIndex / 100.0,
		_centerPosition.z + 0.5f * _modelSize.z, 0, 1));
	
	/*
	// 4 -x -z
	verts.push_back(VertexTextureFormat(_centerPosition.x - 0.5f * _modelSize.x,
		_agentIndex / 100.0 + 10,
		_centerPosition.z - 0.5f * _modelSize.z, 0, 0));

	// 5 +x -z
	verts.push_back(VertexTextureFormat(_centerPosition.x + 0.5f * _modelSize.x,
		_agentIndex / 100.0 + 10,
		_centerPosition.z - 0.5f * _modelSize.z, 1, 0));

	// 6 +x +z
	verts.push_back(VertexTextureFormat(_centerPosition.x + 0.5f * _modelSize.x,
		_agentIndex / 100.0 + 10,
		_centerPosition.z + 0.5f * _modelSize.z, 1, 1));

	// 7 -x +z
	verts.push_back(VertexTextureFormat(_centerPosition.x - 0.5f * _modelSize.x,
		_agentIndex / 100.0 + 10,
		_centerPosition.z + 0.5f * _modelSize.z, 0, 1));
	*/

	
	indx.push_back(glm::uvec3(0, 1, 2));
	indx.push_back(glm::uvec3(2, 3, 0));

	/*indx.push_back(glm::uvec3(4, 5, 6));
	indx.push_back(glm::uvec3(6, 7, 4));

	indx.push_back(glm::uvec3(0, 4, 5));
	indx.push_back(glm::uvec3(5, 1, 0));

	indx.push_back(glm::uvec3(1, 5, 6));
	indx.push_back(glm::uvec3(6, 2, 1));

	indx.push_back(glm::uvec3(3, 7, 6));
	indx.push_back(glm::uvec3(6, 2, 3));
	
	indx.push_back(glm::uvec3(0, 4, 7));
	indx.push_back(glm::uvec3(7, 3, 0));*/

	//vao
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	//vbo
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexTextureFormat) * verts.size(), &verts[0], GL_STATIC_DRAW);

	//ibo
	glGenBuffers(1, &_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indx.size() * 3, &indx[0], GL_STATIC_DRAW);

	// legatura intre atributele vertecsilor si pipeline, datele noastre sunt INTERLEAVED.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureFormat), (void*)0);						// trimite pozitii pe pipe 0
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTextureFormat), (void*)(sizeof(float) * 3));		// trimite normale pe pipe 1
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexTextureFormat), (void*)(2 * sizeof(float) * 3));	// trimite texcoord pe pipe 2

	_numIndices = (unsigned int)indx.size() * 3;
}

void Agent::Draw()
{
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glUniform1i(glGetUniformLocation(_glProgramShader, "textura"), 1);

	glBindVertexArray(_vao);
	glUniformMatrix4fv(glGetUniformLocation(_glProgramShader, "model_matrix"), 1, false, glm::value_ptr(_modelMatrix));
	glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, nullptr);
}

void Agent::CheckCollision()
{
	if (_minX > _centerPosition.x + _speed.x && !(_collisionType == 1))
	{
		_collision = true;
		_collisionType = 1;
		_speed.x = _collisionSpeed;
	}

	if (_maxX < _centerPosition.x + _speed.x && !(_collisionType == 2))
	{
		_collision = true;
		_collisionType = 2;
		_speed.x = -_collisionSpeed;
	}

	if (_minZ > _centerPosition.z + _speed.z && !(_collisionType == 3))
	{
		_collision = true;
		_collisionType = 3;
		_speed.z = _collisionSpeed;
	}

	if (_maxZ < _centerPosition.z + _speed.z && !(_collisionType == 4))
	{
		_collision = true;
		_collisionType = 4;
		_speed.z = -_collisionSpeed;
	}

	if (_minY > _centerPosition.y + _speed.y && !(_collisionType == 5))
	{
		_collision = true;
		_collisionType = 5;
		_speed.y = -_collisionSpeed;
	}

	if (_maxY < _centerPosition.y + _speed.y && !(_collisionType == 6))
	{
		_collision = true;
		_collisionType = 6;
		_speed.y = -_collisionSpeed;
	}
}

glm::vec3 Agent::getPosition()
{
	return _centerPosition;
}

glm::vec3 Agent::getModelSize()
{
	return _modelSize;
}

void Agent::Move()
{
	_modelMatrix = glm::translate(_modelMatrix, _speed);
	_centerPosition += _speed;
}


