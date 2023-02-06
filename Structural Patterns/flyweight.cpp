#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef uint32_t key;

struct User
{
	User(const string& first_name, const string& last_name) 
		:first_name{add(first_name)}, 
		last_name{add(last_name)}
	{}

	const string& get_first_name()const
	{
		return names[first_name];
	}
	const string& get_last_name()const
	{
		return names[last_name];
	}


	friend ostream& operator <<(ostream& os, const User& obj)
	{
		return os
			<< "first_name:" << obj.first_name << " "
			<< obj.get_first_name()
			<< "last_name:" << obj.last_name << " "
			<< obj.get_last_name();
	}

	static void info()
	{
		for (auto& entry : names)
		{
			cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
		}
		cout << "size of map: " << names.size() << endl;
	}

protected:
	static std::unordered_map<key, string> names;
	static int seed;

	static key add(const string& s)
	{
		auto it = std::find_if(names.begin(), names.end(),
			[&s](const std::pair<key, string>& p) {
				return p.second == s;
			});
		if (it == names.end())
		{
			key id = ++seed;
			names.insert(std::make_pair(seed, s));
			return id;
		}
		return it->first;
	}

	key first_name;
	key last_name;
};

int User::seed = 0;
unordered_map<key, string> User::names{};

int main()
{
	User smr{ "smr","mousavi" };
	User sm{ "sm","mousavi" };

	cout << "smr " << smr << endl;
	cout << "sm " << sm << endl;
	
	User::info();
	return 0;

}
