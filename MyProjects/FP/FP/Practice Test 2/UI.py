from controller import *
from repository import *
from domain import *
class UI:
    def __init__(self,addressController=Controller()):
        self.__ac=addressController
    def readAddress(self):
        x=int(input("Enter the address ID:"))
        y=input("Enter the address name:")
        z=int(input("Enter the x value:"))
        t=int(input("Enter the y value:"))
        a=Address(x,y,z,t)
        return a
    def printMenu(self):
        aMenu="1. Add an address to the list\n"
        aMenu+="2. List all addresses\n"
        aMenu+="3. List the addresses that are in the distance d of a given position\n"
        aMenu+="0. Exit\n"
        aMenu+="help"
        print(aMenu)
    def printList(self,lst):
        for i in range(len(lst)):
            print(lst[i])
    def start(self):
        self.printMenu()
        while True:
            command=input("Enter the command:")
            if command=='0':
                break
            elif command =='help':
                self.printMenu()
            elif command=='1':
                a=self.readAddress()
                self.__ac.add(a)
            elif command=='2':
                print(self.__ac)
            elif command=='3':
                d = int(input("Enter the maximum distance:"))
                x = int(input("Enter the x value:"))
                y = int(input("Enter the y value:"))
                self.__ac.distanceAddress(d,x,y)
            else:
                print("Invalid command!")