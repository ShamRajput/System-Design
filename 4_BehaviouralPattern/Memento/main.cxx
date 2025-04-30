#include <iostream>
#include <string>
#include "TextEditor.hpp"
#include "History.hpp"


int main() {

    std::cout << "Momemto Pattern" << std::endl;
    
    History history;
    TextEditor editor("Hello");
    history.save(editor);
    
    editor.setText("Hello World");
    history.restore(editor);
    history.restore(editor);

    editor.setText("Hello World Shamkumar");
    history.save(editor);

    std::cout << "Current Text: " << editor.getText() << std::endl;
    return 0;
}
