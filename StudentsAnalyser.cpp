#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

enum class Mention // Stocke les mentions possible dans cette enum class (C++ moderne)
{
	A,
	B,
	C,
	D,
	F
};

struct Student // Our dynamique array of students
{
	std::string firstname;
	std::string name;
	std::vector<double> grade;
	double moyenne;
	Mention mention;
};

std::vector<Student> studentsList; // A dynamique array containing the struct of a student

void displayListStudents(std::vector<Student>& list)
{
	if (list.empty()) // Vérifie si le vector n'est pas vide, donc si il contient un élément
	{
		std::cout << "[Error] - There is none student in the form\n";
	}

	for (int i{ 0 }; i < list.size(); i++)
	{
		std::cout << "\t\t Student \n";
		std::cout << "[Firstname] : " << list[i].firstname << '\n';
		std::cout << "[Name] : " << list[i].name << '\n';
		std::cout << "[Grade] : \n";

		for (double grade : list[i].grade)
		{
			std::cout << grade << '\n';
		}
	}
}

void addStudentInForm(std::vector<Student>& studenttoAdd) // Ajoute un étudiant dans le vector référencé dans les paramètres de la fonction, qui va enregistrer son prenom et son nom dans un premier temps
{
	Student newStudent{};

	std::cout << "\t\t Add a student \n";
	std::cout << "Complete this : \n";

	std::cout << "\t What is the firstname of the student ? : ";
	std::cin >> newStudent.firstname;

	std::cout << "\t What is the name of the student ? : ";
	std::cin >> newStudent.name;

	studenttoAdd.push_back(newStudent);

	std::cout << "[Success] - You have bien add the all informations of the student ! " << studenttoAdd.back().name << '\n';
}

void deleteStudentInForm(std::vector<Student>& studentToDelete) // Supprime un étudiant dans le vector référencé dans les paramètres de la fonction, qui va supprimer tous les champs d'un "student"
{
	int studentChoiceToDelete{ 0 };

	if (studentToDelete.empty()) // Vérifie si le vector est vide, donc ne contient aucun élément
	{
		std::cout << "[Error] - There is none students to delete actually in the form\n";
		return;
	}

	for (std::size_t i{ 0 }; i < studentToDelete.size(); i++)
	{
		std::cout << "[" << i << "]\n";
		std::cout << "[FirstName] - " << studentToDelete[i].firstname << '\n';
		std::cout << "[Name] - " << studentToDelete[i].name << '\n';
		std::cout << "[Grade] - \n\n";

		for (double grade : studentToDelete[i].grade)
		{
			std::cout << grade << '\n';
		}
	}

	std::cout << "Which student do you want to delete? : ";
	std::cin >> studentChoiceToDelete;

	if (studentChoiceToDelete < 0 || studentChoiceToDelete >= studentToDelete.size()) // Vérifie si le choix d'index est valide ou non, si il ne l'est pas on ne fait rien
	{
		std::cout << "[Error] - The index specified is not valid\n";
		return; // On ajoute un return afin de sortir de la fonction si cette condition est vrais car sinon on éxécute quand même le reste de la fonction
	}

	studentToDelete.erase(studentToDelete.begin() + studentChoiceToDelete);
	std::cout << "[Success] - You have delete the student number : " << studentChoiceToDelete << '\n\n';
}

void deleteAllStudentsInForm(std::vector<Student>& students) // Supprime tous les étudiants dans le vector référencé dans les paramètres de la fonction, qui va supprimer tous les champs d'un "student"
{
	std::string choiceDeleteAllStudents{};

	if (students.empty()) // Vérifie si le vector est vide, si c'est le cas on ne fait rien et on sort de la fonction
	{
		std::cout << "[Error] - There is none students to delete actually in the form\n";
		return;
	}

	std::cout << "Are you sure you want to delete all the students currently registered in the form? : (Yes/No) ";
	std::cin >> choiceDeleteAllStudents;

	if (choiceDeleteAllStudents != "Yes" && choiceDeleteAllStudents != "No") // Vérifie si l'entrée est bien une des deux réponses souhaité
	{
		std::cout << "[Error] - Please provide your prompt, question, or instructions in English, and I will give you a valid, comprehensive response tailored exactly to what you need\n";
		return;
	}

	if (choiceDeleteAllStudents == "No") // Vérifie si le champs rempli est égal à "No"
	{
		std::cout << "[Info] - You decided not to delete all the students from the form\n";
		return;
	}

	if (choiceDeleteAllStudents == "Yes") // Vérifie si le champs rempli est égal à "Yes"
	{
		std::cout << "[Success] - You have removed all the students from the list\n";
		students.clear();
	}
}

void addGradeToStudentInForm(std::vector<Student>& studentGrade) // Ajoute une note à un étudiant qui est actuellement enregistrer et qui est vérifié à l'avance
{
	int indexStudent;
	double grade;

	std::cout << "\t\t ADD A GRADE \n";

	if (studentGrade.empty()) // Vérifie si le vector est vide, si c'est le cas on ne fait rien et on sort de la fonction
	{
		std::cout << "[Info] - There is none students to add a grade\n";
		return;
	}
	
	for (int i{ 0 }; i < studentGrade.size(); i++)
	{
		std::cout << "[" << i << "]" << " - " << studentGrade[i].name << '\n';
	}

	std::cout << "A quelle etudiant voulez vous rajouter une note ? : ";
	std::cin >> indexStudent;

	if (indexStudent < 0 || indexStudent >= studentGrade.size()) // Vérifie si l'index renseigné est valide ou non, si ce n'est pas le cas on sort de la fonction
	{
		std::cout << "[Info] - Vous ne pouvez pas mettre une note inferieur a 0 ou superieur a 20\n";
		return;
	}

	std::cout << "\t Quelle note voulez vous attribuer ? : ";
	std::cin >> grade;

	if (grade < 0 || grade > 20) // Vérifie si le grade renseigné est supérieur à 0 et inférieur ou égal à 20, si ce n'est pas le cas on sort de la fonction
	{
		std::cout << "[Info] - Vous ne pouvez pas mettre une note inferieur a 0 ou superieur a 20\n";
		return;
	}

	studentGrade[indexStudent].grade.push_back(grade);

	std::cout << "[Success] - Vous avez bien ajouter une note a l'etudiant : " << studentGrade[indexStudent].name << '\n';
}

void displayGradeOfStudentInForm(std::vector<Student>& students) // Affiche l'ensemble des notes de l'étudiant choisit, qui sera vérifié en avance
{
	int indexStudent;

	if (students.empty()) // Vérifie si le vector est vide, si c'est le cas on ne fait rien et on sort de la fonction
	{
		std::cout << "[Info] - There is none students to add a grade\n";
		return;
	}

	for (int i{ 0 }; i < students.size(); i++)
	{
		std::cout << "[" << i << "]" << " - " << students[i].name << '\n';
	}

	std::cout << "De quelle etudiant voulez-vous voir les notes ? : ";
	std::cin >> indexStudent;

	if (indexStudent < 0 || indexStudent >= students.size()) // Vérifie si l'index renseigné est valide ou non, si ce n'est pas le cas on sort de la fonction
	{
		std::cout << "[Info] - Veuillez renseignez un index qui est valide\n";
		return;
	}

	for (int i{ 0 }; i < students[indexStudent].grade.size(); i++)
	{
		std::cout << students[indexStudent].grade[i] << '\n';
	}

	std::cout << "[Success] - Toutes les notes de " << students[indexStudent].name << " on ete affiche\n";
}

