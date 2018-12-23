import sys
def populateTheGraph():
    '''
    Constructs and returns a undirected graph
    '''
    f = open("test.txt", "r")
    line = f.readline().strip()
    attrs = line.split(" ")
    n = int(attrs[0])
    m = int(attrs[1])
    graf = Graph(n)
    line = f.readline().strip()
    while m != 0:
        attrs = line.split(" ")
        v1 = int(attrs[0])
        v2 = int(attrs[1])
        cost = int(attrs[2])
        graf.graph[v1][v2] = cost
        graf.graph[v2][v1] = cost
        line = f.readline().strip()
        m = m - 1
    f.close()
    return graf

def start():
    graf = populateTheGraph()
    graf.PRIM()
class Graph():

    def __init__(self, n):
        self.Vertices = n
        self.graph = [[0 for column in range(n)] for row in range(n)]

    def existMinPath(self, pathTree):
        for i in range(1, self.Vertices):
            if (pathTree[i] == None):
                return 0
        return 1

    def printMST(self, pathTree):
        if (self.existMinPath(pathTree) == 0):
            print("Doesn`t exist a minimal tree path in the graf")
        else:
            print ("Muchie  Cost")
            for i in range(1, self.Vertices):
                print (pathTree[i], "-", i, "  ", self.graph[i][pathTree[i]])

    def printGraf(self):
        for i in range(0, self.Vertices):
            for j in range(0, self.Vertices):
                print(self.getItem(i, j), ' ')
            print("\n")

    def getItem(self, i, j):
        return self.graph[i][j]


    def minKey(self, costMin, inPathTree):
        '''
        Gaseste distanta cu costul minim dintre muchiile care nu au
        fost inca adaugate in shortest path tree
        '''
        min = sys.maxsize
        min_index = -1
        for v in range(self.Vertices):
            if costMin[v] < min and inPathTree[v] == False:
                min = costMin[v]
                min_index = v

        return min_index

    def PRIM(self):

        costMin = [sys.maxsize] * self.Vertices
        pathTree = [None] * self.Vertices
        costMin[0] = 0
        inPathTree = [False] * self.Vertices
        pathTree[0] = -1
        for cout in range(self.Vertices):
            # Pick the minimum distance vertex from the set of vertices not
            minVertex = self.minKey(costMin, inPathTree)
            # Put the minimum distance vertex in the shortest path tree
            inPathTree[minVertex] = True
            for v in range(self.Vertices):
                '''
                Daca graph[minVertex][v] nu este 0 doar daca este muchie intre minVertex si v
                inPathTree[v] este false pentru muchiile care nu sunt incluse inca 
                in path
                '''
                if self.graph[minVertex][v] > 0 and inPathTree[v] == False and costMin[v] > self.graph[minVertex][v]:
                    costMin[v] = self.graph[minVertex][v]
                    pathTree[v] = minVertex

        self.printMST(pathTree)

start()