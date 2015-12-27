# This file was automagically generated by mbed.org. For more information,
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded

GCC_BIN =
PROJECT = weather_machine
OBJECTS = ./main.o \
		  ./sunrise/sunrise.o
SYS_OBJECTS = ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/board.o ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/cmsis_nvic.o ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/mbed_overrides.o ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/retarget.o ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/startup_MK64F12.o ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/system_MK64F12.o \
			  ./mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M4/TOOLCHAIN_GCC/HAL_CM4.o ./mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M4/TOOLCHAIN_GCC/SVC_Table.o \
			  ./mbed-rtos/rtos/Semaphore.o ./mbed-rtos/rtos/Mutex.o ./mbed-rtos/rtos/RtosTimer.o ./mbed-rtos/rtos/Thread.o \
			  ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Mailbox.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Robin.o ./mbed-rtos/rtx/TARGET_CORTEX_M/HAL_CM.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Mutex.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Event.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Time.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Task.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_CMSIS.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_List.o ./mbed-rtos/rtx/TARGET_CORTEX_M/RTX_Conf_CM.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_System.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_Semaphore.o ./mbed-rtos/rtx/TARGET_CORTEX_M/rt_MemBox.o \
			  ./MQTTPacket/MQTTConnectClient.o ./MQTTPacket/MQTTSubscribeClient.o ./MQTTPacket/MQTTConnectServer.o ./MQTTPacket/MQTTSubscribeServer.o ./MQTTPacket/MQTTDeserializePublish.o ./MQTTPacket/MQTTUnsubscribeClient.o ./MQTTPacket/MQTTPacket.o ./MQTTPacket/MQTTUnsubscribeServer.o ./MQTTPacket/MQTTSerializePublish.o \
			  ./C12832/TextDisplay.o ./C12832/GraphicsDisplay.o ./C12832/C12832.o \
			  ./NetworkAPI/socket.o ./NetworkAPI/buffer.o ./NetworkAPI/select.o ./NetworkAPI/tcp/socket.o ./NetworkAPI/udp/socket.o ./NetworkAPI/ip/address.o ./NetworkAPI/ip/endpoint.o \
			  ./EthernetInterface/EthernetInterface.o ./EthernetInterface/Socket/TCPSocketServer.o ./EthernetInterface/Socket/Socket.o ./EthernetInterface/Socket/Endpoint.o ./EthernetInterface/Socket/UDPSocket.o ./EthernetInterface/Socket/TCPSocketConnection.o \
			  ./EthernetInterface/lwip-eth/arch/TARGET_Freescale/fsl_enet_driver.o ./EthernetInterface/lwip-eth/arch/TARGET_Freescale/hardware_init_MK64F12.o ./EthernetInterface/lwip-eth/arch/TARGET_Freescale/k64f_emac.o \
			  ./EthernetInterface/lwip-sys/arch/memcpy.o ./EthernetInterface/lwip-sys/arch/sys_arch.o ./EthernetInterface/lwip-sys/arch/checksum.o ./EthernetInterface/lwip/core/mem.o ./EthernetInterface/lwip/core/raw.o ./EthernetInterface/lwip/core/def.o ./EthernetInterface/lwip/core/tcp_in.o ./EthernetInterface/lwip/core/dns.o ./EthernetInterface/lwip/core/stats.o ./EthernetInterface/lwip/core/timers.o ./EthernetInterface/lwip/core/init.o ./EthernetInterface/lwip/core/netif.o ./EthernetInterface/lwip/core/udp.o ./EthernetInterface/lwip/core/pbuf.o ./EthernetInterface/lwip/core/tcp_out.o ./EthernetInterface/lwip/core/memp.o ./EthernetInterface/lwip/core/tcp.o ./EthernetInterface/lwip/core/dhcp.o ./EthernetInterface/lwip/core/ipv4/ip_frag.o ./EthernetInterface/lwip/core/ipv4/ip_addr.o ./EthernetInterface/lwip/core/ipv4/autoip.o ./EthernetInterface/lwip/core/ipv4/icmp.o ./EthernetInterface/lwip/core/ipv4/inet_chksum.o ./EthernetInterface/lwip/core/ipv4/ip.o ./EthernetInterface/lwip/core/ipv4/inet.o ./EthernetInterface/lwip/core/ipv4/igmp.o ./EthernetInterface/lwip/core/snmp/msg_in.o ./EthernetInterface/lwip/core/snmp/mib2.o ./EthernetInterface/lwip/core/snmp/asn1_dec.o ./EthernetInterface/lwip/core/snmp/asn1_enc.o ./EthernetInterface/lwip/core/snmp/mib_structs.o ./EthernetInterface/lwip/core/snmp/msg_out.o ./EthernetInterface/lwip/netif/etharp.o ./EthernetInterface/lwip/netif/ethernetif.o ./EthernetInterface/lwip/netif/slipif.o ./EthernetInterface/lwip/netif/ppp/chpms.o ./EthernetInterface/lwip/netif/ppp/fsm.o ./EthernetInterface/lwip/netif/ppp/auth.o ./EthernetInterface/lwip/netif/ppp/magic.o ./EthernetInterface/lwip/netif/ppp/chap.o ./EthernetInterface/lwip/netif/ppp/randm.o ./EthernetInterface/lwip/netif/ppp/pap.o ./EthernetInterface/lwip/netif/ppp/vj.o ./EthernetInterface/lwip/netif/ppp/ipcp.o ./EthernetInterface/lwip/netif/ppp/md5.o ./EthernetInterface/lwip/netif/ppp/ppp_oe.o ./EthernetInterface/lwip/netif/ppp/lcp.o ./EthernetInterface/lwip/netif/ppp/ppp.o ./EthernetInterface/lwip/api/sockets.o ./EthernetInterface/lwip/api/api_msg.o ./EthernetInterface/lwip/api/err.o ./EthernetInterface/lwip/api/netifapi.o ./EthernetInterface/lwip/api/netbuf.o ./EthernetInterface/lwip/api/netdb.o ./EthernetInterface/lwip/api/tcpip.o ./EthernetInterface/lwip/api/api_lib.o


