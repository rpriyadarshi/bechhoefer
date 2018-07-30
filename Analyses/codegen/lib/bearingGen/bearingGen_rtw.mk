###########################################################################
## Makefile generated for MATLAB file/project 'bearingGen'. 
## 
## Makefile     : bearingGen_rtw.mk
## Generated on : Sun Jul 29 17:50:56 2018
## MATLAB Coder version: 4.0 (R2018a)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/bearingGen.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = bearingGen
MAKEFILE                  = bearingGen_rtw.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2018a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2018a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/r_pri/Documents/Projects/bitbucket/bechhoefer/Analyses
ARCH                      = win64
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Xilinx Software Development Kit (SDK)  | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2018a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# XILINX_ARM_CROSS_COMPILE
# TARGET_LOAD_CMD_ARGS
# TARGET_PKG_INSTALLDIR

#-----------
# MACROS
#-----------

SHELL                    = %SystemRoot%/system32/cmd.exe
XILINXSDK_TOOLS          = $(XILINX_ARM_CROSS_COMPILE)
CCOUTPUTFLAG             = --output_file=
LDOUTPUTFLAG             = --output_file=
EXE_FILE_EXT             = $(PROGRAM_FILE_EXT)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Xilinx SDK Assembler
AS_PATH = $(XILINXSDK_TOOLS)
AS = $(AS_PATH)/arm-xilinx-linux-gnueabi-as

# C Compiler: Xilinx SDK C Compiler
CC_PATH = $(XILINXSDK_TOOLS)
CC = $(CC_PATH)/arm-xilinx-linux-gnueabi-gcc

# Linker: Xilinx SDK Linker
LD_PATH = $(XILINXSDK_TOOLS)
LD = $(LD_PATH)/arm-xilinx-linux-gnueabi-gcc

# C++ Compiler: Xilinx SDK C++ Compiler
CPP_PATH = $(XILINXSDK_TOOLS)
CPP = $(CPP_PATH)/arm-xilinx-linux-gnueabi-g++

# C++ Linker: Xilinx SDK C++ Linker
CPP_LD_PATH = $(XILINXSDK_TOOLS)
CPP_LD = $(CPP_LD_PATH)/arm-xilinx-linux-gnueabi-gcc

# Archiver: Xilinx SDK Archiver
AR_PATH = $(XILINXSDK_TOOLS)
AR = $(AR_PATH)/arm-xilinx-linux-gnueabi-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD_PATH = $(TARGET_PKG_INSTALLDIR)
DOWNLOAD = $(DOWNLOAD_PATH)/download.bat

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -ruvs
ASFLAGS              = -c \
                       -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -O0
CPPFLAGS             = -c \
                       -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -O2
CPP_LDFLAGS          = -lm \
                       -lrt \
                       -lpthread \
                       -ldl \
                       -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon
CPP_SHAREDLIB_LDFLAGS  = -shared  \
                         -lm \
                         -lrt \
                         -lpthread \
                         -ldl \
                         -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS)  $(ZYNQ_PASSWORD)  $(ZYNQ_USERNAME) $(ZYNQ_IPADDRESS) /tmp $(PRODUCT)
EXECUTE_FLAGS        =
LDFLAGS              = -lm \
                       -lrt \
                       -lpthread \
                       -ldl \
                       -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared  \
                       -lm \
                       -lrt \
                       -lpthread \
                       -ldl \
                       -march=armv7-a -mcpu=cortex-a9  -mfloat-abi=softfp -mfpu=neon

#--------------------
# File extensions
#--------------------

