CXXFLAGS = -O2 -g -DMESA_GLES2 -Wall -c -std=c++14 -I../noudar-core/noudar-core/include -Iincludes -I../OpenALSoundSystem -I../noudar-rendering -I../gles2-renderer/ -IX11-version -I../glm -I../nanovg/src -DGLM_FORCE_RADIANS -I../noudar-core/EASTL/include -I../noudar-core/EASTL/test/packages/EABase/include/Common -DUSE_ITEMS_INSTANTLY
LDFLAGS = -lX11 -lGLESv2 -lEGL -lpng -lopenal

OBJS = X11-version/main.o \
    ../noudar-core/noudar-core/src/Vec2i.o \
    ../noudar-core/noudar-core/src/CActor.o \
    ../noudar-core/noudar-core/src/CMonster.o \
    ../noudar-core/noudar-core/src/CMonsterGenerator.o \
    ../noudar-core/noudar-core/src/CTeam.o \
    ../noudar-core/noudar-core/src/CMap.o \
    ../noudar-core/noudar-core/src/Common.o \
    ../noudar-core/noudar-core/src/CCharacter.o \
    ../noudar-core/noudar-core/src/CCharacterArchetype.o \
    ../noudar-core/noudar-core/src/CDoorway.o \
    ../noudar-core/noudar-core/src/IFileLoaderDelegate.o \
    ../noudar-core/noudar-core/src/IMapElement.o \
    ../noudar-core/noudar-core/src/CGame.o \
    ../noudar-core/noudar-core/src/CItem.o \
    ../noudar-core/noudar-core/src/CStorageItem.o \
    ../noudar-core/noudar-core/src/CPlainFileLoader.o \
    ../noudar-core/noudar-core/src/CGameDelegate.o \
    ../noudar-core/noudar-core/src/commands/IGameCommand.o \
    ../noudar-core/noudar-core/src/commands/CMoveActorCommand.o \
    ../noudar-core/noudar-core/src/commands/CLoadNewLevelCommand.o \
    ../noudar-core/noudar-core/src/commands/CTurnActorCommand.o \
    ../noudar-core/noudar-core/src/commands/CQuitCommand.o \
    ../noudar-core/noudar-core/src/commands/CNullCommand.o \
    ../noudar-core/noudar-core/src/commands/CEndTurnCommand.o \
    ../noudar-core/noudar-core/src/commands/CPickItemCommand.o \
    ../noudar-core/noudar-core/src/commands/CDropItemCommand.o \
    ../noudar-core/noudar-core/src/commands/CSuggestItemCommand.o \
    ../noudar-core/noudar-core/src/commands/CUseCurrentItemCommand.o \
    ../noudar-core/noudar-core/src/commands/CCycleNextItemCommand.o \
    ../noudar-core/noudar-core/src/commands/CCyclePreviousItemCommand.o \
    ../noudar-rendering/GameNativeAPI.o \
        ../noudar-rendering/OverlayNanoVGRenderer.o \
        ../noudar-rendering/DungeonGLES2Renderer.o \
        ../noudar-rendering/LightningStrategy.o \
        ../noudar-rendering/VisibilityStrategy.o \
        ../noudar-rendering/NoudarDungeonSnapshot.o \
        ../noudar-rendering/SplatAnimation.o \
        ../noudar-rendering/RenderingJobSnapshotAdapter.o \
        ../noudar-rendering/CTile3DProperties.o \
        ../noudar-rendering/NoudarGLES2Bridge.o \
        ../noudar-rendering/Animation.o \
        ../noudar-rendering/AnimationStep.o \
        ../noudar-rendering/GraphicNode.o \
        X11-version/WindowOperationsX11.o \
        X11-version/x11_native.o \
        ../gles2-renderer/LoadPNG.o \
        ../gles2-renderer/Logger.o \
        ../gles2-renderer/CLerp.o \
        ../gles2-renderer/Trig.o \
        ../gles2-renderer/Camera.o \
        ../gles2-renderer/TrigBatch.o \
        ../gles2-renderer/VBORenderingJob.o \
        ../gles2-renderer/NativeBitmap.o \
        ../gles2-renderer/Scene.o \
        ../nanovg/src/nanovg.o \
        ../OpenALSoundSystem/SoundClip.o \
        ../OpenALSoundSystem/SoundEmitter.o \
        ../OpenALSoundSystem/SoundListener.o \
        ../OpenALSoundSystem/SoundUtils.o

TARGET = noudar

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
	rm *~
