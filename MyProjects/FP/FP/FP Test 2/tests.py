import unittest
from controller import *
from domain import *
from domain import *

class Test(unittest.TestCase):

    def testControllerFindByAssiID(self):
        r = Repository()
        a1 = Person(1, 'Do this', '7.7.7')
        a2 = Person(2, 'Do this', '7.7.1')
        r.add(a1)
        r.add(a2)
        c = Controller(r)
        self.assertEqual(c.(1),0)
        self.assertEqual(c.findByAssiID(2), 1)


a=Test()
a.testControllerFindByAssiID()