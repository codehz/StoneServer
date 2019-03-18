// This file was automatically generated using tools/process_headers.py
// Generated on Mon Mar 18 2019 13:08:07 UTC

#include <hybris/dlfcn.h>
#include <log.h>

#include "MinecraftCommands.h"
static void (MinecraftCommands::*_MinecraftCommands_setOutputSender)(std::unique_ptr<CommandOutputSender>);
void MinecraftCommands::setOutputSender(std::unique_ptr<CommandOutputSender> p1) {
    (this->*_MinecraftCommands_setOutputSender)(std::move(p1));
}
static MCRESULT (MinecraftCommands::*_MinecraftCommands_requestCommandExecution)(std::unique_ptr<CommandOrigin>, mcpe::string const &, int, bool) const;
MCRESULT MinecraftCommands::requestCommandExecution(std::unique_ptr<CommandOrigin> p1, mcpe::string const & p2, int p3, bool p4) const {
    return (this->*_MinecraftCommands_requestCommandExecution)(std::move(p1), p2, p3, p4);
}
static CommandRegistry & (MinecraftCommands::*_MinecraftCommands_getRegistry)();
CommandRegistry & MinecraftCommands::getRegistry() {
    return (this->*_MinecraftCommands_getRegistry)();
}

#include "CommandRegistry.h"
static std::unique_ptr<AutoCompleteInformation> (CommandRegistry::*_CommandRegistry_getAutoCompleteOptions)(CommandOrigin const &, mcpe::string const &, unsigned int) const;
std::unique_ptr<AutoCompleteInformation> CommandRegistry::getAutoCompleteOptions(CommandOrigin const & p1, mcpe::string const & p2, unsigned int p3) const {
    return (this->*_CommandRegistry_getAutoCompleteOptions)(p1, p2, p3);
}
static CommandRegistry::Signature * (CommandRegistry::*_CommandRegistry_findCommand)(mcpe::string const &);
CommandRegistry::Signature * CommandRegistry::findCommand(mcpe::string const & p1) {
    return (this->*_CommandRegistry_findCommand)(p1);
}
static void (CommandRegistry::*_CommandRegistry_registerOverloadInternal)(CommandRegistry::Signature &, CommandRegistry::Overload &);
void CommandRegistry::registerOverloadInternal(CommandRegistry::Signature & p1, CommandRegistry::Overload & p2) {
    (this->*_CommandRegistry_registerOverloadInternal)(p1, p2);
}
static void (CommandRegistry::*_CommandRegistry_registerCommand)(mcpe::string const &, char const *, CommandPermissionLevel, CommandFlag, CommandFlag);
void CommandRegistry::registerCommand(mcpe::string const & p1, char const * p2, CommandPermissionLevel p3, CommandFlag p4, CommandFlag p5) {
    (this->*_CommandRegistry_registerCommand)(p1, p2, p3, p4, p5);
}
static void (CommandRegistry::*_CommandRegistry_buildOverload)(CommandRegistry::Overload &);
void CommandRegistry::buildOverload(CommandRegistry::Overload & p1) {
    (this->*_CommandRegistry_buildOverload)(p1);
}
static void (CommandRegistry::*_CommandRegistry_addSoftEnum)(mcpe::string const &, std::vector<mcpe::string>, bool);
void CommandRegistry::addSoftEnum(mcpe::string const & p1, std::vector<mcpe::string> p2, bool p3) {
    (this->*_CommandRegistry_addSoftEnum)(p1, p2, p3);
}
static void (CommandRegistry::*_CommandRegistry_setSoftEnumValues)(mcpe::string const &, std::vector<mcpe::string>);
void CommandRegistry::setSoftEnumValues(mcpe::string const & p1, std::vector<mcpe::string> p2) {
    (this->*_CommandRegistry_setSoftEnumValues)(p1, p2);
}
static void (CommandParameterData::*_CommandParameterData_CommandParameterData)(typeid_t<CommandRegistry>, Parser, char const *, CommandParameterDataType, char const *, int, bool, int);
CommandParameterData::CommandParameterData(typeid_t<CommandRegistry> p1, Parser p2, char const * p3, CommandParameterDataType p4, char const * p5, int p6, bool p7, int p8) {
    (this->*_CommandParameterData_CommandParameterData)(p1, p2, p3, p4, p5, p6, p7, p8);
}
static void (CommandParameterData::*_CommandParameterData_CommandParameterData2)(CommandParameterData const &);
CommandParameterData::CommandParameterData(CommandParameterData const & p1) {
    (this->*_CommandParameterData_CommandParameterData2)(p1);
}

#include "MessagingCommand.h"
static bool (MessagingCommand::*_MessagingCommand_checkChatPermissions)(CommandOrigin const &, CommandOutput &) const;
bool MessagingCommand::checkChatPermissions(CommandOrigin const & p1, CommandOutput & p2) const {
    return (this->*_MessagingCommand_checkChatPermissions)(p1, p2);
}

#include "CommandOutput.h"
static std::vector<CommandOutputMessage> const & (CommandOutput::*_CommandOutput_getMessages)() const;
std::vector<CommandOutputMessage> const & CommandOutput::getMessages() const {
    return (this->*_CommandOutput_getMessages)();
}
static void (CommandOutput::*_CommandOutput_addMessage)(mcpe::string const &, std::vector<CommandOutputParameter> const &, CommandOutputMessageType);
void CommandOutput::addMessage(mcpe::string const & p1, std::vector<CommandOutputParameter> const & p2, CommandOutputMessageType p3) {
    (this->*_CommandOutput_addMessage)(p1, p2, p3);
}
static void (CommandOutput::*_CommandOutput_error)(mcpe::string const &, std::vector<CommandOutputParameter> const &);
void CommandOutput::error(mcpe::string const & p1, std::vector<CommandOutputParameter> const & p2) {
    (this->*_CommandOutput_error)(p1, p2);
}
static void (CommandOutput::*_CommandOutput_success)(mcpe::string const &, std::vector<CommandOutputParameter> const &);
void CommandOutput::success(mcpe::string const & p1, std::vector<CommandOutputParameter> const & p2) {
    (this->*_CommandOutput_success)(p1, p2);
}
static void (CommandOutput::*_CommandOutput_success2)();
void CommandOutput::success() {
    (this->*_CommandOutput_success2)();
}
static void (CommandOutputParameter::*_CommandOutputParameter_CommandOutputParameter)(mcpe::string const &);
CommandOutputParameter::CommandOutputParameter(mcpe::string const & p1) {
    (this->*_CommandOutputParameter_CommandOutputParameter)(p1);
}
static void (CommandOutputParameter::*_CommandOutputParameter_CommandOutputParameter2)(int);
CommandOutputParameter::CommandOutputParameter(int p1) {
    (this->*_CommandOutputParameter_CommandOutputParameter2)(p1);
}

#include "Common.h"
static mcpe::string (*_Common_getGameVersionStringNet)();
mcpe::string Common::getGameVersionStringNet() {
    return _Common_getGameVersionStringNet();
}
static mcpe::string (*_Common_getGameDevVersionString)();
mcpe::string Common::getGameDevVersionString() {
    return _Common_getGameDevVersionString();
}

#include "FilePickerSettings.h"

#include "IMinecraftApp.h"

#include "NetworkIdentifier.h"
static int (NetworkIdentifier::*_NetworkIdentifier_getHash)() const;
int NetworkIdentifier::getHash() const {
    return (this->*_NetworkIdentifier_getHash)();
}
static bool (NetworkIdentifier::*_NetworkIdentifier_equalsTypeData)(NetworkIdentifier const &) const;
bool NetworkIdentifier::equalsTypeData(NetworkIdentifier const & p1) const {
    return (this->*_NetworkIdentifier_equalsTypeData)(p1);
}

#include "Options.h"
static bool (Options::*_Options_getFullscreen)() const;
bool Options::getFullscreen() const {
    return (this->*_Options_getFullscreen)();
}
static void (Options::*_Options_setFullscreen)(bool);
void Options::setFullscreen(bool p1) {
    (this->*_Options_setFullscreen)(p1);
}

#include "V8Internals.h"

#include "AutomationPlayerCommandOrigin.h"
static void (AutomationPlayerCommandOrigin::*_AutomationPlayerCommandOrigin_AutomationPlayerCommandOrigin)(mcpe::string const &, Player &);
AutomationPlayerCommandOrigin::AutomationPlayerCommandOrigin(mcpe::string const & p1, Player & p2) {
    (this->*_AutomationPlayerCommandOrigin_AutomationPlayerCommandOrigin)(p1, p2);
}

#include "AutoComplete.h"

#include "json.h"
static void (Json::Reader::*_Json_Reader_Reader)();
Json::Reader::Reader() {
    (this->*_Json_Reader_Reader)();
}
static bool (Json::Reader::*_Json_Reader_parse)(std::istream &, Json::Value &, bool);
bool Json::Reader::parse(std::istream & p1, Json::Value & p2, bool p3) {
    return (this->*_Json_Reader_parse)(p1, p2, p3);
}
static void (Json::StyledWriter::*_Json_StyledWriter_StyledWriter)();
Json::StyledWriter::StyledWriter() {
    (this->*_Json_StyledWriter_StyledWriter)();
}
static void (Json::StyledWriter::*_Json_StyledWriter_destructor)();
Json::StyledWriter::~StyledWriter() {
    (this->*_Json_StyledWriter_destructor)();
}
static mcpe::string (Json::StyledWriter::*_Json_StyledWriter_write)(Json::Value const &);
mcpe::string Json::StyledWriter::write(Json::Value const & p1) {
    return (this->*_Json_StyledWriter_write)(p1);
}
static void (Json::FastWriter::*_Json_FastWriter_FastWriter)();
Json::FastWriter::FastWriter() {
    (this->*_Json_FastWriter_FastWriter)();
}
static void (Json::FastWriter::*_Json_FastWriter_destructor)();
Json::FastWriter::~FastWriter() {
    (this->*_Json_FastWriter_destructor)();
}
static mcpe::string (Json::FastWriter::*_Json_FastWriter_write)(Json::Value const &);
mcpe::string Json::FastWriter::write(Json::Value const & p1) {
    return (this->*_Json_FastWriter_write)(p1);
}
static void (Json::Value::*_Json_Value_Value)(Json::ValueType);
Json::Value::Value(Json::ValueType p1) {
    (this->*_Json_Value_Value)(p1);
}
static void (Json::Value::*_Json_Value_destructor)();
Json::Value::~Value() {
    (this->*_Json_Value_destructor)();
}

#include "ContentIdentity.h"
ContentIdentity * ContentIdentity::EMPTY;

#include "Block.h"

#include "App.h"
static void (App::*_App_init)(AppContext &);
void App::init(AppContext & p1) {
    (this->*_App_init)(p1);
}
static int vti_App_quit;
void App::quit(mcpe::string const & p1, mcpe::string const & p2) {
    union { void* voidp; void (App::*funcp)(mcpe::string const &, mcpe::string const &); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_App_quit];
    (this->*u.funcp)(p1, p2);
}
static int vti_App_wantToQuit;
bool App::wantToQuit() {
    union { void* voidp; bool (App::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_App_wantToQuit];
    return (this->*u.funcp)();
}

#include "PermissionsFile.h"
static void (PermissionsFile::*_PermissionsFile_PermissionsFile)(mcpe::string const &);
PermissionsFile::PermissionsFile(mcpe::string const & p1) {
    (this->*_PermissionsFile_PermissionsFile)(p1);
}

#include "SharedConstants.h"
int * SharedConstants::MajorVersion;
int * SharedConstants::MinorVersion;
int * SharedConstants::PatchVersion;
int * SharedConstants::RevisionVersion;

#include "Resource.h"
static void (*_ResourceLoaders_registerLoader)(ResourceFileSystem, std::unique_ptr<ResourceLoader>);
void ResourceLoaders::registerLoader(ResourceFileSystem p1, std::unique_ptr<ResourceLoader> p2) {
    _ResourceLoaders_registerLoader(p1, std::move(p2));
}

#include "Mouse.h"
static void (*_Mouse_feed)(char, char, short, short, short, short);
void Mouse::feed(char p1, char p2, short p3, short p4, short p5, short p6) {
    _Mouse_feed(p1, p2, p3, p4, p5, p6);
}

#include "MinecraftGame.h"
static void (MinecraftGame::*_MinecraftGame_MinecraftGame)(int, char * *);
MinecraftGame::MinecraftGame(int p1, char * * p2) {
    (this->*_MinecraftGame_MinecraftGame)(p1, p2);
}
static void (MinecraftGame::*_MinecraftGame_destructor)();
MinecraftGame::~MinecraftGame() {
    (this->*_MinecraftGame_destructor)();
}
static bool (MinecraftGame::*_MinecraftGame_isInGame)() const;
bool MinecraftGame::isInGame() const {
    return (this->*_MinecraftGame_isInGame)();
}
static void (MinecraftGame::*_MinecraftGame_requestLeaveGame)(bool, bool);
void MinecraftGame::requestLeaveGame(bool p1, bool p2) {
    (this->*_MinecraftGame_requestLeaveGame)(p1, p2);
}
static void (MinecraftGame::*_MinecraftGame_update)();
void MinecraftGame::update() {
    (this->*_MinecraftGame_update)();
}
static void (MinecraftGame::*_MinecraftGame_setRenderingSize)(int, int);
void MinecraftGame::setRenderingSize(int p1, int p2) {
    (this->*_MinecraftGame_setRenderingSize)(p1, p2);
}
static void (MinecraftGame::*_MinecraftGame_setUISizeAndScale)(int, int, float);
void MinecraftGame::setUISizeAndScale(int p1, int p2, float p3) {
    (this->*_MinecraftGame_setUISizeAndScale)(p1, p2, p3);
}
static std::shared_ptr<Options> (MinecraftGame::*_MinecraftGame_getPrimaryUserOptions)();
std::shared_ptr<Options> MinecraftGame::getPrimaryUserOptions() {
    return (this->*_MinecraftGame_getPrimaryUserOptions)();
}
static ClientInstance * (MinecraftGame::*_MinecraftGame_getPrimaryClientInstance)();
ClientInstance * MinecraftGame::getPrimaryClientInstance() {
    return (this->*_MinecraftGame_getPrimaryClientInstance)();
}
static void (MinecraftGame::*_MinecraftGame_startLeaveGame)();
void MinecraftGame::startLeaveGame() {
    (this->*_MinecraftGame_startLeaveGame)();
}
static void (MinecraftGame::*_MinecraftGame_continueLeaveGame)();
void MinecraftGame::continueLeaveGame() {
    (this->*_MinecraftGame_continueLeaveGame)();
}
static void (MinecraftGame::*_MinecraftGame_setTextboxText)(mcpe::string const &, int);
void MinecraftGame::setTextboxText(mcpe::string const & p1, int p2) {
    (this->*_MinecraftGame_setTextboxText)(p1, p2);
}

#include "Level.h"
static unsigned int (*_Level_createRandomSeed)();
unsigned int Level::createRandomSeed() {
    return _Level_createRandomSeed();
}
static ServerLevelEventCoordinator * & (Level::*_Level__getServerLevelEventCoordinator)();
ServerLevelEventCoordinator * & Level::_getServerLevelEventCoordinator() {
    return (this->*_Level__getServerLevelEventCoordinator)();
}
static void (Level::*_Level__setServerLevelEventCoordinator)(std::unique_ptr<ServerLevelEventCoordinator, std::default_delete<ServerLevelEventCoordinator> > &&);
void Level::_setServerLevelEventCoordinator(std::unique_ptr<ServerLevelEventCoordinator, std::default_delete<ServerLevelEventCoordinator> > && p1) {
    (this->*_Level__setServerLevelEventCoordinator)(std::move(p1));
}
static void (Level::*_Level_suspendPlayer)(Player &);
void Level::suspendPlayer(Player & p1) {
    (this->*_Level_suspendPlayer)(p1);
}
static void (Level::*_Level_resumePlayer)(Player &);
void Level::resumePlayer(Player & p1) {
    (this->*_Level_resumePlayer)(p1);
}

#include "AppResourceLoader.h"
static void (AppResourceLoader::*_AppResourceLoader_AppResourceLoader)(std::function<mcpe::string ( )>);
AppResourceLoader::AppResourceLoader(std::function<mcpe::string ( )> p1) {
    (this->*_AppResourceLoader_AppResourceLoader)(p1);
}

#include "EventResult.h"

#include "ServerInstance.h"
static void (EducationOptions::*_EducationOptions_EducationOptions)(ResourcePackManager *);
EducationOptions::EducationOptions(ResourcePackManager * p1) {
    (this->*_EducationOptions_EducationOptions)(p1);
}
static void (ServerInstance::*_ServerInstance_ServerInstance)(IMinecraftApp &, ServerInstanceEventCoordinator &);
ServerInstance::ServerInstance(IMinecraftApp & p1, ServerInstanceEventCoordinator & p2) {
    (this->*_ServerInstance_ServerInstance)(p1, p2);
}
static void (ServerInstance::*_ServerInstance_initializeServer)(IMinecraftApp &, Whitelist &, PermissionsFile *, FilePathManager *, std::chrono::seconds, mcpe::string, mcpe::string, mcpe::string, LevelSettings, int, bool, int, int, int, bool, std::vector<mcpe::string> const &, mcpe::string, mce::UUID const &, IMinecraftEventing &, ResourcePackRepository &, ContentTierManager const &, ResourcePackManager &, std::function<std::unique_ptr<LevelStorage> ( Scheduler & )>, mcpe::string const &, LevelData *, mcpe::string, mcpe::string, std::unique_ptr<EducationOptions>, ResourcePackManager *, std::function<void ( mcpe::string const & )>, std::function<void ( mcpe::string const & )>, ServerCommunicationInterface *);
void ServerInstance::initializeServer(IMinecraftApp & p1, Whitelist & p2, PermissionsFile * p3, FilePathManager * p4, std::chrono::seconds p5, mcpe::string p6, mcpe::string p7, mcpe::string p8, LevelSettings p9, int p10, bool p11, int p12, int p13, int p14, bool p15, std::vector<mcpe::string> const & p16, mcpe::string p17, mce::UUID const & p18, IMinecraftEventing & p19, ResourcePackRepository & p20, ContentTierManager const & p21, ResourcePackManager & p22, std::function<std::unique_ptr<LevelStorage> ( Scheduler & )> p23, mcpe::string const & p24, LevelData * p25, mcpe::string p26, mcpe::string p27, std::unique_ptr<EducationOptions> p28, ResourcePackManager * p29, std::function<void ( mcpe::string const & )> p30, std::function<void ( mcpe::string const & )> p31, ServerCommunicationInterface * p32) {
    (this->*_ServerInstance_initializeServer)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, std::move(p28), p29, p30, p31, p32);
}
static void (ServerInstance::*_ServerInstance_destructor)();
ServerInstance::~ServerInstance() {
    (this->*_ServerInstance_destructor)();
}
static void (ServerInstance::*_ServerInstance_startServerThread)();
void ServerInstance::startServerThread() {
    (this->*_ServerInstance_startServerThread)();
}
static void (ServerInstance::*_ServerInstance_leaveGameSync)();
void ServerInstance::leaveGameSync() {
    (this->*_ServerInstance_leaveGameSync)();
}
static void (ServerInstance::*_ServerInstance_queueForServerThread)(std::function<void ( )>);
void ServerInstance::queueForServerThread(std::function<void ( )> p1) {
    (this->*_ServerInstance_queueForServerThread)(p1);
}

#include "CommandOutputSender.h"
static std::vector<mcpe::string> (*_CommandOutputSender_translate)(std::vector<mcpe::string> const &);
std::vector<mcpe::string> CommandOutputSender::translate(std::vector<mcpe::string> const & p1) {
    return _CommandOutputSender_translate(p1);
}
static void (CommandOutputSender::*_CommandOutputSender_CommandOutputSender)(Automation::AutomationClient &);
CommandOutputSender::CommandOutputSender(Automation::AutomationClient & p1) {
    (this->*_CommandOutputSender_CommandOutputSender)(p1);
}
static void (CommandOutputSender::*_CommandOutputSender_destructor)();
CommandOutputSender::~CommandOutputSender() {
    (this->*_CommandOutputSender_destructor)();
}
static void (CommandOutputSender::*_CommandOutputSender_send)(CommandOrigin const &, CommandOutput const &);
void CommandOutputSender::send(CommandOrigin const & p1, CommandOutput const & p2) {
    (this->*_CommandOutputSender_send)(p1, p2);
}
static void (CommandOutputSender::*_CommandOutputSender_registerOutputCallback)();
void CommandOutputSender::registerOutputCallback() {
    (this->*_CommandOutputSender_registerOutputCallback)();
}

