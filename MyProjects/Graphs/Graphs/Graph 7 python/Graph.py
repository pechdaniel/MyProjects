'''
Created on May 3, 2018

@author: Ale
'''
import math
from EdgeCost import *
from numpy import Inf


class Graph():
    def __init__(self, n):
        self._vertices = n
        self._dictIn = {}
        self._dictOut = {}
        self._matr = {}
        self._paths = {}
        self._generated = False
        for i in range(n):
            self._dictIn[i] = []
            self._dictOut[i] = []

    def fillPaths(self):
        for v in self.getVertices():
            self._paths[v] = {}
            for v2 in self.getVertices():
                if v != v2:
                    self._paths[v][v2] = [(v, v2)]
                else:
                    self._paths[v][v2] = []

    def getDictOut(self):
        return self._dictOut

    def getDictIn(self):
        return self._dictIn

    def getInForX(self, x):
        return self._dictIn[x]

    def getOutForX(self, x):
        return self._dictOut[x]

    def getEdge(self, a, b):
        if self.checkEdge(a, b):
            return True
        return False

    def checkEdge(self, a, b):
        if a in self._dictOut.keys():
            return b in self._dictOut[a]

    def setMatrix(self, matr):
        self._matr = matr

    def getMatrix(self):
        return self._matr

    def getPaths(self):
        return self._paths

    def setPaths(self, p):
        self._paths = p

    def getVertices(self):
        s = set()
        for v in self.getDictIn().keys():
            s.add(v)
        for v in self.getDictOut().keys():
            s.add(v)
        return s

    def getNumberOfEdges(self):
        res = 0
        for vertex in self._dictIn.keys():
            res += len(self._dictIn[vertex])
        return res

    def addEdge(self, startPoint, endPoint):
        if self.validVertex(startPoint) and self.validVertex(endPoint):
            if startPoint not in self._dictIn[endPoint]:
                self._dictIn[endPoint].append(startPoint)
                self._dictOut[startPoint].append(endPoint)
            else:
                raise ValueError('nope')
        else:
            raise ValueError('invalid vertices')

    def getGenerated(self):
        return self._generated

    def addVertex(self, vertex):
        if not self.validVertex(vertex):
            self.getDictIn()[vertex] = []
            self.getDictOut()[vertex] = []
            return 1

    def removeEdge(self, a, b):
        if self.checkEdge(a, b):
            self._dictIn[b].remove(a)
            self._dictOut[a].remove(b)
        else:
            return 1

    def removeVertex(self, vertex):
        if not self.validVertex(vertex):
            return 1
        if vertex in self._dictIn.keys():
            for v in self._dictIn[vertex]:
                self._dictOut[v].remove(vertex)
            del self._dictIn[vertex]
        if vertex in self._dictOut.keys():
            for v in self._dictOut[vertex]:
                self._dictIn[v].remove(vertex)
            del self._dictOut[vertex]

    def getminCostWalk(self, start, end):
        n = len(self.getVertices())
        mat = self.getMatrix()
        self.fillPaths()
        path = self.getPaths()

        for i in range(n + 1):
            res, path = multiply(mat, mat, path)
            mat = res

        self.setPaths(path)
        self.setMatrix(res)

        if res[start][start] < 0:
            raise ValueError("negative cost cycle detected")

        return res[start][end], path[start][end]

    def validVertex(self, vertex):
        return vertex in self.getDictIn().keys() and vertex in self.getDictOut().keys()

    def getIsolatedVertices(self):
        l = []
        for vertex in self.getDictIn().keys():
            if self.getDictIn()[vertex] == [] and self.getDictOut()[vertex] == []:
                l.append(vertex)
        return l


def multiply(a, b, pathsA):
    res = {}
    for i in a.keys():
        res[i] = {}
        for j in b.keys():
            l = {}
            mini = Inf
            for k in a.keys():
                e = a[i][k] + b[k][j]
                if e < mini:
                    mini = e
                    s = k
            if mini == Inf:
                pathsA[i][j] = []

            pathsA[i][j] = pathsA[i][s] + pathsA[s][j]
            res[i][j] = mini

    return res, pathsA