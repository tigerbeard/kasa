##
## oryx/utility/make.inc
##
## History:
##    2014/07/21 - [Yupeng Chang] Created file
##
## Copyright (c) 2016 Ambarella, Inc.
##
## This file and its contents ("Software") are protected by intellectual
## property rights including, without limitation, U.S. and/or foreign
## copyrights. This Software is also the confidential and proprietary
## information of Ambarella, Inc. and its licensors. You may not use, reproduce,
## disclose, distribute, modify, or otherwise prepare derivative works of this
## Software or any portion thereof except pursuant to a signed license agreement
## or nondisclosure agreement with Ambarella, Inc. or its authorized affiliates.
## In the absence of such an agreement, you agree to promptly notify and return
## this Software to Ambarella, Inc.
##
## THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
## INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF NON-INFRINGEMENT,
## MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
## IN NO EVENT SHALL AMBARELLA, INC. OR ITS AFFILIATES BE LIABLE FOR ANY DIRECT,
## INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; COMPUTER FAILURE OR MALFUNCTION; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
## POSSIBILITY OF SUCH DAMAGE.
##

LOCAL_PATH   := $(call my-dir)

## libamosal.so
ifeq ($(BUILD_AMBARELLA_ORYX_OSAL), y)

include $(CLEAR_VARS)

OSAL_VER_FILE   = $(ORYX_DIR)/include/utility/version.h
OSAL_VER_PREFIX = OSAL

OSAL_TARGET   = libamosal.so
LOCAL_TARGET := $(OSAL_TARGET)
LOCAL_SRCS   := $(LOCAL_PATH)/am_fd.cpp     \
                $(LOCAL_PATH)/am_io.cpp     \
                $(LOCAL_PATH)/am_file.cpp   \
                $(LOCAL_PATH)/am_event.cpp  \
                $(LOCAL_PATH)/am_mutex.cpp  \
                $(LOCAL_PATH)/am_timer.cpp  \
                $(LOCAL_PATH)/am_plugin.cpp \
                $(LOCAL_PATH)/am_signal.cpp \
                $(LOCAL_PATH)/am_thread.cpp

LOCAL_LDFLAGS := -lpthread -ldl

LOCAL_CFLAGS := -I$(ORYX_DIR)/include/utility \
                -I$(ORYX_DIR)/include         \
                -std=c++11 -Werror

LOCAL_LIBS := libamutil.so

OSAL_SO_VER_MAJOR  := $(shell awk '/define\ $(OSAL_VER_PREFIX)_LIB_MAJOR/{print $$3}' $(OSAL_VER_FILE))
OSAL_SO_VER_MINOR  := $(shell awk '/define\ $(OSAL_VER_PREFIX)_LIB_MINOR/{print $$3}' $(OSAL_VER_FILE))
OSAL_SO_VER_PATCH  := $(shell awk '/define\ $(OSAL_VER_PREFIX)_LIB_PATCH/{print $$3}' $(OSAL_VER_FILE))
OSAL_SO_VER_STRING := $(OSAL_SO_VER_MAJOR).$(OSAL_SO_VER_MINOR).$(OSAL_SO_VER_PATCH)

OSAL_SO_NAME   = $(patsubst %.so,%.so.$(OSAL_SO_VER_MAJOR), $(OSAL_TARGET))
OSAL_SO_TARGET = $(patsubst %.so,%.so.$(OSAL_SO_VER_STRING), $(OSAL_TARGET))

LOCAL_SO_NAME := $(OSAL_SO_NAME)

include $(BUILD_APP)

.PHONY: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(LOCAL_MODULE)
	@mkdir -p $(ORYX_LIB_DIR)/
	@cp -dpRf $< $(ORYX_LIB_DIR)/$(OSAL_SO_TARGET)
	@ln -sf $(OSAL_SO_TARGET) $(ORYX_LIB_DIR)/$(OSAL_SO_NAME)
	@echo "Build $@ Done."

$(call add-target-into-build, $(LOCAL_TARGET))

endif
