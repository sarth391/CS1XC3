/**
 * @file main.c
 * @author Sarthak Anand (you@domain.com)
 * @brief The main file that utilizes the course and student libraries to generate a course and corresponding data
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief the main function that utilizes the Course and Student Libraries
 * 
 * @return int 
 */
int main()
{
  srand((unsigned) time(NULL));

  /**
   * @brief makes a new course type struct called MATH101 and assigns it a name and code
   * 
   */
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  /**
   * @brief generates 20 random students, each with 8 random marks and enrolls them into the course and then prints the course
   * 
   */
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  print_course(MATH101);

  /**
   * @brief generates the top student of the class and prints it
   * 
   */
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  /**
   * @brief determines the names and number of the students passing the course and prints all the passing students
   * 
   */
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}