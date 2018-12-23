import pickle
class Repository:
    def __init__(self):
        self._data=[]

    def get(self,index):
        '''
        Returns the element from the index position, -1 if it does not exist
        :param index:
        :return:
        '''
        if index>=len(self._data):
            return -1
        return self._data[index]
    def getAll(self):
        '''
        Returns self._data
        :return:
        '''
        return self._data
    def add(self,el):
        '''
        Adds an element to the list
        :param el:
        :return:
        '''
        self._data.append(el)


class PickleRepository(Repository):
    def __init__(self,fileName):
        Repository.__init__(self)
        self.__fileName=fileName
        self.__load()
    def add(self,el):
        '''
        Adds an element to the file
        :param el:
        :return:
        '''
        Repository.add(self,el)
        self.__store()
    def __load(self):
        '''
        Loads the file into self._data
        :return:
        '''
        file=open(self.__fileName,"rb")
        try:
            self._data=pickle.load(file)
        except EOFError:
            self._data=[]
        except Exception as exc:
            raise exc
        finally:
            file.close()
    def __store(self):
        '''
        Stores self._data into the file
        :return:
        '''
        file=open(self.__fileName,"wb")
        pickle.dump(self._data,file)
        file.close()
