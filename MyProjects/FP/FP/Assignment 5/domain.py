class Student:
    def __init__(self,id,name,group):
        self.__id=id
        self.__name=name
        self.__group=group
    def __str__(self):
        a='StudentID: '+str(self.__id)+', StudentName: '+str(self.__name)+', StudentGroup: '+str(self.__group)
        return a
    def setName(self,name):
        self.__name=name
    def setStudentID(self,id):
        self.__id=id
    def setGroup(self,group):
        self.__group=group
    def getStudentID(self):
        return self.__id
    def getName(self):
        return self.__name
    def getGroup(self):
        return self.__group
    def __eq__(self,z):
        if isinstance(z,Student):
            return self.__id==z.__id or self.__name==z.__name
        return False
    def __gt__(self,el):
        if self.__name>el.__name:
            return True
        return False
    def __lt__(self,el):
        if self.__name>el.__name:
            return False
        return True

class Assignment:
    def __init__(self,id,description,deadline):
        self.__id=id
        self.__description=description
        self.__deadline=deadline
    def __str__(self):
        a ='AssignmentID: '+str(self.__id)+', AssignmentDesc: '+str(self.__description)+', AssignmentDeadline: '+str(self.__deadline)
        return a
    def setAssignmentID(self,id):
        self.__id=id
    def setDescription(self,description):
        self.__description=description
    def setDeadline(self,deadline):
        self.__deadline=deadline
    def getAssignmentID(self):
        return self.__id
    def getDescription(self):
        return self.__description
    def getDeadline(self):
        return self.__deadline
    def __eq__(self,y):
        if isinstance(y,Assignment):
            return self.__id==y.__id or self.__description==y.__description
        return False


class Grade:
    def __init__(self,ida,ids,grade):
        self.__ida=ida
        self.__ids=ids
        self.__grade=grade
    def __str__(self):
        a = 'AssignmentID: '+str(self.__ida)+', StudentID: '+str(self.__ids)+', Grade: '+str(self.__grade)
        return a
    def __gt__(self,el):
        if self.__grade>el.__grade:
            return True
        return False
    def __lt__(self,el):
        if self.__grade>el.__grade:
            return False
        return True
    def setAssignmentID(self,ida):
        self.__ida=ida
    def setStudentID(self,ids):
        self.__ids=ids
    def setGrade(self,grade):
        self.__grade=grade
    def getAssignmentID(self):
        return self.__ida
    def getStudentID(self):
        return self.__ids
    def getGrade(self):
        return self.__grade
    def __eq__(self,x):
        if isinstance(x,Grade):
            return self.__grade==x.__grade
        return False
class StudentAssignments:
    def __init__(self,student):
        self.__student=student
        self.__assignment=[]
    def __str__(self):
        lst=''
        a=''
        for i in range(len(self.__assignment)):
            if i>0:
                lst=lst+'; ['+str(i+1)+']. '+str(self.__assignment[i])
            else:
                lst = lst+'['+str(i+1)+']. '+ str(self.__assignment[i])
        a=a+'['+str(self.__student)+'] '+': '+'['+lst+'] '
        return a
    def addTo(self,x):
        self.__assignment.append(x)
    def setStudent(self,student):
        self.__student=student
    def getStudent(self):
        return self.__student
    def getAssignment(self):
        return self.__assignment
    def getAssignmentIndex(self,index):
        return self.__assignment[index]
    def isFound(self,assignment):
        for i in range(len(self.__assignment)):
            if self.__assignment[i]==assignment:
                return True
        return False
    def studentIsFound(self,student):
        if self.__student==student:
            return True
        return False