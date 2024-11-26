import shutil 
import os.path

sourceDir = 'sdcard'
targetFile = 'assets'

if os.path.exists(targetFile):
   os.unlink(targetFile)

archived = shutil.make_archive(targetFile, 'zip', sourceDir)