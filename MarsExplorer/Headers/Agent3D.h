#pragma once
#include "Includes.h"
class Agent3D
{
private:
  unsigned int _vbo, _circleVbo;
  unsigned int _colorsVbo, _circleColorsVbo;
  unsigned int _ibo, _circleIbo;
  unsigned int _vao, _circleVao;
  unsigned int _numIndices, _circleNumIndices;
  unsigned int _glProgramShader;
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
  std::vector<Agent3D*> _swarmReference;
  std::vector<Agent3D*> _neighborsList;
  Agent3D *_leader;

  time_t _influenceStartTimer;
  time_t _noLeaderTimer;
  time_t _leaderLifeTimer;

public:
  Agent3D(unsigned int gl_program_shader, glm::vec3 startingPosition, glm::vec3 modelSize, glm::vec3 startPosition, float agentDistance, int swarmSize, float distanceThreshold, glm::vec3 startSpeed, int agentIndex, glm::vec3 moveSpeed, float centerDistance, float leaderLifeTime)
  {
    _glProgramShader = gl_program_shader;
    _centerPosition = startingPosition;
    _modelSize = modelSize;
    _startPosition = startPosition;
    _agentDistance = agentDistance;
    _agentIndex = agentIndex;
    _swarmSize = swarmSize;
    _distanceThreshold = distanceThreshold;
    _startSpeed = startSpeed;
    _speed = startSpeed;
    _moveSpeed = moveSpeed;
    _centerDistance = centerDistance;
    _collision = false;
    _reposition = true;
    _collisionType = 0;
    _collisionSpeed = 40.0f;
    _followers = 0;
    _neighbors = 0;
    _isLeader = false;
    _hasLeader = false;
    _adoptionThreshold = 95;
    _influenceDistance = glm::vec3(_modelSize.x * 10, _modelSize.y * 10, _modelSize.z * 10);
    _influenceTime = 4;
    _leaderLifeTime = leaderLifeTime;
    _leader = NULL;

    _minX = _minZ = -5000;
    _maxX = 13000;
    _maxZ = 5000;
    _minY = 0;
    _maxY = 2000;
    _startTimer = false;

    _leaderColor.x = ((float)(rand() % 255)) / 255;
    _leaderColor.y = ((float)(rand() % 255)) / 255;
    _leaderColor.z = ((float)(rand() % 255)) / 255;

    _leaderSpeed.x = (rand() % 2 == 0 ? -1.0f : 1.0f) * _collisionSpeed;
    _leaderSpeed.y = (rand() % 2 == 0 ? -1.0f : 1.0f) * _collisionSpeed;
    _leaderSpeed.z = (rand() % 2 == 0 ? -1.0f : 1.0f) * _collisionSpeed;

    create();
    // createCircle();
  }

  glm::vec3 getColor()
  {
    return _leaderColor;
  }

  void setLeader(Agent3D *leader) {
    _leader = leader;
    _hasLeader = true;
  }

  void resetLeader()
  {
    _hasLeader = false;
    _leader = NULL;
  }

  std::vector<Agent3D*> getNeighbors()
  {
    return _neighborsList;
  }

  Agent3D* getLeader()
  {
    return _leader;
  }

  bool hasLeader()
  {
    return _hasLeader;
  }

  bool hasSpecificLeader(Agent3D* leader)
  {
    return _hasLeader && _leader == leader;
  }

  void setCollisionType(int type) {
    _collisionType = type;
  }

  unsigned int getNumIndices()
  {
    return _numIndices;
  }

  unsigned int getVao()
  {
    return _vao;
  }

  int getAgentIndex()
  {
    return _agentIndex;
  }

  bool getCollision()
  {
    return _collision;
  }

  int getCollisionType()
  {
    return _collisionType;
  }

  glm::vec3 getSpeed()
  {
    return _speed;
  }

  glm::vec3 getCenterPosition()
  {
    return _centerPosition;
  }

