#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediatorInterface;
class NodeInterface
{
    string ip;
public:
    string getIp() const {return ip;}

    explicit NodeInterface(const string &ip)
    : ip(ip) {}

    virtual void sendMessage(const MediatorInterface& mediator,
                             const string& message)const =0;
    virtual void receiveMessage(const NodeInterface* sender,
                                const string& message) const =0;

    virtual void sendMsgTo(const MediatorInterface& mediator,
                           const NodeInterface* receiver,
                           const string& message)const =0;
    virtual void receiveMsgFrom(const NodeInterface* receiver,
                                const string& message) const =0;

};

class Node : public NodeInterface{

//    using NodeInterface::NodeInterface;
public:
    explicit Node(const string &ip)
    : NodeInterface(ip) {}

    void sendMessage(const MediatorInterface &mediator, const string &message) const override;

    void receiveMessage(const NodeInterface *sender, const string &message) const override;

    void sendMsgTo(const MediatorInterface& mediator,
                   const NodeInterface* receiver,
                   const string& message)const override;
    void receiveMsgFrom(const NodeInterface* receiver,
                                const string& message) const override;
};

class MediatorInterface
{
    vector<NodeInterface*> nodes;

public:
    const vector<NodeInterface *> &getNodes() const {
        return nodes;
    }
    void registerNode(NodeInterface* node){nodes.emplace_back(node);}
    virtual void broadcast(const NodeInterface* sender,
                           const string& msg)const =0;

    virtual void sendTo(const NodeInterface* sender,
                        const NodeInterface* receiver,
                        const string& message)const =0;

};

class Mediator: public MediatorInterface
{
    void broadcast(const NodeInterface* sender,
                   const string& msg)const override;
    void sendTo(const NodeInterface* sender,
                const NodeInterface* receiver,
                const string& message)const override;
};


void Node::sendMessage(const MediatorInterface &mediator,
                       const string &message) const {
    mediator.broadcast(this,message);
}

void Node::receiveMessage(const NodeInterface *sender,
                          const string &message) const {
    cout<< getIp()<<"received msg from " << sender->getIp() + ":"
    << message<<endl;
}

void Node::sendMsgTo(const MediatorInterface &mediator,
                     const NodeInterface *receiver,
                     const string &message) const {
    mediator.sendTo(this, receiver,message);
}

void Node::receiveMsgFrom(const NodeInterface *receiver,
                          const string &message) const {
    cout<< receiver->getIp()<<"received msg from "
        << this->getIp() + ":"
        << message<<endl;
}

void Mediator::broadcast(const NodeInterface *sender,
                         const string &msg) const {
    for(const auto& n:getNodes())
        if(n != sender)
            n->receiveMessage(sender,msg);
}

void Mediator::sendTo(const NodeInterface *sender,
                      const NodeInterface *receiver,
                      const string &message) const {
    for(const auto& n:getNodes())
        if(n == receiver)
            sender->receiveMessage(receiver,message);
}

int main() {

    Node* node1 = new Node("node1");
    Node* node2 = new Node("node2");
    Node* node3 = new Node("node3");
    Node* node4 = new Node("node4");
    Node* node5 = new Node("node5");

    Mediator mediator;
    mediator.registerNode(node1);
    mediator.registerNode(node2);
    mediator.registerNode(node3);

    node1->sendMessage(mediator,"test data");
    cout<<"--------------------\n";
    mediator.registerNode(node4);
    node1->sendMessage(mediator,"test data after node4");
    cout<<"--------------------\n";

    mediator.registerNode(node5);
    node1->sendMsgTo(mediator,node5,"node5 welcome");
	
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;

    return 0;
}
