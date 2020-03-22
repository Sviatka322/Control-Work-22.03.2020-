#include <iostream>
#include <string>

class People
{
protected:
	std::string m_name;
	int m_age;
	std::string m_sex;

public:
	People(std::string name = "", int age = 0, std::string sex = "")
		: m_name(name), m_age(age), m_sex(sex) {}

	std::string getName()
	{
		return m_name;
	}

	int getAge()
	{
		return m_age;
	}

	std::string getSex()
	{
		return m_sex;
	}
};

class Teacher : public People
{
private:
	std::string m_position;
	float m_experience;

public:
	Teacher(std::string name = "", int age = 0, std::string sex = "",std::string position = "", float experience = 0.0)
		: People(name, age, sex),
			m_position(position), m_experience(experience) {}

	std::string getPosition()
	{
		return m_position;
	}

	float getExperience()
	{
		return m_experience;
	}
};

class Student : public People
{
private:
	std::string m_faculty;
	float m_average_rating;

public:
	Student(std::string name = "", int age = 0, std::string sex = "", std::string faculty = "", float average_rating = 0.0)
		:  People(name, age, sex),
			m_faculty(faculty), m_average_rating(average_rating) {}

	std::string getFaculty()
	{
		return m_faculty;
	}

	float getAverageRating()
	{
		return m_average_rating;
	}
};

int main()
{

	return 0;
}