import sys

versionPath = "src/version.h"
versionNumber = sys.argv[1]
  
with open(versionPath, "w") as file: 
    file.write('#define SW_VER "' + versionNumber + '"') 