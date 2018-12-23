from repository import *
from domain import *
import unittest
class Controller:
    def __init__(self,repo=Repository()):
        self.__repo=repo
    def __str__(self):
        '''
        Returns the string of the controller
        :return:
        '''
        s=''
        for i in range(len(self.__repo.getAll())):
            s+='['+str(i+1)+']. '+str(self.__repo.get(i))+'\n'
        return s
    def __len__(self):
        return len(self.__repo.getAll())
    def getAll(self):
        '''
        Returns the repository
        :return:
        '''
        return self.__repo
    def get(self,index):
        '''
        Returns the element from the given index
        in:param index:
        :return:
        '''
        return self.__repo.get(index)
    def add(self,el):
        '''
        Adds an element to the controller repository
        :return:
        '''
        self.__repo.add(el)
    def remove(self,element):
        '''
        Removes an element from the controller repository
        :param element:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i)==element:
                self.__repo.remove(element)
    def removeIndex(self,index):
        '''
        Removes an index from the controller repository
        :param index:
        :return:
        '''
        self.__repo.removeIndex(index)
    def update(self,old,new):
        '''
        Updates an element from the controller repo with a new one
        in:param old:
        in:param new:
        :return:
        '''
        self.__repo.update(old,new)
    def findByAssiID(self,id):
        '''
        Returns the index of the element with the given id, -1 if it doesn't exist
        in:param id:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).getAssignmentID()==id:
                return i
        return -1
    def findByStuID(self,id):
        '''
        Returns the index of the element with the given id, -1 if it doesn't exist
        in:param id:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).getStudentID()==id:
                return i
        return -1
    def groupList(self,group):
        '''
        Returns a list of the entire group
        in:param group:
        out:return:lst
        '''
        lst=self.__repo.groupList(group)
        return lst
    def giveAssignmentToStudent(self,student,assignment):
        '''
        Gives an assignment to a student
        in:param student:
        in:param assignment:
        :return:
        '''
        self.__repo.giveAssignmentToStudent(student,assignment)
    def giveAssignmentToGroup(self,group,assignment,lst):
        '''
        Gives an assignment to an entire group
        in:param group:
        in:param assignment:
        :return:
        '''
        self.__repo.giveAssignmentToGroup(group,assignment,lst)
    def deleteStudentAssignments(self,student):
        '''
        Deletes the assignments along the student
        in:param student:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).getStudent()==student:
                self.__repo.removeIndex(i)
    def findStudent(self,student):
        '''
        Returns the index of the student, -1 if it is not found
        in:param student:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).studentIsFound(student)==True:
                return i
        return -1
    def deleteStudent(self,id):
        '''
        Deletes the student from the grade repository
        in:param student:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).getStudentID()==id:
                self.__repo.removeIndex(i)
    def deleteAssignment(self,id):
        '''
        Deletes the assignment from the grade repository
        in:param assignment:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).getAssignmentID()==id:
                self.__repo.removeIndex(i)
    def assignmentList(self,index):
        '''
        Returns the list of assignments of an index
        in:param index:
        :return:
        '''
        lst=[]
        for i in range(len(self.__repo.get(index).getAssignment())):
            lst.append(self.__repo.get(index).getAssignmentIndex(i))
        return lst
    def averageGrade(self,id1,lst):
        '''
        Returns the average grade, -1 if not all the assignments are graded
        in:param student:
        in:param lst:
        :return:
        '''
        s=0
        for i in range(len(lst)):
            id2=lst[i].getAssignmentID()
            k=0
            for j in range(len(self.__repo.getAll())):
                if id1==self.__repo.get(j).getStudentID() and id2==self.__repo.get(j).getAssignmentID():
                    k=1
                    s+=self.__repo.get(j).getGrade()
            if k==0:
                return -1
        return s/(len(lst))
    def notInTimeID(self):
        '''
        Returns a list with all the student ids that didn't finish in time
        :return:
        '''
        lst=[]
        i=0
        while i<len(self.__repo.getAll()):
            if self.__repo.get(i).getGrade()==-1:
                lst.append(self.__repo.get(i).getStudentID())
            i+=1
        return lst
    def notInTime(self,lst):
        '''
        Returns a list of all the student that didn't finish in time
        in:param lst:
        :return:
        '''
        l=[]
        for i in range(len(lst)):
            for j in range(len(self.__repo.getAll())):
                if self.__repo.get(j).getStudentID()==lst[i]:
                    l.append(self.__repo.get(i))
        return l
    def repoList(self):
        '''
        Returns a list of the repository
        :return:
        '''
        lst=[]
        for i in range(len(self.__repo.getAll())):
            lst.append(self.__repo.get(i))
        return lst
    def filterByGrade(self,grade):
        '''
        Filters the controller so only the grades that are greater or equal than the given grade.
        in:param grade:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i).getGrade()<grade:
                self.__repo.removeIndex(i)



class Data:
    def __init__(self, data):
        self._data = data
        self._idx = 0
    def __iter__(self):
        return self
    def __next__(self):
        try:
            item = self._data[self._idx]
        except IndexError:
            raise StopIteration()
        self._idx += 1
        return item
    def __setitem__(self, key, value):
        self._data[key] = value
    def __delitem__(self, key):
        del self._data[key]
    def __len__(self):
        return len(self._data)
    def __getitem__(self, idx):
        return self._data[idx]
    def append(self, value):
        self._data.append(value)

def sort(myList, key = lambda x: x, reverse = False ):
    '''
    Gnome sort
    :return:
    '''
    pos = 0
    while pos < len(myList):
        if pos == 0 or key(myList[pos]) >= key(myList[pos - 1]):
            pos = pos + 1
        else:
            myList[pos], myList[pos - 1] = myList[pos - 1], myList[pos]
            pos = pos - 1
    if reverse == True:
        myList = reversed(myList)

    return myList

def filter(myList, condition):
    '''
    myList is an iterable data structure
    condition is a function
    :param myList:
    :param condition:
    :return:
    '''
    result = []
    for i in myList:
        if condition(i):
            result.append(i)
    return result

def test(item):
    if item % 2 == 0:
        return True
    return False