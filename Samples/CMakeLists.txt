# Adding options only to speed up build/dev time

# skip pre-1.9mercurial-Android-stuff
if (NOT GAMEKIT_GRAPHIC_BACKEND EQUAL GAMEKIT_GRAPHIC_BACKEND_19_mercurial)
    if (OGREKIT_BUILD_ANDROID)
	    subdirs(AndroidDemo)
    elseif (OGREKIT_BUILD_IPHONE)
	    subdirs(IPhoneDemo)
    else()
	if (SAMPLES_ANDROIDTEST)
	    subdirs(AndroidDemo/Test)
	endif()
    endif()
endif()


if (SAMPLES_RUNTIME)
    if (NOT OGREKIT_BUILD_ANDROID)
	subdirs(Runtime)
    else()
	message(STATUS "**** android runtime: not yet :D")
    endif()
endif()

if (SAMPLES_LOGICDEMO)
	subdirs(LogicDemo)
endif()

if (SAMPLES_VEHICLEDEMO)
	subdirs(VehicleDemo)
endif()

if (SAMPLES_LUARUNTIME AND OGREKIT_USE_LUA)
	subdirs(LuaRuntime)
endif()


if (SAMPLES_CPPDEMO)
    if (NOT OGREKIT_BUILD_ANDROID)
	subdirs(CppDemo)
    else()
	message(STATUS "**** android CppDemo: not yet :D")
    endif()
endif()

if (SAMPLES_NODE_EDITOR)
	subdirs(NodeEditor)
endif()

if (SAMPLES_EMBEDDEMO)
	subdirs(EmbedDemo)
endif()

if (SAMPLES_INSPECTOR)
	subdirs(FileInspector)
endif()

if (SAMPLES_LUA_EDITOR)
    subdirs(LuaEditor)
endif()

if (SAMPLES_GUIDEMO)
    subdirs(GuiDemo)
endif()
