#include <iostream>

// Component Interface
class FileIO
{
public:
    virtual void execute() = 0;
};

// Concrete Component
class RealFileIO : public FileIO
{
public:
    void execute()
    {
        std::cout << "IO Ops performed on file" << std::endl;
        // Perform file IO operations
    }
};

// Decorator Base Class
class FileIODecorator : public FileIO
{
protected:
    FileIO* fileIO;

public:
    FileIODecorator(FileIO* fileIO)
        : fileIO(fileIO)
    {
    }

    void execute() { fileIO->execute(); }
};

// Concrete Decorator
class EncryptionDecorator : public FileIODecorator
{
public:
    EncryptionDecorator(FileIO* fileIO)
        : FileIODecorator(fileIO)
    {
    }
    void encrypt() { std::cout << "File has been encrypted." << std::endl; }
    void decrypt() { std::cout << "File has been decrypted" << std::endl; }
    void execute()
    {
        // Perform encryption before file IO operations
        this->decrypt();

        fileIO->execute();
        
        // Perform encryption after file IO operations
        this->encrypt();
    }
};

// Concrete Decorator
class CompressionDecorator : public FileIODecorator
{
public:
    CompressionDecorator(FileIO* fileIO)
        : FileIODecorator(fileIO)
    {
    }
    void compress() { std::cout << "file has been compressed" << std::endl; }
    void decompress() { std::cout << "file has been decompressed" << std::endl; }
    void execute()
    {
        // Perform compression before file IO operations
        this->decompress();

        fileIO->execute();

        // Perform compression after file IO operations
        this->compress();
    }
};

// Concrete Decorator
class EmailDecorator : public FileIODecorator
{
public:
    EmailDecorator(FileIO* fileIO)
        : FileIODecorator(fileIO)
    {
    }
    void sendmail() { std::cout << "file has sent" << std::endl; }
    void getmail() { std::cout << "file has been download" << std::endl; }
    void execute()
    {
        // Perform compression before file IO operations
        this->getmail();

        fileIO->execute();

        // Perform compression after file IO operations
        this->sendmail();
    }
};