INCLUDE_PATHS = -I. -I./mbed -I./mbed/TARGET_K64F -I./mbed/TARGET_K64F/TARGET_Freescale -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/common -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/common/phyksz8081 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/clock -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/enet -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/interrupt -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/pit -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/pit/common -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/adc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/can -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/dac -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/dmamux -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/dspi -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/edma -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/enet -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/flextimer -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/gpio -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/i2c -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/llwu -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/lptmr -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/lpuart -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/mcg -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/mpu -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/osc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/pdb -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/pit -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/pmc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/port -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/rcm -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/rtc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/sai -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/sdhc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/sim -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/smc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/uart -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/wdog -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/utilities -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/MK64F12 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/TARGET_FRDM -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device/MK64F12 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device/device -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device/device/MK64F12 -I./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM \
				-I./sunrise \
				-I. -I./C12832 -I./NetworkAPI -I./NetworkAPI/tcp -I./NetworkAPI/udp -I./NetworkAPI/ip -I./mbed -I./mbed/TARGET_K64F -I./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM -I./mbed/TARGET_K64F/TARGET_Freescale -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/MK64F12 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device/MK64F12 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device/device -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/device/device/MK64F12 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_MCU_K64F/TARGET_FRDM -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/common -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/common/phyksz8081 -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/lptmr -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/dac -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/gpio -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/port -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/llwu -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/sim -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/rcm -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/sdhc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/can -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/mpu -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/smc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/osc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/flextimer -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/pdb -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/enet -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/i2c -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/uart -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/dspi -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/pit -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/lpuart -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/sai -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/rtc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/mcg -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/edma -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/pmc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/adc -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/wdog -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/hal/dmamux -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/utilities -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/enet -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/pit -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/pit/common -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/interrupt -I./mbed/TARGET_K64F/TARGET_Freescale/TARGET_KPSDK_MCUS/TARGET_KPSDK_CODE/drivers/clock -I./HTTPServer -I./EthernetInterface -I./EthernetInterface/lwip-eth -I./EthernetInterface/lwip-eth/arch -I./EthernetInterface/lwip-eth/arch/TARGET_Freescale -I./EthernetInterface/lwip-sys -I./EthernetInterface/lwip-sys/arch -I./EthernetInterface/lwip -I./EthernetInterface/lwip/core -I./EthernetInterface/lwip/core/ipv4 -I./EthernetInterface/lwip/core/snmp -I./EthernetInterface/lwip/include -I./EthernetInterface/lwip/include/ipv4 -I./EthernetInterface/lwip/include/ipv4/lwip -I./EthernetInterface/lwip/include/netif -I./EthernetInterface/lwip/include/lwip -I./EthernetInterface/lwip/netif -I./EthernetInterface/lwip/netif/ppp -I./EthernetInterface/lwip/api -I./EthernetInterface/Socket -I./mbed-rtos -I./mbed-rtos/rtx -I./mbed-rtos/rtx/TARGET_CORTEX_M -I./mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M4 -I./mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M4/TOOLCHAIN_GCC -I./mbed-rtos/rtos -I./mbed-rpc  -I./HTTPServer -I./HTTPServer/Handler -I./FATFileSystem -I./FATFileSystem/ChaN -I./SDFileSystem -I./Socket -I./HTTPServer -I./DHT22 -I./GP2Y10 -I./MQTT -I./MQTTPacket/ -I./FP/

