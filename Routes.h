/* 
 * File:   Routes.h
 * Author: saucelabs
 *
 * Created on December 24, 2014, 8:58 AM
 */

#ifndef ROUTES_H
#define	ROUTES_H

#include <string>
namespace Routes
{
    static const std::string STATUS = "/wd/hub/status";
    static const std::string SESSION = "/wd/hub/session";
    static const std::string SESSIONS = "/wd/hub/sessions";
    static const std::string CONTEXT_CONTEXT = "/wd/hub/session/{0}/context";
    static const std::string CONTEXT_CONTEXTS = "/wd/hub/session/{0}/contexts";
    static const std::string CONTEXT_ELEMENT = "/wd/hub/session/{0}/element";
    static const std::string CONTEXT_ELEMENTS = "/wd/hub/session/{0}/elements";
    static const std::string ELEMENT_VALUE = "/wd/hub/session/{0}/element/{1}/value";
    static const std::string ELEMENT_CLICK = "/wd/hub/session/{0}/element/{1}/click";
    static const std::string ELEMENT_TEXT = "/wd/hub/session/{0}/element/{1}/text";
    static const std::string ELEMENT_DISPLAYED = "/wd/hub/session/{0}/element/{1}/displayed";
    static const std::string ELEMENT_ENABLED = "/wd/hub/session/{0}/element/{1}/enabled";
    static const std::string ELEMENT_SELECTED = "/wd/hub/session/{0}/element/{1}/selected";
    static const std::string ELEMENT_LOCATION = "/wd/hub/session/{0}/element/{1}/location";
    static const std::string ELEMENT_LOCATION_IN_VIEW = "/wd/hub/session/{0}/element/{1}/location_in_view";
    static const std::string ELEMENT_SIZE = "/wd/hub/session/{0}/element/{1}/size";
    static const std::string ELEMENT_PAGEINDEX = "/wd/hub/session/{0}/element/{1}/pageIndex";
    static const std::string ELEMENT_ATTR_NAME = "/wd/hub/session/{0}/element/{1}/attribute/:name";
    static const std::string ELEMENT_PROPERTYNAME = "/wd/hub/session/{0}/element/{1}/css/:propertyName";
    static const std::string ELEMENT_OTHERID = "/wd/hub/session/{0}/element/{1}/equals/:otherId";
    static const std::string ELEMENT_NAME = "/wd/hub/session/{0}/element/{1}/name";
    static const std::string ELEMENT_CLEAR = "/wd/hub/session/{0}/element/{1}/clear";
    static const std::string CONTEXT_FRAME = "/wd/hub/session/{0}/frame";
    static const std::string CONTEXT_KEYS = "/wd/hub/session/{0}/keys";
    static const std::string CONTEXT_LOCATION = "/wd/hub/session/{0}/location";
    static const std::string CONTEXT_SOURCE = "/wd/hub/session/{0}/source";
    static const std::string CONTEXT_ALERT_TEXT = "/wd/hub/session/{0}/alert_text";
    static const std::string CONTEXT_ACCEPT_ALERT = "/wd/hub/session/{0}/accept_alert";
    static const std::string CONTEXT_DISMISS_ALERT = "/wd/hub/session/{0}/dismiss_alert";
    static const std::string TIMEOUTS_IMPLICIT_WAIT = "/wd/hub/session/{0}/timeouts/implicit_wait";
    static const std::string TIMEOUTS_ASYNC_SCRIPT = "/wd/hub/session/{0}/timeouts/async_script";
    static const std::string CONTEXT_ORIENTATION = "/wd/hub/session/{0}/orientation";
    static const std::string CONTEXT_SCREENSHOT = "/wd/hub/session/{0}/screenshot";
    static const std::string ELEMENT_ELEMENT = "/wd/hub/session/{0}/element/{1}/element";
    static const std::string ELEMENT_ELEMENTS = "/wd/hub/session/{0}/element/{1}/elements";
    static const std::string TOUCH_CLICK = "/wd/hub/session/{0}/touch/click";
    static const std::string TOUCH_LONGCLICK = "/wd/hub/session/{0}/touch/longclick";
    static const std::string TOUCH_DOWN = "/wd/hub/session/{0}/touch/down";
    static const std::string TOUCH_UP = "/wd/hub/session/{0}/touch/up";
    static const std::string TOUCH_MOVE = "/wd/hub/session/{0}/touch/move";
    static const std::string TOUCH_FLICK = "/wd/hub/session/{0}/touch/flick";
    static const std::string CONTEXT_URL = "/wd/hub/session/{0}/url";
    static const std::string ELEMENT_ACTIVE = "/wd/hub/session/{0}/element/active";
    static const std::string CONTEXT_WINDOW_HANDLE = "/wd/hub/session/{0}/window_handle";
    static const std::string CONTEXT_WINDOW_HANDLES = "/wd/hub/session/{0}/window_handles";
    static const std::string CONTEXT_WINDOW = "/wd/hub/session/{0}/window";
    static const std::string WINDOW_SIZE = "/wd/hub/session/{0}/window/{1}/size";
    static const std::string CONTEXT_EXECUTE = "/wd/hub/session/{0}/execute";
    static const std::string CONTEXT_EXECUTE_ASYNC = "/wd/hub/session/{0}/execute_async";
    static const std::string CONTEXT_TITLE = "/wd/hub/session/{0}/title";
    static const std::string ELEMENT_SUBMIT = "/wd/hub/session/{0}/element/{1}/submit";
    static const std::string CONTEXT_MOVETO = "/wd/hub/session/{0}/moveto";
    static const std::string CONTEXT_CLICK = "/wd/hub/session/{0}/click";
    static const std::string CONTEXT_BACK = "/wd/hub/session/{0}/back";
    static const std::string CONTEXT_FORWARD = "/wd/hub/session/{0}/forward";
    static const std::string CONTEXT_REFRESH = "/wd/hub/session/{0}/refresh";
    static const std::string CONTEXT_COOKIE = "/wd/hub/session/{0}/cookie";
    static const std::string COOKIE_NAME = "/wd/hub/session/{0}/cookie/:name";
    static const std::string CONTEXT_LOG = "/wd/hub/session/{0}/log";
    static const std::string LOG_TYPES = "/wd/hub/session/{0}/log/types";
    static const std::string CONTEXT_TIMEOUTS = "/wd/hub/session/{0}/timeouts";
    static const std::string CONTEXT_NETWORK_CONNECTION = "/wd/hub/session/{0}/network_connection";
    static const std::string TOUCH_PERFORM = "/wd/hub/session/{0}/touch/perform";
    static const std::string CONTEXT_RECEIVE_ASYNC_RESPONSE = "/wd/hub/session/{0}/receive_async_response";
    static const std::string CONTEXT_PRODUCE_ERROR = "/wd/hub/produce_error";
    static const std::string CONTEXT_CRASH = "/wd/hub/crash";
    static const std::string CONTEXT_PIG = "/test/guinea-pig";
    static const std::string IME_AVAILABLE_ENGINES = "/wd/hub/session/{0}/ime/available_engines";
    static const std::string IME_ACTIVE_ENGINE = "/wd/hub/session/{0}/ime/active_engine";
    static const std::string IME_ACTIVATED = "/wd/hub/session/{0}/ime/activated";
    static const std::string IME_DEACTIVATE = "/wd/hub/session/{0}/ime/deactivate";
    static const std::string IME_ACTIVATE = "/wd/hub/session/{0}/ime/activate";
    static const std::string CONTEXT_LOCAL_STORAGE = "/wd/hub/session/{0}/local_storage";
    static const std::string LOCAL_STORAGE_KEY = "/wd/hub/session/{0}/local_storage/key/{1}";
    static const std::string LOCAL_STORAGE_SIZE = "/wd/hub/session/{0}/local_storage/size";
    static const std::string WINDOW_POSITION = "/wd/hub/session/{0}/window/{1}/position";
    static const std::string WINDOW_MAXIMIZE = "/wd/hub/session/{0}/window/{1}/maximize";
    static const std::string ELEMENT_SESSION = "/wd/hub/session/{0}/element/{1}";
    static const std::string CONTEXT_BUTTONDOWN = "/wd/hub/session/{0}/buttondown";
    static const std::string CONTEXT_BUTTONUP = "/wd/hub/session/{0}/buttonup";
    static const std::string CONTEXT_DOUBLECLICK = "/wd/hub/session/{0}/doubleclick";
    static const std::string TOUCH_SCROLL = "/wd/hub/session/{0}/touch/scroll";
    static const std::string TOUCH_DOUBLECLICK = "/wd/hub/session/{0}/touch/doubleclick";
    static const std::string CONTEXT_SESSION_STORAGE = "/wd/hub/session/{0}/session_storage";
    static const std::string SESSION_STORAGE_KEY = "/wd/hub/session/{0}/session_storage/key/{1}";
    static const std::string SESSION_STORAGE_SIZE = "/wd/hub/session/{0}/session_storage/size";
    static const std::string APPLICATION_CACHE_STATUS = "/wd/hub/session/{0}/application_cache/status";
    
