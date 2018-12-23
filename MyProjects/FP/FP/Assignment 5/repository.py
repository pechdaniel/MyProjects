import pickle

from domain import *
class Repository:
    def __init__(self):
        self._data=[]
    def __str__(self):
        '''

        out:return: the string of the repository
        '''
        s=''
        for i in range(len(self._data)):
            s+='['+str(i+1)+']. '+str(self._data[i]) + '\n'
        return s
    def add(self,element):
        '''
        Adds an element to the repository
        in:param element:
        '''
        self._data.append(element)
    def remove(self,element):
        '''
        Removes an elemen from the repository
        in:param element:
        '''
        for i in range(len(self._data)):
            if self._data[i]==element:
                self._data.pop(i)
    def removeIndex(self,index):
        '''
        Removes an index from the repository
        in:param index:
        '''
        if index>=0 or index <len(self._data):
            self._data.pop(index)
    def getAll(self):
        '''
        Returns the repository
        out :return:self.__data
        '''
        return self._data
    def get(self,index):
        '''
        Returns the element from the given index
        in:param index:
        out:return:element
        '''
        return self._data[index]
    def findElement(self,element):
        '''
        Returns the index of the element, -1 if not found
        in:param element:
        out:return: index
        '''
        for i in range(len(self._data)):
            if self._data[i]==element:
                return i
        return -1

    def update(self,old,new):
        '''
        Updates the old element with the new element
        :param old:
        :param new:
        :return:
        '''
        for i in range(len(self._data)):
            if self._data[i]==old:
                self._data[i]=new
    def groupList(self,group):
        '''
        Returns a list of the entire group
        in:param group:
        out:return:lst
        '''
        lst=[]
        for i in range(len(self._data)):
            if self._data[i].getGroup()==group:
                lst.append(self._data[i])
        return lst
    def giveAssignmentToStudent(self,student,assignment):
        '''
        Gives an assignment to a student
        in:param student:
        in:param assignment:
        :return:
        '''
        ok=0
        for i in range(len(self._data)):
            ok=1
            if self._data[i].getStudent()==student and self._data[i].isFound(assignment)==False:
                self._data[i].addTo(assignment)
            else:
                a = StudentAssignments(student)
                a.addTo(assignment)
                self._data.append(a)
        if ok==0:
            a=StudentAssignments(student)
            a.addTo(assignment)
            self._data.append(a)
    def giveAssignmentToGroup(self,group,assignment,lst):
        '''
        Gives an assignment to an entire group
        in:param group:
        in:param assignment:
        :return:
        '''
        for i in range(len(lst)):
            ok=-1
            for j in range(len(self._data)):
                if self._data[j].getStudent==lst[i]:
                    ok=j
                if self._data[ok].isFound(assignment)==False:
                    ok=-1
            if ok!=-1:
                self._data[ok].addTo(assignment)
            elif self._data[ok].isFound(assignment)==False:
                a=StudentAssignments(lst[i])
                a.addTo(assignment)
                self._data.append(a)
        if len(self._data)==0:
            for i in range(len(lst)):
                a = StudentAssignments(lst[i])
                a.addTo(assignment)
                self._data.append(a)

class PickleRepository(Repository):
    def __init__(self,fileName):
        Repository.__init__(self)
        self.__fileName=fileName
        self.__load()
    def add(self,el):
        Repository.add(self,el)
        self.__store()
    def remove(self,index):
        Repository.removeIndex(self,index)
        self.__store()
    def update(self,old,new):
        Repository.update(self,old,new)
        self.__store()
    def __load(self):
        file=open(self.__fileName,"rb")
        try:
            self._data=pickle.load(file)
        except EOFError:
            self._data=[]
        except Exception as exc:
            raise exc
        finally:
            file.close()
    def __store(self):
        file=open(self.__fileName,"wb")
        pickle.dump(self._data, file)
        file.close()

def update_gap(gap):
    gap = (gap * 10) / 13
    if gap == 9 or gap == 10:
        gap = 11
    return int(max(1, gap))

def combsort(x):
    gap = len(x)
    swapped = True
    if gap < 2:
        return
    while gap > 1 or swapped:
        gap = update_gap(gap)
        swapped = False
        for i in range(0, len(x) - gap):
            if x[i] > x[i + gap]:
                x[i], x[i + gap] = x[i + gap], x[i]
                swapped = True