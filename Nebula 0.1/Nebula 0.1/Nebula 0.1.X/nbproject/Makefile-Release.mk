#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Release.mk)" "nbproject/Makefile-local-Release.mk"
include nbproject/Makefile-local-Release.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Release
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../apds9960.c ../config.c ../drv8835.c ../i2c.c ../interrupt.c ../main.c ../vcnl4010.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/apds9960.o ${OBJECTDIR}/_ext/1472/config.o ${OBJECTDIR}/_ext/1472/drv8835.o ${OBJECTDIR}/_ext/1472/i2c.o ${OBJECTDIR}/_ext/1472/interrupt.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/vcnl4010.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/apds9960.o.d ${OBJECTDIR}/_ext/1472/config.o.d ${OBJECTDIR}/_ext/1472/drv8835.o.d ${OBJECTDIR}/_ext/1472/i2c.o.d ${OBJECTDIR}/_ext/1472/interrupt.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/vcnl4010.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/apds9960.o ${OBJECTDIR}/_ext/1472/config.o ${OBJECTDIR}/_ext/1472/drv8835.o ${OBJECTDIR}/_ext/1472/i2c.o ${OBJECTDIR}/_ext/1472/interrupt.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/vcnl4010.o

# Source Files
SOURCEFILES=../apds9960.c ../config.c ../drv8835.c ../i2c.c ../interrupt.c ../main.c ../vcnl4010.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Release.mk dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328PB
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/apds9960.o: ../apds9960.c  .generated_files/a852f33c1b21073a248f881fc02d863b49a42d1b.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/apds9960.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/apds9960.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/apds9960.o.d" -MT "${OBJECTDIR}/_ext/1472/apds9960.o.d" -MT ${OBJECTDIR}/_ext/1472/apds9960.o -o ${OBJECTDIR}/_ext/1472/apds9960.o ../apds9960.c 
	
${OBJECTDIR}/_ext/1472/config.o: ../config.c  .generated_files/571b271ace9d517be44e7235c31bf3a2e2e0baf.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/config.o.d" -MT "${OBJECTDIR}/_ext/1472/config.o.d" -MT ${OBJECTDIR}/_ext/1472/config.o -o ${OBJECTDIR}/_ext/1472/config.o ../config.c 
	
${OBJECTDIR}/_ext/1472/drv8835.o: ../drv8835.c  .generated_files/1b20d9c92f3b8bbd8c10188ebc84bb4fbb9fe77.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/drv8835.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/drv8835.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/drv8835.o.d" -MT "${OBJECTDIR}/_ext/1472/drv8835.o.d" -MT ${OBJECTDIR}/_ext/1472/drv8835.o -o ${OBJECTDIR}/_ext/1472/drv8835.o ../drv8835.c 
	
${OBJECTDIR}/_ext/1472/i2c.o: ../i2c.c  .generated_files/406c2803be66e2142a468ef117acf37866ea9f01.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/i2c.o.d" -MT "${OBJECTDIR}/_ext/1472/i2c.o.d" -MT ${OBJECTDIR}/_ext/1472/i2c.o -o ${OBJECTDIR}/_ext/1472/i2c.o ../i2c.c 
	
${OBJECTDIR}/_ext/1472/interrupt.o: ../interrupt.c  .generated_files/ed7a3aa8bae2b33cbb9eebee2612ca54dbb655df.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/interrupt.o.d" -MT "${OBJECTDIR}/_ext/1472/interrupt.o.d" -MT ${OBJECTDIR}/_ext/1472/interrupt.o -o ${OBJECTDIR}/_ext/1472/interrupt.o ../interrupt.c 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  .generated_files/1880b4c40017510b21f5cb18823bf430af205f5.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/main.o.d" -MT "${OBJECTDIR}/_ext/1472/main.o.d" -MT ${OBJECTDIR}/_ext/1472/main.o -o ${OBJECTDIR}/_ext/1472/main.o ../main.c 
	
