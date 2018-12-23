from functions import *
def testModifyDuration():
    myList=[["0001",40,"Mamaia","Brasov"],["0002",45,"Mamaia","Luxemburg"],["0003",120,"Cluj Napoca","Alberta"],["0004",80,"Jobou","Baia Mare"],["0005",38,"Satu Mare","Constanta"],["0006",87,"Tokyo","Bucuresti"],["0007",76,"Bucuresti","Valcea"],["0008",50,"Brasov","Mamaia"],["0009",90,"Cluj Napoca","Bucuresti"],["0010",100,"Satu Mare","Bacau"]]
    modifyDuration(myList,"0001",90)
    modifyDuration(myList, "0003", 60)
    modifyDuration(myList, "0008", 20)
def testFlightReroute():
    myList = [["0001", 40, "Mamaia", "Brasov"], ["0002", 45, "Mamaia", "Luxemburg"],
              ["0003", 120, "Cluj Napoca", "Alberta"], ["0004", 80, "Jobou", "Baia Mare"],
              ["0005", 38, "Satu Mare", "Constanta"], ["0006", 87, "Tokyo", "Bucuresti"],
              ["0007", 76, "Bucuresti", "Valcea"], ["0008", 50, "Brasov", "Mamaia"],
              ["0009", 90, "Cluj Napoca", "Bucuresti"], ["0010", 100, "Satu Mare", "Bacau"]]
    flightReroute(myList, "Cluj Napoca", "Amsterdam")
    flightReroute(myList, "Bucuresti", "Luxemburg")
    flightReroute(myList, "Satu Mare", "Hunedoara")
def testSortFlights():
    myList = [["0001", 40, "Mamaia", "Brasov"], ["0002", 45, "Mamaia", "Luxemburg"],
              ["0003", 120, "Cluj Napoca", "Alberta"], ["0004", 80, "Jobou", "Baia Mare"],
              ["0005", 38, "Satu Mare", "Constanta"], ["0006", 87, "Tokyo", "Bucuresti"],
              ["0007", 76, "Bucuresti", "Valcea"], ["0008", 50, "Brasov", "Mamaia"],
              ["0009", 90, "Cluj Napoca", "Bucuresti"], ["0010", 100, "Satu Mare", "Bacau"]]
    sortFlights(myList)
    sortFlights(myList)
    sortFlights(myList)
