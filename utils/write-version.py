import sys
import subprocess


versionPath = "src/version.h"

if len(sys.argv) > 1:
    versionNumber = sys.argv[1]
else:
    result = subprocess.run(['git', 'pull'])
    result = subprocess.run(['git', 'describe', '--abbrev=0', '--tags'], stdout=subprocess.PIPE)
    versionNumber = result.stdout.decode('utf-8').replace("\n", "")
  
with open(versionPath, "w") as file: 
    file.write('#define SW_VER "' + versionNumber + '"') 