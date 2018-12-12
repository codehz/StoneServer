#include "../patched.h"

#include <stone/server_hook.h>

namespace {

SHook(void, _ZN16EventCoordinatorI27ServerInstanceEventListenerE12processEventESt8functionIF11EventResultPS0_EE, void *) {}

SHook(void, _ZN30ServerInstanceEventCoordinator16sendServerResumeER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator17sendLeaveGameDoneER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator17sendServerSuspendER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator18sendStartLeaveGameER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator19sendServerUpdateEndER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator23sendServerInitializeEndER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator23sendServerThreadStartedER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator23sendServerThreadStoppedER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator25sendServerInitializeStartER14ServerInstance, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator26sendServerLevelInitializedER14ServerInstanceR5Level, ServerInstance *self) {}
SHook(void, _ZN30ServerInstanceEventCoordinator30sendServerMinecraftInitializedER14ServerInstanceR9Minecraft, ServerInstance *self) {}

} // namespace