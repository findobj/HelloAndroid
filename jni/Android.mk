# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := native
LOCAL_SRC_FILES := main.c \
		CppMix.cpp \
		findobj/component/AppDelegate.cpp \
		findobj/foundation/AStar.cpp \
		findobj/foundation/Tile.cpp \
		findobj/foundation/Node.cpp \
		findobj/foundation/Point.cpp \
		findobj/foundation/Rect.cpp \
		findobj/foundation/Size.cpp \
		findobj/foundation/List.cpp \
		findobj/foundation/Object.cpp \
		findobj/util/Config.cpp \
		findobj/util/Log.cpp 
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
		$(LOCAL_PATH)/findobj
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM
LOCAL_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
