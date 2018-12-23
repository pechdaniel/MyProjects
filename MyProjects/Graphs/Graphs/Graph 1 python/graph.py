class Graph:
    '''
        A directed graph, represented as two maps,
    one from each vertex to the set of outbound neighbours,
    the other from each vertex to the set of inbound neighbours
    '''
    def __init__(self,n):
        '''
        Creates a graph with n vertices (from 0 to n-1), no edges
        '''
