from repository import *
class CSVRepo(Repository):
    def __init__(self,fileName):
        Repository.__init__(self)
        self.__fileName=fileName
        self.__loadFromFile()
    def __loadFromFile(self):
        try:
            f = open(self.__fileName, "r")
            line = f.readline().strip()
            while line != "":
                attrs = line.split(",")
                person = [attrs[0], attrs[1], attrs[2], attrs[3]]
                Repository.add(self, person)
                line = f.readline().strip()
        except IOError:
            print("Error")
        finally:
            self.__fileName.close()

    def __storeToFile(self):
        f = open(self.__fileName, "w")
        books = Repository.getAll(self)
        for book in books:
            strf = str(book[0] + "," + book[1] + "," + book[2] + "," + book[3] + "\n")
            f.write(strf)
        f.close()