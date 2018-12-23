from repository import *
from controller import *
from domain import *
class UI:
    def __init__(self,personController=Controller()):
        self.__pc=personController
    def printMenu(self):
        menu='The commands are:\n'
        menu+='day (simulates a new day)\n'
        menu+='vaccinate <person id>\n'
        menu+='print\n'
        menu+='exit'
        print(menu)
    def start(self):
        self.printMenu()
        while True:
            command=input("Enter the command:")
            command=command.split()
            if command[0]=='day':
                self.__pc.newDay()
            elif command[0]=='vaccinate':
                command[1]=int(command[1])
                self.__pc.vaccinate(command[1])
            elif command[0]=='print':
                print(self.__pc)
            elif command[0]=='exit':
                break