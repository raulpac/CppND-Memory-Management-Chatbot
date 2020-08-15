#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                                  // constructor WITHOUT memory allocation
    ChatBot(std::string filename);              // constructor WITH memory allocation
    ~ChatBot();                                 // 1. Destructor

    //// STUDENT CODE
    ////

    ChatBot(const ChatBot &origin);             // 2. Copy Constructor
    ChatBot &operator=(const ChatBot &origin);  // 3. Copy Assignment Operator
    ChatBot(ChatBot &&origin);                  // 4. Move Constructor
    ChatBot &operator=(ChatBot &&origin);       // 5. Move Assignment Operator
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */