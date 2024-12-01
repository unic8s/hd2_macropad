import sys

versionPath = "src/version.h"
versionNumber = sys.argv[1]

with open(versionPath, "r") as file: 
    data = file.read() 
    data = data.replace("{{version}}", versionNumber) 
  
with open(versionPath, "w") as file: 
    file.write(data) 