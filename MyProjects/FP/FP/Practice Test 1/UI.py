from controller import *
from domain import *
from repository import *
class UI:
    def __init__(self,driverController=Controller(),orderController=Controller(),incomeController=Controller()):
        self.__dc=driverController
        self.__oc=orderController
        self.__ic=incomeController
    def readDriver(self):
        x=int(input("Enter the driver's id:"))
        y=input("Enter the driver's name:")
        a=Driver(x,y)
        return a
    def readOrder(self):
        x = int(input("Enter the driver's id:"))
        y=int(input("Enter the distance:"))
        a=Order(x,y)
        return a
    def printMenu(self):
        dMenu=''
        dMenu+='The current commands are:\n'
        dMenu+="1. Add a driver\n"
        dMenu+="2. Add an order\n"
        dMenu+="3. List the drivers\n"
        dMenu+="4. List the orders\n"
        dMenu+="5. List the income of a driver\n"
        dMenu+="6. Print the income from an order of a driver\n"
        dMenu+="0. Exit\n"
        dMenu+="help\n"
        print(dMenu)
    def start(self):
        self.printMenu()
        while True:
            command=input("Enter a command:")
            if command=='0':
                break
            elif command=='help':
                self.printMenu()
            elif command=='1':
                x=self.readDriver()
                y=DriverOrders(x.getID())
                self.__ic.add(y)
                self.__dc.add(x)
            elif command=='2':
                x=self.readOrder()
                y=x.getID()
                z=x.getDistance()
                self.__ic.addOrder(y,z)
                self.__oc.add(x)
            elif command=='3':
                print(self.__dc)
            elif command=='4':
                print(self.__oc)
            elif command=='5':
                x=int(input("Enter the driver's id:"))
                y=self.__ic.idIncome(x)
                print('The income is: ',y)
            elif command=='6':
                x=int(input("Enter the driver's id:"))
                y=int(input("Enter the number of the order:"))
                y=y+1
                z=self.__ic.idOderValue(x,y)
                print('The income is: ',z)