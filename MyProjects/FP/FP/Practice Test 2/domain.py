class Address:
    def __init__(self,id,name,x,y):
        self.__id=id
        self.__name=name
        self.__x=x
        self.__y=y
    def __str__(self):
        s=''
        s=s+'Address id: '+str(self.__id)+' Address name: '+str(self.__name)+' Address coordinates: '+str(self.__x)+', '+str(self.__y)
        return s
    def getID(self):
        return self.__id
    def getName(self):
        return self.__name
    def getX(self):
        return self.__x
    def getY(self):
        return self.__y