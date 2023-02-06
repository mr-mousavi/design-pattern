#include <iostream>

using namespace std;
class ActiveDevice
{
	virtual bool execute() = 0;
};

class MotherBoard : public ActiveDevice
{
private :
	bool powerOn;
public:
	~MotherBoard()
	{
		powerOn = false;
	}
	bool execute() override
	{
		cout << "motherboard power is on\n";
		powerOn = true;
		return powerOn;
	}
};

class CPU : public ActiveDevice
{
	void freez() {}
	void jump(long pos) {}
public:
	bool execute()override
	{
		cout << "execute POST command" << endl;
		cout << "execute BOATLOADER " << endl;
		return true;
	}
};

class Memory 
{
public:
	void load(long position, uint8_t* data) {}
};

class HardDrive
{
public:
	int read(uint8_t* buff, size_t size) 
	{
		cout << "start to read first HDD segment\n";
		return 0; 
	}

	int write(uint8_t* buff, size_t size) { return 0; }
};

class ComputerFacade
{
public:
	void start()
	{
		mb.execute();
		cpu.execute();
		size_t buffSize = 512;
		auto buffer = make_shared<uint8_t[]>(buffSize);
		hardDrive.read(buffer.get(), buffSize);
		memory.load(0x10, buffer.get());
	}

private :
	MotherBoard mb;
	CPU cpu;
	HardDrive hardDrive;
	Memory memory;

};

int main()
{

	ComputerFacade computer;
	computer.start();
	cout << " computer is ready to use >>" << endl;

	return 0;
}