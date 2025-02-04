#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate * isolate = args.GetIsolate();
  args.GetReturnValue().Set(
      String::NewFromUtf8(isolate, "Addons-custom: hello from C++ addon!").
          ToLocalChecked());
}

void Initialize(Local<Object> exports) {
  fprintf(stderr, "[test_addon] %s:%d: invoked.\n", __func__, __LINE__);
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);

}  // namespace demo
