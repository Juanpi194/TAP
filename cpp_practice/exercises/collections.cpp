#include <iostream>
#include <string>
#include <map>

void	search_by_student(const std::string& name, const std::map<std::string, unsigned int>& student_grades)
{
	for (const auto& pair: student_grades)	// Use the auto type in this case
	{
		if (pair.first == name)
		{
		 	std::cout << "Grade: " << pair.second << "\n";
            return;
        }
    }
    std::cout << "Student not found\n";

	// Other method
	// auto it = student_grades.find(name);
	// if (it != student_grades.end())
	// 	std::cout << "Grade: " << it->second << "\n";
	// else
	// 	std::cout << "Student not found\n";
}

void	add_student(std::map<std::string, unsigned int>& student_grades, const std::string& new_student, unsigned int student_grade)
{
	student_grades[new_student] = student_grade;
}

void	remove_student(std::map<std::string, unsigned int>& student_grades, const std::string& student)
{
	student_grades.erase(student);
}

int	main(void)
{
	std::map<std::string, unsigned int>	student_grades = {{"Juanpi", 0}, {"Marcos", 10}};

	student_grades["Pablo"] = 7;	// Adding
	student_grades["Marcos"] = 9;	// Reasigning
	return (0);
}
