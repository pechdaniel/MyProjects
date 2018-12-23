from repository import *
from controller import *

class UI:
    def __init__(self,controller=Controller()):
        self.__c=controller
    def printMenu(self):
        menu=''
        menu+='place <pattern> <x,y>\n'
        menu+='tick [n]\n'
        menu+='save filename\n'
        menu+='load filename\n'
        print(menu)
    def start(self):
        self.printMenu()
        while True:
            try:
                while True:
                    x=None
                    print(self.__c)
                    repeat=True
                    while repeat==True:
                        repeat=False
                        x=input('Enter the command:')
                        x=x.strip()
                        x=x.split()
                        if len(x)==3 and x[0]!='place':
                            repeat=True
                    if x[0]=='place':
                        a=x[2].split(',')
                        a[0]=int(a[0])
                        a[1]=int(a[1])
                        if x[1]=='block':
                            self.__c.block(a[0],a[1])
                        elif x[1]=='tub':
                            self.__c.tub(a[0],a[1])
                        elif x[1]=='blinker':
                            self.__c.blinkerH(a[0],a[1])
                            self.__c.blinkerV(a[0], a[1])
                        elif x[1]=='beacon':
                            self.__c.beacon1(a[0],a[1])
                            self.__c.beacon2(a[0],a[1])
                        elif x[1]=='glider':
                            self.__c.addGlider(a[0],a[1])
                    elif x[0]=='tick':
                        a=int(x[1])
                        self.__c.tick(a)
                    elif x[0]=='store':
                        self.__c.store()
                    elif x[0]=='load':
                        self.__c.load()
            except:
                print('Invalid input!')