${OBJECTDIR}/_ext/1472/vcnl4010.o: ../vcnl4010.c  .generated_files/3bcb4f31003c3dac707af514acd0e0909311582c.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/vcnl4010.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/vcnl4010.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/vcnl4010.o.d" -MT "${OBJECTDIR}/_ext/1472/vcnl4010.o.d" -MT ${OBJECTDIR}/_ext/1472/vcnl4010.o -o ${OBJECTDIR}/_ext/1472/vcnl4010.o ../vcnl4010.c 
	
else
${OBJECTDIR}/_ext/1472/apds9960.o: ../apds9960.c  .generated_files/92097693f52744dda15a82ccbf136624f4f44db4.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/apds9960.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/apds9960.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/apds9960.o.d" -MT "${OBJECTDIR}/_ext/1472/apds9960.o.d" -MT ${OBJECTDIR}/_ext/1472/apds9960.o -o ${OBJECTDIR}/_ext/1472/apds9960.o ../apds9960.c 
	
${OBJECTDIR}/_ext/1472/config.o: ../config.c  .generated_files/c9df0fb4ae0cce2180b4e306b6d10c2b38339f44.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/config.o.d" -MT "${OBJECTDIR}/_ext/1472/config.o.d" -MT ${OBJECTDIR}/_ext/1472/config.o -o ${OBJECTDIR}/_ext/1472/config.o ../config.c 
	
${OBJECTDIR}/_ext/1472/drv8835.o: ../drv8835.c  .generated_files/51ce4966d4c44c4d64fa769721309f33cab077ef.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/drv8835.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/drv8835.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/drv8835.o.d" -MT "${OBJECTDIR}/_ext/1472/drv8835.o.d" -MT ${OBJECTDIR}/_ext/1472/drv8835.o -o ${OBJECTDIR}/_ext/1472/drv8835.o ../drv8835.c 
	
${OBJECTDIR}/_ext/1472/i2c.o: ../i2c.c  .generated_files/c6cc9700ba0534cbf2c124f096b85c0428d28791.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/i2c.o.d" -MT "${OBJECTDIR}/_ext/1472/i2c.o.d" -MT ${OBJECTDIR}/_ext/1472/i2c.o -o ${OBJECTDIR}/_ext/1472/i2c.o ../i2c.c 
	
${OBJECTDIR}/_ext/1472/interrupt.o: ../interrupt.c  .generated_files/285a51db4ff3df9252fffc9c911e8dc2d4b73a91.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/interrupt.o.d" -MT "${OBJECTDIR}/_ext/1472/interrupt.o.d" -MT ${OBJECTDIR}/_ext/1472/interrupt.o -o ${OBJECTDIR}/_ext/1472/interrupt.o ../interrupt.c 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  .generated_files/e34139232edcf339578d338c7fd43bd76074c7f4.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/main.o.d" -MT "${OBJECTDIR}/_ext/1472/main.o.d" -MT ${OBJECTDIR}/_ext/1472/main.o -o ${OBJECTDIR}/_ext/1472/main.o ../main.c 
	
${OBJECTDIR}/_ext/1472/vcnl4010.o: ../vcnl4010.c  .generated_files/cb6f44e1ef3e6987a6d8fba4ed4fc041716b97f1.flag .generated_files/1b5e45a194553695683ca8464176a7a22ee80e49.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/vcnl4010.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/vcnl4010.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall -DXPRJ_Release=$(CND_CONF)   -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" $(COMPARISON_BUILD)  -gdwarf-3 -std=gnu99     -MD -MP -MF "${OBJECTDIR}/_ext/1472/vcnl4010.o.d" -MT "${OBJECTDIR}/_ext/1472/vcnl4010.o.d" -MT ${OBJECTDIR}/_ext/1472/vcnl4010.o -o ${OBJECTDIR}/_ext/1472/vcnl4010.o ../vcnl4010.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_Release=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1     -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall  -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" -std=gnu99 -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.map  -DXPRJ_Release=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -DNDEBUG -Wall  -L"C:/Users/User/Desktop/Project NEBULA/CODE/0.1/Nebula 0.1/Nebula 0.1" -std=gnu99 -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Nebula_0.1.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} -r dist/Release

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
