class Person:
    def __init__(self,id,immus,status):
        self.__id=id
        self.__is=immus
        self.__status=status
    def __str__(self):
        s=''
        s=s+'Person ID: '+str(self.__id)+' Immunization status: '+str(self.__is)+' Status: '+str(self.__status)
        return s
    def getID(self):
        return self.__id
    def getIS(self):
        return self.__is
    def getStatus(self):
        return self.__status
    def setIS(self,status):
        self.__is=status
    def setStatus(self,status):
        self.__status=status
    def setID(self,id):
        self.__id=id