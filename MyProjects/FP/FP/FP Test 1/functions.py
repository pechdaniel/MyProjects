def modifyDuration(myList,code,duration):
    '''
    modifies the duration of a flight with a given code
    in:param myList:
    in:param code:
    out:myList
    '''
    for i in range(len(myList)):
        if myList[i][0]==code:
            myList[i][1]=duration
def flightReroute(myList,oldDest,newDest):
    '''
    reroutes the flight to a new destination
    in:param myList:
    in:param oldDest:
    in:param newDest:
    out:myList
    '''
    for i in range(len(myList)-1):
        if myList[i][3]==oldDest:
            myList[i][3]=newDest
def sortFlights(myList):
    '''
    sorts the flights increasingly by their duration
    in:param myList:
    :return:
    '''
    myList.sort(key=lambda elem:elem[1])