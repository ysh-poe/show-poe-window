#include <node.h>
#include <windows.h>

namespace demo {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void showWindow(const FunctionCallbackInfo<Value> &args) {  
		
		HWND hCurWnd = ::GetForegroundWindow();
		HWND PoEWindow = ::FindWindow(NULL, "Path of Exile");
		DWORD dwMyID = ::GetCurrentThreadId();
		DWORD dwCurID = ::GetWindowThreadProcessId(hCurWnd, NULL);

		::ShowWindow(PoEWindow, 9);
		//::SetWindowPos(PoEWindow, -1, 0, 0, 0, 0, 3);
		//::SetWindowPos(PoEWindow, -2, 0, 0, 0, 0, 3);
		::SetForegroundWindow(PoEWindow);
		::AttachThreadInput(dwCurID, dwCurID, 0);
		::SetFocus(PoEWindow);
		::SetActiveWindow(PoEWindow);
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "showWindow", showWindow);
	}

	NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo


