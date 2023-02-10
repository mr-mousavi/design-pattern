#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
using namespace std;

class StrategyInterface
{
public:
    virtual void generate(ostringstream& oss)  = 0;
};

class Cpp: public StrategyInterface
{
public:
    void generate(ostringstream& oss )  override
    {
        oss<<"\\\\""code generated for Cpp: \n";
        oss << "#include <iostream>\n";
        oss <<"int main() {\n";
        oss <<"\tstd::cout<< \"hello world\" ;"<<endl;
        oss <<"}\n\n\n";
    }
};

class Python: public StrategyInterface
{
public:
    void generate(ostringstream& oss)  override
    {
        oss<< "\\\\""code generated for Python: \n";
        oss<<"print(\"hello world\")\n\n"<<endl;
    }
};

class Java: public StrategyInterface
{
public:
    void generate(ostringstream& oss)  override
    {
        oss<<"\\\\""code generated for Java: \n";
        oss << "import static java.lang.System.out;"<< endl;
        oss << "class Simple{"<< endl;
        oss <<"public static void main(String args[]){\n";
        oss <<"\tSystem.out.println(\"Hello World \");"<<endl;
        oss <<"}\n\n\n";
    }
};

//second Context
class Context
{
private:
    ostringstream oss;
    std::unique_ptr<StrategyInterface> strategy;//we should initialize the unique_ptr explicitly in the constructor and without initialization it is nullptr_t

    void clearOstringStream()
    {
        oss.str("");
        oss.clear();
    }
public:

    explicit Context(std::unique_ptr<StrategyInterface> &&strategy) : strategy(std::move(strategy))
    {
    }

    void set_strategy(std::unique_ptr<StrategyInterface> &&strategy)//for first initialization without constructor ,strategy will be nullptr_t.
    {
        this->strategy = std::move(strategy);
    }
    void generate()
    {
        if (strategy) {
            clearOstringStream();
            strategy->generate(oss);
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }

    string str() const {
        return oss.str();
    }
};

int main(int argc, char *argv[])
{
    Context context(std::make_unique<Cpp>());

    context.generate();
    cout << context.str() << endl;

    context.set_strategy(std::make_unique<Java>());
    context.generate();
    cout << context.str() << endl;

    context.set_strategy(std::make_unique<Python>());
    context.generate();
    cout << context.str() << endl;

    return 0;
}
