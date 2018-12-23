from controller import *
from domain import *
from undocontroller import *
class UI:
    def __init__(self,StudentController=Controller(),AssignmentController=Controller(),GradeController=Controller()
                 ,StudentAssignmentsController=Controller(),studentAverageGrade=Controller()):
        self.__sc=StudentController
        self.__ac=AssignmentController
        self.__gc=GradeController
        self.__sac=StudentAssignmentsController
        self.__sagc=studentAverageGrade
        self.__undoController=UndoController()
    def printMenu(self):
        '''
        Prints the menu:
        :return:
        '''
        menu='   The commands are:\n'
        menu+='1. Add a student\n'
        menu+='2. Add an assignment\n'
        menu+='3. Remove a student\n'
        menu+='4. Remove an assignment\n'
        menu+='5. Update the data from a student\n'
        menu+='6. Update the data from an assignment\n'
        menu+='7. Print the list of students\n'
        menu+='8. Print the list of assignments\n'
        menu+='9. Give an assignment to a student\n'
        menu+='10. Give an assignment to a group\n'
        menu+='11. Grade a student for a given assignment\n'
        menu+='12. Print the best students ordered by their average grade\n'
        menu+='13. Print the students that did not finish their assignments in time\n'
        menu+='14. Print all the students who received a given assignment ordered alphabetically\n'
        menu+='15. Print all assignments for which there is at least one grade, sorted in decreasing order\n'
        menu+='16. Undo the last operation\n'
        menu+='17. Redo the operation that was undone\n'
        menu+='18. Filter students that have an average grade greater than a given grade\n'
        menu+='0. Exit\n'
        print(menu)
    def printList(self,lst):
        '''
        Prints the list of classes
        in:param lst:
        :return:
        '''
        for i in range(len(lst)):
            print(lst[i])
    def readUpdateStudent(self):
        '''
        Reads the modification of the student
        :return:
        '''
        try:
            x=int(input('Give the student id:'))
            y=input("Give the student's new name:")
            z=int(input("Give the student's new group:"))
            a=Student(x,y,z)
            return a
        except ValueError:
            print("Invalid Student format!")
            return
    def readUpdateAssignment(self):
        '''
        Reads the modification of the assignment
        :return:
        '''
        try:
            x=int(input('Give the assignment id:'))
            y=input("Give the assignment's new description:")
            z=input("Give the assignment's new deadline:")
            b = z
            b = b.split('.')
            if len(b) == 3:
                a = Assignment(x, y, z)
                return a
            else:
                raise ValueError
        except ValueError:
            print("Invalid Assignment format!")
            return
    def readStudent(self):
        '''
        Reads the student and returns it if it has a valid format
        :return:
        '''
        try:
            x=int(input('Give the student id:'))
            y=input('Give the student name:')
            z=int(input('Give the group of the student:'))
            a=Student(x,y,z)
            return a
        except ValueError:
            print('Invalid student format!')
            return
    def readAssignment(self):
        '''
        Reads the assignment and returns it if it has a valid format
        :return:
        '''
        try:
            x=int(input('Give the assignment id:'))
            y=input('Give the assignment description:')
            z=input('Give the deadline:')
            b=z
            b=b.split('.')
            if len(b)==3:
                a=Assignment(x,y,z)
                return a
            else:
                raise ValueError
        except ValueError:
            print('Invalid assignment format!')
            return
    def readGrade(self):
        '''
        Reads the grade and returns it if it has a valid format
        :return:
        '''
        try:
            x=int(input('Give the assignment id:'))
            y=int(input('Give the student id:'))
            z=int(input('Give the grade:'))
            a=Grade(x,y,z)
            return a
        except ValueError:
            print('Invalid grade format!')
            return
    def start(self):
        '''
        Creates a loop where the problem is solved
        :return:
        '''
        self.printMenu()
        while True:
            read=input("\nEnter the command ('help' for a list of commands):")
            read = read.strip()
            if read=='0':
                print('\nCYA LATER ALLIGATOR!')
                break
            elif read=='help':
                self.printMenu()
            elif read=='1':
                student=self.readStudent()
                self.__sc.add(student)
                redo=FunctionCall(self.__sc.add,student)
                undo=FunctionCall(self.__sc.remove,student)
                operation=Operation(redo,undo)
                self.__undoController.newOperation()
                self.__undoController.recordOperation(operation)

            elif read=='2':
                assignment=self.readAssignment()
                self.__ac.add(assignment)
                redo=FunctionCall(self.__ac.add,assignment)
                undo = FunctionCall(self.__ac.remove, assignment)
                operation=Operation(redo,undo)
                self.__undoController.recordOperation(operation)
            elif read=='3':
                x = int(input('Give The student id:'))
                a = self.__sc.findByStuID(x)
                c = self.__sc.get(a)
                self.__sc.removeIndex(a)
                self.__sac.deleteStudentAssignments(c)
                self.__gc.deleteStudent(x)
                undo = FunctionCall(self.__sc.add,c)
                redo = FunctionCall(self.__sc.remove,c)
                operation = Operation(redo, undo)
                self.__undoController.newOperation()
                self.__undoController.recordOperation(operation)
            elif read=='4':
                x = int(input('Give the assignment id:'))
                a = self.__ac.findByAssiID(x)
                b = self.__ac.get(a)
                self.__ac.removeIndex(a)
                self.__gc.deleteAssignment(x)
                undo = FunctionCall(self.__ac.add, b)
                redo = FunctionCall(self.__ac.remove, b)
                operation = Operation(redo, undo)
                self.__undoController.recordOperation(operation)
            elif read=='5':
                a=self.readStudent()
                b=self.readUpdateStudent()
                self.__sc.update(a,b)
                redo=FunctionCall(self.__sc.update,a,b)
                undo=FunctionCall(self.__sc.update,b,a)
                operation = Operation(redo, undo)
                self.__undoController.recordOperation(operation)
            elif read=='6':
                a=self.readAssignment()
                b=self.readUpdateAssignment()
                self.__ac.update(a,b)
                redo = FunctionCall(self.__ac.update, a, b)
                undo = FunctionCall(self.__ac.update, b, a)
                operation = Operation(redo, undo)
                self.__undoController.recordOperation(operation)
            elif read=='7':
                print(self.__sc)
            elif read=='8':
                print(self.__ac)
            elif read=='9':
                x=int(input('Give the assignment id:'))
                a=self.__ac.findByAssiID(x)
                b=self.__ac.get(a)
                x=int(input('Give the student id:'))
                a=self.__sc.findByStuID(x)
                c=self.__sc.get(a)
                self.__sac.giveAssignmentToStudent(c,b)
                print(self.__sac)
            elif read=='10':
                x = int(input('Give the assignment id:'))
                a = self.__ac.findByAssiID(x)
                b = self.__ac.get(a)
                c=int(input('Give a group:'))
                lst = self.__sc.groupList(c)
                self.__sac.giveAssignmentToGroup(c,b,lst)
                print(self.__sac)
            elif read=='11':
                x = int(input('Give the assignment id:'))
                a = self.__ac.findByAssiID(x)
                b = self.__ac.get(a)
                y = int(input('Give the student id:'))
                c = self.__sc.findByStuID(y)
                d = self.__sc.get(c)
                ok=1
                for i in range(len(self.__gc)):
                    if self.__gc.get(i).getAssignmentID()==x:
                        ok=0
                        print('Assignment already graded!')
                l=self.__sac.findStudent(d)
                if l==-1:
                    print('Student has no assignment!')
                    ok=0
                m=self.__sac.get(l).isFound(b)
                if m==False:
                    print("Student doesn't have this assignment!")
                    ok=0
                if ok==1:
                    try:
                        h=int(input('Give the grade:'))
                        p=Grade(x,y,h)
                        self.__gc.add(p)
                    except ValueError:
                        print('Invalid grade format!')
                print(self.__gc)
            elif read=='12':
                l=[]
                for i in range(len(self.__sac)):
                    lst=self.__sac.assignmentList(i)
                    student=self.__sac.get(i).getStudent()
                    id1=student.getStudentID()
                    grade=self.__gc.averageGrade(id1,lst)
                    a=[]
                    a.append(student)
                    a.append(grade)
                    l.append(a)
                combsort(l)
                for i in range(len(l)):
                    print(l[i][0],'; with grade: ',l[i][1])
            elif read=='13':
                l=[]
                for i in range(len(self.__sac)):
                    lst=self.__sac.assignmentList(i)
                    id1=self.__sac.get(i).getStudent().getStudentID()
                    g=self.__gc.averageGrade(id1,lst)
                    if g==-1:
                        l.append(self.__sac.get(i).getStudent())
                for i in range(len(l)):
                    print(l[i])
            elif read=='14':
                x = int(input('Give the assignment id:'))
                a = self.__ac.findByAssiID(x)
                b = self.__ac.get(a)
                lst=[]
                for i in range(len(self.__sac)):
                    if self.__sac.get(i).isFound(b)==True:
                        student=self.__sac.get(i).getStudent()
                        lst.append(student)
                        combsort(lst)
                for i in range(len(lst)):
                    print(lst[i])
            elif read=='15':
                lst=self.__gc.repoList()
                combsort(lst)
                for i in range(len(lst)):
                    x=lst[i].getAssignmentID()
                    a = self.__ac.findByAssiID(x)
                    b = self.__ac.get(a)
                    y=lst[i].getStudentID()
                    c = self.__sc.findByStuID(x)
                    d = self.__sc.get(a)
                    print(b,'from student: ',d,' with the grade: ',lst[i].getGrade())
            elif read=='16':
                self.__undoController.undo()
            elif read=='17':
                self.__undoController.redo()
            elif read=='18': #filter students by average grade
                x=int(input("Enter the grade:"))
                self.__gc.filterByGrade(x)
                lst=self.__gc.repoList()
                combsort(lst)
                print(lst)
            else:
                print(len(self.__sc))
                print('Invalid command!')