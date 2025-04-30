#include "TextEditor.hpp"

TextEditor::TextEditor(const std::string &text):mContent(text)
{

}

void TextEditor::setText(const std::string &text)
{
    mContent = text;
}

std::string TextEditor::getText() const
{
    return mContent;
}

std::unique_ptr<TextEditorMemento> TextEditor::save() const
{
    return std::make_unique<TextEditorMemento>(mContent);
}

void TextEditor::undo(const std::unique_ptr<TextEditorMemento>& memento)
{
    mContent = memento->getContent();
}
