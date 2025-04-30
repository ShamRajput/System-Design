#pragma once

#include <stack>
#include <memory>
#include "TextEditorMemento.hpp"
#include "TextEditor.hpp"

class History
{
private:
    std::stack<std::unique_ptr<TextEditorMemento>> mStates;
public:
    void save(const TextEditor& editor) ;
    void restore(TextEditor& editor);
};
