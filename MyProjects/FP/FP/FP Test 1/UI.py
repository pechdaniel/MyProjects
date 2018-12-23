from functions import *
from tests import *
def addFlight(myList):
    '''
    adds a flight to the list
    in:param myList:
    out:myList
    '''
    ok=1
    aux=[]
    x=input("Enter the flight code:")
    if len(x)<=3:
        ok=0
    aux.append(x)
    x=int(input("Enter the duration:"))
    if x<=20:
        ok=0
    aux.append(x)
    x=input("Enter the departure city:")
    if len(x)<=3:
        ok=0
    aux.append(x)
    x=input("Enter the destination city:")
    if len(x)<=3:
        ok=0
    aux.append(x)
    if ok==1:
        myList.append(aux)
    else:
        print("Input correct values for the flights!")
def modifyFlight(myList):
    '''
    modifies the list of flights at the destination
    in:param myList:
    '''
    code=input("Enter the code:")
    duration=int(input("Enter the destination:"))
    modifyDuration(myList,code,duration)
def rerouteMod(myList):
    '''
    reroutes the flight to a new destination
    in:myList
    '''
    oldDest=input("Enter the old destination:")
    newDest=input("Enter the new destination:")
    if len(newDest)>3:
        flightReroute(myList,oldDest,newDest)
    else:
        print("The new destination is not valid!")
def showFlights(myList):
    '''
    shows the flights that are to a given city increasingly by their duration
    in:param myList:
    in:param city:
    out:myList
    '''
    city=input("Enter the departure city:")
    aux=[]
    for i in range(len(myList)-1):
        if myList[i][2]==city:
            aux.append(myList[i])
    sortFlights(aux)
    print(aux)
def showMenu():
    '''
    shows the menu of the application
    '''
    fMenu="1. Adds a flight with a code, duration, departure city and destination city to the list\n"
    fMenu+="2. Modifies the duration of a given flight\n"
    fMenu+="3. For a given destination city all flights a re rerouted\n"
    fMenu+="4. Shows all flights with a given departure city, increasingly by their duration\n"
    fMenu+="5. Help\n"
    fMenu+="6. Prints the list\n"
    fMenu+="0. Exit\n"
    print(fMenu)
def start():
    '''
    runs the application in the asked way
    '''
    myList = [["0001", 40, "Mamaia", "Brasov"], ["0002", 45, "Mamaia", "Luxemburg"],
              ["0003", 120, "Cluj Napoca", "Alberta"], ["0004", 80, "Jobou", "Baia Mare"],
              ["0005", 38, "Satu Mare", "Constanta"], ["0006", 87, "Tokyo", "Bucuresti"],
              ["0007", 76, "Bucuresti", "Valcea"], ["0008", 50, "Brasov", "Mamaia"],
              ["0009", 90, "Cluj Napoca", "Bucuresti"], ["0010", 100, "Satu Mare", "Bacau"]]
    showMenu()
    while True:
        print(">>")
        testFlightReroute()
        testModifyDuration()
        testSortFlights()
        x=int(input("Type in a number:"))
        if x==1:
            addFlight(myList)
        elif x==2:
            modifyFlight(myList)
        elif x==3:
            rerouteMod(myList)
        elif x==4:
            showFlights(myList)
        elif x==5:
            showMenu()
        elif x==6:
            print(myList)
        elif x==0:
            break
        else:
            print("What was that? Type a number from help!")
start()