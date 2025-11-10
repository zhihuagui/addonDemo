#include <napi.h>
#include <regex>
#include <string>
 
using namespace Napi;
 
Napi::String Method(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "world");
}

Napi::Value CallRegex(const Napi::CallbackInfo& info) {
    if (info.Length() != 1 || !info[0].IsString()) {
        return info.Env().Undefined();
    }

    std::regex guidPattern(R"(^\s*GUID\s*\(\s*(\d+)\s*,\s*(\d+)\s*\)\s*$)");
    std::smatch matches;

    const std::string input = info[0].ToString();

    if (std::regex_match(input, matches, guidPattern)) {
        // matches[1] 和 matches[2] 是捕获组
        long long num1 = std::stoll(matches[1].str());
        long long num2 = std::stoll(matches[2].str());

        Napi::Array result = Napi::Array::New(info.Env(), 2);
        result.Set(0u, num1);
        result.Set(1u, num2);
        return result;
    } else {
        printf("Input string does not match GUID(number, number) format.\n");
    }
    return info.Env().Undefined();
}
 
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "HelloWorld"),
                Napi::Function::New(env, Method));
    exports.Set(Napi::String::New(env, "CallRegex"),
                Napi::Function::New(env, CallRegex));
    return exports;
}
 
NODE_API_MODULE(hello_world, Init)
