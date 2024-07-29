#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// ClusterHead class to represent cluster heads
class ClusterHead {
public:
    std::string id;
    std::vector<std::string> assignedNodes;

    ClusterHead(const std::string& headId) : id(headId) {}

    void assignNode(const std::string& nodeId) {
        assignedNodes.push_back(nodeId);
    }
};

// Cluster class to manage cluster heads and their nodes
class Cluster {
public:
    std::vector<ClusterHead> clusterHeads;

    void addClusterHead(const ClusterHead& head) {
        clusterHeads.push_back(head);
    }

    void assignNodeToClusterHead(const std::string& headId, const std::string& nodeId) {
        for (auto& head : clusterHeads) {
            if (head.id == headId) {
                head.assignNode(nodeId);
                return;
            }
        }
        std::cout << "Cluster head not found: " << headId << std::endl;
    }
};

// Function to provide cluster heads
void provideCluster
