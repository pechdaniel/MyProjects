import heapq

class Cost:
    def __init__(self):
        self._cost = {}

    def get(self):
        return self._cost
    def addCost(self, x, y, c):
        try:
            self._cost[(x, y)] = c
        except ValueError:
            print("There's no edge from " + str(x) + " to " + str(y) + "\n")

    def removeCost(self, x, y):
        try:
            del self._cost[(x, y)]
        except ValueError:
            print("There's no edge from " + str(x) + " to " + str(y) + "\n")

    def getCost(self, x, y):
        try:
            return self._cost[(x, y)]
        except ValueError:
            print("There's no edge from " + str(x) + " to " + str(y) + "\n")

    def setCost(self, x, y, newC):
        try:
            self._cost[(x, y)] = newC
        except ValueError:
            print("There's no edge from " + str(x) + " to " + str(y) + "\n")

class DirectGraph:
    def __init__(self, n):
        self._dictIn = {}
        self._dictOut = {}
        for i in range(n):
            self._dictIn[i] = []
            self._dictOut[i] = []

    def parseDict(self):
        return self._dictOut.keys()

    def length(self):
        return len(self._dictOut.keys())

    def parseOut(self, x):
        if x in self._dictOut.keys():
            return self._dictOut[x]
        else:
            print(str(x) + " is not a vertex")

    def parseIn(self, x):
        if x in self._dictIn.keys():
            return self._dictIn[x]
        else:
            print(str(x) + " is not a vertex")

    def isEdge(self, x, y):
        if x in self._dictOut.keys():
            return y in self._dictOut[x]
        else:
            print("There's no edge from " + str(x) + " to " + str(y) + "\n")

    def addEdge(self, x, y):
        if not self.isEdge(x, y):
            self._dictOut[x].append(y)
            self._dictIn[y].append(x)
        else:
            print("Edge already exists!\n")

    def removeEdge(self, x, y):
        if self.isEdge(x, y):
            self._dictOut[x].remove(y)
            self._dictIn[y].remove(x)
        else:
            print("Edge does not exists!\n")

    def addVertex(self, x):
        if not x in self._dictOut.keys():
            self._dictIn[x] = []
            self._dictOut[x] = []
        else:
            print("Vertex already exists! \n")

    def removeVertex(self, x):
        if x in self._dictOut.keys():
            for y in self._dictOut[x]:
                self._dictIn[y].remove(x)
            del self._dictOut[x]
            for y in self._dictIn[x]:
                self._dictOut[y].remove(x)
            del self._dictIn[x]
        else:
            print(str(x) + " is not a vertex! \n")

    def inDegree(self, x):
        return len(self._dictIn[x])

    def outDegree(self, x):
        return len(self._dictOut[x])

def initGraph(DirectGraph):

    f = open("input", "r")

    initLine = f.readline().strip()

    initLine = initLine.split(" ")
    n = int(initLine[0])
    m = int(initLine[1])

    graph = DirectGraph(n)
    cost = Cost()
    line = f.readline().strip()

    while m > 0:
        line = line.split(" ")

        x = int(line[0])
        y = int(line[1])
        c = int(line[2])

        graph.addEdge(x, y)
        cost.addCost(x, y, c)

        line = f.readline().strip()

        m -= 1
    f.close()
    return graph, cost

def retrievePath(endVertex, parent):
    if endVertex not in parent.keys():
        return None
    list = []
    while endVertex is not None:
        list.append(endVertex)
        endVertex = parent[endVertex]
    list.reverse()
    return list


def MatrixMultiplication(graph, cost, start, end):
    queue = []
    heapq.heappush(queue, (0, start))
    dist = {start: 0}
    prev = {start: None}
    while queue:
        d, x = heapq.heappop(queue)
        for y in graph.parseOut(x):
            if y not in prev.keys() or dist[y] > dist[x] + cost[(x, y)]:
                prev[y] = x
                dist[y] = dist[x] + cost[(x, y)]
                heapq.heappush(queue, (dist[y], y))
    return retrievePath(end, prev), dist[end]

def menu():
    print("1. Add a edge")
    print("2. Remove a edge")
    print("3. Add a vertex")
    print("4. Remove a vertex")
    print("5. Print the graph")
    #print("6. Get the number of vertices")
    #print("7. Verify if there is an edge")
    #print("8. In degree and out degree of a vertex")
    #print("9. The outbound edges of a vertex")
    #print("10. The inbound edges of a vertex")
    #print("11. Get the cost of an edge")
    #print("12. Modify the cost of an edge")
    print("6. The lowest cost walk between two vertices.")
    print("0. Exit")

def start():
    graph, cost = initGraph(DirectGraph)

    while True:
        menu()
        option = int(input("Choose: "))
        if option < 0 or option > 13:
            print("Invalid command!\n")
        elif option == 0:
            break
        elif option == 1:
            x = int(input("First vertex: "))
            y = int(input("Second vertex: "))
            c = int(input("The cost: "))
            graph.addEdge(x, y)
            cost.addCost(x, y, c)
        elif option == 2:
            x = int(input("First vertex: "))
            y = int(input("Second vertex: "))
            graph.removeEdge(x, y)
            cost.removeCost(x, y)
        elif option == 3:
            x = int(input("Vertex: "))
            graph.addVertex(x)
        elif option == 4:
            x = int(input("Vertex: "))
            graph.removeVertex(x)
        elif option == 5:
            for x in graph.parseDict():
                for y in graph.parseOut(x):
                    print("[" + str(x) + " , " + str(y) + "]" + " -> " + str(cost.getCost(x, y)))
        elif option == 13:
            vertices = graph.length()
            print("There are " + str(vertices) + " vertices!\n")
        elif option == 7:
            x = int(input("First vertex: "))
            y = int(input("Second vertex: "))
            if graph.isEdge(x, y) == 1:
                print("There's an edge from " + str(x) + " to " + str(y))
            else:
                print("There's no edge from " + str(x) + " to " + str(y))
        elif option == 8:
            x = int(input("Vertex: "))
            print(graph.inDegree(x))
            print(graph.outDegree(x))
        elif option == 9:
            ok = 1
            x = int(input("Vertex: "))
            for y in graph.parseOut(x):
                print("[" + str(x) + " , " + str(y) + "]")
                ok = 0
            if ok == 1:
                print("There are no outbound edges!\n")
        elif option == 10:
            ok = 1
            x = int(input("Vertex: "))
            for y in graph.parseIn(x):
                print("[" + str(y) + " , " + str(x) + "]")
                ok = 0
            if ok == 1:
                print("There are no inbound edges!\n")
        elif option == 11:
            x = int(input("First vertex: "))
            y = int(input("Second vertex: "))
            print("The cost is: " + str(cost.getCost(x, y)))
        elif option == 12:
            x = int(input("First vertex: "))
            y = int(input("Second vertex: "))
            newC = int(input("The new cost: "))
            cost.setCost(x, y, newC)
        elif option == 6:
            x = int(input("Start vertex: "))
            y = int(input("End vertex: "))
            print(MatrixMultiplication(graph, cost.get(), x, y))

start()
