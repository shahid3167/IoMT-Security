#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

// Assuming the required header files for Algorithm 2 and 3 are included here
#include "registerIoMTNode.cpp"  // Including Algorithm 2
#include "provideClusterHead.cpp"  // Including Algorithm 3

// Main algorithm to integrate all functionalities
int main() {
    // Step 1: Initialize the Blockchain and Cluster
    std::cout << "Initializing the blockchain and cluster..." << std::endl;
    Blockchain blockchain;
    Cluster cluster;

    // Step 2: Register IoMT Nodes
    std::cout << "Registering IoMT nodes..." << std::endl;
    std::vector<IoMTNode> nodes;
    for (int i = 1; i <= 1100; ++i) {
        std::string nodeId = "node" + std::to_string(i);
        std::string nodeData = "data" + std::to_string(i);
        nodes.emplace_back(nodeId, nodeData);
        registerIoMTNode(blockchain, nodes.back());
    }

    // Step 3: Provide Cluster Heads
    std::cout << "Providing cluster heads..." << std::endl;
    std::vector<ClusterHead> heads;
    for (int i = 1; i <= 10; ++i) {  // Let's assume we have 10 cluster heads for this example
        std::string headId = "head" + std::to_string(i);
        heads.emplace_back(headId);
        provideClusterHead(cluster, heads.back());
    }

    // Step 4: Assign Nodes to Cluster Heads
    std::cout << "Assigning nodes to cluster heads..." << std::endl;
    srand(time(0));  // Seed for random assignment
    for (const auto& node : nodes) {
        int headIndex = rand() % heads.size();
        cluster.assignNodeToClusterHead(heads[headIndex].id, node.id);
    }

    // Step 5: Output the Blockchain and Cluster Information
    // Print all blocks in the blockchain
    std::cout << "\nBlockchain:\n";
    for (const auto& block : blockchain.chain) {
        std::cout << "Index: " << block.index << ", Data: " << block.data 
                  << ", Hash: " << block.hash << ", Previous Hash: " << block.previousHash << std::endl;
    }

    // Print all cluster heads and their assigned nodes
    std::cout << "\nCluster Heads:\n";
    for (const auto& head : cluster.clusterHeads) {
        std::cout << "Cluster Head ID: " << head.id << ", Assigned Nodes: ";
        for (const auto& nodeId : head.assignedNodes) {
            std::cout << nodeId << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
