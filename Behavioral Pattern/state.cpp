#include <iostream>
#include <string>
using namespace std;

class WindowManager;
struct State
{
  virtual void showCardReaderWindow(WindowManager* wm)
  {
    cout << "we are already in cardReader window :)\n";
  }
  virtual void showPasswordWindow(WindowManager* wm)
  {
    cout << "we are already in password window :)\n";
  }
};

struct CardReaderWindow : State{
    CardReaderWindow()
    {
        cout << "constructing cardReader window :)\n";
    }
    void showPasswordWindow(WindowManager* wm);
};

struct PasswordWindow : State{
    PasswordWindow() {
        cout << "constructing password window :)\n";
    }
    void showCardReaderWindow(WindowManager* wm);
};


struct WindowManager
{
    State* windowState;
    WindowManager()
  {
        windowState = new CardReaderWindow();//default window when app run
  }

  void setState(State* windowState)
  {
        this->windowState = windowState;
  }
  void showCardReaderWindow()
  {
        windowState->showCardReaderWindow(this);
  }
  void showPasswordWindow()
  {
        windowState->showPasswordWindow(this);
  }
};

void CardReaderWindow::showPasswordWindow(WindowManager *wm) {
    cout << "show password window :)\n";
    wm->setState(new PasswordWindow());
    delete this;
}

void PasswordWindow::showCardReaderWindow(WindowManager *wm) {
    cout << "show cardReader window :)\n";
    wm->setState(new CardReaderWindow());
    delete this;
}

int main()
{
    WindowManager wm;
    wm.showPasswordWindow();
    wm.showCardReaderWindow();
//    wm.showCardReaderWindow();
    return 0;
}

