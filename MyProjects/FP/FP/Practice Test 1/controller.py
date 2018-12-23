from repository import *
class Controller:
    def __init__(self,repo=Repository()):
        self.__repo=repo
    def __str__(self):
        '''
                Overwrites the str for this class
                :return:
                '''
        s = ''
        for i in range(len(self.__repo.getAll())):
            s = s + str(self.__repo.get(i)) + '\n'
        return s
    def add(self,element):
        '''
        Adds an element to the controller
        in:param element:
        :return:
        '''
        found=False
        for i in range(len(self.__repo.getAll())):
            if len(self.__repo.getAll())!=0 and self.__repo.get(i)==element:
                print("Element already added!")
                found=True
        if found==False:
            self.__repo.add(element)
    def getAll(self):
        '''
        Returns the repository
        :return:
        '''
        return self.__repo.getAll()
    def get(self,index):
        '''
        Returns the element from that position
        in:param index:
        :return:
        '''
        return self.__repo.get(index)
    def idIncome(self,id):
        '''
        Returns the income of a given id
        in:param id:
        :return:
        '''
        for i in range(len(self.__repo.getAll())):
            if len(self.__repo.getAll())!=0 and self.__repo.get(i).getID()==id:
                return self.__repo.get(i).income()
    def idOderValue(self,id,orderDistance):
        '''
        Returns the order price of a given distance from an id
        in:param id:
        in:param orderDistance:
        :return:
        '''
        x=self.__repo.findByID(id)
        return self.__repo.get(x).orderValue(orderDistance)
    def addOrder(self,id,distance):
        '''
        Adds an order distance to the class
        in:param id:
        in:param distance:
        :return:
        '''
        x=self.__repo.findByID(id)
        self.__repo.get(x).add(distance)