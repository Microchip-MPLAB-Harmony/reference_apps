# Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
#
# You may not use this file except in compliance with the terms and conditions set forth in the
# accompanying LICENSE.TXT file. THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
# DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.

# Setup file for Arduino. Copies Alexa Connect Kit Device SDK files into place such that ACK Host MCU
# sample applications become available as example sketches in the Arduino IDE.

import argparse
import glob
import os.path
import platform
import shutil
import sys

# Require python3.
if sys.version_info < (3, 0):
    print("Python 3 required.")
    sys.exit(1)

class SetupException(Exception):
    def __init__(self, message):
        super().__init__(message)

class Setup:

    def __init__(
        self,
        *,
        only = None,
        altTargetRoot = None,
        altSourceRoot = None,
        quiet = False,
        force = False):

        repoRoot = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../.."))

        # Application sources.
        if altSourceRoot is None:
            sourceRoot = os.path.join(repoRoot, "applications")
        else:
            sourceRoot = altSourceRoot
        if only is None:
            self._appNames = [os.path.basename(dir.rstrip(os.sep)) for dir in glob.glob(os.path.join(sourceRoot, "*" + os.sep))]
        else:
            # Only want one.
            self._appNames = [ only ]

        # Target.
        targetRoot = altTargetRoot
        if targetRoot is None:
            homeDir = os.path.expanduser("~")
            if platform.system() == 'Windows':
                targetRoot = os.path.join(homeDir, "documents", "Arduino")
            elif platform.system() == 'Darwin': # Mac
                targetRoot = os.path.join(homeDir, "Documents", "Arduino")
            else:
                targetRoot = os.path.join(homeDir, "Arduino")

        self._quiet = quiet
        self._force = force
        self._repoRoot = repoRoot
        self._sourceRoot = sourceRoot
        self._targetRoot = targetRoot

    @staticmethod
    def ExamplesPrefix():
        return "AlexaConnectKit_"

    def Run(self):

        # Make sure we have valid source and target.
        self._ValidateSources()
        self._ValidateTarget()

        if not self._quiet:
            print("Copying files to {0}...".format(self._TargetLibrariesRoot()))

        for appName in self._appNames:
            if not self._quiet:
                print(appName)

            sourceDir = self._ApplicationSourceDir(appName)
            targetDir = self._ApplicationTargetDir(appName)

            copies = [
                [ os.path.join(self._repoRoot, "core", "*"), targetDir],
                [ os.path.join(self._repoRoot, "core/generated/*"), targetDir],
                [ os.path.join(self._repoRoot, "core/generated/v3avs_capabilities/*.c"), targetDir ],
                [ os.path.join(self._repoRoot, "core/generated/v3avs_capabilities/*.h"), os.path.join(targetDir, "v3avs_capabilities") ],
                [ os.path.join(self._repoRoot, "core/generated/v3avs_types/*.c"), targetDir ],
                [ os.path.join(self._repoRoot, "core/generated/v3avs_types/*.h"), os.path.join(targetDir, "v3avs_types") ],
                [ os.path.join(self._repoRoot, "include/*"), targetDir ],
                [ os.path.join(self._repoRoot, "include/details/*"), os.path.join(targetDir, "details") ],
                [ os.path.join(self._repoRoot, "external/nanopb/pb*"), targetDir ],
                [ os.path.join(self._repoRoot, "user/*.c"), targetDir ],
                [ os.path.join(self._repoRoot, "user/platform/arduino/*.c*"), targetDir ]]

            # Copy e.g. ack_user_config.h to the library, but not other app-specific header files,
            # which will go into the example directory.
            copyHeaders = []
            for hPath in glob.glob(os.path.join(sourceDir, "*.h")):
                if not Setup._IsExcludedFromLibrary(hPath):
                    copyHeaders.extend([hPath, targetDir])
            if len(copyHeaders) > 0:
                copies.append(copyHeaders)

            for copy in copies:
                self._CopyFilesToDir(copy[0], copy[1])

            self._CreateArduinoSketchFiles(appName)

            self._CreateShimIncludes(appName, "v3avs_capabilities")
            self._CreateShimIncludes(appName, "v3avs_types")

    # Returns a list of directories containing applications to install.
    # Throws a SetupException if at least one of those directories doesn't exist.
    def _ValidateSources(self):

        if len(self._appNames) == 0:
            # This means we were given a path with no directories in it, or possibly that the repo
            # is corrupt (has no directories under the applications directory).
            raise SetupException("No application directories found at '{0}'.".format(self._sourceRoot))

        # Check each path to see if it exists. This really only catches a bad argument to --only,
        # because in other cases self._appDirs contains the directories we found with glob.glob().
        for appName in self._appNames:
            appDir = self._ApplicationSourceDir(appName)
            if not os.path.isdir(appDir):
                raise SetupException("No application directory found at '{0}'.".format(appDir))

    # Validates that the target root exists. If the target root doesn't exist, throws a SetupException.
    # Also throws SetupException if any target directories exist, unless force is set.
    def _ValidateTarget(self):
        if not os.path.isdir(self._targetRoot):
            raise SetupException("Arduino documents directory '{0}' not found.".format(self._targetRoot))

        if not self._force:
            for appName in self._appNames:
                targetDir = self._ApplicationTargetDir(appName)
                if os.path.isdir(targetDir):
                    raise SetupException(
                        "Directory '{0}' exists; save and remove before running this script.".format(targetDir))

    # Copies a set of files to a target directory.
    def _CopyFilesToDir(self, sourceFileWildcards, targetDir):

        for sourceFile in glob.glob(sourceFileWildcards):
            try:
                if os.path.isfile(sourceFile):

                    # Ensure the target dir exists before trying to copy.
                    os.makedirs(targetDir, exist_ok = True)

                    shutil.copy2(sourceFile, targetDir)

            except OSError as e:
                raise SetupException("Unable to copy '{0}' to '{1}': {2}.".format(sourceFile, targetDir, str(e)))

    # Copies a .c to a .ino/.cpp file, changing #include "ack.h" into #include of the special include file
    # created by _CreateArduinoInos.
    def _CreateArduinoIno(self, cSourcePath, inoTargetPath, includeFileName):

        # Ensure the target dir exists before trying to create the .ino file.
        sketchDir = os.path.dirname(inoTargetPath)
        try:
            os.makedirs(sketchDir, exist_ok = True)
        except OSError as e:
            raise SetupException("Unable to create directory '{0}': {1}.".format(sketchDir, str(e)))

        with open(cSourcePath) as cFile:
            sourceLines = cFile.readlines()

        with open(inoTargetPath, "w") as inoFile:
            for line in sourceLines:
                if ("#include" in line) and (("\"ack.h\"" in line) or ("<ack.h>" in line)):
                    inoFile.write("#include \"" + includeFileName + "\"\n")
                else:
                    inoFile.write(line)

    # Copies files into an Arduino sketch directory. There must be exactly one .ino file, which we create
    # from the .c file whose base file name  matches the app name, e.g. HelloWorld.c --> HelloWorld.ino.
    # Other .c files are copied to .cpp files in the sketch. Headers are also copied as-is.
    def _CreateArduinoSketchFiles(self, appName):
        appSourceDir = self._ApplicationSourceDir(appName)
        appTargetDir = self._ApplicationTargetDir(appName)
        inoTargetDir = os.path.join(appTargetDir, "examples", appName)

        # Example .ino files don't #include ack.h directly because multiple libraries all including the same
        # main header causes problems in the Arduino tools. Creates a library-specific header that includes
        # ack.h. When _CreateArduinoIno is called, it creates a .ino in the target that has a #include line
        # to include the library-specific header we create, with the source .c file appended to that.
        includeFileName = "ack_" + appName + "_example_arduino_library.h"
        includeFilePath = os.path.join(appTargetDir, includeFileName)

        with open(includeFilePath, "w") as includeFile:
            includeFile.write("// FILE GENERATED BY SETUP SCRIPT\n")
            includeFile.write("#include \"ack.h\"\n")

        # Process each .c file in the source into a file in the target.
        for cSourcePath in glob.glob(os.path.join(appSourceDir, "*.c")):
            fileNameBase = os.path.splitext(os.path.basename(cSourcePath))[0]
            extension = ".ino" if fileNameBase == appName else ".cpp"
            inoTargetPath = os.path.join(inoTargetDir, fileNameBase + extension)

            self._CreateArduinoIno(cSourcePath, inoTargetPath, includeFileName)

        # Copy each .h file into the example, that wasn't already copied into the library.
        for hSourcePath in glob.glob(os.path.join(appSourceDir, "*.h")):
            if Setup._IsExcludedFromLibrary(hSourcePath):
                shutil.copy2(hSourcePath, inoTargetDir)

    # Special processing for protobuf-generated header files.
    # For Arduino, C files must be in the root of the library, so we've already copied *.pb.c there.
    # An x.pb.c file includes *.pb.h files -- other than its own x.pb.h file -- with a relative path
    # that includes e.g. v3avs_capabilities. So the .pb.h files must be in e.g. a v3avs_capabilities
    # subdirectory. Unfortunately x.pb.c includes its own x.pb.h file without the subdirectory,
    # which means that for Arduino .pb.h files must be in both places. We create a dummy in the root
    # of the library, containing just a #include of the file in the subdirectory.
    def _CreateShimIncludes(self, appName, subdir):

        targetAppRoot = self._ApplicationTargetDir(appName)

        for filePath in glob.glob(os.path.join(targetAppRoot, subdir, "*.pb.h")):

            fileName = os.path.basename(filePath)

            shimFilePath = os.path.join(targetAppRoot, fileName)

            # Generate #include file that points to the actual file in the subdirectory.
            with open(shimFilePath, "w") as shimFile:
                shimFile.write("// FILE GENERATED BY SETUP SCRIPT\n")
                shimFile.write("#include \"{0}/{1}\"\n".format(subdir, fileName))


    # Forms the path to a directory containing an application.
    def _ApplicationSourceDir(self, appName):
        return os.path.join(self._sourceRoot, appName)

    # Forms the path to a directory to contain an Arduino library.
    def _ApplicationTargetDir(self, appName):
        return os.path.join(self._TargetLibrariesRoot(), Setup.ExamplesPrefix() + appName)

    # Forms the path to the Arduino document libraries directory.
    def _TargetLibrariesRoot(self):
        return os.path.join(self._targetRoot, "libraries")

    # Determines whether a header file from the application directory should not go into an Arduino library,
    # e.g. that it should go into an example sketch instead. This is needed bacuse e.g. ack_user_config.h
    # is an app-specific file, but for a given example needs to go into the library instead of the sketch.
    # Other app-specific headers go into the sketch.
    @staticmethod
    def _IsExcludedFromLibrary(filePath):
        fileName = os.path.basename(filePath)
        return fileName != "ack_user_config.h"

