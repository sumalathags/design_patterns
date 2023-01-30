#include "command.hpp"

int main()
{
    BatchProcessor processor;
    for (int i = 0; i < 10; i++)
    {
        processor.addCommand(new RecordCommand(i));
    }
    processor.processCommands();
    return 0;
}
