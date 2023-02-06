//#include <iostream>
//
//using namespace std;
//
//class Handler {
//protected:
//	Handler* next;
//
//public:
//	Handler() {
//		next = NULL;
//	}
//
//	virtual ~Handler() { }
//
//	virtual void request(int value) = 0;
//
//	void setNextHandler(Handler* nextInLine) {
//		next = nextInLine;
//	}
//};
//
//class SpecialHandler : public Handler {
//private:
//	int myLimit;
//	int myId;
//
//public:
//	SpecialHandler(int limit, int id) {
//		myLimit = limit;
//		myId = id;
//	}
//
//	~SpecialHandler() { }
//
//	void request(int value) {
//
//		if (value < myLimit) {
//			cout << "Handler " << myId << " handled the request with a limit of " << myLimit << endl;
//		}
//		else if (next != NULL) {
//			cout << "next" <<endl;
//			next->request(value);
//		}
//		else {
//			cout << "Sorry, I am the last handler (" << myId << ") and I can't handle the request." << endl;
//		}
//	}
//};
//
//int main() {
//	Handler* h1 = new SpecialHandler(10, 1);
//	Handler* h2 = new SpecialHandler(20, 2);
//	Handler* h3 = new SpecialHandler(30, 3);
//
//	h1->setNextHandler(h2);
//	h2->setNextHandler(h3);
//
//	h1->request(18);
//
//	h1->request(40);
//
//	delete h1;
//	delete h2;
//	delete h3;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Creature
//{
//	string name;
//	int attack, defense;
//
//	Creature(const string& name, const int attack, const int defense)
//		: name(name),
//		attack(attack),
//		defense(defense)
//	{
//	}
//
//
//	friend ostream& operator<<(ostream& os, const Creature& obj)
//	{
//		return os
//			<< "name: " << obj.name
//			<< " attack: " << obj.attack
//			<< " defense: " << obj.defense;
//	}
//};
//
//class CreatureModifier
//{
//	CreatureModifier* next{ nullptr }; // unique_ptr
//protected:
//	Creature& creature; // pointer or shared_ptr
//public:
//	explicit CreatureModifier(Creature& creature)
//		: creature(creature)
//	{
//	}
//	virtual ~CreatureModifier() = default;
//
//	void add(CreatureModifier* cm)
//	{
//		if (next) next->add(cm);
//		else next = cm;
//	}
//
//	// two approaches:
//
//	// 1. Always call base handle(). There could be additional logic here.
//	// 2. Only call base handle() when you cannot handle things yourself.
//
//	virtual void handle()
//	{
//		if (next) next->handle();
//	}
//};
//
//// 1. Double the creature's attack
//// 2. Increase defense by 1 unless power > 2
//// 3. No bonuses can be applied to this creature
//
//class NoBonusesModifier : public CreatureModifier
//{
//public:
//	explicit NoBonusesModifier(Creature& creature)
//		: CreatureModifier(creature)
//	{
//	}
//
//	void handle() override
//	{
//		// nothing
//	}
//};
//
//class DoubleAttackModifier : public CreatureModifier
//{
//public:
//	explicit DoubleAttackModifier(Creature& creature)
//		: CreatureModifier(creature)
//	{
//	}
//
//	void handle() override
//	{
//		creature.attack *= 2;
//		CreatureModifier::handle();
//	}
//};
//
//class IncreaseDefenseModifier : public CreatureModifier
//{
//public:
//	explicit IncreaseDefenseModifier(Creature& creature)
//		: CreatureModifier(creature)
//	{
//	}
//
//
//	void handle() override
//	{
//		if (creature.attack <= 2)
//			creature.defense += 1;
//		CreatureModifier::handle();
//	}
//};
//
//int main()
//{
//	Creature goblin{ "Goblin", 1, 1 };
//	CreatureModifier root{ goblin };
//	DoubleAttackModifier r1{ goblin };
//	DoubleAttackModifier r1_2{ goblin };
//	IncreaseDefenseModifier r2{ goblin };
//	//NoBonusesModifier nb{ goblin }; // effectively Command objects
//
//	//root.add(&nb);
//	root.add(&r1);
//	root.add(&r1_2);
//	root.add(&r2);
//
//	root.handle(); // annoying
//
//	cout << goblin << endl;
//
//	//getchar();
//	return 0;
//}


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