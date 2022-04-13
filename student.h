/**
 * @file student.h
 * @author Sarthak Anand (you@domain.com)
 * @brief Student Functions Header File
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Student type that stores a student with the fields firstname, lastname, studentID, a grades pointer and the number of grades
 * 
 */
typedef struct _student 
{ 
  char first_name[50]; /**< the student's first name */
  char last_name[50]; /**< the student's last name */
  char id[11]; /**< the student's student ID */
  double *grades; /**< the student's grades */
  int num_grades; /**< the total number of grades for the student */
} Student;

/**
 * @brief Student Function Headers
 * 
 */
void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