#include "ServerNetworkHandler.h"
static int vti_NetworkPeer_getNetworkStatus;
NetworkStats NetworkPeer::getNetworkStatus() {
    union { void* voidp; NetworkStats (NetworkPeer::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_NetworkPeer_getNetworkStatus];
    return (this->*u.funcp)();
}
static void (ServerNetworkHandler::*_ServerNetworkHandler_addToBlacklist)(mce::UUID const &, mcpe::string const &);
void ServerNetworkHandler::addToBlacklist(mce::UUID const & p1, mcpe::string const & p2) {
    (this->*_ServerNetworkHandler_addToBlacklist)(p1, p2);
}
static void (ServerNetworkHandler::*_ServerNetworkHandler_addToBlacklist2)(mce::UUID const &, mcpe::string const &, mcpe::string const &, std::chrono::seconds const &);
void ServerNetworkHandler::addToBlacklist(mce::UUID const & p1, mcpe::string const & p2, mcpe::string const & p3, std::chrono::seconds const & p4) {
    (this->*_ServerNetworkHandler_addToBlacklist2)(p1, p2, p3, p4);
}
static void (ServerNetworkHandler::*_ServerNetworkHandler_removeFromBlacklist)(mce::UUID const &, mcpe::string const &);
void ServerNetworkHandler::removeFromBlacklist(mce::UUID const & p1, mcpe::string const & p2) {
    (this->*_ServerNetworkHandler_removeFromBlacklist)(p1, p2);
}
static void (ServerNetworkHandler::*_ServerNetworkHandler_disconnectClient)(NetworkIdentifier const &, std::string const &, bool);
void ServerNetworkHandler::disconnectClient(NetworkIdentifier const & p1, std::string const & p2, bool p3) {
    (this->*_ServerNetworkHandler_disconnectClient)(p1, p2, p3);
}
static NetworkPeer * (ServerNetworkHandler::*_ServerNetworkHandler_getPeerForUser)(NetworkIdentifier const &);
NetworkPeer * ServerNetworkHandler::getPeerForUser(NetworkIdentifier const & p1) {
    return (this->*_ServerNetworkHandler_getPeerForUser)(p1);
}
static void (ServerNetworkHandler::*_ServerNetworkHandler_handle)(NetworkIdentifier const &, ClientToServerHandshakePacket const &);
void ServerNetworkHandler::handle(NetworkIdentifier const & p1, ClientToServerHandshakePacket const & p2) {
    (this->*_ServerNetworkHandler_handle)(p1, p2);
}

#include "Packet.h"
XPointer Packet::myVtable;
XPointer Packet::vt_serverToClientHandshake;

#include "AppPlatform.h"
XPointer AppPlatform::myVtable;
AppPlatform * * AppPlatform::instance;
static void (AppPlatform::*_AppPlatform_AppPlatform)();
AppPlatform::AppPlatform() {
    (this->*_AppPlatform_AppPlatform)();
}
static void (AppPlatform::*_AppPlatform__fireAppFocusGained)();
void AppPlatform::_fireAppFocusGained() {
    (this->*_AppPlatform__fireAppFocusGained)();
}
static void (AppPlatform::*_AppPlatform_initialize)();
void AppPlatform::initialize() {
    (this->*_AppPlatform_initialize)();
}
static void (AppPlatform::*_AppPlatform_teardown)();
void AppPlatform::teardown() {
    (this->*_AppPlatform_teardown)();
}
static void (AppPlatform::*_AppPlatform_showKeyboard)(mcpe::string const &, int, bool, bool, bool, int, Vec2 const &);
void AppPlatform::showKeyboard(mcpe::string const & p1, int p2, bool p3, bool p4, bool p5, int p6, Vec2 const & p7) {
    (this->*_AppPlatform_showKeyboard)(p1, p2, p3, p4, p5, p6, p7);
}
static void (AppPlatform::*_AppPlatform_hideKeyboard)();
void AppPlatform::hideKeyboard() {
    (this->*_AppPlatform_hideKeyboard)();
}
static bool (AppPlatform::*_AppPlatform_isKeyboardVisible)();
bool AppPlatform::isKeyboardVisible() {
    return (this->*_AppPlatform_isKeyboardVisible)();
}

#include "CommandSelector.h"
static void (CommandSelectorBase::*_CommandSelectorBase_CommandSelectorBase)(bool);
CommandSelectorBase::CommandSelectorBase(bool p1) {
    (this->*_CommandSelectorBase_CommandSelectorBase)(p1);
}
static void (CommandSelectorBase::*_CommandSelectorBase_destructor)();
CommandSelectorBase::~CommandSelectorBase() {
    (this->*_CommandSelectorBase_destructor)();
}
static std::shared_ptr<std::vector<Actor *> > (CommandSelectorBase::*_CommandSelectorBase_newResults)(CommandOrigin const &) const;
std::shared_ptr<std::vector<Actor *> > CommandSelectorBase::newResults(CommandOrigin const & p1) const {
    return (this->*_CommandSelectorBase_newResults)(p1);
}
typeid_t<CommandRegistry> * CommandActorSelector::tid;
Parser CommandActorSelector::parser;
typeid_t<CommandRegistry> * CommandPlayerSelector::tid;
Parser CommandPlayerSelector::parser;

#include "Command.h"
static void (Command::*_Command_destructor)();
Command::~Command() {
    (this->*_Command_destructor)();
}
static void (Command::*_Command_Command)();
Command::Command() {
    (this->*_Command_Command)();
}

#include "Minecraft.h"
static MinecraftCommands * (Minecraft::*_Minecraft_getCommands)();
MinecraftCommands * Minecraft::getCommands() {
    return (this->*_Minecraft_getCommands)();
}
static Level * (Minecraft::*_Minecraft_getLevel)() const;
Level * Minecraft::getLevel() const {
    return (this->*_Minecraft_getLevel)();
}
static void (Minecraft::*_Minecraft_activateWhitelist)();
void Minecraft::activateWhitelist() {
    (this->*_Minecraft_activateWhitelist)();
}

#include "AutomationClient.h"
static void (Automation::AutomationClient::*_Automation_AutomationClient_AutomationClient)(IMinecraftApp &);
Automation::AutomationClient::AutomationClient(IMinecraftApp & p1) {
    (this->*_Automation_AutomationClient_AutomationClient)(p1);
}

#include "Api.h"

#include "FilePathManager.h"
static void (FilePathManager::*_FilePathManager_FilePathManager)(mcpe::string, bool);
FilePathManager::FilePathManager(mcpe::string p1, bool p2) {
    (this->*_FilePathManager_FilePathManager)(p1, p2);
}
static mcpe::string (FilePathManager::*_FilePathManager_getRootPath)() const;
mcpe::string FilePathManager::getRootPath() const {
    return (this->*_FilePathManager_getRootPath)();
}
static mcpe::string (FilePathManager::*_FilePathManager_getUserDataPath)() const;
mcpe::string FilePathManager::getUserDataPath() const {
    return (this->*_FilePathManager_getUserDataPath)();
}
static mcpe::string (FilePathManager::*_FilePathManager_getWorldsPath)() const;
mcpe::string FilePathManager::getWorldsPath() const {
    return (this->*_FilePathManager_getWorldsPath)();
}
static void (FilePathManager::*_FilePathManager_setPackagePath)(mcpe::string);
void FilePathManager::setPackagePath(mcpe::string p1) {
    (this->*_FilePathManager_setPackagePath)(p1);
}
static mcpe::string (FilePathManager::*_FilePathManager_getPackagePath)() const;
mcpe::string FilePathManager::getPackagePath() const {
    return (this->*_FilePathManager_getPackagePath)();
}
static void (FilePathManager::*_FilePathManager_setSettingsPath)(mcpe::string);
void FilePathManager::setSettingsPath(mcpe::string p1) {
    (this->*_FilePathManager_setSettingsPath)(p1);
}
static mcpe::string (FilePathManager::*_FilePathManager_getSettingsPath)() const;
mcpe::string FilePathManager::getSettingsPath() const {
    return (this->*_FilePathManager_getSettingsPath)();
}

#include "CommandUtils.h"
typeid_t<CommandRegistry> * CommonType<mcpe::string>::tid;
Parser CommonType<mcpe::string>::parser;
typeid_t<CommandRegistry> * CommonType<int>::tid;
Parser CommonType<int>::parser;
typeid_t<CommandRegistry> * CommonType<float>::tid;
Parser CommonType<float>::parser;
typeid_t<CommandRegistry> * CommonType<bool>::tid;
Parser CommonType<bool>::parser;
typeid_t<CommandRegistry> * CommonType<CommandRawText>::tid;
Parser CommonType<CommandRawText>::parser;
static std::tuple<float, float, float> (CommandPosition::*_CommandPosition_getPosition)(CommandOrigin const &) const;
std::tuple<float, float, float> CommandPosition::getPosition(CommandOrigin const & p1) const {
    return (this->*_CommandPosition_getPosition)(p1);
}
typeid_t<CommandRegistry> * CommonType<CommandPosition>::tid;
Parser CommonType<CommandPosition>::parser;
typeid_t<CommandRegistry> * CommonType<Block*>::tid;
Parser CommonType<Block*>::parser;
typeid_t<CommandRegistry> * CommonType<Json::Value>::tid;
Parser CommonType<Json::Value>::parser;

#include "BlockSource.h"
static Biome * (BlockSource::*_BlockSource_getBiome)(BlockPos const &);
Biome * BlockSource::getBiome(BlockPos const & p1) {
    return (this->*_BlockSource_getBiome)(p1);
}
static Block * (BlockSource::*_BlockSource_getBlock)(BlockPos const &) const;
Block * BlockSource::getBlock(BlockPos const & p1) const {
    return (this->*_BlockSource_getBlock)(p1);
}
static Block * (BlockSource::*_BlockSource_getExtraBlock)(BlockPos const &) const;
Block * BlockSource::getExtraBlock(BlockPos const & p1) const {
    return (this->*_BlockSource_getExtraBlock)(p1);
}
static void (BlockSource::*_BlockSource_setBlock)(int, int, int, Block const &, int);
void BlockSource::setBlock(int p1, int p2, int p3, Block const & p4, int p5) {
    (this->*_BlockSource_setBlock)(p1, p2, p3, p4, p5);
}

#include "LevelSettings.h"
static void (LevelSettings::*_LevelSettings_LevelSettings)();
LevelSettings::LevelSettings() {
    (this->*_LevelSettings_LevelSettings)();
}
static void (LevelSettings::*_LevelSettings_LevelSettings2)(LevelSettings const &);
LevelSettings::LevelSettings(LevelSettings const & p1) {
    (this->*_LevelSettings_LevelSettings2)(p1);
}
static void (LevelSettings::*_LevelSettings_destructor)();
LevelSettings::~LevelSettings() {
    (this->*_LevelSettings_destructor)();
}
static int (*_LevelSettings_parseSeedString)(mcpe::string const &, unsigned int);
int LevelSettings::parseSeedString(mcpe::string const & p1, unsigned int p2) {
    return _LevelSettings_parseSeedString(p1, p2);
}

#include "SaveTransactionManager.h"
static void (SaveTransactionManager::*_SaveTransactionManager_SaveTransactionManager)(std::function<void ( bool )>);
SaveTransactionManager::SaveTransactionManager(std::function<void ( bool )> p1) {
    (this->*_SaveTransactionManager_SaveTransactionManager)(p1);
}

#include "ImagePickingCallback.h"

#include "ItemInstance.h"
std::vector<std::unique_ptr<Enchant> > * Enchant::mEnchants;
static mcpe::string & (Enchant::*_Enchant_getDescriptionId)() const;
mcpe::string & Enchant::getDescriptionId() const {
    return (this->*_Enchant_getDescriptionId)();
}
static int vti_Enchant_getMaxLevel;
int Enchant::getMaxLevel() {
    union { void* voidp; int (Enchant::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_Enchant_getMaxLevel];
    return (this->*u.funcp)();
}
static std::vector<EnchantmentInstance> (ItemEnchants::*_ItemEnchants_getEnchants)(int) const;
std::vector<EnchantmentInstance> ItemEnchants::getEnchants(int p1) const {
    return (this->*_ItemEnchants_getEnchants)(p1);
}
static bool (ItemInstance::*_ItemInstance_isNull)() const;
bool ItemInstance::isNull() const {
    return (this->*_ItemInstance_isNull)();
}
static int (ItemInstance::*_ItemInstance_getId)() const;
int ItemInstance::getId() const {
    return (this->*_ItemInstance_getId)();
}
static mcpe::string (ItemInstance::*_ItemInstance_getName)() const;
mcpe::string ItemInstance::getName() const {
    return (this->*_ItemInstance_getName)();
}
static mcpe::string (ItemInstance::*_ItemInstance_getRawNameId)() const;
mcpe::string ItemInstance::getRawNameId() const {
    return (this->*_ItemInstance_getRawNameId)();
}
static mcpe::string (ItemInstance::*_ItemInstance_getCustomName)() const;
mcpe::string ItemInstance::getCustomName() const {
    return (this->*_ItemInstance_getCustomName)();
}
static ItemEnchants (ItemInstance::*_ItemInstance_getEnchantsFromUserData)() const;
ItemEnchants ItemInstance::getEnchantsFromUserData() const {
    return (this->*_ItemInstance_getEnchantsFromUserData)();
}

#include "ExtendedCertificate.h"
static mcpe::string (*_ExtendedCertificate_getXuid)(Certificate const &);
mcpe::string ExtendedCertificate::getXuid(Certificate const & p1) {
    return _ExtendedCertificate_getXuid(p1);
}

#include "Crypto.h"
static mce::UUID (*_Crypto_Random_generateUUID)();
mce::UUID Crypto::Random::generateUUID() {
    return _Crypto_Random_generateUUID();
}

#include "UUID.h"
mce::UUID * mce::UUID::EMPTY;
static mce::UUID (*_mce_UUID_fromString)(mcpe::string const &);
mce::UUID mce::UUID::fromString(mcpe::string const & p1) {
    return _mce_UUID_fromString(p1);
}
static mcpe::string (mce::UUID::*_mce_UUID_asString)() const;
mcpe::string mce::UUID::asString() const {
    return (this->*_mce_UUID_asString)();
}

#include "TransferPacket.h"
void * TransferPacket::myVtable;

#include "fix.h"

#include "ResourcePackStack.h"
static void (PackInstance::*_PackInstance_PackInstance)(ResourcePack *, int, bool, PackSettings *);
PackInstance::PackInstance(ResourcePack * p1, int p2, bool p3, PackSettings * p4) {
    (this->*_PackInstance_PackInstance)(p1, p2, p3, p4);
}
XPointer ResourcePackStack::vtable_sym;
static void (ResourcePackStack::*_ResourcePackStack_add)(PackInstance const &, ResourcePackRepository const &, bool);
void ResourcePackStack::add(PackInstance const & p1, ResourcePackRepository const & p2, bool p3) {
    (this->*_ResourcePackStack_add)(p1, p2, p3);
}

#include "UserManager.h"
static std::unique_ptr<Social::UserManager> (*_Social_UserManager_CreateUserManager)();
std::unique_ptr<Social::UserManager> Social::UserManager::CreateUserManager() {
    return _Social_UserManager_CreateUserManager();
}

#include "Scheduler.h"
static void (Scheduler::*_Scheduler_processCoroutines)(std::chrono::duration<long long>);
void Scheduler::processCoroutines(std::chrono::duration<long long> p1) {
    (this->*_Scheduler_processCoroutines)(p1);
}
static Scheduler * (*_MinecraftScheduler_client)();
Scheduler * MinecraftScheduler::client() {
    return _MinecraftScheduler_client();
}

#include "ExternalFileLevelStorageSource.h"
static void (ExternalFileLevelStorageSource::*_ExternalFileLevelStorageSource_ExternalFileLevelStorageSource)(FilePathManager *, std::shared_ptr<SaveTransactionManager>);
ExternalFileLevelStorageSource::ExternalFileLevelStorageSource(FilePathManager * p1, std::shared_ptr<SaveTransactionManager> p2) {
    (this->*_ExternalFileLevelStorageSource_ExternalFileLevelStorageSource)(p1, p2);
}
static std::unique_ptr<LevelStorage> (ExternalFileLevelStorageSource::*_ExternalFileLevelStorageSource_createLevelStorage)(Scheduler &, mcpe::string const &, ContentIdentity const &, IContentKeyProvider const &);
std::unique_ptr<LevelStorage> ExternalFileLevelStorageSource::createLevelStorage(Scheduler & p1, mcpe::string const & p2, ContentIdentity const & p3, IContentKeyProvider const & p4) {
    return (this->*_ExternalFileLevelStorageSource_createLevelStorage)(p1, p2, p3, p4);
}

#include "ResourcePack.h"
static void (SkinPackKeyProvider::*_SkinPackKeyProvider_SkinPackKeyProvider)();
SkinPackKeyProvider::SkinPackKeyProvider() {
    (this->*_SkinPackKeyProvider_SkinPackKeyProvider)();
}
static void (PackManifestFactory::*_PackManifestFactory_PackManifestFactory)(IPackTelemetry &);
PackManifestFactory::PackManifestFactory(IPackTelemetry & p1) {
    (this->*_PackManifestFactory_PackManifestFactory)(p1);
}
static void (PackSourceFactory::*_PackSourceFactory_PackSourceFactory)(Options *);
PackSourceFactory::PackSourceFactory(Options * p1) {
    (this->*_PackSourceFactory_PackSourceFactory)(p1);
}
static void (ResourcePackRepository::*_ResourcePackRepository_ResourcePackRepository)(IMinecraftEventing &, PackManifestFactory &, IContentAccessibilityProvider &, FilePathManager *, PackSourceFactory &, bool);
ResourcePackRepository::ResourcePackRepository(IMinecraftEventing & p1, PackManifestFactory & p2, IContentAccessibilityProvider & p3, FilePathManager * p4, PackSourceFactory & p5, bool p6) {
    (this->*_ResourcePackRepository_ResourcePackRepository)(p1, p2, p3, p4, p5, p6);
}
static void (ResourcePackRepository::*_ResourcePackRepository_addWorldResourcePacks)(mcpe::string const &);
void ResourcePackRepository::addWorldResourcePacks(mcpe::string const & p1) {
    (this->*_ResourcePackRepository_addWorldResourcePacks)(p1);
}
static void (ResourcePackRepository::*_ResourcePackRepository_refreshPacks)();
void ResourcePackRepository::refreshPacks() {
    (this->*_ResourcePackRepository_refreshPacks)();
}
static void (ContentTierManager::*_ContentTierManager_ContentTierManager)();
ContentTierManager::ContentTierManager() {
    (this->*_ContentTierManager_ContentTierManager)();
}
static void (ResourcePackManager::*_ResourcePackManager_ResourcePackManager)(std::function<mcpe::string ( )> const &, ContentTierManager const &);
ResourcePackManager::ResourcePackManager(std::function<mcpe::string ( )> const & p1, ContentTierManager const & p2) {
    (this->*_ResourcePackManager_ResourcePackManager)(p1, p2);
}
static void (ResourcePackManager::*_ResourcePackManager_setStack)(std::unique_ptr<ResourcePackStack>, ResourcePackStackType, bool);
void ResourcePackManager::setStack(std::unique_ptr<ResourcePackStack> p1, ResourcePackStackType p2, bool p3) {
    (this->*_ResourcePackManager_setStack)(std::move(p1), p2, p3);
}
static void (ResourcePackManager::*_ResourcePackManager_onLanguageChanged)();
void ResourcePackManager::onLanguageChanged() {
    (this->*_ResourcePackManager_onLanguageChanged)();
}

#include "V8.h"
static bool (*_v8_V8_Initialize)();
bool v8::V8::Initialize() {
    return _v8_V8_Initialize();
}
static void (*_v8_V8_InitializePlatform)(v8::Platform *);
void v8::V8::InitializePlatform(v8::Platform * p1) {
    _v8_V8_InitializePlatform(p1);
}
static void * (*_v8_V8_GlobalizeReference)(v8::Isolate *, void *);
void * v8::V8::GlobalizeReference(v8::Isolate * p1, void * p2) {
    return _v8_V8_GlobalizeReference(p1, p2);
}
static void (*_v8_V8_DisposeGlobal)(void *);
void v8::V8::DisposeGlobal(void * p1) {
    _v8_V8_DisposeGlobal(p1);
}
static void * (*_v8_V8_CreateHandle)(v8::Isolate *, void *);
void * v8::V8::CreateHandle(v8::Isolate * p1, void * p2) {
    return _v8_V8_CreateHandle(p1, p2);
}
static void * (*_v8_V8_MakeWeak)(void *, void *, v8::V8::VoidWeakCallback, v8::WeakCallbackType);
void * v8::V8::MakeWeak(void * p1, void * p2, v8::V8::VoidWeakCallback p3, v8::WeakCallbackType p4) {
    return _v8_V8_MakeWeak(p1, p2, p3, p4);
}
static bool (v8::Value::*_v8_Value_IsTrue)() const;
bool v8::Value::IsTrue() const {
    return (this->*_v8_Value_IsTrue)();
}
static bool (v8::Value::*_v8_Value_IsFalse)() const;
bool v8::Value::IsFalse() const {
    return (this->*_v8_Value_IsFalse)();
}
static bool (v8::Value::*_v8_Value_IsName)() const;
bool v8::Value::IsName() const {
    return (this->*_v8_Value_IsName)();
}
static bool (v8::Value::*_v8_Value_IsSymbol)() const;
bool v8::Value::IsSymbol() const {
    return (this->*_v8_Value_IsSymbol)();
}
static bool (v8::Value::*_v8_Value_IsFunction)() const;
bool v8::Value::IsFunction() const {
    return (this->*_v8_Value_IsFunction)();
}
static bool (v8::Value::*_v8_Value_IsArray)() const;
bool v8::Value::IsArray() const {
    return (this->*_v8_Value_IsArray)();
}
static bool (v8::Value::*_v8_Value_IsObject)() const;
bool v8::Value::IsObject() const {
    return (this->*_v8_Value_IsObject)();
}
static bool (v8::Value::*_v8_Value_IsBoolean)() const;
bool v8::Value::IsBoolean() const {
    return (this->*_v8_Value_IsBoolean)();
}
static bool (v8::Value::*_v8_Value_IsNumber)() const;
bool v8::Value::IsNumber() const {
    return (this->*_v8_Value_IsNumber)();
}
static bool (v8::Value::*_v8_Value_IsExternal)() const;
bool v8::Value::IsExternal() const {
    return (this->*_v8_Value_IsExternal)();
}
static bool (v8::Value::*_v8_Value_IsInt32)() const;
bool v8::Value::IsInt32() const {
    return (this->*_v8_Value_IsInt32)();
}
static bool (v8::Value::*_v8_Value_IsUint32)() const;
bool v8::Value::IsUint32() const {
    return (this->*_v8_Value_IsUint32)();
}
static bool (v8::Value::*_v8_Value_IsDate)() const;
bool v8::Value::IsDate() const {
    return (this->*_v8_Value_IsDate)();
}
static bool (v8::Value::*_v8_Value_IsArgumentsObject)() const;
bool v8::Value::IsArgumentsObject() const {
    return (this->*_v8_Value_IsArgumentsObject)();
}
static bool (v8::Value::*_v8_Value_IsBooleanObject)() const;
bool v8::Value::IsBooleanObject() const {
    return (this->*_v8_Value_IsBooleanObject)();
}
static bool (v8::Value::*_v8_Value_IsNumberObject)() const;
bool v8::Value::IsNumberObject() const {
    return (this->*_v8_Value_IsNumberObject)();
}
static bool (v8::Value::*_v8_Value_IsStringObject)() const;
bool v8::Value::IsStringObject() const {
    return (this->*_v8_Value_IsStringObject)();
}
static bool (v8::Value::*_v8_Value_IsSymbolObject)() const;
bool v8::Value::IsSymbolObject() const {
    return (this->*_v8_Value_IsSymbolObject)();
}
static bool (v8::Value::*_v8_Value_IsNativeError)() const;
bool v8::Value::IsNativeError() const {
    return (this->*_v8_Value_IsNativeError)();
}
static bool (v8::Value::*_v8_Value_IsRegExp)() const;
bool v8::Value::IsRegExp() const {
    return (this->*_v8_Value_IsRegExp)();
}
static bool (v8::Value::*_v8_Value_IsAsyncFunction)() const;
bool v8::Value::IsAsyncFunction() const {
    return (this->*_v8_Value_IsAsyncFunction)();
}
static bool (v8::Value::*_v8_Value_IsGeneratorFunction)() const;
bool v8::Value::IsGeneratorFunction() const {
    return (this->*_v8_Value_IsGeneratorFunction)();
}
static bool (v8::Value::*_v8_Value_IsGeneratorObject)() const;
bool v8::Value::IsGeneratorObject() const {
    return (this->*_v8_Value_IsGeneratorObject)();
}
static bool (v8::Value::*_v8_Value_IsPromise)() const;
bool v8::Value::IsPromise() const {
    return (this->*_v8_Value_IsPromise)();
}
static bool (v8::Value::*_v8_Value_IsMap)() const;
bool v8::Value::IsMap() const {
    return (this->*_v8_Value_IsMap)();
}
static bool (v8::Value::*_v8_Value_IsSet)() const;
bool v8::Value::IsSet() const {
    return (this->*_v8_Value_IsSet)();
}
static bool (v8::Value::*_v8_Value_IsMapIterator)() const;
bool v8::Value::IsMapIterator() const {
    return (this->*_v8_Value_IsMapIterator)();
}
static bool (v8::Value::*_v8_Value_IsSetIterator)() const;
bool v8::Value::IsSetIterator() const {
    return (this->*_v8_Value_IsSetIterator)();
}
static bool (v8::Value::*_v8_Value_IsWeakMap)() const;
bool v8::Value::IsWeakMap() const {
    return (this->*_v8_Value_IsWeakMap)();
}
static bool (v8::Value::*_v8_Value_IsWeakSet)() const;
bool v8::Value::IsWeakSet() const {
    return (this->*_v8_Value_IsWeakSet)();
}
static bool (v8::Value::*_v8_Value_IsArrayBuffer)() const;
bool v8::Value::IsArrayBuffer() const {
    return (this->*_v8_Value_IsArrayBuffer)();
}
static bool (v8::Value::*_v8_Value_IsArrayBufferView)() const;
bool v8::Value::IsArrayBufferView() const {
    return (this->*_v8_Value_IsArrayBufferView)();
}
static bool (v8::Value::*_v8_Value_IsTypedArray)() const;
bool v8::Value::IsTypedArray() const {
    return (this->*_v8_Value_IsTypedArray)();
}
static bool (v8::Value::*_v8_Value_IsUint8Array)() const;
bool v8::Value::IsUint8Array() const {
    return (this->*_v8_Value_IsUint8Array)();
}
static bool (v8::Value::*_v8_Value_IsUint8ClampedArray)() const;
bool v8::Value::IsUint8ClampedArray() const {
    return (this->*_v8_Value_IsUint8ClampedArray)();
}
static bool (v8::Value::*_v8_Value_IsInt8Array)() const;
bool v8::Value::IsInt8Array() const {
    return (this->*_v8_Value_IsInt8Array)();
}
static bool (v8::Value::*_v8_Value_IsUint16Array)() const;
bool v8::Value::IsUint16Array() const {
    return (this->*_v8_Value_IsUint16Array)();
}
static bool (v8::Value::*_v8_Value_IsInt16Array)() const;
bool v8::Value::IsInt16Array() const {
    return (this->*_v8_Value_IsInt16Array)();
}
static bool (v8::Value::*_v8_Value_IsUint32Array)() const;
bool v8::Value::IsUint32Array() const {
    return (this->*_v8_Value_IsUint32Array)();
}
static bool (v8::Value::*_v8_Value_IsInt32Array)() const;
bool v8::Value::IsInt32Array() const {
    return (this->*_v8_Value_IsInt32Array)();
}
static bool (v8::Value::*_v8_Value_IsFloat32Array)() const;
bool v8::Value::IsFloat32Array() const {
    return (this->*_v8_Value_IsFloat32Array)();
}
static bool (v8::Value::*_v8_Value_IsFloat64Array)() const;
bool v8::Value::IsFloat64Array() const {
    return (this->*_v8_Value_IsFloat64Array)();
}
static bool (v8::Value::*_v8_Value_IsDataView)() const;
bool v8::Value::IsDataView() const {
    return (this->*_v8_Value_IsDataView)();
}
static bool (v8::Value::*_v8_Value_IsSharedArrayBuffer)() const;
bool v8::Value::IsSharedArrayBuffer() const {
    return (this->*_v8_Value_IsSharedArrayBuffer)();
}
static bool (v8::Value::*_v8_Value_IsProxy)() const;
bool v8::Value::IsProxy() const {
    return (this->*_v8_Value_IsProxy)();
}
static bool (v8::Value::*_v8_Value_IsWebAssemblyCompiledModule)() const;
bool v8::Value::IsWebAssemblyCompiledModule() const {
    return (this->*_v8_Value_IsWebAssemblyCompiledModule)();
}
static v8::Local<v8::Boolean> (v8::Value::*_v8_Value_ToBoolean)(v8::Isolate *) const;
v8::Local<v8::Boolean> v8::Value::ToBoolean(v8::Isolate * p1) const {
    return (this->*_v8_Value_ToBoolean)(p1);
}
static v8::Local<v8::Number> (v8::Value::*_v8_Value_ToNumber)(v8::Isolate *) const;
v8::Local<v8::Number> v8::Value::ToNumber(v8::Isolate * p1) const {
    return (this->*_v8_Value_ToNumber)(p1);
}
static v8::Local<v8::String> (v8::Value::*_v8_Value_ToString)(v8::Isolate *) const;
v8::Local<v8::String> v8::Value::ToString(v8::Isolate * p1) const {
    return (this->*_v8_Value_ToString)(p1);
}
static v8::Local<v8::Object> (v8::Value::*_v8_Value_ToObject)(v8::Isolate *) const;
v8::Local<v8::Object> v8::Value::ToObject(v8::Isolate * p1) const {
    return (this->*_v8_Value_ToObject)(p1);
}
static v8::Local<v8::Integer> (v8::Value::*_v8_Value_ToInteger)(v8::Isolate *) const;
v8::Local<v8::Integer> v8::Value::ToInteger(v8::Isolate * p1) const {
    return (this->*_v8_Value_ToInteger)(p1);
}
static v8::Local<v8::Int32> (v8::Value::*_v8_Value_ToInt32)(v8::Isolate *) const;
v8::Local<v8::Int32> v8::Value::ToInt32(v8::Isolate * p1) const {
    return (this->*_v8_Value_ToInt32)(p1);
}
static bool (v8::Value::*_v8_Value_BooleanValue)() const;
bool v8::Value::BooleanValue() const {
    return (this->*_v8_Value_BooleanValue)();
}
static v8::MaybeLocal<v8::Uint32> (v8::Value::*_v8_Value_ToArrayIndex)() const;
v8::MaybeLocal<v8::Uint32> v8::Value::ToArrayIndex() const {
    return (this->*_v8_Value_ToArrayIndex)();
}
static v8::Maybe<bool> (v8::Value::*_v8_Value_Equals)(v8::Local<v8::Context>, v8::Local<v8::Value>) const;
v8::Maybe<bool> v8::Value::Equals(v8::Local<v8::Context> p1, v8::Local<v8::Value> p2) const {
    return (this->*_v8_Value_Equals)(p1, p2);
}
static v8::Maybe<bool> (v8::Value::*_v8_Value_Equals2)(v8::Local<v8::Value>) const;
v8::Maybe<bool> v8::Value::Equals(v8::Local<v8::Value> p1) const {
    return (this->*_v8_Value_Equals2)(p1);
}
static bool (v8::Value::*_v8_Value_StrictEquals)(v8::Local<v8::Value>) const;
bool v8::Value::StrictEquals(v8::Local<v8::Value> p1) const {
    return (this->*_v8_Value_StrictEquals)(p1);
}
static bool (v8::Value::*_v8_Value_SameValue)(v8::Local<v8::Value>) const;
bool v8::Value::SameValue(v8::Local<v8::Value> p1) const {
    return (this->*_v8_Value_SameValue)(p1);
}
static v8::Local<v8::String> (v8::Value::*_v8_Value_TypeOf)(v8::Isolate *);
v8::Local<v8::String> v8::Value::TypeOf(v8::Isolate * p1) {
    return (this->*_v8_Value_TypeOf)(p1);
}
static bool (v8::Value::*_v8_Value_FullIsNull)() const;
bool v8::Value::FullIsNull() const {
    return (this->*_v8_Value_FullIsNull)();
}
static bool (v8::Value::*_v8_Value_FullIsUndefined)() const;
bool v8::Value::FullIsUndefined() const {
    return (this->*_v8_Value_FullIsUndefined)();
}
static bool (v8::Value::*_v8_Value_FullIsString)() const;
bool v8::Value::FullIsString() const {
    return (this->*_v8_Value_FullIsString)();
}
static void (*_v8_Name_CheckCast)(v8::Value *);
void v8::Name::CheckCast(v8::Value * p1) {
    _v8_Name_CheckCast(p1);
}
static int (v8::String::*_v8_String_Length)() const;
int v8::String::Length() const {
    return (this->*_v8_String_Length)();
}
static int (v8::String::*_v8_String_Utf8Length)() const;
int v8::String::Utf8Length() const {
    return (this->*_v8_String_Utf8Length)();
}
static bool (v8::String::*_v8_String_IsOneByte)() const;
bool v8::String::IsOneByte() const {
    return (this->*_v8_String_IsOneByte)();
}
static bool (v8::String::*_v8_String_ContainsOnlyOneByte)() const;
bool v8::String::ContainsOnlyOneByte() const {
    return (this->*_v8_String_ContainsOnlyOneByte)();
}
static bool (v8::String::*_v8_String_IsExternal)() const;
bool v8::String::IsExternal() const {
    return (this->*_v8_String_IsExternal)();
}
static bool (v8::String::*_v8_String_IsExternalOneByte)() const;
bool v8::String::IsExternalOneByte() const {
    return (this->*_v8_String_IsExternalOneByte)();
}
static v8::Local<v8::String> (*_v8_String_NewFromUtf8)(v8::Isolate *, char const *, v8::NewStringType, int);
v8::Local<v8::String> v8::String::NewFromUtf8(v8::Isolate * p1, char const * p2, v8::NewStringType p3, int p4) {
    return _v8_String_NewFromUtf8(p1, p2, p3, p4);
}
static v8::Local<v8::String> (*_v8_String_NewFromTwoByte)(v8::Isolate *, char16_t const *, v8::NewStringType, int);
v8::Local<v8::String> v8::String::NewFromTwoByte(v8::Isolate * p1, char16_t const * p2, v8::NewStringType p3, int p4) {
    return _v8_String_NewFromTwoByte(p1, p2, p3, p4);
}
static int (v8::String::*_v8_String_Write)(unsigned short *, int, int, int) const;
int v8::String::Write(unsigned short * p1, int p2, int p3, int p4) const {
    return (this->*_v8_String_Write)(p1, p2, p3, p4);
}
static void (*_v8_String_CheckCast)(v8::Value *);
void v8::String::CheckCast(v8::Value * p1) {
    _v8_String_CheckCast(p1);
}
static void (v8::String::Utf8Value::*_v8_String_Utf8Value_Utf8Value)(v8::Isolate *, v8::Local<v8::Value>);
v8::String::Utf8Value::Utf8Value(v8::Isolate * p1, v8::Local<v8::Value> p2) {
    (this->*_v8_String_Utf8Value_Utf8Value)(p1, p2);
}
static void (v8::String::Utf8Value::*_v8_String_Utf8Value_destructor)();
v8::String::Utf8Value::~Utf8Value() {
    (this->*_v8_String_Utf8Value_destructor)();
}
static v8::Local<v8::Number> (*_v8_Number_New)(v8::Isolate *, double);
v8::Local<v8::Number> v8::Number::New(v8::Isolate * p1, double p2) {
    return _v8_Number_New(p1, p2);
}
static double (v8::Number::*_v8_Number_Value)() const;
double v8::Number::Value() const {
    return (this->*_v8_Number_Value)();
}
static void (*_v8_Number_CheckCast)(v8::Value *);
void v8::Number::CheckCast(v8::Value * p1) {
    _v8_Number_CheckCast(p1);
}
static v8::Local<v8::Integer> (*_v8_Integer_New)(v8::Isolate *, int32_t);
v8::Local<v8::Integer> v8::Integer::New(v8::Isolate * p1, int32_t p2) {
    return _v8_Integer_New(p1, p2);
}
static v8::Local<v8::Integer> (*_v8_Integer_NewFromUnsigned)(v8::Isolate *, uint32_t);
v8::Local<v8::Integer> v8::Integer::NewFromUnsigned(v8::Isolate * p1, uint32_t p2) {
    return _v8_Integer_NewFromUnsigned(p1, p2);
}
static int64_t (v8::Integer::*_v8_Integer_Value)() const;
int64_t v8::Integer::Value() const {
    return (this->*_v8_Integer_Value)();
}
static void (*_v8_Integer_CheckCast)(v8::Value *);
void v8::Integer::CheckCast(v8::Value * p1) {
    _v8_Integer_CheckCast(p1);
}
static bool (v8::Boolean::*_v8_Boolean_Value)() const;
bool v8::Boolean::Value() const {
    return (this->*_v8_Boolean_Value)();
}
static void (*_v8_Boolean_CheckCast)(v8::Value *);
void v8::Boolean::CheckCast(v8::Value * p1) {
    _v8_Boolean_CheckCast(p1);
}
static void (v8::TryCatch::*_v8_TryCatch_TryCatch)(v8::Isolate *);
v8::TryCatch::TryCatch(v8::Isolate * p1) {
    (this->*_v8_TryCatch_TryCatch)(p1);
}
static void (v8::TryCatch::*_v8_TryCatch_destructor)();
v8::TryCatch::~TryCatch() {
    (this->*_v8_TryCatch_destructor)();
}
static bool (v8::TryCatch::*_v8_TryCatch_HasCaught)() const;
bool v8::TryCatch::HasCaught() const {
    return (this->*_v8_TryCatch_HasCaught)();
}
static bool (v8::TryCatch::*_v8_TryCatch_CanContinue)() const;
bool v8::TryCatch::CanContinue() const {
    return (this->*_v8_TryCatch_CanContinue)();
}
static bool (v8::TryCatch::*_v8_TryCatch_HasTerminated)() const;
bool v8::TryCatch::HasTerminated() const {
    return (this->*_v8_TryCatch_HasTerminated)();
}
static v8::Local<v8::Value> (v8::TryCatch::*_v8_TryCatch_ReThrow)();
v8::Local<v8::Value> v8::TryCatch::ReThrow() {
    return (this->*_v8_TryCatch_ReThrow)();
}
static v8::Local<v8::Value> (v8::TryCatch::*_v8_TryCatch_Exception)() const;
v8::Local<v8::Value> v8::TryCatch::Exception() const {
    return (this->*_v8_TryCatch_Exception)();
}
static v8::MaybeLocal<v8::Value> (v8::TryCatch::*_v8_TryCatch_StackTrace)(v8::Local<v8::Context>) const;
v8::MaybeLocal<v8::Value> v8::TryCatch::StackTrace(v8::Local<v8::Context> p1) const {
    return (this->*_v8_TryCatch_StackTrace)(p1);
}
static v8::Local<v8::Message> (v8::TryCatch::*_v8_TryCatch_Message)() const;
v8::Local<v8::Message> v8::TryCatch::Message() const {
    return (this->*_v8_TryCatch_Message)();
}
static void (v8::TryCatch::*_v8_TryCatch_Reset)();
void v8::TryCatch::Reset() {
    (this->*_v8_TryCatch_Reset)();
}
static void (v8::TryCatch::*_v8_TryCatch_SetVerbose)(bool);
void v8::TryCatch::SetVerbose(bool p1) {
    (this->*_v8_TryCatch_SetVerbose)(p1);
}
static void (v8::TryCatch::*_v8_TryCatch_SetCaptureMessage)(bool);
void v8::TryCatch::SetCaptureMessage(bool p1) {
    (this->*_v8_TryCatch_SetCaptureMessage)(p1);
}
static v8::Local<v8::String> (v8::Message::*_v8_Message_Get)() const;
v8::Local<v8::String> v8::Message::Get() const {
    return (this->*_v8_Message_Get)();
}
static v8::Local<v8::Value> (v8::Isolate::*_v8_Isolate_ThrowException)(v8::Local<v8::Value>);
v8::Local<v8::Value> v8::Isolate::ThrowException(v8::Local<v8::Value> p1) {
    return (this->*_v8_Isolate_ThrowException)(p1);
}
static v8::Isolate * (*_v8_Isolate_GetCurrent)();
v8::Isolate * v8::Isolate::GetCurrent() {
    return _v8_Isolate_GetCurrent();
}
static v8::Local<v8::Context> (v8::Isolate::*_v8_Isolate_GetCurrentContext)();
v8::Local<v8::Context> v8::Isolate::GetCurrentContext() {
    return (this->*_v8_Isolate_GetCurrentContext)();
}
static bool (v8::Isolate::*_v8_Isolate_InContext)();
bool v8::Isolate::InContext() {
    return (this->*_v8_Isolate_InContext)();
}
static void (v8::Isolate::*_v8_Isolate_Enter)();
void v8::Isolate::Enter() {
    (this->*_v8_Isolate_Enter)();
}
static void (v8::Isolate::*_v8_Isolate_Exit)();
void v8::Isolate::Exit() {
    (this->*_v8_Isolate_Exit)();
}
static void (v8::Isolate::*_v8_Isolate_RequestGarbageCollectionForTesting)(v8::Isolate::GarbageCollectionType);
void v8::Isolate::RequestGarbageCollectionForTesting(v8::Isolate::GarbageCollectionType p1) {
    (this->*_v8_Isolate_RequestGarbageCollectionForTesting)(p1);
}
static void (v8::Isolate::*_v8_Isolate_RunMicrotasks)();
void v8::Isolate::RunMicrotasks() {
    (this->*_v8_Isolate_RunMicrotasks)();
}
static void (v8::Context::*_v8_Context_Enter)();
void v8::Context::Enter() {
    (this->*_v8_Context_Enter)();
}
static void (v8::Context::*_v8_Context_Exit)();
void v8::Context::Exit() {
    (this->*_v8_Context_Exit)();
}
static v8::Local<v8::Context> (*_v8_Context_New)(v8::Isolate *, v8::ExtensionConfiguration *, v8::MaybeLocal<v8::ObjectTemplate>, v8::MaybeLocal<v8::Value>);
v8::Local<v8::Context> v8::Context::New(v8::Isolate * p1, v8::ExtensionConfiguration * p2, v8::MaybeLocal<v8::ObjectTemplate> p3, v8::MaybeLocal<v8::Value> p4) {
    return _v8_Context_New(p1, p2, p3, p4);
}
static v8::Local<v8::Object> (*_v8_Context_Global)();
v8::Local<v8::Object> v8::Context::Global() {
    return _v8_Context_Global();
}
static void (v8::HandleScope::*_v8_HandleScope_HandleScope)(v8::Isolate *);
v8::HandleScope::HandleScope(v8::Isolate * p1) {
    (this->*_v8_HandleScope_HandleScope)(p1);
}
static void (v8::HandleScope::*_v8_HandleScope_destructor)();
v8::HandleScope::~HandleScope() {
    (this->*_v8_HandleScope_destructor)();
}
static void (v8::EscapableHandleScope::*_v8_EscapableHandleScope_EscapableHandleScope)(v8::Isolate *);
v8::EscapableHandleScope::EscapableHandleScope(v8::Isolate * p1) {
    (this->*_v8_EscapableHandleScope_EscapableHandleScope)(p1);
}
static v8::Local<v8::Object> (*_v8_Object_New)(v8::Isolate *);
v8::Local<v8::Object> v8::Object::New(v8::Isolate * p1) {
    return _v8_Object_New(p1);
}
static bool (v8::Object::*_v8_Object_Set)(unsigned, v8::Local<v8::Value>);
bool v8::Object::Set(unsigned p1, v8::Local<v8::Value> p2) {
    return (this->*_v8_Object_Set)(p1, p2);
}
static bool (v8::Object::*_v8_Object_Set2)(v8::Local<v8::Value>, v8::Local<v8::Value>);
bool v8::Object::Set(v8::Local<v8::Value> p1, v8::Local<v8::Value> p2) {
    return (this->*_v8_Object_Set2)(p1, p2);
}
static v8::Local<v8::Value> (v8::Object::*_v8_Object_Get)(unsigned);
v8::Local<v8::Value> v8::Object::Get(unsigned p1) {
    return (this->*_v8_Object_Get)(p1);
}
static v8::Local<v8::Value> (v8::Object::*_v8_Object_Get2)(v8::Local<v8::Value>);
v8::Local<v8::Value> v8::Object::Get(v8::Local<v8::Value> p1) {
    return (this->*_v8_Object_Get2)(p1);
}
static bool (v8::Object::*_v8_Object_Has)(v8::Local<v8::Value>);
bool v8::Object::Has(v8::Local<v8::Value> p1) {
    return (this->*_v8_Object_Has)(p1);
}
static void (v8::Object::*_v8_Object_SetInternalField)(int, v8::Local<v8::Value>);
void v8::Object::SetInternalField(int p1, v8::Local<v8::Value> p2) {
    (this->*_v8_Object_SetInternalField)(p1, p2);
}
static void (v8::Object::*_v8_Object_SetAlignedPointerInInternalField)(int, void *);
void v8::Object::SetAlignedPointerInInternalField(int p1, void * p2) {
    (this->*_v8_Object_SetAlignedPointerInInternalField)(p1, p2);
}
static v8::Local<v8::Value> (v8::Object::*_v8_Object_GetInternalField)(int);
v8::Local<v8::Value> v8::Object::GetInternalField(int p1) {
    return (this->*_v8_Object_GetInternalField)(p1);
}
static void * (v8::Object::*_v8_Object_GetAlignedPointerFromInternalField)(int);
void * v8::Object::GetAlignedPointerFromInternalField(int p1) {
    return (this->*_v8_Object_GetAlignedPointerFromInternalField)(p1);
}
static v8::Local<v8::Array> (v8::Object::*_v8_Object_GetOwnPropertyNames)(v8::Local<v8::Context>);
v8::Local<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context> p1) {
    return (this->*_v8_Object_GetOwnPropertyNames)(p1);
}
static v8::Local<v8::Array> (v8::Object::*_v8_Object_GetOwnPropertyNames2)(v8::Local<v8::Context>, v8::PropertyFilter);
v8::Local<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context> p1, v8::PropertyFilter p2) {
    return (this->*_v8_Object_GetOwnPropertyNames2)(p1, p2);
}
static void (*_v8_Object_CheckCast)(v8::Value *);
void v8::Object::CheckCast(v8::Value * p1) {
    _v8_Object_CheckCast(p1);
}
static v8::Local<v8::Array> (*_v8_Array_New)(v8::Isolate *, int);
v8::Local<v8::Array> v8::Array::New(v8::Isolate * p1, int p2) {
    return _v8_Array_New(p1, p2);
}
static unsigned (v8::Array::*_v8_Array_Length)() const;
unsigned v8::Array::Length() const {
    return (this->*_v8_Array_Length)();
}
static void (*_v8_Array_CheckCast)(v8::Value *);
void v8::Array::CheckCast(v8::Value * p1) {
    _v8_Array_CheckCast(p1);
}
static v8::ArrayBuffer::Contents (v8::ArrayBuffer::*_v8_ArrayBuffer_GetContents)();
v8::ArrayBuffer::Contents v8::ArrayBuffer::GetContents() {
    return (this->*_v8_ArrayBuffer_GetContents)();
}
static v8::Local<v8::ArrayBuffer> (*_v8_ArrayBuffer_New)(v8::Isolate *, size_t);
v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate * p1, size_t p2) {
    return _v8_ArrayBuffer_New(p1, p2);
}
static void (*_v8_ArrayBuffer_CheckCast)(v8::Value *);
void v8::ArrayBuffer::CheckCast(v8::Value * p1) {
    _v8_ArrayBuffer_CheckCast(p1);
}
static v8::MaybeLocal<v8::Value> (v8::Function::*_v8_Function_Call)(v8::Local<v8::Value>, int, v8::Local<v8::Value> *);
v8::MaybeLocal<v8::Value> v8::Function::Call(v8::Local<v8::Value> p1, int p2, v8::Local<v8::Value> * p3) {
    return (this->*_v8_Function_Call)(p1, p2, p3);
}
static v8::Local<v8::Object> (v8::Function::*_v8_Function_NewInstance)(v8::Local<v8::Context>, int, v8::Local<v8::Value> *);
v8::Local<v8::Object> v8::Function::NewInstance(v8::Local<v8::Context> p1, int p2, v8::Local<v8::Value> * p3) {
    return (this->*_v8_Function_NewInstance)(p1, p2, p3);
}
static v8::Local<v8::Function> (*_v8_Function_New)(v8::Isolate *, v8::FunctionCallback, v8::Local<v8::Value>, int);
v8::Local<v8::Function> v8::Function::New(v8::Isolate * p1, v8::FunctionCallback p2, v8::Local<v8::Value> p3, int p4) {
    return _v8_Function_New(p1, p2, p3, p4);
}
static void (*_v8_Function_CheckCast)(v8::Value *);
void v8::Function::CheckCast(v8::Value * p1) {
    _v8_Function_CheckCast(p1);
}
static void (v8::Template::*_v8_Template_Set)(v8::Local<v8::Name>, v8::Local<v8::Data>, v8::PropertyAttribute);
void v8::Template::Set(v8::Local<v8::Name> p1, v8::Local<v8::Data> p2, v8::PropertyAttribute p3) {
    (this->*_v8_Template_Set)(p1, p2, p3);
}
static void (v8::Template::*_v8_Template_SetAccessorProperty)(v8::Local<v8::Name>, v8::Local<v8::FunctionTemplate>, v8::Local<v8::FunctionTemplate>, v8::PropertyAttribute, v8::AccessControl);
void v8::Template::SetAccessorProperty(v8::Local<v8::Name> p1, v8::Local<v8::FunctionTemplate> p2, v8::Local<v8::FunctionTemplate> p3, v8::PropertyAttribute p4, v8::AccessControl p5) {
    (this->*_v8_Template_SetAccessorProperty)(p1, p2, p3, p4, p5);
}
static v8::Local<v8::FunctionTemplate> (*_v8_FunctionTemplate_New)(v8::Isolate *, v8::FunctionCallback, v8::Local<v8::Value>, v8::Local<v8::Signature>, int);
v8::Local<v8::FunctionTemplate> v8::FunctionTemplate::New(v8::Isolate * p1, v8::FunctionCallback p2, v8::Local<v8::Value> p3, v8::Local<v8::Signature> p4, int p5) {
    return _v8_FunctionTemplate_New(p1, p2, p3, p4, p5);
}
static void (v8::FunctionTemplate::*_v8_FunctionTemplate_Inherit)(v8::Local<v8::FunctionTemplate>);
void v8::FunctionTemplate::Inherit(v8::Local<v8::FunctionTemplate> p1) {
    (this->*_v8_FunctionTemplate_Inherit)(p1);
}
static void (v8::FunctionTemplate::*_v8_FunctionTemplate_SetClassName)(v8::Local<v8::String>);
void v8::FunctionTemplate::SetClassName(v8::Local<v8::String> p1) {
    (this->*_v8_FunctionTemplate_SetClassName)(p1);
}
static v8::Local<v8::ObjectTemplate> (v8::FunctionTemplate::*_v8_FunctionTemplate_PrototypeTemplate)();
v8::Local<v8::ObjectTemplate> v8::FunctionTemplate::PrototypeTemplate() {
    return (this->*_v8_FunctionTemplate_PrototypeTemplate)();
}
static v8::Local<v8::ObjectTemplate> (v8::FunctionTemplate::*_v8_FunctionTemplate_InstanceTemplate)();
v8::Local<v8::ObjectTemplate> v8::FunctionTemplate::InstanceTemplate() {
    return (this->*_v8_FunctionTemplate_InstanceTemplate)();
}
static v8::Local<v8::Object> (v8::FunctionTemplate::*_v8_FunctionTemplate_GetFunction)(v8::Local<v8::Context>);
v8::Local<v8::Object> v8::FunctionTemplate::GetFunction(v8::Local<v8::Context> p1) {
    return (this->*_v8_FunctionTemplate_GetFunction)(p1);
}
static bool (v8::FunctionTemplate::*_v8_FunctionTemplate_HasInstance)(v8::Local<v8::Value>);
bool v8::FunctionTemplate::HasInstance(v8::Local<v8::Value> p1) {
    return (this->*_v8_FunctionTemplate_HasInstance)(p1);
}
static v8::Local<v8::Object> (v8::ObjectTemplate::*_v8_ObjectTemplate_NewInstance)(v8::Local<v8::Context>);
v8::Local<v8::Object> v8::ObjectTemplate::NewInstance(v8::Local<v8::Context> p1) {
    return (this->*_v8_ObjectTemplate_NewInstance)(p1);
}
static void (v8::ObjectTemplate::*_v8_ObjectTemplate_SetImmutableProto)();
void v8::ObjectTemplate::SetImmutableProto() {
    (this->*_v8_ObjectTemplate_SetImmutableProto)();
}
static void (v8::ObjectTemplate::*_v8_ObjectTemplate_SetInternalFieldCount)(int);
void v8::ObjectTemplate::SetInternalFieldCount(int p1) {
    (this->*_v8_ObjectTemplate_SetInternalFieldCount)(p1);
}
static v8::Local<v8::ObjectTemplate> (*_v8_ObjectTemplate_New)(v8::Isolate *, v8::Local<v8::FunctionTemplate>);
v8::Local<v8::ObjectTemplate> v8::ObjectTemplate::New(v8::Isolate * p1, v8::Local<v8::FunctionTemplate> p2) {
    return _v8_ObjectTemplate_New(p1, p2);
}
static v8::Local<v8::Value> (*_v8_Exception_RangeError)(v8::Local<v8::String>);
v8::Local<v8::Value> v8::Exception::RangeError(v8::Local<v8::String> p1) {
    return _v8_Exception_RangeError(p1);
}
static v8::Local<v8::Value> (*_v8_Exception_ReferenceError)(v8::Local<v8::String>);
v8::Local<v8::Value> v8::Exception::ReferenceError(v8::Local<v8::String> p1) {
    return _v8_Exception_ReferenceError(p1);
}
static v8::Local<v8::Value> (*_v8_Exception_SyntaxError)(v8::Local<v8::String>);
v8::Local<v8::Value> v8::Exception::SyntaxError(v8::Local<v8::String> p1) {
    return _v8_Exception_SyntaxError(p1);
}
static v8::Local<v8::Value> (*_v8_Exception_TypeError)(v8::Local<v8::String>);
v8::Local<v8::Value> v8::Exception::TypeError(v8::Local<v8::String> p1) {
    return _v8_Exception_TypeError(p1);
}
static v8::Local<v8::Value> (*_v8_Exception_Error)(v8::Local<v8::String>);
v8::Local<v8::Value> v8::Exception::Error(v8::Local<v8::String> p1) {
    return _v8_Exception_Error(p1);
}
static v8::Local<v8::Message> (*_v8_Exception_CreateMessage)(v8::Local<v8::Value>);
v8::Local<v8::Message> v8::Exception::CreateMessage(v8::Local<v8::Value> p1) {
    return _v8_Exception_CreateMessage(p1);
}
static v8::Local<v8::Promise::Resolver> (*_v8_Promise_Resolver_New)(v8::Local<v8::Context>);
v8::Local<v8::Promise::Resolver> v8::Promise::Resolver::New(v8::Local<v8::Context> p1) {
    return _v8_Promise_Resolver_New(p1);
}
static v8::Maybe<bool> (v8::Promise::Resolver::*_v8_Promise_Resolver_Resolve)(v8::Local<v8::Context>, v8::Local<v8::Value>);
v8::Maybe<bool> v8::Promise::Resolver::Resolve(v8::Local<v8::Context> p1, v8::Local<v8::Value> p2) {
    return (this->*_v8_Promise_Resolver_Resolve)(p1, p2);
}
static v8::Maybe<bool> (v8::Promise::Resolver::*_v8_Promise_Resolver_Reject)(v8::Local<v8::Context>, v8::Local<v8::Value>);
v8::Maybe<bool> v8::Promise::Resolver::Reject(v8::Local<v8::Context> p1, v8::Local<v8::Value> p2) {
    return (this->*_v8_Promise_Resolver_Reject)(p1, p2);
}
static v8::Local<v8::Promise> (v8::Promise::Resolver::*_v8_Promise_Resolver_GetPromise)();
v8::Local<v8::Promise> v8::Promise::Resolver::GetPromise() {
    return (this->*_v8_Promise_Resolver_GetPromise)();
}
static void (*_v8_Promise_Resolver_CheckCast)(v8::Value *);
void v8::Promise::Resolver::CheckCast(v8::Value * p1) {
    _v8_Promise_Resolver_CheckCast(p1);
}

