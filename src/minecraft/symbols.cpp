// This file was automatically generated using tools/process_headers.py
// Generated on Sun Oct 28 2018 19:57:17 UTC

#include <hybris/dlfcn.h>
#include <log.h>

#include "Resource.h"
static void (*_ResourceLoaders_registerLoader)(ResourceFileSystem, std::unique_ptr<ResourceLoader>);
void ResourceLoaders::registerLoader(ResourceFileSystem p1, std::unique_ptr<ResourceLoader> p2) {
    _ResourceLoaders_registerLoader(p1, std::move(p2));
}

#include "UserManager.h"
static std::unique_ptr<Social::UserManager> (*_Social_UserManager_CreateUserManager)();
std::unique_ptr<Social::UserManager> Social::UserManager::CreateUserManager() {
    return _Social_UserManager_CreateUserManager();
}

#include "Xbox.h"
static void * (*_xbox_services_xbox_services_error_code_category)();
void * xbox::services::xbox_services_error_code_category() {
    return _xbox_services_xbox_services_error_code_category();
}
static void (web::json::value::*_web_json_value_value)();
web::json::value::value() {
    (this->*_web_json_value_value)();
}
static void (web::json::value::*_web_json_value_value2)(mcpe::string);
web::json::value::value(mcpe::string p1) {
    (this->*_web_json_value_value2)(p1);
}
static void (web::json::value::*_web_json_value_value3)(web::json::value const &);
web::json::value::value(web::json::value const & p1) {
    (this->*_web_json_value_value3)(p1);
}
static void (web::json::value::*_web_json_value_value4)(web::json::value &&);
web::json::value::value(web::json::value && p1) {
    (this->*_web_json_value_value4)(std::move(p1));
}
static web::json::value & (web::json::value::*_web_json_value_operator)(mcpe::string const &);
web::json::value & web::json::value::operator[](mcpe::string const & p1) {
    return (this->*_web_json_value_operator)(p1);
}
static web::json::value & (web::json::value::*_web_json_value_operator2)(web::json::value &&);
web::json::value & web::json::value::operator=(web::json::value && p1) {
    return (this->*_web_json_value_operator2)(std::move(p1));
}
static mcpe::string (web::json::value::*_web_json_value_to_string)() const;
mcpe::string web::json::value::to_string() const {
    return (this->*_web_json_value_to_string)();
}
static void (web::json::value::*_web_json_value_erase)(mcpe::string const &);
void web::json::value::erase(mcpe::string const & p1) {
    (this->*_web_json_value_erase)(p1);
}
static std::shared_ptr<xbox::services::java_interop> (*_xbox_services_java_interop_get_java_interop_singleton)();
std::shared_ptr<xbox::services::java_interop> xbox::services::java_interop::get_java_interop_singleton() {
    return _xbox_services_java_interop_get_java_interop_singleton();
}
static uint32_t (xbox::services::xbox_live_app_config::*_xbox_services_xbox_live_app_config_title_id)();
uint32_t xbox::services::xbox_live_app_config::title_id() {
    return (this->*_xbox_services_xbox_live_app_config_title_id)();
}
static std::shared_ptr<xbox::services::xbox_live_app_config> (*_xbox_services_xbox_live_app_config_get_app_config_singleton)();
std::shared_ptr<xbox::services::xbox_live_app_config> xbox::services::xbox_live_app_config::get_app_config_singleton() {
    return _xbox_services_xbox_live_app_config_get_app_config_singleton();
}
static int vti_xbox_services_local_config_get_value_from_local_storage;
mcpe::string xbox::services::local_config::get_value_from_local_storage(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3) {
    union { void* voidp; mcpe::string (xbox::services::local_config::*funcp)(mcpe::string const &, mcpe::string const &, mcpe::string const &); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_xbox_services_local_config_get_value_from_local_storage];
    return (this->*u.funcp)(p1, p2, p3);
}
static int vti_xbox_services_local_config_write_value_to_local_storage;
xbox::services::xbox_live_result<void> xbox::services::local_config::write_value_to_local_storage(mcpe::string const & p1, mcpe::string const & p2, mcpe::string const & p3, mcpe::string const & p4) {
    union { void* voidp; xbox::services::xbox_live_result<void> (xbox::services::local_config::*funcp)(mcpe::string const &, mcpe::string const &, mcpe::string const &, mcpe::string const &); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_xbox_services_local_config_write_value_to_local_storage];
    return (this->*u.funcp)(p1, p2, p3, p4);
}
static std::shared_ptr<xbox::services::local_config> (*_xbox_services_local_config_get_local_config_singleton)();
std::shared_ptr<xbox::services::local_config> xbox::services::local_config::get_local_config_singleton() {
    return _xbox_services_local_config_get_local_config_singleton();
}
static void (xbox::services::xsapi_singleton::*_xbox_services_xsapi_singleton_destructor)();
xbox::services::xsapi_singleton::~xsapi_singleton() {
    (this->*_xbox_services_xsapi_singleton_destructor)();
}
static void (xbox::services::system::user_impl::*_xbox_services_system_user_impl_user_signed_out)();
void xbox::services::system::user_impl::user_signed_out() {
    (this->*_xbox_services_system_user_impl_user_signed_out)();
}
static std::shared_ptr<xbox::services::system::user_impl_android> (*_xbox_services_system_user_impl_android_get_instance)();
std::shared_ptr<xbox::services::system::user_impl_android> xbox::services::system::user_impl_android::get_instance() {
    return _xbox_services_system_user_impl_android_get_instance();
}
static void (pplx::task_completion_event_java_rps_ticket::*_pplx_task_completion_event_java_rps_ticket_set)(xbox::services::system::java_rps_ticket);
void pplx::task_completion_event_java_rps_ticket::set(xbox::services::system::java_rps_ticket p1) {
    (this->*_pplx_task_completion_event_java_rps_ticket_set)(p1);
}
static void (pplx::task_completion_event_auth_flow_result::*_pplx_task_completion_event_auth_flow_result_set)(xbox::services::system::auth_flow_result);
void pplx::task_completion_event_auth_flow_result::set(xbox::services::system::auth_flow_result p1) {
    (this->*_pplx_task_completion_event_auth_flow_result_set)(p1);
}
static void (pplx::task_completion_event_xbox_live_result_void::*_pplx_task_completion_event_xbox_live_result_void_set)(xbox::services::xbox_live_result<void>);
void pplx::task_completion_event_xbox_live_result_void::set(xbox::services::xbox_live_result<void> p1) {
    (this->*_pplx_task_completion_event_xbox_live_result_void_set)(p1);
}
static xbox::services::xbox_live_result<void> (pplx::task_xbox_live_result_void::*_pplx_task_xbox_live_result_void_get)();
xbox::services::xbox_live_result<void> pplx::task_xbox_live_result_void::get() {
    return (this->*_pplx_task_xbox_live_result_void_get)();
}
static xbox::services::xbox_live_result<xbox::services::system::token_and_signature_result> (pplx::task_xbox_live_result_token_and_signature_result::*_pplx_task_xbox_live_result_token_and_signature_result_get)();
xbox::services::xbox_live_result<xbox::services::system::token_and_signature_result> pplx::task_xbox_live_result_token_and_signature_result::get() {
    return (this->*_pplx_task_xbox_live_result_token_and_signature_result_get)();
}
static void (xbox::services::system::auth_config::*_xbox_services_system_auth_config_set_xtoken_composition)(std::vector<xbox::services::system::token_identity_type>);
void xbox::services::system::auth_config::set_xtoken_composition(std::vector<xbox::services::system::token_identity_type> p1) {
    (this->*_xbox_services_system_auth_config_set_xtoken_composition)(p1);
}
static mcpe::string const & (xbox::services::system::auth_config::*_xbox_services_system_auth_config_xbox_live_endpoint)() const;
mcpe::string const & xbox::services::system::auth_config::xbox_live_endpoint() const {
    return (this->*_xbox_services_system_auth_config_xbox_live_endpoint)();
}
static std::shared_ptr<xbox::services::system::auth_manager> (*_xbox_services_system_auth_manager_get_auth_manager_instance)();
std::shared_ptr<xbox::services::system::auth_manager> xbox::services::system::auth_manager::get_auth_manager_instance() {
    return _xbox_services_system_auth_manager_get_auth_manager_instance();
}
static void (xbox::services::system::auth_manager::*_xbox_services_system_auth_manager_set_rps_ticket)(mcpe::string const &);
void xbox::services::system::auth_manager::set_rps_ticket(mcpe::string const & p1) {
    (this->*_xbox_services_system_auth_manager_set_rps_ticket)(p1);
}
static pplx::task_xbox_live_result_void (xbox::services::system::auth_manager::*_xbox_services_system_auth_manager_initialize_default_nsal)(pplx::cancellation_token);
pplx::task_xbox_live_result_void xbox::services::system::auth_manager::initialize_default_nsal(pplx::cancellation_token p1) {
    return (this->*_xbox_services_system_auth_manager_initialize_default_nsal)(p1);
}
static pplx::task_xbox_live_result_void (xbox::services::system::auth_manager::*_xbox_services_system_auth_manager_initialize_title_nsal)(mcpe::string const &, pplx::cancellation_token);
pplx::task_xbox_live_result_void xbox::services::system::auth_manager::initialize_title_nsal(mcpe::string const & p1, pplx::cancellation_token p2) {
    return (this->*_xbox_services_system_auth_manager_initialize_title_nsal)(p1, p2);
}
static pplx::task_xbox_live_result_token_and_signature_result (xbox::services::system::auth_manager::*_xbox_services_system_auth_manager_internal_get_token_and_signature)(mcpe::string, mcpe::string const &, mcpe::string const &, mcpe::string, std::vector<unsigned char> const &, bool, bool, mcpe::string const &, pplx::cancellation_token);
pplx::task_xbox_live_result_token_and_signature_result xbox::services::system::auth_manager::internal_get_token_and_signature(mcpe::string p1, mcpe::string const & p2, mcpe::string const & p3, mcpe::string p4, std::vector<unsigned char> const & p5, bool p6, bool p7, mcpe::string const & p8, pplx::cancellation_token p9) {
    return (this->*_xbox_services_system_auth_manager_internal_get_token_and_signature)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
}
static std::shared_ptr<xbox::services::system::auth_config> (xbox::services::system::auth_manager::*_xbox_services_system_auth_manager_get_auth_config)();
std::shared_ptr<xbox::services::system::auth_config> xbox::services::system::auth_manager::get_auth_config() {
    return (this->*_xbox_services_system_auth_manager_get_auth_config)();
}
pplx::task_completion_event_java_rps_ticket * xbox::services::system::user_auth_android::s_rpsTicketCompletionEvent;
pplx::task_completion_event_xbox_live_result_void * xbox::services::system::user_auth_android::s_signOutCompleteEvent;
static std::shared_ptr<xbox::services::system::user_auth_android> (*_xbox_services_system_user_auth_android_get_instance)();
std::shared_ptr<xbox::services::system::user_auth_android> xbox::services::system::user_auth_android::get_instance() {
    return _xbox_services_system_user_auth_android_get_instance();
}
static void (xbox::services::system::user_auth_android::*_xbox_services_system_user_auth_android_complete_sign_in_with_ui)(xbox::services::system::auth_flow_result const &);
void xbox::services::system::user_auth_android::complete_sign_in_with_ui(xbox::services::system::auth_flow_result const & p1) {
    (this->*_xbox_services_system_user_auth_android_complete_sign_in_with_ui)(p1);
}

#include "ServerInstance.h"
static void (ServerInstance::*_ServerInstance_ServerInstance)(IMinecraftApp &, Whitelist &, PermissionsMap const &, FilePathManager *, std::chrono::seconds, mcpe::string, mcpe::string, mcpe::string, LevelSettings, int, bool, int, int, int, bool, std::vector<mcpe::string> const &, mcpe::string, mce::UUID const &, IMinecraftEventing &, ResourcePackRepository &, ContentTierManager const &, ResourcePackManager &, std::function<std::unique_ptr<LevelStorage> ( Scheduler & )>, mcpe::string const &, LevelData *, TextFilteringProcessor *, ResourcePackManager *, std::function<void ( mcpe::string const & )>, std::function<void ( mcpe::string const & )>);
ServerInstance::ServerInstance(IMinecraftApp & p1, Whitelist & p2, PermissionsMap const & p3, FilePathManager * p4, std::chrono::seconds p5, mcpe::string p6, mcpe::string p7, mcpe::string p8, LevelSettings p9, int p10, bool p11, int p12, int p13, int p14, bool p15, std::vector<mcpe::string> const & p16, mcpe::string p17, mce::UUID const & p18, IMinecraftEventing & p19, ResourcePackRepository & p20, ContentTierManager const & p21, ResourcePackManager & p22, std::function<std::unique_ptr<LevelStorage> ( Scheduler & )> p23, mcpe::string const & p24, LevelData * p25, TextFilteringProcessor * p26, ResourcePackManager * p27, std::function<void ( mcpe::string const & )> p28, std::function<void ( mcpe::string const & )> p29) {
    (this->*_ServerInstance_ServerInstance)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29);
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

#include "Mouse.h"
static void (*_Mouse_feed)(char, char, short, short, short, short);
void Mouse::feed(char p1, char p2, short p3, short p4, short p5, short p6) {
    _Mouse_feed(p1, p2, p3, p4, p5, p6);
}

#include "Level.h"
static unsigned int (*_Level_createRandomSeed)();
unsigned int Level::createRandomSeed() {
    return _Level_createRandomSeed();
}

#include "PermissionsMap.h"
static void (PermissionsMap::*_PermissionsMap_PermissionsMap)(bool);
PermissionsMap::PermissionsMap(bool p1) {
    (this->*_PermissionsMap_PermissionsMap)(p1);
}

