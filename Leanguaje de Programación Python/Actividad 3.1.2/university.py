import datetime
class University:
    def __init__(self, name: str):
        self.name = name
        self.faculties = []
        self.students = []

    def add_faculty(self, faculty: 'Faculty'):
        self.faculties.append(faculty)

    def add_student(self, student: 'Student'):
        self.students.append(student)


class Faculty:
    def __init__(self, name: str):
        self.name = name
        self.courses = []
        self.professors = []

    def add_course(self, course: 'Course'):
        self.courses.append(course)

    def add_professor(self, professor: 'Professor'):
        self.professors.append(professor)


class Course:
    def __init__(self, name: str, semester: 'Semester'):
        self.name = name
        self.semester = semester
        self.professors = []
        self.students = []
        self.exams = []
        self.grades = []

    def add_professor(self, professor: 'Professor'):
        self.professors.append(professor)

    def add_student(self, student: 'Student'):
        self.students.append(student)

    def add_exam(self, exam: 'Exam'):
        self.exams.append(exam)

    def add_grade(self, grade: 'Grade'):
        self.grades.append(grade)


class Professor:
    def __init__(self, name: str):
        self.name = name
        self.courses = []

    def add_course(self, course: 'Course'):
        self.courses.append(course)


class Student:
    def __init__(self, name: str):
        self.name = name
        self.courses = []
        self.grades = []

    def add_course(self, course: 'Course'):
        self.courses.append(course)

    def add_grade(self, grade: 'Grade'):
        self.grades.append(grade)


class Semester:
    def __init__(self, name: str):
        self.name = name


class Exam:
    def __init__(self, date: datetime.datetime, course: 'Course'):
        self.date = date
        self.course = course
        self.students = []
        self.grades = []

    def add_student(self, student: 'Student'):
        self.students.append(student)

    def add_grade(self, grade: 'Grade'):
        self.grades.append(grade)


class Grade:
    def __init__(self, student: 'Student', exam: 'Exam', grade: float):
        self.student = student
        self.exam = exam
        self.grade = grade