  glm::vec3 getNeighborMeanSpeed()
  {

    _neighborsList.clear();
    glm::vec3 meanSpeed = glm::vec3(0, 0, 0);
    int noNeighbors = 0;
    for (auto agent = _swarmReference.begin(); agent != _swarmReference.end(); ++agent) {
      if ((*agent)->getAgentIndex() == _agentIndex) continue;
      glm::vec3 neighborPosition = (*agent)->getCenterPosition();
      if (glm::distance(neighborPosition, _centerPosition) < _modelSize.x * 3.0f) {
        meanSpeed += (*agent)->getSpeed();
        noNeighbors++;
        _neighborsList.push_back((*agent));
      }
    }
    _neighbors = noNeighbors;
    if (noNeighbors == 0) noNeighbors = 1;
    return glm::vec3(meanSpeed.x / noNeighbors, meanSpeed.y / noNeighbors, meanSpeed.z / noNeighbors);
  }

  void setSwarmReference(std::vector<Agent3D*> & swarm)
  {
    _swarmReference = swarm;
  }

  void setSpeed(glm::vec3 speed)
  {
    _speed = speed;
  }

  void setCollision(bool collision)
  {
    _collision = collision;
  }

  int getNoNeighbors()
  {
    return _neighbors;
  }

  void setAsLeader(bool isLeader)
  {
    if (isLeader && !_isLeader)
    {
      time(&_leaderLifeTimer);

      _leaderSpeed.x = (rand() % 2 == 0 ? -1.0f : 1.0f) * _leaderSpeed.x;
      _leaderSpeed.y = 0;
      _leaderSpeed.z = (rand() % 2 == 0 ? -1.0f : 1.0f) * _leaderSpeed.z;

    }
    _isLeader = isLeader;
  }

  bool isLeader()
  {
    return _isLeader;
  }

  void bindAgent()
  {
    float i, j, k, a;

    std::vector<glm::vec4> colors;
    if (_isLeader) {
      i = 0, j = 0, j = 0;
      colors.push_back(glm::vec4(_leaderColor.x, _leaderColor.y, _leaderColor.z, 1));
      colors.push_back(glm::vec4(_leaderColor.y, _leaderColor.z, _leaderColor.x, 1));
      colors.push_back(glm::vec4(_leaderColor.x, _leaderColor.y, _leaderColor.z, 1));
      colors.push_back(glm::vec4(_leaderColor.y, _leaderColor.z, _leaderColor.x, 1));
    }
    else if (_hasLeader) {
      glm::vec3 leaderColor = _leader->getColor();
      colors.push_back(glm::vec4(leaderColor.x, leaderColor.y, leaderColor.z, 1));
      colors.push_back(glm::vec4(leaderColor.x, leaderColor.y, leaderColor.z, 1));
      colors.push_back(glm::vec4(leaderColor.x, leaderColor.y, leaderColor.z, 1));
      colors.push_back(glm::vec4(leaderColor.x, leaderColor.y, leaderColor.z, 1));
    }
    else {
      // white = 0
      i = 1; j = 1; k = 1, a = 1;


      /*
      // blue = 1
          else if (_neighbors < 2) {
            i = 0; j = 0; k = 1, a = 1;
          }
          // yellow = 2
          else if (_neighbors < 3)
          {
            i = 1; j = 1; k = 0, a = 1;
          }
          // green = 3
          else if (_neighbors < 4) {
            i = 0; j = 1; k = 0, a = 1;
          }
          // red = 4
          else  if (_neighbors < 5) {
            i = 1; j = 0; k = 0, a = 1;
          }
          // pink > 4
          else {
            i = 1; j = 0; k = 1, a = 1;
          }
      */

      colors.push_back(glm::vec4(i, j, k, a));
      colors.push_back(glm::vec4(i, j, k, a));
      colors.push_back(glm::vec4(i, j, k, a));
      colors.push_back(glm::vec4(i, j, k, a));
    }

    glBindBuffer(GL_ARRAY_BUFFER, _colorsVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * colors.size(), &colors[0], GL_STATIC_DRAW);

    glBindVertexArray(_vao);
  }

  void bindCircle()
  {
    if (_isLeader || _hasLeader) {
      glBindVertexArray(_circleVao);
    }
  }

  void renderCircle()
  {
    if (_isLeader || _hasLeader) {
      glUniformMatrix4fv(glGetUniformLocation(_glProgramShader, "model_matrix"), 1, false, glm::value_ptr(_circleModelMatrix));
      glDrawElements(GL_TRIANGLES, _circleNumIndices, GL_UNSIGNED_INT, nullptr);
    }
  }

