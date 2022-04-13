/**
 * @file student.c
 * @author Sarthak Anand (you@domain.com)
 * @brief Student Functions File
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


/**
 * @brief a function that takes a student and a grade value and adds it to that students grades array
 * 
 * @param student 
 * @param grade 
 */
void add_grade(Student* student, double grade)
{
  /**
   * @brief increases the students total number of grades, if this is their first grade then using calloc to allocate memory for
   * an array of 1 element, if it is not the first grade then using realloc to modify the memory allocated for the existing array
   * and adds more grade values
   * 
   */
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief calculates and returns the students average
 * 
 * @param student 
 * @return double 
 */
double average(Student* student)
{
  /**
   * @brief if there are no grade values for the student then returns a 0, else loops through all the grades and calculates the average
   * 
   */
  if (student->num_grades == 0) return 0;
  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

/**
 * @brief a function to print the students, name, id, grades and average in a formatted manner
 * 
 * @param student 
 */
void print_student(Student* student)
{
  /**
   * @brief prints the name, ID and grades headings
   * 
   */
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");

  /**
   * @brief loops through all the grades and prints them
   * 
   */
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);

  /**
   * @brief prints the calculated average
   * 
   */
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief a function that generates a random student with all its properties
 * 
 * @param grades 
 * @return Student* 
 */
Student* generate_random_student(int grades)
{
  /**
   * @brief a list of random first names and last names to choose from
   * 
   */
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};
  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
  
  /**
   * @brief dynamically allocates memory for an array with one student
   * 
   */
  Student *new_student = calloc(1, sizeof(Student));

  /**
   * @brief randomly picks a first name and last name from the list and assigns it to the student type
   * 
   */
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  /**
   * @brief generates a random studentID and assigns it to the student
   * 
   */
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  /**
   * @brief generates a number of random grades specified by the int grade parameter and adds them to the students grades array
   * using the add function
   * 
   */
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}