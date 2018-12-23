'''
Created on May 3, 2018

@author: Ale
'''
from numpy import Inf
from Graph import *


class UI():
    def __init__(self, g):
        self._graph = g
        self._costs = EdgeCost()

    def printMenu(self):
        print('1-load graph from file')
        print('2-get min cost walk')
        print('0-exit')

    def buildMatrix(self):
        m = {}
        p = {}
        vertices = self._graph.getVertices()
        costs = self._costs.getCostDict()
        for v in vertices:
            m[v] = {}
            p[v] = {}

        for i in vertices:
            for j in vertices:
                p[i][j] = j
                if (i, j) in costs.keys():
                    m[i][j] = costs[(i, j)]
                elif i != j:
                    m[i][j] = Inf
                elif i == j:
                    m[i][j] = 0

        self._graph.setMatrix(m)

    def readFromFile(self, fname):
        try:
            f = open(fname, 'r')
            d = f.readline().strip().split(' ')
            n = int(d[0])
            m = int(d[1])
            self._graph = Graph(n)
            self._costs = EdgeCost()
            line = f.readline().strip()
            while line != '':
                data = line.split(' ')
                startPoint = int(data[0])
                endPoint = int(data[1])
                cost = int(data[2])
                self._graph.addEdge(startPoint, endPoint)
                self._costs.getCostDict()[startPoint, endPoint] = cost

                line = f.readline().strip()
        except:
            self._graph = Graph(0)
            raise ValueError('file could not be opened')
        finally:
            f.close()
        self.buildMatrix()

    def mainMenu(self):
        self.printMenu()
        while True:
            try:
                cmd = raw_input("Enter command: ")
                if cmd == '1':
                    filename = raw_input("Enter filename: ")
                    self.readFromFile(filename)

                elif cmd == '2':
                    x = input("Enter first vertex: ")
                    y = input("Enter second vertex: ")
                    if not self._graph.validVertex(x) or not self._graph.validVertex(y):
                        print("Vertices not valid")

                    length, path = self._graph.getminCostWalk(x, y)

                    print("The total cost is " + str(length))

                    if length == Inf:
                        print("Not accessible")
                    else:
                        print("Path: ")
                        print(path)

                elif cmd == '0':
                    break
            except Exception as e:
                print(e)


g = Graph(0)
ui = UI(g)
ui.mainMenu()