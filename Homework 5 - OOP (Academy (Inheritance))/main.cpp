/*Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate(Дипломник)
Подумать, как сюда применить наследование.*/

#include<iostream>
#include<string>
using namespace std;

class Human 
{
	string last_name;
	string first_name;
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
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//                   Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
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
		const string& last_name, const string& first_name, unsigned int age, 
		const string& speciality, const string& group, double rating 
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
	unsigned int experience_worke;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience_worke()const
	{
		return experience_worke;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience_worke(unsigned int experience_worke)
	{
		this->experience_worke = experience_worke;
	}
	//                       Constructurs
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience_worke
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience_worke(experience_worke);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << speciality << ", опыт работы преподавателем: " << experience_worke << " лет." << endl;
	}
};
class Graduate :public Student 
{
	string topic; // Тема дипломного проекта
	string page_count; // Количество страниц (требуемый объем диплома)
public:
	const string& get_topic()const
	{
		return this->topic;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}
	const string& get_page_count()const
	{
		return page_count;
	}
	void set_page_count(const string& page_count)
	{
		this->page_count = page_count;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age, 
		const string& speciality, const string& group, double rating, 
		const string& topic, const string& page_count
	) :Student(last_name, first_name, age, speciality, group, rating)	
	{
		set_topic(topic); 
		set_page_count(page_count);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << "Тема дипломного проекта: " << topic << ", Требуемый объем дипломного проекта: " << page_count << " стр." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Student Ivan("Гаврилов", "Иван", 20, "Разработка программного обеспечения", "CPD_011", 4.7);
	Ivan.info();
	Teacher teacher("Абрамов", "Антон", 45, "Matematics", 20);
	teacher.info();
	Graduate Alekc("Соколов", "Алексей", 25, "Иноформационные технологии", "CV_011", 90, "Внедрение новейших технологий", "130-150");
	Alekc.info();
}