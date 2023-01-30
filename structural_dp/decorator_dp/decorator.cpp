#include "decorator.hpp"

// Client code
int main()
{
    FileIO* fileIO = new RealFileIO();
    fileIO         = new CompressionDecorator(fileIO);
    fileIO         = new EncryptionDecorator(fileIO);
    fileIO         = new EmailDecorator(fileIO);
    fileIO->execute();

    return 0;
}
