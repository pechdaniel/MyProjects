class Repository:
    def __init__(self):
        self.__data=[]
    def add(self,element):
        '''
        Adds an element to the list
        in:param element:
        :return:
        '''
        self.__data.append(element)
    def __str__(self):
        '''
        Overwrites the str for this class
        :return:
        '''
        s=''
        for i in range(len(self.__data)):
            s=s+str(self.__data[i])+'; '
        return s
    def getAll(self):
        '''
        Returns the list from the repository
        :return:
        '''
        return self.__data
    def get(self,index):
        '''
        Returns an element from the list by index
        in:param index:
        :return:
        '''
        return self.__data[index]
    def findByID(self,id):
        '''
        Returns the index of an element with a specific id
        in:param id:
        :return:
        '''
        for i in range(len(self.__data)):
            if len(self.__data)!=0 and self.__data[i].getID()==id:
                return i
        return -1