#include "MinecraftCommands.h"
static void (MinecraftCommands::*_MinecraftCommands_setOutputSender)(std::unique_ptr<CommandOutputSender>);
void MinecraftCommands::setOutputSender(std::unique_ptr<CommandOutputSender> p1) {
    (this->*_MinecraftCommands_setOutputSender)(std::move(p1));
}
static MCRESULT (MinecraftCommands::*_MinecraftCommands_requestCommandExecution)(std::unique_ptr<CommandOrigin>, mcpe::string const &, int, bool) const;
MCRESULT MinecraftCommands::requestCommandExecution(std::unique_ptr<CommandOrigin> p1, mcpe::string const & p2, int p3, bool p4) const {
    return (this->*_MinecraftCommands_requestCommandExecution)(std::move(p1), p2, p3, p4);
}

#include "I18n.h"
static mcpe::string (*_I18n_get)(mcpe::string const &, std::vector<mcpe::string> const &);
mcpe::string I18n::get(mcpe::string const & p1, std::vector<mcpe::string> const & p2) {
    return _I18n_get(p1, p2);
}
static void (*_I18n_chooseLanguage)(mcpe::string const &);
void I18n::chooseLanguage(mcpe::string const & p1) {
    _I18n_chooseLanguage(p1);
}
static void (*_I18n_loadLanguages)(ResourcePackManager &, mcpe::string const &);
void I18n::loadLanguages(ResourcePackManager & p1, mcpe::string const & p2) {
    _I18n_loadLanguages(p1, p2);
}

