from repository import *
import random
class Controller:
    def __init__(self,repo=Repository()):
        self.__repo=repo
        grid=[]
        for i in range(9):
            use=[]
            for j in range(9):
                use.append(0)
            grid.append(use)
        self.__grid=grid[:]
        self.__time=1
        self.__glider=[]
        self.__blinker=[]
        self.__beacon=[]
    def __str__(self):
        '''
        Overwrites the str function for this class
        :return:
        '''
        s=''
        for i in range(8):
            s+='|'
            for j in range(8):
                if self.__grid[i][j]==0:
                    s+='   |'
                else:
                    s+=' x |'
            s+='\n'
        return s
    def blinkerH(self,i,j):
        '''
        Generates the blinker in horizontal position
        :param i:
        :param j:
        :return:
        '''
        self.__blinker.append([i,j])
        if self.__time%2==1:
            if i<0 or j<0 or i>7 or j>7:
                raise ValueError
            for k in range(i,i+3):
                for l in range(j,j+3):
                    if k==i+1:
                        if self.__grid[k][l]!=0:
                            raise ValueError
                        else:
                            self.__grid[k][l]=1
    def blinkerV(self,i,j):
        '''
        Generates the blinker in vertical position
        :param i:
        :param j:
        :return:
        '''
        self.__blinker.append([i,j])
        if self.__time%2==0:
            if i<0 or j<0 or i>7 or j>7:
                raise ValueError
            for k in range(i,i+3):
                for l in range(j,j+3):
                    if l==j+1:
                        if self.__grid[k][l]!=0:
                            raise ValueError
                        else:
                            self.__grid[k][l]=1
    def block(self,i,j):
        '''
        Generates the block
        :param i:
        :param j:
        :return:
        '''
        if i<0 or j<0 or i>7 or j>7:
            raise ValueError
        for k in range(i,i+2):
            for l in range(j,j+2):
                if self.__grid[k][l]!=0:
                    raise ValueError
                else:
                    self.__grid[k][l]=1
    def tub(self,i,j):
        '''
        Generates the tub
        :param i:
        :param j:
        :return:
        '''
        if i<0 or j<0 or i>7 or j>7:
            raise ValueError
        for k in range(i,i+3):
            for l in range(j,j+3):
                if k==i and l==j+1:
                    if self.__grid[k][l] != 0:
                        raise ValueError
                    else:
                        self.__grid[k][l]=1
                elif k==i+1 and (l==j or l==j+2):
                    if self.__grid[k][l] != 0:
                        raise ValueError
                    else:
                        self.__grid[k][l]=1
                elif k==i+2 and l==j+1:
                    if self.__grid[k][l] != 0:
                        raise ValueError
                    else:
                        self.__grid[k][l]=1
    def beacon1(self,i,j):
        '''
        Generates the first beacon
        :param i:
        :param j:
        :return:
        '''
        self.__beacon.append([i,j])
        if self.__time % 2 == 1:
            if i<0 or j<0 or i>7 or j>7:
                raise ValueError
            for k in range(i,i+4):
                for l in range(j,j+4):
                    if (k==i and l==j) or (k==i and l==j+1) or (k==i+1 and l==j) or (k==i+1 and l==j+1) or (k==i+2 and l==j+2) or\
                            (k==i+2 and l==j+3) or (k==i+3 and l==j+2) or (k==i+3 and l==+3):
                        if self.__grid[k][l] != 0:
                            raise ValueError
                        else:
                            self.__grid[k][l]=1
    def beacon2(self,i,j):
        '''
        Generates the second beacon
        :param i:
        :param j:
        :return:
        '''
        self.__beacon.append([i,j])
        if self.__time % 2 == 0:
            if i<0 or j<0 or i>7 or j>7:
                raise ValueError
            for k in range(i,i+4):
                for l in range(j,j+4):
                    if (k==i and l==j) or (k==i and l==j+1) or (k==i+1 and l==j) or\
                            (k==i+2 and l==j+3) or (k==i+3 and l==j+2) or (k==i+3 and l==+3):
                        if self.__grid[k][l] != 0:
                            raise ValueError
                        else:
                            self.__grid[k][l]=1
    def beacon(self):
        '''
        Updates the beacon
        :return:
        '''
        for p in range(len(self.__beacon)):
            i=self.__beacon[p][0]
            j=self.__beacon[p][1]
            if self.__time % 2 == 1:
                if i < 0 or j < 0 or i > 7 or j > 7:
                    raise ValueError
                for k in range(i, i + 4):
                    for l in range(j, j + 4):
                        if (k == i and l == j) or (k == i and l == j + 1) or (k == i + 1 and l == j) or (
                                k == i + 1 and l == j + 1) or (k == i + 2 and l == j + 2) or \
                                (k == i + 2 and l == j + 3) or (k == i + 3 and l == j + 2) or (k == i + 3 and l == +3):
                            if self.__grid[k][l] != 0:
                                raise ValueError
                            else:
                                self.__grid[k][l] = 1
            else:
                if i < 0 or j < 0 or i > 7 or j > 7:
                    raise ValueError
                for k in range(i, i + 4):
                    for l in range(j, j + 4):
                        if (k == i and l == j) or (k == i and l == j + 1) or (k == i + 1 and l == j) or \
                                (k == i + 2 and l == j + 3) or (k == i + 3 and l == j + 2) or (k == i + 3 and l == +3):
                            if self.__grid[k][l] != 0:
                                raise ValueError
                            else:
                                self.__grid[k][l] = 1
    def blinker(self):
        '''
        Updates the blinker
        :return:
        '''
        for p in range(len(self.__blinker)):
            i=self.__blinker[p][0]
            j=self.__blinker[p][1]
            if self.__time % 2 == 1:
                if i < 0 or j < 0 or i > 7 or j > 7:
                    raise ValueError
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        if k == i + 1:
                            if self.__grid[k][l] != 0:
                                raise ValueError
                            else:
                                self.__grid[k][l] = 1
            else:
                if i < 0 or j < 0 or i > 7 or j > 7:
                    raise ValueError
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        if l == j + 1:
                            if self.__grid[k][l] != 0:
                                raise ValueError
                            else:
                                self.__grid[k][l] = 1
    def addGlider(self,i,j):
        '''
        Adds the position of the glider to the list of gliders
        :param i:
        :param j:
        :return:
        '''
        self.__glider.append([i,j])
    def changeGlider(self):
        '''
        Randomises the gliders of the list
        :return:
        '''
        if self.__time%4==0:
            for k in range(len(self.__glider)):
                i=self.__glider[k][0]
                j=self.__glider[k][1]
                for m in range(4):
                    for n in range(4):
                        self.__grid[m][n]=0
                for m in range(5):
                    repeat=True
                    n=None
                    o=None
                    while repeat==True:
                        repeat=False
                        n=random.randint(i,i+3)
                        o=random.randint(j,j+3)
                        if self.__grid[n][o]==1:
                            repeat=True
                    self.__grid[n][o]=1
    def store(self):
        '''
        Stores into the file
        :return:
        '''
        self.__repo=self.__grid
    def load(self):
        """
        Loads from the file
        :return:
        """
        self.__grid=self.__repo
    def tick(self,value):
        '''
        Simulates a generation
        :return:
        '''
        self.__time+=value
        for p in range(value+1):
            self.changeGlider()
            self.blinker()
            self.beacon()
            for i in range(8):
                count = 0
                for j in range(8):
                    if self.__grid[i-1][j-1]==1 and i-1>=0 and i-1<8 and j-1>=0 and j-1<8:
                        count+=1
                    if self.__grid[i-1][j+1]==1 and i-1>=0 and i-1<8 and j+1>=0 and j+1<8:
                        count+=1
                    if self.__grid[i-1][j]==1 and i-1>=0 and i-1<8 and j>=0 and j<8:
                        count+=1
                    if self.__grid[i+1][j+1]==1 and i+1>=0 and i+1<8 and j+1>=0 and j+1<8:
                        count+=1
                    if self.__grid[i+1][j-1]==1 and i+1>=0 and i+1<8 and j-1>=0 and j-1<8:
                        count+=1
                    if self.__grid[i+1][j]==1 and i+1>=0 and i+1<8 and j>=0 and j<8:
                        count+=1
                    if self.__grid[i][j+1]==1 and i>=0 and i<8 and j+1>=0 and j+1<8:
                        count+=1
                    if self.__grid[i][j-1]==1 and i>=0 and i<8 and j-1>=0 and j-1<8:
                        count+=1

                    if count<2:
                        self.__grid[i][j]=0
                    elif count>3:
                        self.__grid[i][j]=0
                    elif count==3 and self.__grid[i][j]==0:
                        self.__grid[i][j]=1
    def get(self,i,j):
        return self.__grid[i][j]