class Driver:
    def __init__(self,id,name):
        self.__id=id
        self.__name=name
    def __str__(self):
        s=''
        s=s+'ID: '+str(self.__id)+' Name: '+str(self.__name)
        return s
    def setID(self,id):
        self.__id=id
    def setName(self,name):
        self.__name=name
    def getID(self):
        return self.__id
    def getName(self):
        return self.__name

class Order:
    def __init__(self,driverID,dist):
        self.__id=driverID
        self.__distance=dist
    def __str__(self):
        s=''
        s=s+'Driver ID: '+str(self.__id)+' Distance traveled: '+str(self.__distance)
        return s
    def setID(self,id):
        self.__id=id
    def setDistance(self,dist):
        self.__distance=dist
    def getID(self):
        return self.__id
    def getDistance(self):
        return self.__distance

class DriverOrders:
    def __init__(self,id):
        self.__orders=[]
        self.__id=id
    def add(self,el):
        if el<1:
            print("Distance not valid!")
        else:
            self.__orders.append(el)
    def getOrders(self):
        return self.__orders
    def getID(self):
        return self.__id
    def income(self):
        s=0
        if len(self.__orders)==0:
            return 0
        for i in range(len(self.__orders)):
            s=s+self.__orders[i]
        return s*2.5
    def orderValue(self,index):
        if index <len(self.__orders):
            s=self.__orders[index]
            return s*2.5
        return -1