#include "MinecraftScreenModel.h"
static void (MinecraftScreenModel::*_MinecraftScreenModel_navigateToXblConsoleSignInScreen)(mcpe::string const &, mcpe::string const &);
void MinecraftScreenModel::navigateToXblConsoleSignInScreen(mcpe::string const & p1, mcpe::string const & p2) {
    (this->*_MinecraftScreenModel_navigateToXblConsoleSignInScreen)(p1, p2);
}
static void (MinecraftScreenModel::*_MinecraftScreenModel_navigateToXblConsoleSignInSucceededScreen)(Social::SignInResult const &, mcpe::function<void ( Social::SignInResult )>, bool);
void MinecraftScreenModel::navigateToXblConsoleSignInSucceededScreen(Social::SignInResult const & p1, mcpe::function<void ( Social::SignInResult )> p2, bool p3) {
    (this->*_MinecraftScreenModel_navigateToXblConsoleSignInSucceededScreen)(p1, p2, p3);
}
static void (MinecraftScreenModel::*_MinecraftScreenModel_leaveScreen)();
void MinecraftScreenModel::leaveScreen() {
    (this->*_MinecraftScreenModel_leaveScreen)();
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

#include "ResourcePackStack.h"
static void (PackInstance::*_PackInstance_PackInstance)(ResourcePack *, int, bool, PackSettings *);
PackInstance::PackInstance(ResourcePack * p1, int p2, bool p3, PackSettings * p4) {
    (this->*_PackInstance_PackInstance)(p1, p2, p3, p4);
}
void * * ResourcePackStack::vtable_sym;
static void (ResourcePackStack::*_ResourcePackStack_add)(PackInstance const &, ResourcePackRepository const &, bool);
void ResourcePackStack::add(PackInstance const & p1, ResourcePackRepository const & p2, bool p3) {
    (this->*_ResourcePackStack_add)(p1, p2, p3);
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

#include "Api.h"

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
static void (MinecraftGame::*_MinecraftGame_doPrimaryClientReadyWork)(mcpe::function<void ( )>);
void MinecraftGame::doPrimaryClientReadyWork(mcpe::function<void ( )> p1) {
    (this->*_MinecraftGame_doPrimaryClientReadyWork)(p1);
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

#include "ClientInstance.h"
static std::shared_ptr<Social::User> (ClientInstance::*_ClientInstance_getUser)();
std::shared_ptr<Social::User> ClientInstance::getUser() {
    return (this->*_ClientInstance_getUser)();
}
static void (ClientInstance::*_ClientInstance__startLeaveGame)();
void ClientInstance::_startLeaveGame() {
    (this->*_ClientInstance__startLeaveGame)();
}
static void (ClientInstance::*_ClientInstance__syncDestroyGame)();
void ClientInstance::_syncDestroyGame() {
    (this->*_ClientInstance__syncDestroyGame)();
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

#include "CommandOutput.h"
static std::vector<CommandOutputMessage> const & (CommandOutput::*_CommandOutput_getMessages)() const;
std::vector<CommandOutputMessage> const & CommandOutput::getMessages() const {
    return (this->*_CommandOutput_getMessages)();
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

#include "NullTextToSpeechClient.h"
void * * NullTextToSpeechClient::myVtable;

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

#include "ImagePickingCallback.h"

#include "IMinecraftApp.h"

#include "Whitelist.h"

#include "AppPlatform.h"
void * * AppPlatform::myVtable;
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

#include "SaveTransactionManager.h"
static void (SaveTransactionManager::*_SaveTransactionManager_SaveTransactionManager)(std::function<void ( bool )>);
SaveTransactionManager::SaveTransactionManager(std::function<void ( bool )> p1) {
    (this->*_SaveTransactionManager_SaveTransactionManager)(p1);
}

#include "SharedConstants.h"
int * SharedConstants::MajorVersion;
int * SharedConstants::MinorVersion;
int * SharedConstants::PatchVersion;
int * SharedConstants::RevisionVersion;

#include "AppResourceLoader.h"
static void (AppResourceLoader::*_AppResourceLoader_AppResourceLoader)(std::function<mcpe::string ( )>);
AppResourceLoader::AppResourceLoader(std::function<mcpe::string ( )> p1) {
    (this->*_AppResourceLoader_AppResourceLoader)(p1);
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

#include "Social.h"
static Social::XboxLiveUser * (Social::User::*_Social_User_getLiveUser)() const;
Social::XboxLiveUser * Social::User::getLiveUser() const {
    return (this->*_Social_User_getLiveUser)();
}
static void (Social::XboxLiveUser::*_Social_XboxLiveUser__handleUISignInNoError)(xbox::services::system::sign_in_result &, mcpe::function<void ( Social::SignInResult, bool )>);
void Social::XboxLiveUser::_handleUISignInNoError(xbox::services::system::sign_in_result & p1, mcpe::function<void ( Social::SignInResult, bool )> p2) {
    (this->*_Social_XboxLiveUser__handleUISignInNoError)(p1, p2);
}

#include "FilePickerSettings.h"

#include "AutomationClient.h"
static void (Automation::AutomationClient::*_Automation_AutomationClient_AutomationClient)(IMinecraftApp &);
Automation::AutomationClient::AutomationClient(IMinecraftApp & p1) {
    (this->*_Automation_AutomationClient_AutomationClient)(p1);
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
static void (ResourcePackRepository::*_ResourcePackRepository_ResourcePackRepository)(IMinecraftEventing &, PackManifestFactory &, IContentAccessibilityProvider &, FilePathManager *, PackSourceFactory &);
ResourcePackRepository::ResourcePackRepository(IMinecraftEventing & p1, PackManifestFactory & p2, IContentAccessibilityProvider & p3, FilePathManager * p4, PackSourceFactory & p5) {
    (this->*_ResourcePackRepository_ResourcePackRepository)(p1, p2, p3, p4, p5);
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

#include "DedicatedServerCommandOrigin.h"
static void (DedicatedServerCommandOrigin::*_DedicatedServerCommandOrigin_DedicatedServerCommandOrigin)(mcpe::string const &, Minecraft &);
DedicatedServerCommandOrigin::DedicatedServerCommandOrigin(mcpe::string const & p1, Minecraft & p2) {
    (this->*_DedicatedServerCommandOrigin_DedicatedServerCommandOrigin)(p1, p2);
}

#include "MultiplayerService.h"
static void (Social::MultiplayerXBL::*_Social_MultiplayerXBL_MultiplayerXBL)();
Social::MultiplayerXBL::MultiplayerXBL() {
    (this->*_Social_MultiplayerXBL_MultiplayerXBL)();
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

#include "ExternalFileLevelStorageSource.h"
static void (ExternalFileLevelStorageSource::*_ExternalFileLevelStorageSource_ExternalFileLevelStorageSource)(FilePathManager *, std::shared_ptr<SaveTransactionManager>);
ExternalFileLevelStorageSource::ExternalFileLevelStorageSource(FilePathManager * p1, std::shared_ptr<SaveTransactionManager> p2) {
    (this->*_ExternalFileLevelStorageSource_ExternalFileLevelStorageSource)(p1, p2);
}
static std::unique_ptr<LevelStorage> (ExternalFileLevelStorageSource::*_ExternalFileLevelStorageSource_createLevelStorage)(Scheduler &, mcpe::string const &, ContentIdentity const &, IContentKeyProvider const &);
std::unique_ptr<LevelStorage> ExternalFileLevelStorageSource::createLevelStorage(Scheduler & p1, mcpe::string const & p2, ContentIdentity const & p3, IContentKeyProvider const & p4) {
    return (this->*_ExternalFileLevelStorageSource_createLevelStorage)(p1, p2, p3, p4);
}

#include "Minecraft.h"
static MinecraftCommands * (Minecraft::*_Minecraft_getCommands)();
MinecraftCommands * Minecraft::getCommands() {
    return (this->*_Minecraft_getCommands)();
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
static int (*_LevelSettings_parseSeedString)(mcpe::string const &, unsigned int);
int LevelSettings::parseSeedString(mcpe::string const & p1, unsigned int p2) {
    return _LevelSettings_parseSeedString(p1, p2);
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

#include "Crypto.h"
static mce::UUID (*_Crypto_Random_generateUUID)();
mce::UUID Crypto::Random::generateUUID() {
    return _Crypto_Random_generateUUID();
}

#include "ContentIdentity.h"
ContentIdentity * ContentIdentity::EMPTY;

#include "Common.h"
static mcpe::string (*_Common_getGameVersionStringNet)();
mcpe::string Common::getGameVersionStringNet() {
    return _Common_getGameVersionStringNet();
}

#include "legacy/Xbox.h"
static int vti_Legacy_Pre_1_8_xbox_services_local_config_get_value_from_local_storage;
mcpe::string Legacy::Pre_1_8::xbox::services::local_config::get_value_from_local_storage(mcpe::string const & p1) {
    union { void* voidp; mcpe::string (Legacy::Pre_1_8::xbox::services::local_config::*funcp)(mcpe::string const &); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_Legacy_Pre_1_8_xbox_services_local_config_get_value_from_local_storage];
    return (this->*u.funcp)(p1);
}

#include "legacy/App.h"
static int vti_Legacy_Pre_1_8_App_quit;
void Legacy::Pre_1_8::App::quit() {
    union { void* voidp; void (Legacy::Pre_1_8::App::*funcp)(); } u;
    u.funcp = nullptr;
    u.voidp = vtable[vti_Legacy_Pre_1_8_App_quit];
    (this->*u.funcp)();
}

static int resolve_vtable_func(void** vtable, void* what) {
    for (int i = 0; ; i++) {
        if (vtable[i] == nullptr)
            return -1;
        if (vtable[i] == what)
            return i;
    }
}
void minecraft_symbols_init(void* handle) {
    ((void*&) _ResourceLoaders_registerLoader) = hybris_dlsym(handle, "_ZN15ResourceLoaders14registerLoaderE18ResourceFileSystemSt10unique_ptrI14ResourceLoaderSt14default_deleteIS2_EE");
    if (_ResourceLoaders_registerLoader == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15ResourceLoaders14registerLoaderE18ResourceFileSystemSt10unique_ptrI14ResourceLoaderSt14default_deleteIS2_EE");
    ((void*&) _Social_UserManager_CreateUserManager) = hybris_dlsym(handle, "_ZN6Social11UserManager17CreateUserManagerEv");
    if (_Social_UserManager_CreateUserManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Social11UserManager17CreateUserManagerEv");
    ((void*&) _xbox_services_xbox_services_error_code_category) = hybris_dlsym(handle, "_ZN4xbox8services33xbox_services_error_code_categoryEv");
    if (_xbox_services_xbox_services_error_code_category == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services33xbox_services_error_code_categoryEv");
    ((void*&) _web_json_value_value) = hybris_dlsym(handle, "_ZN3web4json5valueC2Ev");
    if (_web_json_value_value == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5valueC2Ev");
    ((void*&) _web_json_value_value2) = hybris_dlsym(handle, "_ZN3web4json5valueC2ESs");
    if (_web_json_value_value2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5valueC2ESs");
    ((void*&) _web_json_value_value3) = hybris_dlsym(handle, "_ZN3web4json5valueC2ERKS1_");
    if (_web_json_value_value3 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5valueC2ERKS1_");
    ((void*&) _web_json_value_value4) = hybris_dlsym(handle, "_ZN3web4json5valueC2EOS1_");
    if (_web_json_value_value4 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5valueC2EOS1_");
    ((void*&) _web_json_value_operator) = hybris_dlsym(handle, "_ZN3web4json5valueixERKSs");
    if (_web_json_value_operator == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5valueixERKSs");
    ((void*&) _web_json_value_operator2) = hybris_dlsym(handle, "_ZN3web4json5valueaSEOS1_");
    if (_web_json_value_operator2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5valueaSEOS1_");
    ((void*&) _web_json_value_to_string) = hybris_dlsym(handle, "_ZNK3web4json5value9to_stringEv");
    if (_web_json_value_to_string == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3web4json5value9to_stringEv");
    ((void*&) _web_json_value_erase) = hybris_dlsym(handle, "_ZN3web4json5value5eraseERKSs");
    if (_web_json_value_erase == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3web4json5value5eraseERKSs");
    ((void*&) _xbox_services_java_interop_get_java_interop_singleton) = hybris_dlsym(handle, "_ZN4xbox8services12java_interop26get_java_interop_singletonEv");
    if (_xbox_services_java_interop_get_java_interop_singleton == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services12java_interop26get_java_interop_singletonEv");
    ((void*&) _xbox_services_xbox_live_app_config_title_id) = hybris_dlsym(handle, "_ZN4xbox8services20xbox_live_app_config8title_idEv");
    if (_xbox_services_xbox_live_app_config_title_id == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services20xbox_live_app_config8title_idEv");
    ((void*&) _xbox_services_xbox_live_app_config_get_app_config_singleton) = hybris_dlsym(handle, "_ZN4xbox8services20xbox_live_app_config24get_app_config_singletonEv");
    if (_xbox_services_xbox_live_app_config_get_app_config_singleton == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services20xbox_live_app_config24get_app_config_singletonEv");
    void** vt_xbox_services_local_config = (void**) hybris_dlsym(handle, "_ZTVN4xbox8services12local_configE") + 2;
    vti_xbox_services_local_config_get_value_from_local_storage = resolve_vtable_func(vt_xbox_services_local_config, hybris_dlsym(handle, "_ZN4xbox8services12local_config28get_value_from_local_storageERKSsS3_S3_"));
    if (vti_xbox_services_local_config_get_value_from_local_storage == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN4xbox8services12local_config28get_value_from_local_storageERKSsS3_S3_");
    vti_xbox_services_local_config_write_value_to_local_storage = resolve_vtable_func(vt_xbox_services_local_config, hybris_dlsym(handle, "_ZN4xbox8services12local_config28write_value_to_local_storageERKSsS3_S3_S3_"));
    if (vti_xbox_services_local_config_write_value_to_local_storage == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN4xbox8services12local_config28write_value_to_local_storageERKSsS3_S3_S3_");
    ((void*&) _xbox_services_local_config_get_local_config_singleton) = hybris_dlsym(handle, "_ZN4xbox8services12local_config26get_local_config_singletonEv");
    if (_xbox_services_local_config_get_local_config_singleton == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services12local_config26get_local_config_singletonEv");
    ((void*&) _xbox_services_xsapi_singleton_destructor) = hybris_dlsym(handle, "_ZN4xbox8services15xsapi_singletonD2Ev");
    if (_xbox_services_xsapi_singleton_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services15xsapi_singletonD2Ev");
    ((void*&) _xbox_services_system_user_impl_user_signed_out) = hybris_dlsym(handle, "_ZN4xbox8services6system9user_impl15user_signed_outEv");
    if (_xbox_services_system_user_impl_user_signed_out == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system9user_impl15user_signed_outEv");
    ((void*&) _xbox_services_system_user_impl_android_get_instance) = hybris_dlsym(handle, "_ZN4xbox8services6system17user_impl_android12get_instanceEv");
    if (_xbox_services_system_user_impl_android_get_instance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system17user_impl_android12get_instanceEv");
    ((void*&) _pplx_task_completion_event_java_rps_ticket_set) = hybris_dlsym(handle, "_ZNK4pplx21task_completion_eventIN4xbox8services6system15java_rps_ticketEE3setES4_");
    if (_pplx_task_completion_event_java_rps_ticket_set == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK4pplx21task_completion_eventIN4xbox8services6system15java_rps_ticketEE3setES4_");
    ((void*&) _pplx_task_completion_event_auth_flow_result_set) = hybris_dlsym(handle, "_ZNK4pplx21task_completion_eventIN4xbox8services6system16auth_flow_resultEE3setES4_");
    if (_pplx_task_completion_event_auth_flow_result_set == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK4pplx21task_completion_eventIN4xbox8services6system16auth_flow_resultEE3setES4_");
    ((void*&) _pplx_task_completion_event_xbox_live_result_void_set) = hybris_dlsym(handle, "_ZNK4pplx21task_completion_eventIN4xbox8services16xbox_live_resultIvEEE3setES4_");
    if (_pplx_task_completion_event_xbox_live_result_void_set == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK4pplx21task_completion_eventIN4xbox8services16xbox_live_resultIvEEE3setES4_");
    ((void*&) _pplx_task_xbox_live_result_void_get) = hybris_dlsym(handle, "_ZNK4pplx4taskIN4xbox8services16xbox_live_resultIvEEE3getEv");
    if (_pplx_task_xbox_live_result_void_get == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK4pplx4taskIN4xbox8services16xbox_live_resultIvEEE3getEv");
    ((void*&) _pplx_task_xbox_live_result_token_and_signature_result_get) = hybris_dlsym(handle, "_ZNK4pplx4taskIN4xbox8services16xbox_live_resultINS2_6system26token_and_signature_resultEEEE3getEv");
    if (_pplx_task_xbox_live_result_token_and_signature_result_get == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK4pplx4taskIN4xbox8services16xbox_live_resultINS2_6system26token_and_signature_resultEEEE3getEv");
    ((void*&) _xbox_services_system_auth_config_set_xtoken_composition) = hybris_dlsym(handle, "_ZN4xbox8services6system11auth_config22set_xtoken_compositionESt6vectorINS1_19token_identity_typeESaIS4_EE");
    if (_xbox_services_system_auth_config_set_xtoken_composition == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system11auth_config22set_xtoken_compositionESt6vectorINS1_19token_identity_typeESaIS4_EE");
    ((void*&) _xbox_services_system_auth_config_xbox_live_endpoint) = hybris_dlsym(handle, "_ZNK4xbox8services6system11auth_config18xbox_live_endpointEv");
    if (_xbox_services_system_auth_config_xbox_live_endpoint == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK4xbox8services6system11auth_config18xbox_live_endpointEv");
    ((void*&) _xbox_services_system_auth_manager_get_auth_manager_instance) = hybris_dlsym(handle, "_ZN4xbox8services6system12auth_manager25get_auth_manager_instanceEv");
    if (_xbox_services_system_auth_manager_get_auth_manager_instance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system12auth_manager25get_auth_manager_instanceEv");
    ((void*&) _xbox_services_system_auth_manager_set_rps_ticket) = hybris_dlsym(handle, "_ZN4xbox8services6system12auth_manager14set_rps_ticketERKSs");
    if (_xbox_services_system_auth_manager_set_rps_ticket == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system12auth_manager14set_rps_ticketERKSs");
    ((void*&) _xbox_services_system_auth_manager_initialize_default_nsal) = hybris_dlsym(handle, "_ZN4xbox8services6system12auth_manager23initialize_default_nsalEN4pplx18cancellation_tokenE");
    if (_xbox_services_system_auth_manager_initialize_default_nsal == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system12auth_manager23initialize_default_nsalEN4pplx18cancellation_tokenE");
    ((void*&) _xbox_services_system_auth_manager_initialize_title_nsal) = hybris_dlsym(handle, "_ZN4xbox8services6system12auth_manager21initialize_title_nsalERKSsN4pplx18cancellation_tokenE");
    if (_xbox_services_system_auth_manager_initialize_title_nsal == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system12auth_manager21initialize_title_nsalERKSsN4pplx18cancellation_tokenE");
    ((void*&) _xbox_services_system_auth_manager_internal_get_token_and_signature) = hybris_dlsym(handle, "_ZN4xbox8services6system12auth_manager32internal_get_token_and_signatureESsRKSsS4_SsRKSt6vectorIhSaIhEEbbS4_N4pplx18cancellation_tokenE");
    if (_xbox_services_system_auth_manager_internal_get_token_and_signature == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system12auth_manager32internal_get_token_and_signatureESsRKSsS4_SsRKSt6vectorIhSaIhEEbbS4_N4pplx18cancellation_tokenE");
    ((void*&) _xbox_services_system_auth_manager_get_auth_config) = hybris_dlsym(handle, "_ZN4xbox8services6system12auth_manager15get_auth_configEv");
    if (_xbox_services_system_auth_manager_get_auth_config == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system12auth_manager15get_auth_configEv");
    ((void*&) xbox::services::system::user_auth_android::s_rpsTicketCompletionEvent) = hybris_dlsym(handle, "_ZN4xbox8services6system17user_auth_android26s_rpsTicketCompletionEventE");
    if (xbox::services::system::user_auth_android::s_rpsTicketCompletionEvent == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system17user_auth_android26s_rpsTicketCompletionEventE");
    ((void*&) xbox::services::system::user_auth_android::s_signOutCompleteEvent) = hybris_dlsym(handle, "_ZN4xbox8services6system17user_auth_android22s_signOutCompleteEventE");
    if (xbox::services::system::user_auth_android::s_signOutCompleteEvent == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system17user_auth_android22s_signOutCompleteEventE");
    ((void*&) _xbox_services_system_user_auth_android_get_instance) = hybris_dlsym(handle, "_ZN4xbox8services6system17user_auth_android12get_instanceEv");
    if (_xbox_services_system_user_auth_android_get_instance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system17user_auth_android12get_instanceEv");
    ((void*&) _xbox_services_system_user_auth_android_complete_sign_in_with_ui) = hybris_dlsym(handle, "_ZN4xbox8services6system17user_auth_android24complete_sign_in_with_uiERKNS1_16auth_flow_resultE");
    if (_xbox_services_system_user_auth_android_complete_sign_in_with_ui == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4xbox8services6system17user_auth_android24complete_sign_in_with_uiERKNS1_16auth_flow_resultE");
    ((void*&) _ServerInstance_ServerInstance) = hybris_dlsym(handle, "_ZN14ServerInstanceC2ER13IMinecraftAppR9WhitelistRK14PermissionsMapP15FilePathManagerNSt6chrono8durationIxSt5ratioILx1ELx1EEEESsSsSs13LevelSettingsibiiibRKSt6vectorISsSaISsEESsRKN3mce4UUIDER18IMinecraftEventingR22ResourcePackRepositoryRK18ContentTierManagerR19ResourcePackManagerSt8functionIFSt10unique_ptrI12LevelStorageSt14default_deleteISZ_EER9SchedulerEERKSsP9LevelDataP22TextFilteringProcessorPSV_SX_IFvS18_EES1F_");
    if (_ServerInstance_ServerInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstanceC2ER13IMinecraftAppR9WhitelistRK14PermissionsMapP15FilePathManagerNSt6chrono8durationIxSt5ratioILx1ELx1EEEESsSsSs13LevelSettingsibiiibRKSt6vectorISsSaISsEESsRKN3mce4UUIDER18IMinecraftEventingR22ResourcePackRepositoryRK18ContentTierManagerR19ResourcePackManagerSt8functionIFSt10unique_ptrI12LevelStorageSt14default_deleteISZ_EER9SchedulerEERKSsP9LevelDataP22TextFilteringProcessorPSV_SX_IFvS18_EES1F_");
    ((void*&) _ServerInstance_destructor) = hybris_dlsym(handle, "_ZN14ServerInstanceD2Ev");
    if (_ServerInstance_destructor == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstanceD2Ev");
    ((void*&) _ServerInstance_startServerThread) = hybris_dlsym(handle, "_ZN14ServerInstance17startServerThreadEv");
    if (_ServerInstance_startServerThread == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance17startServerThreadEv");
    ((void*&) _ServerInstance_leaveGameSync) = hybris_dlsym(handle, "_ZN14ServerInstance13leaveGameSyncEv");
    if (_ServerInstance_leaveGameSync == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance13leaveGameSyncEv");
    ((void*&) _ServerInstance_queueForServerThread) = hybris_dlsym(handle, "_ZN14ServerInstance20queueForServerThreadESt8functionIFvvEE");
    if (_ServerInstance_queueForServerThread == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ServerInstance20queueForServerThreadESt8functionIFvvEE");
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
    ((void*&) _Mouse_feed) = hybris_dlsym(handle, "_ZN5Mouse4feedEccssss");
    if (_Mouse_feed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Mouse4feedEccssss");
    ((void*&) _Level_createRandomSeed) = hybris_dlsym(handle, "_ZN5Level16createRandomSeedEv");
    if (_Level_createRandomSeed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN5Level16createRandomSeedEv");
    ((void*&) _PermissionsMap_PermissionsMap) = hybris_dlsym(handle, "_ZN14PermissionsMapC2Eb");
    if (_PermissionsMap_PermissionsMap == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14PermissionsMapC2Eb");
    ((void*&) _MinecraftCommands_setOutputSender) = hybris_dlsym(handle, "_ZN17MinecraftCommands15setOutputSenderESt10unique_ptrI19CommandOutputSenderSt14default_deleteIS1_EE");
    if (_MinecraftCommands_setOutputSender == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftCommands15setOutputSenderESt10unique_ptrI19CommandOutputSenderSt14default_deleteIS1_EE");
    ((void*&) _MinecraftCommands_requestCommandExecution) = hybris_dlsym(handle, "_ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKSsib");
    if (_MinecraftCommands_requestCommandExecution == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK17MinecraftCommands23requestCommandExecutionESt10unique_ptrI13CommandOriginSt14default_deleteIS1_EERKSsib");
    ((void*&) _I18n_get) = hybris_dlsym(handle, "_ZN4I18n3getERKSsRKSt6vectorISsSaISsEE");
    if (_I18n_get == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4I18n3getERKSsRKSt6vectorISsSaISsEE");
    ((void*&) _I18n_chooseLanguage) = hybris_dlsym(handle, "_ZN4I18n14chooseLanguageERKSs");
    if (_I18n_chooseLanguage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4I18n14chooseLanguageERKSs");
    ((void*&) _I18n_loadLanguages) = hybris_dlsym(handle, "_ZN4I18n13loadLanguagesER19ResourcePackManagerRKSs");
    if (_I18n_loadLanguages == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN4I18n13loadLanguagesER19ResourcePackManagerRKSs");
    ((void*&) _MinecraftScreenModel_navigateToXblConsoleSignInScreen) = hybris_dlsym(handle, "_ZN20MinecraftScreenModel32navigateToXblConsoleSignInScreenERKSsS1_");
    if (_MinecraftScreenModel_navigateToXblConsoleSignInScreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20MinecraftScreenModel32navigateToXblConsoleSignInScreenERKSsS1_");
    ((void*&) _MinecraftScreenModel_navigateToXblConsoleSignInSucceededScreen) = hybris_dlsym(handle, "_ZN20MinecraftScreenModel41navigateToXblConsoleSignInSucceededScreenERKN6Social12SignInResultESt8functionIFvS1_EEb");
    if (_MinecraftScreenModel_navigateToXblConsoleSignInSucceededScreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20MinecraftScreenModel41navigateToXblConsoleSignInSucceededScreenERKN6Social12SignInResultESt8functionIFvS1_EEb");
    ((void*&) _MinecraftScreenModel_leaveScreen) = hybris_dlsym(handle, "_ZN20MinecraftScreenModel11leaveScreenEv");
    if (_MinecraftScreenModel_leaveScreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN20MinecraftScreenModel11leaveScreenEv");
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
    ((void*&) _PackInstance_PackInstance) = hybris_dlsym(handle, "_ZN12PackInstanceC2EP12ResourcePackibP12PackSettings");
    if (_PackInstance_PackInstance == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN12PackInstanceC2EP12ResourcePackibP12PackSettings");
    ((void*&) ResourcePackStack::vtable_sym) = hybris_dlsym(handle, "_ZTV17ResourcePackStack");
    if (ResourcePackStack::vtable_sym == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV17ResourcePackStack");
    ((void*&) _ResourcePackStack_add) = hybris_dlsym(handle, "_ZN17ResourcePackStack3addE12PackInstanceRK22ResourcePackRepositoryb");
    if (_ResourcePackStack_add == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17ResourcePackStack3addE12PackInstanceRK22ResourcePackRepositoryb");
    ((void*&) _MinecraftEventing_MinecraftEventing) = hybris_dlsym(handle, "_ZN17MinecraftEventingC2ERKSs");
    if (_MinecraftEventing_MinecraftEventing == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftEventingC2ERKSs");
    ((void*&) _MinecraftEventing_init) = hybris_dlsym(handle, "_ZN17MinecraftEventing4initEv");
    if (_MinecraftEventing_init == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17MinecraftEventing4initEv");
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
    ((void*&) _MinecraftGame_doPrimaryClientReadyWork) = hybris_dlsym(handle, "_ZN13MinecraftGame24doPrimaryClientReadyWorkESt8functionIFvvEE");
    if (_MinecraftGame_doPrimaryClientReadyWork == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13MinecraftGame24doPrimaryClientReadyWorkESt8functionIFvvEE");
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
    ((void*&) _ClientInstance_getUser) = hybris_dlsym(handle, "_ZN14ClientInstance7getUserEv");
    if (_ClientInstance_getUser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ClientInstance7getUserEv");
    ((void*&) _ClientInstance__startLeaveGame) = hybris_dlsym(handle, "_ZN14ClientInstance15_startLeaveGameEv");
    if (_ClientInstance__startLeaveGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ClientInstance15_startLeaveGameEv");
    ((void*&) _ClientInstance__syncDestroyGame) = hybris_dlsym(handle, "_ZN14ClientInstance16_syncDestroyGameEv");
    if (_ClientInstance__syncDestroyGame == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN14ClientInstance16_syncDestroyGameEv");
    ((void*&) Keyboard::_states) = hybris_dlsym(handle, "_ZN8Keyboard7_statesE");
    if (Keyboard::_states == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard7_statesE");
    ((void*&) Keyboard::_inputCaretLocation) = hybris_dlsym(handle, "_ZN8Keyboard19_inputCaretLocationE");
    if (Keyboard::_inputCaretLocation == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard19_inputCaretLocationE");
    ((void*&) _Keyboard_feed) = hybris_dlsym(handle, "_ZN8Keyboard4feedEhi");
    if (_Keyboard_feed == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard4feedEhi");
    ((void*&) _Keyboard_feedText) = hybris_dlsym(handle, "_ZN8Keyboard8feedTextERKSsbh");
    if (_Keyboard_feedText == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN8Keyboard8feedTextERKSsbh");
    ((void*&) _CommandOutput_getMessages) = hybris_dlsym(handle, "_ZNK13CommandOutput11getMessagesEv");
    if (_CommandOutput_getMessages == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK13CommandOutput11getMessagesEv");
    ((void*&) _Scheduler_processCoroutines) = hybris_dlsym(handle, "_ZN9Scheduler17processCoroutinesENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE");
    if (_Scheduler_processCoroutines == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Scheduler17processCoroutinesENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE");
    ((void*&) _MinecraftScheduler_client) = hybris_dlsym(handle, "_ZN18MinecraftScheduler6clientEv");
    if (_MinecraftScheduler_client == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN18MinecraftScheduler6clientEv");
    ((void*&) NullTextToSpeechClient::myVtable) = hybris_dlsym(handle, "_ZTV22NullTextToSpeechClient");
    if (NullTextToSpeechClient::myVtable == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZTV22NullTextToSpeechClient");
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
    ((void*&) _App_init) = hybris_dlsym(handle, "_ZN3App4initER10AppContext");
    if (_App_init == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3App4initER10AppContext");
    void** vt_App = (void**) hybris_dlsym(handle, "_ZTV3App") + 2;
    vti_App_quit = resolve_vtable_func(vt_App, hybris_dlsym(handle, "_ZN3App4quitERKSsS1_"));
    if (vti_App_quit == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN3App4quitERKSsS1_");
    vti_App_wantToQuit = resolve_vtable_func(vt_App, hybris_dlsym(handle, "_ZN3App10wantToQuitEv"));
    if (vti_App_wantToQuit == -1) Log::error("MinecraftSymbols", "Unresolved vtable symbol: %s", "_ZN3App10wantToQuitEv");
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
    ((void*&) _SaveTransactionManager_SaveTransactionManager) = hybris_dlsym(handle, "_ZN22SaveTransactionManagerC2ESt8functionIFvbEE");
    if (_SaveTransactionManager_SaveTransactionManager == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22SaveTransactionManagerC2ESt8functionIFvbEE");
    ((void*&) SharedConstants::MajorVersion) = hybris_dlsym(handle, "_ZN15SharedConstants12MajorVersionE");
    if (SharedConstants::MajorVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants12MajorVersionE");
    ((void*&) SharedConstants::MinorVersion) = hybris_dlsym(handle, "_ZN15SharedConstants12MinorVersionE");
    if (SharedConstants::MinorVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants12MinorVersionE");
    ((void*&) SharedConstants::PatchVersion) = hybris_dlsym(handle, "_ZN15SharedConstants12PatchVersionE");
    if (SharedConstants::PatchVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants12PatchVersionE");
    ((void*&) SharedConstants::RevisionVersion) = hybris_dlsym(handle, "_ZN15SharedConstants15RevisionVersionE");
    if (SharedConstants::RevisionVersion == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15SharedConstants15RevisionVersionE");
    ((void*&) _AppResourceLoader_AppResourceLoader) = hybris_dlsym(handle, "_ZN17AppResourceLoaderC2ESt8functionIFSsvEE");
    if (_AppResourceLoader_AppResourceLoader == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17AppResourceLoaderC2ESt8functionIFSsvEE");
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
    ((void*&) _Social_User_getLiveUser) = hybris_dlsym(handle, "_ZNK6Social4User11getLiveUserEv");
    if (_Social_User_getLiveUser == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK6Social4User11getLiveUserEv");
    ((void*&) _Social_XboxLiveUser__handleUISignInNoError) = hybris_dlsym(handle, "_ZN6Social12XboxLiveUser22_handleUISignInNoErrorERN4xbox8services6system14sign_in_resultESt8functionIFvNS_12SignInResultEbEE");
    if (_Social_XboxLiveUser__handleUISignInNoError == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Social12XboxLiveUser22_handleUISignInNoErrorERN4xbox8services6system14sign_in_resultESt8functionIFvNS_12SignInResultEbEE");
    ((void*&) _Automation_AutomationClient_AutomationClient) = hybris_dlsym(handle, "_ZN10Automation16AutomationClientC2ER13IMinecraftApp");
    if (_Automation_AutomationClient_AutomationClient == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN10Automation16AutomationClientC2ER13IMinecraftApp");
    ((void*&) _SkinPackKeyProvider_SkinPackKeyProvider) = hybris_dlsym(handle, "_ZN19SkinPackKeyProviderC2Ev");
    if (_SkinPackKeyProvider_SkinPackKeyProvider == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19SkinPackKeyProviderC2Ev");
    ((void*&) _PackManifestFactory_PackManifestFactory) = hybris_dlsym(handle, "_ZN19PackManifestFactoryC2ER14IPackTelemetry");
    if (_PackManifestFactory_PackManifestFactory == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN19PackManifestFactoryC2ER14IPackTelemetry");
    ((void*&) _PackSourceFactory_PackSourceFactory) = hybris_dlsym(handle, "_ZN17PackSourceFactoryC2EP7Options");
    if (_PackSourceFactory_PackSourceFactory == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN17PackSourceFactoryC2EP7Options");
    ((void*&) _ResourcePackRepository_ResourcePackRepository) = hybris_dlsym(handle, "_ZN22ResourcePackRepositoryC2ER18IMinecraftEventingR19PackManifestFactoryR29IContentAccessibilityProviderP15FilePathManagerR17PackSourceFactory");
    if (_ResourcePackRepository_ResourcePackRepository == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN22ResourcePackRepositoryC2ER18IMinecraftEventingR19PackManifestFactoryR29IContentAccessibilityProviderP15FilePathManagerR17PackSourceFactory");
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
    ((void*&) _DedicatedServerCommandOrigin_DedicatedServerCommandOrigin) = hybris_dlsym(handle, "_ZN28DedicatedServerCommandOriginC2ERKSsR9Minecraft");
    if (_DedicatedServerCommandOrigin_DedicatedServerCommandOrigin == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN28DedicatedServerCommandOriginC2ERKSsR9Minecraft");
    ((void*&) _Social_MultiplayerXBL_MultiplayerXBL) = hybris_dlsym(handle, "_ZN6Social14MultiplayerXBLC2Ev");
    if (_Social_MultiplayerXBL_MultiplayerXBL == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Social14MultiplayerXBLC2Ev");
    ((void*&) mce::UUID::EMPTY) = hybris_dlsym(handle, "_ZN3mce4UUID5EMPTYE");
    if (mce::UUID::EMPTY == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3mce4UUID5EMPTYE");
    ((void*&) _mce_UUID_fromString) = hybris_dlsym(handle, "_ZN3mce4UUID10fromStringERKSs");
    if (_mce_UUID_fromString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN3mce4UUID10fromStringERKSs");
    ((void*&) _mce_UUID_asString) = hybris_dlsym(handle, "_ZNK3mce4UUID8asStringEv");
    if (_mce_UUID_asString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK3mce4UUID8asStringEv");
    ((void*&) _ExternalFileLevelStorageSource_ExternalFileLevelStorageSource) = hybris_dlsym(handle, "_ZN30ExternalFileLevelStorageSourceC2EP15FilePathManagerSt10shared_ptrI22SaveTransactionManagerE");
    if (_ExternalFileLevelStorageSource_ExternalFileLevelStorageSource == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN30ExternalFileLevelStorageSourceC2EP15FilePathManagerSt10shared_ptrI22SaveTransactionManagerE");
    ((void*&) _ExternalFileLevelStorageSource_createLevelStorage) = hybris_dlsym(handle, "_ZN30ExternalFileLevelStorageSource18createLevelStorageER9SchedulerRKSsRK15ContentIdentityRK19IContentKeyProvider");
    if (_ExternalFileLevelStorageSource_createLevelStorage == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN30ExternalFileLevelStorageSource18createLevelStorageER9SchedulerRKSsRK15ContentIdentityRK19IContentKeyProvider");
    ((void*&) _Minecraft_getCommands) = hybris_dlsym(handle, "_ZN9Minecraft11getCommandsEv");
    if (_Minecraft_getCommands == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN9Minecraft11getCommandsEv");
    ((void*&) _LevelSettings_LevelSettings) = hybris_dlsym(handle, "_ZN13LevelSettingsC2Ev");
    if (_LevelSettings_LevelSettings == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettingsC2Ev");
    ((void*&) _LevelSettings_LevelSettings2) = hybris_dlsym(handle, "_ZN13LevelSettingsC2ERKS_");
    if (_LevelSettings_LevelSettings2 == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettingsC2ERKS_");
    ((void*&) _LevelSettings_parseSeedString) = hybris_dlsym(handle, "_ZN13LevelSettings15parseSeedStringERKSsj");
    if (_LevelSettings_parseSeedString == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN13LevelSettings15parseSeedStringERKSsj");
    ((void*&) _Options_getFullscreen) = hybris_dlsym(handle, "_ZNK7Options13getFullscreenEv");
    if (_Options_getFullscreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZNK7Options13getFullscreenEv");
    ((void*&) _Options_setFullscreen) = hybris_dlsym(handle, "_ZN7Options13setFullscreenEb");
    if (_Options_setFullscreen == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN7Options13setFullscreenEb");
    ((void*&) _Crypto_Random_generateUUID) = hybris_dlsym(handle, "_ZN6Crypto6Random12generateUUIDEv");
    if (_Crypto_Random_generateUUID == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Crypto6Random12generateUUIDEv");
    ((void*&) ContentIdentity::EMPTY) = hybris_dlsym(handle, "_ZN15ContentIdentity5EMPTYE");
    if (ContentIdentity::EMPTY == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN15ContentIdentity5EMPTYE");
    ((void*&) _Common_getGameVersionStringNet) = hybris_dlsym(handle, "_ZN6Common23getGameVersionStringNetEv");
    if (_Common_getGameVersionStringNet == nullptr) Log::error("MinecraftSymbols", "Unresolved symbol: %s", "_ZN6Common23getGameVersionStringNetEv");
    vti_Legacy_Pre_1_8_xbox_services_local_config_get_value_from_local_storage = resolve_vtable_func(vt_xbox_services_local_config, hybris_dlsym(handle, "_ZN4xbox8services12local_config28get_value_from_local_storageERKSs"));
    vti_Legacy_Pre_1_8_App_quit = resolve_vtable_func(vt_App, hybris_dlsym(handle, "_ZN3App4quitEv"));
}