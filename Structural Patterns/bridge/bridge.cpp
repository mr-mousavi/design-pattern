#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Implementation {
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0;
};

class WindowsImpl : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "WindowsImpl:: Here's the result on the Windows platform .\n";
    }
};

class LinuxImpl : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "LinuxImpl:: Here's the result on the Linux platform.\n";
    }
};


class Abstraction {

protected:
    Implementation* implementation_;

public:
    Abstraction(Implementation* implementation) : implementation_(implementation) {
    }

    virtual ~Abstraction() {

    }

    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

class Windows : public Abstraction {
public:
    Windows(Implementation* implementation) : Abstraction(implementation) {
    }
    std::string Operation() const override {
        return "Windows:: Windows operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

class Linux : public Abstraction {
public:
    Linux(Implementation* implementation) : Abstraction(implementation) {
    }
    std::string Operation() const override {
        return "Linux:: Linux operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

void ClientCode(const Abstraction& abstraction) {
	// ...
	std::cout << abstraction.Operation();
	// ...
}

int main() {
	Implementation* implementation = new WindowsImpl;
	Abstraction* abstraction = new Abstraction(implementation);
	ClientCode(*abstraction);
	std::cout << std::endl;
	delete implementation;
	delete abstraction;



    std::cout << "--------------------------------------" << std::endl;
	implementation = new LinuxImpl;
	//abstraction = new Windows(implementation);
	//ClientCode(*abstraction);
 //   delete abstraction;
	abstraction = new Linux(implementation);
	ClientCode(*abstraction);

	delete implementation;
	delete abstraction;

	return 0;
}