# Entry point when invoked stand-alone.
if __name__ == '__main__':
    Parser = argparse.ArgumentParser(description = "Installs ACK applications into the Arduino IDE")
    Parser.add_argument("--only", metavar = "APPLICATIONNAME", help = "Install one ACK application")
    Parser.add_argument("--nopause", dest = "pause", default = True, action = "store_false", help = "Suppress pause for enter when complete")
    Parser.add_argument("--quiet", action = "store_true", help = "Quieter operation")
    Parser.add_argument("--force", action = "store_true", help = "Allow installing into existing directories")
    Parser.add_argument("--targetroot", help = "Alternate location of target Arduino documents root")
    Parser.add_argument("--sourceroot", help = "Alternate location of Arduino applications source root")

    args = Parser.parse_args()

    setup = Setup(
        only = args.only,
        altTargetRoot = args.targetroot,
        altSourceRoot = args.sourceroot,
        quiet = args.quiet,
        force = args.force)

    success = True
    try:
        setup.Run()
    except SetupException as e:
        print(str(e))
        success = False

    if success and not args.quiet:
        print("Success. Restart your Arduino IDE and look in the File->Examples menu for examples "
            "starting with \"{0}\".".format(Setup.ExamplesPrefix()))

    if args.pause:
        input("Press [ENTER] to exit...")

    sys.exit(0 if success else 1)