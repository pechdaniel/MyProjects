import  pickle
import unittest
from repository import *
class Pickle(Repository):
    def __init__(self,fileName):
        Repository.__init__(self)
        self.__fileName=fileName
        self.__load()
    def add(self,lol):
        Repository.add(self,lol)
        self.__store()
    def __load(self):
        file=open(self.__fileName,"rb")
        try:
            self._data=pickle.load(file)
        except EOFError:
            self.__data=[]
        except Exception as exc:
            raise exc
        finally:
            file.close()
    def __store(self):
        file=open(self.__fileName,"wb")
        pickle.dump(self.__data,file)
        file.close()

class Test(unittest.TestCase):
    def testLol(self):
        a=Repository()