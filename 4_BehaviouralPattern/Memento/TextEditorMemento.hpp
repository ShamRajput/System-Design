
#pragma once

#include <string>

class TextEditorMemento
{
private:
    const std::string mContent;
public:
    TextEditorMemento( const std::string &content);
    std::string getContent() const;
   
};


