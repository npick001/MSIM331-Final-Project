#ifndef COMPUTER_H
#define COMPUTER_H

#include "Distribution.h"
#include "Message.h"
#include "Network.h"
#include "SimulationExecutive.h"
#include "FIFO.h"
#include <vector>

class Network;

class Computer {
public:
    Computer(Triangular& serviceTimeDist, Exponential& msgGenRateDist, const std::vector<int>& edges, int id);
    void SetNetwork(Network* _network);
    void AddMessageToSource(Message* message);
    int GetQueueSize();
    void ReportStatistics();
    int getId() const;

    std::vector<int> edges;
private:
    // Event methods
    class GenerateMessageEA;
    class ArriveEA;
    class StartServiceEA;
    class DoneServiceEA;
    void GenerateMessageEM();
    void ArriveEM(Message* message);
    void StartServiceEM();
    void DoneServiceEM(Message* message);
    void ProcessMessage(); // Add the ProcessMessage method declaration

    // Member variables
    Triangular& _serviceTimeDist;
    Exponential& _msgGenRateDist;
    int _id;
    int _connectedEdges;
    FIFO<Message>* _serviceQueue;
    bool _available;
    Network* _computerNetwork;
};

#endif // COMPUTER_H
