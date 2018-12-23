from domain import *
from copy import deepcopy


def copyList(myList): #makes a deepcopy from myList indo undoL
    '''

    int:param myList:
    out:return: undoL
    '''
    undoL=deepcopy(myList)
    return undoL
def undoCommand(undoL): #undoes the last modification of the list
    '''

    int:param undoL:
    out:return: the last element of undoL
    '''
    i=len(undoL)
    if i>1:
        undoL.pop(i-1)
        i=i-1
    return undoL[i-1]
def addToList(myList,nr): #adds complex numbers to the list
    '''

    int:param myList, nr
    out:return: myList
    '''
    myList.append(nr)
    return myList
def insertToList(myList,nr,poz): #inserts numbers in the list on a given position
    '''

    in:param myList,nr,poz
    out:return:myList
    '''
    n=len(myList)-1
    myList.append(myList[n])
    while n>poz:
        myList[n]=myList[n-1]
        n=n-1
    myList[poz]=nr
    return myList
def removePozFromList(myList,poz): #removes a number from the list from a given position
    '''

    in:param myList,poz
    out:return:myList
    '''
    myList.pop(poz)
    return myList
def removeFromFirstToLastFromList(myList,start,end): #removes elements from the list from a start point to an end point
    '''

    in:param myList,start,end
    out:return:myList
    '''
    i=end
    while i>=start:
        aux = myList[:]
        myList.pop(i)
        i=i-1
    return myList
def replaceOldWithNew(myList,old,new): #replaces all elements from the list equal to a given element with a new element
    '''

    in:param myList,old,new
    out:return:myList
    '''
    n=len(myList)-1
    for i in range(n):
        if myList[i]==old:
            myList[i]=new
    return myList
def writeList(myList): #prints the list of elements
    '''

    in:param myList
    out:prints myList
    '''
    print(myList)
def realList(myList,start,end): #prints the real elements from the list from a start point to an end point
    '''

    in:param myList,start,end
    out:prints aux
    '''
    i=start
    aux=[]
    while i<=end:
        if checkReal(myList[i])==True:
            aux.append(myList[i])
        i=i+1
    writeList(aux)
def showModuloFromList(myList,sign,md): #prints all the numbers that are < | > | = with a given value (md)
    '''

    in:param myList,sign,md
    out: prints the auxiliary list
    '''
    n=len(myList)-1
    aux=[]
    if sign=='<':
        for i in range(n):
            a=realPart(myList[i])
            b=imaginaryPart(myList[i])
            modulo=moduloComplex(a,b)
            if modulo<md:
                aux.append(myList[i])
    elif sign=='>':
        for i in range(n):
            a = realPart(myList[i])
            b = imaginaryPart(myList[i])
            modulo = moduloComplex(a, b)
            if modulo>md:
                aux.append(myList[i])
    elif sign=='=':
        for i in range(n):
            a = realPart(myList[i])
            b = imaginaryPart(myList[i])
            modulo = moduloComplex(a, b)
            if modulo==md:
                aux.append(myList[i])
    writeList(aux)
def filterRealCommand(myList): #filters the list for only real elements
    '''

    in:param myList:
    out:return: myList
    '''
    i=len(myList)-1
    while i>=0:
        if imaginaryPart(myList[i])!=0:
            removePozFromList(myList,i)
        i=i-1
    return myList
def filterModuloCommand(myList,sign,param): #filters the list for only elements that have the modulus <,>,= to a given number
    '''

    in:param myList,sign,param
    out:return:myList
    '''
    i=len(myList)-1
    if sign=='<':
      while i>=0:
        a=realPart(myList[i])
        b=imaginaryPart(myList[i])
        if not moduloComplex(a,b)<param:
            myList=removePozFromList(myList,i)
            i=i-1
        i=i-1
    elif sign=='>':
        while i >= 0:
            a = realPart(myList[i])
            b = imaginaryPart(myList[i])
            if not moduloComplex(a, b) > param:
                myList = removePozFromList(myList, i)
                i = i - 1
            i = i - 1
    elif sign=='=':
        while i >= 0:
            a = realPart(myList[i])
            b = imaginaryPart(myList[i])
            if not moduloComplex(a, b) == param:
                myList = removePozFromList(myList, i)
                i = i - 1
            i = i - 1
    return myList
def sumCommand(myList,start,end): #prints the sum of elements from a start pos to an end pos
    '''

    in:param myList,start,end
    out:return: k
    '''
    s1=0
    s2=0
    i=start
    while i<=end:
        s1=s1+realPart(myList[i])
        s2=s2+imaginaryPart(myList[i])
        i=i+1
    k=intToString(s1,s2)
    return k
def productCommand(myList,start,end): #prints the sum of elements from a start pos to an end pos
    '''

    in:param myList,start,end
    out:return:k
    '''
    s1 = 1
    s2 = 1
    i = start
    while i <= end:
        s1 = s1 * realPart(myList[i])
        s2 = s2 * imaginaryPart(myList[i])
        i = i + 1
    k = intToString(s1, s2)
    return k
