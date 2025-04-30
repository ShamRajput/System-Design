#include "TextEditorMemento.hpp"

TextEditorMemento::TextEditorMemento(const std::string &content):mContent(content)
{

}

std::string TextEditorMemento::getContent() const
{
    return mContent;
}
