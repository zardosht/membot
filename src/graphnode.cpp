#include "graphedge.h"
#include "graphnode.h"

using std::cout;
using std::endl;

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    
    std::cout << "GraphNode Destructor" << std::endl;

    delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    std::cout << "GraphNode.MoveChatbotHere(): chatbot: " << chatbot << std::endl; 

    // _chatBot = chatbot;
    _chatBot = new ChatBot(chatbot);

    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index];

    ////
    //// EOF STUDENT CODE
}