    // APPIUM
    static const std::string DEVICE_SHAKE = "/wd/hub/session/{0}/appium/device/shake";
    static const std::string DEVICE_LOCK = "/wd/hub/session/{0}/appium/device/lock";
    static const std::string DEVICE_UNLOCK = "/wd/hub/session/{0}/appium/device/unlock";
    static const std::string DEVICE_IS_LOCKED = "/wd/hub/session/{0}/appium/device/is_locked";
    static const std::string DEVICE_PRESS_KEYCODE = "/wd/hub/session/{0}/appium/device/press_keycode";
    static const std::string DEVICE_LONG_PRESS_KEYCODE = "/wd/hub/session/{0}/appium/device/long_press_keycode";
    static const std::string DEVICE_KEYEVENT = "/wd/hub/session/{0}/appium/device/keyevent";
    static const std::string DEVICE_ROTATE = "/wd/hub/session/{0}/appium/device/rotate";
    static const std::string DEVICE_CURRENT_ACTIVITY = "/wd/hub/session/{0}/appium/device/current_activity";
    static const std::string DEVICE_INSTALL_APP = "/wd/hub/session/{0}/appium/device/install_app";
    static const std::string DEVICE_REMOVE_APP = "/wd/hub/session/{0}/appium/device/remove_app";
    static const std::string DEVICE_APP_INSTALLED = "/wd/hub/session/{0}/appium/device/app_installed";
    static const std::string DEVICE_HIDE_KEYBOARD = "/wd/hub/session/{0}/appium/device/hide_keyboard";
    static const std::string DEVICE_PUSH_FILE = "/wd/hub/session/{0}/appium/device/push_file";
    static const std::string DEVICE_PULL_FILE = "/wd/hub/session/{0}/appium/device/pull_file";
    static const std::string DEVICE_PULL_FOLDER = "/wd/hub/session/{0}/appium/device/pull_folder";
    static const std::string DEVICE_TOGGLE_AIRPLANE_MODE = "/wd/hub/session/{0}/appium/device/toggle_airplane_mode";
    static const std::string DEVICE_TOGGLE_DATA = "/wd/hub/session/{0}/appium/device/toggle_data";
    static const std::string DEVICE_TOGGLE_WIFI = "/wd/hub/session/{0}/appium/device/toggle_wifi";
    static const std::string DEVICE_TOGGLE_LOCATION_SERVICES = "/wd/hub/session/{0}/appium/device/toggle_location_services";
    static const std::string DEVICE_OPEN_NOTIFICATIONS = "/wd/hub/session/{0}/appium/device/open_notifications";
    static const std::string DEVICE_START_ACTIVITY = "/wd/hub/session/{0}/appium/device/start_activity";
    static const std::string APP_LAUNCH = "/wd/hub/session/{0}/appium/app/launch";
    static const std::string APP_CLOSE = "/wd/hub/session/{0}/appium/app/close";
    static const std::string APP_RESET = "/wd/hub/session/{0}/appium/app/reset";
    static const std::string APP_BACKGROUND = "/wd/hub/session/{0}/appium/app/background";
    static const std::string APP_END_TEST_COVERAGE = "/wd/hub/session/{0}/appium/app/end_test_coverage";
    static const std::string APP_STRINGS = "/wd/hub/session/{0}/appium/app/strings";
    static const std::string ELEMENT_VALUE_APPIUM = "/wd/hub/session/{0}/appium/element/{1}/value";
    static const std::string ELEMENT_REPLACE_VALUE = "/wd/hub/session/{0}/appium/element/{1}/replace_value";
    static const std::string CONTEXT_SETTINGS = "/wd/hub/session/{0}/appium/settings";
}


#endif	/* ROUTES_H */

