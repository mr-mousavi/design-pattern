#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Forward declaring the builder
class EmailBuilder;

class Email
{
  public:
    friend class EmailBuilder;  // the builder can access Email's privates
    
    static EmailBuilder make();
    
    string to_string() const {
        stringstream stream;
        stream << "from: " << m_from
               << "\nto: " << m_to
               << "\nsubject: " << m_subject
               << "\nbody: " << m_body;
        return stream.str();
    }
    
  private:
    Email() = default; // restrict construction to builder
    
    string m_from;
    string m_to;
    string m_subject;
    string m_body;
};

class EmailBuilder
{
  public:
    EmailBuilder& from(const string &from) {
        m_email.m_from = from;
        return *this;
    }
    
    EmailBuilder& to(const string &to) {
        m_email.m_to = to;
        return *this;
    }
    
    EmailBuilder& subject(const string &subject) {
        m_email.m_subject = subject;
        return *this;
    }
    
    EmailBuilder& body(const string &body) {
        m_email.m_body = body;
        return *this;
    }
    
    operator Email&&() {
        return std::move(m_email); // notice the move
    }
    
  private:
    Email m_email;
};

EmailBuilder Email::make()
{
    return EmailBuilder();
}

// Bonus example!
std::ostream& operator <<(std::ostream& stream, const Email& email)
{
    stream << email.to_string();
    return stream;
}

int main()
{
    Email mail = Email::make().from("me@mail.com")
                              .to("you@mail.com")
                              .subject("C++ builders")
                              .body("I like this API, don't you?");
                              
    cout << mail << endl;
}