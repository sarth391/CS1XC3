/**
 * @file course.h
 * @author Sarthak Anand (you@domain.com)
 * @brief Course Functions Header File
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "student.h"
#include <stdbool.h>

/**
 * @brief Course type that stores a course with the fields coursename, course code, students type and the number of students
 * 
 */
typedef struct _course 
{
  char name[100]; /**< the course name */
  char code[10]; /**< the course code */
  Student *students; /**< the students */
  int total_students; /**< total number of students */
} Course;

/**
 * @brief Course Function headers
 * 
 */
void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