double calcMoyenneOfStudent(std::vector<Student>& students) // Calcule la moyenne d'un étudiant via ces notes
{
	int indexStudent;
	double moyenneStudent{ 0.0 };

	if (students.empty()) // Vérifie si le vector est vide, si c'est le cas on ne fait rien et on sort de la fonction
	{
		std::cout << "[Info] - There is none students to add a grade\n";
		return 0.0;
	}

	for (int i{ 0 }; i < students.size(); i++)
	{
		std::cout << "[" << i << "]" << " - " << students[i].name << '\n';
	}

	std::cout << "De quelle etudiant voulez vous calculer la moyenne ? : ";
	std::cin >> indexStudent;

	if (indexStudent < 0 || indexStudent >= students.size()) // Vérifie si l'index renseigné est valide ou non, si ce n'est pas le cas on sort de la fonction
	{
		std::cout << "[Error] - Veuillez renseigner un indes valid\n";
		return 0.0;
	}

	auto& selectedIndexStudent{ students[indexStudent] }; // On stocke l'index par référence dans une variable afin de l'utiliser plus facilement

	for (double note : selectedIndexStudent.grade) // On parcoures toutes les notes qu'on met dans une variable temporaire et on les ajoutent dans notre vector de notes
	{
		moyenneStudent += note;
	}

	if (selectedIndexStudent.grade.empty())
	{
		std::cout << "[Error] - Aucune moyenne possible car il n'y a pas de note pour cette etudiant";
		return 0.0;
	}

	selectedIndexStudent.moyenne = moyenneStudent / selectedIndexStudent.grade.size(); // On calcule la moyenne

	std::cout << "[Info] - La moyenne de l'etudiant " << students[indexStudent].name << " est de " << students[indexStudent].moyenne << "/20\n";

	return selectedIndexStudent.moyenne;
}

std::string mentionToString(Mention mention) // Renvoie la valeur en "std::string" en fonction de la valeur de la "Mention"
{
	switch (mention)
	{
	case Mention::A: return "A";
	case Mention::B: return "B";
	case Mention::C: return "C";
	case Mention::D: return "D";
	case Mention::F: return "F";
	}

	return "Unknown"; // Si aucune de ces valeurs est utilisé alors c'est une mention "Unkwnow"
}

void addMentionToStudent(std::vector<Student>& students) // Ajoute une mention à l'étudiant choisit, étudiant valide vérifiez en avance
{
	Mention mention;
	int indexStudent;

	if (students.empty()) // Vérifie si il y a des éléments dans le vector 
	{
		std::cout << "[Error] - Il n'y a aucun etudiants\n";
		return;
	}

	for (int i{ 0 }; i < students.size(); i++)
	{
		std::cout << "[" << i << "]" << " - " << students[i].name << '\n';
	}
	
	std::cout << "A quelle etudiant voulez-vous mettre la mention ? : ";
	std::cin >> indexStudent;

	if (indexStudent < 0 || indexStudent >= students.size() || students[indexStudent].grade.empty() || students[indexStudent].moyenne <= 0.0) // Vérifie si l'index renseigné est valide ou non puis on vérifie si il y a deja une moyenn qui a été calculé si ce n'est pas le cas on sort de la fonction
	{
		std::cout << "Veuillez renseignez un indes valide ou verifiez que l'etudiant possede des notes dans son bulletin\n";
		return;
	}

	if (students[indexStudent].moyenne < 5.0) // Vérifie si la moyenne est supérieur à 5.0
	{
		students[indexStudent].mention = Mention::F;
		std::cout << "[Success] - La note " << mentionToString(students[indexStudent].mention) << " a ete attribue a " << students[indexStudent].name;
	}
	else if (students[indexStudent].moyenne > 5.0 && students[indexStudent].moyenne <= 10.0) // Vérifie si la moyenne est supérieur à 5.0 et inférieur à 10.0
	{
		students[indexStudent].mention = Mention::D;
		std::cout << "[Success] - La note " << mentionToString(students[indexStudent].mention) << " a ete attribue a " << students[indexStudent].name;
	}
	else if (students[indexStudent].moyenne > 10.0 && students[indexStudent].moyenne <= 14.0) // Vérifie si la moyenne est supérieur à 10.0 et inférieur à 14.0
	{
		students[indexStudent].mention = Mention::C;
		std::cout << "[Success] - La note " << mentionToString(students[indexStudent].mention) << " a ete attribue a " << students[indexStudent].name;
	}
	else if (students[indexStudent].moyenne > 14.0 && students[indexStudent].moyenne <= 16.0) // Vérifie si la moyenne est supérieur à 14.0 et inférieur à 16.0
	{
		students[indexStudent].mention = Mention::B;
		std::cout << "[Success] - La note " << mentionToString(students[indexStudent].mention) << " a ete attribue a " << students[indexStudent].name;
	}
	else if (students[indexStudent].moyenne >= 16.0 && students[indexStudent].moyenne <= 20.0) // Vérifie si la moyenne est supérieur à 10.0 et inférieur ou égal à 20.0
	{
		students[indexStudent].mention = Mention::A;
		std::cout << "[Success] - La note " << mentionToString(students[indexStudent].mention) << " a ete attribue a " << students[indexStudent].name;
	}
}

