#include <iostream>
#include <vector>
#include <string>

// Block class to represent each block in the blockchain
class Block {
public:
    int index;
    std::string data;
    std::string hash;
    std::string previousHash;

    Block(int idx, const std::string& dat, const std::string& prevHash)
        : index(idx), data(dat), previousHash(prevHash) {
        hash = generateHash();
    }

private:
    std::string generateHash() {
        // Simplified hash generation for illustration purposes
        return std::to_string(index) + data + previousHash;
    }
};

// Blockchain class to manage the blockchain
class Blockchain {
public:
    std::vector<Block> chain;

    Blockchain() {
        // Create the genesis block
        chain.push_back(createGenesisBlock());
    }

    void addBlock(const std::string& data) {
        int index = chain.size();
        std::string previousHash = chain.back().hash;
        chain.push_back(Block(index, data, previousHash));
    }

private:
    Block createGenesisBlock() {
        return Block(0, "Genesis Block", "0");
    }
};

// IoMTNode class to represent IoMT nodes
class IoMTNode {
public:
    std::string id;
    std::string data;

    IoMTNode(const std::string& nodeId, const std::string& nodeData)
        : id(nodeId), data(nodeData) {}
};

// Function to register IoMT nodes into the blockchain
void registerIoMTNode(Blockchain& blockchain, const IoMTNode& node) {
    blockchain.addBlock(node.id + ": " + node.data);
}
