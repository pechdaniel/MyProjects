from tests import *
from functions import *
def readCommand(): #rads the command and splits it into a command and parameters
    x=input(">>")
    if x.find(' ')==-1:
        command=x
        params=[]
        return (command,params)
    command=x[0:x.find(' ')]
    params=x[x.find(' '):]
    params = params.split()
    for i in range(len(params)):
        params[i] = params[i].strip()
    return (command,params)

def showMenu(): #prints the menu of commands
    sMenu="The current commands are (use them carefully):\n"
    sMenu+="add <number>\n"
    sMenu+="insert <number> at <position>\n"
    sMenu+="remove <position>\n"
    sMenu+="remove <start position> to <end position>\n"
    sMenu+="replace <old number> with <new number>\n"
    sMenu+="list\n"
    sMenu+="list real <start position> to <end position>\n"
    sMenu+="list modulo [< | = | >] <number>\n"
    sMenu+="sum <start position> to <end position>\n"
    sMenu+="product <start position> to <end position>\n"
    sMenu+="filter real\n"
    sMenu+="filter modulo [< | = | >] <number>\n"
    sMenu+="undo\n"
    sMenu+="exit\n"
    print(sMenu)

def start(): #resolves the problem in the asked way
    undoL = []
    myList=[]
    testCheckReal()
    testImaginaryPart()
    testIntToString()
    testModuloComplex()
    testRealPart()
    showMenu()
    while True:
        j=0
        aux=myList[:]
        cmd=readCommand()
        command=cmd[0]
        params=cmd[1]
        if command=="add":
            addToList(myList,params[0])
        elif command=="insert":
            params[2]=int(params[2])
            insertToList(myList,params[0],params[2])
        elif command=="remove" and len(params)==1:
            params[0]=int(params[0])
            myList=removePozFromList(myList,params[0])
        elif command=="remove" and len(params)>1 and params[1]=='to':
            params[0]=int(params[0])
            params[2]=int(params[2])
            myList=removeFromFirstToLastFromList(myList,params[0],params[2])
        elif command=="replace":
            replaceOldWithNew(myList,params[0],params[2])
        elif command=="list" and len(params)==0:
            writeList(myList)
        elif command=="list" and len(params)>3 and params[0]=="real":
            params[1]=int(params[1])
            params[3]=int(params[3])
            realList(myList,params[1],params[3])
        elif command=="list" and len(params)>3 and params[0]=="modulo":
            params[2]=int(params[2])
            showModuloFromList(myList,params[1],params[2])
        elif command=="sum" and len(params)>0:
            params[0]=int(params[0])
            params[2]=int(params[2])
            print(sumCommand(myList,params[0],params[2]))
        elif command=="product":
            params[0] = int(params[0])
            params[2] = int(params[2])
            print(productCommand(myList,params[0],params[2]))
        elif command=="filter" and len(params)>0 and params[0]=="real":
             myList=filterRealCommand(myList)
        elif command=="filter" and len(params)==3:
            params[2]=int(params[2])
            myList=filterModuloCommand(myList,params[1],params[2])
        elif command=="undo":
            j=1
            myList=undoCommand(undoL)
        elif command=="exit":
            break
        elif command=="help":
            showMenu()
        else:
            print("Type a valid command! LOL")
        if aux!=myList and j==0:
            undoL.append(deepcopy(myList))