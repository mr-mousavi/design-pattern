#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


class HtmlElement {
	friend class HtmlBuilder;
	string name, text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement() {	}
	HtmlElement(const string& name, const string& text) :name(name), text(text)
	{

	}
public:
	string str(int indent = 0) const
	{
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << endl;
		if (text.size() > 0)
			oss << string(indent_size * (indent + 1), ' ') << text << endl;

		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}
	

	//hint to user...
	static HtmlBuilder create(string root_name);

};

class HtmlBuilder
{
	HtmlElement root;
public:
	HtmlBuilder(string root_name)
	{
		root.name = root_name;
	}

	HtmlBuilder& add_child(string child_name, string child_text)
	{
		HtmlElement e{ child_name,child_text };
		root.elements.emplace_back(e);
		return *this;
	}

	HtmlElement build() { return root; }

	string str()const { return root.str(); }

	//automatic convertion operator to return HtmlElement
	operator HtmlElement() const 
	{
		cout << "HtmlElement ())" << endl;
		return root; 
	}
	
	//automatic convertion operator to return HtmlElement
	operator HtmlElement && () {
		cout << "HtmlElement &&" << endl;
		return std::move(root); 
	}
};

//hint to user...
HtmlBuilder HtmlElement::create(string root_name)
{
	return { root_name };//return HtmlBuilder instance with argument(necessary arg) inside curly bracket....
	//return HtmlBuilder(root_name);
}

int main()
{
	////fluent builder....
	//HtmlBuilder builder{ "ul" };
	//builder.add_child("li", "hello").add_child("li", "world");
	//cout << builder.str() << endl;


	//auto builder = HtmlElement::create("ul").add_child("li", "hello").add_child("li","builder");

	HtmlElement elem = HtmlElement::create("ul").add_child("li", "world"); //need too automatic convertion operator at HtmlBuilder class

	cout << elem.str() << endl;

	return 0;
}
