#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include CMakefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/hgp/common/Input.o \
	${OBJECTDIR}/hgp/common/displaymanager.o \
	${OBJECTDIR}/hgp/common/eventmanager.o \
	${OBJECTDIR}/hgp/common/inputdevice.o \
	${OBJECTDIR}/hgp/common/keyboard/linuxinput.o \
	${OBJECTDIR}/hgp/common/keyboard/macinput.o \
	${OBJECTDIR}/hgp/common/keyboard/windowsinput.o \
	${OBJECTDIR}/hgp/common/mouse/linuxinput.o \
	${OBJECTDIR}/hgp/common/mouse/macinput.o \
	${OBJECTDIR}/hgp/common/mouse/windowsinput.o \
	${OBJECTDIR}/hgp/game.o \
	${OBJECTDIR}/hgp/gamecontroller.o \
	${OBJECTDIR}/hgp/interface/control.o \
	${OBJECTDIR}/hgp/interface/view.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hgp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hgp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hgp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/hgp/common/Input.o: hgp/common/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/Input.o hgp/common/Input.cpp

${OBJECTDIR}/hgp/common/displaymanager.o: hgp/common/displaymanager.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/displaymanager.o hgp/common/displaymanager.cpp

${OBJECTDIR}/hgp/common/eventmanager.o: hgp/common/eventmanager.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/eventmanager.o hgp/common/eventmanager.cpp

${OBJECTDIR}/hgp/common/inputdevice.o: hgp/common/inputdevice.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/inputdevice.o hgp/common/inputdevice.cpp

${OBJECTDIR}/hgp/common/keyboard/linuxinput.o: hgp/common/keyboard/linuxinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common/keyboard
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/keyboard/linuxinput.o hgp/common/keyboard/linuxinput.cpp

${OBJECTDIR}/hgp/common/keyboard/macinput.o: hgp/common/keyboard/macinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common/keyboard
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/keyboard/macinput.o hgp/common/keyboard/macinput.cpp

${OBJECTDIR}/hgp/common/keyboard/windowsinput.o: hgp/common/keyboard/windowsinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common/keyboard
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/keyboard/windowsinput.o hgp/common/keyboard/windowsinput.cpp

${OBJECTDIR}/hgp/common/mouse/linuxinput.o: hgp/common/mouse/linuxinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common/mouse
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/mouse/linuxinput.o hgp/common/mouse/linuxinput.cpp

${OBJECTDIR}/hgp/common/mouse/macinput.o: hgp/common/mouse/macinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common/mouse
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/mouse/macinput.o hgp/common/mouse/macinput.cpp

${OBJECTDIR}/hgp/common/mouse/windowsinput.o: hgp/common/mouse/windowsinput.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/common/mouse
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/common/mouse/windowsinput.o hgp/common/mouse/windowsinput.cpp

${OBJECTDIR}/hgp/game.o: hgp/game.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/game.o hgp/game.cpp

${OBJECTDIR}/hgp/gamecontroller.o: hgp/gamecontroller.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/gamecontroller.o hgp/gamecontroller.cpp

${OBJECTDIR}/hgp/interface/control.o: hgp/interface/control.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/interface/control.o hgp/interface/control.cpp

${OBJECTDIR}/hgp/interface/view.o: hgp/interface/view.cpp 
	${MKDIR} -p ${OBJECTDIR}/hgp/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hgp/interface/view.o hgp/interface/view.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hgp

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
