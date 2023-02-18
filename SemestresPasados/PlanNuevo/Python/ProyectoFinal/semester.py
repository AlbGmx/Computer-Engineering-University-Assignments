import datetime
from university import *

university = University('Universidad de Baja California')

faculty = Faculty('Facultad de Ciencias Químicas e Ingeniería')
university.add_faculty(faculty)

semester = Semester('2022-2')

python = Course('Lenguaje de Programación Python', semester)
faculty.add_course(python)
ingles = Course('Ingles II', semester)
faculty.add_course(ingles)
sdc = Course('Sistemas de Control', semester)
faculty.add_course(python)
analisis = Course('Analisis y diseño de sistemas', semester)
faculty.add_course(analisis)
ia = Course('Inteligencia Artificial', semester)
faculty.add_course(ia)
traductores = Course('Traductores', semester)
faculty.add_course(traductores)
interacion = Course('Interaccion Humano-Computadora', semester)
faculty.add_course(interacion)

professor = Professor('Manuel Castañon Puga')
python.add_professor(professor)
professor = Professor('Reyes Hernandez Karla Fabiola')
ingles.add_professor(professor)
professor = Professor('Araiza Medrano Lizette')
sdc.add_professor(professor)
professor = Professor('Navarro Almanaza Raul Ignacio')
ia.add_professor(professor)
professor = Professor('Ocegueda Miramontes Thelma Violeta')
analisis.add_professor(professor)
professor = Professor('Licea Sandoval Guillermo')
traductores.add_professor(professor)
professor = Professor('Trujillo Perez-Humberto')
interacion.add_professor(professor)

student = Student('Emmanuel Gómez')
python.add_student(student)
student = Student('Emmanuel Gómez')
ingles.add_student(student)
student = Student('Emmanuel Gómez')
sdc.add_student(student)
student = Student('Emmanuel Gómez')
analisis.add_student(student)
student = Student('Emmanuel Gómez')
ia.add_student(student)
student = Student('Emmanuel Gómez')
traductores.add_student(student)
student = Student('Emmanuel Gómez')
interacion.add_student(student)

exam = Exam(datetime.datetime(2022, 10, 15), python)
python.add_exam(exam)

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
