class File {
public:
    virtual ~File() = default;
    virtual void read() = 0;
    virtual void write() = 0;
};

class ReadFile : public File {
public:
    void read() override {
        // Implementation for reading a file
    }

    void write() override {
        // Not applicable for ReadFile
        throw std::logic_error("Cannot write to a read-only file");
    }
};
class WriteFile : public File {
public:
    void read() override {
        // Not applicable for WriteFile
        throw std::logic_error("Cannot read from a write-only file");
    }

    void write() override {
        // Implementation for writing to a file
    }
};
class ReadWriteFile : public File {
public:
    void read() override {
        // Implementation for reading a file
    }

    void write() override {
        // Implementation for writing to a file
    }
};
class FileHandler {
public:
    void processFile(File& file) {
        file.read();
        file.write();
    }
};

int main() {
    ReadFile readFile;
    WriteFile writeFile;
    ReadWriteFile readWriteFile;

    FileHandler fileHandler;

    // Process files
    fileHandler.processFile(readFile);
    fileHandler.processFile(writeFile);
    fileHandler.processFile(readWriteFile);

    return 0;
}

//This principle is about ensuring that derived classes can be substituted for 
//their base classes without altering the correctness of
// the program.

/// above code is voilating the Liskov Substitution Principle (LSP) because the ReadFile and WriteFile classes  
// do not fulfill the contract of the File class.
// The File class defines a common interface for reading and writing files, but the ReadFile and WriteFile classes do not implement
// both methods correctly.

// To fix this, we can create a separate interface for read-only and write-only files.

class IReadable {
public:
    virtual ~IReadable() = default;
    virtual void read() = 0;
};
class IWritable {
public:
    virtual ~IWritable() = default;
    virtual void write() = 0;
};
class ReadFile : public IReadable {

public:
    void read() override {
        // Implementation for reading a file
    }
};
class WriteFile : public IWritable {
public:
    void write() override {
        // Implementation for writing to a file
    }
};
class ReadWriteFile : public IReadable, public IWritable {
public:
    void read() override {
        // Implementation for reading a file
    }

    void write() override {
        // Implementation for writing to a file
    }
};
class FileHandler {
public:
    void processReadable(IReadable& file) {
        file.read();
    }

    void processWritable(IWritable& file) {
        file.write();
    }
};
int main() {
    ReadFile readFile;
    WriteFile writeFile;
    ReadWriteFile readWriteFile;

    FileHandler fileHandler;

    // Process files
    fileHandler.processReadable(readFile);
    fileHandler.processWritable(writeFile);
    fileHandler.processReadable(readWriteFile);
    fileHandler.processWritable(readWriteFile);

    return 0;
}