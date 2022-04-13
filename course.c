/**
 * @file course.c
 * @author Sarthak Anand (you@domain.com)
 * @brief Course Functions File
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief a function that takes the course type and student type and enrolls the student in the course by adding them to the students 
 * array
 * 
 * @param course 
 * @param student 
 */
void enroll_student(Course *course, Student *student)
{
  /**
   * @brief the total number of students in the course is increased, if this is the first student in the course
   * the calloc is used to create an array with the memory for 1 item, else if this isn't the first student in the course
   * then dynamic memory reallocation is used to add more students into the course
   * 
   */
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief prints the course name, code, total number of students, and all the students in a formatted manner
 * 
 * @param course 
 */
void print_course(Course* course)
{
  /**
   * @brief prints the name, code and total number of students
   * 
   */
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");

  /**
   * @brief loops through all the students and prints them one by one
   * 
   */
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief a function that determines and returns the top student in the course by finding the max average
 * 
 * @param course 
 * @return Student* 
 */
Student* top_student(Course* course)
{
  /**
   * @brief if no students present in the class then NULL is returned
   * the max average and top student is initialized to the first student in the class, while student average is set to 0 initially
   * 
   */
  if (course->total_students == 0) return NULL;
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];

  /**
   * @brief Loops through all the students in the course, determines there average, if there average is more than the
   * max average so far, then sets the current student as the top student and their average as the new max average,
   * until the top student is determined
   * 
   * @param i 
   */
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
 * @brief a function that determines how many students are passing the course and returns only the passing students
 * 
 * @param course 
 * @param total_passing 
 * @return Student* 
 */
Student *passing(Course* course, int *total_passing)
{

  /**
   * @brief determines the number of students passing the course and allocates memory for an array to hold all those students using calloc
   * 
   */
  int count = 0;
  Student *passing = NULL;
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  passing = calloc(count, sizeof(Student));

  /**
   * @brief loops through the whole class list, and adds only the passing students to the passing array and returns it at the end
   * 
   */
  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}