import datetime
from university import *

university = University('Universidad de Baja California')

faculty = Faculty('Facultad de Ciencias Químicas e Ingeniería')
university.add_faculty(faculty)

semester = Semester('2022-2')

course = Course('Lenguaje de Programación Python', semester)
faculty.add_course(course)

professor = Professor('Profesor Manuel Castañon Puga')
course.add_professor(professor)

student = Student('Emmanuel Gómez')
course.add_student(student)

exam = Exam(datetime.datetime(2022, 10, 15), course)
course.add_exam(exam)

grade = Grade(student, exam, 90.0)
exam.add_grade(grade)
student.add_grade(grade)

print('Universidad:', university.name)
print('Facultades:')
for faculty in university.faculties:
    print('-', faculty.name)
    print('  Cursos:')
    for course in faculty.courses:
        print('  -', course.name)
        print('    Profesores:')
        for professor in course.professors:
            print('    -', professor.name)
        print('    Estudiantes:')
        for student in course.students:
            print('    -', student.name)
        print('    Exámenes:')
        for exam in course.exams:
            print('    -', exam.date)
            