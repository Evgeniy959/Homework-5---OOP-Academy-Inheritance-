﻿/*Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate(Дипломник)
Подумать, как сюда применить наследование.*/

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Human 
{
	string last_name;
	string first_name;
	//time_t birth_date;
	unsigned int age;
	
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	/*const time_t& get_birth_date()const
	{
		return birth_date;
	}*/
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	/*void set_birth_date(const time_t& birth_date)
	{
		this->birth_date = birth_date;
	}*/
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//                   Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)//const time_t& birth_date)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		//set_birth_date(birth_date);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//                       Methods
	void info()const
	{
		/*cout << "Last_name " << last_name << endl;
		cout << "First_name" << first_name << endl;
		//cout << "Birth_date" << birth_date << endl;
		cout << "Age: \t\t" << age << "years" << endl;*/
		cout << last_name << " " << first_name << ", " << age << " лет"<< endl;
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//                     Constructors

	Student 
	(
		const string& last_name, const string& first_name, unsigned int age, //Атрибуты базового класса
		const string& speciality, const string& group, double rating //Атрибуты нашего класса
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human:: info();
		cout << speciality << ", " << group << ", успеваемость: " << rating << endl;
	}
};
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//                       Constructurs
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << speciality << ", опыт преподавания: " << experience << " лет." << endl;
	}
};
class Graduate :public Student 
{
	string topic; // Тема дипломного проекта
public:
	const string& get_topic()const
	{
		return this->topic;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age, //Атрибуты базового класса
		const string& speciality, const string& group, double rating, //Атрибуты нашего класса
		const string& topic
	) :Student(last_name, first_name, age, speciality, group, rating),
		topic(topic)
	{
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << "Тема дипломного проекта: " << topic << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("Тупенко", "Василий", 18);
	human.info();*/
	Student Vasya("Тупенко", "Василий", 18, "Программирование", "CPD_011", 4.5);
	Vasya.info();
	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();
	Graduate Tony("Montana", "Antonio", 25, "Современные технологии продаж", "CPD_011", 80, "Распространение кокаина");
	Tony.info();
}