#pragma once
#include "..\Headers\MarsExplorer.h"

namespace MarsExplorer
{
  int swarmSize, noLeaders, selectedLeaders;
  float agentDistance, distanceThreshold;
  float moveRadius, moveStep;
  float startX, startZ, startY;
  float thresholdX, thresholdY, thresholdZ;
  float speedX, speedY, speedZ;

  float centerDistance;
  int xpos, ypos, zpos, angle;
  int lastx, lasty;
  float level;

  float aspectRatio = 0.0f;
  float horizontalAngle = 3.14f;
  // vertical angle : 0, look at the horizon
  float verticalAngle = 0.0f;
  // Initial Field of View
  float initialFoV = 45.0f;


  float foV;
  float speed = 9.0f; // 3 units / second
  float mouseSpeed = 0.005f;
  float zoomSpeed = 0.3f;
  float mouseZoom = 0;
  float maxMouseZoom = 0.7f;
  float minMouseZoom = -0.7f;
  float delay = 0;
  float simulationTime = 0;

  float leaderSpawnRate = 10;
  float leaderLifeTime = 20;
  float initialDelay = 20;
  int noFrames = 0;

  static bool bMouseMove = true;
  static bool bStart = false;

  bool spawnLeaders = false;
  bool worldCamOn;
  std::vector<Agent*> agents;
  std::vector<ObstacleAgent*> cristals;
  std::vector<ObstacleAgent*> obstacles;
  BaseAgent* baseAgent;

  glm::vec3 worldCameraPos;
  glm::vec3 worldCameraCenter;
  glm::vec3 winCameraPos;
  glm::vec3 winCameraCenter;
  glm::vec3 right, up, direction, eyePosition;
  glm::vec3 swarmDirection;
  glm::vec3 modelSize;
  glm::mat4 matProjection;
  glm::mat4 matModel, matView;
  glm::vec4 mapSize;
  Camera *worldCamera;
  Container *container;
  unsigned int gl_program_shader, gl_program_shader_tex;
  unsigned int screen_width, screen_height;
  unsigned int texBackground, texSearchAgent, texCarrierAgent, texBase, texObstacle, texCristal;



  bool* boolStariTaste;
  bool* boolStariSpeciale;
  bool represenationType;

  WindowInfo _window_information;					//aici sunt tinute informatii despre fereastra
  FramebufferInfo _framebuffer_information;		//aici sunt tinute informatii despre framebuffer
  ContextInfo _context_information;				//aici sunt tinute informatii despre context


  time_t startTime;
  time_t lastSpawnTime;

  //nu suporta compresie! 
  //incarca un fisier BMP intr-un array unsigned char
  //returneaza un pointer la un array ce contine datele texturii si valori in argumentele trimise prin referinta width si height
  unsigned char* _loadBMPFile(const std::string &filename, unsigned int &width, unsigned int &height) {
	  //structuri pentru datele din header
	  struct header {
		  unsigned char type[2];
		  int f_lenght;
		  short rezerved1;
		  short rezerved2;
		  int offBits;
	  };
	  struct header_info {
		  int size;
		  int width;
		  int height;
		  short planes;
		  short bitCount;
		  int compresion;
		  int sizeImage;
		  int xPelsPerMeter;
		  int yPelsPerMeter;
		  int clrUsed;
		  int clrImportant;
	  };

	  //citim din fisier
	  std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary);
	  if (!file.good()) {
		  std::cout << "Texture Loader: Nu am gasit fisierul bmp " << filename << " sau nu am drepturile sa il deschid!" << std::endl;
		  width = 0;
		  height = 0;
		  return NULL;
	  }
	  std::cout << "Texture Loader: Incarc fisierul " << filename << std::endl;


	  //citesc headere
	  header h; header_info h_info;
	  file.read((char*)&(h.type[0]), sizeof(char));
	  file.read((char*)&(h.type[1]), sizeof(char));
	  file.read((char*)&(h.f_lenght), sizeof(int));
	  file.read((char*)&(h.rezerved1), sizeof(short));
	  file.read((char*)&(h.rezerved2), sizeof(short));
	  file.read((char*)&(h.offBits), sizeof(int));
	  file.read((char*)&(h_info), sizeof(header_info));

