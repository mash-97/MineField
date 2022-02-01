import os 

dir_path = os.path.split(os.path.abspath(__file__))[0] 

def checkPyFile(filepath):
  if os.path.isfile(os.path.join(dir_path, filepath)) and os.path.splitext(filepath)[1]=='.py':
    return True 
  return False 

files = os.listdir(dir_path)

for pyfile in files:
  if checkPyFile(pyfile)==True:
    module_name = os.path.splitext(os.path.basename(pyfile))[0]
    exec(f"from pydescriptors.{module_name} import *")


