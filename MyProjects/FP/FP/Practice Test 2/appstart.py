from UI import *
from repository import *
from controller import *
from domain import *
addressRepo=Repository()
addressController=Controller(addressRepo)
ui=UI(addressController)
ui.start()