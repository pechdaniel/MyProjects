from domain import *
class Repository:
    def __init__(self):
        self.__data=[]
    def add(self,el):
        '''
        Adds an element to the list
        in:param el:
        :return:
        '''
        self.__data.append(el)
    def getAll(self):
        '''
        Returns the list
        :return:
        '''
        return self.__data
    def get(self,index):
        '''
        Returns the element from that given index
        in:param index:
        :return:
        '''
        if index<len(self.__data):
            return self.__data[index]
    def findByID(self,id):
        '''
        Returns the index of the element with the given id
        in:param id:
        :return:
        '''
        for i in range(len(self.__data)):
            if self.__data[i].getID()==id:
                return i
        return -1