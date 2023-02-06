#include <iostream>

#include <memory>
using namespace std;



struct Image
{
	virtual ~Image() = default;
	virtual void draw() = 0;
};

struct Bitmap : Image
{
	Bitmap(const string& filename) : filename(filename)
	{
		cout << "Loading image from " << filename << endl;
	}

	void draw() override
	{
		cout << "Drawing image" << endl;
	}

	string filename;
};

struct LazyBitmap : Image
{
	LazyBitmap(const string& filename) : filename(filename) {}
	~LazyBitmap() { delete bmp; }
	void draw() override
	{
		if (!bmp)
			bmp = new Bitmap(filename);
		bmp->draw();
	}

private:
	Bitmap* bmp{ nullptr };
	string filename;
};

int main()
{
	//Bitmap bmp{ "xy.png" };
	//bmp.draw();

	//LazyBitmap is virtual proxy to Bitmap class
	LazyBitmap bmp{ "xy.png" };
	bmp.draw();
}