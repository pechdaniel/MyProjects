import unittest
from controller import *
from domain import *
from domain import *

class Test(unittest.TestCase):
    def testGetStudentID(self):
        s1=Student(1,'Marian',1)
        s2=Student(2,'Maria',3)
        self.assertEqual(s1.getStudentID(),1)
        self.assertEqual(s2.getStudentID(),2)
    def testGetName(self):
        s1 = Student(1, 'Marian', 1)
        s2 = Student(2, 'Maria', 3)
        self.assertEqual(s1.getName(), 'Marian')
        self.assertEqual(s2.getName(), 'Maria')
    def testGetGroup(self):
        s1 = Student(1, 'Marian', 1)
        s2 = Student(2, 'Maria', 3)
        self.assertEqual(s1.getName(), 1)
        self.assertEqual(s2.getName(), 3)
    def testGetAssignmentID(self):
        a1=Assignment(1,'Do this','7.7.7')
        a2=Assignment(2,'Make that happen','10.10.2017')
        self.assertEqual(a1.getAssignmentID(),1)
        self.assertEqual(a2.getAssignmentID(), 2)
    def testGetAssignmentDescription(self):
        a1 = Assignment(1, 'Do this', '7.7.7')
        a2 = Assignment(2, 'Make that happen', '10.10.2017')
        self.assertEqual(a1.getDescription(), 'Do this')
        self.assertEqual(a2.getDescription(), 'Make that happen')
    def testGetAssignmentDeadline(self):
        a1 = Assignment(1, 'Do this', '7.7.7')
        a2 = Assignment(2, 'Make that happen', '10.10.2017')
        self.assertEqual(a1.getDeadline(), '7.7.7')
        self.assertEqual(a2.getDeadline(), '10.10.2017')



    def testRepositoryAdd(self):
        r=Repository()
        a1 = Assignment(1, 'Do this', '7.7.7')
        a2 = Assignment(2, 'Do this', '7.7.1')
        r.add(a1)
        r.add(a2)
        self.assertEqual(r.get(0),a1)
        self.assertEqual(r.get(1),a2)
    def testRepositoryRemoveIndex(self):
        r = Repository()
        a1 = Assignment(1, 'Do this', '7.7.7')
        r.add(a1)
        r.add(a1)
        r.removeIndex(1)
        self.assertEqual(r.get(0), a1)
        self.assertEqual(len(r.getAll()), 1)



    def testControllerFindByAssiID(self):
        r = Repository()
        c=Controller(r)
        a1 = Assignment(1, 'Do this', '7.7.7')
        a2 = Assignment(2, 'Do this', '7.7.1')
        c.add(a1)
        c.add(a2)
        self.assertEqual(c.findByAssiID(1),0)
        self.assertEqual(c.findByAssiID(2), 1)
class TestData(unittest.TestCase):
    # def __init__(self):
    #     self.data = Data()
    #     for i in range(100):
    #         self.data.append(i)
    def test1(self):
        data = []
        for i in range(100):
            data.append(i)
        data = Data(data)
        j = 0
        for i in data:
            self.assertEqual(j, i)
            j += 1
    def test2(self):
        list = [2, 1, 4, 3, 16, 6, 100]
        sort(list, lambda x: x)
        for i in range(0, len(list) - 1):
            self.assertLessEqual(list[i], list[i + 1])
    def test3(self):
        data = Data()
        for i in range(100):
            data.append(i)
        result = filter(data, test)
        for i in result:
            if i % 2 == 1:
                self.assertEqual(True, False)
    def test4(self):
        data = Data([])
        data.append(1)
        self.assertEqual(len(data), 1)
        data[0] = 10
        self.assertEqual(data[0], 10)
        del data[0]
        self.assertEqual(len(data), 0)
        if _name_ == '_main_':
            unittest.main()

a=Test()
a.testGetStudentID()
a.testGetAssignmentID()
a.testGetAssignmentDescription()
a.testGetAssignmentDeadline()
a.testRepositoryAdd()
a.testRepositoryRemoveIndex()
a.testControllerFindByAssiID()