#include "ServerCommandOrigin.h"
static void (ServerCommandOrigin::*_ServerCommandOrigin_ServerCommandOrigin)(mcpe::string const &, ServerLevel &);
ServerCommandOrigin::ServerCommandOrigin(mcpe::string const & p1, ServerLevel & p2) {
    (this->*_ServerCommandOrigin_ServerCommandOrigin)(p1, p2);
}

#include "CommandOrigin.h"
static int vti_CommandOrigin_getName;
mcpe::string CommandOrigin::getName() {
    union { void* voidp; mcpe::string (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_getName];
    return (this->*u.funcp)();
}
static int vti_CommandOrigin_getBlockPosition;
BlockPos CommandOrigin::getBlockPosition() {
    union { void* voidp; BlockPos (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_getBlockPosition];
    return (this->*u.funcp)();
}
static int vti_CommandOrigin_getWorldPosition;
Vec3 CommandOrigin::getWorldPosition() {
    union { void* voidp; Vec3 (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_getWorldPosition];
    return (this->*u.funcp)();
}
static int vti_CommandOrigin_clone;
std::unique_ptr<CommandOrigin> CommandOrigin::clone() {
    union { void* voidp; std::unique_ptr<CommandOrigin> (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_clone];
    return (this->*u.funcp)();
}
static int vti_CommandOrigin_getOriginType;
CommandOriginType CommandOrigin::getOriginType() {
    union { void* voidp; CommandOriginType (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_getOriginType];
    return (this->*u.funcp)();
}
static int vti_CommandOrigin_getEntity;
Actor * CommandOrigin::getEntity() {
    union { void* voidp; Actor * (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_getEntity];
    return (this->*u.funcp)();
}
static int vti_CommandOrigin_getPermissionLevel;
unsigned char CommandOrigin::getPermissionLevel() {
    union { void* voidp; unsigned char (CommandOrigin::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_CommandOrigin_getPermissionLevel];
    return (this->*u.funcp)();
}
static mce::UUID const & (CommandOrigin::*_CommandOrigin_getUUID)() const;
mce::UUID const & CommandOrigin::getUUID() const {
    return (this->*_CommandOrigin_getUUID)();
}
static void (PlayerCommandOrigin::*_PlayerCommandOrigin_PlayerCommandOrigin)(Player &);
PlayerCommandOrigin::PlayerCommandOrigin(Player & p1) {
    (this->*_PlayerCommandOrigin_PlayerCommandOrigin)(p1);
}

#include "gl.h"
static mcpe::string (*_gl_getOpenGLVendor)();
mcpe::string gl::getOpenGLVendor() {
    return _gl_getOpenGLVendor();
}
static mcpe::string (*_gl_getOpenGLRenderer)();
mcpe::string gl::getOpenGLRenderer() {
    return _gl_getOpenGLRenderer();
}
static mcpe::string (*_gl_getOpenGLVersion)();
mcpe::string gl::getOpenGLVersion() {
    return _gl_getOpenGLVersion();
}
static mcpe::string (*_gl_getOpenGLExtensions)();
mcpe::string gl::getOpenGLExtensions() {
    return _gl_getOpenGLExtensions();
}
static void (*_mce_Platform_OGL_InitBindings)();
void mce::Platform::OGL::InitBindings() {
    _mce_Platform_OGL_InitBindings();
}

#include "ModalForm.h"
void * ModalFormRequestPacket::myVtable;
void * ModalFormResponsePacket::myVtable;

#include "ScriptApi.h"
static void (ScriptEngine::*_ScriptEngine_fireEventToScript)(EventInfo const &, ScriptApi::ScriptObjectHandle const &);
void ScriptEngine::fireEventToScript(EventInfo const & p1, ScriptApi::ScriptObjectHandle const & p2) {
    (this->*_ScriptEngine_fireEventToScript)(p1, p2);
}
static void (ScriptEngine::*_ScriptEngine_deserializeScriptObjectHandleToJson)(ScriptApi::ScriptObjectHandle const &, Json::Value &);
void ScriptEngine::deserializeScriptObjectHandleToJson(ScriptApi::ScriptObjectHandle const & p1, Json::Value & p2) {
    (this->*_ScriptEngine_deserializeScriptObjectHandleToJson)(p1, p2);
}
static void (ScriptEngine::*_ScriptEngine_serializeJsonToScriptObjectHandle)(ScriptApi::ScriptObjectHandle &, Json::Value const &);
void ScriptEngine::serializeJsonToScriptObjectHandle(ScriptApi::ScriptObjectHandle & p1, Json::Value const & p2) {
    (this->*_ScriptEngine_serializeJsonToScriptObjectHandle)(p1, p2);
}
static int (MinecraftServerScriptEngine::*_MinecraftServerScriptEngine_helpDefineActor)(Actor const &, ScriptApi::ScriptObjectHandle &);
int MinecraftServerScriptEngine::helpDefineActor(Actor const & p1, ScriptApi::ScriptObjectHandle & p2) {
    return (this->*_MinecraftServerScriptEngine_helpDefineActor)(p1, p2);
}
static int (MinecraftServerScriptEngine::*_MinecraftServerScriptEngine_helpGetActor)(ScriptApi::ScriptObjectHandle const &, Actor * &);
int MinecraftServerScriptEngine::helpGetActor(ScriptApi::ScriptObjectHandle const & p1, Actor * & p2) {
    return (this->*_MinecraftServerScriptEngine_helpGetActor)(p1, p2);
}
static int (MinecraftServerScriptEngine::*_MinecraftServerScriptEngine_isValidEntity)(ScriptApi::ScriptVersionInfo const &, ScriptApi::ScriptObjectHandle const &, bool &);
int MinecraftServerScriptEngine::isValidEntity(ScriptApi::ScriptVersionInfo const & p1, ScriptApi::ScriptObjectHandle const & p2, bool & p3) {
    return (this->*_MinecraftServerScriptEngine_isValidEntity)(p1, p2, p3);
}
static void (ScriptEventData::*_ScriptEventData_ScriptEventData)(mcpe::string const &);
ScriptEventData::ScriptEventData(mcpe::string const & p1) {
    (this->*_ScriptEventData_ScriptEventData)(p1);
}
static void (ScriptEventData::*_ScriptEventData_destructor)();
ScriptEventData::~ScriptEventData() {
    (this->*_ScriptEventData_destructor)();
}
static bool (ScriptEventData::*_ScriptEventData_serialize)(ScriptEngine &, EventInfo &, ScriptApi::ScriptObjectHandle &) const;
bool ScriptEventData::serialize(ScriptEngine & p1, EventInfo & p2, ScriptApi::ScriptObjectHandle & p3) const {
    return (this->*_ScriptEventData_serialize)(p1, p2, p3);
}

#include "GameMode.h"
XPointer GameMode::vtable;
static void (GameMode::*_GameMode_destructor)();
GameMode::~GameMode() {
    (this->*_GameMode_destructor)();
}

#include "Multitouch.h"
static void (*_Multitouch_feed)(char, char, short, short, int);
void Multitouch::feed(char p1, char p2, short p3, short p4, int p5) {
    _Multitouch_feed(p1, p2, p3, p4, p5);
}

#include "Tag.h"
static void (Tag::*_Tag_destructor)();
Tag::~Tag() {
    (this->*_Tag_destructor)();
}
static void (Tag::*_Tag_deleteChildren)();
void Tag::deleteChildren() {
    (this->*_Tag_deleteChildren)();
}
static bool (Tag::*_Tag_equals)(Tag const &) const;
bool Tag::equals(Tag const & p1) const {
    return (this->*_Tag_equals)(p1);
}
static void (Tag::*_Tag_print)(PrintStream &) const;
void Tag::print(PrintStream & p1) const {
    (this->*_Tag_print)(p1);
}
static void (Tag::*_Tag_print2)(mcpe::string const &, PrintStream &) const;
void Tag::print(mcpe::string const & p1, PrintStream & p2) const {
    (this->*_Tag_print2)(p1, p2);
}
static void (Tag::*_Tag_setName)(mcpe::string const &);
void Tag::setName(mcpe::string const & p1) {
    (this->*_Tag_setName)(p1);
}
static mcpe::string (Tag::*_Tag_getName)() const;
mcpe::string Tag::getName() const {
    return (this->*_Tag_getName)();
}
XPointer EndTag::vt;
static void (EndTag::*_EndTag_write)(IDataOutput &) const;
void EndTag::write(IDataOutput & p1) const {
    (this->*_EndTag_write)(p1);
}
static void (EndTag::*_EndTag_load)(IDataInput &);
void EndTag::load(IDataInput & p1) {
    (this->*_EndTag_load)(p1);
}
static mcpe::string (EndTag::*_EndTag_toString)() const;
mcpe::string EndTag::toString() const {
    return (this->*_EndTag_toString)();
}
static int (EndTag::*_EndTag_getId)() const;
int EndTag::getId() const {
    return (this->*_EndTag_getId)();
}
static bool (EndTag::*_EndTag_equals)(Tag const &) const;
bool EndTag::equals(Tag const & p1) const {
    return (this->*_EndTag_equals)(p1);
}
static std::unique_ptr<Tag> (EndTag::*_EndTag_copy)() const;
std::unique_ptr<Tag> EndTag::copy() const {
    return (this->*_EndTag_copy)();
}
XPointer DoubleTag::vt;
static void (DoubleTag::*_DoubleTag_write)(IDataOutput &) const;
void DoubleTag::write(IDataOutput & p1) const {
    (this->*_DoubleTag_write)(p1);
}
static void (DoubleTag::*_DoubleTag_load)(IDataInput &);
void DoubleTag::load(IDataInput & p1) {
    (this->*_DoubleTag_load)(p1);
}
static mcpe::string (DoubleTag::*_DoubleTag_toString)() const;
mcpe::string DoubleTag::toString() const {
    return (this->*_DoubleTag_toString)();
}
static int (DoubleTag::*_DoubleTag_getId)() const;
int DoubleTag::getId() const {
    return (this->*_DoubleTag_getId)();
}
static bool (DoubleTag::*_DoubleTag_equals)(Tag const &) const;
bool DoubleTag::equals(Tag const & p1) const {
    return (this->*_DoubleTag_equals)(p1);
}
static std::unique_ptr<Tag> (DoubleTag::*_DoubleTag_copy)() const;
std::unique_ptr<Tag> DoubleTag::copy() const {
    return (this->*_DoubleTag_copy)();
}
XPointer ByteArrayTag::vt;
static void (ByteArrayTag::*_ByteArrayTag_write)(IDataOutput &) const;
void ByteArrayTag::write(IDataOutput & p1) const {
    (this->*_ByteArrayTag_write)(p1);
}
static void (ByteArrayTag::*_ByteArrayTag_load)(IDataInput &);
void ByteArrayTag::load(IDataInput & p1) {
    (this->*_ByteArrayTag_load)(p1);
}
static mcpe::string (ByteArrayTag::*_ByteArrayTag_toString)() const;
mcpe::string ByteArrayTag::toString() const {
    return (this->*_ByteArrayTag_toString)();
}
static int (ByteArrayTag::*_ByteArrayTag_getId)() const;
int ByteArrayTag::getId() const {
    return (this->*_ByteArrayTag_getId)();
}
static bool (ByteArrayTag::*_ByteArrayTag_equals)(Tag const &) const;
bool ByteArrayTag::equals(Tag const & p1) const {
    return (this->*_ByteArrayTag_equals)(p1);
}
static std::unique_ptr<Tag> (ByteArrayTag::*_ByteArrayTag_copy)() const;
std::unique_ptr<Tag> ByteArrayTag::copy() const {
    return (this->*_ByteArrayTag_copy)();
}
XPointer CompoundTag::vt;
static void (CompoundTag::*_CompoundTag_write)(IDataOutput &) const;
void CompoundTag::write(IDataOutput & p1) const {
    (this->*_CompoundTag_write)(p1);
}
static void (CompoundTag::*_CompoundTag_load)(IDataInput &);
void CompoundTag::load(IDataInput & p1) {
    (this->*_CompoundTag_load)(p1);
}
static mcpe::string (CompoundTag::*_CompoundTag_toString)() const;
mcpe::string CompoundTag::toString() const {
    return (this->*_CompoundTag_toString)();
}
static int (CompoundTag::*_CompoundTag_getId)() const;
int CompoundTag::getId() const {
    return (this->*_CompoundTag_getId)();
}
static bool (CompoundTag::*_CompoundTag_equals)(Tag const &) const;
bool CompoundTag::equals(Tag const & p1) const {
    return (this->*_CompoundTag_equals)(p1);
}
static void (CompoundTag::*_CompoundTag_print)(mcpe::string const &, PrintStream &) const;
void CompoundTag::print(mcpe::string const & p1, PrintStream & p2) const {
    (this->*_CompoundTag_print)(p1, p2);
}
static std::unique_ptr<Tag> (CompoundTag::*_CompoundTag_copy)() const;
std::unique_ptr<Tag> CompoundTag::copy() const {
    return (this->*_CompoundTag_copy)();
}
XPointer ListTag::vt;
static void (ListTag::*_ListTag_deleteChildren)();
void ListTag::deleteChildren() {
    (this->*_ListTag_deleteChildren)();
}
static void (ListTag::*_ListTag_write)(IDataOutput &) const;
void ListTag::write(IDataOutput & p1) const {
    (this->*_ListTag_write)(p1);
}
static void (ListTag::*_ListTag_load)(IDataInput &);
void ListTag::load(IDataInput & p1) {
    (this->*_ListTag_load)(p1);
}
static mcpe::string (ListTag::*_ListTag_toString)() const;
mcpe::string ListTag::toString() const {
    return (this->*_ListTag_toString)();
}
static int (ListTag::*_ListTag_getId)() const;
int ListTag::getId() const {
    return (this->*_ListTag_getId)();
}
static bool (ListTag::*_ListTag_equals)(Tag const &) const;
bool ListTag::equals(Tag const & p1) const {
    return (this->*_ListTag_equals)(p1);
}
static void (ListTag::*_ListTag_print)(mcpe::string const &, PrintStream &) const;
void ListTag::print(mcpe::string const & p1, PrintStream & p2) const {
    (this->*_ListTag_print)(p1, p2);
}
static std::unique_ptr<Tag> (ListTag::*_ListTag_copy)() const;
std::unique_ptr<Tag> ListTag::copy() const {
    return (this->*_ListTag_copy)();
}
XPointer FloatTag::vt;
static void (FloatTag::*_FloatTag_write)(IDataOutput &) const;
void FloatTag::write(IDataOutput & p1) const {
    (this->*_FloatTag_write)(p1);
}
static void (FloatTag::*_FloatTag_load)(IDataInput &);
void FloatTag::load(IDataInput & p1) {
    (this->*_FloatTag_load)(p1);
}
static mcpe::string (FloatTag::*_FloatTag_toString)() const;
mcpe::string FloatTag::toString() const {
    return (this->*_FloatTag_toString)();
}
static int (FloatTag::*_FloatTag_getId)() const;
int FloatTag::getId() const {
    return (this->*_FloatTag_getId)();
}
static bool (FloatTag::*_FloatTag_equals)(Tag const &) const;
bool FloatTag::equals(Tag const & p1) const {
    return (this->*_FloatTag_equals)(p1);
}
static std::unique_ptr<Tag> (FloatTag::*_FloatTag_copy)() const;
std::unique_ptr<Tag> FloatTag::copy() const {
    return (this->*_FloatTag_copy)();
}
XPointer ByteTag::vt;
static void (ByteTag::*_ByteTag_write)(IDataOutput &) const;
void ByteTag::write(IDataOutput & p1) const {
    (this->*_ByteTag_write)(p1);
}
static void (ByteTag::*_ByteTag_load)(IDataInput &);
void ByteTag::load(IDataInput & p1) {
    (this->*_ByteTag_load)(p1);
}
static mcpe::string (ByteTag::*_ByteTag_toString)() const;
mcpe::string ByteTag::toString() const {
    return (this->*_ByteTag_toString)();
}
static int (ByteTag::*_ByteTag_getId)() const;
int ByteTag::getId() const {
    return (this->*_ByteTag_getId)();
}
static bool (ByteTag::*_ByteTag_equals)(Tag const &) const;
bool ByteTag::equals(Tag const & p1) const {
    return (this->*_ByteTag_equals)(p1);
}
static std::unique_ptr<Tag> (ByteTag::*_ByteTag_copy)() const;
std::unique_ptr<Tag> ByteTag::copy() const {
    return (this->*_ByteTag_copy)();
}
XPointer ShortTag::vt;
static void (ShortTag::*_ShortTag_write)(IDataOutput &) const;
void ShortTag::write(IDataOutput & p1) const {
    (this->*_ShortTag_write)(p1);
}
static void (ShortTag::*_ShortTag_load)(IDataInput &);
void ShortTag::load(IDataInput & p1) {
    (this->*_ShortTag_load)(p1);
}
static mcpe::string (ShortTag::*_ShortTag_toString)() const;
mcpe::string ShortTag::toString() const {
    return (this->*_ShortTag_toString)();
}
static int (ShortTag::*_ShortTag_getId)() const;
int ShortTag::getId() const {
    return (this->*_ShortTag_getId)();
}
static bool (ShortTag::*_ShortTag_equals)(Tag const &) const;
bool ShortTag::equals(Tag const & p1) const {
    return (this->*_ShortTag_equals)(p1);
}
static std::unique_ptr<Tag> (ShortTag::*_ShortTag_copy)() const;
std::unique_ptr<Tag> ShortTag::copy() const {
    return (this->*_ShortTag_copy)();
}
XPointer Int64Tag::vt;
static void (Int64Tag::*_Int64Tag_write)(IDataOutput &) const;
void Int64Tag::write(IDataOutput & p1) const {
    (this->*_Int64Tag_write)(p1);
}
static void (Int64Tag::*_Int64Tag_load)(IDataInput &);
void Int64Tag::load(IDataInput & p1) {
    (this->*_Int64Tag_load)(p1);
}
static mcpe::string (Int64Tag::*_Int64Tag_toString)() const;
mcpe::string Int64Tag::toString() const {
    return (this->*_Int64Tag_toString)();
}
static int (Int64Tag::*_Int64Tag_getId)() const;
int Int64Tag::getId() const {
    return (this->*_Int64Tag_getId)();
}
static bool (Int64Tag::*_Int64Tag_equals)(Tag const &) const;
bool Int64Tag::equals(Tag const & p1) const {
    return (this->*_Int64Tag_equals)(p1);
}
static std::unique_ptr<Tag> (Int64Tag::*_Int64Tag_copy)() const;
std::unique_ptr<Tag> Int64Tag::copy() const {
    return (this->*_Int64Tag_copy)();
}
XPointer IntArrayTag::vt;
static void (IntArrayTag::*_IntArrayTag_write)(IDataOutput &) const;
void IntArrayTag::write(IDataOutput & p1) const {
    (this->*_IntArrayTag_write)(p1);
}
static void (IntArrayTag::*_IntArrayTag_load)(IDataInput &);
void IntArrayTag::load(IDataInput & p1) {
    (this->*_IntArrayTag_load)(p1);
}
static mcpe::string (IntArrayTag::*_IntArrayTag_toString)() const;
mcpe::string IntArrayTag::toString() const {
    return (this->*_IntArrayTag_toString)();
}
static int (IntArrayTag::*_IntArrayTag_getId)() const;
int IntArrayTag::getId() const {
    return (this->*_IntArrayTag_getId)();
}
static bool (IntArrayTag::*_IntArrayTag_equals)(Tag const &) const;
bool IntArrayTag::equals(Tag const & p1) const {
    return (this->*_IntArrayTag_equals)(p1);
}
static std::unique_ptr<Tag> (IntArrayTag::*_IntArrayTag_copy)() const;
std::unique_ptr<Tag> IntArrayTag::copy() const {
    return (this->*_IntArrayTag_copy)();
}
XPointer IntTag::vt;
static void (IntTag::*_IntTag_write)(IDataOutput &) const;
void IntTag::write(IDataOutput & p1) const {
    (this->*_IntTag_write)(p1);
}
static void (IntTag::*_IntTag_load)(IDataInput &);
void IntTag::load(IDataInput & p1) {
    (this->*_IntTag_load)(p1);
}
static mcpe::string (IntTag::*_IntTag_toString)() const;
mcpe::string IntTag::toString() const {
    return (this->*_IntTag_toString)();
}
static int (IntTag::*_IntTag_getId)() const;
int IntTag::getId() const {
    return (this->*_IntTag_getId)();
}
static bool (IntTag::*_IntTag_equals)(Tag const &) const;
bool IntTag::equals(Tag const & p1) const {
    return (this->*_IntTag_equals)(p1);
}
static std::unique_ptr<Tag> (IntTag::*_IntTag_copy)() const;
std::unique_ptr<Tag> IntTag::copy() const {
    return (this->*_IntTag_copy)();
}
XPointer StringTag::vt;
static void (StringTag::*_StringTag_write)(IDataOutput &) const;
void StringTag::write(IDataOutput & p1) const {
    (this->*_StringTag_write)(p1);
}
static void (StringTag::*_StringTag_load)(IDataInput &);
void StringTag::load(IDataInput & p1) {
    (this->*_StringTag_load)(p1);
}
static mcpe::string (StringTag::*_StringTag_toString)() const;
mcpe::string StringTag::toString() const {
    return (this->*_StringTag_toString)();
}
static int (StringTag::*_StringTag_getId)() const;
int StringTag::getId() const {
    return (this->*_StringTag_getId)();
}
static bool (StringTag::*_StringTag_equals)(Tag const &) const;
bool StringTag::equals(Tag const & p1) const {
    return (this->*_StringTag_equals)(p1);
}
static std::unique_ptr<Tag> (StringTag::*_StringTag_copy)() const;
std::unique_ptr<Tag> StringTag::copy() const {
    return (this->*_StringTag_copy)();
}

#include "I18n.h"
static void (ResourceLoadManager::*_ResourceLoadManager_ResourceLoadManager)();
ResourceLoadManager::ResourceLoadManager() {
    (this->*_ResourceLoadManager_ResourceLoadManager)();
}
static void (ResourceLoadManager::*_ResourceLoadManager_sync)(ResourceLoadType);
void ResourceLoadManager::sync(ResourceLoadType p1) {
    (this->*_ResourceLoadManager_sync)(p1);
}
static mcpe::string (*_I18n_get)(mcpe::string const &, std::vector<mcpe::string> const &);
mcpe::string I18n::get(mcpe::string const & p1, std::vector<mcpe::string> const & p2) {
    return _I18n_get(p1, p2);
}
static void (*_I18n_chooseLanguage)(mcpe::string const &);
void I18n::chooseLanguage(mcpe::string const & p1) {
    _I18n_chooseLanguage(p1);
}
static void (*_I18n_loadLanguages)(ResourcePackManager &, ResourceLoadManager &, mcpe::string const &);
void I18n::loadLanguages(ResourcePackManager & p1, ResourceLoadManager & p2, mcpe::string const & p3) {
    _I18n_loadLanguages(p1, p2, p3);
}

#include "MultiplayerService.h"
static void (Social::MultiplayerXBL::*_Social_MultiplayerXBL_MultiplayerXBL)();
Social::MultiplayerXBL::MultiplayerXBL() {
    (this->*_Social_MultiplayerXBL_MultiplayerXBL)();
}

#include "Keyboard.h"
int * Keyboard::_states;
std::vector<int> * Keyboard::_inputCaretLocation;
static void (*_Keyboard_feed)(unsigned char, int);
void Keyboard::feed(unsigned char p1, int p2) {
    _Keyboard_feed(p1, p2);
}
static void (*_Keyboard_feedText)(mcpe::string const &, bool, unsigned char);
void Keyboard::feedText(mcpe::string const & p1, bool p2, unsigned char p3) {
    _Keyboard_feedText(p1, p2, p3);
}

#include "Whitelist.h"
static void (WhitelistEntry::*_WhitelistEntry_WhitelistEntry)(mcpe::string, mce::UUID, mcpe::string, bool);
WhitelistEntry::WhitelistEntry(mcpe::string p1, mce::UUID p2, mcpe::string p3, bool p4) {
    (this->*_WhitelistEntry_WhitelistEntry)(p1, p2, p3, p4);
}
static void (Whitelist::*_Whitelist_Whitelist)(mcpe::function<void ( )>);
Whitelist::Whitelist(mcpe::function<void ( )> p1) {
    (this->*_Whitelist_Whitelist)(p1);
}
static void (Whitelist::*_Whitelist_destructor)();
Whitelist::~Whitelist() {
    (this->*_Whitelist_destructor)();
}
static void (Whitelist::*_Whitelist_deserialize)(Json::Value &);
void Whitelist::deserialize(Json::Value & p1) {
    (this->*_Whitelist_deserialize)(p1);
}
static void (Whitelist::*_Whitelist_serialize)(Json::Value &);
void Whitelist::serialize(Json::Value & p1) {
    (this->*_Whitelist_serialize)(p1);
}
static void (Whitelist::*_Whitelist_removeByName)(mcpe::string const &);
void Whitelist::removeByName(mcpe::string const & p1) {
    (this->*_Whitelist_removeByName)(p1);
}

#include "MinecraftEventing.h"
static void (MinecraftEventing::*_MinecraftEventing_MinecraftEventing)(mcpe::string const &);
MinecraftEventing::MinecraftEventing(mcpe::string const & p1) {
    (this->*_MinecraftEventing_MinecraftEventing)(p1);
}
static void (MinecraftEventing::*_MinecraftEventing_init)();
void MinecraftEventing::init() {
    (this->*_MinecraftEventing_init)();
}

#include "types.h"

#include "TextPacket.h"
static void (TextPacket::*_TextPacket_TextPacket)(TextPacketType, mcpe::string const &, mcpe::string const &, std::vector<mcpe::string> const &, bool, mcpe::string const &, mcpe::string const &);
TextPacket::TextPacket(TextPacketType p1, mcpe::string const & p2, mcpe::string const & p3, std::vector<mcpe::string> const & p4, bool p5, mcpe::string const & p6, mcpe::string const & p7) {
    (this->*_TextPacket_TextPacket)(p1, p2, p3, p4, p5, p6, p7);
}
static TextPacket (*_TextPacket_createRaw)(mcpe::string const &);
TextPacket TextPacket::createRaw(mcpe::string const & p1) {
    return _TextPacket_createRaw(p1);
}
static TextPacket (*_TextPacket_createJukeboxPopup)(mcpe::string const &);
TextPacket TextPacket::createJukeboxPopup(mcpe::string const & p1) {
    return _TextPacket_createJukeboxPopup(p1);
}
static TextPacket (*_TextPacket_createSystemMessage)(mcpe::string const &);
TextPacket TextPacket::createSystemMessage(mcpe::string const & p1) {
    return _TextPacket_createSystemMessage(p1);
}
static TextPacket (*_TextPacket_createChat)(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
TextPacket TextPacket::createChat(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3, mcpe::string const & p4) {
    return _TextPacket_createChat(p1, p2, p3, p4);
}
static TextPacket (*_TextPacket_createTranslatedChat)(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
TextPacket TextPacket::createTranslatedChat(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3, mcpe::string const & p4) {
    return _TextPacket_createTranslatedChat(p1, p2, p3, p4);
}
static TextPacket (*_TextPacket_createTranslatedAnnouncement)(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
TextPacket TextPacket::createTranslatedAnnouncement(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3, mcpe::string const & p4) {
    return _TextPacket_createTranslatedAnnouncement(p1, p2, p3, p4);
}
static TextPacket (*_TextPacket_createWhisper)(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &);
TextPacket TextPacket::createWhisper(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3, mcpe::string const & p4) {
    return _TextPacket_createWhisper(p1, p2, p3, p4);
}
static TextPacket (*_TextPacket_createTranslated)(mcpe::string const &, std::vector<mcpe::string> const &);
TextPacket TextPacket::createTranslated(mcpe::string const & p1, std::vector<mcpe::string> const & p2) {
    return _TextPacket_createTranslated(p1, p2);
}

#include "GameControllerManager.h"
GameControllerManager * GameControllerManager::sGamePadManager;
static void (GameControllerManager::*_GameControllerManager_setGameControllerConnected)(int, bool);
void GameControllerManager::setGameControllerConnected(int p1, bool p2) {
    (this->*_GameControllerManager_setGameControllerConnected)(p1, p2);
}
static void (GameControllerManager::*_GameControllerManager_feedButton)(int, int, GameControllerButtonState, bool);
void GameControllerManager::feedButton(int p1, int p2, GameControllerButtonState p3, bool p4) {
    (this->*_GameControllerManager_feedButton)(p1, p2, p3, p4);
}
static void (GameControllerManager::*_GameControllerManager_feedStick)(int, int, GameControllerStickState, float, float);
void GameControllerManager::feedStick(int p1, int p2, GameControllerStickState p3, float p4, float p5) {
    (this->*_GameControllerManager_feedStick)(p1, p2, p3, p4, p5);
}
static void (GameControllerManager::*_GameControllerManager_feedTrigger)(int, int, float);
void GameControllerManager::feedTrigger(int p1, int p2, float p3) {
    (this->*_GameControllerManager_feedTrigger)(p1, p2, p3);
}
static void (GameControllerManager::*_GameControllerManager_feedJoinGame)(int, bool);
void GameControllerManager::feedJoinGame(int p1, bool p2) {
    (this->*_GameControllerManager_feedJoinGame)(p1, p2);
}

#include "CommandMessage.h"
CDT CommandMessage::constructor;
CDT CommandMessage::destructor;
typeid_t<CommandRegistry> * CommandMessage::tid;
Parser CommandMessage::parser;
static mcpe::string (CommandMessage::*_CommandMessage_getMessage)(CommandOrigin const &) const;
mcpe::string CommandMessage::getMessage(CommandOrigin const & p1) const {
    return (this->*_CommandMessage_getMessage)(p1);
}

#include "Player.h"
static mcpe::string * (Player::*_Player_getPlatformOnlineId)() const;
mcpe::string * Player::getPlatformOnlineId() const {
    return (this->*_Player_getPlatformOnlineId)();
}
static Certificate * (Player::*_Player_getCertificate)() const;
Certificate * Player::getCertificate() const {
    return (this->*_Player_getCertificate)();
}
static bool (Player::*_Player_isCreative)();
bool Player::isCreative() {
    return (this->*_Player_isCreative)();
}
static float (Player::*_Player_getLevelProgress)() const;
float Player::getLevelProgress() const {
    return (this->*_Player_getLevelProgress)();
}
static void (Player::*_Player_sendNetworkPacket)(Packet &) const;
void Player::sendNetworkPacket(Packet & p1) const {
    (this->*_Player_sendNetworkPacket)(p1);
}
static bool (Player::*_Player_canUseAbility)(mcpe::string const &);
bool Player::canUseAbility(mcpe::string const & p1) {
    return (this->*_Player_canUseAbility)(p1);
}
static unsigned char (Player::*_Player_getCommandPermissionLevel)() const;
unsigned char Player::getCommandPermissionLevel() const {
    return (this->*_Player_getCommandPermissionLevel)();
}
static BlockPos (Player::*_Player_getSpawnPosition)();
BlockPos Player::getSpawnPosition() {
    return (this->*_Player_getSpawnPosition)();
}
static ItemInstance & (Player::*_Player_getSelectedItem)() const;
ItemInstance & Player::getSelectedItem() const {
    return (this->*_Player_getSelectedItem)();
}
static int (Player::*_Player_getSleepTimer)() const;
int Player::getSleepTimer() const {
    return (this->*_Player_getSleepTimer)();
}
static float (Player::*_Player_getLuck)();
float Player::getLuck() {
    return (this->*_Player_getLuck)();
}
static int (Player::*_Player_getAttackDamage)();
int Player::getAttackDamage() {
    return (this->*_Player_getAttackDamage)();
}
static Actor * (Player::*_Player_getAgent)() const;
Actor * Player::getAgent() const {
    return (this->*_Player_getAgent)();
}

#include "Actor.h"
static mcpe::string (ActorDefinitionIdentifier::*_ActorDefinitionIdentifier_getCanonicalName)() const;
mcpe::string ActorDefinitionIdentifier::getCanonicalName() const {
    return (this->*_ActorDefinitionIdentifier_getCanonicalName)();
}
static ActorDefinitionIdentifier & (Actor::*_Actor_getActorIdentifier)() const;
ActorDefinitionIdentifier & Actor::getActorIdentifier() const {
    return (this->*_Actor_getActorIdentifier)();
}
static int64_t & (Actor::*_Actor_getUniqueID)() const;
int64_t & Actor::getUniqueID() const {
    return (this->*_Actor_getUniqueID)();
}
static bool (Actor::*_Actor_save)(CompoundTag &);
bool Actor::save(CompoundTag & p1) {
    return (this->*_Actor_save)(p1);
}
static bool (Actor::*_Actor_load)(CompoundTag const &);
bool Actor::load(CompoundTag const & p1) {
    return (this->*_Actor_load)(p1);
}
static Vec3 & (Actor::*_Actor_getPos)() const;
Vec3 & Actor::getPos() const {
    return (this->*_Actor_getPos)();
}
static Vec2 (Actor::*_Actor_getRotation)() const;
Vec2 Actor::getRotation() const {
    return (this->*_Actor_getRotation)();
}
static BlockSource & (Actor::*_Actor_getRegion)() const;
BlockSource & Actor::getRegion() const {
    return (this->*_Actor_getRegion)();
}
static mcpe::string const & (Actor::*_Actor_getNameTag)() const;
mcpe::string const & Actor::getNameTag() const {
    return (this->*_Actor_getNameTag)();
}
static std::tuple<int> (Actor::*_Actor_getDimensionId)() const;
std::tuple<int> Actor::getDimensionId() const {
    return (this->*_Actor_getDimensionId)();
}
static int (Actor::*_Actor_getVariant)() const;
int Actor::getVariant() const {
    return (this->*_Actor_getVariant)();
}
static short (Actor::*_Actor_getAirSupply)() const;
short Actor::getAirSupply() const {
    return (this->*_Actor_getAirSupply)();
}
static short (Actor::*_Actor_getTotalAirSupply)() const;
short Actor::getTotalAirSupply() const {
    return (this->*_Actor_getTotalAirSupply)();
}
static int (Actor::*_Actor_getStrength)() const;
int Actor::getStrength() const {
    return (this->*_Actor_getStrength)();
}
static int (Actor::*_Actor_getStrengthMax)() const;
int Actor::getStrengthMax() const {
    return (this->*_Actor_getStrengthMax)();
}
static int (Actor::*_Actor_getAge)() const;
int Actor::getAge() const {
    return (this->*_Actor_getAge)();
}
static int (Actor::*_Actor_getHealth)() const;
int Actor::getHealth() const {
    return (this->*_Actor_getHealth)();
}
static int (Actor::*_Actor_getMaxHealth)() const;
int Actor::getMaxHealth() const {
    return (this->*_Actor_getMaxHealth)();
}
static Actor * (Actor::*_Actor_getRide)() const;
Actor * Actor::getRide() const {
    return (this->*_Actor_getRide)();
}
static Actor * (Actor::*_Actor_getRideRoot)() const;
Actor * Actor::getRideRoot() const {
    return (this->*_Actor_getRideRoot)();
}
static Actor * (Actor::*_Actor_getTarget)() const;
Actor * Actor::getTarget() const {
    return (this->*_Actor_getTarget)();
}
static ItemInstance & (Actor::*_Actor_getArmor)(ArmorSlot) const;
ItemInstance & Actor::getArmor(ArmorSlot p1) const {
    return (this->*_Actor_getArmor)(p1);
}
static int vti_Actor_changeDimension;
void Actor::changeDimension(int p1, bool p2) {
    union { void* voidp; void (Actor::*funcp)(int, bool); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_Actor_changeDimension];
    (this->*u.funcp)(p1, p2);
}

#include "legacy/App.h"
static int vti_Legacy_Pre_1_8_App_quit;
void Legacy::Pre_1_8::App::quit() {
    union { void* voidp; void (Legacy::Pre_1_8::App::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_Legacy_Pre_1_8_App_quit];
    (this->*u.funcp)();
}

#include "legacy/MinecraftGame.h"
static void (Legacy::Pre_1_2_10::MinecraftGame::*_Legacy_Pre_1_2_10_MinecraftGame_setTextboxText)(mcpe::string const &);
void Legacy::Pre_1_2_10::MinecraftGame::setTextboxText(mcpe::string const & p1) {
    (this->*_Legacy_Pre_1_2_10_MinecraftGame_setTextboxText)(p1);
}

#include "legacy/AppPlatform.h"
static void (Legacy::Pre_1_2_10::AppPlatform::*_Legacy_Pre_1_2_10_AppPlatform_showKeyboard)(mcpe::string const &, int, bool, bool, bool, Vec2 const &);
void Legacy::Pre_1_2_10::AppPlatform::showKeyboard(mcpe::string const & p1, int p2, bool p3, bool p4, bool p5, Vec2 const & p6) {
    (this->*_Legacy_Pre_1_2_10_AppPlatform_showKeyboard)(p1, p2, p3, p4, p5, p6);
}

#include "legacy/Xbox.h"
static int vti_Legacy_Beta_1_8_xbox_services_local_config_get_value_from_local_storage;
mcpe::string Legacy::Beta_1_8::xbox::services::local_config::get_value_from_local_storage(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3) {
    union { void* voidp; mcpe::string (Legacy::Beta_1_8::xbox::services::local_config::*funcp)(mcpe::string const &, mcpe::string const &, mcpe::string const &); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_Legacy_Beta_1_8_xbox_services_local_config_get_value_from_local_storage];
    return (this->*u.funcp)(p1, p2, p3);
}

static int resolve_vtable_func(void** vtable, void* what) {
    if (vtable - 2 == nullptr)
        return -1;
    for (int i = 0; ; i++) {
        if (vtable[i] == nullptr)
            return -1;
        if (vtable[i] == what)
            return i;
    }
}
void minecraft_symbols_init(void* handle) {
    ((void*&) _MinecraftCommands_setOutputSender) = hybris_dlsym(handle, "_ZN17MinecraftCommands15setOutputSenderESt10unique_ptrI19CommandOutputSenderSt14default_deleteIS1_EE");
    if (_MinecraftCommands_setOutputSender == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftCommands15setOutputSenderESt10unique_ptrI19CommandOutputSenderSt14default_deleteIS1_EE");
    ((void*&) _MinecraftCommands_requestCommandExecution) = hybris_dlsym(handle, "_ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKSsib");
    if (_MinecraftCommands_requestCommandExecution == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKSsib");
    ((void*&) _MinecraftCommands_getRegistry) = hybris_dlsym(handle, "_ZN17MinecraftCommands11getRegistryEv");
    if (_MinecraftCommands_getRegistry == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftCommands11getRegistryEv");
    ((void*&) _CommandRegistry_getAutoCompleteOptions) = hybris_dlsym(handle, "_ZNK15CommandRegistry22getAutoCompleteOptionsERK13CommandOriginRKSsj");
    if (_CommandRegistry_getAutoCompleteOptions == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry22getAutoCompleteOptionsERK13CommandOriginRKSsj");
    ((void*&) _CommandRegistry_findCommand) = hybris_dlsym(handle, "_ZN15CommandRegistry11findCommandERKSs");
    if (_CommandRegistry_findCommand == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15CommandRegistry11findCommandERKSs");
    ((void*&) _CommandRegistry_registerOverloadInternal) = hybris_dlsym(handle, "_ZN15CommandRegistry24registerOverloadInternalERNS_9SignatureERNS_8OverloadE");
    if (_CommandRegistry_registerOverloadInternal == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15CommandRegistry24registerOverloadInternalERNS_9SignatureERNS_8OverloadE");
    ((void*&) _CommandRegistry_registerCommand) = hybris_dlsym(handle, "_ZN15CommandRegistry15registerCommandERKSsPKc22CommandPermissionLevel11CommandFlagS5_");
    if (_CommandRegistry_registerCommand == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15CommandRegistry15registerCommandERKSsPKc22CommandPermissionLevel11CommandFlagS5_");
    ((void*&) _CommandRegistry_buildOverload) = hybris_dlsym(handle, "_ZN15CommandRegistry13buildOverloadERNS_8OverloadE");
    if (_CommandRegistry_buildOverload == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15CommandRegistry13buildOverloadERNS_8OverloadE");
    ((void*&) _CommandRegistry_addSoftEnum) = hybris_dlsym(handle, "_ZN15CommandRegistry11addSoftEnumERKSsSt6vectorISsSaISsEEb");
    if (_CommandRegistry_addSoftEnum == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15CommandRegistry11addSoftEnumERKSsSt6vectorISsSaISsEEb");
    ((void*&) _CommandRegistry_setSoftEnumValues) = hybris_dlsym(handle, "_ZN15CommandRegistry17setSoftEnumValuesERKSsSt6vectorISsSaISsEE");
    if (_CommandRegistry_setSoftEnumValues == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15CommandRegistry17setSoftEnumValuesERKSsSt6vectorISsSaISsEE");
    ((void*&) _CommandParameterData_CommandParameterData) = hybris_dlsym(handle, "_ZN20CommandParameterDataC2E8typeid_tI15CommandRegistryEMS1_KFbPvRKNS1_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEEEPKc24CommandParameterDataTypeSI_ibi");
    if (_CommandParameterData_CommandParameterData == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20CommandParameterDataC2E8typeid_tI15CommandRegistryEMS1_KFbPvRKNS1_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEEEPKc24CommandParameterDataTypeSI_ibi");
    ((void*&) _CommandParameterData_CommandParameterData2) = hybris_dlsym(handle, "_ZN20CommandParameterDataC2ERKS_");
    if (_CommandParameterData_CommandParameterData2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20CommandParameterDataC2ERKS_");
    ((void*&) _MessagingCommand_checkChatPermissions) = hybris_dlsym(handle, "_ZNK16MessagingCommand20checkChatPermissionsERK13CommandOriginR13CommandOutput");
    if (_MessagingCommand_checkChatPermissions == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK16MessagingCommand20checkChatPermissionsERK13CommandOriginR13CommandOutput");
    ((void*&) _CommandOutput_getMessages) = hybris_dlsym(handle, "_ZNK13CommandOutput11getMessagesEv");
    if (_CommandOutput_getMessages == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK13CommandOutput11getMessagesEv");
    ((void*&) _CommandOutput_addMessage) = hybris_dlsym(handle, "_ZN13CommandOutput10addMessageERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE24CommandOutputMessageType");
    if (_CommandOutput_addMessage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13CommandOutput10addMessageERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE24CommandOutputMessageType");
    ((void*&) _CommandOutput_error) = hybris_dlsym(handle, "_ZN13CommandOutput5errorERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE");
    if (_CommandOutput_error == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13CommandOutput5errorERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE");
    ((void*&) _CommandOutput_success) = hybris_dlsym(handle, "_ZN13CommandOutput7successERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE");
    if (_CommandOutput_success == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13CommandOutput7successERKSsRKSt6vectorI22CommandOutputParameterSaIS3_EE");
    ((void*&) _CommandOutput_success2) = hybris_dlsym(handle, "_ZN13CommandOutput7successEv");
    if (_CommandOutput_success2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13CommandOutput7successEv");
    ((void*&) _CommandOutputParameter_CommandOutputParameter) = hybris_dlsym(handle, "_ZN22CommandOutputParameterC2ERKSs");
    if (_CommandOutputParameter_CommandOutputParameter == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22CommandOutputParameterC2ERKSs");
    ((void*&) _CommandOutputParameter_CommandOutputParameter2) = hybris_dlsym(handle, "_ZN22CommandOutputParameterC2Ei");
    if (_CommandOutputParameter_CommandOutputParameter2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22CommandOutputParameterC2Ei");
    ((void*&) _Common_getGameVersionStringNet) = hybris_dlsym(handle, "_ZN6Common23getGameVersionStringNetEv");
    if (_Common_getGameVersionStringNet == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Common23getGameVersionStringNetEv");
    ((void*&) _Common_getGameDevVersionString) = hybris_dlsym(handle, "_ZN6Common23getGameDevVersionStringEv");
    if (_Common_getGameDevVersionString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Common23getGameDevVersionStringEv");
    ((void*&) _NetworkIdentifier_getHash) = hybris_dlsym(handle, "_ZNK17NetworkIdentifier7getHashEv");
    if (_NetworkIdentifier_getHash == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK17NetworkIdentifier7getHashEv");
    ((void*&) _NetworkIdentifier_equalsTypeData) = hybris_dlsym(handle, "_ZNK17NetworkIdentifier14equalsTypeDataERKS_");
    if (_NetworkIdentifier_equalsTypeData == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK17NetworkIdentifier14equalsTypeDataERKS_");
    ((void*&) _Options_getFullscreen) = hybris_dlsym(handle, "_ZNK7Options13getFullscreenEv");
    if (_Options_getFullscreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7Options13getFullscreenEv");
    ((void*&) _Options_setFullscreen) = hybris_dlsym(handle, "_ZN7Options13setFullscreenEb");
    if (_Options_setFullscreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7Options13setFullscreenEb");
    ((void*&) _AutomationPlayerCommandOrigin_AutomationPlayerCommandOrigin) = hybris_dlsym(handle, "_ZN29AutomationPlayerCommandOriginC2ERKSsR6Player");
    if (_AutomationPlayerCommandOrigin_AutomationPlayerCommandOrigin == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN29AutomationPlayerCommandOriginC2ERKSsR6Player");
    ((void*&) _Json_Reader_Reader) = hybris_dlsym(handle, "_ZN4Json6ReaderC2Ev");
    if (_Json_Reader_Reader == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json6ReaderC2Ev");
    ((void*&) _Json_Reader_parse) = hybris_dlsym(handle, "_ZN4Json6Reader5parseERSiRNS_5ValueEb");
    if (_Json_Reader_parse == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json6Reader5parseERSiRNS_5ValueEb");
    ((void*&) _Json_StyledWriter_StyledWriter) = hybris_dlsym(handle, "_ZN4Json12StyledWriterC2Ev");
    if (_Json_StyledWriter_StyledWriter == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json12StyledWriterC2Ev");
    ((void*&) _Json_StyledWriter_destructor) = hybris_dlsym(handle, "_ZN4Json12StyledWriterD2Ev");
    if (_Json_StyledWriter_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json12StyledWriterD2Ev");
    ((void*&) _Json_StyledWriter_write) = hybris_dlsym(handle, "_ZN4Json12StyledWriter5writeERKNS_5ValueE");
    if (_Json_StyledWriter_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json12StyledWriter5writeERKNS_5ValueE");
    ((void*&) _Json_FastWriter_FastWriter) = hybris_dlsym(handle, "_ZN4Json10FastWriterC2Ev");
    if (_Json_FastWriter_FastWriter == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json10FastWriterC2Ev");
    ((void*&) _Json_FastWriter_destructor) = hybris_dlsym(handle, "_ZN4Json10FastWriterD2Ev");
    if (_Json_FastWriter_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json10FastWriterD2Ev");
    ((void*&) _Json_FastWriter_write) = hybris_dlsym(handle, "_ZN4Json10FastWriter5writeERKNS_5ValueE");
    if (_Json_FastWriter_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json10FastWriter5writeERKNS_5ValueE");
    ((void*&) _Json_Value_Value) = hybris_dlsym(handle, "_ZN4Json5ValueC2ENS_9ValueTypeE");
    if (_Json_Value_Value == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json5ValueC2ENS_9ValueTypeE");
    ((void*&) _Json_Value_destructor) = hybris_dlsym(handle, "_ZN4Json5ValueD2Ev");
    if (_Json_Value_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4Json5ValueD2Ev");
    ((void*&) ContentIdentity::EMPTY) = hybris_dlsym(handle, "_ZN15ContentIdentity5EMPTYE");
    if (ContentIdentity::EMPTY == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15ContentIdentity5EMPTYE");
    ((void*&) _App_init) = hybris_dlsym(handle, "_ZN3App4initER10AppContext");
    if (_App_init == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3App4initER10AppContext");
    void** vt_App = (void**) hybris_dlsym(handle, "_ZTV3App") + 2;
    vti_App_quit = resolve_vtable_func(vt_App, hybris_dlsym(handle, "_ZN3App4quitERKSsS1_"));
    if (vti_App_quit == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN3App4quitERKSsS1_");
    vti_App_wantToQuit = resolve_vtable_func(vt_App, hybris_dlsym(handle, "_ZN3App10wantToQuitEv"));
    if (vti_App_wantToQuit == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN3App10wantToQuitEv");
    ((void*&) _PermissionsFile_PermissionsFile) = hybris_dlsym(handle, "_ZN15PermissionsFileC2ERKSs");
    if (_PermissionsFile_PermissionsFile == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15PermissionsFileC2ERKSs");
    ((void*&) SharedConstants::MajorVersion) = hybris_dlsym(handle, "_ZN15SharedConstants12MajorVersionE");
    if (SharedConstants::MajorVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants12MajorVersionE");
    ((void*&) SharedConstants::MinorVersion) = hybris_dlsym(handle, "_ZN15SharedConstants12MinorVersionE");
    if (SharedConstants::MinorVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants12MinorVersionE");
    ((void*&) SharedConstants::PatchVersion) = hybris_dlsym(handle, "_ZN15SharedConstants12PatchVersionE");
    if (SharedConstants::PatchVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants12PatchVersionE");
    ((void*&) SharedConstants::RevisionVersion) = hybris_dlsym(handle, "_ZN15SharedConstants15RevisionVersionE");
    if (SharedConstants::RevisionVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants15RevisionVersionE");
    ((void*&) _ResourceLoaders_registerLoader) = hybris_dlsym(handle, "_ZN15ResourceLoaders14registerLoaderE18ResourceFileSystemSt10unique_ptrI14ResourceLoaderSt14default_deleteIS2_EE");
    if (_ResourceLoaders_registerLoader == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15ResourceLoaders14registerLoaderE18ResourceFileSystemSt10unique_ptrI14ResourceLoaderSt14default_deleteIS2_EE");
    ((void*&) _Mouse_feed) = hybris_dlsym(handle, "_ZN5Mouse4feedEccssss");
    if (_Mouse_feed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Mouse4feedEccssss");
    ((void*&) _MinecraftGame_MinecraftGame) = hybris_dlsym(handle, "_ZN13MinecraftGameC2EiPPc");
    if (_MinecraftGame_MinecraftGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGameC2EiPPc");
    ((void*&) _MinecraftGame_destructor) = hybris_dlsym(handle, "_ZN13MinecraftGameD2Ev");
    if (_MinecraftGame_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGameD2Ev");
    ((void*&) _MinecraftGame_isInGame) = hybris_dlsym(handle, "_ZNK13MinecraftGame8isInGameEv");
    if (_MinecraftGame_isInGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK13MinecraftGame8isInGameEv");
    ((void*&) _MinecraftGame_requestLeaveGame) = hybris_dlsym(handle, "_ZN13MinecraftGame16requestLeaveGameEbb");
    if (_MinecraftGame_requestLeaveGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame16requestLeaveGameEbb");
    ((void*&) _MinecraftGame_update) = hybris_dlsym(handle, "_ZN13MinecraftGame6updateEv");
    if (_MinecraftGame_update == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame6updateEv");
    ((void*&) _MinecraftGame_setRenderingSize) = hybris_dlsym(handle, "_ZN13MinecraftGame16setRenderingSizeEii");
    if (_MinecraftGame_setRenderingSize == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame16setRenderingSizeEii");
    ((void*&) _MinecraftGame_setUISizeAndScale) = hybris_dlsym(handle, "_ZN13MinecraftGame17setUISizeAndScaleEiif");
    if (_MinecraftGame_setUISizeAndScale == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame17setUISizeAndScaleEiif");
    ((void*&) _MinecraftGame_getPrimaryUserOptions) = hybris_dlsym(handle, "_ZN13MinecraftGame21getPrimaryUserOptionsEv");
    if (_MinecraftGame_getPrimaryUserOptions == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame21getPrimaryUserOptionsEv");
    ((void*&) _MinecraftGame_getPrimaryClientInstance) = hybris_dlsym(handle, "_ZN13MinecraftGame24getPrimaryClientInstanceEv");
    if (_MinecraftGame_getPrimaryClientInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame24getPrimaryClientInstanceEv");
    ((void*&) _MinecraftGame_startLeaveGame) = hybris_dlsym(handle, "_ZN13MinecraftGame14startLeaveGameEv");
    if (_MinecraftGame_startLeaveGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame14startLeaveGameEv");
    ((void*&) _MinecraftGame_continueLeaveGame) = hybris_dlsym(handle, "_ZN13MinecraftGame17continueLeaveGameEv");
    if (_MinecraftGame_continueLeaveGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame17continueLeaveGameEv");
    ((void*&) _MinecraftGame_setTextboxText) = hybris_dlsym(handle, "_ZN13MinecraftGame14setTextboxTextERKSsi");
    if (_MinecraftGame_setTextboxText == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame14setTextboxTextERKSsi");
    ((void*&) _Level_createRandomSeed) = hybris_dlsym(handle, "_ZN5Level16createRandomSeedEv");
    if (_Level_createRandomSeed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Level16createRandomSeedEv");
    ((void*&) _Level__getServerLevelEventCoordinator) = hybris_dlsym(handle, "_ZN5Level31_getServerLevelEventCoordinatorEv");
    if (_Level__getServerLevelEventCoordinator == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Level31_getServerLevelEventCoordinatorEv");
    ((void*&) _Level__setServerLevelEventCoordinator) = hybris_dlsym(handle, "_ZN5Level31_setServerLevelEventCoordinatorEOSt10unique_ptrI27ServerLevelEventCoordinatorSt14default_deleteIS1_EE");
    if (_Level__setServerLevelEventCoordinator == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Level31_setServerLevelEventCoordinatorEOSt10unique_ptrI27ServerLevelEventCoordinatorSt14default_deleteIS1_EE");
    ((void*&) _Level_suspendPlayer) = hybris_dlsym(handle, "_ZN5Level13suspendPlayerER6Player");
    if (_Level_suspendPlayer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Level13suspendPlayerER6Player");
    ((void*&) _Level_resumePlayer) = hybris_dlsym(handle, "_ZN5Level12resumePlayerER6Player");
    if (_Level_resumePlayer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Level12resumePlayerER6Player");
    ((void*&) _AppResourceLoader_AppResourceLoader) = hybris_dlsym(handle, "_ZN17AppResourceLoaderC2ESt8functionIFSsvEE");
    if (_AppResourceLoader_AppResourceLoader == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17AppResourceLoaderC2ESt8functionIFSsvEE");
    ((void*&) _EducationOptions_EducationOptions) = hybris_dlsym(handle, "_ZN16EducationOptionsC2EP19ResourcePackManager");
    if (_EducationOptions_EducationOptions == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN16EducationOptionsC2EP19ResourcePackManager");
    ((void*&) _ServerInstance_ServerInstance) = hybris_dlsym(handle, "_ZN14ServerInstanceC2ER13IMinecraftAppR30ServerInstanceEventCoordinator");
    if (_ServerInstance_ServerInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstanceC2ER13IMinecraftAppR30ServerInstanceEventCoordinator");
    ((void*&) _ServerInstance_initializeServer) = hybris_dlsym(handle, "_ZN14ServerInstance16initializeServerER13IMinecraftAppR9WhitelistP15PermissionsFileP15FilePathManagerNSt6chrono8durationIxSt5ratioILx1ELx1EEEESsSsSs13LevelSettingsibiiibRKSt6vectorISsSaISsEESsRKN3mce4UUIDER18IMinecraftEventingR22ResourcePackRepositoryRK18ContentTierManagerR19ResourcePackManagerSt8functionIFSt10unique_ptrI12LevelStorageSt14default_deleteISY_EER9SchedulerEERKSsP9LevelDataSsSsSX_I16EducationOptionsSZ_IS1A_EEPSU_SW_IFvS17_EES1F_P28ServerCommunicationInterface");
    if (_ServerInstance_initializeServer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance16initializeServerER13IMinecraftAppR9WhitelistP15PermissionsFileP15FilePathManagerNSt6chrono8durationIxSt5ratioILx1ELx1EEEESsSsSs13LevelSettingsibiiibRKSt6vectorISsSaISsEESsRKN3mce4UUIDER18IMinecraftEventingR22ResourcePackRepositoryRK18ContentTierManagerR19ResourcePackManagerSt8functionIFSt10unique_ptrI12LevelStorageSt14default_deleteISY_EER9SchedulerEERKSsP9LevelDataSsSsSX_I16EducationOptionsSZ_IS1A_EEPSU_SW_IFvS17_EES1F_P28ServerCommunicationInterface");
    ((void*&) _ServerInstance_destructor) = hybris_dlsym(handle, "_ZN14ServerInstanceD2Ev");
    if (_ServerInstance_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstanceD2Ev");
    ((void*&) _ServerInstance_startServerThread) = hybris_dlsym(handle, "_ZN14ServerInstance17startServerThreadEv");
    if (_ServerInstance_startServerThread == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance17startServerThreadEv");
    ((void*&) _ServerInstance_leaveGameSync) = hybris_dlsym(handle, "_ZN14ServerInstance13leaveGameSyncEv");
    if (_ServerInstance_leaveGameSync == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance13leaveGameSyncEv");
    ((void*&) _ServerInstance_queueForServerThread) = hybris_dlsym(handle, "_ZN14ServerInstance20queueForServerThreadESt8functionIFvvEE");
    if (_ServerInstance_queueForServerThread == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance20queueForServerThreadESt8functionIFvvEE");
    ((void*&) _CommandOutputSender_translate) = hybris_dlsym(handle, "_ZN19CommandOutputSender9translateERKSt6vectorISsSaISsEE");
    if (_CommandOutputSender_translate == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandOutputSender9translateERKSt6vectorISsSaISsEE");
    ((void*&) _CommandOutputSender_CommandOutputSender) = hybris_dlsym(handle, "_ZN19CommandOutputSenderC2ERN10Automation16AutomationClientE");
    if (_CommandOutputSender_CommandOutputSender == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandOutputSenderC2ERN10Automation16AutomationClientE");
    ((void*&) _CommandOutputSender_destructor) = hybris_dlsym(handle, "_ZN19CommandOutputSenderD2Ev");
    if (_CommandOutputSender_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandOutputSenderD2Ev");
    ((void*&) _CommandOutputSender_send) = hybris_dlsym(handle, "_ZN19CommandOutputSender4sendERK13CommandOriginRK13CommandOutput");
    if (_CommandOutputSender_send == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandOutputSender4sendERK13CommandOriginRK13CommandOutput");
    ((void*&) _CommandOutputSender_registerOutputCallback) = hybris_dlsym(handle, "_ZN19CommandOutputSender22registerOutputCallbackERKSt8functionIFvR19AutomationCmdOutputEE");
    if (_CommandOutputSender_registerOutputCallback == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandOutputSender22registerOutputCallbackERKSt8functionIFvR19AutomationCmdOutputEE");
    void** vt_LocalNetworkPeer = (void**) hybris_dlsym(handle, "_ZTV16LocalNetworkPeer") + 2;
    vti_NetworkPeer_getNetworkStatus = resolve_vtable_func(vt_LocalNetworkPeer, hybris_dlsym(handle, "_ZN16LocalNetworkPeer16getNetworkStatusEv"));
    if (vti_NetworkPeer_getNetworkStatus == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN16LocalNetworkPeer16getNetworkStatusEv");
    ((void*&) _ServerNetworkHandler_addToBlacklist) = hybris_dlsym(handle, "_ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSs");
    if (_ServerNetworkHandler_addToBlacklist == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSs");
    ((void*&) _ServerNetworkHandler_addToBlacklist2) = hybris_dlsym(handle, "_ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSsS5_RKN9Blacklist8DurationE");
    if (_ServerNetworkHandler_addToBlacklist2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20ServerNetworkHandler14addToBlacklistERKN3mce4UUIDERKSsS5_RKN9Blacklist8DurationE");
    ((void*&) _ServerNetworkHandler_removeFromBlacklist) = hybris_dlsym(handle, "_ZN20ServerNetworkHandler19removeFromBlacklistERKN3mce4UUIDERKSs");
    if (_ServerNetworkHandler_removeFromBlacklist == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20ServerNetworkHandler19removeFromBlacklistERKN3mce4UUIDERKSs");
    ((void*&) _ServerNetworkHandler_disconnectClient) = hybris_dlsym(handle, "_ZN20ServerNetworkHandler16disconnectClientERK17NetworkIdentifierRKSsb");
    if (_ServerNetworkHandler_disconnectClient == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20ServerNetworkHandler16disconnectClientERK17NetworkIdentifierRKSsb");
    ((void*&) _ServerNetworkHandler_getPeerForUser) = hybris_dlsym(handle, "_ZN14NetworkHandler14getPeerForUserERK17NetworkIdentifier");
    if (_ServerNetworkHandler_getPeerForUser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14NetworkHandler14getPeerForUserERK17NetworkIdentifier");
    ((void*&) _ServerNetworkHandler_handle) = hybris_dlsym(handle, "_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK29ClientToServerHandshakePacket");
    if (_ServerNetworkHandler_handle == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20ServerNetworkHandler6handleERK17NetworkIdentifierRK29ClientToServerHandshakePacket");
    ((void*&) Packet::myVtable) = hybris_dlsym(handle, "_ZTV6Packet");
    if (Packet::myVtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV6Packet");
    ((void*&) Packet::vt_serverToClientHandshake) = hybris_dlsym(handle, "_ZTV29ServerToClientHandshakePacket");
    if (Packet::vt_serverToClientHandshake == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV29ServerToClientHandshakePacket");
    ((void*&) AppPlatform::myVtable) = hybris_dlsym(handle, "_ZTV11AppPlatform");
    if (AppPlatform::myVtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV11AppPlatform");
    ((void*&) AppPlatform::instance) = hybris_dlsym(handle, "_ZN14ServiceLocatorI11AppPlatformE15mDefaultServiceE");
    if (AppPlatform::instance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServiceLocatorI11AppPlatformE15mDefaultServiceE");
    ((void*&) _AppPlatform_AppPlatform) = hybris_dlsym(handle, "_ZN11AppPlatformC2Ev");
    if (_AppPlatform_AppPlatform == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatformC2Ev");
    ((void*&) _AppPlatform__fireAppFocusGained) = hybris_dlsym(handle, "_ZN11AppPlatform19_fireAppFocusGainedEv");
    if (_AppPlatform__fireAppFocusGained == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatform19_fireAppFocusGainedEv");
    ((void*&) _AppPlatform_initialize) = hybris_dlsym(handle, "_ZN11AppPlatform10initializeEv");
    if (_AppPlatform_initialize == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatform10initializeEv");
    ((void*&) _AppPlatform_teardown) = hybris_dlsym(handle, "_ZN11AppPlatform8teardownEv");
    if (_AppPlatform_teardown == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatform8teardownEv");
    ((void*&) _AppPlatform_showKeyboard) = hybris_dlsym(handle, "_ZN11AppPlatform12showKeyboardERKSsibbbiRK4Vec2");
    if (_AppPlatform_showKeyboard == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatform12showKeyboardERKSsibbbiRK4Vec2");
    ((void*&) _AppPlatform_hideKeyboard) = hybris_dlsym(handle, "_ZN11AppPlatform12hideKeyboardEv");
    if (_AppPlatform_hideKeyboard == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatform12hideKeyboardEv");
    ((void*&) _AppPlatform_isKeyboardVisible) = hybris_dlsym(handle, "_ZN11AppPlatform17isKeyboardVisibleEv");
    if (_AppPlatform_isKeyboardVisible == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11AppPlatform17isKeyboardVisibleEv");
    ((void*&) _CommandSelectorBase_CommandSelectorBase) = hybris_dlsym(handle, "_ZN19CommandSelectorBaseC2Eb");
    if (_CommandSelectorBase_CommandSelectorBase == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandSelectorBaseC2Eb");
    ((void*&) _CommandSelectorBase_destructor) = hybris_dlsym(handle, "_ZN19CommandSelectorBaseD2Ev");
    if (_CommandSelectorBase_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19CommandSelectorBaseD2Ev");
    ((void*&) _CommandSelectorBase_newResults) = hybris_dlsym(handle, "_ZNK19CommandSelectorBase10newResultsERK13CommandOrigin");
    if (_CommandSelectorBase_newResults == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK19CommandSelectorBase10newResultsERK13CommandOrigin");
    ((void*&) CommandActorSelector::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistry15CommandSelectorI5ActorEE8typeid_tIT_EvE2id");
    if (CommandActorSelector::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistry15CommandSelectorI5ActorEE8typeid_tIT_EvE2id");
    ((void*&) CommandActorSelector::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseI15CommandSelectorI5ActorEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommandActorSelector::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseI15CommandSelectorI5ActorEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommandPlayerSelector::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistry15CommandSelectorI6PlayerEE8typeid_tIT_EvE2id");
    if (CommandPlayerSelector::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistry15CommandSelectorI6PlayerEE8typeid_tIT_EvE2id");
    ((void*&) CommandPlayerSelector::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseI15CommandSelectorI6PlayerEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommandPlayerSelector::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseI15CommandSelectorI6PlayerEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) _Command_destructor) = hybris_dlsym(handle, "_ZN7CommandD2Ev");
    if (_Command_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7CommandD2Ev");
    ((void*&) _Command_Command) = hybris_dlsym(handle, "_ZN7CommandC2Ev");
    if (_Command_Command == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7CommandC2Ev");
    ((void*&) _Minecraft_getCommands) = hybris_dlsym(handle, "_ZN9Minecraft11getCommandsEv");
    if (_Minecraft_getCommands == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Minecraft11getCommandsEv");
    ((void*&) _Minecraft_getLevel) = hybris_dlsym(handle, "_ZNK9Minecraft8getLevelEv");
    if (_Minecraft_getLevel == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9Minecraft8getLevelEv");
    ((void*&) _Minecraft_activateWhitelist) = hybris_dlsym(handle, "_ZN9Minecraft17activateWhitelistEv");
    if (_Minecraft_activateWhitelist == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Minecraft17activateWhitelistEv");
    ((void*&) _Automation_AutomationClient_AutomationClient) = hybris_dlsym(handle, "_ZN10Automation16AutomationClientC2ER13IMinecraftApp");
    if (_Automation_AutomationClient_AutomationClient == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10Automation16AutomationClientC2ER13IMinecraftApp");
    ((void*&) _FilePathManager_FilePathManager) = hybris_dlsym(handle, "_ZN15FilePathManagerC2ESsb");
    if (_FilePathManager_FilePathManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15FilePathManagerC2ESsb");
    ((void*&) _FilePathManager_getRootPath) = hybris_dlsym(handle, "_ZNK15FilePathManager11getRootPathEv");
    if (_FilePathManager_getRootPath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15FilePathManager11getRootPathEv");
    ((void*&) _FilePathManager_getUserDataPath) = hybris_dlsym(handle, "_ZNK15FilePathManager15getUserDataPathEv");
    if (_FilePathManager_getUserDataPath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15FilePathManager15getUserDataPathEv");
    ((void*&) _FilePathManager_getWorldsPath) = hybris_dlsym(handle, "_ZNK15FilePathManager13getWorldsPathEv");
    if (_FilePathManager_getWorldsPath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15FilePathManager13getWorldsPathEv");
    ((void*&) _FilePathManager_setPackagePath) = hybris_dlsym(handle, "_ZN15FilePathManager14setPackagePathESs");
    if (_FilePathManager_setPackagePath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15FilePathManager14setPackagePathESs");
    ((void*&) _FilePathManager_getPackagePath) = hybris_dlsym(handle, "_ZNK15FilePathManager14getPackagePathEv");
    if (_FilePathManager_getPackagePath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15FilePathManager14getPackagePathEv");
    ((void*&) _FilePathManager_setSettingsPath) = hybris_dlsym(handle, "_ZN15FilePathManager15setSettingsPathESs");
    if (_FilePathManager_setSettingsPath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15FilePathManager15setSettingsPathESs");
    ((void*&) _FilePathManager_getSettingsPath) = hybris_dlsym(handle, "_ZNK15FilePathManager15getSettingsPathEv");
    if (_FilePathManager_getSettingsPath == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15FilePathManager15getSettingsPathEv");
    ((void*&) CommonType<mcpe::string>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistrySsE8typeid_tIT_EvE2id");
    if (CommonType<mcpe::string>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistrySsE8typeid_tIT_EvE2id");
    ((void*&) CommonType<mcpe::string>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseISsEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<mcpe::string>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseISsEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommonType<int>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id");
    if (CommonType<int>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistryiE8typeid_tIT_EvE2id");
    ((void*&) CommonType<int>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseIiEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<int>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseIiEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommonType<float>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id");
    if (CommonType<float>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistryfE8typeid_tIT_EvE2id");
    ((void*&) CommonType<float>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseIfEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<float>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseIfEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommonType<bool>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistrybE8typeid_tIT_EvE2id");
    if (CommonType<bool>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistrybE8typeid_tIT_EvE2id");
    ((void*&) CommonType<bool>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseIbEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<bool>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseIbEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommonType<CommandRawText>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistry14CommandRawTextE8typeid_tIT_EvE2id");
    if (CommonType<CommandRawText>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistry14CommandRawTextE8typeid_tIT_EvE2id");
    ((void*&) CommonType<CommandRawText>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseI14CommandRawTextEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<CommandRawText>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseI14CommandRawTextEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) _CommandPosition_getPosition) = hybris_dlsym(handle, "_ZNK15CommandPosition11getPositionERK13CommandOrigin");
    if (_CommandPosition_getPosition == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandPosition11getPositionERK13CommandOrigin");
    ((void*&) CommonType<CommandPosition>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistry15CommandPositionE8typeid_tIT_EvE2id");
    if (CommonType<CommandPosition>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistry15CommandPositionE8typeid_tIT_EvE2id");
    ((void*&) CommonType<CommandPosition>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseI15CommandPositionEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<CommandPosition>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseI15CommandPositionEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommonType<Block*>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistryPK5BlockE8typeid_tIT_EvE2id");
    if (CommonType<Block*>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistryPK5BlockE8typeid_tIT_EvE2id");
    ((void*&) CommonType<Block*>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseIPK5BlockEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<Block*>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseIPK5BlockEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) CommonType<Json::Value>::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistryN4Json5ValueEE8typeid_tIT_EvE2id");
    if (CommonType<Json::Value>::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistryN4Json5ValueEE8typeid_tIT_EvE2id");
    ((void*&) CommonType<Json::Value>::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseIN4Json5ValueEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommonType<Json::Value>::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseIN4Json5ValueEEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) _BlockSource_getBiome) = hybris_dlsym(handle, "_ZN11BlockSource8getBiomeERK8BlockPos");
    if (_BlockSource_getBiome == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11BlockSource8getBiomeERK8BlockPos");
    ((void*&) _BlockSource_getBlock) = hybris_dlsym(handle, "_ZNK11BlockSource8getBlockERK8BlockPos");
    if (_BlockSource_getBlock == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11BlockSource8getBlockERK8BlockPos");
    ((void*&) _BlockSource_getExtraBlock) = hybris_dlsym(handle, "_ZNK11BlockSource13getExtraBlockERK8BlockPos");
    if (_BlockSource_getExtraBlock == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11BlockSource13getExtraBlockERK8BlockPos");
    ((void*&) _BlockSource_setBlock) = hybris_dlsym(handle, "_ZN11BlockSource8setBlockEiiiRK5Blocki");
    if (_BlockSource_setBlock == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11BlockSource8setBlockEiiiRK5Blocki");
    ((void*&) _LevelSettings_LevelSettings) = hybris_dlsym(handle, "_ZN13LevelSettingsC2Ev");
    if (_LevelSettings_LevelSettings == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettingsC2Ev");
    ((void*&) _LevelSettings_LevelSettings2) = hybris_dlsym(handle, "_ZN13LevelSettingsC2ERKS_");
    if (_LevelSettings_LevelSettings2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettingsC2ERKS_");
    ((void*&) _LevelSettings_destructor) = hybris_dlsym(handle, "_ZN13LevelSettingsD2Ev");
    if (_LevelSettings_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettingsD2Ev");
    ((void*&) _LevelSettings_parseSeedString) = hybris_dlsym(handle, "_ZN13LevelSettings15parseSeedStringERKSsj");
    if (_LevelSettings_parseSeedString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettings15parseSeedStringERKSsj");
    ((void*&) _SaveTransactionManager_SaveTransactionManager) = hybris_dlsym(handle, "_ZN22SaveTransactionManagerC2ESt8functionIFvbEE");
    if (_SaveTransactionManager_SaveTransactionManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22SaveTransactionManagerC2ESt8functionIFvbEE");
    ((void*&) Enchant::mEnchants) = hybris_dlsym(handle, "_ZN7Enchant9mEnchantsE");
    if (Enchant::mEnchants == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7Enchant9mEnchantsE");
    ((void*&) _Enchant_getDescriptionId) = hybris_dlsym(handle, "_ZNK7Enchant16getDescriptionIdEv");
    if (_Enchant_getDescriptionId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7Enchant16getDescriptionIdEv");
    void** vt_Enchant = (void**) hybris_dlsym(handle, "_ZTV7Enchant") + 2;
    vti_Enchant_getMaxLevel = resolve_vtable_func(vt_Enchant, hybris_dlsym(handle, "_ZNK7Enchant11getMaxLevelEv"));
    if (vti_Enchant_getMaxLevel == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK7Enchant11getMaxLevelEv");
    ((void*&) _ItemEnchants_getEnchants) = hybris_dlsym(handle, "_ZNK12ItemEnchants11getEnchantsEi");
    if (_ItemEnchants_getEnchants == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemEnchants11getEnchantsEi");
    ((void*&) _ItemInstance_isNull) = hybris_dlsym(handle, "_ZNK12ItemInstance6isNullEv");
    if (_ItemInstance_isNull == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemInstance6isNullEv");
    ((void*&) _ItemInstance_getId) = hybris_dlsym(handle, "_ZNK12ItemInstance5getIdEv");
    if (_ItemInstance_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemInstance5getIdEv");
    ((void*&) _ItemInstance_getName) = hybris_dlsym(handle, "_ZNK12ItemInstance7getNameEv");
    if (_ItemInstance_getName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemInstance7getNameEv");
    ((void*&) _ItemInstance_getRawNameId) = hybris_dlsym(handle, "_ZNK12ItemInstance12getRawNameIdEv");
    if (_ItemInstance_getRawNameId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemInstance12getRawNameIdEv");
    ((void*&) _ItemInstance_getCustomName) = hybris_dlsym(handle, "_ZNK12ItemInstance13getCustomNameEv");
    if (_ItemInstance_getCustomName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemInstance13getCustomNameEv");
    ((void*&) _ItemInstance_getEnchantsFromUserData) = hybris_dlsym(handle, "_ZNK12ItemInstance23getEnchantsFromUserDataEv");
    if (_ItemInstance_getEnchantsFromUserData == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ItemInstance23getEnchantsFromUserDataEv");
    ((void*&) _ExtendedCertificate_getXuid) = hybris_dlsym(handle, "_ZN19ExtendedCertificate7getXuidERK11Certificate");
    if (_ExtendedCertificate_getXuid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ExtendedCertificate7getXuidERK11Certificate");
    ((void*&) _Crypto_Random_generateUUID) = hybris_dlsym(handle, "_ZN6Crypto6Random12generateUUIDEv");
    if (_Crypto_Random_generateUUID == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Crypto6Random12generateUUIDEv");
    ((void*&) mce::UUID::EMPTY) = hybris_dlsym(handle, "_ZN3mce4UUID5EMPTYE");
    if (mce::UUID::EMPTY == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3mce4UUID5EMPTYE");
    ((void*&) _mce_UUID_fromString) = hybris_dlsym(handle, "_ZN3mce4UUID10fromStringERKSs");
    if (_mce_UUID_fromString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3mce4UUID10fromStringERKSs");
    ((void*&) _mce_UUID_asString) = hybris_dlsym(handle, "_ZNK3mce4UUID8asStringEv");
    if (_mce_UUID_asString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3mce4UUID8asStringEv");
    ((void*&) TransferPacket::myVtable) = hybris_dlsym(handle, "_ZTV14TransferPacket");
    if (TransferPacket::myVtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV14TransferPacket");
    ((void*&) _PackInstance_PackInstance) = hybris_dlsym(handle, "_ZN12PackInstanceC2EP12ResourcePackibP12PackSettings");
    if (_PackInstance_PackInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN12PackInstanceC2EP12ResourcePackibP12PackSettings");
    ((void*&) ResourcePackStack::vtable_sym) = hybris_dlsym(handle, "_ZTV17ResourcePackStack");
    if (ResourcePackStack::vtable_sym == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV17ResourcePackStack");
    ((void*&) _ResourcePackStack_add) = hybris_dlsym(handle, "_ZN17ResourcePackStack3addE12PackInstanceRK22ResourcePackRepositoryb");
    if (_ResourcePackStack_add == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17ResourcePackStack3addE12PackInstanceRK22ResourcePackRepositoryb");
    ((void*&) _Social_UserManager_CreateUserManager) = hybris_dlsym(handle, "_ZN6Social11UserManager17CreateUserManagerEv");
    if (_Social_UserManager_CreateUserManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Social11UserManager17CreateUserManagerEv");
    ((void*&) _Scheduler_processCoroutines) = hybris_dlsym(handle, "_ZN9Scheduler17processCoroutinesENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE");
    if (_Scheduler_processCoroutines == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Scheduler17processCoroutinesENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE");
    ((void*&) _MinecraftScheduler_client) = hybris_dlsym(handle, "_ZN18MinecraftScheduler6clientEv");
    if (_MinecraftScheduler_client == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN18MinecraftScheduler6clientEv");
    ((void*&) _ExternalFileLevelStorageSource_ExternalFileLevelStorageSource) = hybris_dlsym(handle, "_ZN30ExternalFileLevelStorageSourceC2EP15FilePathManagerSt10shared_ptrI22SaveTransactionManagerE");
    if (_ExternalFileLevelStorageSource_ExternalFileLevelStorageSource == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN30ExternalFileLevelStorageSourceC2EP15FilePathManagerSt10shared_ptrI22SaveTransactionManagerE");
    ((void*&) _ExternalFileLevelStorageSource_createLevelStorage) = hybris_dlsym(handle, "_ZN30ExternalFileLevelStorageSource18createLevelStorageER9SchedulerRKSsRK15ContentIdentityRK19IContentKeyProvider");
    if (_ExternalFileLevelStorageSource_createLevelStorage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN30ExternalFileLevelStorageSource18createLevelStorageER9SchedulerRKSsRK15ContentIdentityRK19IContentKeyProvider");
    ((void*&) _SkinPackKeyProvider_SkinPackKeyProvider) = hybris_dlsym(handle, "_ZN19SkinPackKeyProviderC2Ev");
    if (_SkinPackKeyProvider_SkinPackKeyProvider == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19SkinPackKeyProviderC2Ev");
    ((void*&) _PackManifestFactory_PackManifestFactory) = hybris_dlsym(handle, "_ZN19PackManifestFactoryC2ER14IPackTelemetry");
    if (_PackManifestFactory_PackManifestFactory == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19PackManifestFactoryC2ER14IPackTelemetry");
    ((void*&) _PackSourceFactory_PackSourceFactory) = hybris_dlsym(handle, "_ZN17PackSourceFactoryC2EP7Options");
    if (_PackSourceFactory_PackSourceFactory == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17PackSourceFactoryC2EP7Options");
    ((void*&) _ResourcePackRepository_ResourcePackRepository) = hybris_dlsym(handle, "_ZN22ResourcePackRepositoryC2ER18IMinecraftEventingR19PackManifestFactoryR29IContentAccessibilityProviderP15FilePathManagerR17PackSourceFactoryb");
    if (_ResourcePackRepository_ResourcePackRepository == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22ResourcePackRepositoryC2ER18IMinecraftEventingR19PackManifestFactoryR29IContentAccessibilityProviderP15FilePathManagerR17PackSourceFactoryb");
    ((void*&) _ResourcePackRepository_addWorldResourcePacks) = hybris_dlsym(handle, "_ZN22ResourcePackRepository21addWorldResourcePacksERKSs");
    if (_ResourcePackRepository_addWorldResourcePacks == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22ResourcePackRepository21addWorldResourcePacksERKSs");
    ((void*&) _ResourcePackRepository_refreshPacks) = hybris_dlsym(handle, "_ZN22ResourcePackRepository12refreshPacksEv");
    if (_ResourcePackRepository_refreshPacks == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22ResourcePackRepository12refreshPacksEv");
    ((void*&) _ContentTierManager_ContentTierManager) = hybris_dlsym(handle, "_ZN18ContentTierManagerC2Ev");
    if (_ContentTierManager_ContentTierManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN18ContentTierManagerC2Ev");
    ((void*&) _ResourcePackManager_ResourcePackManager) = hybris_dlsym(handle, "_ZN19ResourcePackManagerC2ESt8functionIFSsvEERK18ContentTierManager");
    if (_ResourcePackManager_ResourcePackManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ResourcePackManagerC2ESt8functionIFSsvEERK18ContentTierManager");
    ((void*&) _ResourcePackManager_setStack) = hybris_dlsym(handle, "_ZN19ResourcePackManager8setStackESt10unique_ptrI17ResourcePackStackSt14default_deleteIS1_EE21ResourcePackStackTypeb");
    if (_ResourcePackManager_setStack == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ResourcePackManager8setStackESt10unique_ptrI17ResourcePackStackSt14default_deleteIS1_EE21ResourcePackStackTypeb");
    ((void*&) _ResourcePackManager_onLanguageChanged) = hybris_dlsym(handle, "_ZN19ResourcePackManager17onLanguageChangedEv");
    if (_ResourcePackManager_onLanguageChanged == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ResourcePackManager17onLanguageChangedEv");
    ((void*&) _v8_V8_Initialize) = hybris_dlsym(handle, "_ZN2v82V810InitializeEv");
    if (_v8_V8_Initialize == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v82V810InitializeEv");
    ((void*&) _v8_V8_InitializePlatform) = hybris_dlsym(handle, "_ZN2v82V818InitializePlatformEPNS_8PlatformE");
    if (_v8_V8_InitializePlatform == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v82V818InitializePlatformEPNS_8PlatformE");
    ((void*&) _v8_V8_GlobalizeReference) = hybris_dlsym(handle, "_ZN2v82V818GlobalizeReferenceEPNS_8internal7IsolateEPPNS1_6ObjectE");
    if (_v8_V8_GlobalizeReference == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v82V818GlobalizeReferenceEPNS_8internal7IsolateEPPNS1_6ObjectE");
    ((void*&) _v8_V8_DisposeGlobal) = hybris_dlsym(handle, "_ZN2v82V813DisposeGlobalEPPNS_8internal6ObjectE");
    if (_v8_V8_DisposeGlobal == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v82V813DisposeGlobalEPPNS_8internal6ObjectE");
    ((void*&) _v8_V8_CreateHandle) = hybris_dlsym(handle, "_ZN2v811HandleScope12CreateHandleEPNS_8internal7IsolateEPNS1_6ObjectE");
    if (_v8_V8_CreateHandle == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v811HandleScope12CreateHandleEPNS_8internal7IsolateEPNS1_6ObjectE");
    ((void*&) _v8_V8_MakeWeak) = hybris_dlsym(handle, "_ZN2v82V88MakeWeakEPPNS_8internal6ObjectEPvPFvRKNS_16WeakCallbackInfoIvEEENS_16WeakCallbackTypeE");
    if (_v8_V8_MakeWeak == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v82V88MakeWeakEPPNS_8internal6ObjectEPvPFvRKNS_16WeakCallbackInfoIvEEENS_16WeakCallbackTypeE");
    ((void*&) _v8_Value_IsTrue) = hybris_dlsym(handle, "_ZNK2v85Value6IsTrueEv");
    if (_v8_Value_IsTrue == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value6IsTrueEv");
    ((void*&) _v8_Value_IsFalse) = hybris_dlsym(handle, "_ZNK2v85Value7IsFalseEv");
    if (_v8_Value_IsFalse == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value7IsFalseEv");
    ((void*&) _v8_Value_IsName) = hybris_dlsym(handle, "_ZNK2v85Value6IsNameEv");
    if (_v8_Value_IsName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value6IsNameEv");
    ((void*&) _v8_Value_IsSymbol) = hybris_dlsym(handle, "_ZNK2v85Value8IsSymbolEv");
    if (_v8_Value_IsSymbol == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8IsSymbolEv");
    ((void*&) _v8_Value_IsFunction) = hybris_dlsym(handle, "_ZNK2v85Value10IsFunctionEv");
    if (_v8_Value_IsFunction == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value10IsFunctionEv");
    ((void*&) _v8_Value_IsArray) = hybris_dlsym(handle, "_ZNK2v85Value7IsArrayEv");
    if (_v8_Value_IsArray == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value7IsArrayEv");
    ((void*&) _v8_Value_IsObject) = hybris_dlsym(handle, "_ZNK2v85Value8IsObjectEv");
    if (_v8_Value_IsObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8IsObjectEv");
    ((void*&) _v8_Value_IsBoolean) = hybris_dlsym(handle, "_ZNK2v85Value9IsBooleanEv");
    if (_v8_Value_IsBoolean == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9IsBooleanEv");
    ((void*&) _v8_Value_IsNumber) = hybris_dlsym(handle, "_ZNK2v85Value8IsNumberEv");
    if (_v8_Value_IsNumber == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8IsNumberEv");
    ((void*&) _v8_Value_IsExternal) = hybris_dlsym(handle, "_ZNK2v85Value10IsExternalEv");
    if (_v8_Value_IsExternal == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value10IsExternalEv");
    ((void*&) _v8_Value_IsInt32) = hybris_dlsym(handle, "_ZNK2v85Value7IsInt32Ev");
    if (_v8_Value_IsInt32 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value7IsInt32Ev");
    ((void*&) _v8_Value_IsUint32) = hybris_dlsym(handle, "_ZNK2v85Value8IsUint32Ev");
    if (_v8_Value_IsUint32 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8IsUint32Ev");
    ((void*&) _v8_Value_IsDate) = hybris_dlsym(handle, "_ZNK2v85Value6IsDateEv");
    if (_v8_Value_IsDate == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value6IsDateEv");
    ((void*&) _v8_Value_IsArgumentsObject) = hybris_dlsym(handle, "_ZNK2v85Value17IsArgumentsObjectEv");
    if (_v8_Value_IsArgumentsObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value17IsArgumentsObjectEv");
    ((void*&) _v8_Value_IsBooleanObject) = hybris_dlsym(handle, "_ZNK2v85Value15IsBooleanObjectEv");
    if (_v8_Value_IsBooleanObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value15IsBooleanObjectEv");
    ((void*&) _v8_Value_IsNumberObject) = hybris_dlsym(handle, "_ZNK2v85Value14IsNumberObjectEv");
    if (_v8_Value_IsNumberObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value14IsNumberObjectEv");
    ((void*&) _v8_Value_IsStringObject) = hybris_dlsym(handle, "_ZNK2v85Value14IsStringObjectEv");
    if (_v8_Value_IsStringObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value14IsStringObjectEv");
    ((void*&) _v8_Value_IsSymbolObject) = hybris_dlsym(handle, "_ZNK2v85Value14IsSymbolObjectEv");
    if (_v8_Value_IsSymbolObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value14IsSymbolObjectEv");
    ((void*&) _v8_Value_IsNativeError) = hybris_dlsym(handle, "_ZNK2v85Value13IsNativeErrorEv");
    if (_v8_Value_IsNativeError == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value13IsNativeErrorEv");
    ((void*&) _v8_Value_IsRegExp) = hybris_dlsym(handle, "_ZNK2v85Value8IsRegExpEv");
    if (_v8_Value_IsRegExp == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8IsRegExpEv");
    ((void*&) _v8_Value_IsAsyncFunction) = hybris_dlsym(handle, "_ZNK2v85Value15IsAsyncFunctionEv");
    if (_v8_Value_IsAsyncFunction == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value15IsAsyncFunctionEv");
    ((void*&) _v8_Value_IsGeneratorFunction) = hybris_dlsym(handle, "_ZNK2v85Value19IsGeneratorFunctionEv");
    if (_v8_Value_IsGeneratorFunction == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value19IsGeneratorFunctionEv");
    ((void*&) _v8_Value_IsGeneratorObject) = hybris_dlsym(handle, "_ZNK2v85Value17IsGeneratorObjectEv");
    if (_v8_Value_IsGeneratorObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value17IsGeneratorObjectEv");
    ((void*&) _v8_Value_IsPromise) = hybris_dlsym(handle, "_ZNK2v85Value9IsPromiseEv");
    if (_v8_Value_IsPromise == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9IsPromiseEv");
    ((void*&) _v8_Value_IsMap) = hybris_dlsym(handle, "_ZNK2v85Value5IsMapEv");
    if (_v8_Value_IsMap == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value5IsMapEv");
    ((void*&) _v8_Value_IsSet) = hybris_dlsym(handle, "_ZNK2v85Value5IsSetEv");
    if (_v8_Value_IsSet == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value5IsSetEv");
    ((void*&) _v8_Value_IsMapIterator) = hybris_dlsym(handle, "_ZNK2v85Value13IsMapIteratorEv");
    if (_v8_Value_IsMapIterator == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value13IsMapIteratorEv");
    ((void*&) _v8_Value_IsSetIterator) = hybris_dlsym(handle, "_ZNK2v85Value13IsSetIteratorEv");
    if (_v8_Value_IsSetIterator == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value13IsSetIteratorEv");
    ((void*&) _v8_Value_IsWeakMap) = hybris_dlsym(handle, "_ZNK2v85Value9IsWeakMapEv");
    if (_v8_Value_IsWeakMap == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9IsWeakMapEv");
    ((void*&) _v8_Value_IsWeakSet) = hybris_dlsym(handle, "_ZNK2v85Value9IsWeakSetEv");
    if (_v8_Value_IsWeakSet == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9IsWeakSetEv");
    ((void*&) _v8_Value_IsArrayBuffer) = hybris_dlsym(handle, "_ZNK2v85Value13IsArrayBufferEv");
    if (_v8_Value_IsArrayBuffer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value13IsArrayBufferEv");
    ((void*&) _v8_Value_IsArrayBufferView) = hybris_dlsym(handle, "_ZNK2v85Value17IsArrayBufferViewEv");
    if (_v8_Value_IsArrayBufferView == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value17IsArrayBufferViewEv");
    ((void*&) _v8_Value_IsTypedArray) = hybris_dlsym(handle, "_ZNK2v85Value12IsTypedArrayEv");
    if (_v8_Value_IsTypedArray == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12IsTypedArrayEv");
    ((void*&) _v8_Value_IsUint8Array) = hybris_dlsym(handle, "_ZNK2v85Value12IsUint8ArrayEv");
    if (_v8_Value_IsUint8Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12IsUint8ArrayEv");
    ((void*&) _v8_Value_IsUint8ClampedArray) = hybris_dlsym(handle, "_ZNK2v85Value19IsUint8ClampedArrayEv");
    if (_v8_Value_IsUint8ClampedArray == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value19IsUint8ClampedArrayEv");
    ((void*&) _v8_Value_IsInt8Array) = hybris_dlsym(handle, "_ZNK2v85Value11IsInt8ArrayEv");
    if (_v8_Value_IsInt8Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value11IsInt8ArrayEv");
    ((void*&) _v8_Value_IsUint16Array) = hybris_dlsym(handle, "_ZNK2v85Value13IsUint16ArrayEv");
    if (_v8_Value_IsUint16Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value13IsUint16ArrayEv");
    ((void*&) _v8_Value_IsInt16Array) = hybris_dlsym(handle, "_ZNK2v85Value12IsInt16ArrayEv");
    if (_v8_Value_IsInt16Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12IsInt16ArrayEv");
    ((void*&) _v8_Value_IsUint32Array) = hybris_dlsym(handle, "_ZNK2v85Value13IsUint32ArrayEv");
    if (_v8_Value_IsUint32Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value13IsUint32ArrayEv");
    ((void*&) _v8_Value_IsInt32Array) = hybris_dlsym(handle, "_ZNK2v85Value12IsInt32ArrayEv");
    if (_v8_Value_IsInt32Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12IsInt32ArrayEv");
    ((void*&) _v8_Value_IsFloat32Array) = hybris_dlsym(handle, "_ZNK2v85Value14IsFloat32ArrayEv");
    if (_v8_Value_IsFloat32Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value14IsFloat32ArrayEv");
    ((void*&) _v8_Value_IsFloat64Array) = hybris_dlsym(handle, "_ZNK2v85Value14IsFloat64ArrayEv");
    if (_v8_Value_IsFloat64Array == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value14IsFloat64ArrayEv");
    ((void*&) _v8_Value_IsDataView) = hybris_dlsym(handle, "_ZNK2v85Value10IsDataViewEv");
    if (_v8_Value_IsDataView == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value10IsDataViewEv");
    ((void*&) _v8_Value_IsSharedArrayBuffer) = hybris_dlsym(handle, "_ZNK2v85Value19IsSharedArrayBufferEv");
    if (_v8_Value_IsSharedArrayBuffer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value19IsSharedArrayBufferEv");
    ((void*&) _v8_Value_IsProxy) = hybris_dlsym(handle, "_ZNK2v85Value7IsProxyEv");
    if (_v8_Value_IsProxy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value7IsProxyEv");
    ((void*&) _v8_Value_IsWebAssemblyCompiledModule) = hybris_dlsym(handle, "_ZNK2v85Value27IsWebAssemblyCompiledModuleEv");
    if (_v8_Value_IsWebAssemblyCompiledModule == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value27IsWebAssemblyCompiledModuleEv");
    ((void*&) _v8_Value_ToBoolean) = hybris_dlsym(handle, "_ZNK2v85Value9ToBooleanEPNS_7IsolateE");
    if (_v8_Value_ToBoolean == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9ToBooleanEPNS_7IsolateE");
    ((void*&) _v8_Value_ToNumber) = hybris_dlsym(handle, "_ZNK2v85Value8ToNumberEPNS_7IsolateE");
    if (_v8_Value_ToNumber == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8ToNumberEPNS_7IsolateE");
    ((void*&) _v8_Value_ToString) = hybris_dlsym(handle, "_ZNK2v85Value8ToStringEPNS_7IsolateE");
    if (_v8_Value_ToString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8ToStringEPNS_7IsolateE");
    ((void*&) _v8_Value_ToObject) = hybris_dlsym(handle, "_ZNK2v85Value8ToObjectEPNS_7IsolateE");
    if (_v8_Value_ToObject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value8ToObjectEPNS_7IsolateE");
    ((void*&) _v8_Value_ToInteger) = hybris_dlsym(handle, "_ZNK2v85Value9ToIntegerEPNS_7IsolateE");
    if (_v8_Value_ToInteger == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9ToIntegerEPNS_7IsolateE");
    ((void*&) _v8_Value_ToInt32) = hybris_dlsym(handle, "_ZNK2v85Value7ToInt32EPNS_7IsolateE");
    if (_v8_Value_ToInt32 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value7ToInt32EPNS_7IsolateE");
    ((void*&) _v8_Value_BooleanValue) = hybris_dlsym(handle, "_ZNK2v85Value12BooleanValueEv");
    if (_v8_Value_BooleanValue == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12BooleanValueEv");
    ((void*&) _v8_Value_ToArrayIndex) = hybris_dlsym(handle, "_ZNK2v85Value12ToArrayIndexEv");
    if (_v8_Value_ToArrayIndex == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12ToArrayIndexEv");
    ((void*&) _v8_Value_Equals) = hybris_dlsym(handle, "_ZNK2v85Value6EqualsENS_5LocalINS_7ContextEEENS1_IS0_EE");
    if (_v8_Value_Equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value6EqualsENS_5LocalINS_7ContextEEENS1_IS0_EE");
    ((void*&) _v8_Value_Equals2) = hybris_dlsym(handle, "_ZNK2v85Value6EqualsENS_5LocalIS0_EE");
    if (_v8_Value_Equals2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value6EqualsENS_5LocalIS0_EE");
    ((void*&) _v8_Value_StrictEquals) = hybris_dlsym(handle, "_ZNK2v85Value12StrictEqualsENS_5LocalIS0_EE");
    if (_v8_Value_StrictEquals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12StrictEqualsENS_5LocalIS0_EE");
    ((void*&) _v8_Value_SameValue) = hybris_dlsym(handle, "_ZNK2v85Value9SameValueENS_5LocalIS0_EE");
    if (_v8_Value_SameValue == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value9SameValueENS_5LocalIS0_EE");
    ((void*&) _v8_Value_TypeOf) = hybris_dlsym(handle, "_ZN2v85Value6TypeOfEPNS_7IsolateE");
    if (_v8_Value_TypeOf == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v85Value6TypeOfEPNS_7IsolateE");
    ((void*&) _v8_Value_FullIsNull) = hybris_dlsym(handle, "_ZNK2v85Value10FullIsNullEv");
    if (_v8_Value_FullIsNull == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value10FullIsNullEv");
    ((void*&) _v8_Value_FullIsUndefined) = hybris_dlsym(handle, "_ZNK2v85Value15FullIsUndefinedEv");
    if (_v8_Value_FullIsUndefined == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value15FullIsUndefinedEv");
    ((void*&) _v8_Value_FullIsString) = hybris_dlsym(handle, "_ZNK2v85Value12FullIsStringEv");
    if (_v8_Value_FullIsString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Value12FullIsStringEv");
    ((void*&) _v8_Name_CheckCast) = hybris_dlsym(handle, "_ZN2v84Name9CheckCastEPNS_5ValueE");
    if (_v8_Name_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v84Name9CheckCastEPNS_5ValueE");
    ((void*&) _v8_String_Length) = hybris_dlsym(handle, "_ZNK2v86String6LengthEv");
    if (_v8_String_Length == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String6LengthEv");
    ((void*&) _v8_String_Utf8Length) = hybris_dlsym(handle, "_ZNK2v86String10Utf8LengthEv");
    if (_v8_String_Utf8Length == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String10Utf8LengthEv");
    ((void*&) _v8_String_IsOneByte) = hybris_dlsym(handle, "_ZNK2v86String9IsOneByteEv");
    if (_v8_String_IsOneByte == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String9IsOneByteEv");
    ((void*&) _v8_String_ContainsOnlyOneByte) = hybris_dlsym(handle, "_ZNK2v86String19ContainsOnlyOneByteEv");
    if (_v8_String_ContainsOnlyOneByte == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String19ContainsOnlyOneByteEv");
    ((void*&) _v8_String_IsExternal) = hybris_dlsym(handle, "_ZNK2v86String10IsExternalEv");
    if (_v8_String_IsExternal == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String10IsExternalEv");
    ((void*&) _v8_String_IsExternalOneByte) = hybris_dlsym(handle, "_ZNK2v86String17IsExternalOneByteEv");
    if (_v8_String_IsExternalOneByte == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String17IsExternalOneByteEv");
    ((void*&) _v8_String_NewFromUtf8) = hybris_dlsym(handle, "_ZN2v86String11NewFromUtf8EPNS_7IsolateEPKcNS_13NewStringTypeEi");
    if (_v8_String_NewFromUtf8 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86String11NewFromUtf8EPNS_7IsolateEPKcNS_13NewStringTypeEi");
    ((void*&) _v8_String_NewFromTwoByte) = hybris_dlsym(handle, "_ZN2v86String14NewFromTwoByteEPNS_7IsolateEPKtNS_13NewStringTypeEi");
    if (_v8_String_NewFromTwoByte == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86String14NewFromTwoByteEPNS_7IsolateEPKtNS_13NewStringTypeEi");
    ((void*&) _v8_String_Write) = hybris_dlsym(handle, "_ZNK2v86String5WriteEPtiii");
    if (_v8_String_Write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86String5WriteEPtiii");
    ((void*&) _v8_String_CheckCast) = hybris_dlsym(handle, "_ZN2v86String9CheckCastEPNS_5ValueE");
    if (_v8_String_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86String9CheckCastEPNS_5ValueE");
    ((void*&) _v8_String_Utf8Value_Utf8Value) = hybris_dlsym(handle, "_ZN2v86String9Utf8ValueC2ENS_5LocalINS_5ValueEEE");
    if (_v8_String_Utf8Value_Utf8Value == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86String9Utf8ValueC2ENS_5LocalINS_5ValueEEE");
    ((void*&) _v8_String_Utf8Value_destructor) = hybris_dlsym(handle, "_ZN2v86String9Utf8ValueD2Ev");
    if (_v8_String_Utf8Value_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86String9Utf8ValueD2Ev");
    ((void*&) _v8_Number_New) = hybris_dlsym(handle, "_ZN2v86Number3NewEPNS_7IsolateEd");
    if (_v8_Number_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Number3NewEPNS_7IsolateEd");
    ((void*&) _v8_Number_Value) = hybris_dlsym(handle, "_ZNK2v86Number5ValueEv");
    if (_v8_Number_Value == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v86Number5ValueEv");
    ((void*&) _v8_Number_CheckCast) = hybris_dlsym(handle, "_ZN2v86Number9CheckCastEPNS_5ValueE");
    if (_v8_Number_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Number9CheckCastEPNS_5ValueE");
    ((void*&) _v8_Integer_New) = hybris_dlsym(handle, "_ZN2v87Integer3NewEPNS_7IsolateEi");
    if (_v8_Integer_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Integer3NewEPNS_7IsolateEi");
    ((void*&) _v8_Integer_NewFromUnsigned) = hybris_dlsym(handle, "_ZN2v87Integer15NewFromUnsignedEPNS_7IsolateEj");
    if (_v8_Integer_NewFromUnsigned == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Integer15NewFromUnsignedEPNS_7IsolateEj");
    ((void*&) _v8_Integer_Value) = hybris_dlsym(handle, "_ZNK2v87Integer5ValueEv");
    if (_v8_Integer_Value == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v87Integer5ValueEv");
    ((void*&) _v8_Integer_CheckCast) = hybris_dlsym(handle, "_ZN2v87Integer9CheckCastEPNS_5ValueE");
    if (_v8_Integer_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Integer9CheckCastEPNS_5ValueE");
    ((void*&) _v8_Boolean_Value) = hybris_dlsym(handle, "_ZNK2v87Boolean5ValueEv");
    if (_v8_Boolean_Value == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v87Boolean5ValueEv");
    ((void*&) _v8_Boolean_CheckCast) = hybris_dlsym(handle, "_ZN2v87Boolean9CheckCastEPNS_5ValueE");
    if (_v8_Boolean_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Boolean9CheckCastEPNS_5ValueE");
    ((void*&) _v8_TryCatch_TryCatch) = hybris_dlsym(handle, "_ZN2v88TryCatchC2EPNS_7IsolateE");
    if (_v8_TryCatch_TryCatch == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88TryCatchC2EPNS_7IsolateE");
    ((void*&) _v8_TryCatch_destructor) = hybris_dlsym(handle, "_ZN2v88TryCatchD2Ev");
    if (_v8_TryCatch_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88TryCatchD2Ev");
    ((void*&) _v8_TryCatch_HasCaught) = hybris_dlsym(handle, "_ZNK2v88TryCatch9HasCaughtEv");
    if (_v8_TryCatch_HasCaught == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88TryCatch9HasCaughtEv");
    ((void*&) _v8_TryCatch_CanContinue) = hybris_dlsym(handle, "_ZNK2v88TryCatch11CanContinueEv");
    if (_v8_TryCatch_CanContinue == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88TryCatch11CanContinueEv");
    ((void*&) _v8_TryCatch_HasTerminated) = hybris_dlsym(handle, "_ZNK2v88TryCatch13HasTerminatedEv");
    if (_v8_TryCatch_HasTerminated == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88TryCatch13HasTerminatedEv");
    ((void*&) _v8_TryCatch_ReThrow) = hybris_dlsym(handle, "_ZN2v88TryCatch7ReThrowEv");
    if (_v8_TryCatch_ReThrow == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88TryCatch7ReThrowEv");
    ((void*&) _v8_TryCatch_Exception) = hybris_dlsym(handle, "_ZNK2v88TryCatch9ExceptionEv");
    if (_v8_TryCatch_Exception == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88TryCatch9ExceptionEv");
    ((void*&) _v8_TryCatch_StackTrace) = hybris_dlsym(handle, "_ZNK2v88TryCatch10StackTraceENS_5LocalINS_7ContextEEE");
    if (_v8_TryCatch_StackTrace == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88TryCatch10StackTraceENS_5LocalINS_7ContextEEE");
    ((void*&) _v8_TryCatch_Message) = hybris_dlsym(handle, "_ZNK2v88TryCatch7MessageEv");
    if (_v8_TryCatch_Message == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88TryCatch7MessageEv");
    ((void*&) _v8_TryCatch_Reset) = hybris_dlsym(handle, "_ZN2v88TryCatch5ResetEv");
    if (_v8_TryCatch_Reset == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88TryCatch5ResetEv");
    ((void*&) _v8_TryCatch_SetVerbose) = hybris_dlsym(handle, "_ZN2v88TryCatch10SetVerboseEb");
    if (_v8_TryCatch_SetVerbose == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88TryCatch10SetVerboseEb");
    ((void*&) _v8_TryCatch_SetCaptureMessage) = hybris_dlsym(handle, "_ZN2v88TryCatch17SetCaptureMessageEb");
    if (_v8_TryCatch_SetCaptureMessage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88TryCatch17SetCaptureMessageEb");
    ((void*&) _v8_Message_Get) = hybris_dlsym(handle, "_ZNK2v87Message3GetEv");
    if (_v8_Message_Get == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v87Message3GetEv");
    ((void*&) _v8_Isolate_ThrowException) = hybris_dlsym(handle, "_ZN2v87Isolate14ThrowExceptionENS_5LocalINS_5ValueEEE");
    if (_v8_Isolate_ThrowException == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate14ThrowExceptionENS_5LocalINS_5ValueEEE");
    ((void*&) _v8_Isolate_GetCurrent) = hybris_dlsym(handle, "_ZN2v87Isolate10GetCurrentEv");
    if (_v8_Isolate_GetCurrent == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate10GetCurrentEv");
    ((void*&) _v8_Isolate_GetCurrentContext) = hybris_dlsym(handle, "_ZN2v87Isolate17GetCurrentContextEv");
    if (_v8_Isolate_GetCurrentContext == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate17GetCurrentContextEv");
    ((void*&) _v8_Isolate_InContext) = hybris_dlsym(handle, "_ZN2v87Isolate9InContextEv");
    if (_v8_Isolate_InContext == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate9InContextEv");
    ((void*&) _v8_Isolate_Enter) = hybris_dlsym(handle, "_ZN2v87Isolate5EnterEv");
    if (_v8_Isolate_Enter == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate5EnterEv");
    ((void*&) _v8_Isolate_Exit) = hybris_dlsym(handle, "_ZN2v87Isolate4ExitEv");
    if (_v8_Isolate_Exit == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate4ExitEv");
    ((void*&) _v8_Isolate_RequestGarbageCollectionForTesting) = hybris_dlsym(handle, "_ZN2v87Isolate34RequestGarbageCollectionForTestingENS0_21GarbageCollectionTypeE");
    if (_v8_Isolate_RequestGarbageCollectionForTesting == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate34RequestGarbageCollectionForTestingENS0_21GarbageCollectionTypeE");
    ((void*&) _v8_Isolate_RunMicrotasks) = hybris_dlsym(handle, "_ZN2v87Isolate13RunMicrotasksEv");
    if (_v8_Isolate_RunMicrotasks == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Isolate13RunMicrotasksEv");
    ((void*&) _v8_Context_Enter) = hybris_dlsym(handle, "_ZN2v87Context5EnterEv");
    if (_v8_Context_Enter == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Context5EnterEv");
    ((void*&) _v8_Context_Exit) = hybris_dlsym(handle, "_ZN2v87Context4ExitEv");
    if (_v8_Context_Exit == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Context4ExitEv");
    ((void*&) _v8_Context_New) = hybris_dlsym(handle, "_ZN2v87Context3NewEPNS_7IsolateEPNS_22ExtensionConfigurationENS_10MaybeLocalINS_14ObjectTemplateEEENS5_INS_5ValueEEE");
    if (_v8_Context_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Context3NewEPNS_7IsolateEPNS_22ExtensionConfigurationENS_10MaybeLocalINS_14ObjectTemplateEEENS5_INS_5ValueEEE");
    ((void*&) _v8_Context_Global) = hybris_dlsym(handle, "_ZN2v87Context6GlobalEv");
    if (_v8_Context_Global == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Context6GlobalEv");
    ((void*&) _v8_HandleScope_HandleScope) = hybris_dlsym(handle, "_ZN2v811HandleScopeC2EPNS_7IsolateE");
    if (_v8_HandleScope_HandleScope == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v811HandleScopeC2EPNS_7IsolateE");
    ((void*&) _v8_HandleScope_destructor) = hybris_dlsym(handle, "_ZN2v811HandleScopeD2Ev");
    if (_v8_HandleScope_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v811HandleScopeD2Ev");
    ((void*&) _v8_EscapableHandleScope_EscapableHandleScope) = hybris_dlsym(handle, "_ZN2v820EscapableHandleScopeC2EPNS_7IsolateE");
    if (_v8_EscapableHandleScope_EscapableHandleScope == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v820EscapableHandleScopeC2EPNS_7IsolateE");
    ((void*&) _v8_Object_New) = hybris_dlsym(handle, "_ZN2v86Object3NewEPNS_7IsolateE");
    if (_v8_Object_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object3NewEPNS_7IsolateE");
    ((void*&) _v8_Object_Set) = hybris_dlsym(handle, "_ZN2v86Object3SetEjNS_5LocalINS_5ValueEEE");
    if (_v8_Object_Set == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object3SetEjNS_5LocalINS_5ValueEEE");
    ((void*&) _v8_Object_Set2) = hybris_dlsym(handle, "_ZN2v86Object3SetENS_5LocalINS_5ValueEEES3_");
    if (_v8_Object_Set2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object3SetENS_5LocalINS_5ValueEEES3_");
    ((void*&) _v8_Object_Get) = hybris_dlsym(handle, "_ZN2v86Object3GetEj");
    if (_v8_Object_Get == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object3GetEj");
    ((void*&) _v8_Object_Get2) = hybris_dlsym(handle, "_ZN2v86Object3GetENS_5LocalINS_5ValueEEE");
    if (_v8_Object_Get2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object3GetENS_5LocalINS_5ValueEEE");
    ((void*&) _v8_Object_Has) = hybris_dlsym(handle, "_ZN2v86Object3HasENS_5LocalINS_5ValueEEE");
    if (_v8_Object_Has == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object3HasENS_5LocalINS_5ValueEEE");
    ((void*&) _v8_Object_SetInternalField) = hybris_dlsym(handle, "_ZN2v86Object16SetInternalFieldEiNS_5LocalINS_5ValueEEE");
    if (_v8_Object_SetInternalField == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object16SetInternalFieldEiNS_5LocalINS_5ValueEEE");
    ((void*&) _v8_Object_SetAlignedPointerInInternalField) = hybris_dlsym(handle, "_ZN2v86Object32SetAlignedPointerInInternalFieldEiPv");
    if (_v8_Object_SetAlignedPointerInInternalField == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object32SetAlignedPointerInInternalFieldEiPv");
    ((void*&) _v8_Object_GetInternalField) = hybris_dlsym(handle, "_ZN2v86Object20SlowGetInternalFieldEi");
    if (_v8_Object_GetInternalField == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object20SlowGetInternalFieldEi");
    ((void*&) _v8_Object_GetAlignedPointerFromInternalField) = hybris_dlsym(handle, "_ZN2v86Object38SlowGetAlignedPointerFromInternalFieldEi");
    if (_v8_Object_GetAlignedPointerFromInternalField == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object38SlowGetAlignedPointerFromInternalFieldEi");
    ((void*&) _v8_Object_GetOwnPropertyNames) = hybris_dlsym(handle, "_ZN2v86Object19GetOwnPropertyNamesENS_5LocalINS_7ContextEEE");
    if (_v8_Object_GetOwnPropertyNames == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object19GetOwnPropertyNamesENS_5LocalINS_7ContextEEE");
    ((void*&) _v8_Object_GetOwnPropertyNames2) = hybris_dlsym(handle, "_ZN2v86Object19GetOwnPropertyNamesENS_5LocalINS_7ContextEEENS_14PropertyFilterE");
    if (_v8_Object_GetOwnPropertyNames2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object19GetOwnPropertyNamesENS_5LocalINS_7ContextEEENS_14PropertyFilterE");
    ((void*&) _v8_Object_CheckCast) = hybris_dlsym(handle, "_ZN2v86Object9CheckCastEPNS_5ValueE");
    if (_v8_Object_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v86Object9CheckCastEPNS_5ValueE");
    ((void*&) _v8_Array_New) = hybris_dlsym(handle, "_ZN2v85Array3NewEPNS_7IsolateEi");
    if (_v8_Array_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v85Array3NewEPNS_7IsolateEi");
    ((void*&) _v8_Array_Length) = hybris_dlsym(handle, "_ZNK2v85Array6LengthEv");
    if (_v8_Array_Length == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v85Array6LengthEv");
    ((void*&) _v8_Array_CheckCast) = hybris_dlsym(handle, "_ZN2v85Array9CheckCastEPNS_5ValueE");
    if (_v8_Array_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v85Array9CheckCastEPNS_5ValueE");
    ((void*&) _v8_ArrayBuffer_GetContents) = hybris_dlsym(handle, "_ZN2v811ArrayBuffer11GetContentsEv");
    if (_v8_ArrayBuffer_GetContents == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v811ArrayBuffer11GetContentsEv");
    ((void*&) _v8_ArrayBuffer_New) = hybris_dlsym(handle, "_ZN2v811ArrayBuffer3NewEPNS_7IsolateEj");
    if (_v8_ArrayBuffer_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v811ArrayBuffer3NewEPNS_7IsolateEj");
    ((void*&) _v8_ArrayBuffer_CheckCast) = hybris_dlsym(handle, "_ZN2v811ArrayBuffer9CheckCastEPNS_5ValueE");
    if (_v8_ArrayBuffer_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v811ArrayBuffer9CheckCastEPNS_5ValueE");
    ((void*&) _v8_Function_Call) = hybris_dlsym(handle, "_ZN2v88Function4CallENS_5LocalINS_5ValueEEEiPS3_");
    if (_v8_Function_Call == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88Function4CallENS_5LocalINS_5ValueEEEiPS3_");
    ((void*&) _v8_Function_NewInstance) = hybris_dlsym(handle, "_ZNK2v88Function11NewInstanceENS_5LocalINS_7ContextEEEiPNS1_INS_5ValueEEE");
    if (_v8_Function_NewInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK2v88Function11NewInstanceENS_5LocalINS_7ContextEEEiPNS1_INS_5ValueEEE");
    ((void*&) _v8_Function_New) = hybris_dlsym(handle, "_ZN2v88Function3NewEPNS_7IsolateEPFvRKNS_20FunctionCallbackInfoINS_5ValueEEEENS_5LocalIS4_EEi");
    if (_v8_Function_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88Function3NewEPNS_7IsolateEPFvRKNS_20FunctionCallbackInfoINS_5ValueEEEENS_5LocalIS4_EEi");
    ((void*&) _v8_Function_CheckCast) = hybris_dlsym(handle, "_ZN2v88Function9CheckCastEPNS_5ValueE");
    if (_v8_Function_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88Function9CheckCastEPNS_5ValueE");
    ((void*&) _v8_Template_Set) = hybris_dlsym(handle, "_ZN2v88Template3SetENS_5LocalINS_4NameEEENS1_INS_4DataEEENS_17PropertyAttributeE");
    if (_v8_Template_Set == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88Template3SetENS_5LocalINS_4NameEEENS1_INS_4DataEEENS_17PropertyAttributeE");
    ((void*&) _v8_Template_SetAccessorProperty) = hybris_dlsym(handle, "_ZN2v88Template19SetAccessorPropertyENS_5LocalINS_4NameEEENS1_INS_16FunctionTemplateEEES5_NS_17PropertyAttributeENS_13AccessControlE");
    if (_v8_Template_SetAccessorProperty == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v88Template19SetAccessorPropertyENS_5LocalINS_4NameEEENS1_INS_16FunctionTemplateEEES5_NS_17PropertyAttributeENS_13AccessControlE");
    ((void*&) _v8_FunctionTemplate_New) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate3NewEPNS_7IsolateEPFvRKNS_20FunctionCallbackInfoINS_5ValueEEEENS_5LocalIS4_EENSA_INS_9SignatureEEEiNS_19ConstructorBehaviorE");
    if (_v8_FunctionTemplate_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate3NewEPNS_7IsolateEPFvRKNS_20FunctionCallbackInfoINS_5ValueEEEENS_5LocalIS4_EENSA_INS_9SignatureEEEiNS_19ConstructorBehaviorE");
    ((void*&) _v8_FunctionTemplate_Inherit) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate7InheritENS_5LocalIS0_EE");
    if (_v8_FunctionTemplate_Inherit == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate7InheritENS_5LocalIS0_EE");
    ((void*&) _v8_FunctionTemplate_SetClassName) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate12SetClassNameENS_5LocalINS_6StringEEE");
    if (_v8_FunctionTemplate_SetClassName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate12SetClassNameENS_5LocalINS_6StringEEE");
    ((void*&) _v8_FunctionTemplate_PrototypeTemplate) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate17PrototypeTemplateEv");
    if (_v8_FunctionTemplate_PrototypeTemplate == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate17PrototypeTemplateEv");
    ((void*&) _v8_FunctionTemplate_InstanceTemplate) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate16InstanceTemplateEv");
    if (_v8_FunctionTemplate_InstanceTemplate == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate16InstanceTemplateEv");
    ((void*&) _v8_FunctionTemplate_GetFunction) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate11GetFunctionENS_5LocalINS_7ContextEEE");
    if (_v8_FunctionTemplate_GetFunction == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate11GetFunctionENS_5LocalINS_7ContextEEE");
    ((void*&) _v8_FunctionTemplate_HasInstance) = hybris_dlsym(handle, "_ZN2v816FunctionTemplate11HasInstanceENS_5LocalINS_5ValueEEE");
    if (_v8_FunctionTemplate_HasInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v816FunctionTemplate11HasInstanceENS_5LocalINS_5ValueEEE");
    ((void*&) _v8_ObjectTemplate_NewInstance) = hybris_dlsym(handle, "_ZN2v814ObjectTemplate11NewInstanceENS_5LocalINS_7ContextEEE");
    if (_v8_ObjectTemplate_NewInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v814ObjectTemplate11NewInstanceENS_5LocalINS_7ContextEEE");
    ((void*&) _v8_ObjectTemplate_SetImmutableProto) = hybris_dlsym(handle, "_ZN2v814ObjectTemplate17SetImmutableProtoEv");
    if (_v8_ObjectTemplate_SetImmutableProto == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v814ObjectTemplate17SetImmutableProtoEv");
    ((void*&) _v8_ObjectTemplate_SetInternalFieldCount) = hybris_dlsym(handle, "_ZN2v814ObjectTemplate21SetInternalFieldCountEi");
    if (_v8_ObjectTemplate_SetInternalFieldCount == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v814ObjectTemplate21SetInternalFieldCountEi");
    ((void*&) _v8_ObjectTemplate_New) = hybris_dlsym(handle, "_ZN2v814ObjectTemplate3NewEPNS_7IsolateENS_5LocalINS_16FunctionTemplateEEE");
    if (_v8_ObjectTemplate_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v814ObjectTemplate3NewEPNS_7IsolateENS_5LocalINS_16FunctionTemplateEEE");
    ((void*&) _v8_Exception_RangeError) = hybris_dlsym(handle, "_ZN2v89Exception10RangeErrorENS_5LocalINS_6StringEEE");
    if (_v8_Exception_RangeError == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v89Exception10RangeErrorENS_5LocalINS_6StringEEE");
    ((void*&) _v8_Exception_ReferenceError) = hybris_dlsym(handle, "_ZN2v89Exception14ReferenceErrorENS_5LocalINS_6StringEEE");
    if (_v8_Exception_ReferenceError == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v89Exception14ReferenceErrorENS_5LocalINS_6StringEEE");
    ((void*&) _v8_Exception_SyntaxError) = hybris_dlsym(handle, "_ZN2v89Exception11SyntaxErrorENS_5LocalINS_6StringEEE");
    if (_v8_Exception_SyntaxError == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v89Exception11SyntaxErrorENS_5LocalINS_6StringEEE");
    ((void*&) _v8_Exception_TypeError) = hybris_dlsym(handle, "_ZN2v89Exception9TypeErrorENS_5LocalINS_6StringEEE");
    if (_v8_Exception_TypeError == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v89Exception9TypeErrorENS_5LocalINS_6StringEEE");
    ((void*&) _v8_Exception_Error) = hybris_dlsym(handle, "_ZN2v89Exception5ErrorENS_5LocalINS_6StringEEE");
    if (_v8_Exception_Error == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v89Exception5ErrorENS_5LocalINS_6StringEEE");
    ((void*&) _v8_Exception_CreateMessage) = hybris_dlsym(handle, "_ZN2v89Exception13CreateMessageEPNS_7IsolateENS_5LocalINS_5ValueEEE");
    if (_v8_Exception_CreateMessage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v89Exception13CreateMessageEPNS_7IsolateENS_5LocalINS_5ValueEEE");
    ((void*&) _v8_Promise_Resolver_New) = hybris_dlsym(handle, "_ZN2v87Promise8Resolver3NewENS_5LocalINS_7ContextEEE");
    if (_v8_Promise_Resolver_New == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Promise8Resolver3NewENS_5LocalINS_7ContextEEE");
    ((void*&) _v8_Promise_Resolver_Resolve) = hybris_dlsym(handle, "_ZN2v87Promise8Resolver7ResolveENS_5LocalINS_7ContextEEENS2_INS_5ValueEEE");
    if (_v8_Promise_Resolver_Resolve == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Promise8Resolver7ResolveENS_5LocalINS_7ContextEEENS2_INS_5ValueEEE");
    ((void*&) _v8_Promise_Resolver_Reject) = hybris_dlsym(handle, "_ZN2v87Promise8Resolver6RejectENS_5LocalINS_7ContextEEENS2_INS_5ValueEEE");
    if (_v8_Promise_Resolver_Reject == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Promise8Resolver6RejectENS_5LocalINS_7ContextEEENS2_INS_5ValueEEE");
    ((void*&) _v8_Promise_Resolver_GetPromise) = hybris_dlsym(handle, "_ZN2v87Promise8Resolver10GetPromiseEv");
    if (_v8_Promise_Resolver_GetPromise == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Promise8Resolver10GetPromiseEv");
    ((void*&) _v8_Promise_Resolver_CheckCast) = hybris_dlsym(handle, "_ZN2v87Promise8Resolver9CheckCastEPNS_5ValueE");
    if (_v8_Promise_Resolver_CheckCast == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2v87Promise8Resolver9CheckCastEPNS_5ValueE");
    ((void*&) _ServerCommandOrigin_ServerCommandOrigin) = hybris_dlsym(handle, "_ZN19ServerCommandOriginC2ERKSsR11ServerLevel");
    if (_ServerCommandOrigin_ServerCommandOrigin == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ServerCommandOriginC2ERKSsR11ServerLevel");
    void** vt_PlayerCommandOrigin = (void**) hybris_dlsym(handle, "_ZTV19PlayerCommandOrigin") + 2;
    vti_CommandOrigin_getName = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin7getNameEv"));
    if (vti_CommandOrigin_getName == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin7getNameEv");
    vti_CommandOrigin_getBlockPosition = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin16getBlockPositionEv"));
    if (vti_CommandOrigin_getBlockPosition == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin16getBlockPositionEv");
    vti_CommandOrigin_getWorldPosition = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin16getWorldPositionEv"));
    if (vti_CommandOrigin_getWorldPosition == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin16getWorldPositionEv");
    vti_CommandOrigin_clone = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin5cloneEv"));
    if (vti_CommandOrigin_clone == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin5cloneEv");
    vti_CommandOrigin_getOriginType = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin13getOriginTypeEv"));
    if (vti_CommandOrigin_getOriginType == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin13getOriginTypeEv");
    vti_CommandOrigin_getEntity = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin9getEntityEv"));
    if (vti_CommandOrigin_getEntity == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin9getEntityEv");
    vti_CommandOrigin_getPermissionLevel = resolve_vtable_func(vt_PlayerCommandOrigin, hybris_dlsym(handle, "_ZNK19PlayerCommandOrigin19getPermissionsLevelEv"));
    if (vti_CommandOrigin_getPermissionLevel == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZNK19PlayerCommandOrigin19getPermissionsLevelEv");
    ((void*&) _CommandOrigin_getUUID) = hybris_dlsym(handle, "_ZNK13CommandOrigin7getUUIDEv");
    if (_CommandOrigin_getUUID == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK13CommandOrigin7getUUIDEv");
    ((void*&) _PlayerCommandOrigin_PlayerCommandOrigin) = hybris_dlsym(handle, "_ZN19PlayerCommandOriginC2ER6Player");
    if (_PlayerCommandOrigin_PlayerCommandOrigin == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19PlayerCommandOriginC2ER6Player");
    ((void*&) _gl_getOpenGLVendor) = hybris_dlsym(handle, "_ZN2gl15getOpenGLVendorEv");
    if (_gl_getOpenGLVendor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2gl15getOpenGLVendorEv");
    ((void*&) _gl_getOpenGLRenderer) = hybris_dlsym(handle, "_ZN2gl17getOpenGLRendererEv");
    if (_gl_getOpenGLRenderer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2gl17getOpenGLRendererEv");
    ((void*&) _gl_getOpenGLVersion) = hybris_dlsym(handle, "_ZN2gl16getOpenGLVersionEv");
    if (_gl_getOpenGLVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2gl16getOpenGLVersionEv");
    ((void*&) _gl_getOpenGLExtensions) = hybris_dlsym(handle, "_ZN2gl19getOpenGLExtensionsEv");
    if (_gl_getOpenGLExtensions == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN2gl19getOpenGLExtensionsEv");
    ((void*&) _mce_Platform_OGL_InitBindings) = hybris_dlsym(handle, "_ZN3mce8Platform3OGL12InitBindingsEv");
    if (_mce_Platform_OGL_InitBindings == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3mce8Platform3OGL12InitBindingsEv");
    ((void*&) ModalFormRequestPacket::myVtable) = hybris_dlsym(handle, "_ZTV22ModalFormRequestPacket");
    if (ModalFormRequestPacket::myVtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV22ModalFormRequestPacket");
    ((void*&) ModalFormResponsePacket::myVtable) = hybris_dlsym(handle, "_ZTV23ModalFormResponsePacket");
    if (ModalFormResponsePacket::myVtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV23ModalFormResponsePacket");
    ((void*&) _ScriptEngine_fireEventToScript) = hybris_dlsym(handle, "_ZN12ScriptEngine17fireEventToScriptERK9EventInfoRKN9ScriptApi18ScriptObjectHandleE");
    if (_ScriptEngine_fireEventToScript == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN12ScriptEngine17fireEventToScriptERK9EventInfoRKN9ScriptApi18ScriptObjectHandleE");
    ((void*&) _ScriptEngine_deserializeScriptObjectHandleToJson) = hybris_dlsym(handle, "_ZN12ScriptEngine35deserializeScriptObjectHandleToJsonERKN9ScriptApi18ScriptObjectHandleERN4Json5ValueE");
    if (_ScriptEngine_deserializeScriptObjectHandleToJson == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN12ScriptEngine35deserializeScriptObjectHandleToJsonERKN9ScriptApi18ScriptObjectHandleERN4Json5ValueE");
    ((void*&) _ScriptEngine_serializeJsonToScriptObjectHandle) = hybris_dlsym(handle, "_ZN12ScriptEngine33serializeJsonToScriptObjectHandleERN9ScriptApi18ScriptObjectHandleERKN4Json5ValueE");
    if (_ScriptEngine_serializeJsonToScriptObjectHandle == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN12ScriptEngine33serializeJsonToScriptObjectHandleERN9ScriptApi18ScriptObjectHandleERKN4Json5ValueE");
    ((void*&) _MinecraftServerScriptEngine_helpDefineActor) = hybris_dlsym(handle, "_ZN23ScriptEngineWithContextI19ScriptServerContextE15helpDefineActorERK5ActorRN9ScriptApi18ScriptObjectHandleE");
    if (_MinecraftServerScriptEngine_helpDefineActor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN23ScriptEngineWithContextI19ScriptServerContextE15helpDefineActorERK5ActorRN9ScriptApi18ScriptObjectHandleE");
    ((void*&) _MinecraftServerScriptEngine_helpGetActor) = hybris_dlsym(handle, "_ZN23ScriptEngineWithContextI19ScriptServerContextE12helpGetActorERKN9ScriptApi18ScriptObjectHandleEPP5Actor");
    if (_MinecraftServerScriptEngine_helpGetActor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN23ScriptEngineWithContextI19ScriptServerContextE12helpGetActorERKN9ScriptApi18ScriptObjectHandleEPP5Actor");
    ((void*&) _MinecraftServerScriptEngine_isValidEntity) = hybris_dlsym(handle, "_ZN23ScriptEngineWithContextI19ScriptClientContextE13isValidEntityERKN9ScriptApi17ScriptVersionInfoERKNS2_18ScriptObjectHandleERb");
    if (_MinecraftServerScriptEngine_isValidEntity == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN23ScriptEngineWithContextI19ScriptClientContextE13isValidEntityERKN9ScriptApi17ScriptVersionInfoERKNS2_18ScriptObjectHandleERb");
    ((void*&) _ScriptEventData_ScriptEventData) = hybris_dlsym(handle, "_ZN15ScriptEventDataC2ERKSs");
    if (_ScriptEventData_ScriptEventData == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15ScriptEventDataC2ERKSs");
    ((void*&) _ScriptEventData_destructor) = hybris_dlsym(handle, "_ZN15ScriptEventDataD2Ev");
    if (_ScriptEventData_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15ScriptEventDataD2Ev");
    ((void*&) _ScriptEventData_serialize) = hybris_dlsym(handle, "_ZNK15ScriptEventData9serializeER12ScriptEngineR9EventInfoRN9ScriptApi18ScriptObjectHandleE");
    if (_ScriptEventData_serialize == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15ScriptEventData9serializeER12ScriptEngineR9EventInfoRN9ScriptApi18ScriptObjectHandleE");
    ((void*&) GameMode::vtable) = hybris_dlsym(handle, "_ZTV8GameMode");
    if (GameMode::vtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV8GameMode");
    ((void*&) _GameMode_destructor) = hybris_dlsym(handle, "_ZN8GameModeD2Ev");
    if (_GameMode_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8GameModeD2Ev");
    ((void*&) _Multitouch_feed) = hybris_dlsym(handle, "_ZN10Multitouch4feedEccssi");
    if (_Multitouch_feed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10Multitouch4feedEccssi");
    ((void*&) _Tag_destructor) = hybris_dlsym(handle, "_ZN3TagD2Ev");
    if (_Tag_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3TagD2Ev");
    ((void*&) _Tag_deleteChildren) = hybris_dlsym(handle, "_ZN3Tag14deleteChildrenEv");
    if (_Tag_deleteChildren == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3Tag14deleteChildrenEv");
    ((void*&) _Tag_equals) = hybris_dlsym(handle, "_ZNK3Tag6equalsERKS_");
    if (_Tag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3Tag6equalsERKS_");
    ((void*&) _Tag_print) = hybris_dlsym(handle, "_ZNK3Tag5printER11PrintStream");
    if (_Tag_print == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3Tag5printER11PrintStream");
    ((void*&) _Tag_print2) = hybris_dlsym(handle, "_ZNK3Tag5printERKSsR11PrintStream");
    if (_Tag_print2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3Tag5printERKSsR11PrintStream");
    ((void*&) _Tag_setName) = hybris_dlsym(handle, "_ZN3Tag7setNameERKSs");
    if (_Tag_setName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3Tag7setNameERKSs");
    ((void*&) _Tag_getName) = hybris_dlsym(handle, "_ZNK3Tag7getNameEv");
    if (_Tag_getName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3Tag7getNameEv");
    ((void*&) EndTag::vt) = hybris_dlsym(handle, "_ZTV6EndTag");
    if (EndTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV6EndTag");
    ((void*&) _EndTag_write) = hybris_dlsym(handle, "_ZNK6EndTag5writeER11IDataOutput");
    if (_EndTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6EndTag5writeER11IDataOutput");
    ((void*&) _EndTag_load) = hybris_dlsym(handle, "_ZN6EndTag4loadER10IDataInput");
    if (_EndTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6EndTag4loadER10IDataInput");
    ((void*&) _EndTag_toString) = hybris_dlsym(handle, "_ZNK6EndTag8toStringEv");
    if (_EndTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6EndTag8toStringEv");
    ((void*&) _EndTag_getId) = hybris_dlsym(handle, "_ZNK6EndTag5getIdEv");
    if (_EndTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6EndTag5getIdEv");
    ((void*&) _EndTag_equals) = hybris_dlsym(handle, "_ZNK6EndTag6equalsERK3Tag");
    if (_EndTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6EndTag6equalsERK3Tag");
    ((void*&) _EndTag_copy) = hybris_dlsym(handle, "_ZNK6EndTag4copyEv");
    if (_EndTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6EndTag4copyEv");
    ((void*&) DoubleTag::vt) = hybris_dlsym(handle, "_ZTV9DoubleTag");
    if (DoubleTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV9DoubleTag");
    ((void*&) _DoubleTag_write) = hybris_dlsym(handle, "_ZNK9DoubleTag5writeER11IDataOutput");
    if (_DoubleTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9DoubleTag5writeER11IDataOutput");
    ((void*&) _DoubleTag_load) = hybris_dlsym(handle, "_ZN9DoubleTag4loadER10IDataInput");
    if (_DoubleTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9DoubleTag4loadER10IDataInput");
    ((void*&) _DoubleTag_toString) = hybris_dlsym(handle, "_ZNK9DoubleTag8toStringEv");
    if (_DoubleTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9DoubleTag8toStringEv");
    ((void*&) _DoubleTag_getId) = hybris_dlsym(handle, "_ZNK9DoubleTag5getIdEv");
    if (_DoubleTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9DoubleTag5getIdEv");
    ((void*&) _DoubleTag_equals) = hybris_dlsym(handle, "_ZNK9DoubleTag6equalsERK3Tag");
    if (_DoubleTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9DoubleTag6equalsERK3Tag");
    ((void*&) _DoubleTag_copy) = hybris_dlsym(handle, "_ZNK9DoubleTag4copyEv");
    if (_DoubleTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9DoubleTag4copyEv");
    ((void*&) ByteArrayTag::vt) = hybris_dlsym(handle, "_ZTV12ByteArrayTag");
    if (ByteArrayTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV12ByteArrayTag");
    ((void*&) _ByteArrayTag_write) = hybris_dlsym(handle, "_ZNK12ByteArrayTag5writeER11IDataOutput");
    if (_ByteArrayTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ByteArrayTag5writeER11IDataOutput");
    ((void*&) _ByteArrayTag_load) = hybris_dlsym(handle, "_ZN12ByteArrayTag4loadER10IDataInput");
    if (_ByteArrayTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN12ByteArrayTag4loadER10IDataInput");
    ((void*&) _ByteArrayTag_toString) = hybris_dlsym(handle, "_ZNK12ByteArrayTag8toStringEv");
    if (_ByteArrayTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ByteArrayTag8toStringEv");
    ((void*&) _ByteArrayTag_getId) = hybris_dlsym(handle, "_ZNK12ByteArrayTag5getIdEv");
    if (_ByteArrayTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ByteArrayTag5getIdEv");
    ((void*&) _ByteArrayTag_equals) = hybris_dlsym(handle, "_ZNK12ByteArrayTag6equalsERK3Tag");
    if (_ByteArrayTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ByteArrayTag6equalsERK3Tag");
    ((void*&) _ByteArrayTag_copy) = hybris_dlsym(handle, "_ZNK12ByteArrayTag4copyEv");
    if (_ByteArrayTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ByteArrayTag4copyEv");
    ((void*&) CompoundTag::vt) = hybris_dlsym(handle, "_ZTV11CompoundTag");
    if (CompoundTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV11CompoundTag");
    ((void*&) _CompoundTag_write) = hybris_dlsym(handle, "_ZNK11CompoundTag5writeER11IDataOutput");
    if (_CompoundTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11CompoundTag5writeER11IDataOutput");
    ((void*&) _CompoundTag_load) = hybris_dlsym(handle, "_ZN11CompoundTag4loadER10IDataInput");
    if (_CompoundTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11CompoundTag4loadER10IDataInput");
    ((void*&) _CompoundTag_toString) = hybris_dlsym(handle, "_ZNK11CompoundTag8toStringEv");
    if (_CompoundTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11CompoundTag8toStringEv");
    ((void*&) _CompoundTag_getId) = hybris_dlsym(handle, "_ZNK11CompoundTag5getIdEv");
    if (_CompoundTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11CompoundTag5getIdEv");
    ((void*&) _CompoundTag_equals) = hybris_dlsym(handle, "_ZNK11CompoundTag6equalsERK3Tag");
    if (_CompoundTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11CompoundTag6equalsERK3Tag");
    ((void*&) _CompoundTag_print) = hybris_dlsym(handle, "_ZNK11CompoundTag5printERKSsR11PrintStream");
    if (_CompoundTag_print == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11CompoundTag5printERKSsR11PrintStream");
    ((void*&) _CompoundTag_copy) = hybris_dlsym(handle, "_ZNK11CompoundTag4copyEv");
    if (_CompoundTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11CompoundTag4copyEv");
    ((void*&) ListTag::vt) = hybris_dlsym(handle, "_ZTV7ListTag");
    if (ListTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV7ListTag");
    ((void*&) _ListTag_deleteChildren) = hybris_dlsym(handle, "_ZN7ListTag14deleteChildrenEv");
    if (_ListTag_deleteChildren == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7ListTag14deleteChildrenEv");
    ((void*&) _ListTag_write) = hybris_dlsym(handle, "_ZNK7ListTag5writeER11IDataOutput");
    if (_ListTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ListTag5writeER11IDataOutput");
    ((void*&) _ListTag_load) = hybris_dlsym(handle, "_ZN7ListTag4loadER10IDataInput");
    if (_ListTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7ListTag4loadER10IDataInput");
    ((void*&) _ListTag_toString) = hybris_dlsym(handle, "_ZNK7ListTag8toStringEv");
    if (_ListTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ListTag8toStringEv");
    ((void*&) _ListTag_getId) = hybris_dlsym(handle, "_ZNK7ListTag5getIdEv");
    if (_ListTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ListTag5getIdEv");
    ((void*&) _ListTag_equals) = hybris_dlsym(handle, "_ZNK7ListTag6equalsERK3Tag");
    if (_ListTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ListTag6equalsERK3Tag");
    ((void*&) _ListTag_print) = hybris_dlsym(handle, "_ZNK7ListTag5printERKSsR11PrintStream");
    if (_ListTag_print == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ListTag5printERKSsR11PrintStream");
    ((void*&) _ListTag_copy) = hybris_dlsym(handle, "_ZNK7ListTag4copyEv");
    if (_ListTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ListTag4copyEv");
    ((void*&) FloatTag::vt) = hybris_dlsym(handle, "_ZTV8FloatTag");
    if (FloatTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV8FloatTag");
    ((void*&) _FloatTag_write) = hybris_dlsym(handle, "_ZNK8FloatTag5writeER11IDataOutput");
    if (_FloatTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8FloatTag5writeER11IDataOutput");
    ((void*&) _FloatTag_load) = hybris_dlsym(handle, "_ZN8FloatTag4loadER10IDataInput");
    if (_FloatTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8FloatTag4loadER10IDataInput");
    ((void*&) _FloatTag_toString) = hybris_dlsym(handle, "_ZNK8FloatTag8toStringEv");
    if (_FloatTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8FloatTag8toStringEv");
    ((void*&) _FloatTag_getId) = hybris_dlsym(handle, "_ZNK8FloatTag5getIdEv");
    if (_FloatTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8FloatTag5getIdEv");
    ((void*&) _FloatTag_equals) = hybris_dlsym(handle, "_ZNK8FloatTag6equalsERK3Tag");
    if (_FloatTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8FloatTag6equalsERK3Tag");
    ((void*&) _FloatTag_copy) = hybris_dlsym(handle, "_ZNK8FloatTag4copyEv");
    if (_FloatTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8FloatTag4copyEv");
    ((void*&) ByteTag::vt) = hybris_dlsym(handle, "_ZTV7ByteTag");
    if (ByteTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV7ByteTag");
    ((void*&) _ByteTag_write) = hybris_dlsym(handle, "_ZNK7ByteTag5writeER11IDataOutput");
    if (_ByteTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ByteTag5writeER11IDataOutput");
    ((void*&) _ByteTag_load) = hybris_dlsym(handle, "_ZN7ByteTag4loadER10IDataInput");
    if (_ByteTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7ByteTag4loadER10IDataInput");
    ((void*&) _ByteTag_toString) = hybris_dlsym(handle, "_ZNK7ByteTag8toStringEv");
    if (_ByteTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ByteTag8toStringEv");
    ((void*&) _ByteTag_getId) = hybris_dlsym(handle, "_ZNK7ByteTag5getIdEv");
    if (_ByteTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ByteTag5getIdEv");
    ((void*&) _ByteTag_equals) = hybris_dlsym(handle, "_ZNK7ByteTag6equalsERK3Tag");
    if (_ByteTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ByteTag6equalsERK3Tag");
    ((void*&) _ByteTag_copy) = hybris_dlsym(handle, "_ZNK7ByteTag4copyEv");
    if (_ByteTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7ByteTag4copyEv");
    ((void*&) ShortTag::vt) = hybris_dlsym(handle, "_ZTV8ShortTag");
    if (ShortTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV8ShortTag");
    ((void*&) _ShortTag_write) = hybris_dlsym(handle, "_ZNK8ShortTag5writeER11IDataOutput");
    if (_ShortTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8ShortTag5writeER11IDataOutput");
    ((void*&) _ShortTag_load) = hybris_dlsym(handle, "_ZN8ShortTag4loadER10IDataInput");
    if (_ShortTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8ShortTag4loadER10IDataInput");
    ((void*&) _ShortTag_toString) = hybris_dlsym(handle, "_ZNK8ShortTag8toStringEv");
    if (_ShortTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8ShortTag8toStringEv");
    ((void*&) _ShortTag_getId) = hybris_dlsym(handle, "_ZNK8ShortTag5getIdEv");
    if (_ShortTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8ShortTag5getIdEv");
    ((void*&) _ShortTag_equals) = hybris_dlsym(handle, "_ZNK8ShortTag6equalsERK3Tag");
    if (_ShortTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8ShortTag6equalsERK3Tag");
    ((void*&) _ShortTag_copy) = hybris_dlsym(handle, "_ZNK8ShortTag4copyEv");
    if (_ShortTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8ShortTag4copyEv");
    ((void*&) Int64Tag::vt) = hybris_dlsym(handle, "_ZTV8Int64Tag");
    if (Int64Tag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV8Int64Tag");
    ((void*&) _Int64Tag_write) = hybris_dlsym(handle, "_ZNK8Int64Tag5writeER11IDataOutput");
    if (_Int64Tag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8Int64Tag5writeER11IDataOutput");
    ((void*&) _Int64Tag_load) = hybris_dlsym(handle, "_ZN8Int64Tag4loadER10IDataInput");
    if (_Int64Tag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Int64Tag4loadER10IDataInput");
    ((void*&) _Int64Tag_toString) = hybris_dlsym(handle, "_ZNK8Int64Tag8toStringEv");
    if (_Int64Tag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8Int64Tag8toStringEv");
    ((void*&) _Int64Tag_getId) = hybris_dlsym(handle, "_ZNK8Int64Tag5getIdEv");
    if (_Int64Tag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8Int64Tag5getIdEv");
    ((void*&) _Int64Tag_equals) = hybris_dlsym(handle, "_ZNK8Int64Tag6equalsERK3Tag");
    if (_Int64Tag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8Int64Tag6equalsERK3Tag");
    ((void*&) _Int64Tag_copy) = hybris_dlsym(handle, "_ZNK8Int64Tag4copyEv");
    if (_Int64Tag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK8Int64Tag4copyEv");
    ((void*&) IntArrayTag::vt) = hybris_dlsym(handle, "_ZTV11IntArrayTag");
    if (IntArrayTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV11IntArrayTag");
    ((void*&) _IntArrayTag_write) = hybris_dlsym(handle, "_ZNK11IntArrayTag5writeER11IDataOutput");
    if (_IntArrayTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11IntArrayTag5writeER11IDataOutput");
    ((void*&) _IntArrayTag_load) = hybris_dlsym(handle, "_ZN11IntArrayTag4loadER10IDataInput");
    if (_IntArrayTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN11IntArrayTag4loadER10IDataInput");
    ((void*&) _IntArrayTag_toString) = hybris_dlsym(handle, "_ZNK11IntArrayTag8toStringEv");
    if (_IntArrayTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11IntArrayTag8toStringEv");
    ((void*&) _IntArrayTag_getId) = hybris_dlsym(handle, "_ZNK11IntArrayTag5getIdEv");
    if (_IntArrayTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11IntArrayTag5getIdEv");
    ((void*&) _IntArrayTag_equals) = hybris_dlsym(handle, "_ZNK11IntArrayTag6equalsERK3Tag");
    if (_IntArrayTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11IntArrayTag6equalsERK3Tag");
    ((void*&) _IntArrayTag_copy) = hybris_dlsym(handle, "_ZNK11IntArrayTag4copyEv");
    if (_IntArrayTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK11IntArrayTag4copyEv");
    ((void*&) IntTag::vt) = hybris_dlsym(handle, "_ZTV6IntTag");
    if (IntTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV6IntTag");
    ((void*&) _IntTag_write) = hybris_dlsym(handle, "_ZNK6IntTag5writeER11IDataOutput");
    if (_IntTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6IntTag5writeER11IDataOutput");
    ((void*&) _IntTag_load) = hybris_dlsym(handle, "_ZN6IntTag4loadER10IDataInput");
    if (_IntTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6IntTag4loadER10IDataInput");
    ((void*&) _IntTag_toString) = hybris_dlsym(handle, "_ZNK6IntTag8toStringEv");
    if (_IntTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6IntTag8toStringEv");
    ((void*&) _IntTag_getId) = hybris_dlsym(handle, "_ZNK6IntTag5getIdEv");
    if (_IntTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6IntTag5getIdEv");
    ((void*&) _IntTag_equals) = hybris_dlsym(handle, "_ZNK6IntTag6equalsERK3Tag");
    if (_IntTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6IntTag6equalsERK3Tag");
    ((void*&) _IntTag_copy) = hybris_dlsym(handle, "_ZNK6IntTag4copyEv");
    if (_IntTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6IntTag4copyEv");
    ((void*&) StringTag::vt) = hybris_dlsym(handle, "_ZTV9StringTag");
    if (StringTag::vt == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV9StringTag");
    ((void*&) _StringTag_write) = hybris_dlsym(handle, "_ZNK9StringTag5writeER11IDataOutput");
    if (_StringTag_write == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9StringTag5writeER11IDataOutput");
    ((void*&) _StringTag_load) = hybris_dlsym(handle, "_ZN9StringTag4loadER10IDataInput");
    if (_StringTag_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9StringTag4loadER10IDataInput");
    ((void*&) _StringTag_toString) = hybris_dlsym(handle, "_ZNK9StringTag8toStringEv");
    if (_StringTag_toString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9StringTag8toStringEv");
    ((void*&) _StringTag_getId) = hybris_dlsym(handle, "_ZNK9StringTag5getIdEv");
    if (_StringTag_getId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9StringTag5getIdEv");
    ((void*&) _StringTag_equals) = hybris_dlsym(handle, "_ZNK9StringTag6equalsERK3Tag");
    if (_StringTag_equals == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9StringTag6equalsERK3Tag");
    ((void*&) _StringTag_copy) = hybris_dlsym(handle, "_ZNK9StringTag4copyEv");
    if (_StringTag_copy == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK9StringTag4copyEv");
    ((void*&) _ResourceLoadManager_ResourceLoadManager) = hybris_dlsym(handle, "_ZN19ResourceLoadManagerC2Ev");
    if (_ResourceLoadManager_ResourceLoadManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ResourceLoadManagerC2Ev");
    ((void*&) _ResourceLoadManager_sync) = hybris_dlsym(handle, "_ZN19ResourceLoadManager4syncE16ResourceLoadType");
    if (_ResourceLoadManager_sync == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19ResourceLoadManager4syncE16ResourceLoadType");
    ((void*&) _I18n_get) = hybris_dlsym(handle, "_ZN4I18n3getERKSsRKSt6vectorISsSaISsEE");
    if (_I18n_get == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4I18n3getERKSsRKSt6vectorISsSaISsEE");
    ((void*&) _I18n_chooseLanguage) = hybris_dlsym(handle, "_ZN4I18n14chooseLanguageERKSs");
    if (_I18n_chooseLanguage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4I18n14chooseLanguageERKSs");
    ((void*&) _I18n_loadLanguages) = hybris_dlsym(handle, "_ZN4I18n13loadLanguagesER19ResourcePackManagerR19ResourceLoadManagerRKSs");
    if (_I18n_loadLanguages == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4I18n13loadLanguagesER19ResourcePackManagerR19ResourceLoadManagerRKSs");
    ((void*&) _Social_MultiplayerXBL_MultiplayerXBL) = hybris_dlsym(handle, "_ZN6Social14MultiplayerXBLC2Ev");
    if (_Social_MultiplayerXBL_MultiplayerXBL == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Social14MultiplayerXBLC2Ev");
    ((void*&) Keyboard::_states) = hybris_dlsym(handle, "_ZN8Keyboard7_statesE");
    if (Keyboard::_states == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard7_statesE");
    ((void*&) Keyboard::_inputCaretLocation) = hybris_dlsym(handle, "_ZN8Keyboard19_inputCaretLocationE");
    if (Keyboard::_inputCaretLocation == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard19_inputCaretLocationE");
    ((void*&) _Keyboard_feed) = hybris_dlsym(handle, "_ZN8Keyboard4feedEhi");
    if (_Keyboard_feed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard4feedEhi");
    ((void*&) _Keyboard_feedText) = hybris_dlsym(handle, "_ZN8Keyboard8feedTextERKSsbh");
    if (_Keyboard_feedText == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard8feedTextERKSsbh");
    ((void*&) _WhitelistEntry_WhitelistEntry) = hybris_dlsym(handle, "_ZN14WhitelistEntryC2ESsN3mce4UUIDESsb");
    if (_WhitelistEntry_WhitelistEntry == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14WhitelistEntryC2ESsN3mce4UUIDESsb");
    ((void*&) _Whitelist_Whitelist) = hybris_dlsym(handle, "_ZN9WhitelistC2ESt8functionIFvvEE");
    if (_Whitelist_Whitelist == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9WhitelistC2ESt8functionIFvvEE");
    ((void*&) _Whitelist_destructor) = hybris_dlsym(handle, "_ZN9WhitelistD2Ev");
    if (_Whitelist_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9WhitelistD2Ev");
    ((void*&) _Whitelist_deserialize) = hybris_dlsym(handle, "_ZN9Whitelist11deserializeERN4Json5ValueE");
    if (_Whitelist_deserialize == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Whitelist11deserializeERN4Json5ValueE");
    ((void*&) _Whitelist_serialize) = hybris_dlsym(handle, "_ZN9Whitelist9serializeERN4Json5ValueE");
    if (_Whitelist_serialize == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Whitelist9serializeERN4Json5ValueE");
    ((void*&) _Whitelist_removeByName) = hybris_dlsym(handle, "_ZN9Whitelist12removeByNameERKSs");
    if (_Whitelist_removeByName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Whitelist12removeByNameERKSs");
    ((void*&) _MinecraftEventing_MinecraftEventing) = hybris_dlsym(handle, "_ZN17MinecraftEventingC2ERKSs");
    if (_MinecraftEventing_MinecraftEventing == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftEventingC2ERKSs");
    ((void*&) _MinecraftEventing_init) = hybris_dlsym(handle, "_ZN17MinecraftEventing4initEv");
    if (_MinecraftEventing_init == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftEventing4initEv");
    ((void*&) _TextPacket_TextPacket) = hybris_dlsym(handle, "_ZN10TextPacketC2E14TextPacketTypeRKSsS2_RKSt6vectorISsSaISsEEbS2_S2_");
    if (_TextPacket_TextPacket == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacketC2E14TextPacketTypeRKSsS2_RKSt6vectorISsSaISsEEbS2_S2_");
    ((void*&) _TextPacket_createRaw) = hybris_dlsym(handle, "_ZN10TextPacket9createRawERKSs");
    if (_TextPacket_createRaw == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket9createRawERKSs");
    ((void*&) _TextPacket_createJukeboxPopup) = hybris_dlsym(handle, "_ZN10TextPacket18createJukeboxPopupERKSs");
    if (_TextPacket_createJukeboxPopup == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket18createJukeboxPopupERKSs");
    ((void*&) _TextPacket_createSystemMessage) = hybris_dlsym(handle, "_ZN10TextPacket19createSystemMessageERKSs");
    if (_TextPacket_createSystemMessage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket19createSystemMessageERKSs");
    ((void*&) _TextPacket_createChat) = hybris_dlsym(handle, "_ZN10TextPacket10createChatERKSsS1_S1_S1_");
    if (_TextPacket_createChat == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket10createChatERKSsS1_S1_S1_");
    ((void*&) _TextPacket_createTranslatedChat) = hybris_dlsym(handle, "_ZN10TextPacket20createTranslatedChatERKSsS1_S1_S1_");
    if (_TextPacket_createTranslatedChat == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket20createTranslatedChatERKSsS1_S1_S1_");
    ((void*&) _TextPacket_createTranslatedAnnouncement) = hybris_dlsym(handle, "_ZN10TextPacket28createTranslatedAnnouncementERKSsS1_S1_S1_");
    if (_TextPacket_createTranslatedAnnouncement == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket28createTranslatedAnnouncementERKSsS1_S1_S1_");
    ((void*&) _TextPacket_createWhisper) = hybris_dlsym(handle, "_ZN10TextPacket13createWhisperERKSsS1_S1_S1_");
    if (_TextPacket_createWhisper == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket13createWhisperERKSsS1_S1_S1_");
    ((void*&) _TextPacket_createTranslated) = hybris_dlsym(handle, "_ZN10TextPacket16createTranslatedERKSsRKSt6vectorISsSaISsEE");
    if (_TextPacket_createTranslated == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10TextPacket16createTranslatedERKSsRKSt6vectorISsSaISsEE");
    ((void*&) GameControllerManager::sGamePadManager) = hybris_dlsym(handle, "_ZN21GameControllerManager15sGamePadManagerE");
    if (GameControllerManager::sGamePadManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN21GameControllerManager15sGamePadManagerE");
    ((void*&) _GameControllerManager_setGameControllerConnected) = hybris_dlsym(handle, "_ZN21GameControllerManager26setGameControllerConnectedEib");
    if (_GameControllerManager_setGameControllerConnected == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN21GameControllerManager26setGameControllerConnectedEib");
    ((void*&) _GameControllerManager_feedButton) = hybris_dlsym(handle, "_ZN21GameControllerManager10feedButtonEii25GameControllerButtonStateb");
    if (_GameControllerManager_feedButton == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN21GameControllerManager10feedButtonEii25GameControllerButtonStateb");
    ((void*&) _GameControllerManager_feedStick) = hybris_dlsym(handle, "_ZN21GameControllerManager9feedStickEii24GameControllerStickStateff");
    if (_GameControllerManager_feedStick == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN21GameControllerManager9feedStickEii24GameControllerStickStateff");
    ((void*&) _GameControllerManager_feedTrigger) = hybris_dlsym(handle, "_ZN21GameControllerManager11feedTriggerEiif");
    if (_GameControllerManager_feedTrigger == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN21GameControllerManager11feedTriggerEiif");
    ((void*&) _GameControllerManager_feedJoinGame) = hybris_dlsym(handle, "_ZN21GameControllerManager12feedJoinGameEib");
    if (_GameControllerManager_feedJoinGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN21GameControllerManager12feedJoinGameEib");
    ((void*&) CommandMessage::constructor) = hybris_dlsym(handle, "_ZN14CommandMessageC2Ev");
    if (CommandMessage::constructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14CommandMessageC2Ev");
    ((void*&) CommandMessage::destructor) = hybris_dlsym(handle, "_ZN14CommandMessageD2Ev");
    if (CommandMessage::destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14CommandMessageD2Ev");
    ((void*&) CommandMessage::tid) = hybris_dlsym(handle, "_ZZ7type_idI15CommandRegistry14CommandMessageE8typeid_tIT_EvE2id");
    if (CommandMessage::tid == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZZ7type_idI15CommandRegistry14CommandMessageE8typeid_tIT_EvE2id");
    ((void*&) CommandMessage::parser) = hybris_dlsym(handle, "_ZNK15CommandRegistry5parseI14CommandMessageEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    if (CommandMessage::parser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK15CommandRegistry5parseI14CommandMessageEEbPvRKNS_10ParseTokenERK13CommandOriginiRSsRSt6vectorISsSaISsEE");
    ((void*&) _CommandMessage_getMessage) = hybris_dlsym(handle, "_ZNK14CommandMessage10getMessageERK13CommandOrigin");
    if (_CommandMessage_getMessage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK14CommandMessage10getMessageERK13CommandOrigin");
    ((void*&) _Player_getPlatformOnlineId) = hybris_dlsym(handle, "_ZNK6Player19getPlatformOnlineIdEv");
    if (_Player_getPlatformOnlineId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player19getPlatformOnlineIdEv");
    ((void*&) _Player_getCertificate) = hybris_dlsym(handle, "_ZNK6Player14getCertificateEv");
    if (_Player_getCertificate == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player14getCertificateEv");
    ((void*&) _Player_isCreative) = hybris_dlsym(handle, "_ZNK5Actor10isCreativeEv");
    if (_Player_isCreative == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor10isCreativeEv");
    ((void*&) _Player_getLevelProgress) = hybris_dlsym(handle, "_ZNK6Player16getLevelProgressEv");
    if (_Player_getLevelProgress == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player16getLevelProgressEv");
    ((void*&) _Player_sendNetworkPacket) = hybris_dlsym(handle, "_ZNK12ServerPlayer17sendNetworkPacketER6Packet");
    if (_Player_sendNetworkPacket == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK12ServerPlayer17sendNetworkPacketER6Packet");
    ((void*&) _Player_canUseAbility) = hybris_dlsym(handle, "_ZN6Player13canUseAbilityERKSs");
    if (_Player_canUseAbility == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Player13canUseAbilityERKSs");
    ((void*&) _Player_getCommandPermissionLevel) = hybris_dlsym(handle, "_ZNK6Player25getCommandPermissionLevelEv");
    if (_Player_getCommandPermissionLevel == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player25getCommandPermissionLevelEv");
    ((void*&) _Player_getSpawnPosition) = hybris_dlsym(handle, "_ZN6Player16getSpawnPositionEv");
    if (_Player_getSpawnPosition == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Player16getSpawnPositionEv");
    ((void*&) _Player_getSelectedItem) = hybris_dlsym(handle, "_ZNK6Player15getSelectedItemEv");
    if (_Player_getSelectedItem == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player15getSelectedItemEv");
    ((void*&) _Player_getSleepTimer) = hybris_dlsym(handle, "_ZNK6Player13getSleepTimerEv");
    if (_Player_getSleepTimer == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player13getSleepTimerEv");
    ((void*&) _Player_getLuck) = hybris_dlsym(handle, "_ZN6Player7getLuckEv");
    if (_Player_getLuck == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Player7getLuckEv");
    ((void*&) _Player_getAttackDamage) = hybris_dlsym(handle, "_ZN6Player15getAttackDamageEv");
    if (_Player_getAttackDamage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Player15getAttackDamageEv");
    ((void*&) _Player_getAgent) = hybris_dlsym(handle, "_ZNK6Player8getAgentEv");
    if (_Player_getAgent == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Player8getAgentEv");
    ((void*&) _ActorDefinitionIdentifier_getCanonicalName) = hybris_dlsym(handle, "_ZNK25ActorDefinitionIdentifier16getCanonicalNameEv");
    if (_ActorDefinitionIdentifier_getCanonicalName == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK25ActorDefinitionIdentifier16getCanonicalNameEv");
    ((void*&) _Actor_getActorIdentifier) = hybris_dlsym(handle, "_ZNK5Actor18getActorIdentifierEv");
    if (_Actor_getActorIdentifier == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor18getActorIdentifierEv");
    ((void*&) _Actor_getUniqueID) = hybris_dlsym(handle, "_ZNK5Actor11getUniqueIDEv");
    if (_Actor_getUniqueID == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor11getUniqueIDEv");
    ((void*&) _Actor_save) = hybris_dlsym(handle, "_ZN5Actor4saveER11CompoundTag");
    if (_Actor_save == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Actor4saveER11CompoundTag");
    ((void*&) _Actor_load) = hybris_dlsym(handle, "_ZN5Actor4loadERK11CompoundTag");
    if (_Actor_load == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Actor4loadERK11CompoundTag");
    ((void*&) _Actor_getPos) = hybris_dlsym(handle, "_ZNK5Actor6getPosEv");
    if (_Actor_getPos == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor6getPosEv");
    ((void*&) _Actor_getRotation) = hybris_dlsym(handle, "_ZNK5Actor11getRotationEv");
    if (_Actor_getRotation == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor11getRotationEv");
    ((void*&) _Actor_getRegion) = hybris_dlsym(handle, "_ZNK5Actor9getRegionEv");
    if (_Actor_getRegion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor9getRegionEv");
    ((void*&) _Actor_getNameTag) = hybris_dlsym(handle, "_ZNK5Actor10getNameTagEv");
    if (_Actor_getNameTag == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor10getNameTagEv");
    ((void*&) _Actor_getDimensionId) = hybris_dlsym(handle, "_ZNK5Actor14getDimensionIdEv");
    if (_Actor_getDimensionId == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor14getDimensionIdEv");
    ((void*&) _Actor_getVariant) = hybris_dlsym(handle, "_ZNK5Actor10getVariantEv");
    if (_Actor_getVariant == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor10getVariantEv");
    ((void*&) _Actor_getAirSupply) = hybris_dlsym(handle, "_ZNK5Actor12getAirSupplyEv");
    if (_Actor_getAirSupply == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor12getAirSupplyEv");
    ((void*&) _Actor_getTotalAirSupply) = hybris_dlsym(handle, "_ZNK5Actor17getTotalAirSupplyEv");
    if (_Actor_getTotalAirSupply == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor17getTotalAirSupplyEv");
    ((void*&) _Actor_getStrength) = hybris_dlsym(handle, "_ZNK5Actor11getStrengthEv");
    if (_Actor_getStrength == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor11getStrengthEv");
    ((void*&) _Actor_getStrengthMax) = hybris_dlsym(handle, "_ZNK5Actor14getStrengthMaxEv");
    if (_Actor_getStrengthMax == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor14getStrengthMaxEv");
    ((void*&) _Actor_getAge) = hybris_dlsym(handle, "_ZNK5Actor6getAgeEv");
    if (_Actor_getAge == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor6getAgeEv");
    ((void*&) _Actor_getHealth) = hybris_dlsym(handle, "_ZNK5Actor9getHealthEv");
    if (_Actor_getHealth == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor9getHealthEv");
    ((void*&) _Actor_getMaxHealth) = hybris_dlsym(handle, "_ZNK5Actor12getMaxHealthEv");
    if (_Actor_getMaxHealth == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor12getMaxHealthEv");
    ((void*&) _Actor_getRide) = hybris_dlsym(handle, "_ZNK5Actor7getRideEv");
    if (_Actor_getRide == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor7getRideEv");
    ((void*&) _Actor_getRideRoot) = hybris_dlsym(handle, "_ZNK5Actor11getRideRootEv");
    if (_Actor_getRideRoot == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor11getRideRootEv");
    ((void*&) _Actor_getTarget) = hybris_dlsym(handle, "_ZNK5Actor9getTargetEv");
    if (_Actor_getTarget == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor9getTargetEv");
    ((void*&) _Actor_getArmor) = hybris_dlsym(handle, "_ZNK5Actor8getArmorE9ArmorSlot");
    if (_Actor_getArmor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK5Actor8getArmorE9ArmorSlot");
    void** vt_ServerPlayer = (void**) hybris_dlsym(handle, "_ZTV12ServerPlayer") + 2;
    vti_Actor_changeDimension = resolve_vtable_func(vt_ServerPlayer, hybris_dlsym(handle, "_ZN12ServerPlayer15changeDimensionE11AutomaticIDI9DimensioniEb"));
    if (vti_Actor_changeDimension == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN12ServerPlayer15changeDimensionE11AutomaticIDI9DimensioniEb");
    vti_Legacy_Pre_1_8_App_quit = resolve_vtable_func(vt_App, hybris_dlsym(handle, "_ZN3App4quitEv"));
    ((void*&) _Legacy_Pre_1_2_10_MinecraftGame_setTextboxText) = hybris_dlsym(handle, "_ZN13MinecraftGame14setTextboxTextERKSs");
    ((void*&) _Legacy_Pre_1_2_10_AppPlatform_showKeyboard) = hybris_dlsym(handle, "_ZN11AppPlatform12showKeyboardERKSsibbbRK4Vec2");
    void** vt_xbox_services_local_config = (void**) hybris_dlsym(handle, "_ZTVN4xbox8services12local_configE") + 2;
    vti_Legacy_Beta_1_8_xbox_services_local_config_get_value_from_local_storage = resolve_vtable_func(vt_xbox_services_local_config, hybris_dlsym(handle, "_ZN4xbox8services12local_config28get_value_from_local_storageERKSsS3_S3_"));
}
