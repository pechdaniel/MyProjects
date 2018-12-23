from UI import *
from controller import *
from CSVRepository import *
from repository import *
from domain import *
repo=Repository()
el=Person(1,'nonvaccinated','ill')
repo.add(el)
el=Person(2,'nonvaccinated','healthy')
repo.add(el)
el=Person(3,'vaccinated','healthy')
repo.add(el)
el=Person(4,'nonvaccinated','healthy')
repo.add(el)
controller=Controller(repo)
ui=UI(controller)
ui.start()