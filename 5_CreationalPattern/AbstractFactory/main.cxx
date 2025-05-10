#include <iostream>
#include "Application.hxx"
#include "UIAbstractFactory.hxx"
#include "WindowsUIFactory.hxx"
#include "LinuxUIFactory.hxx"

int main(int argc, char* argv[]) {

    // Check if the user provided a command line argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <UI type>" << std::endl;
        return 1;
    }
    // Get the UI type from the command line argument
    std::string uiType = argv[1];
    // Check if the UI type is valid
    if (uiType != "windows" && uiType != "linux") {
        std::cerr << "Invalid UI type. Use 'windows' or 'linux'." << std::endl;
        return 1;
    }
    UIAbstractFactory* factory = nullptr;
    if (uiType == "linux") {
            factory = new LinuxUIFactory();
    }
    else if (uiType == "windows") {
            factory = new WindowsUIFactory();
    }
    else {
        std::cerr << "Invalid UI type. Use 'windows' or 'linux'." << std::endl;
        return 1;
    }

    Application app(factory);
    app.run();
    delete factory;


    return 0;

}
