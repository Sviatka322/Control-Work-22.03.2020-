#include <iostream>
#include <string>
#include <fstream>

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
	double m_average_rating;

public:
	Student(std::string name = "", int age = 0, std::string sex = "", std::string faculty = "", double average_rating = 0.0)
		:  People(name, age, sex),
			m_faculty(faculty), m_average_rating(average_rating) {}

	std::string getFaculty()
	{
		return m_faculty;
	}

	double getAverageRating()
	{
		return m_average_rating;
	}
};

void sortPeople(People *people[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (people[i]->getName() > people[j]->getName())
			{
				People* t_people = people[i];
				people[i] = people[j];
				people[j] = t_people;
			}
		}
	}
}

void printFacultyStudents(Student *student[], int n, std::string faculty)
{
	for (int i = 0; i < n; i++)
	{
		if (student[i]->getFaculty() == faculty)
		{
			std::cout << "Name: " << student[i]->getName() << ", Age: " << student[i]->getAge() << ", Faculty: " << student[i]->getFaculty() << ", Average rating: " << student[i]->getAverageRating() << '\n';
		}
	}
}

Teacher& MinExperience(Teacher *teacher[], int n, std::string position)
{

	int index = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (teacher[i]->getPosition() == position)
		{
			index = i;
			break;
		}
	}

	Teacher* min_experience = teacher[index];

	for (int i = 0; i < n; i++)
	{
		if (teacher[i]->getPosition() == position && teacher[i]->getExperience() < min_experience->getExperience())
		{
			min_experience = teacher[i];
		}
	}

	return *min_experience;

}

/*
void fill()
{
	std::ofstream fout("Student.txt");

	std::string name;
	std::string sex;
	std::string faculty;
	int age;
	double rating;

	while (name != "exit")
	{
		std::cout << "Enter name: ";
		std::cin >> name;

		if (name == "exit")
			break;
		
		std::cout << "Enter age: ";
		std::cin >> age;

		std::cout << "Enter sex: ";
		std::cin >> sex;

		std::cout << "Enter faculty: ";
		std::cin >> faculty;

		std::cout << "Enter rating: ";
		std::cin >> rating;

		Student student(name, age, sex, faculty, rating);
		
		fout.write((char*)&student, sizeof(student));

		std::cout << '\n';
	}
}
*/

int main()
{
	
	Student andrew("Andrew", 18, "male", "AMI", 68.9), maria("Maria", 21, "famale", "LAW", 83.2), danil("Danil", 18, "male", "AMI", 53.2);
	Teacher irina("Irina", 38, "famale", "Assistent", 12.5), yuri("Yuri", 73, "male", "Profesor", 51), taras("Taras", 40, "male", "Profesor", 30);

	/*
	std::ofstream fout("Student.txt");

	fout.write((char*)&andrew, sizeof(Student));
	*/

	People *peoples[]{ &andrew, &maria, &irina, &yuri, &danil, &taras};
	Student* students[]{ &andrew, &maria, &danil };
	Teacher* teachers[]{ &irina, &yuri, &taras };

	for (int i = 0; i < sizeof(peoples) / sizeof(peoples[0]); i++)
	{
		std::cout << peoples[i]->getName() << " ";
	}

	std::cout << '\n';

	sortPeople(peoples, sizeof(peoples) / sizeof(peoples[0]));

	for (int i = 0; i < sizeof(peoples) / sizeof(peoples[0]); i++)
	{
		std::cout << peoples[i]->getName() << " ";
	}

	std::cout << '\n';

	printFacultyStudents(students, sizeof(students) / sizeof(students[0]), "AMI");

	Teacher t = MinExperience(teachers, sizeof(teachers) / sizeof(teachers[0]), "Profesor");

	std::cout << t.getName() << '\n';

	std::ifstream fin("Student.txt");

	Student s;

	fin.read((char*)&s, sizeof(Student));

	std::cout << s.getName() << '\n';

	return 0;
}