from repository import *
class Controller:
    def __init__(self,repo=Repository()):
        self.__repo=repo
        lst=[]
        for i in range(len(repo.getAll())):
            if repo.get(i).getStatus()=='ill':
                lst.append(repo.get(i))
        self.__ill=lst
        self.__day=0
        self.__index=-1
        self.__illDays = []
        for i in range(len(lst)):
            a=[]
            a.append(lst[i])
            a.append(0)
            self.__illDays.append(a)
    def __str__(self):
        '''
        Overwrites the str function for this class
        :return:
        '''
        s=''
        for i in range(len(self.__repo.getAll())):
            s=s+str(self.__repo.get(i))+', \n'
        return s
    def vaccinate(self,id):
        '''
        Vaccinates a given person if possible
        in:param id:
        :return:
        '''
        x=self.__repo.findByID(id)
        if self.__repo.get(x).getIS()=='nonvaccinated' and self.__repo.get(x).getStatus()=='healthy':
            self.__repo.get(x).setIS('vaccinated')
        else:
            print("Person cannot be vaccinated!")
    def newDay(self):
            '''
            An ill person will infect a healthy one
            :return:
            '''
            self.__index+=1
            self.__day+=1
            n=len(self.__ill)
            for i in range(n):
                ok = 1
                if self.__illDays[i][1]<3:
                    self.__illDays[i][1]+=1
                else:
                    self.__illDays.pop(i)
                    self.__ill.pop(i)
                for j in range(len(self.__repo.getAll())):
                    if self.__repo.get(j).getStatus()=='healthy' and ok==1:
                        if self.__repo.get(j).getIS()=='nonvaccinated':
                            self.__repo.get(j).setStatus('ill')
                            self.__ill.append(self.__repo.get(j))
                            a = []
                            a.append(self.__repo.get(i))
                            a.append(0)
                            self.__illDays.append(a)
                            ok=0
            for i in range(len(self.__ill)):
                j=self.__ill[i]
                j=j.getID()
                x=self.__repo.findByID(j)
                self.__repo.get(x).setStatus('ill')
    def getAll(self):
        '''
        Returns the repository
        :return:
        '''
        return self.__repo
    def get(self,index):
        '''
        Returns the element on the given index
        in:param index:
        :return:
        '''
        return self.__repo.get(index)