#include <iostream>
#include <vector>

class Command
{
public:
    virtual void execute() = 0;
};

class BatchProcessor
{
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* cmd) { commands.push_back(cmd); }

    void processCommands()
    {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }
};

class RecordCommand : public Command
{
private:
    int recordId;

public:
    RecordCommand(int id)
        : recordId(id)
    {
    }

    void execute()
    {
        // Perform resource-intensive processing on record with id = recordId
        std::cout << "Processing record " << recordId << std::endl;
    }
};