OBJ_EXT             = .s.o
ASM_EXT             = .s
C_DEP               = .c.dep
H_EXT               = .h
COBJ_EXT            = .c.o
C_EXT               = .c
EXE_EXT             =
SHAREDLIB_EXT       =
CXX_DEP             = .cpp.dep
HPP_EXT             = .hpp
CPPOBJ_EXT          = .cpp.o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       =
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/bearingGen.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/bearingGen -I$(START_DIR) -IC:/ProgramData/MATLAB/SupportPackages/R2018a/toolbox/target/supportpackages/zynq/src -IC:/ProgramData/MATLAB/SupportPackages/R2018a/toolbox/target/supportpackages/zynq/include -IC:/ProgramData/MATLAB/SupportPackages/R2018a/toolbox/target/supportpackages/arm_cortex_a/include -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DARM_PROJECT -DMW_EXTMODE_RECV_TIMEOUT_USEC=10 -DSTACK_SIZE=200000 -DMODEL=bearingGen -DHAVESTDIO -DUSE_RTMODEL
DEFINES_SKIPFORSIL = -DARM_PROJECT -DMW_EXTMODE_RECV_TIMEOUT_USEC=10 -DSTACK_SIZE=200000
DEFINES_STANDARD = -DMODEL=bearingGen -DHAVESTDIO -DUSE_RTMODEL

DEFINES = $(DEFINES_) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/bearingGen/bearingGen_rtwutil.c $(START_DIR)/codegen/lib/bearingGen/bearingGen_initialize.c $(START_DIR)/codegen/lib/bearingGen/bearingGen_terminate.c $(START_DIR)/codegen/lib/bearingGen/bearingGen.c $(START_DIR)/codegen/lib/bearingGen/calcFaultFreq.c $(START_DIR)/codegen/lib/bearingGen/GetBearFreqRatio.c $(START_DIR)/codegen/lib/bearingGen/power.c $(START_DIR)/codegen/lib/bearingGen/envelope1.c $(START_DIR)/codegen/lib/bearingGen/exp.c $(START_DIR)/codegen/lib/bearingGen/filter.c $(START_DIR)/codegen/lib/bearingGen/abs.c $(START_DIR)/codegen/lib/bearingGen/psde.c $(START_DIR)/codegen/lib/bearingGen/detrend.c $(START_DIR)/codegen/lib/bearingGen/mldivide.c $(START_DIR)/codegen/lib/bearingGen/qrsolve.c $(START_DIR)/codegen/lib/bearingGen/xgeqp3.c $(START_DIR)/codegen/lib/bearingGen/sqrt.c $(START_DIR)/codegen/lib/bearingGen/xnrm2.c $(START_DIR)/codegen/lib/bearingGen/ixamax.c $(START_DIR)/codegen/lib/bearingGen/xswap.c $(START_DIR)/codegen/lib/bearingGen/xzlarfg.c $(START_DIR)/codegen/lib/bearingGen/xzlarf.c $(START_DIR)/codegen/lib/bearingGen/xgemv.c $(START_DIR)/codegen/lib/bearingGen/xgerc.c $(START_DIR)/codegen/lib/bearingGen/fft.c $(START_DIR)/codegen/lib/bearingGen/any.c $(START_DIR)/codegen/lib/bearingGen/calcFaultPeaks.c $(START_DIR)/codegen/lib/bearingGen/findpeaks.c $(START_DIR)/codegen/lib/bearingGen/eml_setop.c $(START_DIR)/codegen/lib/bearingGen/mean.c $(START_DIR)/codegen/lib/bearingGen/rt_nonfinite.c $(START_DIR)/codegen/lib/bearingGen/rtGetNaN.c $(START_DIR)/codegen/lib/bearingGen/rtGetInf.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = bearingGen_rtwutil.c.o bearingGen_initialize.c.o bearingGen_terminate.c.o bearingGen.c.o calcFaultFreq.c.o GetBearFreqRatio.c.o power.c.o envelope1.c.o exp.c.o filter.c.o abs.c.o psde.c.o detrend.c.o mldivide.c.o qrsolve.c.o xgeqp3.c.o sqrt.c.o xnrm2.c.o ixamax.c.o xswap.c.o xzlarfg.c.o xzlarf.c.o xgemv.c.o xgerc.c.o fft.c.o any.c.o calcFaultPeaks.c.o findpeaks.c.o eml_setop.c.o mean.c.o rt_nonfinite.c.o rtGetNaN.c.o rtGetInf.c.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : build


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(START_DIR)/codegen/lib/bearingGen/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(START_DIR)/codegen/lib/bearingGen/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(START_DIR)/codegen/lib/bearingGen/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(ECHO) "### Deleted all derived files."


