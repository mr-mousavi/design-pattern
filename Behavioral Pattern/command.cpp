
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class FileSystem
{
public:

    int vfs_link(std::string filename, std::string linkName)
    {
        std::cout<< linkName<< " --> "<< filename<<endl;
        return 0;

    }
    int sysfs_create_file_ns(std::string filename)
    {
        std::cout<< "create file "<< filename<<endl;
        return 0;
    }

};

struct Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

//linux mkdir command
class Touch : public Command
{
    FileSystem fileSystem;
    std::string filename;
public:
    explicit Touch( std::string filename) : filename(filename) {}

    void execute() override
    {
        fileSystem.sysfs_create_file_ns(filename);
    }
};

//linux Ln command
class Ln : public Command
{
    FileSystem fileSystem;
    std::string filename;
    std::string linkName;
public:
    Ln(const string &filename, const string &linkName)
            : filename(filename), linkName(linkName) {}

    void execute()  override
    {
        fileSystem.vfs_link(filename,linkName);
    }
};


int main()
{
    Touch touch{"test"};
    Ln ln{"test", "link"};

    vector<Command*> commands{&touch, &ln};
    for (auto& cmd : commands)
    {
        cmd->execute();
    }
    return 0;
}

