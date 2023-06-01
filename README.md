# Learning Management System (LMS)

## Introduction
A learning management system (LMS) is a software application used to plan, implement, and assess specific learning processes. It facilitates eLearning practices and consists of a server for core functionality and a user interface for instructors, students, and administrators. The LMS empowers instructors to create and deliver content, monitor student participation, and assess performance. Students can benefit from interactive features. This system improves traditional educational methods, saving organizations time and money. Instructors and administrators efficiently manage user registration, attendence, assessment, user access, result evaluation and DMC generation.

## Overview of Project
1. Student Registration
2. Faculty Registration
3. Course Registration
4. Add/Drop Registration
5. Attendance Marking
6. Assign Assessment Marks
7. Result Evaluation
8. Detail Marks Certificate (DMC) Generation

## Major Portions of Code
### Admin Class
The admin class performs major functionalities such as adding teachers and courses, managing user information, updating course details, and providing interfaces for teachers, courses, and students.

### Teacher Class
The teacher class allows teachers to manage attendance, assessments, marks, and grades for each course they are teaching.

### Student Class
The student class enables students to add/drop courses, view attendance, assessment marks, grades, and semester-wise detail marks certificates (DMC).

### Assessment Class
The assessment class manages assessment details, including obtained marks, total marks, and weightage.

### Course Class
The course class handles course information, including course code, credit hours, and title. It also manages assessments and lecture details.

### Person Class
The person class serves as the parent class, providing utility functions for names, gender, CNIC, and other personal information.

### Lecture Class
The lecture class tracks student attendance in the form of a Boolean value (0 or 1) for each enrolled course.

## Menu-driven Interface
The program utilizes a menu-driven interface for easy navigation. Admin, teachers, and students have their own interfaces for performing specific tasks.

