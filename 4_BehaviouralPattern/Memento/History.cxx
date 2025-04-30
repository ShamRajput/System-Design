#include "History.hpp"

void History::save(const TextEditor& editor)
{
    mStates.push(editor.save());
}

void History::restore(TextEditor& editor)
{
    if(!mStates.empty()) {
        editor.undo(mStates.top());
        mStates.pop();
    }
}