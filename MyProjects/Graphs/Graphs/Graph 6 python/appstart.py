class Cost:
    def __init__(self):
        self._cost = {}

    def addCostToEdge(self, v1, v2, c):
        try:
            self._cost[(v1, v2)] = c
        except ValueError:
            print("No edge! " + str(v1) + " " + str(v2) + "\n")

    def getCostFromEdge(self, v1, v2):
        try:
            return self._cost[(v1, v2)]
        except ValueError:
            print("No edge! " + str(v1) + " " + str(v2) + "\n")

    def setCostOfEdge(self, v1, v2, newCost):
        try:
            self._cost[(v1, v2)] = newCost
        except ValueError:
            print("No edge! " + str(v1) + " " + str(v2) + "\n")

class DirectGraph:
    def __init__(self, n):
        self._verticeIn = {}
        self._verticeOut = {}
        for i in range(n):
            self._verticeIn[i] = []
            self._verticeOut[i] = []

    def parseDict(self):
        return self._verticeOut.keys()

    def length(self):
        return len(self._verticeOut.keys())

    def parseVerticeOut(self, vertice):
        if vertice in self._verticeOut.keys():
            return self._verticeOut[vertice]
        else:
            print(str(vertice) + " is not a vertex")

    def parseVerticeIn(self, vertice):
        if vertice in self._verticeIn.keys():
            return self._verticeIn[vertice]
        else:
            print(str(vertice) + " is not a vertex")

    def isEdge(self, v1, v2):
        if v1 in self._verticeOut.keys():
            return v2 in self._verticeOut[v1]
        else:
            print("No edge! " + str(v1) + " " + str(v2) + "\n")

    def addEdge(self, v1, v2):
        if not self.isEdge(v1, v2):
            self._verticeOut[v1].append(v2)
            self._verticeIn[v2].append(v1)
        else:
            print("Edge already there!\n")

    def inDegree(self, vertice):
        return len(self._verticeIn[vertice])

    def outDegree(self, vertice):
        return len(self._verticeOut[vertice])

def initGraph(DirectGraph):

    f = open("in", "r")

    Line = f.readline().strip()

    Line = Line.split(" ")
    n = int(Line[0])
    m = int(Line[1])

    graph = DirectGraph(n)
    cost = Cost()
    lines = f.readline().strip()

    while m > 0:
        lines = lines.split(" ")

        v1 = int(lines[0])
        v2 = int(lines[1])
        c = int(lines[2])

        graph.addEdge(v1, v2)
        cost.addCostToEdge(v1, v2, c)

        lines = f.readline().strip()

        m -= 1
    f.close()
    return graph, cost

def menu():
    print("1. Print the graph")
    print("2. Get the number of vertices")
    print("3. Given two vertices, find out whether there is an edge from the first one to the second one, and retrieve ")
    print("   the Edge_id if there is an edge (the latter is not required if an edge is represented simply as a pair of vertex identifiers)")
    print("4. Get the in degree and the out degree of a specified vertex")
    print("5. iterate through the set of outbound edges of a specified vertex (that is, provide an iterator). For each outbound edge,")
    print("   the iterator shall provide the Edge_id of the curren edge (or the target vertex, if no Edge_id is used)")
    print("6. Iterate through the set of inbound edges of a specified vertex (as above)")
    print("7. Get the endpoints of an edge specified by an Edge_id (if applicable)")
    print("8. Retrieve or modify the information (the integer) attached to a specified edge")
    print("0. Exit")

def start():
    graph, cost = initGraph(DirectGraph)

    while True:
        menu()
        option = int(input("Choose: "))
        if option < 0 or option > 8:
            print("Invalid command!\n")
        elif option == 0:
            break
        elif option == 1:
            for v1 in graph.parseDict():
                for v2 in graph.parseVerticeOut(v1):
                    print("[" + str(v1) + " , " + str(v2) + "]" + " -> " + str(cost.getCostFromEdge(v1, v2)))
        elif option == 2:
            vertices = graph.length()
            print("There are " + str(vertices) + " vertices!\n")
        elif option == 3:
            v1 = int(input("First vertex: "))
            v2 = int(input("Second vertex: "))
            if graph.isEdge(v1, v2) == 1:
                print("There's an edge from " + str(v1) + " to " + str(v2))
            else:
                print("There's no edge from " + str(v1) + " to " + str(v2))
        elif option == 4:
            v1 = int(input("Vertex: "))
            if v1 in graph.parseDict():
                print(graph.inDegree(v1))
                print(graph.outDegree(v1))
            else:
                print("Invalid vertex! ")
        elif option == 5:
            ok = 1
            v1 = int(input("Vertex: "))
            if v1 in graph.parseDict():
                for v2 in graph.parseVerticeOut(v1):
                    print("[" + str(v1) + " , " + str(v2) + "]")
                    ok = 0
                if ok == 1:
                    print("There are no outbound edges!\n")
            else:
                print("Invalid vertex! ")
        elif option == 6:
            ok = 1
            v1 = int(input("Vertex: "))
            if v1 in graph.parseDict():
                for v2 in graph.parseVerticeIn(v1):
                    print("[" + str(v2) + " , " + str(v1) + "]")
                    ok = 0
                if ok == 1:
                    print("There are no inbound edges!\n")
            else:
                print("Invalid vertex! ")
        elif option == 7:
            v1 = int(input("First vertex: "))
            v2 = int(input("Second vertex: "))
            if v1 in graph.parseDict() and v2 in graph.parseDict():
                print("The cost is: " + str(cost.getCostFromEdge(v1, v2)))
            else:
                print("Invalid vertexes! ")
        elif option == 8:
            v1 = int(input("First vertex: "))
            v2 = int(input("Second vertex: "))
            if v1 in graph.parseDict() and v2 in graph.parseDict():
                newCost = int(input("The new cost: "))
                cost.setCostOfEdge(v1, v2, newCost)
            else:
                print("Invalid vertexes! ")

start()
