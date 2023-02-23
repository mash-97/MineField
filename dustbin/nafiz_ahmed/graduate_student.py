class Graduate_Student:
     number_of_graduate_students = 0

     def __init__(self, name, credits):
         self.name = name
         self.credits = credits

     def __str__(self):
         s =  "Department: "+self.name+", Course Credits: "+str(self.credits)
         return s

class MSc_Student(Graduate_Student):
    def __init__(self, name, credits):
        super().__init__(name, credits)
        self.students = []
        print("MSc Students in {} have to complete {} hours for courses.".format(self.name, self.credits))
    
    def add_MSc_Student(self, *args):
        i = 0
        l = len(args)
        while i < l-1:
            self.students.append([args[i], args[i+1]])
            i += 2
            Graduate_Student.number_of_graduate_students += 1
    
    def __str__(self):
        r = super().__str__()
        r += "\nTotal Student(s): {}\n".format(len(self.students))
        r += "Student details:\n"
        for student in self.students:
            r += "Name: {}, Course Credits remaining: {}\n".format(student[0], self.credits-student[1])
        return r 

class MEng_Student(Graduate_Student):
    def __init__(self, name, credits):
        super().__init__(name, credits)
        self.students = []
        print("MEng Students in {} have to complete {} hours for courses.".format(self.name, self.credits))
    
    def add_MEng_Student(self, *args):
        i = 0
        l = len(args)
        while i < l-1:
            self.students.append([args[i], args[i+1]])
            i += 2
            Graduate_Student.number_of_graduate_students += 1
    
    def __str__(self):
        r = super().__str__()
        r += "\nTotal Student(s): {}\n".format(len(self.students))
        r += "Student details:\n"
        for student in self.students:
            r += "Name: {}, Course Credits remaining: {}\n".format(student[0], self.credits-student[1])
        return r 


# Write your codes here.
# Do not change the following lines of code.
p1 = MSc_Student("CSE", 18)
print("=================================")
p1.add_MSc_Student("Daniel", 12,  "Catherine", 18, "Michael", 15)
print("=================================")
print(p1)
print("=================================")
p2 = MEng_Student("CSE", 30)
print("=================================")
p2.add_MEng_Student("Barry", 12, "Sam", 18)
print("=================================")
print(p2)
print("=================================")
print("Total GraduateStudent: ", 
Graduate_Student.number_of_graduate_students)