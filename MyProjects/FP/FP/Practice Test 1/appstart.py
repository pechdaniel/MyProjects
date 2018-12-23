from UI import *
from controller import *
from repository import *
from domain import *
driverRepo=Repository()
orderRepo=Repository()
incomeRepo=Repository()
driverController=Controller(driverRepo)
orderController=Controller(orderRepo)
incomeController=Controller(incomeRepo)
ui=UI(driverController,orderController,incomeController)
ui.start()