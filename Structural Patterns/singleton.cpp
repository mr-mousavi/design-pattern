#include <iostream>
#include <fstream>
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include < mutex>

using namespace std;

////   Monostate 
//class Printer
//{
//    static int id;
//public:
//    int getId() const{
//        return id;
//    }
//    void setId(int id)
//    {
//        id = id;
//    }
//};
//
//int main()
//{
//    Printer p1;
//    p1.getId();
//    Printer p2;
//    return 0;
//}



class CardReader
{
	CardReader() {}
	CardReader(const CardReader& other) = delete;
	CardReader& operator =(const CardReader&) = delete;

	static CardReader* instance;

public:
	static CardReader* getInstance()
	{
		if (!CardReader::instance)
			return CardReader::instance;
		return CardReader::instance = new CardReader();
	}

	static void deleteMethod()
	{
		if (!CardReader::instance)
		{
			delete CardReader::instance;
			CardReader::instance = nullptr;
		}
	}

	void print()
	{
		cout << "singleton pattern podcast\n";
	}

};
CardReader* CardReader::instance = nullptr;

int main()
{
	////first usage
	//CardReader::getInstance()->print();

	//second usage
	CardReader* cr = CardReader::getInstance();
	cr->print();
}