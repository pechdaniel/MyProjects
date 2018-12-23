import unittest
from repository import *
from controller import *
class ControllerTest(unittest.TestCase):
    def testBlinker(self):
        a=Repository()
        b=Controller(a)
        b.blinkerV(0,0)
        self.assertEqual(b.get(1,0),1)
    def testBlock(self):
        a = Repository()
        b = Controller(a)
        b.block(0,0)
        self.assertEqual(b.get(0,0),1)
    def testTub(self):
        a = Repository()
        b = Controller(a)
        b.tub(0,0)
        self.assertEqual(b.get(0,1),1)
    def testBeacon(self):
        a = Repository()
        b = Controller(a)
        b.beacon1(0,0)
        self.assertEqual(b.get(0,0),1)
    def testTick(self):
        a = Repository()
        b = Controller(a)
        b.block(0,0)
        b.tick(1)
        self.assertEqual(b.get(7,7),0)
class RepoTest(unittest.TestCase):
    def testGet(self):
        a = Repository()
        a.add(1)
        self.assertEqual(a.get(0),1)
    def testAdd(self):
        a = Repository()
        a.add(1)
        self.assertEqual(a.get(0), 1)
    def testGetAll(self):
        a = Repository()
        a.add(1)
        self.assertEqual(a.getAll(), [1])