	  //aloc memorie (un pixel are 3 componente R, G, B)
	  unsigned char *data = new unsigned char[h_info.width*h_info.height * 3];

	  // verific daca exista grupuri de 4 octeti pe linie
	  long padd = 0;
	  if ((h_info.width * 3) % 4 != 0) padd = 4 - (h_info.width * 3) % 4;

	  //save height &width
	  width = h_info.width;
	  height = h_info.height;

	  long pointer;
	  unsigned char r, g, b;
	  //citesc matricea
	  for (unsigned int i = 0; i < height; i++)
	  {
		  for (unsigned int j = 0; j < width; j++)
		  {
			  file.read((char*)&b, 1);	//in bmp ordinea in pixel este b,g,r (specific windows)
			  file.read((char*)&g, 1);
			  file.read((char*)&r, 1);

			  pointer = ((height - i - 1)*width + j) * 3;
			  //pointer = (i*width + j) * 3;
			  data[pointer] = r;
			  data[pointer + 1] = g;
			  data[pointer + 2] = b;
		  }

		  file.seekg(padd, std::ios_base::cur);
	  }
	  file.close();

	  //returneaza datele
	  return data;
  }

  //incarca o imagine BMP si creeaza cu ea o textura
  //aceasta este functia pe care o veti apela
  //returneaza id-ul texturii
  unsigned int loadTextureBMP(const std::string &filename) {

	  unsigned int width, height;
	  unsigned char* data = _loadBMPFile(filename, width, height);

	  //creeaza textura OpenGL
	  unsigned int gl_texture_object;
	  glGenTextures(1, &gl_texture_object);
	  glBindTexture(GL_TEXTURE_2D, gl_texture_object);

	  //filtrare
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	  float maxAnisotropy;
	  glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);

	  //cand lucram cu texturi cu dimensiuni non multiple de 4 trebuie sa facem cititorul de randuri
	  //ce incarca texturile in OpenGL sa lucreze cu memorie aliniata la 1 (default este la 4)
	  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	  //genereaza textura
	  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	  //distruge array-ul din RAM
	  delete data;

	  //creaza ierarhia de mipmapuri
	  glGenerateMipmap(GL_TEXTURE_2D);

	  //returneaza obiectul textura
	  return gl_texture_object;
  }

  /* incarca 6 imagini BMP si creeaza cu ele un cubemap */
  unsigned int loadTextureCubemapBMP(const std::string &posx, const std::string &posy, const std::string &posz, const std::string& negx, const std::string& negy, const std::string& negz) {

	  unsigned int width, height;
	  unsigned char* data_posx = _loadBMPFile(posx, width, height);
	  unsigned char* data_posy = _loadBMPFile(posy, width, height);
	  unsigned char* data_posz = _loadBMPFile(posz, width, height);
	  unsigned char* data_negx = _loadBMPFile(negx, width, height);
	  unsigned char* data_negy = _loadBMPFile(negy, width, height);
	  unsigned char* data_negz = _loadBMPFile(negz, width, height);

	  //creeaza textura OpenGL
	  unsigned int gl_texture_object;
	  glGenTextures(1, &gl_texture_object);
	  glBindTexture(GL_TEXTURE_CUBE_MAP, gl_texture_object);

	  //filtrare
	  glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	  float maxAnisotropy;
	  glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);

	  //cand lucram cu texturi cu dimensiuni non multiple de 4 trebuie sa facem cititorul de randuri
	  //ce incarca texturile in OpenGL sa lucreze cu memorie aliniata la 1 (default este la 4)
	  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	  //adauga date
	  glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data_posx);
	  glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data_posy);
	  glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data_posz);
	  glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data_negx);
	  glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data_negy);
	  glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data_negz);

	  //distruge array-ul din RAM
	  delete data_posx;
	  delete data_posy;
	  delete data_posz;
	  delete data_negx;
	  delete data_negy;
	  delete data_negz;

	  glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

	  //returneaza obiectul textura
	  return gl_texture_object;
  }


  void initTextures()
  {
	  texBackground = loadTextureBMP("Resources\\Textures\\Background.bmp");
	  texSearchAgent = loadTextureBMP("Resources\\Textures\\SearchAgent.bmp");
	  texCarrierAgent = loadTextureBMP("Resources\\Textures\\CarrierAgent.bmp");
	  texBase = loadTextureBMP("Resources\\Textures\\Base.bmp");
	  texObstacle = loadTextureBMP("Resources\\Textures\\Obstacle.bmp");
	  texCristal = loadTextureBMP("Resources\\Textures\\Cristal.bmp");
  }


  std::ofstream outputFile;
  void setModelSize(float x, float y, float z)
  {
      MarsExplorer::modelSize = glm::vec3(x, y, z);
  }

  void setNoLeaders(int noLeaders)
  {
    MarsExplorer::noLeaders = noLeaders;
  }

  void setLeaderSpawnRate(float spawnRate)
  {
    MarsExplorer::leaderSpawnRate = spawnRate;
  }

  void setLeaderLifeTime(float lifeTime)
  {
    MarsExplorer::leaderLifeTime = lifeTime;
  }

  void setInitialDelay(float initialDelay)
  {
    MarsExplorer::initialDelay = initialDelay;
  }

  void setSimulationTime(float simulationTime)
  {
    MarsExplorer::simulationTime = simulationTime;
  }

  void setOutputFile(System::String^ outputFile)
  {
    std::string converted = msclr::interop::marshal_as< std::string >(outputFile);
    MarsExplorer::outputFile.open(converted);

  }

  void setSwarmDirection(int x, int y, int z)
  {
    swarmDirection = glm::vec3(x, y, z);
  }

  void setSwarmSize(int swarmSize)
  {
    MarsExplorer::swarmSize = swarmSize;
  }

  void setCenterDistance(float centerDistance)
  {
    MarsExplorer::centerDistance = centerDistance;
  }

  void disableStart()
  {
    bStart = false;
  }

  void setAgentDistance(float agentDistance)
  {
    MarsExplorer::agentDistance = agentDistance;
  }

  void setDistanceThreshold(float distanceThreshold)
  {
    MarsExplorer::distanceThreshold = distanceThreshold;
  }

  void CloseGLContext() {
    std::cout << "GLUT:\tTerminat" << std::endl;
    glutLeaveMainLoop();
  }

  void AddDelay(float delay)
  {
    MarsExplorer::delay = delay;
  }

  void SetRepresentationType(bool type)
  {
    represenationType = type;
  }

  void IdleGLContext()
  {
    glutPostRedisplay();
  }

  void DoMovements()
  {
    if (boolStariSpeciale[GLUT_KEY_RIGHT]) {
      eyePosition += right * speed;
      matView = glm::lookAt(eyePosition, eyePosition + direction, up);
    }
    if (boolStariSpeciale[GLUT_KEY_LEFT]) {
      eyePosition -= right * speed;
      matView = glm::lookAt(eyePosition, eyePosition + direction, up);
    }
    if (boolStariSpeciale[GLUT_KEY_UP]) {
      eyePosition += direction * speed;
      matView = glm::lookAt(eyePosition, eyePosition + direction, up);
    }
    if (boolStariSpeciale[GLUT_KEY_DOWN]) {
      eyePosition -= direction * speed;
      matView = glm::lookAt(eyePosition, eyePosition + direction, up);
    }
    std::cout << eyePosition.x << " " << eyePosition.y << " " << eyePosition.z << std::endl;
  }

  void InitMouseMovements()
  {
    RECT actualDesktop;
    GetWindowRect(GetDesktopWindow(), &actualDesktop);

    //pentru miscarea camerei dupa mouse
    xpos = actualDesktop.right / 2;		ypos = actualDesktop.bottom / 2;
    lastx = actualDesktop.right / 2;	lasty = actualDesktop.bottom / 2;

    verticalAngle = 0.0f;
    horizontalAngle = 3.145f;

    direction = glm::vec3(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(horizontalAngle));
    right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0.0f, cos(horizontalAngle - 3.14f / 2.0f));
    up = glm::cross(right, direction);

    foV = initialFoV;
  }

  void CreateCameras()
  {
    eyePosition = glm::vec3(3900, 9550, 200);

    matView = glm::lookAt(eyePosition, glm::vec3(1000, 100, 1000), glm::vec3(0, 1, 0));
  }

  void InitAgents()
  {
	  agents.clear();
	  for (auto i = 0; i < swarmSize; ++i)
	  {
		  speedX = (rand() % 2 == 0 ? -1.0f : 1.0f) * 40.0f;
		  speedY = 0;
		  speedZ = (rand() % 2 == 0 ? -1.0f : 1.0f) * 40.0f;

		  auto centerX = 12900 - (rand() % 18000);
		  auto centerY = 0.1;
		  auto centerZ = 5000 - (rand() % 9900);

		  auto agentSpeed = glm::vec3(speedX, speedY, speedZ);
		  auto modelCenterPosition = glm::vec3(centerX, centerY, centerZ);

		  agents.push_back(new SearchAgent(gl_program_shader_tex, modelSize, modelCenterPosition, i, agentSpeed, mapSize, texSearchAgent));
 }
  }

  void InitCristals()
  {
	  cristals.clear();
	  for (auto i = 0; i < swarmSize; ++i)
	  {
		  glm::vec3 modelCenterPosition;
		  bool coliding = false;
		  
		  while (true) {
			  auto centerX = 12900 - (rand() % 18000);
			  auto centerY = 0.1;
			  auto centerZ = 5000 - (rand() % 9900);

			  for (int j = 0; j < cristals.size(); j++)
			  {
				  if (glm::distance(glm::vec3(centerX, centerY, centerZ), cristals[j]->getPosition()) < modelSize.x * 2)
				  {
					  coliding = true;
				  }

				  if (coliding)
				  {
					  break;
				  }
			  }

			  if (glm::distance(glm::vec3(centerX, centerY, centerZ), baseAgent->getPosition()) < baseAgent->getModelSize().x * 2)
			  {
				  coliding = true;
			  }

			  if (!coliding) {
				  modelCenterPosition = glm::vec3(centerX, centerY, centerZ);
				  break;
			  }
		  }

		  auto agentSpeed = glm::vec3(speedX, speedY, speedZ);
		  cristals.push_back(new ObstacleAgent(gl_program_shader_tex, modelSize, modelCenterPosition, i, mapSize, texCristal, true));
	  }
  }

  void InitObstacles()
  {
	  obstacles.clear();
	  for (auto i = 0; i < swarmSize; ++i)
	  {
		  glm::vec3 modelCenterPosition;
		  

		  while (true) {
			  bool coliding = false;
			  auto centerX = 12900 - (rand() % 18000);
			  auto centerY = 0.1;
			  auto centerZ = 5000 - (rand() % 9900);

			  for (int j = 0; j < cristals.size(); j++)
			  {
				  if (glm::distance(glm::vec3(centerX, centerY, centerZ), cristals[j]->getPosition()) < modelSize.x * 2)
				  {
					  coliding = true;
				  }

				  if (coliding)
				  {
					  break;
				  }
			  }

			  if (coliding)
			  {
				  continue;
			  }

			  for (int j = 0; j < obstacles.size(); j++)
			  {
				  if (glm::distance(glm::vec3(centerX, centerY, centerZ), obstacles[j]->getPosition()) < modelSize.x * 2)
				  {
					  coliding = true;
				  }

				  if (coliding)
				  {
					  break;
				  }
			  }

			  if (coliding)
			  {
				  continue;
			  }

			  if (glm::distance(glm::vec3(centerX, centerY, centerZ), baseAgent->getPosition()) < baseAgent->getModelSize().x * 2)
			  {
				  coliding = true;
			  }

			  if (!coliding) {
				  modelCenterPosition = glm::vec3(centerX, centerY, centerZ);
				  break;
			  }
		  }

		  auto agentSpeed = glm::vec3(speedX, speedY, speedZ);
		  obstacles.push_back(new ObstacleAgent(gl_program_shader_tex, modelSize, modelCenterPosition, i, mapSize, texObstacle, false));
	  }
  }

  void InitSwarm()
  {
	  baseAgent = new BaseAgent(gl_program_shader_tex, glm::vec3(1000, 500, 1000), glm::vec3(-4000, 0, -4000), mapSize, texBase);  
	  InitObstacles();
	  InitCristals();
	  InitAgents();
  }

  void InitShaders()
  {
    gl_program_shader = loadShader("Shaders\\shader_vertex.glsl", "Shaders\\shader_fragment.glsl");
	gl_program_shader_tex = loadShader("Resources\\Shaders\\vertex_shader.glsl", "Resources\\Shaders\\fragment_shader.glsl");
  }

  void InitKeyboard()
  {
    boolStariTaste = new bool[256];
    boolStariSpeciale = new bool[256];

    for (int i = 0; i < 255; i++) {
      boolStariSpeciale[i] = false;
      boolStariTaste[i] = false;
    }
  }

  void CreateContainer()
  {
	  container = new Container(gl_program_shader_tex, glm::vec4(-5000, 13000, -5000, 5000), texBackground);
  }

  void InitMatrices()
  {
	  mapSize = glm::vec4(-5000, 13000, -5000, 5000);
  }

  void Init() {
    glClearColor(0.5, 0.5, 0.5, 1);
    glClearDepth(1);
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	InitMatrices();
    InitShaders();
	initTextures();
    CreateContainer();
    InitKeyboard();

    InitMouseMovements();
    InitSwarm();
    CreateCameras();


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glutFullScreenToggle();
  }

  void Unload() {
    //distruge shader
    glDeleteProgram(gl_program_shader);
  }

  void RenderAgents()
  {
	  for (auto agent = agents.begin(); agent != agents.end(); ++agent)
	  {
		  (*agent)->Draw();
	  }

	  for (auto agent = cristals.begin(); agent != cristals.end(); ++agent)
	  {
		  (*agent)->Draw();
	  }

	  for (auto agent = obstacles.begin(); agent != obstacles.end(); ++agent)
	  {
		  (*agent)->Draw();
	  }
  }

  void RenderContainer()
  {
	  container->Draw(matView, matProjection);
  }

  void SetViewProjectionMatrix()
  {
    matProjection = glm::perspective(foV, aspectRatio, 0.1f, 10000.0f);
    glUniformMatrix4fv(glGetUniformLocation(gl_program_shader, "view_matrix"), 1, false, glm::value_ptr(matView));
    glUniformMatrix4fv(glGetUniformLocation(gl_program_shader, "projection_matrix"), 1, false, glm::value_ptr(matProjection));

	glUniformMatrix4fv(glGetUniformLocation(gl_program_shader_tex, "view_matrix"), 1, false, glm::value_ptr(matView));
	glUniformMatrix4fv(glGetUniformLocation(gl_program_shader_tex, "projection_matrix"), 1, false, glm::value_ptr(matProjection));

  }

  void NotifyBeginFrame()
  {
	  time_t currentTime;
	  time(&currentTime);

	  if (Utils::closeSimulation(startTime, simulationTime))
	  {
		  glutLeaveMainLoop();
		  outputFile.close();
	  }
  }

  void NotifyEndFrame()
  {

  }

  void NotifyDisplayFrame()
  {
	  NotifyBeginFrame();

	  //pe tot ecranul
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	  glUseProgram(gl_program_shader_tex);

	  SetViewProjectionMatrix();
	  RenderContainer();
	  baseAgent->Draw();

	  //glUseProgram(gl_program_shader);
	  RenderAgents();
	  DoMovements();

	  glutSwapBuffers();

	  NotifyEndFrame();
  }

  //functie care e chemata cand se schimba dimensiunea ferestrei initiale
  void NotifyReshape(int width, int height)
  {
    //reshape
    if (height == 0) height = 1;
    screen_width = width;
    screen_height = height;
    aspectRatio = (float)width / (float)height;
    glViewport(0, 0, screen_width, screen_height);
    matProjection = glm::perspective(foV, aspectRatio, 0.1f, 10000.0f);

    _window_information.width = width;
    _window_information.height = height;
  }

  //tasta apasata
  void NotifyKeyPressed(unsigned char key_pressed, int mouse_x, int mouse_y)
  {
    if (key_pressed == 27) {
      CloseGLContext();
    }

    if (key_pressed == 'w') {
      static bool wire = true;
      wire = !wire;
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    //if (key_pressed == 'q') {
   ////   bMouseMove = !bMouseMove;
   // }

    if (key_pressed == 's') {
      bStart = !bStart;
    }


  }

  //tasta ridicata
  void NotifyKeyReleased(unsigned char key_released, int mouse_x, int mouse_y)
  {	}

  //tasta speciala (up/down/F1/F2..) apasata
  void NotifySpecialKeyPressed(int key_pressed, int mouse_x, int mouse_y)
  {
    switch (key_pressed) {
    case GLUT_KEY_RIGHT:
      boolStariSpeciale[GLUT_KEY_RIGHT] = true;
      break;
    case GLUT_KEY_LEFT:
      boolStariSpeciale[GLUT_KEY_LEFT] = true;
      break;
    case GLUT_KEY_DOWN:
      boolStariSpeciale[GLUT_KEY_DOWN] = true;
      break;
    case GLUT_KEY_UP:
      boolStariSpeciale[GLUT_KEY_UP] = true;
      break;
    }

    if (key_pressed == GLUT_KEY_F1) glutFullScreenToggle();
  }

  //tasta speciala ridicata
  void NotifySpecialKeyReleased(int key_released, int mouse_x, int mouse_y)
  {
    switch (key_released) {
    case GLUT_KEY_RIGHT:
      boolStariSpeciale[GLUT_KEY_RIGHT] = false;
      break;
    case GLUT_KEY_LEFT:
      boolStariSpeciale[GLUT_KEY_LEFT] = false;
      break;
    case GLUT_KEY_DOWN:
      boolStariSpeciale[GLUT_KEY_DOWN] = false;
      break;
    case GLUT_KEY_UP:
      boolStariSpeciale[GLUT_KEY_UP] = false;
      break;
    }
  }

  //drag cu mouse-ul
  void NotifyMouseDrag(int mouse_x, int mouse_y)
  { }

  //am miscat mouseul (fara sa apas vreun buton)
  void NotifyMouseMove(int mouse_x, int mouse_y)
  {
    RECT actualDesktop;
    GetWindowRect(GetDesktopWindow(), &actualDesktop);

    if (bMouseMove) {
      xpos = mouse_x;
      ypos = mouse_y;

      if (xpos != lastx || ypos != lasty) {
        horizontalAngle += mouseSpeed * float(actualDesktop.right / 2 - xpos);
        verticalAngle += mouseSpeed * float(actualDesktop.bottom / 2 - ypos);

        direction = glm::vec3(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(horizontalAngle));
        right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0.0f, cos(horizontalAngle - 3.14f / 2.0f));
        up = glm::cross(right, direction);

        matView = glm::lookAt(eyePosition, eyePosition + direction, up);
        glutWarpPointer(actualDesktop.right / 2, actualDesktop.bottom / 2);

        lastx = mouse_x;
        lasty = mouse_y;
      }
    }
  }

  //am apasat pe un boton
  void NotifyMouseClick(int button, int state, int mouse_x, int mouse_y)
  { }

  //scroll cu mouse-ul
  void NotifyMouseScroll(int wheel, int direction, int mouse_x, int mouse_y)
  {
    /* if (direction > 0 && mouseZoom < maxMouseZoom)
    {
    foV -= zoomSpeed;
    mouseZoom -= zoomSpeed;
    }
    if (direction < 0 && mouseZoom > minMouseZoom)
    {
    foV += zoomSpeed;
    mouseZoom += zoomSpeed;
    }*/

  }

  void InitGLContext(const WindowInfo &window, const ContextInfo &context, const FramebufferInfo &framebuffer)
  {
    //copiaza informatie pentru fereastra,context,framebuffer
    _context_information = context;
    _window_information = window;
    _framebuffer_information = framebuffer;

    //cerem glut un context OpenGL
    glutInitContextVersion(context.major_version, context.minor_version);
    glutInitContextFlags(GLUT_DEBUG);
    if (context.core) glutInitContextProfile(GLUT_CORE_PROFILE);
    else glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    //argumente fake pentru ca nu folosim glut in linie de comanda
    int fakeargc = 1;		char *fakeargv[] = { "fake",NULL };
    glutInit(&fakeargc, fakeargv);
    glutInitDisplayMode(framebuffer.flags);
    glutInitWindowPosition(window.start_position_x, window.start_position_y);
    glutInitWindowSize(window.width, window.height);
    glutCreateWindow(window.name.c_str());

    //leaga functiile locale la GLUT
    glutIdleFunc(IdleGLContext);
    glutCloseFunc(CloseGLContext);
    glutDisplayFunc(NotifyDisplayFrame);
    glutReshapeFunc(NotifyReshape);
    glutKeyboardFunc(NotifyKeyPressed);
    glutKeyboardUpFunc(NotifyKeyReleased);
    glutSpecialFunc(NotifySpecialKeyPressed);
    glutSpecialUpFunc(NotifySpecialKeyReleased);
    glutMotionFunc(NotifyMouseDrag);
    glutPassiveMotionFunc(NotifyMouseMove);
    glutMouseFunc(NotifyMouseClick);
    glutMouseWheelFunc(NotifyMouseScroll);

    //scrie la consola diverse detalii utile
    const unsigned char* renderer = glGetString(GL_RENDERER);
    const unsigned char* vendor = glGetString(GL_VENDOR);
    const unsigned char* version = glGetString(GL_VERSION);
    std::cout << "*******************************************************************************" << std::endl;
    std::cout << "GLUT:initializare" << std::endl;
    std::cout << "GLUT:\tVendor : " << vendor << std::endl;
    std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
    std::cout << "GLUT:\tutilizez versiunea de OpenGl : " << version << std::endl;
    std::cout << "GLUT:\tFereasta initiala se numeste `" << window.name << "`, are dimensiunile  (" << window.width << "X" << window.height;
    std::cout << ") incepe de la coordonatele de ecran (" << window.start_position_x << "X" << window.start_position_y;
    std::cout << ") si " << ((window.is_reshapable) ? "este" : "nu este") << " redimensionabila" << std::endl;
    std::cout << "GLUT:\tFramebuffer initial contine buffere(duble) pentru" << std::endl;
    if (glutGet(GLUT_WINDOW_RGBA)) {
      int r_bits, g_bits, b_bits, a_bits;
      glGetIntegerv(GL_RED_BITS, &r_bits);	glGetIntegerv(GL_GREEN_BITS, &g_bits);
      glGetIntegerv(GL_BLUE_BITS, &b_bits);	glGetIntegerv(GL_ALPHA_BITS, &a_bits);
      std::cout << "\tCuloare R" << r_bits << "G" << g_bits << "B" << b_bits << "A" << a_bits << std::endl;
    }
    if (_framebuffer_information.flags&GLUT_DEPTH) {
      int d_bits;	glGetIntegerv(GL_DEPTH_BITS, &d_bits);
      std::cout << "\tAdancime DEPTH" << d_bits << std::endl;
    }
    if (_framebuffer_information.flags&GLUT_STENCIL) {
      int s_bits;	glGetIntegerv(GL_STENCIL_BITS, &s_bits);
      std::cout << "\tStencil STENCIL" << s_bits << std::endl;
    }
    if (_framebuffer_information.flags&GLUT_MULTISAMPLE) std::cout << "\tmultisampling cu 4 sample-uri per pixel" << std::endl;
    std::cout << "GLUT:\tContextul OpenGL este " << _context_information.major_version << "." << _context_information.minor_version;
    std::cout << " si profilul este de " << ((_context_information.core) ? "core" : "compatibilitate") << std::endl;
    std::cout << "*******************************************************************************" << std::endl;

    //cand glut este inchis este returnat la main pentru oportunitatea de cleanup corect
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

  }

  void Load() {
    //initializeaza GLUT (fereastra + input + context OpenGL)
    WindowInfo window(std::string("lab shadere 3 - camera"), 800, 600, 100, 100, true);
    ContextInfo context(3, 1, false);
    FramebufferInfo framebuffer(true, false, true, true);
    InitGLContext(window, context, framebuffer);

    // ignora tastele ce sunt tinute apasate
    glutIgnoreKeyRepeat(0);

    //initializeaza GLEW (ne incarca functiile openGL, altfel ar trebui sa facem asta manual!)
    glewExperimental = true;
    glewInit();
    std::cout << "GLEW:initializare" << std::endl;

    time(&startTime);
    //initializare
    Init();

    //run
    glutMainLoop();
  }
}
  
