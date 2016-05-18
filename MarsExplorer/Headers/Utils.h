#pragma once
#include "Includes.h"
#include "Agent3D.h"

namespace MarsExplorer
{
  class Utils
  {
  public:
    static void printAgentsWithoutLeaders(std::vector<Agent3D*> &swarmReference, std::ofstream &outFile, time_t startTime)
    {

      int noLeaderWithoutLeader = 0;
      for (auto agent = swarmReference.begin(); agent != swarmReference.end(); agent++)
      {
        if (!(*agent)->hasLeader())
        {
          noLeaderWithoutLeader++;
        }
      }

      time_t currentTime;
      time(&currentTime);

      double timePassed = difftime(currentTime, startTime);

      outFile << timePassed << ", " << noLeaderWithoutLeader << std::endl;

    }

    static bool closeSimulation(time_t startTime, double simulationTime)
    {
      time_t currentTime;
      time(&currentTime);
      return difftime(currentTime, startTime) > simulationTime;
    }


    static void printNumberOfAgentsPerLeader(std::vector<Agent3D*> &swarmReference, std::ofstream &outFile, time_t startTime)
    {

      time_t currentTime;
      time(&currentTime);
      double timePassed = difftime(currentTime, startTime);

      int agentNo = 0;
      for (auto agent = swarmReference.begin(); agent != swarmReference.end(); agent++)
      {
          if (!(*agent)->isLeader()) continue;

          agentNo ++;
          int agents = 0;
          for (auto otherAgent = swarmReference.begin(); otherAgent != swarmReference.end(); otherAgent++)
          {
            if (otherAgent == agent) continue;
            if ((*otherAgent)->getLeader() == (*agent))
            {
              agents ++;
            }
          }

          outFile << agentNo << ", " << agents << ", " << timePassed << std::endl;
      }
    }

  };
}