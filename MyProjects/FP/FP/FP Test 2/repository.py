class Repository:
    def __init__(self):
        self.__data=[]
    def __str__(self):
        s=''
        for i in range(len(self.__data)):
            s=s+str(self.__data[i])+', '
        return s
    def getAll(self):
        return self.__data
    def get(self,index):
        return self.__data[index]
    def findByID(self,id):
        for i in range(len(self.__data)):
            if self.__data[i].getID()==id:
                return i
        return -1
    def add(self,el):
        el.setID(int(el.getID()))
        self.__data.append(el)