/*Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate(Дипломник)
Подумать, как сюда применить наследование.*/

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Human 
{
	string last_name;
	string first_name;
	time_t birth_date;
	
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	const time_t& get_birth_date()const
	{
		return birth_date;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(const string& birth_date)
	{
		this->birth_date = birth_date;
	}
	
	Box& operator()(double height, double width, double depth)
	{
		this->height = height;
		this->width = width;
		this->depth = depth;
		return *this;
	}

	Box(double height, double width, double depth)
	{
		this->height = height;
		this->width = width;
		this->depth = depth;
	}

	void open()
	{
		is_open = true;
	}
	void close()
	{
		is_open = false;
	}
	void info()const
	{
		cout << height << "x" << width << "x" << depth << endl;
		cout << (is_open ? "Open" : "Closed") << endl;
	}
};

class GiftBox :public Box
{
	string cover;
	string bantik;
public:
	const string& get_conver()const
	{
		return cover;
	}
	const string& get_bantik()const
	{
		return bantik;
	}
	GiftBox
	(
		double height, double width, double depth,
		const string& cover, const string& bantik
	) :Box(height, width, depth)
	{
		this->cover = cover;
		this->bantik = bantik;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Box box;
	box(2, 3, 4);
	box.open();
	box.close();
	box.info();*/
	GiftBox box(2, 3, 4, "С котами и мышами", "Зеленый бантик");
}