  void render()
  {
    glUniformMatrix4fv(glGetUniformLocation(_glProgramShader, "model_matrix"), 1, false, glm::value_ptr(_modelMatrix));
    glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, nullptr);
  }

  void create()
  {
    std::vector<VertexFormat>verts;
    std::vector<glm::uvec3>indx;

    float i, j, k;
    i = j = k = 1;

    verts.push_back(VertexFormat(_centerPosition.x - 2.0f * _modelSize.x / 3.0f + _startPosition.x, _startPosition.y + _centerPosition.y, _centerPosition.z - _modelSize.z / 3.0f + _startPosition.z, i, j, k, 1));
    verts.push_back(VertexFormat(_centerPosition.x + _modelSize.x / 3.0f + _startPosition.x, _startPosition.y + _centerPosition.y, _centerPosition.z - _modelSize.z / 3.0f + _startPosition.z, i, j, k, 1));
    verts.push_back(VertexFormat(_centerPosition.x + _startPosition.x, _startPosition.y + _centerPosition.y, _centerPosition.z + 2.0f * _modelSize.z / 3.0f + _startPosition.z, i, j, k, 1));
    verts.push_back(VertexFormat(_centerPosition.x + _startPosition.x, _startPosition.y + 10.0f + _centerPosition.y, _centerPosition.z + 2.0f * _modelSize.z / 3.0f + _startPosition.z, i, j, k, 1));

    indx.push_back(glm::uvec3(1, 2, 0));
    indx.push_back(glm::uvec3(2, 0, 1));
    indx.push_back(glm::uvec3(0, 3, 2));
    indx.push_back(glm::uvec3(0, 1, 3));
    indx.push_back(glm::uvec3(3, 1, 2));

    //vao
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    //vbo
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * verts.size(), &verts[0], GL_STATIC_DRAW);

    //ibo
    glGenBuffers(1, &_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indx.size() * 3, &indx[0], GL_STATIC_DRAW);

    int pipe = glGetAttribLocation(_glProgramShader, "in_position");
    glEnableVertexAttribArray(pipe);
    glVertexAttribPointer(pipe, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), static_cast<void*>(nullptr));


    std::vector<glm::vec4> colors;
    colors.push_back(glm::vec4(i, j, k, 1));
    colors.push_back(glm::vec4(i, j, k, 1));
    colors.push_back(glm::vec4(i, j, k, 1));
    colors.push_back(glm::vec4(i, j, k, 1));

    //colorsVBO
    glGenBuffers(1, &_colorsVbo);
    glBindBuffer(GL_ARRAY_BUFFER, _colorsVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * colors.size(), &colors[0], GL_STATIC_DRAW);

    pipe = glGetAttribLocation(_glProgramShader, "in_color");
    glEnableVertexAttribArray(pipe);
    glVertexAttribPointer(pipe, 4, GL_FLOAT, GL_FALSE, 0, 0);
    _numIndices = (unsigned int)indx.size() * 3;
  }

  void createCircle() {

    std::vector<VertexFormat>verts;
    std::vector<glm::uvec3>indx;
    std::vector<glm::vec4> colors;

    float i, j, k;
    i = j = k = 1;

    verts.push_back(VertexFormat(_centerPosition.x - 4.0f * _modelSize.x / 3.0f, _centerPosition.y - 1.0f, _centerPosition.z - 4.0f * _modelSize.z / 3.0f, 0, 0, 1, 0.5f));
    colors.push_back(glm::vec4(0, 0, 1, 0.5f));
    for (int i = 0; i <= 10; i++) {
      float angle = 2.0f * PI * float(i) / float(10);
      verts.push_back(VertexFormat(_centerPosition.x - 4.0f * _modelSize.x / 3.0f + glm::cos(angle) * _modelSize.x, _centerPosition.y - 1.0f,
        _centerPosition.z - 4.0f * _modelSize.z / 3.0f + glm::sin(angle) * _modelSize.z, 0, 0, 1, 0.5f));
      colors.push_back(glm::vec4(0, 0, 1, 0.5f));
    }

    for (int i = 0; i < verts.size() - 2; i += 2) {
      indx.push_back(glm::uvec3(0, i + 1, i + 2));
      indx.push_back(glm::uvec3(i + 2, i + 3, 0));
    }

    //vao
    glGenVertexArrays(1, &_circleVao);
    glBindVertexArray(_circleVao);

    //vbo
    glGenBuffers(1, &_circleVbo);
    glBindBuffer(GL_ARRAY_BUFFER, _circleVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * verts.size(), &verts[0], GL_STATIC_DRAW);

    //ibo
    glGenBuffers(1, &_circleIbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _circleIbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indx.size() * 3, &indx[0], GL_STATIC_DRAW);

    int pipe = glGetAttribLocation(_glProgramShader, "in_position");
    glEnableVertexAttribArray(pipe);
    glVertexAttribPointer(pipe, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), static_cast<void*>(nullptr));

    //colorsVBO
    glGenBuffers(1, &_circleColorsVbo);
    glBindBuffer(GL_ARRAY_BUFFER, _circleColorsVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * colors.size(), &colors[0], GL_STATIC_DRAW);

    pipe = glGetAttribLocation(_glProgramShader, "in_color");
    glEnableVertexAttribArray(pipe);
    glVertexAttribPointer(pipe, 4, GL_FLOAT, GL_FALSE, 0, 0);

    _circleNumIndices = (unsigned int)indx.size() * 3;
  }

  void reposition()
  {
    //if (!_collision) {
    int noNeighbors = 0;
    for (auto agent = _swarmReference.begin(); agent != _swarmReference.end(); ++agent) {
      if ((*agent)->getAgentIndex() == _agentIndex) continue;
      glm::vec3 neighborPosition = (*agent)->getCenterPosition();
      if (glm::distance(neighborPosition, _centerPosition) < _modelSize.x * 2.0f) {
        noNeighbors++;
        float distanceX = fabs(_centerPosition.x - neighborPosition.x);
        float distanceZ = fabs(_centerPosition.z - neighborPosition.z);

        float offsetX = distanceX / 10;
        float offsetZ = distanceZ / 10;

        float newDistX = fabs(_centerPosition.x + offsetX - neighborPosition.x);
        float newDistZ = fabs(_centerPosition.z + offsetZ - neighborPosition.z);

        if (newDistX > _modelSize.x * 3.0f) {
          newDistX = (newDistX - _modelSize.x * 3.0f) / 2.0f;
        }

        if (newDistZ > _modelSize.z * 3.0f) {
          newDistZ = (newDistZ - _modelSize.z * 3.0f) / 2.0f;
        }

        if (newDistX > distanceX && (_centerPosition.x + offsetX < _maxX)) {
          _modelMatrix = glm::translate(_modelMatrix, glm::vec3(offsetX, 0, 0));
          _circleModelMatrix = glm::translate(_circleModelMatrix, glm::vec3(offsetX, 0, 0));

          _centerPosition.x += offsetX;
        }
        else if (_centerPosition.x - offsetX > _minX) {
          _modelMatrix = glm::translate(_modelMatrix, glm::vec3(-offsetX, 0, 0));
          _circleModelMatrix = glm::translate(_circleModelMatrix, glm::vec3(-offsetX, 0, 0));

          _centerPosition.x -= offsetX;
        }

        if (newDistZ > distanceZ && (_centerPosition.z + offsetZ < _maxZ)) {
          _modelMatrix = glm::translate(_modelMatrix, glm::vec3(0, 0, offsetZ));
          _circleModelMatrix = glm::translate(_circleModelMatrix, glm::vec3(0, 0, offsetZ));

          _centerPosition.z += offsetZ;
        }
        else if (_centerPosition.z - offsetZ > _minZ) {
          _modelMatrix = glm::translate(_modelMatrix, glm::vec3(0, 0, -offsetZ));
          _circleModelMatrix = glm::translate(_circleModelMatrix, glm::vec3(0, 0, -offsetZ));
          _centerPosition.z -= offsetZ;
        }
      }
    }
  }

  void getFollowers() {
    _followers = 0;
    for (auto agent = _swarmReference.begin(); agent != _swarmReference.end(); ++agent) {
      if ((*agent)->hasSpecificLeader(this)) {
        _followers++;
      }
    }
  }

  void adoptAgents()
  {
    Agent3D* newLeader = NULL;
    if (_isLeader) {
      for (auto agent = _neighborsList.begin(); agent != _neighborsList.end(); ++agent) {
        auto agentSpeed = (*agent)->getSpeed();
        if (glm::distance(agentSpeed, _speed) < ((((100.0f - _adoptionThreshold) * _collisionSpeed)) / 100.0f)) {
          (*agent)->setLeader(this);
        }
      }
      return;
    }

    int neighborsWithLeader = 0;
    for (auto agent = _neighborsList.begin(); agent != _neighborsList.end(); ++agent) {

      if ((*agent)->isLeader()) {
        setLeader((*agent));
        return;
      }

      auto agentSpeed = (*agent)->getSpeed();
      if ((*agent)->hasLeader() && (glm::distance(agentSpeed, _speed) < ((((100.0f - _adoptionThreshold) * _collisionSpeed)) / 100.0f))) {
        neighborsWithLeader++;
        newLeader = (*agent)->getLeader();
      }
    }

    if (neighborsWithLeader >= 2/* ((5.0 * _neighborsList.size()) / 10) && neighborsWithLeader > 0*/)
    {
      setLeader(newLeader);
      return;
    }
  }

  glm::vec3 getModelSize()
  {
    return _modelSize;
  }

  void checkForCollision()
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

  void startInfluenceTimer()
  {
    time(&_influenceStartTimer);
    _startTimer = true;
  }

  bool isInfluenceTimerOn()
  {
    return _startTimer;
  }

  time_t getStartInfluenceTimer()
  {
    return _influenceStartTimer;
  }

  void stopInfluenceTimer()
  {
    _startTimer = false;
  }

  void startTimerNoLeader()
  {
    _startTimerNoLeader = true;
    time(&_noLeaderTimer);
  }

  void stopTimerNoLeader()
  {
    _startTimerNoLeader = false;
  }


  void checkNoLeader()
  {
    if (_startTimerNoLeader) {
      time_t crtTime;
      time(&crtTime);
      if (difftime(crtTime, _noLeaderTimer) > _leaderLifeSpan) {
        resetLeader();
        _isLeader = false;
        _speed = _startSpeed;
      }
    }
  }

  std::vector<Agent3D*> getFollowersInSwarm()
  {
    std::vector<Agent3D*> followersInSwarm;
    std::vector<Agent3D*> neighbors = getNeighbors();
    while (neighbors.size() > 0) {
      Agent3D* agent = neighbors.front();
      neighbors.erase(neighbors.begin());
      if (agent->hasSpecificLeader(this) &&
        std::find(followersInSwarm.begin(), followersInSwarm.end(), agent) == followersInSwarm.end()) {
        followersInSwarm.push_back(agent);

        std::vector<Agent3D*> newNeighbors = agent->getNeighbors();
        for (auto newAgent = newNeighbors.begin(); newAgent != newNeighbors.end(); ++newAgent)
        {
          if (std::find(followersInSwarm.begin(), followersInSwarm.end(), (*newAgent)) == followersInSwarm.end())
          {
            neighbors.push_back((*newAgent));
          }
        }

      }
    }
    return followersInSwarm;
  }

  void checkFollowersInSameSwarm()
  {
    std::vector<Agent3D*> followersInSwarm = getFollowersInSwarm();

    for (auto agent = _swarmReference.begin(); agent != _swarmReference.end(); ++agent)
    {
      if (!(*agent)->hasSpecificLeader(this)) continue;

      if (std::find(followersInSwarm.begin(), followersInSwarm.end(), (*agent)) == followersInSwarm.end())
      {
        glm::vec3 neighborPosition = (*agent)->getCenterPosition();
        if (glm::distance(_centerPosition, neighborPosition) > _influenceDistance.x)
        {
          if (!(*agent)->isInfluenceTimerOn()) {
            (*agent)->startInfluenceTimer();
          }
          else {
            time_t crtTime;
            time(&crtTime);
            if (difftime(crtTime, (*agent)->getStartInfluenceTimer()) > _influenceTime) {
              (*agent)->resetLeader();
            }
          }
        }
        else {
          (*agent)->stopInfluenceTimer();
        }
      }
      else {
        (*agent)->stopInfluenceTimer();
      }
    }
  }

  void checkIfStillLeader()
  {
    time_t currentTime;
    time(&currentTime);
    bool isStillLeader = difftime(currentTime, _leaderLifeTimer) < _leaderLifeTime;

    if (!isStillLeader) {
      for (auto agent = _swarmReference.begin(); agent != _swarmReference.end(); agent++)
      {
        if ((*agent)->getLeader() == this)
        {
          (*agent)->resetLeader();
        }
      }
    }

    setAsLeader(isStillLeader);
  }

  void move()
  {
    checkForCollision();

    if (_collision) {
      resetLeader();
      _reposition = false;
      float distFromMinMarginX = fabs(_centerPosition.x - _minX);
      float distFromMaxMarginX = fabs(_centerPosition.x - _maxX);
      float distFromMinMarginZ = fabs(_centerPosition.z - _minZ);
      float distFromMaxMarginZ = fabs(_centerPosition.z - _maxZ);
      float distFromMinMarginY = fabs(_centerPosition.y - _minY);
      float distFromMaxMarginY = fabs(_centerPosition.y - _maxY);

      float speedXThreshold = _modelSize.x * 15;
      float speedZThreshold = _modelSize.x * 15;
      float speedYThreshold = _modelSize.x * 15;

      switch (_collisionType) {
      case 1:
        if (distFromMinMarginX > speedXThreshold) {
          _collision = false;
        }
        break;

      case 2:
        if (distFromMaxMarginX > speedXThreshold) {
          _collision = false;
        }
        break;

      case 3:
        if (distFromMinMarginZ > speedZThreshold) {
          _collision = false;
        }
        break;

      case 4:
        if (distFromMaxMarginZ > speedZThreshold) {
          _collision = false;
        }
        break;


      case 5:
        if (distFromMinMarginY > speedYThreshold) {
          _collision = false;
        }
        break;


      case 6:
        if (distFromMaxMarginY > speedYThreshold) {
          _collision = false;
        }
        break;
      }
    }

    if (!_collision) {
      bool leaderSpeed = false;
      setCollisionType(0);
      glm::vec3 neighborSpeed = getNeighborMeanSpeed();
      if (_isLeader) {
        getFollowers();
        checkFollowersInSameSwarm();
        checkIfStillLeader();
        if (_followers > 5) {
          stopTimerNoLeader();
          if ((_speed.x < 0 && _leaderSpeed.x > 0) || (_speed.x > 0 && _leaderSpeed.x < 0)) {
            _leaderSpeed.x = -_leaderSpeed.x;
          }

          if ((_speed.z < 0 && _leaderSpeed.z > 0) || (_speed.z > 0 && _leaderSpeed.z < 0)) {
            _leaderSpeed.z = -_leaderSpeed.z;
          }

          _speed = _leaderSpeed * (float(_followers) / (float)_swarmSize) + neighborSpeed * (1.0f - (float(_followers) / (float)_swarmSize));
          leaderSpeed = true;
        }
        else {
          if (!_startTimerNoLeader) {
            startTimerNoLeader();
          }
          else {
            checkNoLeader();
          }
        }
      }

      if (hasLeader()) {
        _speed = _speed * 0.4f + _leader->getSpeed() * 0.6f;
      }

      else {
        if (!leaderSpeed && (neighborSpeed.x > 0.0005f || neighborSpeed.y > 0.0005f || neighborSpeed.z > 0.0005f)) {
          _speed = _speed * 0.5f + neighborSpeed * 0.5f;
        }
      }
    }

    _modelMatrix = glm::translate(_modelMatrix, _speed);
    _circleModelMatrix = glm::translate(_circleModelMatrix, _speed);
    _centerPosition += _speed;

    reposition();
  }

  void setSwarmCenter(glm::vec3 swarmCenter)
  {
    _swarmCenter = swarmCenter;
  }

  ~Agent3D(void)
  {

  }
};