void hasStudentPassed(std::vector<Student>& students) // Vérifie si le l'étudiant renseigné à reussit ou non via sa moyenne
{
	int indexStudent;


	if (students.empty()) // Vérifie si le vector est vide, si c'est le cas on ne fait rien et on sort de la fonction
	{
		std::cout << "[Info] - There is none student in the form\n";
		return;
	}

	for (int i{ 0 }; i < students.size(); i++)
	{
		std::cout << "[" << i << "] " << " - " << students[i].name << '\n';
	}

	std::cout << "De queelle etudiant voulez-vous savoir s'il a reussit ?\n";
	std::cin >> indexStudent;

	if (indexStudent < 0 || indexStudent >= students.size() || students[indexStudent].moyenne <= 0.0) // Vérifie si l'index renseigné est valide ou non puis on vérifie si il y a deja une moyenn qui a été calculé si ce n'est pas le cas on sort de la fonction
	{
		std::cout << "[Error] - Veuillez reseigne un index valide ou verifiez si l'etudiant en question a deja eu sa moyenne d'attribue\n";
		return;
	}

	if (students[indexStudent].moyenne >= 10) // Vérifie si la moyenne est supérieur ou égal à 10
	{
		std::cout << "[Info] - L'etudiant " << students[indexStudent].name << " a reussit\n";
	}
	else
	{
		std::cout << "[Info] - L'etudiant " << students[indexStudent].name << " n'a pas reussit\n";
	}
}

void startProgramAnalyser()
{
	std::string asks[9] = {"1. Voir les etudiants actuellement enregistrer dans la fiche", "2. Enregistrer un etudiant dans la fiche", 
		"3. Supprimer un etudiant actuellement enregistrer dans la fiche", "4. Faire une suppresion totale des etudiants actuellement enregistrer dans la fiche",
		"5. Ajouter une note a un etudiant actuellement enregistrer dans la fiche",
		"6. Calculer la moyenne d'un etudiant actuellement enregistrer dans la fiche", "7. Attribuer une mention a un etudiant actuellement enregistrer par apport a sa moyenne", 
		"8. Verifiez si un etudiant actuellement enregistrer dans la fiche a reussit", "9. Exit\n"};

	int choose{ 0 };

	while (choose != 9)
	{
		std::cout << "\t\t STUDIANT ANALYSER \n";
		std::cout << "Complete this : \n\n";

		for (const std::string ask : asks) // Affiche tous les string du tableau "asks"
		{
			std::cout << "\t" << ask << '\n';
		}

		std::cout << "\tQue voulez vous faire ? : ";
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			displayListStudents(studentsList);
			break;
		case 2:
			addStudentInForm(studentsList);
			break;
		case 3:
			deleteStudentInForm(studentsList);
			break;
		case 4:
			deleteAllStudentsInForm(studentsList);
			break;
		case 5:
			addGradeToStudentInForm(studentsList);
			break;
		case 6:
			calcMoyenneOfStudent(studentsList);
			break;
		case 7:
			addMentionToStudent(studentsList);
			break;
		case 8:
			hasStudentPassed(studentsList);
			break;
		case 9:
			return;
		}
	}
}

int main()
{
	startProgramAnalyser();
}