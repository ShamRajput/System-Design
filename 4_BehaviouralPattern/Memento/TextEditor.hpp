#pragma once
#include <memory>
#include "TextEditorMemento.hpp"
class TextEditor
{
    public :
        TextEditor(const std::string& text);
        ~TextEditor() = default;
    
    public :
        void setText(const std::string& text) ;
        std::string getText() const ;
        std::unique_ptr<TextEditorMemento> save() const;
        void undo(const std::unique_ptr<TextEditorMemento>& memento);
    
    private :
        std::string mContent;
};
