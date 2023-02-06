#include <iostream>
using namespace std;

struct Letter
{
	string sender, receiver, title;

	Letter(const string& sender, const string& receiver, const string& title)
		: sender(sender),
		receiver(receiver),
		title(title)
	{
	}

	friend ostream& operator<<(ostream& os, const Letter& obj)
	{
		return os
			<< "sender: " << obj.sender
			<< " receiver: " << obj.receiver
			<< " title: " << obj.title;
	}
};

class AbstractLetter
{
	AbstractLetter* next{ nullptr };// unique_ptr
protected:
	Letter& letter;// pointer or shared_ptr

public:
	explicit AbstractLetter(Letter& letter) : letter(letter) {}
	virtual ~AbstractLetter() = default;

	void addChain(AbstractLetter* abstractLetter)
	{
		if (next) next->addChain(abstractLetter);
		else next = abstractLetter;
	}
	virtual void handle()
	{
		if (next) next->handle();
	}

};

class CEO : public AbstractLetter
{
	string receiver = "CEO";
public:
	explicit CEO(Letter& letter)
		: AbstractLetter(letter) {}

	void handle()
	{
		if (letter.receiver.compare(receiver) == 0)
			cout << "CEO got letter\n";
		else {
			AbstractLetter::handle();
			//next->handle(receiver);
		}
	}

};


class FinancialUnit : public AbstractLetter
{
	string receiver = "FinancialUnit";
public:
	explicit FinancialUnit(Letter& letter)
		: AbstractLetter(letter) {}

	void handle()
	{
		if (letter.receiver.compare(receiver) == 0)
			cout << "Financial Unit got letter\n";
		else {
			AbstractLetter::handle();
			//next->handle(receiver);
		}
	}

};


class TechnicalUnit : public AbstractLetter
{
	string receiver = "TechnicalUnit";
public:
	explicit TechnicalUnit(Letter& letter)
		: AbstractLetter(letter) {}

	void handle()
	{
		if (letter.receiver.compare(receiver) == 0)
			cout << "Technical Unit got letter\n";
		else {
			AbstractLetter::handle();
			//next->handle(receiver);
		}
	}
};

class Employee : public AbstractLetter
{
	string receiver = "mohammadReza";
public:
	explicit Employee(Letter& letter)
		: AbstractLetter(letter) {}

	void handle()
	{
		if (letter.receiver.compare(receiver) == 0)
			cout << "mohammadReza got letter\n";
		else {
			AbstractLetter::handle();
			//next->handle(receiver);
		}
	}
};



int main()
{
	Letter letter{ "me","mohammadReza", "deploy mobile app" };
	AbstractLetter root{ letter };
	CEO ceo{ letter };
	FinancialUnit financialUnit{ letter };
	TechnicalUnit technicalUnit{ letter };
	Employee employee{ letter };

	root.addChain(&ceo);
	root.addChain(&financialUnit);
	root.addChain(&technicalUnit);
	root.addChain(&employee);

	root.handle();

	cout << letter << endl;
	return 0;
}