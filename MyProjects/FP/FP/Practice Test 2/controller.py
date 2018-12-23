from repository import *
from math import sqrt
class Controller:
    def __init__(self,repo=Repository()):
        self.__repo=repo
    def __str__(self):
        '''
        Overwrites the str function for this class
        :return:
        '''
        s=''
        for i in range(len(self.__repo.getAll())):
            s=s+str(self.__repo.get(i))+'\n'
        return s
    def add(self,el):
        '''
        Adds an element to the list if it is valid
        in:param el:
        :return:
        '''
        ok=1
        for i in range(len(self.__repo.getAll())):
            if len(self.__repo.getAll()) and self.__repo.get(i).getID()==el.getID():
                print("ID already exists!")
                ok=0

            if int(el.getID())==el.getID() and el.GetID()<=0:
                print("ID is not valid!")
                ok=0
        if len(el.getName())<3:
            print("Name is too short!")
            ok=0
        if el.getX()<0 and el.getX()>100:
            print("Coordinate not valid!")
            ok=0
        if el.getY()<0 and el.getY()>100:
            print("Coordinate not valid!")
            ok = 0
        if ok ==1:
            self.__repo.add(el)
    def distanceAddress(self,d,x,y):
        '''
        Returns a list with all the addresses that are far from the given position by d
        in:param d:
        in:param x:
        in:param y:
        :return:
        '''
        lst=[]
        for i in range(len(self.__repo.getAll())):
            m=(self.__repo.get(i).getX()-x)**2
            n=(self.__repo.get(i).getY()-y)**2
            d1=sqrt(m)+sqrt(n)
            if d1<=d:
                lst.append(self.__repo.get(i))
        for i in range(len(lst)):
            print(lst[i])