LIBRARY_PATHS = -L./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM
LIBRARIES = -lmbed
LINKER_SCRIPT = ./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/K64FN1M0xxx12.ld

###############################################################################
AS      = $(GCC_BIN)arm-none-eabi-as
CC      = $(GCC_BIN)arm-none-eabi-gcc
CPP     = $(GCC_BIN)arm-none-eabi-g++
LD      = $(GCC_BIN)arm-none-eabi-gcc
OBJCOPY = $(GCC_BIN)arm-none-eabi-objcopy
OBJDUMP = $(GCC_BIN)arm-none-eabi-objdump
SIZE    = $(GCC_BIN)arm-none-eabi-size

ifeq ($(HARDFP),1)
	FLOAT_ABI = hard
else
	FLOAT_ABI = softfp
endif


CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=$(FLOAT_ABI)
CC_FLAGS = $(CPU) -c -g -fno-common -fmessage-length=0 -Wall -Wextra -fno-exceptions -ffunction-sections -fdata-sections -fomit-frame-pointer -MMD -MP
CC_SYMBOLS = -DTARGET_KPSDK_MCUS -DTARGET_FF_ARDUINO -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -DCPU_MK64FN1M0VMD12 -DTARGET_FRDM -DTARGET_CORTEX_M -D__FPU_PRESENT=1 -DTARGET_KPSDK_CODE -DTARGET_M4 -D__MBED__=1 -DTARGET_K64F -DTARGET_Freescale -D__CORTEX_M4 -DFSL_RTOS_MBED -DTARGET_MCU_K64F -DARM_MATH_CM4 -DMBED_BUILD_TIMESTAMP=1450710537.68

LD_FLAGS = $(CPU) -Wl,--gc-sections --specs=nano.specs -u _printf_float -u _scanf_float -Wl,--wrap,main -Wl,-Map=$(PROJECT).map,--cref
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys


ifeq ($(DEBUG), 1)
  CC_FLAGS += -DDEBUG -O0
else
  CC_FLAGS += -DNDEBUG -Os
endif

.PHONY: all clean lst size

all: $(PROJECT).bin $(PROJECT).hex size


clean:
	rm -f $(PROJECT).bin $(PROJECT).elf $(PROJECT).hex $(PROJECT).map $(PROJECT).lst $(OBJECTS) $(DEPS)


.asm.o:
	$(CC) $(CPU) -c -x assembler-with-cpp -o $@ $<
.s.o:
	$(CC) $(CPU) -c -x assembler-with-cpp -o $@ $<
.S.o:
	$(CC) $(CPU) -c -x assembler-with-cpp -o $@ $<

.c.o:
	$(CC)  $(CC_FLAGS) $(CC_SYMBOLS) -std=gnu99   $(INCLUDE_PATHS) -o $@ $<

.cpp.o:
	$(CPP) $(CC_FLAGS) $(CC_SYMBOLS) -std=gnu++98 -fno-rtti $(INCLUDE_PATHS) -o $@ $<



$(PROJECT).elf: $(OBJECTS) $(SYS_OBJECTS)
	$(LD) $(LD_FLAGS) -T$(LINKER_SCRIPT) $(LIBRARY_PATHS) -o $@ $^ $(LIBRARIES) $(LD_SYS_LIBS) $(LIBRARIES) $(LD_SYS_LIBS)


$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

$(PROJECT).hex: $(PROJECT).elf
	@$(OBJCOPY) -O ihex $< $@

$(PROJECT).lst: $(PROJECT).elf
	@$(OBJDUMP) -Sdh $< > $@

lst: $(PROJECT).lst

size: $(PROJECT).elf
	$(SIZE) $(PROJECT).elf

DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)
