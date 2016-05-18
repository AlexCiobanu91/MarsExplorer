#pragma once
#include "Includes.h"
#include "Definitions.h"
#include "Structures.h"
#include "Utils.h"
#include "Camera.hpp"
#include "SearchAgent.h"
#include "CarrierAgent.h"
#include "BaseAgent.h"
#include "ObstacleAgent.h"
#include "Container.h"
#include "ShaderLoader.h"

namespace MarsExplorer {

  void CloseGLContext();

  void IdleGLContext();

  void DoMovements();

  void InitMouseMovements();

  void CreateCameras();

  void InitSwarm();

  void InitShaders();

  void InitKeyboard();

  void Init();

  void Unload();

  void RenderSwarm();

  void SetViewProjectionMatrix();

  void NotifyBeginFrame();

  void NotifyEndFrame();

  void NotifyDisplayFrame();

  void NotifyReshape(int width, int height);

  void NotifyKeyPressed(unsigned char key_pressed, int mouse_x, int mouse_y);

  void NotifyKeyReleased(unsigned char key_released, int mouse_x, int mouse_y);

  void NotifySpecialKeyPressed(int key_pressed, int mouse_x, int mouse_y);

  void NotifySpecialKeyReleased(int key_released, int mouse_x, int mouse_y);

  void NotifyMouseDrag(int mouse_x, int mouse_y);

  void NotifyMouseMove(int mouse_x, int mouse_y);

  void NotifyMouseClick(int button, int state, int mouse_x, int mouse_y);

  void NotifyMouseScroll(int wheel, int direction, int mouse_x, int mouse_y);

  void InitGLContext(const WindowInfo &window, const ContextInfo &context, const FramebufferInfo &framebuffer);

  void Load();

  void setSwarmSize(int swarmSize);

  void setCenterDistance(float centerDistance);

  void setSwarmDirection(int x, int y, int z);

  void setAgentDistance(float agentDistance);

  void setDistanceThreshold(float distanceThreshold);

  void disableStart();

  void AddDelay(float delay);

  void SetRepresentationType(bool type);

  void setModelSize(float x, float y, float z);

  void setNoLeaders(int noLeaders);

  void setLeaderSpawnRate(float spawnRate);

  void setLeaderLifeTime(float lifeTime);

  void setInitialDelay(float delay);

  void setSimulationTime(float simulationTime);

  void setOutputFile(System::String^ outputFile);

  void DoResearch();
}