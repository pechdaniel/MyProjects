def readList():
    '''

    in: reads a list of integer numbers
    out: return: myList
    '''
    myList=[]
    stop=False
    nr=input("Enter a value ('end' to terminate):")
    while stop==False:
        myList.append(int(nr))
        nr=input("Enter a value ('end' to terminate):")
        if(nr=="end"):
            stop=True
    return myList
def printList(myList):
    '''

    int: param myList:
    out: prints on screen the list
    '''
    print(myList)
    return
def mountainL(myList):
    '''

    int: param myList (list)
    out: True if myList is a mountain formation
    '''
    n=len(myList)
    i=1
    ok=1
    while i<n:
        if ok==1 and myList[i]<myList[i-1]:
            if i==1:
                return False
            else:
                ok=0
        if ok==0 and myList[i]>myList[i-1]:
            return False
        i=i+1
    if ok==1:
        return False
    return True
def sortList(myList):
    '''

    in: param myList
    out: sorts my list in decreasing order
    '''
    for i in range(len(myList)-1):
       ma=myList[i]
       poz=i
       j=i+1
       while j<len(myList):
           if(myList[j]>ma):
               ma=myList[j]
               poz=j
           j=j+1
       if j!=i:
            a=myList[poz]
            b=myList[i]
            myList[poz]=b
            myList[i]=a
    return
def distVal(myList):
    '''

    in: param myList
    out: True if myList has at most 3 distinct elements, False otherwise
    '''
    n=len(myList)
    count=0
    auxList=myList[:]
    sortList(auxList)
    i=1
    while i<n:
        a=auxList[i]
        b=auxList[i-1]
        if a==b:
            count=count+1
        i=i+1
    if n-count>3:
        return False
    return True
def printMenu():
    '''

    Shows the menu of the application
    '''
    sMenu="1.Read a list from the keyboard\n"
    sMenu+="2.Print the list on the screen\n"
    sMenu+="3.Print the longest sequence from the list that has the mountain property\n"
    sMenu+="4.Print the longest sequence from the list that has at most 3 distinct values\n"
    sMenu+="0.Exit"
    print(sMenu)
def showSmountain(myList):
    '''

    in: param myList
    out: prints the longest sequence of a mountain
    '''
    n = len(myList)
    l = 0
    show = []
    for i in range(n - 3):
        j = i + 1
        while j in range(n):
            aux = myList[i:j + 1]
            if mountainL(aux) == True and j + 1 - i > l:
                l = j + 1 - i
                show = aux[:]
            j = j + 1
    printList(show)
    return
def showSdist(myList):
    '''

    in: param myList
    out: prints the longest sequence of numbers with at most 3 distinct values from myList
    '''
    n=len(myList)
    l=0
    show=[]
    for i in range(n-3):
        j=i+1
        while j in range(n):
            aux=myList[i:j+1]
            if distVal(aux)==True and j+1-i>l:
                l=j+1-i
                show=aux[:]
            j=j+1
    printList(show)
    return
def start():
    '''

    out: starts and runs the application
    '''
    stop=False
    while stop==False:
        printMenu()
        comm=int(input("Input option:"))
        if comm==0:
            stop=True
        elif comm==1:
            myList=readList()
        elif comm==2:
            printList(myList)
        elif comm==3:
            showSmountain(myList)
        elif comm==4:
            showSdist(myList)
        else:
            print("Give a valid option!")
    return
start()