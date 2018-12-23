from UI import *
from controller import *
from repository import *
r=PickleRepository('text.txt')
c=Controller()
ui=UI(c)
ui.start()