'''
Created on May 3, 2018

@author: Ale
'''


class EdgeCost():
    def __init__(self):
        self.__costDict = {}

    def getCostDict(self):
        return self.__costDict

    def getCostForVertex(self, start, end):
        return self.__costDict[(start, end)]

    def addCost(self, start, end, cost):
        self.__costDict[(start, end)] = cost

    def changeCost(self, end, start, newCost):
        self.__costDict[(start, end)] = newCost

    def removeCost(self, start, end):
        del self.__costDict[(start, end)]

    def removeCostOfVertex(self, vertex):
        l = []
        for edge in self.getCostDict().keys():
            l.append(edge)
        for edge in l:
            if vertex in edge:
                self.removeCost(edge[0], edge[1])